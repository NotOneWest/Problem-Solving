#include <bits/stdc++.h>

using namespace std;

int n, ans=0;
priority_queue<int> card;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		card.push(x*(-1));
	}
	if(n == 1) cout << 0 << '\n';
	else{
		while(card.size() > 1){
			int first = card.top(); card.pop();
			int second = card.top(); card.pop();
			ans += (first + second);
			card.push((first + second));
		}
		cout << ans*(-1) << '\n';
	}
	
	return 0;
}