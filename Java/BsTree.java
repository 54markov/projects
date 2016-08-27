class BsTreeNode {
	private int key;
	private String value;
	private BsTreeNode left;
	private BsTreeNode right;

	public BsTreeNode(int rKey, String rValue) {
		this.key = rKey;
		this.value = rValue;
		this.left = null;
		this.right = null;
	}

	public int getKey() { return this.key; }
	public String getValue() { return this.value; }
	public BsTreeNode getLeftChild() { return this.left; }
	public BsTreeNode getRightChild() { return this.right; }

	public void setLeftChild(BsTreeNode rLeft) { this.left = rLeft; }
	public void setRightChild(BsTreeNode rRight) { this.right = rRight; }

	public void printNode(int level) {
		for (int i = 0; i < level; ++i) {
			System.out.print(" ");
		}
		System.out.println("key  : " + this.getKey());

		for (int i = 0; i < level; ++i) {
			System.out.print(" ");
		}
		System.out.println("value: " + this.getValue());
	}
}

class BinarySearchTree {
	private BsTreeNode root;

	public BinarySearchTree() {
		this.root = null;
	}

	public BsTreeNode getRoot() { return this.root; }

	public void addToTree(int key, String value) {

		BsTreeNode newNode = new BsTreeNode(key, value);

		if (this.root == null) {
			root = newNode;
			return;
		}

		BsTreeNode curPtr = this.root;
		BsTreeNode parent = null;

		while (true) {
			parent = curPtr;

			if (key < curPtr.getKey()) {
				curPtr = curPtr.getLeftChild();
				if (curPtr == null) {
					parent.setLeftChild(newNode);
					return;
				}
			} else {
				curPtr = curPtr.getRightChild();
				if (curPtr == null) {
					parent.setRightChild(newNode);
					return;
				}
			}
		}

	}

	public void printTree(BsTreeNode node, int i) {
		++i;

		if (node == null) {
			return;
		}
		printTree(node.getLeftChild(), i);
		printTree(node.getRightChild(), i);
		node.printNode(i);
	}
	
}


public class BsTree {
	public static void main(String args[]) {
		test();
	}

	public static void test() {
		BinarySearchTree tree = new BinarySearchTree();

		tree.addToTree(5, "test_root");

		for (int i = 0; i < 10; ++i) {
			tree.addToTree(i, "test_value");
		}
		tree.printTree(tree.getRoot(), 0);

	}
}