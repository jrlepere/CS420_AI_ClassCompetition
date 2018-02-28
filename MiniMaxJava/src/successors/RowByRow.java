package successors;

import java.util.ArrayList;

public class RowByRow implements Successors {

	@Override
	public int[][] getSuccessors(int[][] board, int prevRow, int prevCol) {
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

}
