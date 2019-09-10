#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define LEN 100005
typedef struct pp {
	char name[100];
	int t;
}P;
int head, tail, n;
P Q[LEN];

void initialize() {
	head = tail = 0;
}
void enqueue(P x) {
	Q[tail] = x;
	tail = (tail + 1) % LEN;	//tail==LEN -> tail=n+1
}
P dequeue() {
	P x = Q[head];
	head = (head + 1) % LEN;	//head==LEN -> head=1
	return x;
}
int main(void) {
	int elaps = 0, c;
	int q;
	P u;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> Q[i].name >> Q[i].t;
	}
	head = 1; tail = n + 1;
	//シミュレーション
	while (head != tail) {
		u = dequeue();
		c = min(q, u.t);	//qまたは55必要な時間u.tだけ処理を行う
		u.t -= c;	//残りの必要時間を計算
		elaps += c; //経過時間を加算
		if (u.t > 0) enqueue(u); //処理が完了しなければキューに追加
		else
			cout << u.name << " " << elaps << endl;
	}
	return 0;
}
