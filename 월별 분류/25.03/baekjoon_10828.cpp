#include <iostream>
#include <stack>

using namespace std;

int N;



int main() {

	stack<int> st;

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int num;
			cin >> num;
			st.push({ num });
		}
		else if (s == "top") {
			if (st.empty()) cout << -1 << "\n";
			else cout << st.top() << "\n";
			
		}
		else if (s == "size")  cout << st.size() << "\n";
		else if (s == "pop") {
			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
			
		}
		else if (s == "empty") {
			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}




}

// 백준 10828
// 스택(기초)

// 스택이 무엇인지 복습할 겸 기초문제를 풀어보았다.
// 스택 자료형을 사용했다면 쉽게 풀 수 있었던 문제

// 실행시간 : 216ms