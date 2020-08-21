/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>

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

	vector<int> a(200000);
	vector<int> b(200000);
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;

		int n, k;
		cin >> n >> k;

		int a_max = 0;
		int b_max = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		sort(a.begin(), a.begin() + n);
		sort(b.begin(), b.begin() + n);

		Answer = 0;
		for (int i = 0; i < k; i++) {
			if (a[i] + b[k - i - 1] > Answer) {
				Answer = a[i] + b[k - i - 1];
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}