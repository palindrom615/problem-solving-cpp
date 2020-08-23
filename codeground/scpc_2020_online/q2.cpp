/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

/**
 * {(), ()}의 경우 case 1.
 * 나는 최선을 다하기 때문에 상대를 case 2로 만들기 위해 노력한다. 상대도 마찬가지.
 * 내 차례에서 카드를 뽑아서 case 2의 상태로 만들 수 있다면 나의 승리(case 1)
 * => 카드의 합이 k 이하가 되도록 뽑는 경우의 수 중 case 2가 단 하나라도 있다면 case 1.
 * 어떻게 뽑아도 case 1밖에 안나온다면 나의 패배(case 2)
 *
 * {(), ()}부터 시작해서 dynamic programming으로 풀기.
 * 임의의 {i,j} 는 case 1, case 2 이렇게 두 종류의 상태 중 하나를 갖는다.
 *
 * 한 번의 draw로 case 2로 만들 수 있다면 반드시 case 1. (converse is not always true)
 *
 * 어떤 {n,m}에서 w.r.t every i <= n, j <= m (단, i, j = n, m은 제외){i, j}를 {n, m}의 이후 상태라고 하자.
 * {n, m}에서 어떤 경우에도 draw 한 번으로 case 2인 이후 상태에 도달할 수 없다고 하자. := case 2 에서 역 드로우로 도달할 수 없다.
 * => 그러면 {n, m}은 case 2인 것이 자명하다. ({n, m}에서 한 번 draw하면 반드시 case 1 상태에 도달하게 되므로)
 *
 * 따라서 한 번 드로우로 case2인 상태에 도달할 수 있는 모든 이전 상태는 case 1.
 * 역으로 case 2인 그 어떤 이후 상태로도 도달할 수 없는 이전 상태는 case 1.
 *
 * pseudo code
 *
 * case(0, 0) = 1
 * for every case(i, j)
 * 		if case(i, j) = 0 // case 2인 이후 상태에서 한 번의 역 드로우로 도달 못한 케이스
 * 			case(i, j) = 2
 * 			for every case((i, j) + draw) that draw < k
 * 				case((i,j) + draw) = 1
 * 		if case(i, j) = 1
 * 			continue
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>

#ifdef test
#define main executable_main
#endif

using namespace std;

typedef pair<int, int> Draw;
typedef vector<int> Deck;

int Answer;

int sum_of_reverse_draw(vector<int> &acc, int i, int draw) {
	return acc[i + draw - 1] - acc[i - 1];
}

void
reverse_draw_from_case_2(int i, int j, vector<vector<int>> &memo, vector<int> &x_acc, vector<int> &y_acc, int k, int n) {
	for (int draw_x = 1; sum_of_reverse_draw(x_acc, i, draw_x) <= k; draw_x += 1) {
		if (i + draw_x > n)
			break;
		memo[i + draw_x][j] = 1;
	}
	for (int draw_y = 1; sum_of_reverse_draw(y_acc, j, draw_y) <= k; draw_y += 1) {
		if (j + draw_y > n)
			break;
		memo[i][j + draw_y] = 1;
	}
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
//	Deck x(3000);
	vector<int> x_accumulated(3000);
//	Deck y(3000);
	vector<int> y_accumulated(3000);

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
		int tmp;
		cin >> x_accumulated[0];
		for (int i = 1; i < n; i++) {
			cin >> tmp;
			x_accumulated[i] = x_accumulated[i - 1] + tmp;
		}
		cin >> y_accumulated[0];
		for (int i = 1; i < n; i++) {
			cin >> tmp;
			y_accumulated[i] = y_accumulated[i - 1] + tmp;
		}

		memo[0][0] = 1;
		int case1 = 0, case2 = 0;

		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (memo[i][j] == 1) {
					case1 += 1;
					continue;
				} else if (memo[i][j] == 0) {
					memo[i][j] = 2;
					reverse_draw_from_case_2(i, j, memo, x_accumulated, y_accumulated, k, n);
					case2 += 1;
					continue;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << case1 << " " << case2 << endl;

		for (int i = 0; i < n + 1; i++) {
			fill(memo[i].begin(), memo[i].begin() + n + 1, 0);
		}
	}

	return 0;//Your program should return 0 on normal termination.
}

