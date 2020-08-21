/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Draw;
typedef vector<int> Deck;

int Answer;

int sum_of_draw(Deck deckX, Deck deckY, int i, int j, Draw draw) {
	int sum = 0;
	for (int n = i - 1; n >= i - draw.first; n--) {
		sum += deckX[n];
	}
	for (int n = j - 1; n >= j - draw.second; n--) {
		sum += deckY[n];
	}
	return sum;
}

int walk_draw(int i, int j, vector<vector<int>>memo, Deck x, Deck y, int k) {
	queue<Draw> q;
	q.push(Draw(1, 0));
	q.push(Draw(0, 1));
	while (!q.empty()) {
		Draw draw = q.front();
		q.pop();
		if (i - draw.first < 0 || j - draw.second < 0) {
			continue;
		}
		if (sum_of_draw(x, y, i, j, draw) > k) {
			continue;
		}
		if (memo[i - draw.first][j - draw.second] == 2) {
			return 1;
		} else {
			q.push(pair<int, int>(draw.first + 1, draw.second));
			q.push(pair<int, int>(draw.first, draw.second + 1));
		}
	}
	return 2;
}

int main(int argc, char **argv) {
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
	Deck x(3000);
	Deck y(3000);
	vector<vector<int>> memo(3001, vector<int>(3001));
	for (test_case = 0; test_case < T; test_case++) {

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */

		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> y[i];
		}

		/**
		 * {(), ()}의 경우 case 1.
		 * 내 차례에서 카드를 뽑아서 case 2의 상태로 만들 수 있다면 나의 승리(case 1)
		 * => 카드의 합이 k 이하가 되도록 뽑는 경우의 수 중 case 2가 단 하나라도 있다면 case 1.
		 * 어떻게 뽑아도 case 1밖에 안나온다면 나의 패배(case 2)
		 *
		 * {(), ()}부터 시작해서 dynamic programming으로 풀기.
		 */
		memo[0][0] = 1;
//		memo[1][0] = memo[0][1] = 2;
		int case1 = 1, case2 = 0;

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (i == 0 && j == 0 ) {
					continue;
				}
				if ( 2 == (memo[i][j] = walk_draw(i, j, memo, x, y, k))) {
					case2 += 1;
				} else {
					case1 +=1;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << case1 << " " << case2 << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

