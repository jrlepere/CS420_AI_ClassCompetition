package cs420_p3;

public class State {
	public static final int BOARD_SIZE = 4;
	
	private int[][] board;
	private boolean maxPlayer;
	
	public State() {
		board = new int[BOARD_SIZE][BOARD_SIZE];
		initBoard();
	}
	
	public State(int[][] board) {
		this.board = board;
	}
	
	public void printState() {
		System.out.println("  0 1 2 3 4 5 6 7");
		for (int i = 0; i < BOARD_SIZE; i++) {
			System.out.print(i + " ");
			for (int j = 0; j < BOARD_SIZE; j++) {
				if (board[i][j] == 1)
					System.out.print("X ");
				else if (board[i][j] == -1)
					System.out.print("O ");
				else if (board[i][j] == 0)
					System.out.print("- ");
			}
			System.out.println("");
		}
	}
	
	public void initBoard() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				board[i][j] = 0;
			}
		}
	}
	
	public boolean putOnBoard(int input, int row, int col) {
		if (row < 0 || row > BOARD_SIZE || col < 0 || col > BOARD_SIZE) {
			System.out.println("Input out of bounds.");
			return false;
		}
		else if (board[row][col] != 0) {
			System.out.println("Square already taken.");
			return false;
		}
		else {
			board[row][col] = input;
			return true;
		}
	}
	
	public int[][] getBoard() {return board;}
	public boolean isMaxPlayer() {return maxPlayer;}
	public void setMaxPlayer(boolean maxPlayer) {this.maxPlayer = maxPlayer;}
}
