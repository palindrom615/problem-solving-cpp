#ifdef TEST
#define main executable_main
#endif

#include <iostream>
using namespace std;

int Answer;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}