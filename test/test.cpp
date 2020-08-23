//
// Created by jwm on 8/23/20.
//

/**
 *
 */

#include "test.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>

using namespace std;

int main(int argc, char **argv) {
	streambuf *coutbuf_ = std::cout.rdbuf();

	cout << TEST_INPUT << TEST_OUTPUT << endl;
	stringstream submit_output;
	ifstream correct_output;
	correct_output.open(TEST_OUTPUT);
	freopen(TEST_INPUT, "r", stdin);
	cout.rdbuf(submit_output.rdbuf());

	executable_main(argc, argv);

	string correct_line;
	string submit_line;
	int line_num = 0;
	while (getline(correct_output, correct_line)) {
		getline(submit_output, submit_line);
		boost::algorithm::trim(submit_line);
		boost::algorithm::trim(correct_line);
		line_num += 1;
		if (correct_line != submit_line) {
			cout.rdbuf(coutbuf_);
			cout << "output line " << line_num << " was wrong"<<endl;
			cout << "\tguess: \n\t" << submit_line << endl;
			cout << "\tcorrect: \n\t" << correct_line << endl;

			cout.rdbuf(submit_output.rdbuf());
		}
	}

	cout.rdbuf(coutbuf_);
	return 0;
}
