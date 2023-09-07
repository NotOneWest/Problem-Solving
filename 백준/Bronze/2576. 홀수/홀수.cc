#include <bits/stdc++.h>
using namespace std;

int main(){
	int num[7], sum=0, min=100;
	for(int i=0; i<7; i++) scanf("%d", &num[i]);
	sort(num, num+7);
	for(int i=0; i<7; i++){
		if(num[i]%2 != 0){
			sum+=num[i];
			if(num[i] < min) min = num[i];			
		}
	}
	if(sum == 0) printf("-1");
	else{
		printf("%d\n", sum);
		printf("%d", min);
	}
	return 0;
}