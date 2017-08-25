#include <bits/stdc++.h>
using namespace std;
struct process {
	int bt, wt, tt, at, rt, id;
};
struct cmp {
    bool operator() (const process &p1, const process &p2) {
        return p1.rt > p2.rt;
    }
};
int main () {
	cout<<"No. of processes : ";
	int n; cin>>n;
	process p[n];
	cout<<"Now enter arrival times (sorted) and burst times for each..."<<endl;
	for(int i = 0; i < n; i++) {
		cin>>p[i].at>>p[i].bt;
		p[i].rt = p[i].bt;
		p[i].id = i + 1;
	}
	
	priority_queue<process, vector<process>, cmp> heap;
	vector<int> order, landmarks;
	heap.push(p[0]);
	int landmark = 0, curjob = 1;
	while(!heap.empty()) {
		process temp = heap.top();
		if(!order.size() || order[order.size() - 1] != temp.id) {
			order.push_back(temp.id);
			landmarks.push_back(landmark);
		}
		heap.pop();
		int gap = temp.rt;
		if(curjob < n) gap = min(gap, p[curjob].at - landmark);
		if(curjob < n && gap == p[curjob].at - landmark) heap.push(p[curjob++]);
		landmark += gap;
		temp.rt -= gap;
		if(temp.rt) heap.push(temp);
	}
	landmarks.push_back(landmark);
	for(int i = 0; i < order.size(); i++) {
		cout<<"Process ID : "<<order[i]<<endl;
		cout<<"Start Time : "<<landmarks[i]<<endl;
		cout<<"End Time : "<<landmarks[i+1]<<endl;
		cout<<endl;
	}
	return 0;
}
