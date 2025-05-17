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

	int mid;

	while (left <= right) {

		mid = (left + right) / 2;
		if (v1[mid] > tar) {
			right = mid - 1;
		}
		else if (v1[mid] < tar) {
			left = mid + 1;
		}
		else return 1;


	}

	return 0;

}

int main() {

	input();
	for (int i = 0; i < M; i++) {
		int now = v2[i];
		cout << bs(now, 0, N - 1) << "\n";
	}

	return 0;
}
// 백준 1920 : 수 찾기
// 이분 탐색, 매개 변수 탐색

// 해당 문제는 주어진 두 숫자의 나열에서 2번째로 주어진 숫자의 나열들이 첫번째 숫자 나열에서 존재 하는지의 여부를 파악하는 문제이다.
// 따라서, 첫번째 배열을 오름차순 혹은 내림차순으로 정렬하여 해결한다면 매우 쉽게 풀 수 있었던 문제

// 이분 탐색을 사용하는 기초적인 문제

// 실행 시간 : 140ms