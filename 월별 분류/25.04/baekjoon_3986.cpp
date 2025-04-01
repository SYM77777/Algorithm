#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;

int main() {

	cin >> N;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num = 0;


	for (int i = 0; i < N; i++) {
		stack<int> st;
		string s;

		cin >> s;

		for (int j = 0; j < s.length(); j++) {

			if (st.empty() || st.top() != s[j]) st.push(s[j]);
			else st.pop();

		}
		
		if (st.empty()) num++;
	}

	cout << num << "\n";

	return 0;
}

// 백준 3986번
// 스택(기초)

// 해당 문제는 같은 글자를 아치형 곡선으로 연결할 수 있는가를 확인하는 문제이다.
// 이 말이 무엇인가 하면. ABBA는 가능하지만 ABAB는 불가능하다. 왜냐하면 A와 B끼리 위로 연결되는 곡선을 그리면 둘이 만나기 때문에 불가능하다는 것이다.
// 즉, 어떠한 글자가 들어왔을 때 해당 글자가 아닌 다른 글자가 들어오면 stack에 더해주고 만약 스택의 맨 위 요소와 같다면 맨위 요소를 제거하면 된다.

// 스택을 알고 있다면 금방 풀 수 있던 문제

// 실행시간 : 4ms