#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int y, x;
int orders;
int dy[5] = { 0, 0, 0, -1, 1 }; // 차례대로 1부터 동서북남
int dx[5] = { 0, 1, -1, 0, 0 }; // 차례대로 1부터 동서북남


int dice[6] = {1, 6, 5, 2, 3, 4}; // 차례대로 시작할때의 위, 아래, 앞, 뒤, 오른쪽, 왼쪽;
int dice_num[7] = { 0, };
int arr[1001][1001] = { 0, };

queue<int> q;

void input() {
    cin >> N >> M >> y >> x >> orders;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < orders; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

}

void cal() {

    int now_y = y;
    int now_x = x;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        int ny = now_y + dy[a];
        int nx = now_x + dx[a];

        if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;

        // 숫자 이동

        // 만약 주사위가 이동했을때는 다음과 같이 변화한다.
        // 차례대로 시작할때의 위, 아래, 앞, 뒤, 오른쪽, 왼쪽;
        // 1. 동 위 -> 오른쪽, 오른쪽 -> 아래, 아래 -> 왼쪽, 왼쪽 -> 위, 앞, 뒤는 그대로
        // 2. 서 위 -> 왼쪽, 왼쪽 -> 아래, 아래 -> 오른쪽, 오른쪽 -> 위, 앞, 뒤는 그대로
        // 3. 북 위 -> 뒤, 뒤 -> 아래, 아래 -> 앞, 앞 -> 위, 오른쪽, 왼쪽은 그대로
        // 4. 남 위 -> 앞, 앞 -> 아래, 아래 -> 뒤, 뒤 -> 위, 오른쪽, 왼쪽은 그대로

        int tmp = 0;
        if (a == 1) { // 동
            tmp = dice[0];
            dice[0] = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[4];
            dice[4] = tmp;
        }
        else if (a == 2) { // 서
            tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[1];
            dice[1] = dice[5];
            dice[5] = tmp;
        }
        else if (a == 3) { // 북
            tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[3];
            dice[3] = tmp;
        }
        else if (a == 4) { // 남
            tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[1];
            dice[1] = dice[2];
            dice[2] = tmp;
        }

        if (arr[ny][nx] == 0) arr[ny][nx] = dice_num[dice[1]];
        else {
            dice_num[dice[1]] = arr[ny][nx];
            arr[ny][nx] = 0;
        }

        // 숫자 출력
        now_y = ny;
        now_x = nx;
        cout << dice_num[dice[0]] << endl;


    }
}

int main() {

    input();
    cal();

    return 0;
}

// 문제를 잘 읽어야 하는 문제이다.
// 지도의 세로 크기 N, 가로 크기 M (1 ≤ N, M ≤ 20), 주사위를 놓은 곳의 좌표 x, y(0 ≤ x ≤ N-1, 0 ≤ y ≤ M-1), 그리고 명령의 개수 K (1 ≤ K ≤ 1,000)가 주어진다.
// 해당 조건에서  N이 x이고 M이 y이기 떄문에 기존에 하던 방식대로 생각하면 헷갈릴 수도 있다. 따라서, 둘을 바꿔줘야 했던 문제.