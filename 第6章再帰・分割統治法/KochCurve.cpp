/*
input
1

output
0.00000000 0.00000000
33.33333333 0.00000000
50.00000000 28.86751346
66.66666667 0.00000000
100.000000000 0.00000000
*/
#define _USE_MATH_DEFINES
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
#define rep(i,a,n) for(int i=a;i<=(int)n;i++)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;

struct Point { double x, y; };
void koch(int n, Point a, Point b) {
	if (n == 0)return;
	Point s, t, u;
	double th = M_PI * 60.0 / 180;	//度からラジアンへ変換

	s.x = (2.0*a.x + 1.0*b.x) / 3.0;
	s.y = (2.0*a.y + 1.0*b.y) / 3.0;
	t.x = (1.0*a.x + 2.0*b.x) / 3.0;
	t.y = (1.0*a.y + 2.0*b.y) / 3.0;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) - (t.y - s.y)*cos(th) + s.y;

	koch(n - 1, a, s);
	cout << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << t.x << " " << t.y << endl;
	koch(n - 1, t, b);
}
int main(void) {
	Point a, b;
	int n;
	cin >> n;
	a.x = 0.0;
	a.y = 0.0;
	b.x = 100.0;
	b.y = 0.0;
	cout << a.x << " " << a.y << endl;
	koch(n, a, b);
	cout << b.x << " " << b.y << endl;
	return 0;
}

