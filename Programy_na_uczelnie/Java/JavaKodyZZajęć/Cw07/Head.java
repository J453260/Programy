
public class Head implements Turn {
	private Direction dir;
	private Position pos;
	
	public Head(Direction dir, Position pos) {
		this.dir = dir;
		this.pos = pos;
	}

	@Override
	public Direction toTheRight() {
		dir = dir.toTheRight();
		return dir;
	}

	@Override
	public Direction toTheLeft() {
		dir = dir.toTheLeft();
		return dir;
	}
	
	public Position next() {
		pos = dir.next(pos);
		return pos;
	}
	
	@Override
	public String toString() {
		return "Head: " + dir + " " + pos;
	}
}
