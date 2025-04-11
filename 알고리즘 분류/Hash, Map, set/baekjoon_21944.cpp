#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

struct Data {
	int pro;
	int level;
	int group;
	bool operator< (Data right) const {
		if (level != right.level) return level > right.level;
		else return pro > right.pro;
	}
};

struct Data2 {
	int pro;
	int level;
	int group;
	bool operator< (Data2 right) const {
		if (level != right.level) return level < right.level;
		else return pro < right.pro;
	}
};

set<Data> hard;
set<Data2> easy;
unordered_map<int, pair<int, int>> dict;

unordered_map<int, set<Data2>> group_easy;
unordered_map<int, set<Data>> group_hard;

unordered_map<int, set<Data>> level_easy;
unordered_map<int, set<Data2>> level_hard;

int main() {

	int N, P;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int pro_num, level_num, group_num;
		cin >> pro_num >> level_num >> group_num;
		hard.insert({pro_num , level_num,  group_num });
		easy.insert({pro_num , level_num, group_num });
		dict.insert({ pro_num, {level_num, group_num} });

		group_easy[group_num].insert({ pro_num , level_num});
		group_hard[group_num].insert({ pro_num , level_num });

	}


	cin >> P;
	for (int i = 0; i < P; i++) {
		string s;
		cin >> s;
		if (s == "recommend") {
			int num, group;
			cin >> group >> num;
			if (num == 1) {

				cout << group_hard[group].begin()->pro << "\n";
			}
			else {
				cout << group_easy[group].begin()->pro << "\n";
			}
		}
		else if (s == "recommend2") {
			int num;
			cin >> num;
			if (num == 1) {
				cout << hard.begin()->pro << "\n";
			}
			else {
				cout << easy.begin()->pro << "\n";
			}
		}
		else if (s == "recommend3") {
			int x, l;
			cin >> x >> l;

			if (x == 1) {
				// 쉬운 문제 중 level ≥ l
				auto it = easy.lower_bound({ 0, l });
				if (it != easy.end()) cout << it->pro << "\n";
				else cout << "-1\n";
			}
			else {
				// 어려운 문제 중 level < l → level ≤ (l-1)
				// since hard는 내림차순, set 순회로 찾기
				auto it = hard.lower_bound({ 0, l }); // 이건 level ≤ l인 가장 큰 값
				while (it != hard.end() && it->level >= l) ++it;
				if (it != hard.end()) cout << it->pro << "\n";
				else cout << "-1\n";
			}
		}

		else if (s[0] == 'a') {
			int pro_num, level_num, group_num;
			cin >> pro_num >> level_num >> group_num;
			hard.insert({ pro_num , level_num,  group_num });
			easy.insert({ pro_num , level_num,  group_num });
			dict.insert({ pro_num, {level_num, group_num}});

			group_easy[group_num].insert({ pro_num , level_num });
			group_hard[group_num].insert({ pro_num , level_num });
		}
		else {
			int pro_num;
			cin >> pro_num;
			int level_num = dict[pro_num].first;
			int group_num = dict[pro_num].second;
			hard.erase({ pro_num, level_num });
			easy.erase({ pro_num, level_num });
			dict.erase(pro_num);

			group_easy[group_num].erase({ pro_num , level_num });
			group_hard[group_num].erase({ pro_num , level_num });
		}
	}


	return 0;

}

// 백준 21944 : 문제 추천 시스템 1
// set, unordered_map

// 해당 문제는 트리 문제 보다는 unordered_map과 set을 사용하여 큰 수로 정렬, 작은 수로 정렬 하여 이를 출력해내는 문제였다.
// 해당 자료 구조를 잘 사용한다면 쉽게 해결 할 수 있었던 문제

// 자료구조 set
// 자료구조 set은 인덱스로 값을 찾는 것은 불가능하다. 
// 따라서, 해당 문제처럼 문제 난이도의 일정 값이상인 값을 찾고 싶으면 레벨 기분 오름차순 혹은 내림차순으로 찾아야한다.
// lower_bound(x)

// 실행 시간 : 528ms