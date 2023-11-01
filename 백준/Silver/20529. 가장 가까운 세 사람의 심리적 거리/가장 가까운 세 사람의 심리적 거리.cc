#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	for(int tc=0; tc<t; tc++){
		int n; cin >> n;
		vector<string> v(n);
		for(int i=0; i<n; i++) cin >> v[i];
		
		if(n > 32){ cout << "0\n"; continue; }
		
		vector<int> score;
		for(int i=0; i<(n-2); i++){
			
			for(int j=(i+1); j<(n-1); j++){
				for(int k=(j+1); k<n; k++){
					int cnt = 0;
					for(int p=0; p<4; p++){
						if(v[i][p] != v[j][p]) cnt++;
						if(v[i][p] != v[k][p]) cnt++;
						if(v[j][p] != v[k][p]) cnt++;
					}
					score.push_back(cnt);
				}
			}
		}
		sort(score.begin(), score.end());
		cout << score[0] << '\n';
	}

	return 0;
}
