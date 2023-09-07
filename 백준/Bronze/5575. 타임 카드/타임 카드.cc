#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
    for(int t=0; t<3; t++){
        int sh, sm, ss, eh, em, es;
        int ah=0, am=0, as=0;
        cin >> sh >> sm >> ss >> eh >> em >> es;
        if(ss > es){
            em-=1;
            es+=60;
        }
        as = (es-ss);
        if(sm > em){
            eh-=1;
            em+=60;
        }
        am = (em-sm);
        ah = (eh-sh);
        cout << ah << ' ' << am << ' ' << as << '\n';
    }
	return 0;
}