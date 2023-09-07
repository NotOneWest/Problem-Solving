#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int num[101][101]={0,};

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        for(int j=x; j<(x+10); j++){
            for(int k=y; k<(y+10); k++){
                if(num[j][k]==0) num[j][k]=1;
            }
        }
    }
    int cnt=0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(num[i][j]==1) cnt++;
        }
    }
    cout << cnt;
	return 0;
}