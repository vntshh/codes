#include<bits/stdc++.h>
using namespace std;

struct nodes {
	int parent, setsize;
};

struct edge {
	int start, end;
};

nodes node[10];

int findroot(int temp) {
	if(node[temp].parent != temp)
		node[temp].parent = findroot(node[temp].parent);
	return node[temp].parent;
}

void takeunion(int x, int y) {
	int xroot = findroot(x), yroot = findroot(y);
	if(node[xroot].setsize >= node[yroot].setsize)
		node[yroot].parent = xroot;
	else node[xroot].parent = yroot;
	node[xroot].setsize = node[yroot].setsize = node[xroot].setsize + node[yroot].setsize;
}

int main() {
	for(int i = 0; i < 10; i++) {
		node[i].parent = i;
		node[i].setsize = 1;
	}
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin>>a>>b;
		takeunion(a,b);
	}
	for(int i = 0; i < n; i++) {
		int a, b;
		cin>>a>>b;
		if(findroot(a) == findroot(b)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
