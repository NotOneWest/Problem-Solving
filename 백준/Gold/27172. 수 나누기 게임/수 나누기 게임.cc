#include <bits/stdc++.h>
using namespace std;

int score[1000001];
int nums[1000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<int> v;
	for(int i=0; i<=1000000; i++){ nums[i] = 0; score[i] = 0; }
	
	for(int i=0; i<n; i++){
		int num; cin >> num;
		nums[num] = 1;
		v.push_back(num);
	}
	
	
	for(int i=0; i<n; i++){
		for(int j = v[i]*2; j<1000001; j+=v[i]){
			if(nums[j]){ score[v[i]]++; score[j]--; }
		}
	}
	
	for(int i=0; i<n; i++) cout << score[v[i]] << " ";
	cout << "\n";
	return 0;
}
