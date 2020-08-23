#include <iostream>
#include <vector>

#ifdef TEST
#define main executable_main
#endif

using namespace std;

int Answer;

vector<int> result[3335];

int pals[] = {9999,9889,9779,9669,9559,9449,9339,9229,9119,9009,8998,8888,8778,8668,8558,8448,8338,8228,8118,8008,7997,7887,7777,7667,7557,7447,7337,7227,7117,7007,6996,6886,6776,6666,6556,6446,6336,6226,6116,6006,5995,5885,5775,5665,5555,5445,5335,5225,5115,5005,4994,4884,4774,4664,4554,4444,4334,4224,4114,4004,3993,3883,3773,3663,3553,3443,3333,3223,3113,3003,2992,2882,2772,2662,2552,2442,2332,2222,2112,2002,1991,1881,1771,1661,1551,1441,1331,1221,1111,1001,999,989,979,969,959,949,939,929,919,909,898,888,878,868,858,848,838,828,818,808,797,787,777,767,757,747,737,727,717,707,696,686,676,666,656,646,636,626,616,606,595,585,575,565,555,545,535,525,515,505,494,484,474,464,454,444,434,424,414,404,393,383,373,363,353,343,333,323,313,303,292,282,272,262,252,242,232,222,212,202,191,181,171,161,151,141,131,121,111,101,99,88,77,66,55,44,33,22,11,9,8,7,6,5,4,3,2,1};
int init() {
	for (int i = 66; i< 198; i++){
		vector<int> a {pals[i]};
		result[pals[i]] = a;
	}
	for (int i = 1; i < 3335; i++){
		vector<int> v {-1};
		result[i] = v;
	}
	return 0;
}

vector<int> calcPal(int a) {
	for (int i = 0; i<198; i++){
		if(a == pals[i]){
			vector<int>b = {a};
			return b;
		}
	}
	if(a <= 3334 && result[a][0] != -1)
		return result[a];
	else {
		vector<int> res = {-1};
		for(int i = 0; pals[i] >= a/3; i++) {
			if(pals[i] >= a){
				continue;
			}
			vector<int> candit {pals[i]};
			auto conc = calcPal(a - pals[i]);
			candit.insert(candit.end(), conc.begin(), conc.end());

			if(res[0] == -1 || candit.size() < res.size()) {
				res = candit;
			}
		}
		if(a <= 3334) {
			result[a] = res;
		}
		return res;
	}
}

int main(int argc, char** argv)
{
	init();

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

	for(test_case = 0; test_case  < T; test_case++)
	{

		string String = "";
		int n;
		cin >> n;
		vector<int> answer = calcPal(n);
		cout << "Case #" << test_case+1 << endl;
		cout << answer.size() << " ";
		auto size = answer.size();
		for(int j = 0; j < size; j++){
			cout << answer[j] << " ";
		}
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}