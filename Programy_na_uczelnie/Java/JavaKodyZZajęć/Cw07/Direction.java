import java.util.Arrays;

public enum Direction implements NextPosition, Turn {
	NORTH(new Vector(0, 1)), EAST(new Vector(1, 0)), 
	SOUTH(new Vector(0, -1)), WEST(new Vector(-1, 0));

	private final Vector unit;

	@Override
	public Direction toTheLeft() {
		int id = ( ordinal() + 3 ) % 4; // -90stopni to 270 stopni
		return values()[id];
	}
	
	@Override
	public Direction toTheRight() {
		int id = ( ordinal() + 1 ) % 4;
		return values()[id];
	}
	
	private Direction(Vector unit) {
		this.unit = unit;
	}

	@Override
	public Position next(Position pos) {
		return unit.shift(pos);
	}
}
