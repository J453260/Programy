public class Main {
	public static void main(String[] args) {
		Position pos = new Position(0, 0);
		
		Direction dir = Direction.NORTH;	
		
		for ( int step = 0; step < 12; step++ ) {
			
			if ( step % 3 == 0 )
				dir = dir.toTheRight();
			
			pos = dir.next(pos);
			System.out.println( dir );
			System.out.println( pos );
		}
		
}
}
