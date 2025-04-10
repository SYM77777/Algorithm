#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
	char left;
	char right;
};
vector<Node> v[27];

void input() {
	int N;
	cin >> N;
	while (N--) {
		char c, a1, a2;
		cin >> c >> a1 >> a2;
		int num = (int)(c - 'A');
		v[num].push_back({ a1, a2 });
	}
}

void DFS(int now, int check, string& s) { // check = 1 전위, 2 중위, 3, 후위

	// 전위 (루트 -> 왼 -> 오)
	if (check == 1) {
		s += (char)now + 'A';

		if (v[now][0].left != '.') DFS((int)(v[now][0].left - 'A'), 1, s);
		if (v[now][0].right != '.') DFS((int)(v[now][0].right - 'A'), 1, s);
	}
	// 중위 (왼 -> 루트 -> 오)
	else if (check == 2) {
		if (v[now][0].left != '.') DFS((int)(v[now][0].left - 'A'), 2, s);
		s += (char)now + 'A';
		if (v[now][0].right != '.') DFS((int)(v[now][0].right - 'A'), 2, s);
	}
	// 후위 (왼 -> 오 -> 루트)
	else {
		if (v[now][0].left != '.') DFS((int)(v[now][0].left - 'A'), 3, s);
		if (v[now][0].right != '.') DFS((int)(v[now][0].right - 'A'), 3, s);
		s += (char)now + 'A';
	}

}


int main() {

	string pre = "";
	string in = "";
	string post = "";

	input();

	// 전위 (루트 -> 왼 -> 오)
	DFS(0, 1, pre);
	// 중위 (왼 -> 루트 -> 오)
	DFS(0, 2, in);
	// 후위 (왼 -> 오 -> 루트)
	DFS(0, 3, post);
	
	

	cout << pre << "\n" << in << "\n" << post << "\n";

	return 0;
}

// 백준 1991번 : 트리 순회
// 트리(재귀)

// 기본적인 트리 순회를 물어보는 문제로 전위 순회, 중위 순회, 후위 순회에 대한 기본적인 개념과 어떻게 구성해야 될지 고민해야 되는 문제였다.
// 전위 순회 : (루트 노드 -> 왼쪽 노드 -> 오른쪽 노드 )의 순서로 트리를 탐색
// 중위 순회 : (왼쪽 노드 -> 루트 노드 -> 오른쪽 노드 )의 순서로 트리를 탐색
// 후위 순회 : (왼쪽 노드 -> 오른쪽 노드 -> 루트 노드 )의 순서로 트리를 탐색

// 해당 순회를 DFS로 구현하여 각각 string으로 저장 및 출력하면 쉽게 풀 수 있었던 문제

// 실행시간 : 0ms