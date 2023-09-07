#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);
int n,ans=0,x;
int arr[100000];

int bs(int n, int target){
  int first=0, last=n-1, middle=(first+last)/2;
  while (first < last) {
    if(arr[middle] == target) return 1;
    if(arr[middle] < target){
      first = middle+1;
    } else{
      last = middle-1;
    }
    middle=(first+last)/2;
  }
  if(arr[middle]!=target) return 0;
  else return 1;
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    int a=0; cin >> a;
    arr[i]=a;
  }
  sort(arr, arr+n);
  cin >> x;
  for(int i=0; i<n; i++){
    if(bs(n, x-arr[i])==1) ans++;
  }
  cout << ans/2 << endl;
	return 0;
}
