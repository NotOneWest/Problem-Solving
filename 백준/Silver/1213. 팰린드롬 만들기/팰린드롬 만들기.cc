#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int alpabet[26];

int main(){
	string s; cin >> s;
	for(int i=0; i<s.size(); i++) alpabet[s[i]-'A']++;
	int even=0, odd=0;
	for(int i=0; i<26; i++){
		if(alpabet[i]%2==0) even++;
		else odd++;
	}
	if(odd<=1){
		string answer;
		int odd_index=-1;
		for(int i=0; i<26; i++){
			if(alpabet[i]%2!=0) odd_index=i;
			for(int j=0; j<alpabet[i]/2; j++) printf("%c", i+65);
		}
		if(odd_index>=0) printf("%c", odd_index+65);
		for(int i=25; i>=0; i--){
			for(int j=0; j<alpabet[i]/2; j++) printf("%c", i+65);
		}
	}
	else cout << "I'm Sorry Hansoo";
	return 0;
}
