#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
    int sum=0, num[9];
    cin >> sum;
    for(int i=0; i<9; i++) cin >> num[i];
    for(int i=0; i<9; i++){
        if((sum+num[i])==100){
            sum=100;
            break;
        }
        else{
            if(abs(sum+num[i]-100)==abs(100-sum)){
                sum+=num[i];
                break;
            }
            else if(abs(sum+num[i]-100) > abs(100-sum)){
                break;
            }
            else sum+=num[i];
        }
    }
    cout << sum;
	return 0;
}