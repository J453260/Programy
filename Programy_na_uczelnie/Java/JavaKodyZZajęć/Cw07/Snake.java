
public class Snake implements Turn {
	private final Head head;
	private final Body body;

	public Snake(Direction dir, Position pos) {
		head = new Head(dir, pos);
		body = new Body();
		body.add(pos);
		
		System.out.println( body );
		System.out.println( body.body());
		body.body().addFirst(pos);
		body.body().removeLast();
		body.body().clear();
		System.out.println( body.body());
		
		
	}

	public Position next() {
		Position nextPosition = head.next();
		body.add(nextPosition);
		return nextPosition;
	}

	public void removeTail() {
		body.removeTail();
	}

	@Override
	public Direction toTheLeft() {
		return head.toTheLeft();
	}

	@Override
	public Direction toTheRight() {
		return head.toTheRight();
	}
	
	@Override
	public String toString() {
		return head.toString() + "\n" + body.toString();
	}
}
