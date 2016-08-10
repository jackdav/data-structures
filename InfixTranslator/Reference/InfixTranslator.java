import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Stack;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

/*
 * This program uses an expression tree to covert an infix expression into a postfix or prefix expression
 * By Jack Davis
 * March 31st 2015
 * 
 */
public class InfixTranslator implements ActionListener {
	//assigning variables
	JFrame frame = new JFrame();
	JButton prefix = new JButton();
	JButton postfix = new JButton();
	JTextField tfield = new JTextField("Please type in an Expression");
	JLabel output = new JLabel("Output");
	Container middle = new Container();
	BinaryNode root;
	public InfixTranslator() {
		//creates the JFrame
		root = new BinaryNode("5");
		BinaryNode newleftchild = new BinaryNode("2");
		root.setLeft(newleftchild);
		BinaryNode newrightchild = new BinaryNode("7");
		root.setRight(newrightchild);
		frame.setLayout(new BorderLayout());
		frame.setSize(300, 300);
		prefix = new JButton("Prefix");
		postfix = new JButton("Postfix");
		middle.setLayout(new GridLayout(1, 2));
		middle.add(prefix);
		middle.add(postfix);
		frame.add(middle, BorderLayout.CENTER);
		prefix.addActionListener(this);
		postfix.addActionListener(this);
		frame.add(tfield, BorderLayout.NORTH);
		frame.add(output, BorderLayout.SOUTH);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public String printInfix(BinaryNode currentRoot) {
		//prints the infix expression (left, center, right)
		if (currentRoot.getLeft() != null && currentRoot.getRight() != null) {
			return printInfix(currentRoot.getLeft()) + currentRoot.getValue() + printInfix(currentRoot.getRight());
		}
		else if (currentRoot.getLeft() == null && currentRoot.getRight() != null) {
			return currentRoot.getValue() + printInfix(currentRoot.getRight());
		}
		else if (currentRoot.getLeft() != null && currentRoot.getRight() == null) {
			return printInfix(currentRoot.getLeft()) + currentRoot.getValue();
		}
		else {
			return currentRoot.getValue();
		}
	}
	public static void main (String[] args) {
		//main method
		new InfixTranslator();
	}

	public void actionPerformed(ActionEvent e) {
		//what happens when the postfix or prefix buttons are pressed
		if (e.getSource().equals(prefix)) {
			root = createExpressionTree(tfield.getText());
			output.setText(printPrefix(root));
		}
		if (e.getSource().equals(postfix)) {
			root = createExpressionTree(tfield.getText());
			output.setText(printPostfix(root));
		}
	}
	public String printPrefix(BinaryNode currentRoot) {
		//prints the prefix expression (center, left, right)
		if (currentRoot.getLeft() != null && currentRoot.getRight() != null) {
			return currentRoot.getValue() + printPrefix(currentRoot.getLeft()) + printPrefix(currentRoot.getRight());
		}
		else if (currentRoot.getLeft() == null && currentRoot.getRight() != null) {
			return currentRoot.getValue() + printPrefix(currentRoot.getRight());
		}
		else if (currentRoot.getLeft() != null && currentRoot.getRight() == null) {
			return currentRoot.getValue() + printPrefix(currentRoot.getLeft());
		}
		else {
			return currentRoot.getValue();
		}
	}
	public String printPostfix(BinaryNode currentRoot) {
		//prints the postfix expression(left, right, center)
		if (currentRoot.getLeft() != null && currentRoot.getRight() != null) {
			return printPostfix(currentRoot.getLeft()) + printPostfix(currentRoot.getRight()) + currentRoot.getValue();
		}
		else if (currentRoot.getLeft() == null && currentRoot.getRight() != null) {
			return printPostfix(currentRoot.getRight()) + currentRoot.getValue() ;
		}
		else if (currentRoot.getLeft() != null && currentRoot.getRight() == null) {
			return printPostfix(currentRoot.getLeft()) + currentRoot.getValue();
		}
		else {
			return currentRoot.getValue();
		}
	}
	public BinaryNode createExpressionTree(String input) {
		//creates the expression tree
		input = "(" + input + ")";
		NodeStack stack = new NodeStack();
		for (int tokenIndex = 0; tokenIndex < input.length(); tokenIndex++) {
			char token = input.charAt(tokenIndex);
			BinaryNode tokenNode = new BinaryNode("" + token);
			System.out.println(token);
			if (token == '(') {
				stack.push(tokenNode);
			}
			else if (Character.isDigit(token)) {
				if (isOperator(stack.peek().getValue().charAt(0))) {
					BinaryNode operator = stack.pop();
					operator.setRight(tokenNode);
					stack.push(operator);
				}
				else {
					stack.push(tokenNode);
				}
			}
			else if (isOperator(token)) {
				BinaryNode top = stack.pop();
				tokenNode.setLeft(top);
				stack.push(tokenNode);
			}
			else { // token is )
				BinaryNode current = stack.pop();
				BinaryNode top = stack.pop();
				while (top.getValue().charAt(0) != '(') {
					top.setRight(current);
					current = top;
					top = stack.pop();
				}
				stack.push(current);
			}
		}
		return stack.pop();
	}
	public boolean isOperator(char token) {
		//checks to see if the value is an mathematical operator
		if (token == '+' || token == '-' || token == '*' || token == '/') {
			return true;
		}
		else return false;
	}
}
	
