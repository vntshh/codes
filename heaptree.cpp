#include<bits/stdc++.h>
using namespace std;
vector<int> heap;
void insertAndReheapify(int temp) {
	float index = heap.size();
	heap.push_back(temp);
	float parent = ceil(index/2 - 1);
	while(parent >= 0 && (heap[parent] < heap[index])) {	
		swap(heap[parent], heap[index]);
		index = parent;
		parent = ceil(index/2 - 1);
	}
	cout<<"Inserted\n";
}
void deleteAndReheapify(int val) {
	int len = heap.size();
	float index;
	for(index = 0; heap[index] != val; index++);
	if(index == heap.size() - 1) {
		heap.pop_back();
		return;
	} 
	heap[index] = heap[len-1];
	heap.pop_back();
	float ti = index;
	float parent = ceil(index/2 - 1);
	while(parent >= 0 && (heap[parent] < heap[index])) {	
		swap(heap[parent], heap[index]);
		index = parent;
		parent = ceil(index/2 - 1);
	}
	index = ti;
	len--;
	int lchild = 2*index + 1;
	int rchild = 2*index + 2;
	while((lchild < len && heap[index]<heap[lchild]) || rchild < len && heap[index]<heap[rchild]) {
		if(lchild < len && heap[index]<heap[lchild] && heap[lchild] > heap[rchild]) {
			swap(heap[index], heap[lchild]);
			index = lchild;
		}
		if(rchild < len && heap[index]<heap[rchild] && heap[lchild] < heap[rchild]) {
			swap(heap[index], heap[rchild]);
			index = rchild;
		}
		lchild = 2*index + 1;
		rchild = 2*index + 2;
	}
	
} 

void traverse() {
	int len = heap.size();
	for(int i = 0; i < len; i++) {
		cout<<heap[i]<<" ";
	}
	cout<<endl<<endl;
}

int main() {
	int choice;
	while(1) {
		cout<<"1) Enter\n2) Delete\n3) Traverse\n";
		cin>>choice;
		int val;
		switch(choice) {
			case 1:
				cout<<"Enter value\n";
				cin>>val;
				insertAndReheapify(val);
			break;
			case 2:
				cin>>val;
				deleteAndReheapify(val);		
			break;
			case 3:
				traverse();	
			break;
		}
	}
}
