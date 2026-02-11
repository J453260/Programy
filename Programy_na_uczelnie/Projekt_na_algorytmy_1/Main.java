import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.util.List;

class MainFrame extends JFrame {

    private PointDatabase database = new PointDatabase();
    private Integer fixedDimension = null;

    private JTextField dimField = new JTextField(5);
    private JTextField nameField = new JTextField(10);
    private JTextField coordField = new JTextField(20);
    private JTextField idField = new JTextField(5);
    private JTextArea output = new JTextArea(10,40);
    private JTextArea historyArea = new JTextArea(5,40);

    public MainFrame() {
        setTitle("Baza punktów Euklidesowych z Historią");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Panel wprowadzania danych
        JPanel top = new JPanel();
        top.add(new JLabel("Wymiar:"));
        top.add(dimField);
        top.add(new JLabel("Nazwa:"));
        top.add(nameField);
        top.add(new JLabel("Współrzędne (np. 1 2 3):"));
        top.add(coordField);

        // Przyciski
        JButton addBtn = new JButton("Dodaj punkt");
        JButton showBtn = new JButton("Pokaż punkty");
        JButton nearestBtn = new JButton("Najbliższy do ID");
        JButton undoBtn = new JButton("Cofnij (Undo)");
        JButton showHistoryBtn = new JButton("Pokaż historię");
        JButton deleteBtn = new JButton("Usuń punkt");

        JPanel buttons = new JPanel();
        buttons.add(addBtn);
        buttons.add(deleteBtn);
        buttons.add(showBtn);
        buttons.add(nearestBtn);
        buttons.add(undoBtn);
        buttons.add(showHistoryBtn);

        JPanel searchPanel = new JPanel();
        searchPanel.add(new JLabel("ID punktu:"));
        searchPanel.add(idField);

        // Panel dla historii
        JPanel historyPanel = new JPanel(new BorderLayout());
        historyPanel.add(new JLabel("Historia operacji (Stos):"), BorderLayout.NORTH);
        historyArea.setEditable(false);
        historyArea.setFont(new Font("Monospaced", Font.PLAIN, 11));
        historyPanel.add(new JScrollPane(historyArea), BorderLayout.CENTER);

        // Panel główny
        JPanel mainPanel = new JPanel(new GridLayout(2,1));
        JPanel outputPanel = new JPanel(new BorderLayout());
        outputPanel.add(new JLabel("Wyniki:"), BorderLayout.NORTH);
        outputPanel.add(new JScrollPane(output), BorderLayout.CENTER);

        mainPanel.add(outputPanel);
        mainPanel.add(historyPanel);

        add(top, BorderLayout.NORTH);
        add(buttons, BorderLayout.CENTER);
        add(searchPanel, BorderLayout.EAST);
        add(mainPanel, BorderLayout.SOUTH);

        addBtn.addActionListener(e -> addPoint());
        showBtn.addActionListener(e -> showPoints());
        nearestBtn.addActionListener(e -> findNearest());
        undoBtn.addActionListener(e -> undo());
        showHistoryBtn.addActionListener(e -> showHistory());
        deleteBtn.addActionListener(e -> deletePoint());

        pack();
        setVisible(true);
    }

    private void deletePoint() {
        try {
            int id = Integer.parseInt(idField.getText());
            Point deleted = database.deletePoint(id);

            if(deleted == null) {
                output.append("Nie znaleziono punktu o ID " + id + "\n");
            } else {
                output.append("Usunięto: " + deleted + "\n");
                updateHistoryDisplay();
            }
        } catch(NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Podaj poprawny numer ID");
        }
    }

    private void undo() {
        boolean success = database.undo();
        if(success) {
            output.append("Cofnięto ostatnią operację\n");
            updateHistoryDisplay();

            // Jeśli po undo nie ma żadnych punktów, odblokuj wymiar
            if(database.getAll().isEmpty()) {
                fixedDimension = null;
                dimField.setEditable(true);
            }
        } else {
            output.append("Brak operacji do cofnięcia\n");
        }
    }

    private void showHistory() {
        updateHistoryDisplay();
        output.append("Historia wyświetlona poniżej\n");
    }

    private void updateHistoryDisplay() {
        historyArea.setText("");
        Stack<Operation> history = database.getHistory();

        if(history.isEmpty()) {
            historyArea.append("Historia pusta\n");
            return;
        }

        historyArea.append("=== STOS OPERACJI (góra stosu) ===\n");
        int index = history.size();
        for(int i = history.size() - 1; i >= 0; i--) {
            Operation op = history.get(i);
            historyArea.append(String.format("[%d] %s\n", index--, op));
        }
        historyArea.append("=== (dno stosu) ===\n");
    }

    private void findNearest() {
        try {
            int id = Integer.parseInt(idField.getText());
            Point nearest = database.findNearest(id);
            Point target = database.find(id);

            if(target == null) {
                output.append("Nie znaleziono punktu o ID " + id + "\n");
                return;
            }

            if(nearest == null) {
                output.append("Brak innych punktów w bazie.\n");
            } else {
                double dist = Point.distance(target, nearest);
                output.append("Najbliższy punkt do " + target + "\nto: " + nearest +
                        "\nOdległość: " + String.format("%.2f", dist) + "\n\n");
            }

        } catch(NumberFormatException ex){
            JOptionPane.showMessageDialog(this, "Podaj poprawny numer ID");
        }
    }

