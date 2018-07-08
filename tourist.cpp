#include <iostream>
#include <vector>

using namespace std;
vector<string> Answer;

int main() {
  int T;
  cin >> T;
  for(int testCase = 1; testCase < T+1; ++testCase){
    int N, K; long long V;
    cin >> N >> K >> V;
    string Attractions[N];
    int rem = (V - 1) % N;
    int modSumCntAttr = rem * K;
    int modAttr = modSumCntAttr % N;
    int notfreqAttr = N - modAttr;

    for(int i = 0; i < N; ++i){
      cin >> Attractions[i];
    }

    cout << "Case #" << testCase << ":";
    if(K <= notfreqAttr){
      for(int i = modAttr; i < modAttr + K; ++i){
        cout << " " << Attractions[i];
      }
    } else{
      for(int i = 0; i < K - notfreqAttr; i++){
        cout << " " << Attractions[i];
      }
      for(int i = modAttr; i < N; ++i){
        cout << " " << Attractions[i];
      }
    }
    cout << endl;
  }
  return 0;
}
