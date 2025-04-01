#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 연산자 우선순위 정하는 함수
int priority(char op) {
    if (op == '(') return 0;        // '('는 가장 낮은 우선순위
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main() {
    string input;
    cin >> input;

    stack<char> s;
    string result = "";

    for (char c : input) {
        // 1. 피연산자면 바로 출력
        if ('A' <= c && c <= 'Z') {
            result += c;
        }
        // 2. 여는 괄호 '('는 무조건 push
        else if (c == '(') {
            s.push(c);
        }
        // 3. 닫는 괄호 ')'면 '(' 나올 때까지 pop
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // '(' 제거
        }
        // 4. 연산자면 우선순위 비교해서 pop 후 push
        else { // +, -, *, /
            while (!s.empty() && priority(s.top()) >= priority(c)) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // 5. 스택에 남은 연산자 다 출력
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    cout << result << '\n';

    return 0;
}

// 백준 1918 : 후위 표기식
// 스택(심화)

// 해당 문제는 스택의 아이디어를 활용해서 어떻게 연산자의 우선순위를 처리할지 고민해야되는 문제이다.

// 내가 생각하는 이 문제의 핵심은 우선순위를 만드는 과정이다.
// 모두가 알듯이 스택을 활용해서 ()가 되면 쌍이 될때까지 연산자를 출력하면 된다. 다만, 연산자를 출력할때 문제가 발생하는데 연산자가 우선순위가 +, -와 *, /가 다르다는 것이다.
// 따라서, A + B * C 와 A * B + c 가 후위 표기식이 다를 것이다. ABC*+, AB*C+
// 따라서, int형 함수를 하나 만들어 줘야 하는것이 핵심이다.
// ( 가 들어가는 경우 다른 연산자들 보다 우선순위가 높아, 연산자를 넣었을 때 ( 문자가 나온다면 우선순위에서 밀린다.

//int priority(char op) {
//    if (op == '(') return 0;        // '('는 가장 낮은 우선순위
//    if (op == '+' || op == '-') return 1;
//    if (op == '*' || op == '/') return 2;
//    return -1;
//}

// 따라서 만약 연산자가 들어왔을 때 해당 함수를 실행시키고 연산자의 우선순위가 밀리지 않는다면 해당 연산자를 출력하는 과정을 반복한다.

// 우선순위를 어떻게 처리해야 될지가 핵심이 되었던 문제

// 실행시간 : 0ms