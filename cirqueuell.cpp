#include<bits/stdc++.h>
using namespace std;
struct node {
	int data;
	struct node* next;
};
struct node *front = NULL, *rear = NULL;
void qinsert(int val) {
	struct node* temp = (struct node*)malloc(sizeof(node));
	temp->data = val;
	if(rear == NULL) {
		front = rear = temp;
		rear->next = temp;
	}
	else {
		rear->next = temp;
		temp->next = front;
		rear = temp;
	}
	cout<<"Inserted\n";
}
void qdelete() {
	if(rear == NULL) {
		cout<<"Queue empty\n";
	}
	else if(rear == front) {
		front = rear = NULL;
		cout<<"Deleted\n";
	}
	else {
		rear->next = front->next;
		free(front);
		front = rear->next;
		cout<<"Deleted\n";
	}
}
void traverse() {
	if(rear == NULL) {
		cout<<"Queue empty\n";
	}
	else {
		struct node* temp = front;
		while(temp != rear) {
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
}
int main() {
	int choice;
	while(1) {
		cout<<"1) Enter\n2) Delete\n3) Traverse\n";
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"Enter value\n";
				int t;
				cin>>t;
				qinsert(t);
			break;
			case 2:
				qdelete();		
			break;
			case 3:
				traverse();	
			break;
		}
	}
}

