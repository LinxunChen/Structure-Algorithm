public class StrProcessing3 {
	public static String strFilter (String str) {
		if (str==null || str.length()==0) {
			return null;
		}
		
		char[] chArray = str.toCharArray();
		int indexOfOriginal = 0;
		int indexOfONew = 0;
		for (indexOfOriginal=0; indexOfOriginal<chArray.length; indexOfOriginal++) {
			if (chArray[indexOfOriginal] == 'c') {
				continue;
			}
			else if (chArray[indexOfOriginal] == 'a') {
				chArray[indexOfONew++] = chArray[indexOfOriginal];
			}
			else if (indexOfONew>0 && chArray[indexOfONew-1]=='a' && chArray[indexOfOriginal]=='b') {
				indexOfONew--;
			}
			else {
				chArray[indexOfONew++] = chArray[indexOfOriginal];
			}
		}
		str = new String(chArray, 0, indexOfONew);
		return str;
	}
	
	public static void main(String[] args) {
		String str1 = "jfyabitc3407a";	
		str1 = strFilter(str1);
		System.out.println(str1);
		
		String str2 = "aacbccbb";	
		str2 = strFilter(str2);
		System.out.println(str2);
		
		String str3 = "acb";	
		str3 = strFilter(str3);
		System.out.println(str3);
		
		String str4 = "aabb";	
		str4 = strFilter(str4);
		System.out.println(str4);
	}
}