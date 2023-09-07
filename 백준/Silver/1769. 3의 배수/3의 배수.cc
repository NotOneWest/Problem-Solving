#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int cnt=0;
void threenum(string num){
	int size=num.size(), sum=0;
	if(size>1){
		for(int i=0; i<size; i++) sum+=(num[i]-'0');
		cnt++;
	}
	if(to_string(sum).size()==1){
		cout << cnt << '\n';
		if(stoi(num)%3==0) cout << "YES";
		else cout << "NO";
	}
	else threenum(to_string(sum));
}

int main(){
	string num; cin >> num;
	threenum(num);
	return 0;
}
