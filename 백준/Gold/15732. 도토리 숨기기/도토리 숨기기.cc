#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int a[10001], b[10001], c[10001];

int main(){
    int n,k,d; cin >> n >> k >> d;
    for(int i=0; i<k; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int low=1, high=n;
    while((low+1)<high){
        int mid = (low+high)/2;
        ll sum=0;
        for(int i=0; i<k; i++){ // 각 규칙에 따라 정해진 구간 내에 총 몇개가 들어갈 수 있는지 모두 더해준다.
            if(a[i]<=mid){ // 구간 길이가 양수일 때 까지만.
                sum+=((min(b[i],mid)-a[i])/c[i]+1);
            }
        }
        if(d<=sum) high=mid;
        else low=mid;
    }
    cout << high;
}
// 완전 탐색이 시간초과 -> 이분 탐색을 고려해볼 것 ==> 배운점.