#include <iostream>
#include <stack>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    stack<int> st;  // {키, 같은 키 개수}
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        while (!st.empty()) {
            if (st.top() <= num) {
                st.pop();
            }
            else {
                ans += st.size();
                break;
            }
        }
        st.push(num);


    }

    cout << ans << '\n';
}

// 백준 6198번 : 옥상 정원 꾸미기
// 스택(심화) - 참고 백준 3015번

// 해당 문제는 옥상에서 다른 옥상을 바라보는 방향이 정해져 있고 현재보다 오른쪽으로 봤을 때 키가 작은 옥상만 볼 수 있는 문제이다.
// 따라서, stack에 입력을 하면서 만약 stack의 맨 위의 값이 현재값보다 작다면 pop으로 제거, 만약 아니라면, ans 값에 현재 st의 size를 넣어준다.

// 하나씩 풀어가면 생각보다 쉽게 풀 수 있던 문제

// 실행시간 : 8m