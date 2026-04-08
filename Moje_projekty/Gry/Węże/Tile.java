public enum Tile {
    EMPTY('.'),
    HEAD('▲'),
    BODY('■'),
    FOOD('●');

    public final char symbol;

    Tile(char symbol) {
        this.symbol = symbol;
    }
}
