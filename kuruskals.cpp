#include<bits/stdc++.h>
using namespace std;

struct subset {
	int parent;
};

struct edge {
	int src, dest, wt;
};

bool cmp(const edge& e1, const edge& e2) {
	return (e1.wt < e2.wt);
}

subset subsets[100];
edge edges[100]; 

int findroot(int node) {
	if(subsets[node].parent != node)
		subsets[node].parent = findroot(subsets[node].parent);
	return subsets[node].parent;
}

int takeunion(int x, int y) {
	int xroot = findroot(x);
	int yroot = findroot(y);
	subsets[yroot].parent = xroot;
}

int main() {
	int n;
	cin>>n;
	vector<edge> final;
	for(int i = 0; i < n; i++) {
		subsets[i].parent = i;
	}
	int t;
	cin>>t;
	for(int i = 0; i < t; i++) {
		cin>>edges[i].src;
		cin>>edges[i].dest;
		cin>>edges[i].wt;
	}
	sort(edges, edges + t, cmp);
	for(int i = 0; i < t; i++) {
		if(findroot(edges[i].src) != findroot(edges[i].dest)) {
			final.push_back(edges[i]);
			takeunion(edges[i].src, edges[i].dest);
		}
	}
	for(int i = 0; i < final.size(); i++) {
		cout<<final[i].src<<" "<<final[i].dest<<endl;
	}
	return 0;
}
