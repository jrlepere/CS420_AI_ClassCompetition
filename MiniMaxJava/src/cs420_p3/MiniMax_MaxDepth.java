package cs420_p3;

import java.util.ArrayList;
import java.util.Arrays;

public class MiniMax_MaxDepth {
	
	private final int MAX_DEPTH = 2;
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
		int[] move = MiniMaxAlgo(mainBoard, 0, maxPlayer, LARGE_NEG, LARGE_POS);
		int player;
		if (maxPlayer) {player = MAX_PLAYER;}
		else {player = MIN_PLAYER;}
		
		System.out.println("Heuristic: " + move[0] + " " + move[1] + " " + move[2]);
		
		mainBoard.putOnBoard(player, move[1], move[2]);
	}
	
	private int[] MiniMaxAlgo(State board, int depth, boolean maxPlayer, int alpha, int beta) {
		if (depth == MAX_DEPTH || isTerminalState(board)) {
			int heuristicH = chosenHeuristic(board, maxPlayer);
			if (maxPlayer) {heuristicH = heuristicH * -1;}
			
			int[] temp = {heuristicH};
			return temp;
		}
		
		int[][] successors = getSuccessors(board.getBoard());
		
		if (maxPlayer) {
			int[] bestValue = {LARGE_NEG, 0, 0};
			for (int i = 0; i < successors.length; i++) {
				int prevRow = successors[i][0];
				int prevCol = successors[i][1];
				board.putOnBoard(MAX_PLAYER, prevRow, prevCol);
				int[] v = MiniMaxAlgo(board, depth + 1, !maxPlayer, alpha, beta);
				board.getBoard()[prevRow][prevCol] = 0;
				if (v[0] > bestValue[0]) {
					bestValue[0] = v[0];
					bestValue[1] = prevRow;
					bestValue[2] = prevCol;
				}
				// Alpha-beta pruning
				if (bestValue[0] >= beta) {return bestValue;}
				alpha = Math.max(alpha, bestValue[0]);
				
				// Debug
				if (bestValue[0] == MAX_H_VALUE) {return bestValue;}
			}
			return bestValue;
		}
		else {
			int[] bestValue = {LARGE_POS, 0, 0};
			for (int i = 0; i < successors.length; i++) {
				int prevRow = successors[i][0];
				int prevCol = successors[i][1];
				board.putOnBoard(MIN_PLAYER, prevRow, prevCol);
				int[] v = MiniMaxAlgo(board, depth + 1, !maxPlayer, alpha, beta);
				board.getBoard()[prevRow][prevCol] = 0; // reset board
				if (v[0] < bestValue[0]) {
					bestValue[0] = v[0];
					bestValue[1] = prevRow;
					bestValue[2] = prevCol;
				}
				// Alpha beta pruning
				if (bestValue[0] <= alpha) {return bestValue;}
				beta = Math.min(beta, bestValue[0]);
				
				if (bestValue[0] == (MAX_H_VALUE * -1)) {return bestValue;}
			}
			return bestValue;
		}
	}	
	
	private int chosenHeuristic(State board, boolean maxPlayer) {
		return debugHeuristic(board, maxPlayer);
	}
	
	private int debugHeuristic(State board, boolean maxPlayer) {
		if (isTerminalState(board)) {
			return MAX_H_VALUE; 
		}
		
		int[][] curBoard = board.getBoard();
		
		// Check for XX_X
		for (int i = 0; i < curBoard.length; i++) {
			for (int j = 0; j < curBoard[i].length; j++) {
				if (j >= 2 && j < curBoard[i].length - 1 &&
						curBoard[i][j] != 0 &&
						curBoard[i][j-2] != 0 &&
						curBoard[i][j-2] != curBoard[i][j] &&
						curBoard[i][j-2] == curBoard[i][j-1] &&
						curBoard[i][j-2] == curBoard[i][j+1]) {
					return MAX_H_VALUE - 10;
				}
			}
		}
		
		return 0;
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
	
	private int[][] getSuccessors(int[][] board) {
		ArrayList< int[] > temp = new ArrayList< int[] >();
		
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[i].length; j++) {
				int temp2[] = new int[2];
				if (board[i][j] == 0) {
					temp2[0] = i;
					temp2[1] = j;
					temp.add(temp2);
				}
			}
		}
		
		int[][] returnValue = new int[temp.size()][2];
		for (int i = 0; i < returnValue.length; i++) {
			for (int j = 0; j < returnValue[i].length; j++) {
				returnValue[i][j] = temp.get(i)[j];
			}
		}
		
		return returnValue;
	}
	
	public State getMainBoard() {return mainBoard;}
}
