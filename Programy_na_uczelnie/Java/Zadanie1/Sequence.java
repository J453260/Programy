public class Sequence extends AbstractSequence {
    private int[] data;              // oryginalne dane zakodowane lub surowe
    private int deltaSegmentSize;    // liczba delt

    @Override
    public void sequence(int[] data, int deltaSegmentSize) {
        this.data = data;
        this.deltaSegmentSize = deltaSegmentSize;
    }

    @Override
    public int[] decode() {
        if (data == null || data.length == 0) {
            System.out.println("Brak danych do dekodowania!");
            return new int[0];
        }

        int[] result = new int[data.length];
        int index = 0;

        // Przechodzimy po segmentach danych
        while (index < data.length) {
            int segmentStart = index;
            int sum = data[segmentStart];
            result[segmentStart] = sum;

            // Kolejne liczby to delty — dodajemy je do sumy
            for (int i = 1; i <= deltaSegmentSize && (segmentStart + i) < data.length; i++) {
                sum += data[segmentStart + i];
                result[segmentStart + i] = sum;
            }

            // Przejście do kolejnego segmentu
            index += deltaSegmentSize + 1;
        }

        return result;
    }

    @Override
    public int[] encode(int deltaSegmentSize) {
        if (data == null || data.length == 0) {
            System.out.println("Brak danych do zakodowania!");
            return new int[0];
        }

        int[] decoded = decode(); // odkodowujemy dane, by móc wyliczyć delty
        int[] result = new int[data.length];
        int index = 0;

        // Kodowanie segmentów
        while (index < decoded.length) {
            int segmentStart = index;
            result[segmentStart] = decoded[segmentStart]; // pierwsza liczba wprost

            for (int i = 1; i <= deltaSegmentSize && (segmentStart + i) < decoded.length; i++) {
                result[segmentStart + i] =
                        decoded[segmentStart + i] - decoded[segmentStart + i - 1];
            }

            index += deltaSegmentSize + 1;
        }

        return result;
    }

    @Override
    public boolean equals(int[] data, int deltaSegmentSize) {
        // Dekodujemy dane przekazane w argumencie
        Sequence temp = new Sequence();
        temp.sequence(data, deltaSegmentSize);
        int[] decodedOther = temp.decode();

        // Dekodujemy nasze dane
        int[] decodedThis = this.decode();

        // Porównujemy długości
        if (decodedOther.length != decodedThis.length) {
            return false;
        }

        // Porównujemy wartości
        for (int i = 0; i < decodedThis.length; i++) {
            if (decodedThis[i] != decodedOther[i]) {
                return false;
            }
        }

        return true;
    }
}