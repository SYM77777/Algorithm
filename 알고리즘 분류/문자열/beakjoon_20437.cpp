#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

void input() {

	string word;
	queue<int> q[30];
	int word_cnt[30] = { 0, };
	int num;

	int short_ans = -1;
	int long_ans = -1;

	cin >> word;
	cin >> num;

	for (int i = 0; i < word.length(); i++) {
		int now = (int)(word[i] - 'a');

		word_cnt[now]++;
		q[now].push(i);

		if (word_cnt[now] >= num) {
			int cal = i + 1 - q[now].front();

			if (cal > long_ans) long_ans = cal;

			if (short_ans == -1) short_ans = cal;
			else if (short_ans != -1 && cal < short_ans) short_ans = cal;

			q[now].pop();
		}
	}

	if (short_ans == -1) cout << -1 << "\n";
	else cout << short_ans << " " << long_ans << "\n";

}

int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) input();

	return 0;
}

// 20437번 : 문자열 게임 2
// 알파벳 소문자로 이루어진 문자열 W에서 양의 정수 K개를 포함하는 가장 짧은 문자열과 가장 긴 문자열의 길이를 구하는것이다.
// 만약, 길이를 만족하지 않는다면 -1 출력
// 큐 혹은 벡터로 알파벳 별 숫자를 저장
// 현재는 큐에 저장하여 각각의 위치를 저장하도록 구현
// 만약 일정 길이 이상의 알파벳이 나온다면 길이를 찾은 다음 long_ans 와 short_ans와 비교 후, 길이를 구한다.
// 만약 둘 다 -1이라면 -1만 출력력

// 아래와 같은 방식으로 핵심 로직을 수정도 가능하다.
// vector<int> v[26];
// for (int i = 0; i < word.size(); i++)
//     v[word[i] - 'a'].push_back(i);

// for (int c = 0; c < 26; c++) {
//     for (int i = num - 1; i < v[c].size(); i++) {
//         int len = v[c][i] - v[c][i - num + 1] + 1;
//         short_ans = (short_ans == -1) ? len : min(short_ans, len);
//         long_ans = max(long_ans, len);
//     }
// }


// 실행시간 : 16ms