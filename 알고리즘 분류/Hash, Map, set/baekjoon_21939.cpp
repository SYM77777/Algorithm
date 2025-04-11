#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

struct Data {
	int pro;
	int level;
	bool operator< (Data right) const {
		if (level != right.level) return level > right.level;
		else return pro > right.pro;
	}
};

struct Data2 {
	int pro;
	int level;
	bool operator< (Data2 right) const {
		if (level != right.level) return level < right.level;
		else return pro < right.pro;
	}
};

set<Data> hard;
set<Data2> easy;
unordered_map<int, int> dict;

int main() {

	int N, P;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int pro_num, level_num;
		cin >> pro_num >> level_num;
		hard.insert({ pro_num , level_num });
		easy.insert({ pro_num , level_num });
		dict.insert({ pro_num, level_num });
	}


	cin >> P;
	for (int i = 0; i < P; i++) {
		string s;
		cin >> s;
		if (s[0] == 'r') {
			int num;
			cin >> num;
			if (num == 1) {
				cout << hard.begin()->pro << "\n";
			}
			else {
				cout << easy.begin()->pro << "\n";
			}
		}
		else if (s[0] == 'a') {
			int pro_num, level_num;
			cin >> pro_num >> level_num;
			hard.insert({ pro_num , level_num });
			easy.insert({ pro_num , level_num });
			dict.insert({ pro_num, level_num });
		}
		else {
			int pro_num;
			cin >> pro_num;
			int level_num = dict[pro_num];
			hard.erase({ pro_num, level_num });
			easy.erase({ pro_num, level_num });
			dict.erase(pro_num);
		}
	}


	return 0;

}

// 백준 21939 : 문제 추천 시스템 1
// set, unordered_map

// 해당 문제는 트리 문제 보다는 unordered_map과 set을 사용하여 큰 수로 정렬, 작은 수로 정렬 하여 이를 출력해내는 문제였다.
// 해당 자료 구조를 잘 사용한다면 쉽게 해결 할 수 있었던 문제

// 실행 시간 : 312ms