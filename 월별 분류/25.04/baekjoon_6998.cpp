#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
	vector<Node*> children;
};

// 문자열 토큰 배열
vector<string> tokens;
int idx;

// 문자열을 공백 기준으로 토큰화하여 token 벡터에 저장한다.
void tokenize(string& s) {
	tokens.clear();
	string tmp;
	for (char c : s) {
		if (c == ' ') {
			if (!tmp.empty()) {
				tokens.push_back(tmp);
				tmp.clear();
			}
		}
		else {
			tmp += c;
		}
	}

	if (!tmp.empty()) tokens.push_back(tmp);
}

// 전위 순회 문자열로부터 트리 생성
Node* build() {
	if (idx >= tokens.size() || tokens[idx] == "#") {
		idx++;
		return nullptr;
	}

	Node* node = new Node();
	idx++; // 현재 노드 하나 처리했으니 다음으로

	while (true) {
		Node* child = build();
		if (child == nullptr) break;
		node->children.push_back(child);
	}

	return node;
}

string serialize(Node* node) {
	if (!node) return "";

	vector<string> subs;
	for (auto* child : node->children) {
		subs.push_back(serialize(child));
	}
	sort(subs.begin(), subs.end());

	string res = "(";
	for (string& s : subs) res += s;
	res += ")";

	return res;
}
void freeTree(Node* node) {
	for (auto* child : node->children)
		freeTree(child);
	delete node;
}

int main() {

	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string s1;
		string s2;

		getline(cin, s1);
		getline(cin, s2);

		// 트리 1 생성
		tokenize(s1);
		idx = 0;
		Node* root1 = build();

		// 트리 2 생성
		tokenize(s2);
		idx = 0;
		Node* root2 = build();


		if (serialize(root1) == serialize(root2))
			cout << "The two trees are isomorphic.\n";
		else
			cout << "The two trees are not isomorphic.\n";


		freeTree(root1);
		freeTree(root2);

	}



	return 0;
}

// 백준 6998 : 트리 동형 사항

// 트리 동형 사상이란?
// 두 트리 구조가 본질적으로 같은지, 즉 형태나 구조가 동일한지를 판별하는 개념이다.

// 두 트리가 동형(isomorphic)이라고 말하려면 T1, T2의 트리가 존재한다고 할때
// 1. 루트 노드부터 시작해서 구조가 동일하고
// 2. 각 노드의 자식 노드 개수와 자식들의 구조도 같아야 한다.
// 3. 단, 자식 노드의 순서는 달라도 상관없다.

// 이 코드는 전위 순회로 표현된 트리 문자열을 파싱하여 트리를 구성한 뒤,
// 트리를 직렬화(serialize)해서 자식 순서를 정렬한 문자열로 만든 다음,
// 두 문자열이 같은지를 비교하여 동형 여부를 판단한다.

//   - "#"은 NULL 노드를 의미한다.
//   - 전위 순회 문자열을 파싱해서 트리를 구성하고,
//   - serialize() 함수로 각 서브트리를 괄호로 감싼 문자열로 표현한다.
//   - 자식 노드 순서를 정렬하여 자식 순서에 상관없이 비교 가능하게 만든다.

// 예를 들어 다음과 같은 입력이 주어진 경우:
//
// 입력 1:
// A B # # C # #
// X Z # # Y # #
//
// → 두 트리의 구조는 다음과 같음:
//
//     A             X
//    / \           / \
//   B   C         Z   Y
//
// 자식 순서는 다르지만 구조는 같으므로 이 둘은 동형이다.
//
// 이때 serialize() 결과는:
//   A 트리 → ((())(())) → 루트가 ( (자식B) + (자식C) )
//   X 트리 → ((())(())) → 자식 순서 정렬로 결과 동일
//
// 그래서 출력은: The two trees are isomorphic.

// 트리 동형 사상 문제에 대해 알아볼 수 있었던 문제

// 실행시간 : 0ms