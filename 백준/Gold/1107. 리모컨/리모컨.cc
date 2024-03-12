#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(int a, vector<int> n);
void recursion(int a, int n, int &min, vector<int> v1, vector<int> &v2);
void result(int n, int &min, vector<int> v2);
int recursion2(int n);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;           // n = 목표 채널, k = 망가진 버튼의 개수
  vector<int> num;    // 정상적으로 작동하는 버튼
  vector<int> defect; // 망가진 버튼
  cin >> n >> k;
  int min;
  if (n - 100 < 0) {
    min = 100 - n;
  } else {
    min = n - 100;
  } // 시작 채널 = 100 에서 목표 채널까지 + or - 버튼으로 갔을 시 버튼의
  //횟수를 min(최소값)으로 설정.

  for (int i = 0; i < k; i++) {
    int t;
    cin >> t;
    defect.push_back(t); // 망가진 버튼 입력.
  }
  for (int i = 0; i < 10; i++) {
    if (compare(i, defect)) {
      num.push_back(i);
    } // 망가진 버튼을 제외하고 정상으로 작동하는 버튼을 vector로 만듬.
  }
  for (int i = 1; i <= 6; i++) {
    vector<int> abc(i);
    recursion(0, n, min, num, abc); // 정상적으로 작동하는 버튼으로 만들 수
    //있는 모든 경우의 수(1~6자리수)를 만들어 목표채널까지 버튼 입력 횟수를
    //구하는 함수.
  }
  cout << min;
}

bool compare(int a, vector<int> n) {
  for (int i = 0; i < n.size(); i++) {
    if (a == n[i]) {
      return false;
    }
  }
  return true;
} // 입력받은 숫자가 vector의 원소들 중 하나 일시에 false, 없을 시에 true를
// return 하는 bool 함수.
void recursion(int a, int n, int &min, vector<int> v1, vector<int> &v2) {
  if (a == v2.size()) {
    result(n, min, v2);
    return;
  }
  for (int i = 0; i < v1.size(); i++) {
    v2[a] = v1[i];
    recursion(a + 1, n, min, v1, v2);
  }
} // v1의 원소들을 입력받은 a가 v2.size()와 동일할 때까지 v1의 원소들을 v2에
//입력. 재귀를 통해 v1으로 만들 수 있는 모든 경우가 만들어짐.

void result(int n, int &min, vector<int> v2) {
  int sum = 0;
  for (int i = 0; i < v2.size(); i++) {
    sum += v2[i] * recursion2(i);
  }
  if (n - sum < 0) {
    if (min > sum - n + v2.size()) {
      min = sum - n + v2.size();
    }
  } else {
    if (min > n - sum + v2.size()) {
      min = n - sum + v2.size();
    }
  }
} // recursion 함수에서 만들어진 v2의 원소들로 자릿수를 생각해 sum 값에
//초기화. sum 과 n 의 차이가 min보다 작을 시에 min에 초기화.

int recursion2(int n) {
  if (n < 1) {
    return 1;
  }
  return 10 * recursion2(n - 1);
} // 자릿수를 위해 10의 제곱수를 만들어내는 함수.