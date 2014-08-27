interface Fruit {
	public void eat();
}

class Apple implements Fruit {
	public void eat() {
		System.out.println("**apple");
	}
}

class Orange implements Fruit {
	public void eat() {
		System.out.println("**orange");
	}
}

class Factory {
	public static Fruit getInstance(String s) {
		Fruit f = null;
		if ("apple".equals(s)) {
			f = new Apple();
		}
		if ("orange".equals(s)) {
			f = new Orange();
		}
		return f;
	}
}

public class SimpleFactory {
	public static void main(String[] args) {
		Fruit f = null;
		if (args[0] != null) {
			f = Factory.getInstance(args[0]);
			if (f != null) {
				f.eat();
			}
		}
	}
}