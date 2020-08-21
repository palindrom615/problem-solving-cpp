/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
/**
 * 어떤 점이 사다리를 타고 움직인다고 해 보자. 하나는 출발지에서 아래로, 하나는 도착지에서 위로.
 * w.r.t some column(s) of ladder, 두 점 모두 어느 시점에선가 이 칼럼의 각각 위쪽과 아래쪽을 지난다.
 * 그렇지 않으면 rung을 아무리 제거하더라도 둘은 만나지 못한다.
 *
 * column을 rung으로 나뉜 구간의 집합이라고 하면 점이 지나다니는 자취 구간의 연속으로 나타낼 수 있다.
 * 한 column 안에서 두 점의 자취가 포함된 가장 가까운 구간을 구하는 것이 문제.
 *
 * 각 column의 구간의 개수를 integer로 나타내면?
 * rung 하나가 갈 때 마다 그 양쪽의 column의 구간의 개수가 하나씩 늘어난다..!
 *
 * 자취를 몇 번째 rung을 넘었는지로 판단 가능.
 * 점의 자취를
 * * from(rung을 넘기 전 column)
 * * to(넘은 후 column)
 * * rung_idx(전체 rung 중 해당 rung의 idx)
 * 이렇게 세 값으로 구성된 구간의 array로 표현 가능.
 * 두 점이 만나기 위해 고장나야 하는 rung의 개수 = 두 점의 자취의 구간 중 to가 같고 rung_idx의 차이가 최소가 되는 구간 사이의 rung의 개수
 * (단, down 점의 rung_idx가 up 점의 rung_idx보다 커야 한다)
 */

#include <iostream>
#include <vector>

using namespace std;

int Answer;

typedef pair<int, int> Rung;

int solve(int from, int to, vector<Rung>& rungs) {
	return 0;
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
	for (test_case = 0; test_case < T; test_case++) {
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		int N, k, m;
		cin >> N >> k >> m;
		vector<Rung> rungs(2000);
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			rungs[i] = Rung(a, b);
		}
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			Answer += solve(from, to, rungs);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}