#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
    if(n == 1) return false;
    for(long long i=2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string s = "";
    while(n != 0){
        s += (n%k + '0');
        n /= k;
    }
    
    string num="";
    for(int i=s.length()-1; i>=0; i--){
        if(num.length() == 0){
            if(s[i] != '0') num += s[i];
        } else{
            if(s[i] == '0'){
                if(isPrime(stol(num))) answer++;
                num = "";
            } else num += s[i];
        }
    }
    if(num.length() != 0){
        if(isPrime(stol(num))) answer++;
    }
    
    return answer;
}