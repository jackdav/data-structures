/*
 * This class creates the binary node and its commands
 * By Jack Davis
 * March 31st 2015
 * 
 */
public class BinaryNode {
	String value;
	BinaryNode left;
	BinaryNode right;
	static int counter = 0;
	public BinaryNode() {
		value = "";
		left = null;
		right = null;
		counter++;
	}
	
	public BinaryNode(String newValue) {
		this();
		value = newValue;
	}
	//creates the binary node
	public BinaryNode(String newValue, BinaryNode newLeft, BinaryNode newRight) {
		this();
		value = newValue;
		left = newLeft;
		right = newRight;
	}
	//gets count of the amount of nodes
	public int getNodeCount() {
		return counter;
	}
	//returns the value
	public String getValue() {
		return value;
	}
	//sets the value
	public void setValue(String newValue) {
		value = newValue;
	}
	//returns the left value
	public BinaryNode getLeft() {
		return left;
	}
	//sets a value to the left
	public void setLeft(BinaryNode newLeft){
		left = newLeft;
	}
	//returns the right
	public BinaryNode getRight() {
		return right;
	}
	//sets a value to the right
	public void setRight(BinaryNode newRight){
		right = newRight;
	}
	
}
