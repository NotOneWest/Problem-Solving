#include <stdio.h>
#include <string.h>

int main(){
	char a[100001], b[100001];
	scanf("%s %s", &a, &b);
	
	long long int sum=0;
	int i=strlen(a), j=strlen(b);
	
	for(int k=0; k<i; k++){
		for(int t=0; t<j; t++) sum += (long long)(a[k]-48)*(b[t]-48);
	}
	
	printf("%lld", sum);
	return 0;
}