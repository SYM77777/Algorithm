#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Passenger {
    int arrival;
    int index;
};

int M, t, N;
queue<Passenger> L, R;
vector<int> result;

void input() {
    cin >> M >> t >> N;
    result.resize(N);

    for (int i = 0; i < N; i++) {
        int arrival_time;
        string side;
        cin >> arrival_time >> side;
        if (side == "left") {
            L.push({ arrival_time, i });
        }
        else {
            R.push({ arrival_time, i });
        }
    }
}

void cal() {
    int cur_time = 0;
    bool is_left = true; // true: left, false: right

    while (!L.empty() || !R.empty()) {
        int cnt = 0;
        bool loaded = false;

        queue<Passenger>& current_side = is_left ? L : R;

        // 현재 위치에서 태울 수 있는 승객 태우기
        while (!current_side.empty() && current_side.front().arrival <= cur_time && cnt < M) {
            Passenger p = current_side.front();
            current_side.pop();
            result[p.index] = cur_time + t; // index 마다 삽입하여 순서를 지키도록 한다.
            cnt++;
            loaded = true;
        }

        // 핵심 코드
        if (loaded) {
            // 손님을 태웠으면 출발
            cur_time += t;
            is_left = !is_left;
        }
        else {
            // 태울 승객이 없다면 다음 승객 도착 시간까지 대기하거나 빈 배로 이동
            int next_time = 1e9;
            if (!L.empty()) next_time = min(next_time, L.front().arrival);
            if (!R.empty()) next_time = min(next_time, R.front().arrival);

            if (next_time > cur_time) { // 현재 시간에 어떤 손님도 도착하지 않음
                cur_time = next_time; // 그럼 다음 손님이 오는 시간으로 설정
            }
            else {
                // 손님이 도착한 부두로 배 이동
                cur_time += t;
                is_left = !is_left;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    cal();

    for (int i = 0; i < N; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}

// 백준 2065 : 나룻배
// 큐(응용, 심화)

// 해당 문제는 나룻배에 인원을 태워 반대쪽으로 보내는 로직을 제작하는데 넣은 순서대로 도착하는 시간을 계산하여 출력하는 문제이다.
// 핵심은 '넣은 순서대로' 도착 시간을 출력해야한다는 것이다.
// 만약 대기하는 인원이 존재하여 해당 인원을 이동했는데 해당 index가 2, 4이면 2번째 4번째 순서로 해당 도착 시간을 출력해야한다는 것이다.

// 핵심 코드 설명
// 따라서, queue를 제작할 때 구조체를 활용하여 해당 시간과 index를 넣는다. 또한, L, R로 왼쪽과 오른쪽을 따로 제작하여 각각 동작하도록 한다.
// 그리고 배가 현재 아무 손님도 없다면 가장 빠른 손님 시간을 찾아 현재 시간을 초기화 하고 손님을 받은 후 배를 이동시키는 일련의 과정을 계속 한다.
// 만약 배를 이동시킬 필요가 없다면 그냥 바로 손님을 태우는 과정을 실시하면 되기 때문에 loaded가 실행 될 것이다.

// queue를 어떻게 설계하여 문제를 해결할 지 고민이 어려웠던 문제였다.

// 실행시간 : 0ms