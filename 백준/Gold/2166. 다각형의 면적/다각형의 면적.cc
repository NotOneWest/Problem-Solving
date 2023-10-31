#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	// 신발끈 공식 (N각형 면적 -> 순서대로 좌표 있으면) 
	// (i=1~n : | x(i)*y(i+1) - x(i+1)*y(i)의 합 |/2 ) ... ex) 시계 반대 방향으로 N 각혛 좌표 주어지면 
	int n; cin >> n;
	long long x0, y0; cin >> x0 >> y0;
	long long prev_x = x0, prev_y = y0;
	
	long double ans = 0;
	for(int i=0; i<(n-1); i++){
		long long x, y; cin >> x >> y;
		ans += (prev_x*y - x*prev_y);
		prev_x = x; prev_y = y; 
	} 
	ans += (prev_x*y0 - x0*prev_y);
	ans = abs(ans)/2;
	
	cout << fixed; cout.precision(1);
	cout << ans << '\n';
	return 0;
}
