#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int heap[100001], size=0;

void insert(int num){
	heap[size]=num;
	int index=size;
	while(index!=1){
		int mid=index/2;
		if(heap[mid] < heap[index]) break;
		swap(heap[mid], heap[index]);
		index=mid;
	}
}

void erase(){
	if(size==0) return;
	heap[1]=heap[size];
	int index=1;
	while(2*index<size){
		int left=index*2, right=index*2+1, next;
		if(heap[left] < heap[right]) next=left;
		else next=right;
		if(heap[next] > heap[index]) break;
		swap(heap[next], heap[index]);
		index=next;
	}
	size--;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for(int k=0; k<n; k++){
		int num; cin >> num;
		if(num!=0){
			size++;
			insert(num);
		}
		else{
			if(size!=0){
				cout << heap[1] << '\n';
				erase();
			}
			else cout << 0 << '\n';
		}
	}
	return 0;
}