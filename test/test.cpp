#include "test.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false);
	streambuf *stdout_buf = std::cout.rdbuf();

	stringstream submit_output;
	ifstream correct_output;
	correct_output.open(TEST_OUTPUT);
	freopen(TEST_INPUT, "r", stdin);
	cout.rdbuf(submit_output.rdbuf());

	executable_main(argc, argv);

	string correct_line;
	string submit_line;
	bool is_correct = true;
	int line_num = 0;
	while (getline(correct_output, correct_line)) {
		if (!getline(submit_output, submit_line)) {
			is_correct = false;
			cerr << "submitted output ended too soon!" << endl;
			cerr << line_num << ": " << correct_line << endl;
			break;
		}
		boost::algorithm::trim(submit_line);
		boost::algorithm::trim(correct_line);
		line_num += 1;
		if (correct_line != submit_line) {
			is_correct = false;
			cerr << "output line " << line_num << " was wrong" << endl;
			cerr << "\tguess\n\t" << line_num << ": " << submit_line << endl;
			cerr << "\tcorrect\n\t" << line_num << ": " << correct_line << endl;
		}
	}
	if (getline(submit_output, submit_line)) {
		is_correct = false;
		cerr << "submitted is keep chattering after passing every cases!" << endl;
		cerr << line_num << ": " << submit_line << endl;
	}
	return is_correct ? 0 : 1;
}
