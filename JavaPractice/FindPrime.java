public class FindPrime {
	public static void main(String[] args) {
		int[] a = new int[101];
		
		for (int i=1; i<101; i++) {
			a[i] = 1; //all marks as prime
		}
		
		for (int i=2; i<101; i++) {
			if (a[i] == 1) {
				for (int j=i; j*i<=100; j++) {
					a[i*j] = 0;
				}
			}
		}
		
		for (int i=1; i<101; i++) {
			if (a[i] == 1) {
				System.out.println(i);
			}
		}
	}
}