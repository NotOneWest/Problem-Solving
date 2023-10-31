#include <bits/stdc++.h>
using namespace std;

int cal_len(string a, string b){
	int cnt=0, index=0;
	while(1){
		if(a[index] != b[index]) break;
		cnt++; index++;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<string> v;
	vector<pair<string, int> > v2;
	
	for(int i=0; i<n; i++){
		string s; cin >> s;
		v.push_back(s);
		v2.push_back(make_pair(s, i));
	}
	sort(v2.begin(), v2.end()); // 사전 순 정렬 -> 바로 다음만 비교하면 됨 
	
	int maxLen = -1;
	int same[n] = {0, };
	for(int i=0; i<(n-1); i++){
		int cnt = cal_len(v2[i].first, v2[i+1].first);
		maxLen = max(maxLen, cnt);
		same[v2[i].second] = max(same[v2[i].second], cnt);
		same[v2[i+1].second] = max(same[v2[i+1].second], cnt);
	}
	
	int flag=2;
	string pre="";
	for(int i=0; i<n; i++){
		if(same[i] == maxLen){
			if(flag == 2){
				cout << v[i] << '\n';
				pre = v[i].substr(0, maxLen);
				flag--;
			} else{
				if(v[i].substr(0, maxLen) == pre){
					cout << v[i] << '\n';
					break;
				}
			}
		}
	}
	
	return 0;
}
