#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int carpet = (brown + yellow);
    int h=3;
    while(h < carpet){
        if(carpet%h != 0){ h++; continue; }
        int w = carpet/h;
        int y = ((h-2) * (w-2));
        if(yellow == y && brown == (carpet-y)){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
        h++;
    }
    return answer;
}