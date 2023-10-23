#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v;

int decimalN(int n){
    int one = 0;
    while(n >= 2){
        v.push_back(n%2);
        if(n%2){ one++; }
        n /= 2;
    }
    v.push_back(n);
    if(n == 1) one++;
    return one;
}

int solution(int n) {
    int answer = 0;
    int one = decimalN(n);
    
    while(1){
        n++;
        if(decimalN(n) == one){
            answer = n;
            break;
        }
    }
    return answer;
}