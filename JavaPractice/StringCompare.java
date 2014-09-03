import java.util.*;

public class StringCompare {
	public static void main(String[] args) {
		String a = "achmacmh";
		String b ="macham";
		
		String maxComString = getMaxLengthCommonString(a, b);
		System.out.println(maxComString);
	}
	
	public static String getMaxLengthCommonString(String a, String b) {
		if (a == null || b == null) {
			return null;
		}
	
		int rowLen = a.length();
		int colLen = b.length();
		if (rowLen==0 || colLen ==0) {
			return "";
		}
		
		boolean[][] strMatrix = new boolean[rowLen][colLen];	
		for (int i=0; i<rowLen && i<colLen; i++) {
			for (int j=0; j<colLen; j++) {
				if (a.charAt(i) == b.charAt(j)) {
					strMatrix[i][j] = true;
				}
				else {
					strMatrix[i][j] = false;
				}
			}
		}

		List<String> commonStr = new ArrayList<String>();
		for (int i=0,j=0; j<colLen; j++) {
			String record = "";
			int iDiag = i;
			int jDiag = j;
			while (iDiag != rowLen && jDiag != colLen) {
				if(strMatrix[iDiag][jDiag] == false) {
					if (!record.equals("")) {
						commonStr.add(record);
					}
					record = "";
				}
				else{
					record += b.charAt(jDiag);
					if (iDiag == rowLen-1 || jDiag == colLen-1) {
						commonStr.add(record);
					}
				}
				iDiag++;
				jDiag++;
			}		
		}

		for (int i=1,j=0; i<colLen; i++) {
			String record = "";
			int iDiag = i;
			int jDiag = j;
			while (iDiag != rowLen && jDiag != colLen) {
				if(strMatrix[iDiag][jDiag] == false) {
					if (!record.equals("")) {
						commonStr.add(record);
					}
					record = "";
				}
				else{
					record += a.charAt(iDiag);
					if (iDiag==rowLen-1 || jDiag == colLen-1) {
						commonStr.add(record);
					}
				}
				iDiag++;
				jDiag++;
			}
		}

		Collections.sort(commonStr, new Comparator<String>() {
			public int compare(String a, String b) {
				return b.length() - a.length();
			}
		});

		int num = 1;
		int maxLen=commonStr.get(0).length();
		int i = 1;
		while (commonStr.get(i).length() == maxLen) {
			num++;
			i++;
		}
		
		String MaxCommonStr = "";
		for (int k=0; k<num; k++) {
			MaxCommonStr += (commonStr.get(k) + " ");
		}
		return MaxCommonStr;
	}
}