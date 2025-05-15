#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string s;
int cnt[27] = { 0, };

void input() {

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int now = (int)(s[i] - 'A');
		cnt[now]++;
	}


}

void cal() {

	int check_cnt = 0;
	int check_num = -1;
	for (int i = 0; i < 27; i++) {
		if (cnt[i] % 2 == 1) {
			check_cnt++;
			check_num = i;
		}
		if (check_cnt >= 2) break;
	}
	
	if (check_cnt >= 2) cout << "I'm Sorry Hansoo\n";
	else if (check_cnt == 0) {

		vector<char> v;

		for (int i = 0; i < 27; i++) {
			int now = cnt[i] / 2;
			char now_char = (char)(i + 'A');
			while (now) {
				v.push_back(now_char);
				now--;
			}
		}
		// 문자열 출력
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i];
		}
	}
	else {
		vector<char> v;

		for (int i = 0; i < 27; i++) {
			int now = cnt[i] / 2;
			char now_char = (char)(i + 'A');
			while (now) {
				v.push_back(now_char);
				now--;
			}
		}
		// 문자열 출력
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
		cout << (char)(check_num + 'A');
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i];
		}

	}



}


int main() {


	input();
	cal();



	return 0;
}

// 백준 1213 : 팰린드롬 만들기
// 문자열(기초)

// 해당 문제는 팰린드롬 문자열을 만드는 문제이다. 팰린드롬이란 앞에서 읽에서 읽었을 때와 뒤에서 읽었을 떄 같은 경우, 이를 팰린드롬 문자열이라고 부른다.
// 해당 문제의 핵심은 어떻게 팰린드롬을 만들 수 있을 지 판단하는 것이다.
// 팰린드롬이 어떤 경우에 만들어 질까를 생각해 보면 앞 뒤가 같아야 하므로 적어도 대부분의 문자열은 짝수개로 존재하여야 한다.
// 또한, 만약 홀수개로 존재하는 문자가 존재한다면 이는 딱 한개가 될 것이다.
// 만약, 2개 이상의 문자가 홀수개로 존재한다면 어떻게 만들어도 팰린드롬은 만들 수 없다. 왜냐하면, 홀수개로 존재하기 때문에 앞 뒤에 존재하는 갯수가 다를 것이기 때문이다.
// 이를 고려하여 메모리 제한을 고려한다면 쉽게 풀 수 있었던 문제.

// 실행 시간 : 0ms