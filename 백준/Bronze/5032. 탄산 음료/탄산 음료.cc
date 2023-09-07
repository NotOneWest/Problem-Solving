#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
    int e,f,c; cin >> e >> f >> c;
    int sum = e+f, cnt=0;
    while(sum>=c){
        cnt+=(sum/c);
        sum = sum/c+sum%c;
    }
    cout << cnt;
	return 0;
}