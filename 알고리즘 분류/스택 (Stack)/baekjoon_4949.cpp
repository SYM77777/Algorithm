#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;



int main() {

	string s;
	getline(cin, s);

	while (s != ".") {

		stack<int> st;
		bool check = true;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') st.push(1);
			else if (s[i] == ')') {
				if (st.empty()) {
					check = false;
					break;
				}
				else {
					if (st.top() != 1) {
						check = false;
						break;
					}
					else st.pop();
				}
			}
			else if (s[i] == '[') st.push(2);
			else if (s[i] == ']') {
				if (st.empty()) {
					check = false;
					break;
				}
				else {
					if (st.top() != 2) {
						check = false;
						break;
					}
					else st.pop();
				}
			}


		}

		if (check == true && !st.empty()) check = false;

		if (check) cout << "yes\n";
		else cout << "no\n";

		getline(cin, s);
	}


}

// 백준 4949
// 스택(기초)

// 스택이 무엇인지 복습할 겸 기초문제를 풀어보았다.
// 스택 자료형을 사용했다면 쉽게 풀 수 있었던 문제
// 마찬가지로 스택 문제를 기초에서 약간 응용한 문제이다.

// 이 문제의 핵심은 스택도 있지만 오히려 띄어쓰기(공백)를 포함한 문자열을 받는 방법이라고 생각한다.
// C++에서 공백을 포함한 문자열을 받는 방법은 getline()함수를 사용하면 된다 
// 1. string s라고 할때 getline(cin, s); 이런 식으로 선언
// 2. cin.getline 이용 char s[100]; cin.getline(s, 100, '\n'); 로 사용
// 3. gets_s 이용 char s[100]; 로 선언하였을 때 gets_s(s, sizeof(s)); 로 사용
// 
// 추가로 fgets로 받게 되면 마지막에 '\n'도 들어오게 된다. 따라서, 100개의 문자를 받으려면 102 이상을 잡아야 한다. ('\n', null이 있음)
// 
// 스택에 입력하고 하나씩 출력하며 남아 있는 수가 있는지 여부를 확인하면 끝

// https://aeunhi99.tistory.com/114 참고한 블로그이다.

// 실행시간 : 92ms