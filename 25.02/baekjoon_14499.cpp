#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int y, x;
int orders;
int dy[6] = {0, -1, 0, 0, 1, 2};
int dx[6] = {0, 0, 1, -1, 0, 0};
int arr[1001][1001] = {0, };

queue<int> q;

void input() {
    cin >> N >> M >> x >> y >> orders;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

}

void cal() {


    while(!q.empty()) {
        int a = q.front();
        q.pop();

        cout << a << " ";
    }
}

int main() {

    input();
    cal();

    return 0;
}