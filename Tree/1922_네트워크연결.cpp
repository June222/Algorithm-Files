#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1001

typedef tuple<int, int, int> Tuple;

int parent[MAX]{};


vector<Tuple> getEdge(int times) {
	vector<Tuple> buff;
	for (int i = 0; i < times; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		buff.emplace_back(cost, from, to);
	}
	return buff;
}

vector<Tuple> sortAscending(vector<Tuple> vec) {
	sort(vec.begin(), vec.end());
	return vec;
}

void init(int size) {
	for (int i = 0; i <= size; i++)
	{
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] == x) { return x; }
	return parent[x] = find(parent[x]);
}

bool Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b) { return false; }
	parent[b] = a;
	return true;
}

int spanningTree(vector<Tuple> edges, int numOfComs) {
	int answer = 0;
	int cnt = 0;
	for (Tuple edge : edges) {
		int cost, from, to;
		tie(cost, from, to) = edge;

		if (Union(from, to)) {
			answer += cost;
			cnt++;
		}
		if (cnt == numOfComs - 1) { break; }
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int numOfComs, numOfEdges;
	cin >> numOfComs >> numOfEdges;

	init(numOfComs);

	vector<Tuple> edges = getEdge(numOfEdges);

	edges = sortAscending(edges);

	int answer = spanningTree(edges, numOfComs);

	cout << answer;

	return 0;
}