#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

char node[26][2];

void preorder(char root){
  if(root=='.') return;
  else{
    cout << root;
    preorder(node[root-'A'][0]);
    preorder(node[root-'A'][1]);
  }
}

void inorder(char root){
  if(root=='.') return;
  else{
    inorder(node[root-'A'][0]);
    cout << root;
    inorder(node[root-'A'][1]);
  }
}

void postorder(char root){
  if(root=='.') return;
  else{
    postorder(node[root-'A'][0]);
    postorder(node[root-'A'][1]);
    cout << root;
  }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n; cin >> n;
  for(int i=0; i<n; i++){
    char root, left, right; cin >> root >> left >> right;
    node[root-'A'][0]=left;
    node[root-'A'][1]=right;
  }
  preorder('A');
  cout << '\n';
  inorder('A');
  cout << '\n';
  postorder('A');
  cout << '\n';
	return 0;
}
