#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10001];

struct Edge {
    int idx;
    int num;

    // 정렬 기준이 num 값만을 기준으로 하도록 수정
    bool operator<(const Edge& right) const {
        return num < right.num;
    }
};

vector<int> v;
deque<int> dq;

void init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (arr[a] == 0) {
            arr[a] = 1;
            v.push_back(a);
        }
        else continue;
    }

    sort(v.begin(), v.end());

}

void DFS(int CNT, int now) {

    if (CNT == M) {
        for (int i = 0; i < M; i++) {
            cout << dq[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v.size(); i++) {

        int next = v[i];

        if (now > next) continue;

        dq.push_back(v[i]);
        DFS(CNT + 1, next);
        dq.pop_back();
    }

}

int main() {
    init();
    DFS(0, 0);
    return 0;
}

// 문제이해를 잘 못함
// 처음에 들어오는 숫자의 IDX 까지 고려하여 수열을 구성해야 한다고 생각했다.
// 하지만 그게 아닌 들어오는 숫자의 크기만 고려하여 수열을 구성하면 끝나는 아주 간단한 문제
// 문제를 이해하는 능력을 좀 더 길러보기 위하여 다양한 문제를 풀어 익숙해지는 것이 중요하다고 생각되어 진다.
// 
// 추가 설명
// vector의 자료형으로 구조체를 선언하여 해당 vector를 정렬하기 위한 방법은 크게 2가지가 있다.
// 1. 정렬하고자 하는 기준의 구조체 요소를 맨 앞으로 설정하여 sort
// 2. 정렬하고 싶은 요소를 구조체 안해서 bool operator를 통한 구조체 정렬
// 2에 해당하는 코드를 사용하여 이번 문제를 풀었으니 유의하도록 하자
//