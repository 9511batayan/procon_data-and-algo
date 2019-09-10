#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <string.h>
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

#define M 1046527
#define NIL (-1)
#define L 14
char H[M][L];

//文字から数値に変換
int getChar(char ch) {
	if (ch == 'A') return 1;
	else if (ch == 'C') return 2;
	else if (ch == 'G') return 3;
	else if (ch == 'T')return 4;
	else return 0;
}

//文字列から数値を変換してkeyを生成する
ll getKey(char str[]) {
	ll sum = 0, p=1;
	REP(j, strlen(str)) {
		sum += p * (getChar(str[j]));
		p *= 5;
	}
	return sum;
}
int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

int find(char str[]) {
	ll key, i, h;
	key = getKey(str);	//文字列を数値に変換
	for (i = 0;; i++) {
		h = (h1(key) + i * h2(key)) % M;
		if (strcmp(H[h], str) == 0)return 1;
		else if (strlen(H[h]) == 0) {
			strcpy_s(H[h], str);
			return 0;
		}
	}
	return 0;
}
int insert(char str[]) {
	ll key, i, h;
	key = getKey(str);	//文字列を数値に変換
	for (i = 0;; i++) {
		h = (h1(key) + i * h2(key)) % M;
		if (strcmp(H[h], str) == 0) return 1;
		else if (strlen(H[h]) == 0) {
			strcpy_s(H[h], str);
			return 0;
		}
	}
	return 0;
}
int main(void) {
	int n;
	char str[L], com[9];
	REP(i, M) H[i][0] = '\0';
	cin >> n;
	REP(i, n) {
		cin >> com >> str;
		if (com[0] == 'i')
			insert(str);
		else {
			if (find(str)) {
				cout << "yes" << endl;
			}
			else
				cout << "no" << endl;
		}
	}
	return 0;
}

