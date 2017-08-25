#include <bits/stdc++.h>
using namespace std;
struct process {
	int bt, wt, tt, at, rt;
};
int main () {
	cout<<"No. of processes : ";
	int n; cin>>n;
	process p[n];
	cout<<"Now enter arrival times (sorted) and burst times for each..."<<endl;
	for(int i = 0; i < n; i++) {
		cin>>p[i].at>>p[i].bt;
		p[i].rt = p[i].bt;
	}
	int quantum = 100, next = 1, clock = 0, curtime = 0;
	queue<int> q;
	q.push(0);
	vector<int> schedule, starttime, endtime;
	while (!q.empty()) {
		schedule.push_back(q.front());
		starttime.push_back(curtime);
		curtime += min(quantum, p[q.front()].rt);
		while((next < n) && p[next].at <= curtime) {
			q.push(next);
			next++;
		}
		p[q.front()].rt -= quantum;
		if(p[q.front()].rt > 0) q.push(q.front());
		q.pop();
		endtime.push_back(curtime);
	}
	cout<<endl;
	for(int i = 0; i < schedule.size(); i++) {
		cout<<"Process ID : "<<schedule[i]<<endl;
		cout<<"Start Time : "<<starttime[i]<<endl;
		cout<<"End Time : "<<endtime[i]<<endl;
		cout<<endl;
	}
	return 0;
}
