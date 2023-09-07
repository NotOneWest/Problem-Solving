#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
    string a,oper,b; cin >> a >> oper >> b;
    if(a.length() < b.length()){
        a.swap(b);
    }
    if(a.length()==b.length()){
        if(oper=="*"){
            cout << a;
            for(int i=1; i<a.length(); i++) cout << 0;
        }
        else{
            for(int i=0; i<a.length(); i++){
                if(i==0) cout << (a[0]+b[0]-'0'-'0');
                else cout << 0;
            }
        }
    }
    else{
        int len = a.length()-b.length();
        if(oper=="+"){
            for(int i=0; i<len; i++){
                cout << a[i];
            }
            cout << b;
        }
        else{
            cout << a;
            for(int i=1; i<b.length(); i++) cout << 0;
        }
    }
	return 0;
}