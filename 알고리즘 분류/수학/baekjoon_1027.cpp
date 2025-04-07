#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> v;

int see[51] = { 0, };

void input() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
}

int solve() {
    int max_visible = 0;

    for (int i = 0; i < N; i++) {
        int count = see[i];

        // 오른쪽으로만 가자
        for (int j = i + 1; j < N; j++) {
            bool canSee = true;
            for (int k = i + 1; k < j; k++) {
                // 비교: (v[k] - v[i]) * (j - i) < (v[j] - v[i]) * (k - i)
                if ((v[k] - v[i]) * (j - i) >= (v[j] - v[i]) * (k - i)) {
                    canSee = false;
                    break;
                }
            }
            if (canSee) {
                see[i]++;
                see[j]++;
                count++;
            }
        }

        max_visible = max(max_visible, count);
    }

    return max_visible;
}

int main() {
    input();
    cout << solve() << '\n';
    return 0;
}

// 백준 1027 : 고층 건물 
// 수학, 브루트포스 알고리즘, 기하학

// 해당 문제는 이전 Stack에서 봤던 문제와 매우 유사한 형태이지만 양쪽에서 다 볼 수 있다는 차이점이 존재한다.

// 해당 문제의 핵심은 중간 건물이 걸릴지를 판단하는 로직을 짜는 방법이였다.
// 중간 건물 k가 두 건물을 잇는 선분과 맞닿는지 판단하는 방법은 중간 건물에서 그은 기울기의 크기가 항상 선분의 기울기 값보다 작아야 한다는 것이다.
// 
// 해당 값을 유추하는 과정은 다음과 같다. 기울기 m = v[j] - v[i] / j - i
// 그럼 두 건물을 이은 선분을 그으면 다음과 같다. h = v[i] + (m * (k - i))
// 여기서 이제 내가 아는 정보는 건물의 높이이고 이를 넣으면 v[k] = v[i] + (m * (k - i)) 이다.
// 또한, 건물의 높이가 만약 값을 넣은 값보다 크면 안되므로 v[k] >=  v[i] + (m * (k - i)) 라면 count 하면 안된다.
// 해당 방정식을 m을 넣고 양변에 j-i를 곱하면 (v[k] - v[i]) * (j - i) >= (v[j] - v[i]) * (k - i) 를 얻을 수 잇다.

// 해당 코드의 시간복잡도는 for문 3개를 하고 있으므로 O(N^3)이고 N의 최대값은 50이므로 N=50일 떄, 총 연산 횟수는 약 12만번이다. (C++은 약 1억번에 1초)
// 따라서, 여유롭게 통과되는 코드이다.

// 방정식을 설계하고 자료형(double)을 잘 설정하는것이 중요했던 문제

// 실행시간 : 0ms