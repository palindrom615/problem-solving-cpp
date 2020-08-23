#include <iostream>
#include <string>

using namespace std;

string judgeString(string S) {
  /**
   * divide string into (first letter)S1(first letter)S2:
   * if first letter does not appear again, the ethan algorithm failer fails
   * else if S1(first letter)S2 start with S2, the ethan algorithm failer fails
   * else it should return (first letter)S1(first letter)S1(first letter)S2
   */
  int idx = 0;
  for(int i = 1; i < S.size();++i) {
    if(S[i] == S[0]){
      idx = i;
      break;
    }
  }
  if(idx == 0)
    return "Impossible";
  string S1 = S.substr(1, idx - 1);
  string S2 = S.substr(idx + 1, S.size() - idx);
  for(int i = 0; i < S2.size(); ++i){
    if(S2[i] != S[i + 1]){
      return (S[0] + S1 + S[0] + S1 + S[0] + S2);
    }else continue;
  }
  return "Impossible";
}

int main() {
  int T;
  cin >> T;
  for(int testCase = 1; testCase < T+1; ++testCase){
    bool Answer =  false;
    string A;
    cin >> A;
    cout << "Case #"<<testCase << ": " << judgeString(A)<< endl;
  } 
  return 0;
}
