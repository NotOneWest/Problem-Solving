#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int n, inorder[100001], postorder[100001], idx[100001];

void preorder(int inst, int inend, int postst, int postend){
  if(inst>inend || postst > postend) return;
  else{
    int root=postorder[postend];
    cout << root << ' ';
    preorder(inst,idx[root]-1,postst,postst+(idx[root]-inst)-1);
    preorder(idx[root]+1,inend,postst+(idx[root]-inst),postend-1);
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    inorder[i]=x;
  }
  for(int i=0; i<n; i++){
    int x; cin >> x;
    postorder[i]=x;
  }
  for(int i=0; i<n; i++){
    idx[inorder[i]]=i;
  }
  preorder(0, n-1, 0, n-1);
	return 0;
}
