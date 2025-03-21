#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<long long> HI;
vector<long long> ARC;

long long HI_ans = 0;
long long ARC_ans = 0;
long long draw = 0;


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		long long num = 0;
		cin >> num;
		HI.push_back(num);
	}

	for (int j = 0; j < M; j++) {
		long long num = 0;
		cin >> num;
		ARC.push_back(num);
	}
	sort(HI.begin(), HI.end(), greater<int>());
	sort(ARC.begin(), ARC.end(), greater<int>());
}

void cal() {
	
	int idx_H = 0;
	int idx_A = 0;


	while (idx_H != N && idx_A != M) {
		long long now_HI = HI[idx_H];
		long long now_ARC = ARC[idx_A];

		if (now_HI == now_ARC) {

			bool check = true;
			long long HI_cnt = 1;
			long long ARC_cnt = 1;
			while (check) {
				if (idx_H + 1 >= N || HI[idx_H + 1] != now_HI) check = false;
				else {
					HI_cnt++;
					idx_H++;
				}
			}

			check = true;
			while (check) {
				if (idx_A + 1 >= M || ARC[idx_A + 1] != now_ARC) check = false;
				else {
					ARC_cnt++;
					idx_A++;
				}
			}

			draw += (HI_cnt * ARC_cnt);
			idx_A++;
			idx_H++;
			HI_ans += ((M - idx_A) * HI_cnt);
			ARC_ans += ((N - idx_H) * ARC_cnt);
			
		}
		else if (now_HI > now_ARC) {
			HI_ans += M - idx_A;
			idx_H++;
		}
		else {
			ARC_ans += N - idx_H;
			idx_A++;
		}
	}

	cout << HI_ans << " " << ARC_ans << " " << draw << "\n";


}



int main() {

	input();
	cal();

	return 0;
}

// 백준 28449 
// 누가 이길까? : 투포인터, 이분 탐색
// 해당 문제의 내용은 간단하다. 
// HI, ARC 두 그룹에 대한 값이 주어지는데 두 그룹의 요소끼리 모두 비교해서 HI가 ARC보다 큰 경우, ARC가 HI보다 큰 경우, 둘이 같은 경우를 찾아서 출력하면 된다.
// 일반적으로 생각하면 그냥 출력하면 된다고 생각하여 이중 for 문으로 하게 되면 error가 발생하게 된다.
// N, M의 최대값은 100000으로 만약 N, M이 최대라고 가정하면 반복문으로 N*M인 100억개를 하게 된다.
// 따라서, 반복문으로 해결할 수 없는 문제로 이럴때는 이분탐색, 투포인터 등의 최적화 알고리즘을 고려해야한다.
// 나는 이번 문제에서 투포인터로 고민해보았고 HI, ARC의 요소들을 vector에 넣어 한번 내림차순으로 정렬해준다.

// 둘의 요소가 다른경우 : 만약 HI의 요소가 ARC의 한 요소보다 크다고 가정해보자. 두 벡터 모두 내림차순으로 정렬했기 때문에 현재 요소보다 이후의 요소들은 모두 작을것이다.
// - 따라서, HI의 현재값은 ARC 이후의 값들보다는 전부 클 것이다. -> HI_ans에 ARC 현재값 이후 요소들 개수를 모두 더해줌 / ARC가 큰 경우도 동일하게 진행

// 만약 둘이 같은경우는 예외 경우가 존재한다. 만약 HI, ARC의 값이 5로 같다고 가정하자 근데 5의 값이 하나만 존재할 수 있지만 여러개 존재할 수도 있다.
// HI에 2개, ARC에 3개가 존재한다면 이를 모두 체크하는 것은 for문을 돌리는 것과 마찬가지이므로 투포인터처럼 현재값과 같은 값들을 각각 세어주고
// draw = HI의 같은 개수 * ARC의 같은 개수이고 draw 뿐만 아니라 그 이후의 값들은 현재값보다 작을 것이기 떄문에 HI_ans += (ARC의 이후 요소 개수 * HI의 현재 값 개수) 를 해주어야 한다.
// draw = HI의 같은 개수 * ARC의 같은 개수 / HI_ans += (ARC의 이후 요소 개수 * HI의 현재 값 개수) / ARC_ans += (HI의 이후 요소 개수 * ARC의 현재 값 개수)

// 이를 진행하면 문제 해결

// 실행시간 :88ms