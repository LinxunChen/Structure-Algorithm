public class StrProcessing {
	public static String strFilter (String str) {
		if (str==null || str.length()==0) {
			return null;
		}
		
		/*遍历字符数组，计算新字符数组的长度*/
		char[] chArray = str.toCharArray();
		int numOfErased = 0;
		boolean flagOfA = false;
		for(int i=0; i<chArray.length; i++) {
			if (chArray[i] == 'c') {
				numOfErased++;
				flagOfA = false;
			}
			else if(chArray[i]=='a') {
				flagOfA = true;
			}
			else if(flagOfA==true && chArray[i]=='b') {
				numOfErased += 2;;
				flagOfA = false;
			}
			else {
				flagOfA = false;
			}
		}
		int newLength = chArray.length - numOfErased;
		
		/*从字符数组队首开始，将'ab','c'替换成其他元素*/
		int indexOfOriginal = 0;
		int indexOfONew = 0;
		flagOfA = false;
		for (indexOfOriginal=0; indexOfOriginal<chArray.length; indexOfOriginal++) {
			if (chArray[indexOfOriginal] == 'c') {
				flagOfA = false;
				continue;
			}
			else if (chArray[indexOfOriginal] == 'a') {
				flagOfA = true;;
				chArray[indexOfONew] = chArray[indexOfOriginal];
				indexOfONew++;
			}
			else if (flagOfA==true && chArray[indexOfOriginal]=='b') {
				indexOfONew--;
				flagOfA = false;
			}
			else {
				flagOfA = false;
				chArray[indexOfONew] = chArray[indexOfOriginal];
				indexOfONew++;
			}
		}
		str = new String(chArray, 0, newLength);
		return str;
	}
	
	public static void main(String[] args) {
		String str1 = "jfyabitc3407a";	
		str1 = strFilter(str1);
		System.out.println(str1);
		
		String str2 = "";	
		str2 = strFilter(str2);
		System.out.println(str2);
		
		String str3 = null;	
		str3 = strFilter(str3);
		System.out.println(str3);
		
		String str4 = "abcbabababbab";	
		str4 = strFilter(str4);
		System.out.println(str4);
	}
}