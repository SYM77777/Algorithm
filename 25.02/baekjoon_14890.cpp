#include <iostream>
#include <queue>
using namespace std;

int N, L;
int map[101][101] = { 0, };
int visited_1[101][101] = { 0, }; // 경사로를 사용했는지 확인하기 위한 배열 세로
int visited_2[101][101] = { 0, }; // 경사로를 사용했는지 확인하기 위한 배열 가로
int ans = 0;

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			visited_1[i][j] = 0;
			visited_2[i][j] = 0;
		}
	}
}

// 가로
int slide_use_1(int r, int c) {
	int tmp = 0;
	int start = map[r][c];
	int len = 1;

	if (start > map[r][c - 1]) {
		
		start = map[r][c - 1];
		if (visited_1[r][c - 1] == 1) tmp = 1;
		else {
			visited_1[r][c - 1] = 1;
			while (len != L) {
				if (c - 1 - len < 0) {
					tmp = 1;
					break;
				}
				else if (visited_1[r][c - 1 - len] == 0 && map[r][c - 1 - len] == start) {
					visited_1[r][c - 1 - len] = 1;
				}
				else {
					tmp = 1;
					break;
				}
				len++;
			}
		}
	}
	else {
		
		if (visited_1[r][c] == 1) tmp = 1;
		else {
			visited_1[r][c] = 1;
			while (len != L) {
				if (visited_1[r][c + len] == 0 && map[r][c + len] == start) {
					visited_1[r][c + len] = 1;
				}
				else if (c + len >= N) {
					tmp = 1;
					break;
				}
				else {
					tmp = 1;
					break;
				}
				len++;
			}
		}
	}

	return tmp;
}

// 세로
int slide_use_2(int r, int c) { 
	int tmp = 0;
	int start = map[r][c];
	int len = 1;

	if (start > map[r - 1][c]) {
		start = map[r - 1][c];
		if (visited_2[r - 1][c] == 1) tmp = 1;
		else {
			visited_2[r - 1][c] = 1;
			while (len != L) {
				if (r - 1 - len < 0) {
					tmp = 1;
					break;
				}
				if (visited_2[r - 1 - len][c] == 0 && map[r - 1 - len][c] == start) {
					visited_2[r - 1 - len][c] = 1;
				}
				else {
					tmp = 1;
					break;
				}
				len++;
			}
		}
	}
	else {
		if (visited_2[r][c] == 1) tmp = 1;
		else {
			visited_2[r][c] = 1;
			while (len != L) {
				if (visited_2[r + len][c] == 0 && map[r + len][c] == start) {
					visited_2[r + len][c] = 1;
				}
				else {
					tmp = 1;
					break;
				}
				len++;
			}
		}
	}

	return tmp;
}

void cal() {

	int len = L;

	for (int i = 0; i < N; i++) {

		int now = map[i][0];
		int now_2 = map[0][i];
		int j = 1;
		int k = 1;
		int check = 0;
		int check_2 = 0;


		// 가로
		while (j <= N - 1) {
			int next = map[i][j];
			if (now != next) {
				if (now - next >= 2 || now - next <= -2) {
					check = 1;
					break;
				}
				check = slide_use_1(i, j);

				if (check == 1) break;
				else {
					now = next;
					if (now > next) j += L;
					else j++;
					continue;
				}
			}

			now = next;
			j++;
		}

		if (check == 0) {
			//cout << i << " " << j << "가로더해짐\n";
			ans++;
		}


		// 세로
		while (k <= N - 1) {
			int next = map[k][i];
			if (now_2 != next) {
				if (now_2 - next >= 2 || now_2 - next <= -2) {
					check_2 = 1;
					break;
				}
				check_2 = slide_use_2(k, i);

				if (check_2 == 1) break;
				else {
					now_2 = next;
					if (now_2 > next) k += L;
					else k++;
					continue;
				}
			}

			now_2 = next;
			k++;
		}

		if (check_2 == 0) {
			//cout << i << " " << j << "세로더해짐\n";
			ans++;
		}

	}




}

int main() {

	input();
	cal();

	cout << ans;

	return 0;

}

// 경사로
// 해당 문제는 경사로를 설치하여 해당 행, 열이 한 길이 만들어 지는가를 확인하여 모든 만들어 질 수 있는 길을 세는 문제이다.
// 경사로를 설치하는 조건은 3가지가 있다.
// 1. 경사로를 이미 설치한 지역에는 경사로를 설치할 수 없다.
// 2. 경사로의 높이는 1로 붙어있는 벽의 크기 차이가 2 이상이면 경사로를 설치할 수 없다.
// 3. 경사로의 길이는 무조건 L로 고정되어 있다.

// 해당 문제를 풀기 위해서 map에 정보를 저장하고
// 가로, 세로에 방문하여 경사를 만든 여부를 확인하기 위한 확인 배열을 만들고 for문으로 반복문 진행하면 완료되는 문제

// 다만 문제 조건이 많으므로 항상 문제 조건을 잘 확인하여 이를 체크하는 습관을 기르도록 하자.


// 실행시간 0ms

// #include<stdio.h>
// int main(){
// 	int N, L, ans=0, M, i, j, c;
// 	short A[200][100];
// 	scanf("%d %d", &N, &L);
// 	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%hd", &A[i][j]);
// 	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	A[i+N][j]=A[j][i];
// 	M=2*N;
// 	for(i=0;i<M;++i){
// 		c=1;
// 		for(j=0;j<N-1;++j){
// 			if(A[i][j]==A[i][j+1])	++c;
// 			else if(A[i][j]+1==A[i][j+1] && c>=L)	c=1;
// 			else if(A[i][j]-1==A[i][j+1] && c>=0)	c=-L+1;
// 			else	break;
// 		}
// 		if(j==N-1 && c>=0)	++ans;
// 	}
// 	printf("%d\n", ans);
// 	return 0;
// }

// 위의 코드는 더 짧은 코드이다. 
// 해당 코드가 더 짧은 이유 : 한번에 해결하기 위하여 N의 크기가 100으로 고정되어 있기 떄문에 배열의 크기를 200 까지 늘려 가로와 세로를 모두 해결함
// 배열의 크기가 작은 경우에는 이를 더 늘려서 해결하는 방향도 모색해보도록 하자.