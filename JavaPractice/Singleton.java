/*method 1*/
public class Singleton {
	private Singleton() {}
	private static Singleton instance = new Singleton();
	public static Singleton getInstance() {
		return instance;
	}
}

/*method 2*/
public class Singleton {
	private Singleton() {}
	private static Singleton instance = null;
	public static synchronized Singleton getInstance() {
		if (instance == null) {
			instance = new Singleton();
		}
		return instance;
	}
}