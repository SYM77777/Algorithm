#include <iostream>
#include <algorithm>
using namespace std;

string S, T;
bool ans = false;

void dfs(string cur) {
    if (cur.length() < S.length()) return; // 더 짧아지면 실패
    if (cur == S) { // 성공 조건
        ans = true; 
        return; 
    }         

    // 1. 맨 뒤가 A라면 A 제거
    if (cur.back() == 'A') {
        string next = cur;
        next.pop_back();
        dfs(next);
    }

    // 2. 맨 뒤가 B라면 B 제거 후 뒤집기
    if (cur.front() == 'B') {
        string next = cur;
        reverse(next.begin(), next.end());
        next.pop_back(); // 문자열은 pop_back, push_back, front(), back()이 가능하다.
        dfs(next);
    }
}

int main() {
    cin >> S >> T;
    dfs(T);
    cout << (ans ? 1 : 0) << "\n";
    return 0;
}

// 백준 12919번 : A와 B 2
// DFS
// 해당 문제는 DFS를 사용하되 얼마나 최적화를 시켜 해당 코드를 실행시키냐에 따라 중요한 문제였다.
// 만약 정방향으로 S -> T를 만든다고 가정해보자.
// 최악의 경우의 수로 2^49의 분기가 생겨나게 된다. DFS로 이를 시행하게 되면 너무 오래 걸린다.
// 따라서, T -> S로 가는 경우의 수를 생각하면 된다. 왜냐하면 결국 T가 만들어지냐 안만들어지냐로 판단하기 때문에 이미 만들어진 T로 판단하는 것이 경우의 수를 더 줄일 수 있다.
// S -> T : 전부 시행해야됨 / T -> S : 앞에 B가 있는가? 뒤에 A가 있는가? 로 판단한다. ----> 경우의 수가 현저히 감소!!!!
// 따라서, 이를 구현하면 위의 코드가 만들어진다.

// 항상 알고리즘 문제를 풀 때 정방향보다 역방향을 조심해야 한다는 것을 상기시켜 준 문제이다.


// 실행시간 : 0ms
