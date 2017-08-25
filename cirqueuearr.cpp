//insert delete traverse 
#include<bits/stdc++.h>
using namespace std;
int q[10];
void q_arr_insert(int val, int *front, int *rear, int size) {
	if(*rear == -1) {		//queue is empty
		*front = *rear = 0;
		q[*rear] = val;
	}
	else if((*rear + 1) % size == *front) {		//queue is full
		cout<<"Queue Full\n";
	}
	else {		//simple insertion in queue
		*rear = (*rear + 1) % size;
		q[*rear] = val;
		cout<<"Inserted\n";
	}
}
void q_arr_delete(int *front, int *rear, int size) {
	if(*rear == -1) {
		cout<<"Queue empty\n";
	}
	else if(*front == *rear) {
		*front = *rear = -1;
		cout<<"Deleted!\n";
	}
	else {
		*front = (*front + 1) % size;
		cout<<"Deleted!\n";
	}
}
void q_arr_traverse(int front, int rear, int size) {
	if(rear == -1) {
		cout<<"Queue Empty\n";
	else {
		int temp = front;
		while(temp != rear) {
			cout<<q[temp]<<" ";
			temp = (temp + 1) % size;
		}
		cout<<q[temp]<<endl;
	}
}
int main() {
	int front = -1, rear = -1, size = 10;
	int choice;
	while(1) {
		cout<<"1) Enter\n2) Delete\n3) Traverse\n";
		cin>>choice;
		switch(choice) {
			case 1:
				cout<<"Enter value: ";
				int val;
				cin>>val;
				q_arr_insert(val, &front, &rear, size);	
			break;
			case 2:
				q_arr_delete(&front, &rear, size);
			break;
			case 3:
				q_arr_traverse(front, rear, size);
			break;
		}
	}
}
