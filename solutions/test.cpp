#include <vector>
using namespace std;

int a() {
	vector<int> t(1000);
	return t.back();
}
int b() {
	vector<int> t(1000);
	return t[t.size() - 1];
}
int main() {
	a();
	b();
	return 0;
}
