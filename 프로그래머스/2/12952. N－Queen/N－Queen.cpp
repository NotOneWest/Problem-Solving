#include <string>
#include <vector>

using namespace std;

int col[12], answer=0;

bool check(int x){
    for(int i=0; i<x; i++){
        if(col[i] == col[x] || abs(x-i) == abs(col[x]-col[i])) return false;
    }
    return true;
}

void Nqueen(int x, int n){
    if(x == n){ answer++; return; }
    
    for(int i=0; i<n; i++){
        col[x] = i;
        if(check(x)) Nqueen(x+1, n);
    }
}

int solution(int n) {
    for(int i=0; i<n; i++) col[i]=0;
    Nqueen(0, n);
    return answer;
}