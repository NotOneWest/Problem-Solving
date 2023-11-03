#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] %2 == 0 || numbers[i] == 1) answer.push_back(numbers[i] + 1);
        else{
            long long idx = 1;
            while(1){
                if(numbers[i] & idx) idx*=2;
                else{
                    answer.push_back(numbers[i] + idx - idx/2);
                    break;
                }
            }
        }
    }
    
    return answer;
}