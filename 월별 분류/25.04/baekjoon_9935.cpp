#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    string result = "";
    int b_len = bomb.length();

    for (char c : str) {
        result += c;

        if (result.size() >= b_len && result.substr(result.size() - b_len) == bomb) {
            result.erase(result.end() - b_len, result.end());
        }
    }

    if (result.empty()) cout << "FRULA\n";
    else cout << result << '\n';

    return 0;
}

// 백준 9935번 : 문자열 폭발
// 스택, 문자열 자료구조

// 해당 문제는 스택을 활용하거나 문자열 자료구조 함수를 잘 활용하는 것이 핵심인 문제였다.

// 처음에는 폭발하는 문자열을 접근하기 위해서 처음 시작이 같은 문자의 인덱스를 stack에 담았다.
// 그리고 하나씩 출력하여 substr로 확인하며 폭발 시키며 stack이 다 비게 될때까지 계속 while문을 실행하였다. -> 시간초과

// 시간 초과가 발생하고 다른 접근방법이 필요하였고 문제를 다시 살펴본 결과 만약 앞에서 부터 폭발 문자열이 완성되는 것을 확인하고 바로 제거한다면 더 빠르게 시간 복잡도를 줄일 수 있을 것으로 보였다.
// 예를들어 12ab112ab2ab의 예제에서 폭발문자가 12ab라고 할때 뒤에서 부터 확인하면 (12ab)1(12ab)2ab 일 것이다. 따라서 앞에서부터 제거하게 되면 
// (12ab)1(12ab)2ab - > 1(12ab)2ab -> 12ab -> "" 가 될 것이다.
// 따라서, erase와 substr 함수를 적절히 사용하면 for문 한번으로 해결되는 문제

// String 자료구조를 적절히 사용하는 것이 매우매우 중요했던 문제

// 실행시간 : 56ms


// String 주요 STL 함수 ( string s 로 문자열을 선언하였다고 가정)
// 1. s.size() / s.length() : 문자열 길이 반환         O(1)
// 2. s[i] : i번째 문자 접근                          O(1)
// 3. s.substr(pos, len) : pos부터 len개의 문자열 추출   O(len) -> 새로운 문자열을 복사하므로 비용이 크다
// 4. s += c 또는 s += "abc" : 문자열 덧붙이기       평균 O(1)
// 5. s.append(str) : 문자열 덧붙이기                평균 O(1)
// 6. s.erase(pos, len) : pos부터 len개의 문자 삭제     O(N)
// 6-2. s.erase(iterator) : 해당 위치의 문자 삭제       O(N)
// 7. s.find("abc") : "abc"가 처음 등장하는 위치        O(N*M) N = 문자열 길이이고 M = 찾는 문자열의 길이이다.
// 8. s.compare(str) : 문자열 비교        O(min(N, M))
// 9. s.clear() : 문자열 비우기           O(1)