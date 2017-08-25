#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node *left, *right;
};

struct node* bstinsert(struct node* root, int val) {
	struct node* temp = (struct node*)malloc(sizeof(node));
	temp->data = val;
	temp->left = temp->right = NULL;
	if(root == NULL) {
		root = temp;
		cout<<"\nInserted\n\n";
		return root;
	}
	struct node* trav = root;
	while(1) {
		if(val < trav->data) {
			if(trav->left) {
				trav = trav->left;
			}
			else {
				trav -> left = temp;
				break;
			}
		}
		else if (val > trav->data) {
			if(trav->right) {
				trav = trav->right;
			}
			else {
				trav->right = temp;
				break;
			}
		}
	}
	cout<<"\nInserted\n\n";
	return root;
}

struct node* bstdelete(struct node* root, int val) {
	struct node* temp = root, *parent;
	while(temp->data != val) {
		parent = temp;
		if(val < temp->data) temp = temp->left;
		else temp = temp->right;
	}
	if(temp == root) {
		if(temp->left) {
			struct node* tp = temp->left;
			parent = temp;
			while(tp->right != NULL) {
				parent = tp;
				tp = tp->right;
			}
			temp->data = tp->data;
			free(tp);
			if(parent == temp)
				parent->left = NULL;
			else parent->right = NULL;
		}
		else {
			struct node* tp = temp->right;
			cout<<"%";
			parent = temp;
			while(tp->left != NULL) {
				parent = tp;
				tp = tp->left;
			}
			temp->data = tp->data;
			free(tp);
			if(parent == temp) 
				parent->right = NULL;
			else parent->left = NULL;
		}
	}
	else if(!temp->left && !temp->right) {
		free(temp);
		temp = NULL;
	}
	else if(temp->left && temp->right) {
		struct node* tp = temp->left;
		while(tp->right != NULL) {
			tp = tp->right;
		}
		temp->data = tp->data;
		free(tp);
		tp = NULL;
	}
	else {
		if(parent -> left == temp) {
			if(temp->left) parent->left = temp->left;
			else parent->left = temp->right;
		}
		else {
			if(temp->left) parent->right = temp->left;
			else parent->right = temp->right;
		}
	}
	return root;
}

void inOrder(struct node* root) {
	if(root == NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}
int main() {
	int choice;
	struct node* root = NULL;
	while(1) {
		cout<<"1) Enter\n2) Delete\n3) Traverse\n";
		cin>>choice;
		int val;
		switch(choice) {
			case 1:
				cout<<"Enter value\n";
				cin>>val;
				root = bstinsert(root, val);
			break;
			case 2:
				cin>>val;
				bstdelete(root, val);
			break;
			case 3:
				inOrder(root);
				cout<<endl<<endl;	
			break;
		}
	}
}
