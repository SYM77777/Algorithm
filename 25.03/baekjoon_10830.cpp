#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
long long B;
long long table[5][5];
long long ans[5][5];



void input() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> table[i][j];
			table[i][j] %= 1000;
		}
	}
}

void cal(long long A[5][5], long long B[5][5], long long C[5][5]) {

	long long tmp[5][5] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) tmp[i][j] += (A[i][k] * B[k][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = tmp[i][j] % 1000;
		}
	}
	
}

void multiply(long long A[5][5], long long num, long long result[5][5]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = (i == j) ? 1 : 0;
		}
	}

	long long base[5][5] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			base[i][j] = A[i][j];
		}
	}

	while (num > 0) {
		if (num % 2 == 1) {
			cal(result, base, result);
			num--;
		}
		else { // 만약 같은 경우 base를 2번 계산한 값이 될 것이다.
			cal(base, base, base);
			num /= 2;
		}
		
	}
}

int main() {

	input();
	multiply(table, B, ans);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

// 백준 10830번 : 행렬제곱
// DP 및 분할정복과 관련된 문제
// 분할정복이란 무엇인가?
// 분할 정복(Divide and Conquer)**은 문제를 작은 부분 문제로 나누어서 해결한 뒤, 그 해결 결과를 결합하여 전체 문제를 해결하는 알고리즘 설계 기법

// 여기서 문제 풀이의 핵심은 B의 크기이다.
// 행렬의 제곱을 하게 되면 A*A*A* ...... *A이런식으로 B의 크기만큼 진행되는데 B의 최대값은 무려 천억이다.
// 이런 경우 분할로 접근하는 것이 편리하다.
// 만약 B가 홀수인 경우 : A^(B-1) * A 와 같다.
// 만약 B가 짝수인 경우 : A^(B/2) * A^(B/2)와 같다.
// 만약 B가 5인 경우, 5의 크기가 0까지 줄어들면서 행렬의 곱셈은 결국 A(5) -> A^2(4) -> A^4(2) -> A^5(0) 이렇게 바뀐다.
// 따라서 핵심은 이를 계산하는 분할 정복 계산과 행렬 곱셈을 처음 실행할때 A가 만들어 지기 위하여 단위벡터로 만들어야 한다.
// ex) 2*2 행렬에서 단위벡터는 1 0 / 0 1이다.
// 1 0
// 0 1

// 실행시간 : 0ms