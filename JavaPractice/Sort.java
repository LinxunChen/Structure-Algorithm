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
	
	public static void shellSort(int[] src) {
		for (int gap=src.length/2; gap>0; gap/=2) {
			for (int i=0; i<gap; i++) {
				for (int j=i+gap; j<src.length; j+=gap) {
					for (int k=j; (k>0) && (src[k]>src[k-1]); k--) {
						int temp = src[k];
						src[k] = src[k-1];
						src[k-1] = temp;
					}
				}
			}
		}
	}
	
	public static void mergeSort(int[] src, int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(src, start, mid);
			mergeSort(src, mid+1, end);
			merge(src, start, mid, end);
		}
	}
	
	public static void merge(int[] src, int start, int mid, int end) {
		int[] temp = new int[end-start+1];
		int i = start, j = mid + 1;
		int k =0;
		
		while (i<=mid && j<=end) {
			if (src[i] < src[j] ) {
				temp[k] = src[i];
				i++;
			}
			else {
				temp[k] = src[j];
				j++;
			}
			k++;
		}
		while (i <= mid) {
			temp[k] = src[i];
			k++;
			i++;
		}
		while (j <= end) {
			temp[k] = src[j];
			k++;
			j++;
		}
		k = start;
		for (int element : temp) {
			src[k] = element;
			k++;
		}
	}
	
	public static void heapSort(int[] src) {
		bulidMaxHeap(src);
		for (int i=src.length-1; i>0; i--) {
			swap(src, 0, i);
			heapify(src, 0, i-1);
		}
	}
	
	public static void bulidMaxHeap(int[] src) {
		for (int i=src.length/2; i>=0; i--) {
			heapify(src, i, src.length-1);
		}
	}
	
	public static void heapify(int[] src, int start, int end) {
		int i = start;
		int j =2 * i + 1;
		
		while (j <= end) {
			int largest = i;
			if (src[i] < src[j]) {
				largest = j;
			}
			if (j+1<=end && src[largest] < src[j+1]) {
				largest = j + 1;
			}
			if (i == largest) {
				break;
			}
			swap(src, i, largest);
			i = largest;
			j = 2 * i + 1;
		}
	}
	public static void swap(int[] src, int a, int b) {
		int temp = src[a];
		src[a] = src[b];
		src[b] = temp;
	}
	
	public static void main(String[] args) {
		int[] a = {4,2,4,56,7,2,1};
		heapSort(a);
		for (int i=0; i<a.length; i++) {
			System.out.println(a[i]);
		}
	}
}