#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	string s; cin >> s;
	ll score=0;
	int temp=1, check=0;
	stack<char> st;
	for(int i=0; i<s.length(); i++){
		if(s[i] == '('){
			st.push(s[i]);
			temp*=2;
		}
		else if(s[i] == '['){
			st.push(s[i]);
			temp*=3;
		}
		else if(s[i] == ')'){
			if(st.size() == 0 || st.top() != '('){
				check = 1;
				break;
			}
			if(s[i-1] == '(') score+=temp;
			temp/=2;
			st.pop();
		}
		else{
			if(st.size() == 0 || st.top() != '['){
				check = 1;
				break;
			}
			if(s[i-1] == '[') score+=temp;
			temp/=3;
			st.pop();
		}
	}
	if(check == 1 || st.size() != 0) printf("0");
	else printf("%d", score);
	return 0;
}