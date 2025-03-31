#include <iostream>
#include <stack>

using namespace std;

int N;



int main() {

	stack<int> st;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		switch (num) {
		case 1: {
			int a;
			cin >> a;
			st.push(a);
			break;
		}
		case 2: {
			if (st.empty()) cout << -1 << "\n";
			else {
				cout << st.top() << "\n";
				st.pop();
			}
			break;
		}
		case 3: {
			cout << st.size() << "\n";
			break;
		}
		case 4: {
			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		}
		case 5: {
			if (st.empty()) cout << -1 << "\n";
			else cout << st.top() << "\n";
			break;
		}

		}
	}




}

// 백준 28278
// 스택(기초)

// 스택이 무엇인지 복습할 겸 기초문제를 풀어보았다.
// 스택 자료형을 사용했다면 쉽게 풀 수 있었던 문제

// 다만 한번 틀렸었는데 해당 문제는 입출력 방식이 느리면 여러줄을 입력받거나 출력할 때 시간초과가 발생할 수 있다.
// 따라서, 현재 사용하는 언어인 C++에서는 main 함수에 cin.tie(NULL); ios_base::sync_with_stdio(false); 해당 함수를 둘다 적용해 주도록 하자.

// 실행시간 : 136ms