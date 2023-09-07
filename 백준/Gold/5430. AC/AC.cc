#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for(int i=0; i<t; i++){
		deque<int> dq;
		string s; cin >> s;
		int n; cin >> n;
		string arr, num=""; cin >> arr;
		for(int j=0; j<arr.length(); j++){
			if('0' <= arr[j] && arr[j] <= '9') num += arr[j];
			else if(arr[j] == ',' || arr[j] == ']'){
				if(num.length() != 0){
					dq.push_back(atoi(num.c_str()));
					num="";
				}
			}
		}
		bool r=false, err=false;
		for(int j=0; j<s.length(); j++){
			if(s[j] == 'R') r = !r;
			else {
				if(dq.size() == 0){
					err=true;
					break;
				}
				else{
					if(r == true) dq.pop_back();
					else dq.pop_front();
				}
			}
		}
		if(err == false){
			string answer = "[";
			while(dq.size() > 1){
				if(r == false){
					answer += to_string(dq.front());
					answer += ",";
					dq.pop_front();
				}
				else{
					answer += to_string(dq.back());
					answer += ",";
					dq.pop_back();
				}
			}
			if(dq.size() != 0) answer += to_string(dq.front());
			answer += "]";
			cout << answer << '\n';
		}
		else cout<< "error" << '\n';
	}
	return 0;
}