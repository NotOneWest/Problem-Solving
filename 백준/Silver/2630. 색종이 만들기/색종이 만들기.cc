#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int blue, white;
int paper[129][129];

int same(int y, int x, int size){
	int temp = paper[y][x]; 
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(temp != paper[i][j]) return -1;
		}
	}
	if(temp==1) blue++;
	else white++;
	return temp;
}

void cutting(int y, int x, int size){
	int all_same = same(x,y,size);
	if(all_same != -1) return;
	cutting(y, x, size/2);
	cutting(y, x+size/2, size/2);
	cutting(y+size/2, x, size/2);
	cutting(y+size/2, x+size/2, size/2);
}

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> paper[i][j];
		}
	}
	cutting(0,0,n);
	cout << white << '\n' << blue;
	return 0;
}
