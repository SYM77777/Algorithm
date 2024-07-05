#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int w, h;
int arr[20][20] = { 0, };

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge right) const {
		if (right.cost < cost) return false;
		if (right.cost > cost) return true;
		return false;
	}
};

priority_queue<Edge> pq;

void init() {

	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {
			arr[i][j] = 0;
		}
	}

}

void ans() {

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char a;
			cin >> a;

			if (a == '.') arr[i][j] = 0;
			else if (a == 'o') arr[i][j] = 1;
			else if (a == '*') {
				arr[i][j] = 2;
			}
			else if (a == 'x') arr[i][j] = -1;

		}
	}
}

void BFS() {





}

int main() {

	while (1) {

		init();

		cin >> w >> h;


		if (w == 0 && h == 0) break;
		else ans();

		BFS();


	}

	return 0;
}

