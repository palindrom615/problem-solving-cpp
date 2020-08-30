#include <iostream>

using namespace std;

int Answer;

int num_of_trees_by_init_height[100000];
int height_by_init_height[100000];

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
		int N;
		cin >> N;
		for (int _ = 0; _ < N; _++) {
			int init_height;
			cin >> init_height;
			num_of_trees_by_init_height[init_height] += 1;
			height_by_init_height[init_height] = init_height;
		}
		for (int _ = 0; _ < N; _++) {
			int laser_height;
			cin >> laser_height;
			for (int init_height = 0; init_height < 100000; init_height++) {
				if (num_of_trees_by_init_height[init_height] == 0) {
					continue;
				}
				if (height_by_init_height[init_height] > laser_height) {
					Answer += (height_by_init_height[init_height] - laser_height) *
							  num_of_trees_by_init_height[init_height];
					height_by_init_height[init_height] = laser_height + 1;
				} else {
					height_by_init_height[init_height] += 1;
				}
			}
		}

		fill(num_of_trees_by_init_height, num_of_trees_by_init_height + 100000, 0);
		fill(height_by_init_height, height_by_init_height + 100000, 0);
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}