// Program to find Dijkstra's shortest path using
// priority_queue in STL
#define INF 200001
#include <list>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

list<pair<int, int>> NodeEdge[200000];
void pushEdge(int a, int b, int weight) {
	NodeEdge[a].push_back(make_pair(b, weight));
	NodeEdge[b].push_back(make_pair(a, weight));
}
priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;
pair<int, pair<int, bool>> dist[2000000]; //dist & last & incr
pair<int, int> monoIncDist[200000]; // dist & lastr

int shortestPath(int vtxNum) {

	pq.push(make_pair(0, 0));
	dist[0].first = 0;
	monoIncDist[0].first = 0;

	while (!pq.empty()) {
		int midpoint = pq.top().second;
		pq.pop();
		for (list< pair<int, int> >::iterator i = NodeEdge[midpoint].begin(); i != NodeEdge[midpoint].end(); ++i) {
			int dest = (*i).first;
			int weight = (*i).second;
			if (monoIncDist[midpoint].first < INF && monoIncDist[dest].first > monoIncDist[midpoint].first + weight && monoIncDist[midpoint].second <= weight) {
				monoIncDist[dest].first = monoIncDist[midpoint].first + weight;
				monoIncDist[dest].second = weight;
			}
			if (dist[dest].first > dist[midpoint].first + weight) {
				int newval = dist[midpoint].first + weight;
				int lastPath = dist[midpoint].second.first;
				bool incr = dist[midpoint].second.second;
				int lastIncPath = monoIncDist[midpoint].second;
				if ((incr && lastPath <= weight) ||(!incr && lastPath >= weight)) {
					dist[dest].first = newval;
					dist[dest].second.first = weight;
					dist[dest].second.second = incr;
					pq.push(make_pair(dist[dest].first, dest));
				}
				else if (incr && lastPath >= weight) {
					dist[dest].first = newval;
					dist[dest].second.first = weight;
					dist[dest].second.second = false;
					pq.push(make_pair(dist[dest].first, dest));
				}
				else if(monoIncDist[midpoint].first < INF){
					bool isitIncr = monoIncDist[midpoint].second <= weight;
					dist[dest].first = monoIncDist[midpoint].first + weight;
					dist[dest].second.first = weight;
					dist[dest].second.second = isitIncr;
					pq.push(make_pair(dist[dest].first, dest));
				}
				
			}

		}
	}
	if (dist[vtxNum - 1].first >= INF) {
		return -1;
	}
	return dist[vtxNum - 1].first;
}
int Answer;

int main(int argc, char** argv)
{
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
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		int nodes, edges;
		cin >> nodes >> edges;
		for (int i = 0; i < nodes; ++i) {
			NodeEdge[i].clear();
			dist[i].first = INF;
			dist[i].second.first = 0;
			dist[i].second.second = true;
			monoIncDist[i].first = INF;
			monoIncDist[i].second = 0;
		}
		int a, b;
		int weight;
		for (int i = 0; i < edges; ++i) {
			cin >> a >> b >> weight;
			pushEdge(a-1, b-1, weight);
		}
		Answer = shortestPath(nodes);


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}