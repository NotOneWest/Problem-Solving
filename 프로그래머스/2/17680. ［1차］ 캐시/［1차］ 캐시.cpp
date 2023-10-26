#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0, flag=0;
    vector<string> caches;
    if(cacheSize){
        for(int i=0; i<cities.size(); i++){
            for(int j=0; j<cities[i].length(); j++) cities[i][j] = tolower(cities[i][j]);
        }
        
        for(int i=0; i<cities.size(); i++){
            for(int j=0; j<caches.size(); j++){
                if(caches[j] == cities[i]){
                    caches.erase(caches.begin() + j);
                    caches.push_back(cities[i]);
                    answer++; flag=1; break;
                }
            }
            if(flag){ flag=0; continue; }

            if(caches.size() >= cacheSize) caches.erase(caches.begin());
            caches.push_back(cities[i]);
            answer+=5;
        }
    } else answer = cities.size() * 5;
    
    
    return answer;
}