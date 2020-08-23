#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int T;
  cin >> T;
  int N;
  int P[51];
  for(int testCase = 1; testCase < T+1; ++testCase){
    cin >> N;
    for(int i = 0; i < N+1; ++i){
      cin >> P[i];
    }
    int Answer;
    float x = 0.0;
    
    cout << "Case #" << testCase << ": ";
    if(N % 2 == 0){
      Answer = 0;
      cout << Answer << endl;
    } else {
      Answer = 1;
      cout << Answer << endl;
      cout << fixed << setprecision(7) << x << endl;
    }
  } 
  return 0;
}
