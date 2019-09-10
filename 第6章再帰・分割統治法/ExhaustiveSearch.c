/*
input
5
1 5 7 10 21
4
2 4 17 8

output
no
no
yes
yes
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> a;
bool solve(int i, int m) {
	if (m == 0)return true;
	if (i >= n)return false;
	int res = solve(i + 1, m) || solve(i + 1, m - a[i]);
	return res;
}
int main(void) {
	int q, m;
	cin >> n;
	for (int i = 0;i < n;++i) {
		int input;
		cin >> input;
		a.push_back(input);
	}
	cin >> q;
	vector<string> ans(q);
	for (int i = 0;i < q;i++) {
		cin >> m;
		if (solve(0, m)) ans[i] = "yes";
		else ans[i]="no";
	}
	for (int i = 0;i < q;++i) cout << ans[i] << endl;
	return 0;
}
