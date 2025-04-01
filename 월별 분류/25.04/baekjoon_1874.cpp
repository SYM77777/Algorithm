#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int N;
int now = 0;
stack<int> st;

int arr[100001] = { 0, };


void input() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
}


int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> st;
	vector<char> ans;
	bool check = true;

	input();
	for (int i = 0; i < N; i++) {
		int tar = arr[i];
		if (now <= tar) {
			for (int j = now + 1; j <= tar; j++) {
				st.push(j);
				ans.push_back('+');
			}
			st.pop();
			ans.push_back('-');
			now = tar;
		}
		else if (now > tar) {
			if (st.empty() || st.top() != tar) {
				check = false;
				break;
			}
			else {
				st.pop();
				ans.push_back('-');
			}
		}
	}


	if (check) {
		for (int j = 0; j < ans.size(); j++) cout << ans[j] << "\n";
	}
	else cout << "NO\n";

	return 0;
}

// 백준 1874 : 스택 수열
// 스택(심화)

// 4 3 6 8 7 5 2 1

// 숫자를 받고 해당 수열을 만들 수 있는 가를 물어봤던 문제이다.
// 예를 들어 받은 수열이 3 2 1 일때]
// 1. 3까지 입력한다.
// 2. 3부터 스택으로 빼낸다.
// 3. 3 2 1 만들 수 있는 수열이다.
// 따라서 해당 수열은 가능 하므로 스택이 출력 되는 과정을 + + + - - -로 출력하면 된다.

// 문제 이해를 하는 것이 조금 어려웠던 문제

// 실행 시간 : 20ms