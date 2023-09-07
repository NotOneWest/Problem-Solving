#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main(){
	int c; cin>>c;
	for(int i=0; i<c; i++){
		float n, sum=0, average=0, rate=0;
		scanf("%f", &n);
		int score[(int) n];
		for(int j=0; j<(int) n; j++) scanf("%d", &score[j]);
		for(int j=0; j<(int) n; j++) sum += (float) score[j];
		average = sum/n;\
		for(int j=0; j<(int) n; j++) if(score[j] > average) rate++;
		printf("%.3f%\n", rate/n*100);
	}
	return 0;
}