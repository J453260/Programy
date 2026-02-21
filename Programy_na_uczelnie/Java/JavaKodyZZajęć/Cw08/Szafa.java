
public class Szafa implements Mebel {

	@Override
	public void get() {
		System.out.println( "Biorę coś z szafy");
	}
	
	@Override
	public void put() {
		System.out.println( "Wkładam coś do szafy");
	}
	
}
