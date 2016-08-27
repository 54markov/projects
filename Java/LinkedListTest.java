class LinkedListNode {
	private	int number;
	private	String value;
	private	LinkedListNode ptrNext;

	public LinkedListNode() {
		number = (int)0;
		value = "0";
		ptrNext = null;
	}

	/* Node */
	public LinkedListNode(int num, String val, LinkedListNode ptr) {
		number = num;
		value = val;
		ptrNext = ptr;
	}

	public int getNumber() { return number; }
	public String getValue() { return value; }
	public LinkedListNode getNext() { return ptrNext; }

	public void setNext(LinkedListNode newNode) {
		this.ptrNext = newNode;
	}
}

class LinkedListImplementation {
	private LinkedListNode ptrHead;

	public LinkedListImplementation() {
		ptrHead = null;
	}

	public void addToList(LinkedListNode newNode) {
		if (ptrHead == null) {
			ptrHead = newNode;
		} else {
			newNode.setNext(ptrHead);
			ptrHead = newNode;
		}
	}

	public void showList() {
		int i = 1;
		LinkedListNode printNode = ptrHead;
		do {
			System.out.println("[printing node : " + i + "]");
			System.out.println("getting number: " + printNode.getNumber());
			System.out.println("getting value : " + printNode.getValue());
			System.out.println("");
			i++;
			printNode = printNode.getNext();
		} while (printNode != null);
	}

}

public class LinkedListTest {
	public static void main(String args[]) {
		test();
	}

	public static void test() {
		LinkedListImplementation linkedList = new LinkedListImplementation();

		for (int i = 0; i < 10; ++i) {
			LinkedListNode newNode = new LinkedListNode (i, "test_node", null);
			linkedList.addToList(newNode);
		}

		linkedList.showList();

	}
}