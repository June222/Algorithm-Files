#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

#define INF 2e9
#define MAX 501

typedef tuple<int, int, int> Tuple; // from, to, cost;

vector<Tuple> Edges;

int MinimumCost[MAX]{};

Tuple input() {
	int a, b, c;
	cin >> a >> b >> c;
	return { a,b,c };
}

; void setEdgesUp(int node, int road, int worm)
{
	for (int i = 0; i < road; i++)
	{
		int From, To, Cost;
		tie(From, To, Cost) = input();

		Edges.emplace_back(From, To, Cost);
		Edges.emplace_back(To, From, Cost);
	}

	for (int i = 0; i < worm; i++)
	{
		int From, To, Cost;
		tie(From, To, Cost) = input();

		Edges.emplace_back(From, To, -Cost);
	}
}

void init(int numOfNodes)
{
	for (int i = 0; i < numOfNodes; i++)
	{
		MinimumCost[i] = 0;
	}
}

void clearEdges() {
	Edges.clear();
}

void BellmanFord(int numOfNodes)
{
	int From, To, Cost;

	for (int i = 0; i < numOfNodes - 1; i++) {
		for (int j = 0; j < Edges.size(); j++) {
			tie(From, To, Cost) = Edges[j];

			if (MinimumCost[To] > MinimumCost[From] + Cost) {
				MinimumCost[To] = MinimumCost[From] + Cost;
			}
		}
	}

	for (int i = 0; i < Edges.size(); i++) {
		int From, To, Cost;
		tie(From, To, Cost) = Edges[i];

		if (MinimumCost[To] > MinimumCost[From] + Cost) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
}

int main()
{
	int numOfNodes, numOfRoads, numOfWormhole;
	int tc;	cin >> tc;

	while (tc--) {
		tie(numOfNodes, numOfRoads, numOfWormhole) = input();
		init(numOfNodes);
		setEdgesUp(numOfNodes, numOfRoads, numOfWormhole);
		BellmanFord(numOfNodes);
		clearEdges();
	}

	return 0;
}