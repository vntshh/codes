#include<bits/stdc++.h>
using namespace std;

struct interval {
	int start, finish, wt;
};

bool cmp(const interval& in1, const interval& in2) {
	return in1.finish < in2.finish;
}

vector<interval> v;
int m[100];
int p[100];
int n;
int compatible_index(int val) {
	int comp;
	int low = 0, high = n;
	if(val < v[0].finish)
		return -1;
	while(high - low > 1) {
		int mid = (low + high) / 2;
		if(v[mid].finish <= val) low = mid;
		else high = mid - 1;
	}
	return low;
}
vector<int> backtrack;
int maxwt(int j) {
	if(m[j] == -1) {
		m[j] = max(v[j].wt + maxwt(p[j]), maxwt(j-1));
	}
	return m[j];
}

int main() {
	cin>>n;
	for(int i = 0; i < n; i++) {
		m[i] = -1;
	}
	for(int i = 0; i < n; i++) {
		interval temp;
		cin>>temp.start>>temp.finish>>temp.wt;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = n-1; i >= 0; i--) {
		p[i] = compatible_index(v[i].start);
	}
	for(int i = 0; i < n; i++) {
		cout<<v[i].start<<" "<<v[i].finish<<" "<<v[i].wt<<endl;
	}
	m[0] = v[0].wt;
	int ans = maxwt(n-1);
	cout<<ans;
	int j = n-1;
	while(j >= 0) {
		if(v[j].wt + maxwt(p[j]) > maxwt(j-1)) {
			backtrack.push_back(j);
			j = p[j];
		}
		else j--;
	}
	cout<<endl;
	for(int i = 0; i < backtrack.size(); i++) {
		cout<<backtrack[i]<<" ";
	}
}
