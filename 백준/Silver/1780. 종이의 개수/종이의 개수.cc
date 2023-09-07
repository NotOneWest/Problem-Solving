#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int a, b, c;
int paper[2188][2188];

int same(int y, int x, int size){
	int temp = paper[y][x]; 
	for(int i=y; i<y+size; i++){
		for(int j=x; j<x+size; j++){
			if(temp != paper[i][j]) return -2;
		}
	}
	if(temp==-1) a++;
	else if(temp==0) b++;
	else c++;
	return temp;
}

void cutting(int y, int x, int size){
	int all_same = same(x,y,size);
	if(all_same != -2) return;
	cutting(y, x, size/3);
	cutting(y, x+size/3, size/3);
	cutting(y, x+size/3+size/3, size/3);
	cutting(y+size/3, x, size/3);
	cutting(y+size/3, x+size/3, size/3);
	cutting(y+size/3, x+size/3+size/3, size/3);
	cutting(y+size/3+size/3, x, size/3);
	cutting(y+size/3+size/3, x+size/3, size/3);
	cutting(y+size/3+size/3, x+size/3+size/3, size/3);
}

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> paper[i][j];
		}
	}
	cutting(0,0,n);
	cout << a << '\n' << b << '\n' << c;
	return 0;
}
