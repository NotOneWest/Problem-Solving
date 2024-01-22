#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
double px[51], py[51], vx[51], vy[51];

// 시간 당 최소 직사각형 길이
double box(double t) {
	double min_x = (px[0] + vx[0] * t), min_y = (py[0] + vy[0] * t);
	double max_x = (px[0] + vx[0] * t), max_y = (py[0] + vy[0] * t);
	for (int i = 1; i < n; i++) {
		min_x = min(min_x, (px[i] + vx[i] * t));
		min_y = min(min_y, (py[i] + vy[i] * t));
		max_x = max(max_x, (px[i] + vx[i] * t));
		max_y = max(max_y, (py[i] + vy[i] * t));
	}

	return max((max_x - min_x), (max_y - min_y));
}

int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> px[i] >> py[i] >> vx[i] >> vy[i];

	// -1000 ~ 1000 -> 최대 2000초
	// 삼분 탐색 : 아래/위로 볼록한 경우 -> 극대점 혹은 극소점을 찾아나가는 방법
	// f(mid1) > f(mid2) 일 때, 구간 [a, mid1] 에는 최솟값이 존재 X
	// f(mid1) < f(mid2) 일 때, 구간 [mid2, b]에는 최솟값이 존재 X
	// 실수 범위에서 삼분 탐색을 할 때는 
	// ① 구간의 길이가 충분히 작아질 때까지 시행, 
	// ② 정해진 충분히 많은 횟수만큼 시행

	double start = 0, end = 2000;
	for (int i = 0; i < 100 && start < end; i++){ //100번만 하면 충분히 근사한 값을 얻는다
		double mid1 = (start * 2 + end) / 3;
		double mid2 = (start + end * 2) / 3;
		if (box(mid1) < box(mid2)) end = mid2;
		else start = mid1;
	}

	printf("%.11lf\n", box(start));
	return 0;
}