package successors;

import java.util.ArrayList;

import cs420_p3.State;

public class Spiral implements Successors {

	/**
	 * We will go right, up, left, down, and then right.
	 */
	@Override
	public int[][] getSuccessors(int[][] board, int row, int col) {
		ArrayList<int[]> temp = new ArrayList<int[]>();
		
		int increasedBy = 1;
		int boardSize = State.BOARD_SIZE;
		int maxSearch = (boardSize - 1) * (boardSize - 1);
		boolean successorsRemain = true;
		
		while (successorsRemain) {
			int rowBoundary, colBoundary, curRow, curCol;
			
			if ((col + increasedBy) <= maxSearch || (row - increasedBy) >= 0 ||
					(col - increasedBy) >= 0 || (row + increasedBy) <= maxSearch) {
				// Top right
				colBoundary = col + increasedBy;
				rowBoundary = row - increasedBy;
				curRow = row;
				curCol = colBoundary;
				for (int i = 0; i < increasedBy+1; i++) {					
					if (curRow >= 0 && curRow < boardSize && curCol >= 0 && curCol < boardSize) {
						if (board[curRow][curCol] == 0) {
							temp.add(new int[]{curRow, curCol});
						}
					}
					curRow--;
					curCol--;
				}
				
				// Top left
				colBoundary = col - increasedBy;
				curRow = row;
				curCol = colBoundary;
				for (int i = 0; i < increasedBy; i++) {					
					if (curRow >= 0 && curRow < boardSize && curCol >= 0 && curCol < boardSize) {
						if (board[curRow][curCol] == 0) {
							temp.add(new int[]{curRow, curCol});
						}
					}
					curRow--;
					curCol++;
				}
				
				// Bottom left
				rowBoundary = row + increasedBy;
				curRow = rowBoundary;
				curCol = col;
				for (int i = 0; i < increasedBy; i++) {
					if (curRow >= 0 && curRow < boardSize && curCol >= 0 && curCol < boardSize) {
						if (board[curRow][curCol] == 0) {
							temp.add(new int[]{curRow, curCol});
						}
					}
					curRow--;
					curCol--;
				}
				
				// Bottom right
				colBoundary = col + increasedBy;
				curRow = row + increasedBy - 1;
				curCol = col + 1;
				for (int i = 0; i < increasedBy-1; i++) {					
					if (curRow >= 0 && curRow < boardSize && curCol >= 0 && curCol < boardSize) {
						if (board[curRow][curCol] == 0) {
							temp.add(new int[]{curRow, curCol});
						}
					}
					curRow--;
					curCol++;
				}
				
				increasedBy++;
			}
			else {
				successorsRemain = false;
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
}