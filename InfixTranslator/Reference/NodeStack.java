import java.util.ArrayList;
/*
 * This class creates the NodeStack and gives it the various commands
 * By Jack Davis
 * March 31st 2015
 * 
 */

public class NodeStack {

	ArrayList<BinaryNode> stack;
	
	
	//creates the nodestack
	public NodeStack() {
		stack = new ArrayList<BinaryNode>();
	}
	//push command
	public void push(BinaryNode newnode) {
		stack.add(newnode);
	}
	//peek command
	public BinaryNode peek() {
		return stack.get(stack.size() - 1);
	}
	//pop command
	public BinaryNode pop() {
		BinaryNode top = stack.get(stack.size() - 1);
		stack.remove(stack.size()- 1);
		return top;
	}
}
