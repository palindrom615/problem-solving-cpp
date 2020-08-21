/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
/**
 * 어떤 점이 사다리를 타고 움직인다고 해 보자. 하나는 출발지에서 아래로, 하나는 도착지에서 위로.
 * w.r.t some pillar(s) of ladder, 두 점 모두 어느 시점에선가 이 세로선의 각각 위쪽과 아래쪽을 지난다.
 * 그렇지 않으면 이음선을 아무리 제거하더라도 둘은 만나지 못한다.
 *
 * 점이 움직이는 것을 '몇 번째 세로선의(pillarNum) 몇 번째 이음선(stepIdx)에 도착'의 연속으로 표현.
 *
 * ex. 그림의 경우
 * 1st ladder_down: (4, 2) -> (2, 3)
 * 3rd up: (4, 4) -> (1, 1)
 * 4번째 세로선에서 1 down은 2번째, 3 up은 4번째 이음선에 도착하므로 그 사이에 있는 (4, 3) 이음선을 치우면 서로 만남을 알 수 있다.
 *
 * pseudo code
 *
 * for (from, to)
 * 		Answer += closest(pillarNum_Idxes(ladder_down(from)), pillarNum_Idxes(up(to)))
 *
 */

#include <iostream>
#include <vector>
#include <array>

using namespace std;

int Answer;

typedef pair<int, int> Step;
typedef pair<int, int> PillarNumStepIdx;

vector<array<PillarNumStepIdx, 2>> get_step_position_on_pillar(vector<Step> &steps, int k, vector<int> &cnt) {
	vector<array<PillarNumStepIdx, 2>> pillar_idx(k + 1);
	for (int i = 1; i <= k; i++) {
		auto step = steps[i];
		pillar_idx[i] = {PillarNumStepIdx(step.first, cnt[step.first]), PillarNumStepIdx(step.second, cnt[step.second])};
		cnt[step.first] += 1;
		cnt[step.second] += 1;
	}
	return pillar_idx;
}

vector<PillarNumStepIdx> ladder_down(int pillar, vector<array<PillarNumStepIdx, 2>> &steps) {
	vector<PillarNumStepIdx> res = {PillarNumStepIdx(pillar, 0)};
	int locus = pillar;
	for (auto &step: steps) {
		if (step[0].first == locus) {
			locus = step[1].first;
			res.push_back(step[1]);
		} else if (step[1].first == locus) {
			locus = step[0].first;
			res.push_back(step[0]);
		}
	}
	return res;
}

vector<PillarNumStepIdx> ladder_up(int pillar, vector<array<PillarNumStepIdx, 2>> &steps, vector<int> &cnt) {
	vector<PillarNumStepIdx> res = {PillarNumStepIdx (pillar, cnt[pillar])};
	int locus = pillar;
	for (auto step = steps.rbegin(); step != steps.rend(); step++) {
		if ((*step)[0].first == locus) {
			locus = (*step)[1].first;
			res.push_back((*step)[1]);
		} else if ((*step)[1].first == locus) {
			locus = (*step)[0].first;
			res.push_back((*step)[0]);
		}
	}
	return res;
}

int solve(int from, int to, vector<array<PillarNumStepIdx, 2>> &steps, vector<int>& cnt) {
	auto down_route = ladder_down(from, steps);
	auto up_route = ladder_up(to, steps, cnt);
	if (down_route.back().first == to) {
		return 0;
	}
	int answer = 2001;
	for (auto &dr: down_route) {
		for (auto &ur: up_route) {
			if (dr.first == ur.first) {
				if (dr.second == ur.second) {
					return 1;
				}
				if (dr.second < ur.second && (ur.second - dr.second - 1) < answer) {
					answer = (ur.second - dr.second - 1);
				} else {
					break;
				}
			}
		}
	}
	if (answer == 2001) {
		return -1;
	}
	return answer;
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
		vector<Step> steps(2001);

		for (int i = 1; i <= k; i++) {
			int a, b;
			cin >> a >> b;
			steps[i] = Step(a, b);
		}
		vector<int> cnt(k + 1, 1);

		auto pillarNumStepIdxes = get_step_position_on_pillar(steps, k, cnt);
		for (int i = 0; i < m; i++) {
			int from, to;
			cin >> from >> to;
			Answer += solve(from, to, pillarNumStepIdxes, cnt);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}