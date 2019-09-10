/*
input
13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0

output
node0: parent = -1,depth = 0, root, {1, 4, 10}
node1: parent = 0,depth = 1, internal node, {2, 3}
node2: parent = 1,depth = 2, leaf, {}
node3: parent = 1,depth = 2, leaf, {}
node4: parent = 0,depth = 1, internal node, {5, 6, 7}
node5: parent = 4,depth = 2, leaf, {}
node6: parent = 4,depth = 2, leaf, {}
node7: parent = 4,depth = 2, internal node, {8, 9}
node8: parent = 7,depth = 3, leaf, {}
node9: parent = 7,depth = 3, leaf, {}
node10: parent = 0,depth = 1, internal node, {11, 12}
node11: parent = 10,depth = 2, leaf, {}
node12: parent = 10,depth = 2, leaf, {}
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int p, l, r; };
Node T[MAX];
int n, D[MAX];

void print(int u) {
	int i, c;
	cout << "node" << u << ": ";
	cout << "parent = " << T[u].p << ",";
	cout << "depth = " << D[u]<<", ";

	if (T[u].p == NIL)cout << "root, ";
	else if (T[u].l == NIL)cout << "leaf, ";
	else cout << "internal node, ";

	cout << "{";
	for (i = 0, c = T[u].l;c != NIL;i++, c = T[c].r) {
		if (i)cout << ", ";
		cout << c;
	}
	cout << "}" << endl;
}
//再帰的に深さを求める
int calcDepth(int u, int p) {
	D[u] = p;
	if (T[u].r != NIL)calcDepth(T[u].r, p);		
//右の兄弟に同じ深さを設定
	if (T[u].l != NIL)calcDepth(T[u].l, p + 1);	
//最も左の子に自分の深さ+1を設定
	return 0;
}
int main(void) {
	int i, j, d, v, c, l, r;
	cin >> n;
	for (i = 0;i < n;i++)T[i].p = T[i].l = T[i].r = NIL;

	for (i = 0;i < n;i++) {
		cin >> v >> d;
		for (j = 0;j < d;j++) {
			cin >> c;
			if (j == 0)T[v].l = c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	for (i = 0;i < n;++i) {
		if (T[i].p == NIL) r = i;
	}
	calcDepth(r, 0);

	for (i = 0;i < n;i++)print(i);

	return 0;
}

