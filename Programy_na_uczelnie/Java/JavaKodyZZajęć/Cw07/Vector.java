
public record Vector(int dCol, int dRow) {
	public Position shift(Position pos) {
		return new Position(pos.col() + dCol, pos.row() + dRow);
	}
}
