public class ProducerConsumer {
	public static void main(String[] args) {
		Container ct = new Container();
		Producer a = new Producer(ct);
		Producer b = new Producer(ct);
		Consumer c = new Consumer(ct);
		Consumer d = new Consumer(ct);
		
		new Thread(a).start();
		new Thread(d).start();
		new Thread(c).start();
		new Thread(d).start();
	}
}

class WoTo {
	int id;
	WoTo (int id) {
		this.id = id;
	}
	
	public String toString() {
		return "WoTo is:" + id;
	}
}

class Container {
	int vol = 10, index = 0;
	WoTo[] arrWT = new WoTo[vol];
	
	public synchronized void push(WoTo wt) {
		while(index == arrWT.length) {
			try{
				this.wait();
			}catch (InterruptedException ex) {
				ex.printStackTrace();
			}
		}
		this.notifyAll();
		arrWT[index] = wt;
		index++;
	}
	
	public synchronized WoTo pop() {
		while(index == 0) {
			try{
				this.wait();
			}catch (InterruptedException ex) {
				ex.printStackTrace();
			}
		}
		index--;
		this.notifyAll();
		return arrWT[index];
	}
}

class Producer implements Runnable {
	Container c = null;
	Producer (Container c) {
		this.c =c;
	}
	
	public void run() {
		for (int i = 0; i < 20; i++ ) {
			WoTo wt = new WoTo(i);
			c.push(wt);
			System.out.println("produce:" + wt);
		}
	}
}

class Consumer implements Runnable {
	Container c = null;
	Consumer (Container c) {
		this.c =c;
	}
	
	public void run() {
		for (int i = 0; i < 20; i++ ) {
			WoTo wt = c.pop();
			System.out.println("consume:" + wt);
			try{
				Thread.sleep(1000);
			}catch(InterruptedException ex) {
				ex.printStackTrace();
			}
		}
	}
}