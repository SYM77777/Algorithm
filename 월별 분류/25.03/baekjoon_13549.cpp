#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int check[200001];
int ans = 0;

struct Data {
	int num;
	int cnt;
};

void input() {
	cin >> N >> K;
	for (int i = 0; i <= 2*K; i++) check[i] = 100001;
	if (N >= K) ans = N - K;
}

void cal() {

	queue<Data> q;
	q.push({ N, 0 });
	check[N] = 0;

	if (N >= K) cout << ans << "\n";
	else {
		while (!q.empty()) {
			int now_num = q.front().num;
			int now_cnt = q.front().cnt;
			q.pop();

			if (now_num == K) continue;
			else if (now_num > K) {
				now_cnt += (now_num - K);
				if (now_cnt < check[K]) check[K] = now_cnt;
				continue;
			}

			if (now_num - 1 >= 1 && check[now_num - 1] > now_cnt + 1) {
				check[now_num - 1] = now_cnt + 1;
				q.push({ now_num - 1, now_cnt + 1 });
			}
			if (now_num + 1 <= K && check[now_num + 1] > now_cnt + 1) {
				check[now_num + 1] = now_cnt + 1;
				q.push({ now_num + 1, now_cnt + 1 });
			}
			if (now_num * 2 < 2*K && check[now_num * 2] > now_cnt) {
				check[now_num * 2] = now_cnt;
				q.push({ now_num * 2, now_cnt});
			}


		}
		cout << check[K] << "\n";
	}

}


int main() {


	input();
	cal();


	return 0;
}

// 백준 13549번 : 숨바꼭질 3
// 0-1 BFS, 백트래킹, BFS 등등 다양한 풀이 가능

// 이 문제의 핵심은 어떻게 최단으로 목표지점에 도달하는 것을 구하는가? 이다.
// 나는 이 문제를 해결하기 위해 일반적인 BFS로 접근하였다.
// DFS로 접근하는 경우 만약 100000 0 이 나오는 경우 10만번의 재귀 함수 실행을 통해 해당 문제가 해결이 되는 것이다.
// 하지만 일반 적인 BFS도 이는 마찬가지인 것이, 만약 K의 값을 도착하는데 3번이 걸린 경우의 수가 queue에 먼저 들어가있으면 그 이후에 더 작은 값이 최소가 나오는 경우가 queue 안에 존재할 수도 있게 된다.
// 따라서, 이를 해결하기 위하여 가중치가 작은 값이 앞으로 오도록 BFS의 queue를 설정해주면 된다. 그러기 위해 deque를 사용한 BFS를 사용하면 된다. 이를, 0-1 BFS라고 부른다.
// 0-1 BFS
// 일반적인 BFS는 모든 간선의 가중치가 동일할 때(예: 모두 1) 사용하는 최단거리 알고리즘이다. 큐에 넣은 순서대로 탐색하니까 "거리 순서"대로 진행된다.
// 이때 일반 BFS를 쓰면, 비용 0인 경로를 나중에 탐색할 수도 있다. 그럼 최단거리 탐색이 틀어질 수 있다.
// 따라서, 간선 가중치가 0 또는 1일 때, deque를 이용해서 가중치 0은 앞에, 가중치 1은 뒤에 넣는 방식으로 BFS의 순서를 "가중치 반영"하게 만든 기법이다.
// 0초에 갈 수 있는 경로는 먼저 탐색되고 1초 걸리는 경로는 나중에 탐색되므로 정확한 최단 시간을 구할 수 있는 로직

// 아래는 0-1 BFS로  추가 구현한 cal 함수 로직입니다.
//deque<Data> q;
//q.push_back({ N, 0 });
//check[N] = 0;
//
//if (N >= K) cout << ans << "\n";
//else {
//	while (!q.empty()) {
//		int now_num = q.front().num;
//		int now_cnt = q.front().cnt;
//		q.pop_front();
//
//		if (now_num == K) break;
//		else if (now_num > K) {
//			now_cnt += (now_num - K);
//			if (now_cnt < check[K]) check[K] = now_cnt;
//			continue;
//		}
//
//		if (now_num - 1 >= 1 && check[now_num - 1] > now_cnt + 1) {
//			check[now_num - 1] = now_cnt + 1;
//			q.push_back({ now_num - 1, now_cnt + 1 });
//		}
//		if (now_num + 1 <= K && check[now_num + 1] > now_cnt + 1) {
//			check[now_num + 1] = now_cnt + 1;
//			q.push_back({ now_num + 1, now_cnt + 1 });
//		}
//		if (now_num * 2 < 2 * K && check[now_num * 2] > now_cnt) {
//			check[now_num * 2] = now_cnt;
//			q.push_front({ now_num * 2, now_cnt });
//		}
//
//
//	}
//	cout << check[K] << "\n";
//}


// 실행 시간 : 0ms
