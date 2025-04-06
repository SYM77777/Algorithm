#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, K;
long long ans = 0;
int tmp[21] = { 0, };

queue<int> stu;

void input() {
	cin >> N >> K;

}

void cal() {
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int len = s.length();

		if (stu.size() == K + 1) {
			int now = stu.front();
			tmp[now]--;
			stu.pop();
		}

		ans += tmp[len];

		tmp[len]++;
		stu.push(len);


	}
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cal();

	cout << ans << "\n";

	return 0;
}

// 백준 3078 : 좋은 친구
// 큐(응용), 슬라이딩 윈도우

// 해당 문제는 좋은 친구를 찾는 문제로 이름의 길이가 같고 순위가 K이내인 모든 쌍의 경우의 수를 세는 문제이다.
// 하지만 일반적으로 queue에 다 넣고 맨 앞의 요소를 뺸 다음 K만큼 for문으로 제거하는 방식을 사용하면 시간초과가 발생하게 된다.
// 그 이유는 N의 최대값은 30만이고 K의 최대값 또한 30만 이기 때문에 N * K 는 약 900억번의 연산을 실행해야한다.
// C++ 기준으로 보통 1억번의 연산 당 1초의 소요 시간이 걸린다. 따라서, 900억번은 약 900초 이상의 시간이 걸릴 수 있으므로 당연히 시간초과가 발생한다.

// 따라서, 해당 문제는 슬라이딩 윈도우 기법을 활용한다.

// 제작된 queue에 K만큼 요소를 넣는다.
// 만약 제작된 queue에 이미 K만큼의 요소가 존재한다면 맨 앞의 요소는 제외하고 새로운 요소를 집어 넣는다.
// 요소를 집어 넣을 때마다 학생 이름의 길이에 따라 tmp[len] 값을 늘리고 뺼 때마다 줄인다.
// 그리고 새로운 요소를 넣을때마다 해당 학생 길이의 학생 수만큼 답에 더해 준다. (학생 수 쌍 생성)
// 해당 과정을 실행하면 반복문 하나로 해당 문제를 끝낼 수 있다. O(N)

// 시간 초과 문제를 해결하기 위하여 최적화를 할 필요가 있었던 문제

// 실행시간 : 48ms