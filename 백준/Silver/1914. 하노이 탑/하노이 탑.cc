#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

vector< pii > v;

string bignum2pow(string a){
	string result;
	ll sum=0;
	for(int i=a.size()-1; i>=0; i--){
		sum+=2*(a[i]-'0');
		result += to_string(sum%10);
		sum=sum/10;
	}
	if(sum>0) result += to_string(sum);
	reverse(all(result));
	return result;
}

void hanoi(int n, int from, int by, int to){
	if(n==1) v.pb(mp(from,to));
	else{
		hanoi(n-1,from,to,by);
		v.pb(mp(from,to));
		hanoi(n-1,by,from,to);
	}
}

int main(){
	int n; cin >> n;
	// n이 커지면 횟수가 long long 벗어남.
	string num = "2";
	for(int i=0; i<n-1; i++){
		string temp = bignum2pow(num);
		num=temp;
	}
	string minus = to_string(num[num.size()-1]-'0'-1);
	num[num.size()-1] = minus[0];
	cout << num << '\n';
	if(n<21) hanoi(n,1,2,3);
	for(auto i : v) cout << i.first << ' ' << i.second << '\n';
	return 0;
}
