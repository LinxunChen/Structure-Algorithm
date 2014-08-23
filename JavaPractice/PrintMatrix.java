public class PrintMatrix {
	public static void main(String[] args) {
	/*
		int[][] matrix = {
			{1,2,3,4,5},
			{6,7,8,9,10},
			{11,12,13,14,15},
			{16,17,18,19,20},
			{21,22,23,24,25}
		};*/
		int[][] matrix = {
			{1,2},
			{3,4}
		};
		
		printM(matrix);
	}
	
	static void printM(int[][] matrix) {
		int rowLen = matrix.length;
		int colLen = matrix.length;
		int leftBound = 0;
		int rightBound = colLen - 1;
		int upBound = 0;
		int downBound = rowLen - 1;
		int row = 0;
		int col =0;
		
		while (upBound<=downBound && leftBound<=rightBound) {
			if (leftBound == rightBound) {
				for(; row <= downBound; row++) {
					System.out.print(matrix[row][col]+",");
				}
				break;
			}
			if (upBound == downBound) {
				for(; col <= rightBound; col++) {
					System.out.print(matrix[row][col]+",");
				}
				break;
			}
			
			for (int i =0; i<2; i++) {
				if (col == leftBound) {
					for(; col < rightBound; col++) {
						System.out.print(matrix[row][col]+",");
					}
				}
				else if (col == rightBound) {
					for(; col > leftBound; col--) {
						System.out.print(matrix[row][col]+",");
					}
				}
				
				if (row == upBound) {
					for(; row < downBound; row++) {
						System.out.print(matrix[row][col]+",");
					}
				}
				else if (row == downBound) {
					for(; row > upBound; row--) {
						System.out.print(matrix[row][col]+",");
					}
				}
			}
			leftBound++;
			rightBound--;
			upBound++;
			downBound--;
			row++;
			col++;
		}
	}
}