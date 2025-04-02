#include <iostream>
#include <stack>
using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    stack<pair<int, int>> st;  // {키, 같은 키 개수}
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        int cnt = 1;

        while (!st.empty()) {
            if (st.top().first < num) {
                ans += st.top().second;
                st.pop();
            }
            else if (st.top().first == num) {
                ans += st.top().second;
                cnt += st.top().second;
                st.pop();
            }
            else {
                ans++;
                break;
            }
        }

        st.push({ num, cnt });
    }

    cout << ans << '\n';
}

// 백준 3015번
// 스택(심화)

// 해당 문제는 스택을 활용한 바라볼 수 있는 사람 수 쌍을 구하는 문제이다.
// 문제의 핵심은 A, B가 마주볼 수 있는 조건은 A, B 사이에 A 혹은 B보다 키가 큰 사람이 없다는 것이다.
// 예를 들어 2 1 4 로 사람이 서있으면 가능, 1 2 2 불가능, 3 2 2 가능, 1 6 2 불가능

// 해당 문제를 푸는 핵심은 사람이 들어올 때 마다 스택의 맨 위의 값이 나보다 작은 값이라면 해당 사람은 볼 수 있는 것이다. 따라서, ans 값에 더하고 pop으로 제외한다. 
// 왜냐하면 해당 값 이후에는 현재 값으로 인하여 더 작은 값은 볼 수 없기 때문이다.
// 
// 만약, 현재 값보다 키가 크다면 바로 ans에 1을 더하고 종료해야한다. 

// 가장 중요한 점은 자신과 같은 키를 만난 경우이다.
// 예를 들어 2 2 2로 만났다면 모든 사람들은 서로를 볼 수 있다. 따라서 3가지가 나온다.
// 하지만, 1 2 2 로 있다면 2 2 는 서로를 볼 수 있지만 1과 맨 뒤의 2는 가운데의 2로 인하여 서로를 볼 수 없다.
// 따라서, stack의 자료형을 pair로 선언하여 하나는 키의값, 다른 하나는 해당 키의 갯수를 넣어야 한다.
// 겹치는 경우에는 해당 값을 더하여 다음에 넣어주면 된다.

// 특히 주의할점!
// 여기서 N이 50만개를 max값으로 주었다. 그런데 N이 모든 키가 같아 서로를 모두 볼 수 있다면 해당 답은 2^31 값을 아득히 넘게 된다.
// 따라서 해당 int형으로 선언하며 답을 계산하면 범위를 초과하는 문제가 발생하므로 long long으로 선언하며 문제를 해결한다.

// 하나씩 풀어가면 생각보다 쉽게 풀 수 있던 플레문제

// 실행시간 : 68ms ~ 300ms (ios_base::sync_with_stdio(false), cin.tie(NULL)를 사용하니 실행시간이 68로 나왔다.)