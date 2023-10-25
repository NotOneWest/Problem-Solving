#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    for(int t=0; t<s.length(); t++){
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty()) st.push(s[i]);
                else if(s[i] == '}'){
                    if(st.top() == '{') st.pop();
                    else st.push(s[i]);
                }
                else if(s[i] == ']'){
                    if(st.top() == '[') st.pop();
                    else st.push(s[i]);
                }
                else if(s[i] == ')'){
                    if(st.top() == '(') st.pop();
                    else st.push(s[i]);
                }
            }
        }
        if(st.empty()) answer++;
        s += s[0]; s = s.substr(1, s.length());
    }
    return answer;
}