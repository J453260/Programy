import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

public class Body {
	private Deque<Position> body = new LinkedList<Position>();
	private MyList ghost = new MyList();

	private class MyList extends LinkedList<Position> {
		@Override
		public void clear() {
			System.err.println("Nic z tego!");
		}

		@Override
		public void addFirst(Position e) {
			System.err.println("Dodawania nie będzie");
		}

		@Override
		public Position removeLast() {
			System.err.println("Kasowania nie będzie");
			return null;
		}

		private void addF(Position e) {
			super.addFirst(e);
		}

		private void removeL() {
			super.removeLast();
		}
	}

	public Deque<Position> body() {
		return ghost;
	}

	public void add(Position pos) {
		body.addFirst(pos);
		ghost.addF(pos);
	}

	public void removeTail() {
		body.removeLast();
		ghost.removeL();
	}

	@Override
	public String toString() {
		return "Body: " + body.toString();
	}

}
