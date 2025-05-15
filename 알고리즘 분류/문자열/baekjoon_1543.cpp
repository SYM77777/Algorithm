#include <iostream>
#include <string>

using namespace std;

string s;
string s2;

int ans = 0;


void input() {
	
	getline(cin, s);
	getline(cin, s2);
}

void cal() {

	int now = 0;

	while (now < s.size()) {

		string tmp;
		tmp = s.substr(now, s2.size());

		if (tmp.compare(s2) == 0) {
			ans++;
			now += s2.size();
		}
		else now++;
	}

	cout << ans;

}


int main() {

	input();
	cal();

	return 0;
}

// 백준 1543 : 문서 검색
//문자열(기초)
//
// 해당 문제는 문자열이 주어지고 검색 문자열을 입력하면 중복을 제외하여 얼마나 같은 문자열이 존재하는지 찾는 문제이다.
// 해당 문제는 string 클래스의 함수들을 제대로 이용할 수 있엇다면 쉽게 풀 수 있었던 문제라고 생각한다.
// 해당 문제에서는 substr을 활용한 문자열 추출과 compare를 활용한 문자열 비교를 활용하였다.

// 실행시간 : 0ms

// https://rebro.kr/53
