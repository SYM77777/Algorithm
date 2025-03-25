#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> towers(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> towers[i];

    stack<pair<int, int>> s; // {index, height}
    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        while (!s.empty() && s.top().second < towers[i]) {
            s.pop(); // 나보다 낮은 탑은 버려!
        }

        if (!s.empty()) {
            result[i] = s.top().first; // 가장 가까운 높은 탑
        }
        else {
            result[i] = 0; // 아무도 못 막음
        }

        s.push({ i, towers[i] });
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
}

// 백준 2493번
// 탑
// 해당 문제는 각 탑에서 쏘는 빛을 송신하는 탑의 번호가 어디인지를 계속 찾는 문제이다.

// 해당 문제의 핵심 자료구조는 stack이다.

// stack 이란? 
// 기본적으로 후입선출 (LIFO)로 나중에 넣은 요소가 먼저 나오는 구조이다.
// stack에는 2가지 동작만 존재한다. push, pop
// 또한, top() 과 empty()로 요소의 존재를 확인 가능

// 해당 문제에서 핵심이 되는 부분은 탑에서 쏜 빛이 대체 어느 탑에서 송신을 하는가 확인하는 것이다.
// 문제에서 주어진 조건에 따르면 탑의 갯수는 최대 500000개로 반복문으로 완전탐색을 하기에는 너무 많은 수치이다.
// 따라서, stack을 활용하여 문제를 해결해야 시간 최적화를 해야한다.

// 탑의 높이와 스택의 맨 앞에 있는 탑을 비교하여 만약 탑의 높이보다 스택의 맨 앞의 탑이 작다면 해당 탑은 제거 -> 어차피 그 이후 탑들은 지금 비교하는 탑으로 송신될 것이기 떄문이다.
// 만약 탑의 높이보다 스택의 맨 앞의 탑이 크다면 해당 탑으로 송신
// 이후, 스택에 지금 탑 추가

// 이렇게 스택에 넣고 빼고 반복하게 된다면 반복문으로 500000번 돌리는 것보다 횟수를 많이 감소시킬 수 있다.


// 실행시간 : 284ms
// 시간복잡도 : O(N)