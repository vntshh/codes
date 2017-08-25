#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node *left, *right, *parent;
};

void reheapify(struct node* given) {
	struct node *temp = given;
	//check up
	while(temp->parent) {
		if(temp->parent->data < temp->data) {
			swap(temp->parent->data, temp->data);
			temp = temp->parent;
		}
		else break;
	}
}

int hasBothChildren(struct node* root) {
	return ((root->right != NULL) && (root->left != NULL));
}
struct node* heapinsert(struct node* root, int val) {
	struct node* temp = (struct node*)malloc(sizeof(node));
	temp->data = val;
	temp->left = temp->right = NULL;
	if(root == NULL) {
		root = temp;
		return root;
	}
	struct node *trav, *gotcha;
	queue<struct node*> q;
	if(hasBothChildren(root))
		q.push(root);
	else gotcha = root;
	while(!q.empty()) {
		trav = q.front();
		if(hasBothChildren(trav->left)) q.push(trav->left);
		else {
			gotcha = trav->left;
			break;
		}
		if(hasBothChildren(trav->right)) q.push(trav->right);
		else {
			gotcha = trav->right;
			break;
		}
		q.pop();		
	}
	if(gotcha ->left == NULL) {
		gotcha->left = temp;
		temp->parent = gotcha;
		reheapify(gotcha->left);
	}
	else {
		gotcha->right = temp;
		temp->parent = gotcha;
		reheapify(gotcha->right);
	}
	return root;
}

void heaptraverse(struct node* root) {
	queue<struct node*> q;
	q.push(root);
	while(!q.empty()) {
		struct node* temp = q.front();
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		cout<<temp->data<<" ";
		q.pop();
	}
	cout<<endl<<endl;
}

int main() {
	int choice, val;
	struct node* root = NULL;
	while(1) {
		cout<<"\n1) Enter\n2) Traverse\n";
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"Enter value\n";
				cin>>val;
				root = heapinsert(root, val);
			break;
			case 2:
				heaptraverse(root);	
			break;
		}
	}
}
