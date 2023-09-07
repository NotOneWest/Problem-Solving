#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int born[3], now[3], a=0, b=0, c=0;
	
	for(int i=0; i<3; i++) scanf("%d", &born[i]);
	for(int i=0; i<3; i++) scanf("%d", &now[i]);
	
	b = now[0] - born[0] + 1;
	c = now[0] - born[0];
	
	a = now[0] - born[0] -1;
	if(born[1] < now[1]) a++;
	else if(born[1] == now[1]){
		if(born[2] <= now[2]) a++;
	}
	
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d",c);
}