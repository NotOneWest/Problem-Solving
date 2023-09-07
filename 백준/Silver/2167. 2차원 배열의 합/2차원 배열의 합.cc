#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int N,M, k;
	scanf("%d %d", &N, &M);
	int nums[N][M];
	for(int t=0; t<N; t++){
		for(int p=0; p<M; p++) scanf("%d",&nums[t][p]);
	}
	scanf("%d", &k);
	int loc[k][4];
	for(int t=0; t<k; t++){
		for(int p=0; p<4; p++) scanf("%d", &loc[t][p]);
	}
	for(int t=0; t<k; t++){
		int i = loc[t][0];
		int j = loc[t][1];
		int x = loc[t][2];
		int y = loc[t][3];
		if(j==y && x==i) printf("%d\n", nums[i-1][j-1]);
		else if(j==y && x!=i){
			int sum=0;
			for(int t=i-1; t<x; t++) sum += nums[t][j-1];
			printf("%d\n", sum);
		}
		else{
			int sum = 0;
			if(i == x){
				for(int t=j-1; t<y; t++) sum += nums[i-1][t]; 
			}
			else{
				for(int t = i-1; t<x; t++){
					for(int p = j-1; p<y; p++) sum += nums[t][p];
				}
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}