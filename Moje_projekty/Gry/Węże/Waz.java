import java.util.*;

class Waz {
    public Direction direction;
    LinkedList<int[]> segments = new LinkedList<>();

    Waz(int i, int j, int dl){
        for(int k = 0; k < dl; k++){
            segments.add(new int[]{i - 1, j - 1 - k});
        }

        direction = Direction.RIGHT;
    }

    static Direction zmienKierunek(char key){
        key = Character.toLowerCase(key);

        switch(key){
            case 'w': return Direction.UP;
            case 's': return Direction.DOWN;
            case 'a': return Direction.LEFT;
            case 'd': return Direction.RIGHT;
            default:
                System.out.println("Nieprawidłowy kierunek");
                return null;
        }
    }

    public void ruch(Direction dir){
        int[] head = segments.getFirst();
        int headX = head[0];
        int headY = head[1];

        switch(dir){
            case UP:
                headX--;
                break;
            case DOWN:
                headX++;
                break;
            case LEFT:
                headY--;
                break;
            case RIGHT:
                headY++;
                break;
        }

        segments.addFirst(new int[]{headX, headY});
        segments.removeLast();
    }

    public void dodaj(Direction dir){
        int[] head = segments.getFirst();
        int headX = head[0];
        int headY = head[1];

        switch(dir){
            case UP:
                headX--;
                break;
            case DOWN:
                headX++;
                break;
            case LEFT:
                headY--;
                break;
            case RIGHT:
                headY++;
                break;
        }

        segments.addFirst(new int[]{headX, headY});
    }
}
