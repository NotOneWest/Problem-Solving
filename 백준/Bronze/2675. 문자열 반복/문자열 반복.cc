#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int r; cin >> r;
		string s, answer=""; cin >> s;
		int size = s.size();
		for(int i=0; i<size; i++){
			for(int j=0; j<r; j++){
				answer += s[i];
			}
		}
		printf("%s\n", answer.c_str());
	}
	return 0;
}