#include <iostream>
#include <string>
using namespace std;

#include "linkedStack.h"

void displayLinkedStack(linkedStack<char>&); //get rid of linked word since this takes a template
void pushToLinkedStack(StackInterface<char>&);
void popLinkedStack(StackInterface<char>&);
void peekLinkedStack(StackInterface<char>&);
void isLinkedStackEmpty(StackInterface<char>&);

int operatorPrecedence(char c)
{
	int prec = 0;
	switch (c)
	{
	case '+':
		prec = 1;
		break;
	case '-':
		prec = 1;
		break;
	case '/':
		prec = 2;
		break;
	case '*':
		prec = 2;
		break;
	default:
		prec = -1;
		break;
	}
	return prec;
}

void infixToPostfix(StackInterface<char>& char_stack, StackInterface<float>& float_stack)
{
	//Evaluate postfix expression from infix expression
	string infix;
	string postfix;

	cout << "Choose an expression to convert to a postfix expression:" << endl;
	getline(cin, infix);
	getline(cin, infix);

	for (int i = 0; infix[i]; i++)
	{
		char c = infix[i];
		char stack_top;

		if (c == ' ') { continue; }

		if (isalpha(c) || isdigit(c))
		{
			postfix += c;
		}
		else if (c == '(')
		{
			char_stack.push(c);
		}
		else if (c == ')')
		{
			while (!char_stack.isEmpty() && char_stack.peek() != '(')
			{
				stack_top = char_stack.peek();
				postfix += stack_top;
				char_stack.pop();
			}
			if (!char_stack.isEmpty()) { char_stack.pop(); }
		}
		else //operator logic
		{
			int c_prec = operatorPrecedence(c);
			int top_prec = operatorPrecedence(char_stack.peek());

			//check for higher precedence compared to top of stack
			while (!char_stack.isEmpty() && top_prec >= c_prec)
			{
				stack_top = char_stack.peek();
				top_prec = operatorPrecedence(char_stack.peek());
				postfix += stack_top;
				char_stack.pop();
			}
			char_stack.push(c);
		}
	}

	while (!char_stack.isEmpty())
	{
		char stack_top = char_stack.peek();
		postfix += stack_top;
		char_stack.pop();
	}

	cout << "Postfix: " << postfix << endl;

	//Evaluate postfix to numerical answer
	for (int f = 0; postfix[f]; f++)
	{
		char c = postfix[f];
		int s = c - '0';
		float num_1;
		float num_2;

		if (isdigit(c))
		{
			float_stack.push(s);
		}
		else
		{
			num_1 = float_stack.peek();
			float_stack.pop();
			num_2 = float_stack.peek();
			float_stack.pop();

			switch (c)
			{
			case '+':
				float_stack.push(num_2 + num_1);
				break;
			case '-':
				float_stack.push(num_2 - num_1);
				break;
			case '*':
				float_stack.push(num_2 * num_1);
				break;
			case '/':
				float_stack.push(num_2 / num_1);
				break;
			}
		}
	}
	cout << "Answer: " << float_stack.peek() << endl;
	while (!float_stack.isEmpty()) { float_stack.pop(); } //clear stack
}

int main(void)
{
	int menu_choice;
	linkedStack<char> char_stack;
	linkedStack<float> float_stack;

	do {
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1. Input new infix expression." << endl;
		cout << "2. Push item to linked stack." << endl;
		cout << "3. Pop item from linked stack." << endl;
		cout << "4. Peek at top item from linked stack." << endl;
		cout << "5. Check if linked stack is empty." << endl;
		cin >> menu_choice;

		switch (menu_choice)
		{
		case 0:
			break;
		case 1:
			infixToPostfix(char_stack, float_stack);
			break;
		case 2:
			pushToLinkedStack(char_stack);
			break;
		case 3:
			popLinkedStack(char_stack);
			break;
		case 4:
			peekLinkedStack(char_stack);
			break;
		case 5:
			isLinkedStackEmpty(char_stack);
			break;
		default:
			cout << endl << "Invalid option!" << endl;
			break;
		}
	} while (menu_choice != 0);
	return 0;
}

void pushToLinkedStack(StackInterface<char>& stack)
{
	char newItem;

	cout << endl << "What is the item to push to the stack?" << endl;
	cin >> newItem;

	stack.push(newItem);
	cout << "Stack top: " << stack.peek() << endl;
}

void popLinkedStack(StackInterface<char>& stack)
{
	bool canPop = !stack.isEmpty();
	if (canPop)
	{
		stack.pop();
		cout << "The top item was popped from the stack." << endl;
	} 
	else 
	{
		cout << "There are no items left in the stack to pop." << endl;
	}
}

void peekLinkedStack(StackInterface<char>& stack)
{
	cout << "Stack top: " << stack.peek() << endl;
}

void isLinkedStackEmpty(StackInterface<char>& stack)
{
	if (stack.isEmpty())
	{
		cout << "The stack is empty!" << endl;
	}
	else { cout << "The stack is not empty!" << endl; }
}