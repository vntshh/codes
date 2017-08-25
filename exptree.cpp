#include<bits/stdc++.h>
using namespace std;

struct node {
	char data;
	struct node *left, *right;
	int i;
};

int precedence(char ch) {
	if(ch == '^') return 3;
	if(ch == '/' || ch == '*') return 2;
	else return 1;
}

string toPostfix(string infix) {
	stack<char> s;
	string postfix = "";
	int len = infix.length();
	for(int i = 0; i < len; i++) {
		if(infix[i] == '(') s.push(infix[i]);
		else if (infix[i] == ')') {
			while(s.top() != '(') {
				postfix += s.top();
				s.pop();
			}
			s.pop();
		}
		else if(isalpha(infix[i])) postfix += infix[i];
		else {
			if(s.empty() || s.top() == '(') s.push(infix[i]);
			else {
				if(precedence(s.top()) >= precedence(infix[i])) {
					postfix += s.top();
					s.pop();
					i--;
				}
				else s.push(infix[i]);
			}
		}	
	}
	while(!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

struct node* exptree(string postfix) {
	stack<struct node*> s;
	int len = postfix.length();
	for(int i = 0; i < len; i++) {
		struct node* temp = (struct node*)malloc(sizeof(node));
		temp->data = postfix[i];
		if(isalpha(postfix[i])) {
			temp->left = temp->right = NULL;
			s.push(temp);
		}
		else {
			temp->right = s.top();
			s.pop();
			temp->left = s.top();
			s.pop();
			s.push(temp);
		}
	}
	return s.top();
}

int solve(int a, char c, int b) {
	if(c=='/') return a/b;
	if(c=='*') return a*b;
	if(c=='+') return a+b;
	if(c=='-') return a-b;
}

int inOrder(struct node* root) {
	if(root == NULL)
		return 0;
	if(isalpha(root->data)) {
		root->i = root->data - 'a';
		return (root->i + 1);
	}
	return(solve(inOrder(root->left), root->data, inOrder(root->right)));
}

int main() {
	string infix, postfix;
	cout<<"Enter infix expression\n";
	cin>>infix;
	postfix = toPostfix(infix);
	struct node* root = exptree(postfix);
	cout<<inOrder(root)<<endl;
}
