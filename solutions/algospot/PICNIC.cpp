#include <iostream>
#include <vector>
#include <set>

using namespace std;

int Answer;

template <typename T>
bool inline contains(set<T> set, T elem) {
  return set.find(elem) != set.end();
}

int num_of_cases(int n, set<int> &selected_students, vector<pair<int, int>>::iterator left_friends,  vector<pair<int, int>>::iterator left_friends_end ) {
  int ans = 0;
  if (selected_students.size() == n) {
    return 1;
  }
  for (auto friends = left_friends; friends != left_friends_end; ++friends) {
    if(contains(selected_students, friends->first) || contains(selected_students, friends->second)) {
      continue;
    }
    selected_students.insert(friends->first);
    selected_students.insert(friends->second);
    ans += num_of_cases(n, selected_students, friends, left_friends_end);
    selected_students.erase(friends->first);
    selected_students.erase(friends->second);
  }
  return ans;
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  int T, test_case;

  cin >> T;
  for (test_case = 0; test_case < T; test_case++) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> friends(m);
    for (int i = 0; i < m; i++) {
      int f1, f2;
      cin >> f1 >> f2;
      friends[i] = pair<int, int>(f1, f2);
    }
    set<int> selected_students{};
    Answer = num_of_cases(n, selected_students, friends.begin(), friends.end());
    /////////////////////////////////////////////////////////////////////////////////////////////
    /*
       Implement your algorithm here.
       The answer to the case will be stored in variable Answer.
     */
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << Answer << endl;
  }

  return 0;//Your program should return 0 on normal termination.
}