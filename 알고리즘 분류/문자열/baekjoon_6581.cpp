#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> words;

void input() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word); // 단어 단위로 분리하여 저장
        }
    }
}

void cal() {
    int cnt = 0;

    for (string word : words) {
        if (word == "<br>") {
            cout << '\n';
            cnt = 0;
        }
        else if (word == "<hr>") {
            if (cnt != 0) cout << '\n';
            for (int i = 0; i < 80; i++) cout << '-';
            cout << '\n';
            cnt = 0;
        }
        else {
            // 줄바꿈이 필요한 경우
            if (cnt + word.length() + (cnt > 0 ? 1 : 0) > 80) {
                cout << '\n';
                cnt = 0;
            }

            // 공백이 필요한 경우
            if (cnt > 0) {
                cout << ' ';
                cnt++;
            }

            cout << word;
            cnt += word.length();
        }
    }

    // 마지막 줄 끝 처리 없음 (백준 조건상 필요 없음)
}

int main() {
    input();
    cal();
    return 0;
}

// 백준 6581 : HTML
// 문자열, 파싱

// 해당 문제는 주어진 문자열을 원하는 크기와 원하는 줄바꿈을 실행하고 정해진 문자열 길이만큼 전부 표시하는 문제이다.
// 핵심은 어떻게 문자열을 입력받아 이를 출력하는가? 이다.
// 따라서, 입력을 받을 때 기억할 것을 정리해보도록 하자.

// 1. while 문의 조건은 입력이 되어도 된다. 백준의 경우는 EDF (end of file)이 주어지기 떄문에 while 문의 조건을 입력으로 설정해 놓으면 자동으로 종료될 수 있다.
// 
// 2. stringstream이란 c++에서 문자열(string)을 cin 처럼 다룰 수 있게 해주는 스트림 클래스이다.
// -> 문자열을 입력 스트림처럼 처리해서 단어 단위로 쉽게 파싱할 수 있게 해준다. --> 공백 기준으로 단어를 나눌 수 있다.
// 따라서, 나는 해당 문제에서 일단 stringstream 클래스로 문자열을 1차로 받은 다음 while조건으로 ss >> word 로 하여 띄어쓰기 기준 단어를 나누었다.
// 
// 3. 마지막은 삼항연산자이다. 항상 잘 응용을 못하는 부분인데 만약 참 거짓을 판단하는 부분이 잇다면 이를 삼항연산자로 표현해보도록 하자
// -> 표현하는 방식 :: 조건 ? 참일 때 값 : 거짓 일 때 출력 값 으로 해당 조건에 대한 참 거짓에 따른 값을 나눌 수 있다.

// 다양한 방법을 다루어 문자열을 파싱하는 것이 매우 중요했던 문제

// 실행 시간 : 0ms