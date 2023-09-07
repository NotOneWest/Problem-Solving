#include <stdio.h>
#include <math.h>

int main(){
	int T;
	scanf("%d", &T);
	
	int num[T][6];
	for(int i=0; i<T; i++){
		for(int j=0; j<6; j++) scanf("%d", &num[i][j]);
	}
	
	for(int i=0; i<T; i++){
		int x = num[i][0]-num[i][3];
		int y = num[i][1]-num[i][4];
		int add = num[i][2]+num[i][5];
		int sub = num[i][2]-num[i][5];
		double d = x*x + y*y;

		if(sub*sub<d && d<add*add) printf("%d\n",2);
		else if(d==add*add || (sub*sub==d && d!=0)) printf("%d\n",1);
		else if(d<sub*sub || d>add*add) printf("%d\n",0);
		else if(d==0){
			if(num[i][2] == num[i][5]) printf("-1\n");
			else printf("%d\n",0);
		}
	}
	
	return 0;
}