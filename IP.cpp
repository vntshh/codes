#include<bits/stdc++.h>
using namespace std;
struct slot {
	int start, end;
};

vector<slot> minheap, lecture;

void pushheap(slot temp) {
	int index = minheap.size();
	minheap.push_back(temp);
	int parent = (index - 1) / 2;
	while(parent >= 0) {
		if(minheap[parent].end > minheap[index].end) {
			swap(minheap[parent], minheap[index]);
			index = parent;
			parent = (index - 1) / 2;
		}
		else break;
	}
}

void updateheap(slot temp) {
	minheap[0] = temp;
	int index = 0;
	int lchild = 2*index + 1, rchild = 2*index + 2;
	while(1) {
		if(rchild >= minheap.size()) {
			if(lchild >= minheap.size()) break;
			else {
				if(minheap[index].end > minheap[lchild].end) {
					swap(minheap[index], minheap[lchild]);
					index = lchild; lchild = 2*index + 1; rchild = 2*index + 2;
				}
			}
		}
		else if(minheap[index].end > minheap[lchild].end && minheap[lchild].end <= minheap[rchild].end) {
			swap(minheap[index], minheap[lchild]);
			index = lchild; lchild = 2*index + 1; rchild = 2*index + 2;
		}
		else if(minheap[index].end > minheap[rchild].end && minheap[rchild].end <= minheap[lchild].end) {
			swap(minheap[index], minheap[rchild]);
			index = rchild; lchild = 2*index + 1; rchild = 2*index + 2;
		}
		else break;
	}
}

bool cmp(const slot& l1, const slot &l2) {
	return (l1.start < l2.start);
}

int main() {
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		slot temp;
		cin>>temp.start>>temp.end;
		lecture.push_back(temp);
	}
	sort(lecture.begin(), lecture.end(), cmp);
	int classrooms = 1;
	pushheap(lecture[0]);
	for(int i = 1; i < lecture.size(); i++) {
		if(minheap[0].end <= lecture[i].start) {
			updateheap(lecture[i]);
		}
		else {
			classrooms++;
			pushheap(lecture[i]);
		}
	}
	cout<<classrooms;
	return 0;
}
