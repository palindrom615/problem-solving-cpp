#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for(int testCase = 0; testCase < T; ++testCase){
    int N, K, V;
    cin >> N >> K >> V;
    string Attractions[N];
    for(int i = 0; i < N; ++i){
      cin >> Attractions[i];
    }
    for(int i = 0; i < N; ++i){
      cout << Attractions[i]<<endl;
    }
  }
  return 0;
}
