#include <string>
#include <vector>
#include <iostream>

int gcd(int a, int b){
    int r;
    while(b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){ return (a*b) / gcd(a, b); }

using namespace std;

int solution(vector<int> arr) {
    int answer = lcm(arr[0], arr[1]);
    for(int i=2; i<arr.size(); i++){
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}