#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	string a,b; cin >> a >> b;
	int alpabet_a[26]={0,}, alpabet_b[26]={0,}, cnt=0;
	for(int i=0; i<a.size(); i++) alpabet_a[a[i]-'a']++;
	for(int i=0; i<b.size(); i++) alpabet_b[b[i]-'a']++;
	for(int i=0; i<26; i++){
		if(alpabet_a[i] != alpabet_b[i]) cnt += abs(alpabet_a[i]-alpabet_b[i]);
	}
	printf("%d", cnt);
	return 0;
}