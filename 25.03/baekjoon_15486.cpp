#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int date[1500001];
int price[1500001];
long long dp[1500001];
long long ans = 0;


void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> date[i] >> price[i];
}

void cal() {

	for (int i = 1; i <= N + 1; i++) {
		if (dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
		else if (ans < dp[i]) ans = dp[i];
		long long tmp = (dp[i] + price[i]); // 현재 위치에서 갈 수 있는 가장 큰 값
		long long tmp_date = date[i];
		if (tmp_date + i > N + 1) continue;
		if (dp[i + tmp_date] < tmp) dp[i + tmp_date] = tmp;
		
	}


}

int main() {

	input();
	cal();

	cout << ans << "\n";

	return 0;
}

// 15486번 : 퇴사2
// 많이 상담을 하면서 받을 수 있는 금액이 가장 큰 경우의 수를 뽑아내야한다.
// 나아가는 방식은 다음과 같다.
// 7일이 주어졌다고 가정했을떄 1일에 상담을 한 경우에는 다음 상담 가능한 날짜는 상담 소요 시간만큼 지난 다음 상담 시간일 것이다.
// 따라서 다음 상담 시간에 가능한 날짜에 해당 가격을 저장하고 만약 해당 날짜에서 상담해서 얻을 수 있는 가격의 가치가 이전에 상담을 해서 얻은 가치보다 높은경우 위치를 계속 최신화해준다.
// 위의 방식으로 계속 진행

// 실행시간 : 720ms

// 주의사항
// 위의 코드 22번째 줄에서 예외조건으로 dp[i] < dp[i - 1] 해당 조건을 처음에는 dp[i] == 0이라고 가정하였다. 해당 조건은 상담을 진행한 위치가 처음 상담을 한 것인데
// 해당 위치에서 얻을 수 있는 가장 큰 가치를 불러오기 위한 코드이다.  dp[i] == 0 이 경우에는 dp[i] == 0 인 경우에만 진행하지만 
// 만약 현재날의 상담의 가치가 이전날을 다 합한 것보다 더 큰경우도 존재하게 된다.
// 따라서, 이전에 얻을 수 있는 가장 큰 값이랑 비교하여야 하므로 모두 고려할 수 있는 dp[i] < dp[i - 1] 조건을 사용하여야 한다.