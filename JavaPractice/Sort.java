public class Sort {
	public static void bubbleSort(int[] src) {
		for (int i=src.length-1; i>0; i--) {
			boolean exchange =false;
			for (int j=0; j<i; j++) {
				if (src[j] < src[j+1]) {
					int temp = src[j];
					src[j] = src[j+1];
					src[j+1] = temp;
					exchange = true;
				}
			}
			if (!exchange) {
				return;
			}
		}
	}
	
	public static void selectSort(int[] src) {
		for (int i=0; i<src.length-1; i++) {
			int min = i;
			for (int j=i+1; j<src.length; j++) {
				if (src[j] < src[min]) {
					min = j;
				}
			}
			int temp = src[i];
			src[i] = src[min];
			src[min] = temp;
		}
	}
	
	public static void insertSort(int[] src) {
		if (src == null) {
			System.out.println("error");	
		}
		for (int i=1; i<src.length; i++) {
			for (int j=i; (j>0) && (src[j]<src[j-1]); j--) {
				int temp = src[j];
				src[j] = src[j-1];
				src[j-1] = temp;
			}
		}
	}
	
	public static void quickSort(int[] src, int start, int end) {
		if (start < end) {
			int pivot = partition(src, start, end);
			quickSort(src, start, pivot-1);
			quickSort(src, pivot+1, end);
		}
	}
	
	public static int partition(int[] src, int start, int end) {
		int pivot = start;
		int sep = start;
		for (int i=start+1; i<=end; i++) {
			if (src[i] < src[pivot]) {
				sep++;
				int temp1 = src[sep];
				src[sep] = src[i];
				src[i] = temp1;
			}
		}
		int temp2 = src[pivot];
		src[pivot] = src[sep];
		src[sep] = temp2;
		return sep;
	}
	
	public static void main(String[] args) {
		int[] a = {4,2,4,56,7,2,1};
		quickSort(a, 0, a.length-1);
		for (int i=0; i<a.length; i++) {
			System.out.println(a[i]);
		}
	}
}