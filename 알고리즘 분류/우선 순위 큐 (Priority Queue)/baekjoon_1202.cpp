#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;

struct Edge {
	int weight;
	int value;
	bool operator < (const Edge& right) const {
		return weight < right.weight;
	}
};

struct S {
	int value;
	bool operator < (const S& right) const {
		return value < right.value;
	}
};

vector<Edge> jewel; // 무게, 가치
vector<int> bag; // 가방

long long ans = 0;

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		jewel.push_back({w, v});
	}

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		bag.push_back(num);
	}
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
}

void cal() {
	
	int cnt = 0;
	priority_queue<S> pq;
	for (int i = 0; i < K; i++) {

		int now_bag = bag[i];
		
		while (cnt < N && jewel[cnt].weight <= now_bag ) {
			pq.push({ jewel[cnt].value });
			cnt++;
		}

		if (!pq.empty()) {
			ans += pq.top().value;
			pq.pop();
		}

	}
}

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	cal();

	cout << ans;

	return 0;
}

// 백준 1202번 : 보석 도둑
// 자료 구조, 그리디 알고리즘, 정렬, 우선순위 큐

// 해당 문제는 우선순위 큐와 그리디 알고리즘을 적절히 섞어놓은 문제로 아이디어를 얻는것이 중요했던 문제였다.

// 해당 무제의 핵심은 "어떤 것을 선택해야 가방에 보석을 최대 가치로 1개씩 담을 수 있는가?" 이다

// 일반적으로 생각해보면 가방 하나를 고르고 전체에서 담을 수 있는것을 고르고 하나 넣고 다음 가방을 고르고 ... 해당 과정을 반복하면 풀 수 있다.
// 하지만 주어진 문제의 N, K의 최대값은 30만이다. 따라서, 30만 * 30만을 하게 되면 약 90000000000 -> 90억번이다. 따라서, 90초 정도의 시간이 소요되고 당연히 이는 시간초과이다.
// 따라서, 정렬과 pq를 적절히 사용하면 시간복잡도를 줄일 수 있다.
// 먼저 가방과 보석을 각각 무게로 오름차순 정렬을 한다.
// 다음 계산하는 코드에서 우선순위 큐를 선언해주고 가치를 내림차순 (큰것부터 우선순위를 가짐)으로 정렬해준다.
// 로직은 아래와 같다.
// 1. 가방을 먼저 하나 선택한다. (당연시 오름차순 정렬이므로 크기가 작은 가방부터 선택될 것이다)
// 2. 넣을 수 있는 보석을 모두 고른 후 우선 순위 큐에 모두 넣는다. (이도 역시 오름차순 정렬이므로 무게가 작은 보석부터 선택될 것이다)
// 3. 그럼 우선순위 큐에는 해당 가방에 넣을 수 있는 모든 보석을 선택했고 그중에서 가치가 가장 높은 하나를 골라 가방에 넣는다)
// 4. 가방이 남았다면 1번 과정을 돌아가 해당 과정을 반복한다.

// 여기서 가방이 오름차순 정렬되있으므로 다음 가방은 이전 가방보다 큰 가방이 나올 것이고 따라서 이전에 선택이 되지 않은 보석은 모두 넣을 수 있다는 것이다.
// 해당 부분을 이해했다면 구현하는 것은 쉬웠을 것이다. 아이디어를 생각해 내는 것이 매우 중요했던 문제

// 실행 시간 : 140ms
