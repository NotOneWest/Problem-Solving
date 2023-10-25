#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> s;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum=0;
            for(int k=0; k<=i; k++){
                sum += elements[(k+j)%n];
            }
            s.insert(sum);  
        }
    }
    
    return s.size();
}