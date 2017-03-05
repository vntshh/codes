#include<bits/stdc++.h>
using namespace std;

struct node {
	int parent, setsize;
};

struct edge {
	int src, dest, wt;
};

edge edges[100]; 
node nodes[100];
vector<edge> final;

bool cmp(const edge& e1, const edge& e2) {
	return (e1.wt < e2.wt);
}

int findroot(int i) {
	if(nodes[i].parent != i)
		nodes[i].parent = findroot(nodes[i].parent);
	return nodes[i].parent;
}

int takeunion(int x, int y) {
	int xroot = findroot(x);
	int yroot = findroot(y);
	if(nodes[yroot].setsize >= nodes[xroot].setsize)
		nodes[xroot].parent = yroot;
	else
		nodes[xroot].parent = yroot;
	nodes[xroot].setsize = nodes[yroot].setsize = nodes[xroot].setsize + nodes[yroot].setsize;
}

int main() {
	int n, e;
	cin>>n>>e;
	for(int i = 0; i < n; i++) {
		nodes[i].parent = i;
		nodes[i].setsize = 1;
	}
	for(int i = 0; i < e; i++) {
		cin>>edges[i].src>>edges[i].dest>>edges[i].wt;
	}
	sort(edges, edges + e, cmp);
	
	for(int i = 0; i < e; i++) {
		if(findroot(edges[i].src) != findroot(edges[i].dest)) {
			final.push_back(edges[i]);
			takeunion(edges[i].src, edges[i].dest);
		}
	}
	cout<<endl;
	for(int i = 0; i < final.size(); i++) {
		cout<<final[i].src<<" "<<final[i].dest<<endl;
	}
	return 0;
}
