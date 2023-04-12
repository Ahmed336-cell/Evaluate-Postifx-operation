#include<iostream>
#include<string>
using namespace std;
struct Node {
	int data;
	Node* node;
};
Node* top = NULL;
Node* temp;

void push(int val) {
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->node = NULL;
	if (top == NULL)
	{
		top = newnode;
		return;
	}
	newnode->node = top;
	top = newnode;

}

int pop() {
	int data;
	if (top == NULL) {
		return -1;
	}

	data = top->data;
	temp = top;
	top = top->node;
	free(temp);
	return data;


}

void display() {
	struct Node* n;
	if (top == NULL) {
		cout << "stack is empty" << endl;
	}
	else {
		n = top;
		cout << "your input is : "<<endl;
		while (n != NULL) {
			cout << n->data << " ";
			n = n->node;
		}
	}
	cout << endl;
}

bool isEmpty() {
	return top == NULL;
}

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluatePostix(string postifix) {
	int data=-1, op1,op2,result=0;
	for (int i = 0; i < postifix.length(); i++) {
		if (postifix[i] >= 48 && postifix[i] <= 57) {
			if (data == -1)
				data = 0;
			else
				data = data;

			data = (data * 10) + (postifix[i] - 48);
			continue;
		}

		if (data != -1) 
			push(data);
		

		if (isOperator(postifix[i])) {
			op2 = pop();
			op1 = pop();
			if (op1 == -1 || op2 == -1)
				break;
			
			switch (postifix[i]) {
			case '+':
				result = op1 + op2;
				push(result);
				break;
			case '-':
				result = op1 - op2;
				push(result);
				break;
			case '*':
				result = op1 * op2;
				push(result);
				break;
			case '/':
				result = op1 / op2;
				push(result);
				break;

			}
		}
		data = -1;
	
	}
	if (!isEmpty() &&top->node ==NULL)
	{
		cout << "answer of this postfix is :  " << top->data;
		return top->data;
	}
	else {
		cout << "your input is wrong";
		return -1;
	}

}
int main()

{

	string s;
	cout << "enter your postfix operation : " << endl;
	getline(cin,s);
	evaluatePostix(s);




}
