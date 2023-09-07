#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main(){
	int n; cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr,arr+n);
	for(int i=0; i<n; i++) printf("%d\n", arr[n-i-1]);
	return 0;
}