/*
テストケース
Input
10 9
0 1
0 2
3 4
5 7
5 6
6 7
6 8
7 8
8 9
3
0 1
5 9
1 3

Output
yes
yes
no
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

static const int MAX = 1e5;
static const int NIL = -1;
int n;
vector<int> G[MAX];	//隣接リスト
int color[MAX];

void dfs(int r, int c) {
	stack<int> s;
	s.push(r);
	color[r] = c;
	while (!s.empty()) {
		int u = s.top(); s.pop();
		//頂点uに隣接する頂点vを探索
		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if (color[v] == NIL) {
				color[v] = c;
				s.push(v);
			}
		}
	}
}
void assignColor() {
	int id = 1;
	for (int i = 0; i < n; ++i)color[i] = NIL;
	for (int u = 0; u < n; ++u) {
		if (color[u] == NIL)dfs(u, id++);
	}
}
int main(void) {
	int s, t, m, q;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> s >> t;
		G[s].push_back(t);
		G[s].push_back(s);
	}
	assignColor();
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> s >> t;
		if (color[s] == color[t]) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}