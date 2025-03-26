#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
long long left_ans = 0;
long long right_ans = 0;
long long ans = 2000000001;

vector<long long> v;

void input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}
}

void cal() {

	int left = 0;
	int right = v.size() - 1;

	while (left != right) {

		long long tmp = v[left] + v[right];

		if (ans > 0 && tmp < 0) {
			if (ans > (tmp * -1)) {
				ans = tmp;
				left_ans = v[left];
				right_ans = v[right];
			}
		}
		else if (ans > 0 && tmp > 0) {
			if (ans > tmp) {
				ans = tmp;
				left_ans = v[left];
				right_ans = v[right];
			}
		}
		else if (ans < 0 && tmp > 0) {
			if ((ans * -1) > tmp) {
				ans = tmp;
				left_ans = v[left];
				right_ans = v[right];
			}
		}
		else {
			if (ans < tmp) {
				ans = tmp;
				left_ans = v[left];
				right_ans = v[right];
			}
		}

		if (tmp < 0) left++;
		else if (tmp == 0) {
			left_ans = v[left];
			right_ans = v[right];
			break;
		}
		else right--;


	}

	cout << left_ans << " " << right_ans << "\n";
}




int main() {

	input();
	cal();

	return 0;
}

// 백준 2467 : 용액
// 투 포인터
// 가장 기본적인 투포인터 문제
// 두 용액을 섞었을 때 가장 0에 가깝게 나온 용액 조합을 출력해주는 문제
// 해당 문제의 핵심은 양 끝에서부터 섞어서 오는 것이다.

// 현재 용액은 오름차순으로 정렬되어 있어 작은 수부터 큰 수 순서로 나열되어 있다.
// 섞었을 때는 3가지 조합이 나올 수 있다. 0보다 크거나, 0보다 작거나, 0이거나

// 처음 시작을 왼쪽은 가장 작은값(index 0) 오른쪽은 가장 큰값(index N - 1)
// 0인 경우 : 종료
// 0보다 큰 경우 : 0에 가까워 지기 위해서는 오른쪽값 인덱스 - 1 -> 이러면 오른쪽 값이 작아져 둘의 합은 작아질 것이다.
// 0보다 작은 경우 : 0에 가까워 지기 위해서는 왼쪽값 인덱스 + 1 -> 이러면 왼쪽값이 커져 둘의 합은 커질것이다.

// 해당 작업을 반복하여 둘의 index가 같아진 경우에 종료
// 이 경우에는 N의 최대값인 최대 100000번만 while문을 반복할 것이다.

// 처음에 틀렸던 이유는 초기값 설정을 잘못해준 이슈가 있었다.
// 최대 10억 이므로 10억으로만 이루어진 곳이 있으면 그 합은 20억이 될 것이다. 
// 따라서 초기값을 처음에는 10억으로 설정했는데 20억으로 변경해줌

// 실행 시간 : 56ms