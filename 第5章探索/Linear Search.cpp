#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)n;i++)
#define REP1(j,n) for(int j=0;j<(int)n;j++)
#define REPD(i,n) for(int i=n;i>=0;i--)
#define REPD1(j,n) for(int j=n;j=>0;j--)
#define REPS(i,n) for(int i=1;i<=(int)n;i++)
#define REPS1(j,n) for(int j=1;j<=(int)n;j++)
#define rep(i,a,n) for(int i=a;i<(int)n;i++)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;

int search(int a[], int n, int key) {
	int i = 0;
	a[n] = key;
	while (a[i] != key) {
		i++;
	}
	return i != n;
}
int main(void) {
	int n, q, a[10000 + 1], key, sum = 0;
	cin >> n;
	REP(i, n)cin >> a[i];
	cin >> q;
	REP(i, q) {
		cin >> key;
		if (search(a, n, key)) sum++;
	}
	cout << sum << endl;
	return 0;
}

