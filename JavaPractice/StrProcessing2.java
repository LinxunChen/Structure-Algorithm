public class StrProcessing2 {
	
	public static void main(String[] args) {
		String str = null;	
		if (str!=null && str.length()!=0) {
			str = str.replace("ab", "").replace("c", "");
			System.out.println(str);
		}
	}
}