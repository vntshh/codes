#include <bits/stdc++.h>
using namespace std;
struct process {
	int bt, wt, tt;
};
int main () {
	cout<<"No. of processes : ";
	int n; cin>>n;
	process p[n];
	cout<<"Now enter burst times for each..."<<endl;
	for(int i = 0; i < n; i++) {
		cin>>p[i].bt;
	}
	p[0].wt = 0;
	p[0].tt = p[0].wt + p[0].bt;
	for(int i = 1; i < n; i++) {
		p[i].wt = p[i-1].tt;
		p[i].tt = p[i].wt + p[i].bt;
	}
	cout<<"ID  BT  WT  TT"<<endl;
	for(int i = 0; i < n; i++) {
		cout<<i+1<<"   "<<p[i].bt<<"   "<<p[i].wt<<"   "<<p[i].tt<<endl;
	}
	cout<<endl;
	float avgwt = 0, avgtt = 0;
	for(int i = 0; i < n; i++) {
		avgwt += p[i].wt;
		avgtt += p[i].tt;
	}
	cout<<"Average Waiting Time : "<<avgwt/n<<endl;
	cout<<"Average Turnaround Time : "<<avgtt/n<<endl;
	return 0;
}
