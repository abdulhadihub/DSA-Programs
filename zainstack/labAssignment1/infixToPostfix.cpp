#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int MAX = 101;
struct Stack
{
	char arr[MAX];
	int top;
};
Stack S;
bool isEmpty()
{
	if (S.top == -1)
	{
		return true;
	}
	return false;
}
void push(int x)
{
	if (S.top == MAX - 1)
	{
		cout << "error - stack overflow"<<endl;
		return;
	}
	S.top++;
	S.arr[S.top] = x;
}
void pop()
{
	if (isEmpty())
	{
		cout << "error - stack underflow"<<endl;
		return;
	}
	S.top--;
}
int toppop()
{
	return S.arr[S.top];
}

// Function to convert Infix expression to postfix
string InfixToPostfix(string expression);

// Function to verify whether an operator has higher precedence over other
int HasHigherPrecedence(char operator1, char operator2);

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C);

// Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool IsOperand(char C);

int main()
{
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = " << postfix << "\n";
}

// Function to evaluate Postfix expression and return output
string InfixToPostfix(string expression)
{
	S.top=-1;
	string postfix = ""; // Initialize postfix as empty string.
	for (int i = 0; i < expression.length(); i++)
	{

		// Scanning each character from left.
		// If character is a delimitter, move on.
		if (expression[i] == ' ' || expression[i] == ',')
			continue;
		// Else if character is an operand
		else if (IsOperand(expression[i]))
		{
			postfix += expression[i];
		}
		else if (expression[i] == '(')
		{
			push(expression[i]);
		}
		else if (expression[i] == ')')
		{
		while (!(isEmpty()) && toppop() != '(')
			{
				postfix += toppop();
				pop();
			}
			pop();
		}
		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if (IsOperator(expression[i]))
		{
			while (!(isEmpty()) && toppop() != '(' && HasHigherPrecedence(toppop(), expression[i]))
			{
				postfix += toppop();
				pop();
			}
			push(expression[i]);
		}
	}

	while (!(isEmpty()))
	{
		postfix += toppop();
		pop();
	}

	return postfix;
}

// Function to verify whether a character is english letter or numeric digit as digits can also be operands
// We are assuming in this solution that operand will be a single character
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9')
		return true;
	if (C >= 'a' && C <= 'z')
		return true;
	if (C >= 'A' && C <= 'Z')
		return true;
	return false;
}

// Function to verify whether a character is operator symbol or not.
bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^' || C == '%')
		return true;

	return false;
}



// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
	case '%':
		weight = 2;
		break;
	case '^':
		weight = 3;
		break;
	}
	return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);


	return op1Weight >= op2Weight ? true : false;
}
