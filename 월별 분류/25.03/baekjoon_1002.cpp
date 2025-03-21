#include <iostream>
#include <cmath>

using namespace std;

void input() {
	double x1, y1, r1;
	double x2, y2, r2;
	int ans = 0;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double dist_x = x2 - x1;
	double dist_y = y2 - y1;

	if (dist_x < 0) dist_x *= -1;
	if (dist_y < 0) dist_y *= -1;

	double dist = sqrt(dist_x*dist_x + dist_y*dist_y);
	
	if (dist == 0 && (r1 != r2)) ans = 0;
	else if (dist == 0 && (r1 == r2)) ans = -1;
	else if (dist + r2 < r1 || dist + r1 < r2) ans = 0;
	else if (dist + r2 == r1 || dist + r1 == r2) ans = 1;
	else if (dist < r1 + r2) ans = 2;
	else if (dist == r1 + r2) ans = 1;

	cout << ans << "\n";
}

int main() {

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		input();
	}
	

	return 0;
}

// 터렛
// 2개의 터렛을 기준으로 각각의 원을 그린다고 가정했을때 둘이 만나는 점을 구하는 문제
// 여러 경우의 수를 고려해야한다.
// 1. 두 원이 완전히 겹치는 경우 2. 두 원의 중점은 같으나 원의 크기가 다른경우 3. 한 원이 다른 한 원 안에 있는 경우
// 4. 한 원이 다른 한 원 안에 있으며 한 점에서 만나는 경우 5. 바깥에서 두 원이 접하는 경우 6. 2점에서 만나며 겹치는 경우 7. 안만나는 경우

// 이를 고려해주면 답을 구할 수 있다.

// 실행시간 : 4ms