#include <iostream>

using namespace std;

int N, M;
int arr[501][501];
long long ans = 0;

// 직선, 사각형, ㄴ, ㄹ, ㅗ 모양 순서로 진행
int tetro_dy[19][4] = { {0, 0, 0, 0}, {0, 1, 2, 3}, // 1자는 2가지만 존재
                        {0, 0, 1, 1}, // ㅁ는 한가지만 존재
                        {0, 1, 2, 2}, {0, 0, 0, 1}, {0, 0, 1, 2}, {0, 0, 0, -1}, // ㄴ 모양 4가지
                        {0, 0, -1, -2}, {-1, 0, 0, 0}, {0, 0, 1, 2}, {0, 0, 0, 1}, // ㄴ 대칭 모양 4가지
                        {0, 1, 1, 2}, {0, 0, -1, -1}, {0, -1, -1, -2}, {0, 0, 1, 1}, // ㄹ, ㄹ 대칭 모양 4가지지
                        {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 0, 0, -1}, {0, -1, 0, 1} // ㅜ, ㅏ, ㅗ, ㅓ
};
int tetro_dx[19][4] = { {0, 1, 2, 3}, {0, 0, 0, 0},
                        {0, 1, 0, 1},
                        {0, 0, 0, 1}, {0, 1, 2, 0}, {0, 1, 1, 1}, {0, 1, 2, 2}, // ㄴ 모양 4가지
                        {0, 1, 1, 1}, {0, 0, 1, 2}, {0, 1, 0, 0}, {0, 1, 2, 2}, // ㄴ 대칭 모양 4가지
                        {0, 0, 1, 1}, {0, 1, 1, 2}, {0, 0, 1, 1}, {0, 1, 1, 2}, // ㄹ, ㄹ 대칭 모양 4가지지
                        {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 1, 2, 1}, {0, 1, 1, 1}, // ㅜ, ㅏ, ㅗ, ㅓ
};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

}

// 4칸을 더하며 진행하는 함수
void cal() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 19; k++) {
                int tmp = 0;
                int check = 0;
                for (int l = 0; l < 4; l++) {
                    int ny = i + tetro_dy[k][l];
                    int nx = j + tetro_dx[k][l];

                    if (ny >= N || ny < 0 || nx >= M || nx < 0) {
                        check = 1;
                        break;
                    }
                    else tmp += arr[ny][nx];
                }
                if (check == 1) continue;
                if (tmp > ans) ans = tmp;
            }
        }
    }
}



int main() {

    input();
    cal();

    cout << ans;

    return 0;
}