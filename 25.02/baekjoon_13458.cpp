#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long N;
long B;
long C;
long ans = 0;

queue<long> q;

void input() {
	cin >> N;

	long a;
	for (long i = 0; i < N; i++) {
		cin >> a;
		q.push(a);
	}
	cin >> B >> C;
}

void cal() {

	while (!q.empty()) {
		long now = q.front();
		q.pop();

		if (B >= C) {
			now -= B;
			ans += 1;
			if (now <= 0) continue;
			else {
				ans += (now / C);
				if (now % C != 0) ans += 1;
			}
		}
		else {
			ans += (now / C);
			if (now % C > B) ans += 2;
			else ans += 1;
		}
	}

	cout << ans;
}

int main() {
	input();
	cal();
}

// 항상 범위가 넘어갈 수 있는지를 잘 확인해보도록 하자