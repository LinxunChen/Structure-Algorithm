import java.util.*;
import java.io.*;

public class SortToMin {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("please enter the length of the array:");
		int len = Integer.parseInt(br.readLine());
		int[] a = new int[len];
		
		System.out.println("please enter the array:");
		for (int i=0; i<len; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}

		sort(a);	
	}
	
	static void sort(int[] a) {	
		String[] aStr = new String[a.length];
		for (int i=0; i<a.length; i++) {
			aStr[i] = String.valueOf(a[i]);
		}
		
		Arrays.sort(aStr, new ComNum());
		
		String str = "";
		for (int i=0; i<a.length; i++) {
			str += aStr[i];
		}
		System.out.println(str);
	}
}

class ComNum implements Comparator<String>{
/*
	public int compare(String str1, String str2) {
		char[] a = (str1 + str2).toCharArray();
		char[] b = (str2 + str1).toCharArray();
		
		for(int i=0; i<a.length; i++) {
			if (a[i] < b[i]) {
				return -1;
			}
			else if (a[i] > b[i]){
				return 1;
			}
		}
		return 0;
	} 
	*/
	public int compare(String str1, String str2) {
		String a = str1 + str2;
		String b = str2 + str1;
		return a.compareTo(b);
	}
}