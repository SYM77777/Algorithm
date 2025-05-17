#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long check[100000] = { 0, };
long long total = 0;

long long max_val = 0;
long long ans;

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> check[i];
		if (check[i] > max_val) max_val = check[i];
		total += check[i];
	}

	ans = total;
}

long long cal(long long mid) {

	long long cnt = 1;
	long long sum = 0;
	bool check_mid = true;

	for (int i = 0; i < N; i++) {
		if (check[i] > mid) return 1e9;
		if (sum + check[i] > mid) {
			cnt++;
			sum = check[i];
		}
		else {
			sum += check[i];
		}
	}


	return cnt;
}


void bs(long long left, long long right) {

	long long mid;

	while (left <= right) {
		mid = (left + right) / 2;

		long long num = cal(mid);
		if (num <= M) {
			ans = min(ans, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}


	}

	cout << ans;

}

int main() {

	input();
	bs(max_val, total);

	return 0;
}

// 백준 2343 : 기타 레슨
// 이분 탐색, 매개 변수 탐색

// 해당 문제는 강의 숫자와 강의를 나눌 수 있는 최대 수가 주어졌을 때 녹화할 수 있는 최소 길이를 구하는 문제이다.
// 따라서, 해당 문제는 이분 탐색의 사용이 거의 필수 적이라고 할 수 있다.

// 하지만, 해당 문제에서 굉장히 많은 시간을 소요했었는데 이는 문제 조건을 제대로 확인했으니라 이를 적는 과정에서 제대로 옮겨 적지 않고
// 이를, 확인하는 과정에서 계속 검수가 안되어 잡아내질 못했었다. (십만인데 계속 배열을 만으로 설정해놓음)

// 따라서, 실제 코딩테스트나 다음 문제를 풀 때는 이러한 실수를 절대로 하지 말도록 하자.

// 이를 고려했다면 이분 탐색을 사용하는 기초적인 문제

// 실행시간 : 32ms