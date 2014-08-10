import java.io.*;

/*求两个数的平方*/
public class Square {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String num = in.readLine();
		int number = Integer.parseInt(num);
		String num2 = in.readLine();
		int number2 = Integer.parseInt(num2);
		System.out.println(number + "'s square is" + number*number);
		System.out.println(number2 + "'s square is" + number2*number2);
	}
}