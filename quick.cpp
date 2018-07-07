#include <iostream>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
int T, test_case;
/*
The freopen function below opens input.txt file in read only mode, and afterward,
the program will read from input.txt file instead of standard(keyboard) input.
To test your program, you may save input data in input.txt file,
and use freopen function to read from the file when using cin function.
You may remove the comment symbols(//) in the below statement and use it.
Use #include<cstdio> or #include <stdio.h> to use the function in your program.
But before submission, you must remove the freopen function or rewrite comment symbols(//).
*/

// freopen("input.txt", "r", stdin);

cin >> T;
for (test_case = 0; test_case < T; test_case++){

  Answer = 0;
  int n;
  cin >> n;
  int A[200000];
  int LMax[200000];
  int RMin[200000];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  LMax[0] = -1;
  RMin[n-1] = 10000007;
  int lmax = -1;
  int rmin = 10000007;
  for (int i = 0; i < n-1; ++i) {
      if(A[i] > lmax) {
          lmax = A[i];
          LMax[i+1] = A[i];
      } else {
          LMax[i+1] = LMax[i];
      }
  }
  for(int i = n-1; i > 0; --i){
      if(A[i] < rmin) {
          rmin = A[i];
          RMin[i-1] = A[i];
      } else {
          RMin[i-1] = RMin[i];
      }
  }
  for(int i = 0; i < n; ++i) {
      if(A[i] > LMax[i] && A[i] < RMin[i]) {
          Answer += 1;
      }
  }
  // Print the answer to standard output(screen).
  cout << "Case #" << test_case + 1 << endl;
  cout << Answer << endl;
}

return 0;//Your program should return 0 on normal termination.
}