package cs420_p3;

import java.util.Scanner;

public class MainClass {

	private final int MAX_PLAYER = 1;
	private final int MIN_PLAYER = -1;
	
	private int row;
	private int col;
	MiniMax_MaxDepth mm;
	
	public MainClass() {
		row = 0;
		col = 0;
		mm = new MiniMax_MaxDepth();
		
		play();
	}
	
	private void play() {
		boolean playerTurn = true;
		State mainBoard = mm.getMainBoard();
		Scanner sc = new Scanner(System.in);
		mainBoard.putOnBoard(MAX_PLAYER, 3, 0);
		mainBoard.putOnBoard(MAX_PLAYER, 3, 1);
		
		while (!mm.isTerminalState(mainBoard)) {
			// Player's turn
			if (playerTurn) {
				mainBoard.printState();
				getUserInput(sc);
				mainBoard.putOnBoard(MAX_PLAYER, row, col);
				
				playerTurn = !playerTurn;
			}
			
			else {
				mm.play(row, col, playerTurn);
				playerTurn = !playerTurn;
			}
		}
		sc.close();
	}
	
	private void getUserInput(Scanner sc) {
		System.out.print("Enter row: ");
		row = Integer.parseInt(sc.nextLine());
		
		System.out.print("Enter col: ");
		col = Integer.parseInt(sc.nextLine());
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MainClass();
	}

}