    private void addPoint() {
        try {
            int dim = Integer.parseInt(dimField.getText());

            // Jeśli wymiar nie był jeszcze ustalony, ustawiamy i blokujemy pole
            if(fixedDimension == null){
                fixedDimension = dim;
                dimField.setEditable(false);
            } else {
                // Wymiar już ustalony – sprawdzamy zgodność
                if(dim != fixedDimension)
                    throw new RuntimeException("Wymiar musi być taki sam jak pierwszy punkt: " + fixedDimension);
            }

            String name = nameField.getText();
            String[] parts = coordField.getText().trim().split("\\s+");
            if(parts.length != dim){
                throw new RuntimeException("Zła liczba współrzędnych, oczekiwano " + dim);
            }


            List<Double> coords = new ArrayList<>();
            for(String s : parts){
                coords.add(Double.parseDouble(s));
            }

            Point p = database.addPoint(dim, name, coords);
            output.append("Dodano: " + p + "\n");
            updateHistoryDisplay();

        } catch(Exception ex){
            JOptionPane.showMessageDialog(this, ex.getMessage());
        }
    }

    private void showPoints(){
        output.setText("");
        List<Point> points = database.getAll();
        if(points.isEmpty()) {
            output.append("Baza jest pusta\n");
        } else {
            for(Point p : points)
                output.append(p + "\n");
        }
    }

    public static void main(String[] args){
        new MainFrame();
    }
}

class Point{
    private final int dimension;
    private final int id;
    private final String name;
    private List<Double> coordinates;

    Point(int dim, int id, String name){
        this.dimension = dim;
        this.id = id;
        this.name = name;
        coordinates = new ArrayList<>();
        for(int i = 0; i < dim; i++){
            coordinates.add(0.0);
        }
    }

    void set(int index, double value){
        coordinates.set(index, value);
    }

    int getId(){
        return id;
    }

    int getDim(){
        return dimension;
    }

    static double distance(Point a, Point b){
        double sum = 0;
        for(int i = 0; i < a.dimension; ++i)
        {
            double diff = a.coordinates.get(i) - b.coordinates.get(i);
            sum += diff * diff;
        }
        return Math.sqrt(sum);
    }

    public String toString(){
        return "ID:"+id+" "+name+" "+coordinates;
    }
}

// Klasa reprezentująca operację w historii
class Operation {
    enum Type { ADD, DELETE }

    private Type type;
    private Point point;
    private long timestamp;

    Operation(Type type, Point point) {
        this.type = type;
        this.point = point;
        this.timestamp = System.currentTimeMillis();
    }

    Type getType() { return type; }
    Point getPoint() { return point; }

    public String toString() {
        String typeStr = (type == Type.ADD) ? "DODANO" : "USUNIĘTO";
        return typeStr + ": " + point;
    }
}

class PointDatabase {
    private List<Point> data = new ArrayList<>();
    private Stack<Operation> history = new Stack<>();  // STOS do historii operacji
    private Stack<Integer> availableIds = new Stack<>();  // STOS wolnych ID
    int nextId = 1;

    public Point addPoint(int dim, String name, List<Double> coords){
        // Pobierz ID - ze stosu wolnych ID lub wygeneruj nowe
        int id;
        if(!availableIds.isEmpty()) {
            id = availableIds.pop();  // Użyj zwolnionego ID ze stosu
        } else {
            id = nextId++;  // Wygeneruj nowe ID
        }

        Point p = new Point(dim, id, name); //p - point
        for(int i=0;i<dim;i++)
            p.set(i, coords.get(i));
        data.add(p);

        // Dodaje operację na stos historii
        history.push(new Operation(Operation.Type.ADD, p));

        return p;
    }

    public Point deletePoint(int id) {
        Point p = find(id);
        if(p == null) return null;

        data.remove(p);

        // Zwolnij ID - dodaj na stos wolnych ID
        availableIds.push(id);

        // Dodaj operację usunięcia na stos
        history.push(new Operation(Operation.Type.DELETE, p));

        return p;
    }

    public boolean undo() {
        if(history.isEmpty()) return false;

        // Zdejmij ostatnią operację ze stosu
        Operation lastOp = history.pop();

        if(lastOp.getType() == Operation.Type.ADD) {
            // Cofnij dodanie - usuń punkt i zwolnij jego ID
            Point p = lastOp.getPoint();
            data.remove(p);
            availableIds.push(p.getId());
        } else {
            // Cofnij usunięcie - przywróć punkt i usuń jego ID ze stosu wolnych
            Point p = lastOp.getPoint();
            data.add(p);
            // Usuń ID ze stosu wolnych (ponieważ jest znowu używane)
            availableIds.removeElement(p.getId());
        }

        return true;
    }

    public Stack<Operation> getHistory() {
        return history;
    }

    public List<Point> getAll(){
        return data;
        //lista wszystkich punktów
    }

    public Point find(int id){
        for(Point p:data){
            if(p.getId() == id) return p;
            //przeszukuje punkty i zwraca punkt o podanym ID
        }

        return null;
    }

    public Point findNearest(int id){
        Point target = find(id);
        if(target==null || data.size()<2) return null;

        Point nearest = null;
        double bestDist = Double.MAX_VALUE;

        for(Point p : data){
            if(p.getId() == id) continue;
            if(p.getDim() != target.getDim()) continue;

            double d = Point.distance(target, p);
            if(d < bestDist){
                bestDist = d;
                nearest = p;
            }
        }
        return nearest;
    }
}