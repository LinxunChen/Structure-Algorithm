import java.io.*;

/* 判断是否为2的阶次方数*/
public class JudgePow2 {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(in.readLine());
		if (((num-1) & num) == 0) {
			System.out.println("YES");
		}
		else{
			System.out.println("NO");
		}
	}
}