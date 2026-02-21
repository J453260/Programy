
public class Position {
	private final int col;
	private final int row;
	
	public Position( int col, int row ) {
		this.col = col;
		this.row = row;
	}

	@Override
	public String toString() {
		return "Position [col=" + col + ", row=" + row + "]";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + col;
		result = prime * result + row;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (!(obj instanceof Position))
			return false;
		Position other = (Position) obj;
		if (col != other.col)
			return false;
		if (row != other.row)
			return false;
		return true;
	}
	
	
	
	
}
