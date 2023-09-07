#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n; cin >> n;
	int num[n]={0,};
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	stack<int> st;
	st.push(-100);
	int i=1, j=0, check = 0;
	string s;
	while(j<n){
		if(st.size() == 0){
			st.push(i);
			i++;
			s += "+\n";
		}
		if(num[j] > st.top()){
			st.push(i);
			i++;
			s += "+\n";
		}
		if(num[j] == st.top()){
			st.pop();
			s += "-\n";
			j++;
			if(j == n) break;
		}
		if(num[j] < st.top()) {
			check++;
			break;
		}
	}
	if(check == 0) printf("%s", s.c_str());
	else printf("NO");
	return 0;
}