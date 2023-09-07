#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int cal(int num, int n){
	int sum=0;
	while(num){
		sum += num%n;
		num = num/n;
	}
	return sum;
}

int main(){
	for(int i=1000; i<10000; i++){
		int sum10=cal(i,10), sum12=cal(i,12), sum16=cal(i,16);
		if(sum10 == sum12 && sum10 == sum16) cout << i << '\n';
	}
	return 0;
}