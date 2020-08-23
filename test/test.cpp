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

using namespace std;

int main(int argc, char **argv) {
	streambuf *coutbuf_ = std::cout.rdbuf();

	ostringstream output;
	ifstream correct_output;
	correct_output.open(TEST_OUTPUT);
	freopen(TEST_INPUT, "r", stdin);
//	cout.rdbuf(output.rdbuf());

	executable_main(argc, argv);
	cout.rdbuf(coutbuf_);
	cout << "abcd" << endl;
	return 0;
}
