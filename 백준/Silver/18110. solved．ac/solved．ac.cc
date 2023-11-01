#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	if(n == 0) cout << 0;
	else{
		int minus = round(n * 0.15);
		double sum = 0;
		
		vector<int> score(n);
		for(int i=0; i<n; i++) cin >> score[i];
		
		sort(score.begin(), score.end());
		for(int i=minus; i<(n-minus); i++) sum += score[i];
		
		sum = round(sum/(n-2*minus));
		cout << sum;
	}
	return 0;
}
