#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> v;

int ans = 0;

int main() {

	int N;
	cin >> N;

	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {

		int left = 0;
		int right = N - 1;

		while (left < right) {
			if (v[left] + v[right] < v[i]) left++;
			else if (v[left] + v[right] > v[i]) right--;
			else {
				if (left != i && right != i) {
					ans++;
					break;
				}
				else if (left == i) left++;
				else if (right == i) right--;
			}
		}
	}
	
	cout << ans;

	return 0;
}

// 백준 1253번
// 투포인터

// 투포인터를 활용하여 왼쪽 오른쪽의 값을 가져와 두 수의 합이 타겟값이 되는 지를 확인하면 끝나는 문제
// 문제의 말이 조금 어려웠는데 자기 자신을 제외한 두 수의 합이 자기 자신을 가리킬 수 있을 때 좋은 수가 된다는 의미였다.
// 문제의 의미만 제대로 이해했다면 투포인터로 쉽게 접근할 수 있었던 문제

// 실행 시간 : 16ms