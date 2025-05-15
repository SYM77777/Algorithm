#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<string> v;

bool cmp(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {

		string s;
		cin >> s;

		string tmp = "";
		int now = 0;
		bool check = false;
		while (now < s.size()) {
			if (s[now] <= '9' && s[now] >= '0') {
				tmp += s[now];
				check = true;
				if (now == s.size() - 1) {
					while (tmp.size() > 1 && tmp[0] == '0') {
						tmp.erase(tmp.begin());
					}
					v.push_back(tmp);
				}
			}
			else if (check) {
				while (tmp.size() > 1 && tmp[0] == '0') {
					tmp.erase(tmp.begin());
				}
				v.push_back(tmp);
				tmp = "";
				check = false;
			}

			now++;
		}


	}

	sort(v.begin(), v.end(), cmp);


}

int main() {

	input();
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}



// 백준 2870 : 수학숙제
// 문자열(기초)
// 
// 해당 문제는 문자열의 존재하는 숫자 값을 다 추출한 후 추출된 수를 오름차순 하여 하나씩 출력해보는 문제였다.
// 문제에서 핵심은 3가지였다.
// 1. 문자열의 최대 길이는 100자이다. 따라서, 만약 int, long long 으로 선언했다면 무조건 출력이 잘못된다. 따라서 문자열로 받을 필요가 잇다.
// 2. 1번을 고려했다면 이제 01을 1로 인식해야하므로 앞의 0을 모두 제거해주어야 한다.
// 3. 0을 모두 제거해 주었다면 이제 vector에 존재하는 값을 모두 정렬해 주어야 한다.
// 
// 1번 조건은 문자열로 받으면 해결되는 문제였다.
// 2번 조건은 마찬가지로 while과 string 함수의 erase를 활용하여 맨 앞의 0을 계속 뽑아주면 쉽게 해결할 수 있다.
// 
// 3번 조건이 제일 핵심인데 그냥 sort를 하게 되면 문자열의 맨 앞의 값으로만 정렬하게 되어 43, 2342이 2342 43 순으로 정렬된다.
// 따라서, 임의로 정렬 함수를 만들어 주는 것이 중요하다.
// 특히, cmp 함수를 만드는 과정에서 매개변수의 원본을 건드리지 않는다는 const와 복사하지 않고 참조만 하겠다는 & 레퍼런스를 사용하여 함수를 구성한다.
// 그리고 s1.size()와 s2.size()가 같이않다면 return 값을 >로 정해야 하는 방법이다. 또한 큰 값이 뒤로 오도록 하려면 < 로 설정하고 매개변수의 위치도 중요하다.
// 예시는 내가 작성한 코드를 보도록 하자.
// 
// 정렬 함수를 작성하는 것이 매우 매우 중요했던 문제
//
//
// 실행 시간 : 0ms