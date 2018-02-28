package cs420_p3;

import successors.*;

public class MiniMax_MaxDepth {
	
	private final int MAX_DEPTH = 4;
	private final int MAX_PLAYER = 1;
	private final int MIN_PLAYER = -1;
	private final int MAX_H_VALUE = 100;
	private final int LARGE_POS = 10000;
	private final int LARGE_NEG = -10000;
	
	private State mainBoard;
		
	public MiniMax_MaxDepth() {
		mainBoard = new State();
	}
	
	public void play(int prevRow, int prevCol, boolean maxPlayer) {
		int[] move = MiniMaxAlgo(mainBoard, 0, maxPlayer, LARGE_NEG, LARGE_POS, prevRow, prevCol);
		int player;
		if (maxPlayer) {player = MAX_PLAYER;}
		else {player = MIN_PLAYER;}
		
		System.out.println("Heuristic: " + move[0] + " " + move[1] + " " + move[2]);
		
		mainBoard.putOnBoard(player, move[1], move[2]);
	}
	
	private int[] MiniMaxAlgo(State board, int depth, boolean maxPlayer, int alpha, int beta, int prevRow, int prevCol) {
		if (depth == MAX_DEPTH || isTerminalState(board)) {
			int heuristicH = chosenHeuristic(board);
			if (maxPlayer) {heuristicH = heuristicH * -1;}
			
			int[] temp = {heuristicH};
			return temp;
		}
		
		Successors suc = new Spiral();
		int[][] successors = suc.getSuccessors(board.getBoard(), prevRow, prevCol);
		
		if (maxPlayer) {
			int[] bestValue = {LARGE_NEG, 0, 0};
			for (int i = 0; i < successors.length; i++) {
				int rowTemp = successors[i][0];
				int colTemp = successors[i][1];
				board.putOnBoard(MAX_PLAYER, rowTemp, colTemp);
				int[] v = MiniMaxAlgo(board, depth + 1, !maxPlayer, alpha, beta, rowTemp, colTemp);
				board.getBoard()[rowTemp][colTemp] = 0;
				if (v[0] > bestValue[0]) {
					bestValue[0] = v[0];
					bestValue[1] = rowTemp;
					bestValue[2] = colTemp;
				}
				// Alpha-beta pruning
				if (bestValue[0] >= beta) {return bestValue;}
				alpha = Math.max(alpha, bestValue[0]);
			}
			return bestValue;
		}
		else {
			int[] bestValue = {LARGE_POS, 0, 0};
			for (int i = 0; i < successors.length; i++) {
				int rowTemp = successors[i][0];
				int colTemp = successors[i][1];
				board.putOnBoard(MIN_PLAYER, rowTemp, colTemp);
				int[] v = MiniMaxAlgo(board, depth + 1, !maxPlayer, alpha, beta, rowTemp, colTemp);
				board.getBoard()[rowTemp][colTemp] = 0; // reset board
				if (v[0] < bestValue[0]) {
					bestValue[0] = v[0];
					bestValue[1] = rowTemp;
					bestValue[2] = colTemp;
				}
				// Alpha beta pruning
				if (bestValue[0] <= alpha) {return bestValue;}
				beta = Math.min(beta, bestValue[0]);
			}
			return bestValue;
		}
	}	
	
	private int chosenHeuristic(State board) {
		return debugHeuristic(board);
	}
	
	private int debugHeuristic(State board) {
		if (isTerminalState(board)) {
			return MAX_H_VALUE; 
		}
		
		int v;
		
		v = checkForKillerMoves(board);
		if (v != 0) {return v;}
		
		v = checkForDisjointedSets(board);
		if (v != 0) {return v;}
		
		return 0;
	}
	
	private int checkForDisjointedSets(State boardT) {
		int[][] curBoard = boardT.getBoard();
		
		for (int i = 0; i < curBoard.length; i++) {
			for (int j = 0; j < curBoard[i].length; j++) {
				// -- Row Check -- //
				// Check for XX_X
				if (j < curBoard[i].length - 4 &&
						curBoard[i][j] != 0 &&
						curBoard[i][j+2] != 0 &&
						curBoard[i][j] != curBoard[i][j+2] &&
						curBoard[i][j] == curBoard[i][j+1] &&
						curBoard[i][j] == curBoard[i][j+3]) {
					return MAX_H_VALUE - 10;
				}
				
				// Check for X_XX
				if (j < curBoard[i].length - 4 &&
						curBoard[i][j] != 0 &&
						curBoard[i][j+1] != 0 &&
						curBoard[i][j] != curBoard[i][j+1] &&
						curBoard[i][j] == curBoard[i][j+2] &&
						curBoard[i][j] == curBoard[i][j+3]) {
					return MAX_H_VALUE - 10;
				}
				
				// -- Col Check --//
				// XX_X
				if (i < curBoard[i].length - 4 &&
						curBoard[i][j] != 0 &&
						curBoard[i+2][j] != 0 &&
						curBoard[i][j] != curBoard[i+2][j] &&
						curBoard[i][j] == curBoard[i+1][j] &&
						curBoard[i][j] == curBoard[i+3][j]) {
					return MAX_H_VALUE - 10;
				}
				
				// X_XX
				if (i < curBoard[i].length - 4 &&
						curBoard[i][j] != 0 &&
						curBoard[i+1][j] != 0 &&
						curBoard[i][j] != curBoard[i+1][j] &&
						curBoard[i][j] == curBoard[i+2][j] &&
						curBoard[i][j] == curBoard[i+3][j]) {
					return MAX_H_VALUE - 10;
				}
			}
		}
		
		return 0;
	}
	
	private int checkForKillerMoves(State boardT) {
		int[][] board = boardT.getBoard();
		int bestValue = 0;
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				// Row test
				if (j < 4 && 
					board[i][j] == 0 &&
					board[i][j+4] == 0 &&
					board[i][j+1] != 0 &&
					board[i][j+1] == board[i][j+2] &&
					board[i][j+1] == board[i][j+3]) {
					return MAX_H_VALUE - 15;
				} 
				
				// Col test
				if (i < 4 &&
					board[i][j] == 0 &&
					board[i+4][j] == 0 &&
					board[i+1][j] != 0 &&
					board[i+1][j] == board[i+2][j] &&
					board[i+1][j] == board[i+3][j]) {
					return MAX_H_VALUE - 15;
				}
			}
		}
		
		return bestValue;
	}
	
	public boolean isTerminalState(State board2) {
		int[][] board = board2.getBoard();
		int zeroCounter = 0;
		
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				if (board[i][j] != 0) {
					// Row test
					if (j < board[i].length - 3 &&
						board[i][j] == board[i][j+1] &&
						board[i][j] == board[i][j+2] &&
						board[i][j] == board[i][j+3]) {
						return true;
					}
					
					// Row test
					if (i < board[i].length - 3 &&
						board[i][j] == board[i+1][j] &&
						board[i][j] == board[i+2][j] &&
						board[i][j] == board[i+3][j]) {
						return true;
					}
				}
				else {zeroCounter++;}
			}
		}
		
		if (zeroCounter == 0) {return true;} // no open space
		
		return false;
	}
	
	public State getMainBoard() {return mainBoard;}
}
