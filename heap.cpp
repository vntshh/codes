#include<bits/stdc++.h>
using namespace std;

int *a;

struct interval {
	int start, end;
};

vector<interval> v;
vector<int> end_time;

void ins_heap(int temp) {
	end_time.push_back(temp);
	int index = end_time.size() - 1;
	while(1) {
		int parent_index = (index - 1) / 2;
		if(end_time[parent_index] > end_time[index]) {
			swap(end_time[parent_index], end_time[index]);
			index = parent_index;
		}
		else break;
	}
}

void del_heap() {
	end_time[0] = end_time[end_time.size() - 1];
	end_time.erase(end_time.end()-1);
	int index = 0;
	while(1) {
		int lchild_index = 2*index + 1, rchild_index = 2*index + 2;
		if(lchild_index >= end_time.size()) break;
		else if(rchild_index >= end_time.size()){
			if(end_time[index] > end_time[lchild_index]) {
				swap(end_time[index], end_time[lchild_index]);
				index = lchild_index;
			}
			else break;
		}
		else {
			if(end_time[lchild_index] < end_time[index] && end_time[lchild_index] < end_time[rchild_index]) {
				swap(end_time[lchild_index], end_time[lchild_index]);
				index = lchild_index;
			}
			else if(end_time[rchild_index] < end_time[index] && end_time[rchild_index] < end_time[lchild_index]) {
				swap(end_time[rchild_index], end_time[index]);
				index = rchild_index;
			}
			else break;
		}
	}
}

int main() {
	/*int n;
	cin>>n;
	a = new int[n];*/
	int c;
	while(1) {
	cin>>c;
	switch(c) {
		case 1: int temp; cin>>temp;
		ins_heap(temp);
		for(int i = 0; i < end_time.size(); i++) {
			cout<<end_time[i]<<" ";
		}
		cout<<endl;	
		break;
		default: del_heap(); 
		for(int i = 0; i < end_time.size(); i++) {
			cout<<end_time[i]<<" ";
		}
		cout<<endl;
		break;
	}
	}
	return 0;
}
