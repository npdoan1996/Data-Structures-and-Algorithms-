import java.util.*;

// A Map ADT structure using a red-black tree, where keys must implement
// Comparable.
// The key type of a map must be Comparable. Values can be any type.
public class RedBlackTreeMap<TKey extends Comparable<TKey>, TValue> {
	// A Node class.
	private class Node {
		private TKey mKey;
		private TValue mValue;
		private Node mParent;
		private Node mLeft;
		private Node mRight;
		private boolean mIsRed;

		// Constructs a new node with NIL children.
		public Node(TKey key, TValue data, boolean isRed) {
			mKey = key;
			mValue = data;
			mIsRed = isRed;

			mParent = null;
			mLeft = NIL_NODE;
			mRight = NIL_NODE;
		}

		@Override
		public String toString() {
			return mKey + " : " + mValue + " (" + (mIsRed ? "red)" : "black)");
		}
	}

	private Node mRoot;
	private int mCount;

	// Rather than create a "blank" black Node for each NIL, we use one shared
	// node for all NIL leaves.
	private final Node NIL_NODE = new Node(null, null, false);

	//////////////////// I give you these utility functions for free.

	// Get the # of keys in the tree.
	public int getCount() {
		return mCount;
	}

	// Finds the value associated with the given key.
	public TValue find(TKey key) {
		Node n = bstFind(key, mRoot); // find the Node containing the key if any
		if (n == null || n == NIL_NODE)
			throw new RuntimeException("Key not found");
		return n.mValue;
	}

	// Inserts a key/value pair into the tree, updating the red/black balance
	// of nodes as necessary. Starts with a normal BST insert, then adjusts.
	public void add(TKey key, TValue data) {
		Node n = new Node(key, data, true); // nodes start red

		// normal BST insert; n will be placed into its initial position.
		// returns false if an existing node was updated (no rebalancing needed)
		boolean insertedNew = bstInsert(n, mRoot);
		if (!insertedNew)
			return;

		// check cases 1-5 for balance violations.
		checkBalance(n);
	}

	// Applies rules 1-5 to check the balance of a tree with newly inserted
	// node n.
	private void checkBalance(Node n) {

		if (n == mRoot) {
			// case 1: new node is root.
			n.mIsRed = false;
			return;
		}
		Node p = n.mParent;
		// handle additional insert cases here.
		if (p.mIsRed == false) {
			// case 2: P is black
			return;
		} else {
			Node u = getUncle(n);
			Node gp = getGrandparent(n);
			if (u.mIsRed == true) {
				// case 3: P and U are red
				p.mIsRed = false;
				u.mIsRed = false;
				gp.mIsRed = true;
				if (gp == mRoot || gp.mParent.mIsRed == true)
					checkBalance(getGrandparent(n));
			} else if (getUncle(n).mIsRed == false) {
				// case 4: N is the lr and rl grandchild of G
				if (gp == null) {
					return;
				}

				if (gp.mLeft.mRight == n) {
					singleRotateLeft(p);
				} else if (gp.mRight.mLeft == n) {
					singleRotateRight(p);
				}

				// case 5: N is the ll or rr grandchild of G
				if (gp.mLeft == n || gp.mLeft.mLeft == n) {
					singleRotateRight(gp);
					gp.mParent.mIsRed = false;
					gp.mIsRed = true;
				} else if (gp.mRight == n || gp.mRight.mRight == n) {
					singleRotateLeft(gp);
					gp.mParent.mIsRed = false;
					gp.mIsRed = true;
				}
			}
		}
	}

	// Returns true if the given key is in the tree.
	public boolean containsKey(TKey key) {
		// TODO: using at most three lines of code, finish this method.
		// HINT: write the bstFind method first.
		Node n = bstFind(key, mRoot); // find the Node containing the key if any
		return (n == null) ? false : true;
	}

	// Prints a pre-order traversal of the tree's nodes, printing the key, value,
	// and color of each node.
	public void printStructure() {
		// TODO: a pre-order traversal. Will need recursion.
		printStructure(mRoot);
	}

	private void printStructure(Node n) {
		if (n == null || n == NIL_NODE)
			return;
		System.out.println(n.toString());
		printStructure(n.mLeft);
		printStructure(n.mRight);
	}

	// Retuns the Node containing the given key. Recursive.
	private Node bstFind(TKey key, Node currentNode) {
		// TODO: write this method. Given a key to find and a node to start at,
		// proceed left/right from the current node until finding a node whose
		// key is equal to the given key.
		if (currentNode == null || currentNode == NIL_NODE)
			return null;
		int compare = currentNode.mKey.compareTo(key);
		if (compare < 0) {
			// key is larger; go right.
			return bstFind(key, currentNode.mRight);
		} else if (compare > 0) {
			return bstFind(key, currentNode.mLeft);
		} else if (compare == 0) {
			// found a node with the given key; return the found node
			return currentNode;
		} else {
			return null;
		}
	}

	// Gets the grandparent of n.
	private Node getGrandparent(Node n) {
		// TODO: return the grandparent of n
		if (n.mParent.mParent != null)
			return n.mParent.mParent;
		else
			return null;
	}

	// Gets the uncle (parent's sibling) of n.
	private Node getUncle(Node n) {
		Node gp = getGrandparent(n);
		if (gp == null)
			return null;
		else if (gp.mLeft == n.mParent)
			return gp.mRight;
		else
			return gp.mLeft;
	}

	// Rotate the tree right at the given node.
	private void singleRotateRight(Node n) {
		Node l = n.mLeft, lr = l.mRight, p = n.mParent;
		n.mLeft = lr;
		lr.mParent = n;
		l.mRight = n;
		n.mParent = l;

		if (p == null) { // n is root
			mRoot = l;
		} else if (p.mLeft == n) {
			p.mLeft = l;
		} else {
			p.mRight = l;
		}

		l.mParent = p;
	}

	// Rotate the tree left at the given node.
	private void singleRotateLeft(Node n) {
		// TODO: do a single left rotation (AVL tree calls this a "rr" rotation)
		// at n.
		Node r = n.mRight, rl = r.mLeft, p = n.mParent;
		n.mRight = rl;
		rl.mParent = n;
		r.mLeft = n;
		n.mParent = r;

		if (p == null) { // n is root
			mRoot = r;
		} else if (p.mLeft == n) {
			p.mLeft = r;
		} else {
			p.mRight = r;
		}

		r.mParent = p;
	}

	// This method is used by insert. It is complete.
	// Inserts the key/value into the BST, and returns true if the key wasn't
	// previously in the tree.
	private boolean bstInsert(Node newNode, Node currentNode) {
		if (mRoot == null) {
			// case 1
			mRoot = newNode;
			mCount++;
			return true;
		} else {
			int compare = currentNode.mKey.compareTo(newNode.mKey);
			if (compare < 0) {
				// newNode is larger; go right.
				if (currentNode.mRight != NIL_NODE) {
					return bstInsert(newNode, currentNode.mRight);
				} else {
					currentNode.mRight = newNode;
					newNode.mParent = currentNode;
					mCount++;
					return true;
				}
			} else if (compare > 0) {
				if (currentNode.mLeft != NIL_NODE) {
					return bstInsert(newNode, currentNode.mLeft);
				} else {
					currentNode.mLeft = newNode;
					newNode.mParent = currentNode;
					mCount++;
					return true;
				}
			} else {
				// found a node with the given key; update value.
				currentNode.mValue = newNode.mValue;
				return false; // did NOT insert a new node.
			}
		}
	}
}
