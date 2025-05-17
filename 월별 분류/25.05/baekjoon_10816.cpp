#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> v1;
vector<int> v2;

void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v1.push_back(num);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		v2.push_back(num);
	}

	sort(v1.begin(), v1.end());

}

int bs(int tar, int left, int right) {

	int lower = lower_bound(v1.begin(), v1.end(), tar) - v1.begin(); // tar 이상 값이 처음 나오는 위치를 찾기
	int upper = upper_bound(v1.begin(), v1.end(), tar) - v1.begin(); // tar 초과값으로 처음 나오는 위치 찾기
	return upper - lower;

	// 만약 lower_bound와 upper_bound 로 해당 인덱스의 위치를 알고 싶다면 무조건!!!!!!!!!!! - v1.begin()을 해주어야 한다.

}

int main() {

	input();
	for (int i = 0; i < M; i++) {
		int now = v2[i];
		cout << bs(now, 0, N - 1) << " ";
	}

	return 0;
}
// 백준 10816 : 숫자 카드 2
// 이분 탐색, 정렬, 해시를 사용한 집합과 맵

// 해당 문제는 다양한 방법으로 풀 수 있었던 문제이고 이번 풀이는 이분탐색으로 설명할 계획이다.
// 이전 1920의 문제와 거의 동일하게 2번째 숫자 나열에서 1번째 숫자나열에 숫자가 존재하는 지 여부를 확인하는데 이번에는 몇개가 존재하는 지 찾는 것이다.

// 따라서, 이분 탐색으로 풀게 된다면 upper_bound와 lower_bound를 사용해야만 한다.
// lower_bound란? -> target이 되는 수 이상의 값이 처음 나오는 위치를 찾는다
// upper_bound란? -> target이 되는 수 초과되는 값이 처음 나오는 위치를 찾는다.
// 따라서, upper_bound의 위치와 lower_bound의 위치를 빼게 된다면 target 값이 몇 개가 존재하는지 알 수 있다.

// 2번째 풀이 방법은 unordered_map을 활용한 것으로 그냥 모든 값을 map에 몇개 존재하는지 숫자로 저장하여 이를 뽑아내는 것이다.

// 이분 탐색의 lower_bound와 upper_bound의 차이를 안다면 쉽게 풀 수 있었던 문제

// 실행 시간 : 640ms

// lower bound 직접 구현
//int lower_bound(const vector<int>& v, int target) {
//	int left = 0, right = v.size();  // right는 v.size() (주의!)
//
//	while (left < right) {
//		int mid = (left + right) / 2;
//		if (v[mid] < target) {
//			left = mid + 1;  // target보다 작은 건 무시
//		}
//		else {
//			right = mid;     // target 이상이면 이쪽이 후보
//		}
//	}
//	return left;
//}

// upper_bound 직접 구현
//int upper_bound(const vector<int>& v, int target) {
//	int left = 0, right = v.size();
//
//	while (left < right) {
//		int mid = (left + right) / 2;
//		if (v[mid] <= target) {
//			left = mid + 1;  // target 이하 다 넘김
//		}
//		else {
//			right = mid;     // target 초과는 후보
//		}
//	}
//	return left;
//}
