#include <stdio.h>

int main(){
	
	int m,n;
	scanf("%d %d", &m, &n);
	int u,l,r,d;
	scanf("%d %d %d %d", &u, &l, &r, &d);
	char str[m][n+1];
	for(int i=0; i<m; i++) scanf("%s", &str[i]);
	
	for(int i=0; i<u+m+d; i++){
		for(int j=0; j<r+l+n; j++){
			if(i<u){
				if(i%2==0){
					if(j%2==0) printf("#");
					else printf(".");
				}
				else{
					if(j%2==0) printf(".");
					else printf("#");
				}
			}
			else if(i>=u && i<u+m){
				if(i%2==0){
					if(j<l){
						if(j%2==0) printf("#");
						else printf(".");
					}
					else if (j==l) printf("%s", str[i-u]);
					else if (j>=l+n){
						if((l+n)%2==0){
							if(j%2==0) printf("#");
							else printf(".");
						}
						else{
							if(j%2==0) printf("#");
							else printf(".");
						}
					}
				}
				else{
					if(j<l){
						if(j%2==0) printf(".");
						else printf("#");
					}
					else if (j==l) printf("%s", str[i-u]);
					else if (j>=l+n){
						if((l+n)%2==0){
							if(j%2==0) printf(".");
							else printf("#");
						}
						else{
							if(j%2==0) printf(".");
							else printf("#");
						}
					}
				}
			}
			else{
				if(i%2==0){
					if(j%2==0) printf("#");
					else printf(".");
				}
				else{
					if(j%2==0) printf(".");
					else printf("#");
				}
			}
		}
		if(i<u+m+d-1) printf("\n");
	}
	return 0;
}