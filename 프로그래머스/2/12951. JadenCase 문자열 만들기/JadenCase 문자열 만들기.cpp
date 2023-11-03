#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int flag=0;
    if(s[0] >= 'a' && s[0] <= 'z') s[0] -= 32;
    for(int i=1; i<s.length(); i++){
        if(s[i] == ' ') flag=1;
        else{
            if(flag){
                if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32; flag=0;
            } else{
                if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            }
        }
    }
    return s;
}