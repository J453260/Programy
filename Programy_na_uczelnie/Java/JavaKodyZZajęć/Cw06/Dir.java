
public enum Dir implements NextPosition {
	NORTH {
		@Override
		public Position next(Position pos) {
			return new Position(pos.col(), pos.row() + 1);
		}
	},
	EAST {
		@Override
		public Position next(Position pos) {
			return new Position(pos.col() + 1, pos.row());
		}
	},
	SOUTH {
		@Override
		public Position next(Position pos) {
			return new Position(pos.col(), pos.row() - 1);
		}
	},
	WEST {
		@Override
		public Position next(Position pos) {
			return new Position(pos.col() - 1, pos.row());
		}
	}
}
