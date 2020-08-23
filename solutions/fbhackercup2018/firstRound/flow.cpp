#include <iostream>

using namespace std;

int T;
bool Grid[3][1000];

int main() {
  long long Answer;
  cin >> T;
  for(int caseNum = 1; caseNum < T+1; ++caseNum) {
    int N;
    char row;
    cin >> N;
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < N; ++j){
        cin >> row;
        if(row == '.'){
          Grid[i][j] = true;
        } else {
          Grid[i][j] = false;
        }
      }
    }

    if(N % 2 == 1){
      Answer = 0;
    } else if(!(Grid[0][0] && Grid[1][0] && Grid[1][N-1] && Grid[2][N-1])) {
      Answer = 0;
    } else {
      Answer = 1;
      for(int i = 0; i < N/2 - 1; ++i) {
        int col = i * 2 + 1;
        bool isMidOpen = Grid[1][col] && Grid[1][col+1];
        bool isBotOpen = Grid[2][col] && Grid[2][col+1];
        bool isTopOpen = Grid[0][col] && Grid[0][col+1];
        if(!isMidOpen || !(isTopOpen || isBotOpen)){
          Answer = 0;
          break;
        } else if(isTopOpen && isBotOpen){
          Answer *= 2;
          Answer = Answer % 1000000007;
        }
      }
    }
    cout << "Case #" << caseNum << ": " << Answer << endl;
  }
  return 0;
}
