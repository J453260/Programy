import java.util.HashSet;
import java.util.Set;

public class Main {
	public static void main(String[] args) {

		Position p00 = new Position(0, 0);
		Position p10 = new Position(1, 0);
		Position p01 = new Position(0, 1);

		Position p00prim = new Position(0, 0);
		Position p00bis = new Position(0, 0);
		Position p00ter = new Position(0, 0) {
		};

		Set<Position> zbiór = new HashSet<Position>();

		addToSet(zbiór, p00);
		addToSet(zbiór, p10);
		addToSet(zbiór, p01);
		addToSet(zbiór, p00prim);
		addToSet(zbiór, p00bis);
		addToSet(zbiór, p00ter);

		
//		Position pos = new Position(0, 0);		
//		Direction dir = Direction.NORTH;	
//		
//		Snake snake = new Snake( dir, pos );
//
//		for ( int i = 0 ; i < 3; i++ ) {
//			snake.next();
//			System.out.println(snake);
//		}
//		
//		for ( int i = 0 ; i < 3; i++ ) {
//			snake.next();
//			snake.removeTail();
//			System.out.println(snake);
//		}
	}
	
	private static void addToSet( Set<Position> set, Position toAdd ) {
		System.out.println( "Przed " + set );
		System.out.println( "Obiekt dodawany jest typu " + toAdd.getClass() );
		boolean result = set.add(toAdd);
		System.out.println( "Dodawanie : " + result );
		System.out.println( "Po    " + set );
		System.out.println( ".".repeat( 20 ));
	}
	
}
