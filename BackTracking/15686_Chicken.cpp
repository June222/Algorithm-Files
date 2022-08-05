#include <iostream>
#include <vector>

using namespace std;

#define MIN(a,b) ((a>=b)?b:a)

typedef pair <int, int> Pair;

vector<Pair> houses;
vector<Pair> stores;
vector<Pair> opened;

int N, M;
int MinSum = 1000000;

// ������ ���Ա��� �Ÿ� ���ϴ� �Լ�
int GetDistance(Pair house, Pair store) {
	return abs(house.first - store.first) + abs(house.second - store.second);
}

// ���Ը� �� ���� ������ ġŲ�Ÿ� ���ϱ�.
void CheckMinDistance() {
	int sum = 0;

	// ��� ������ ���
	for (int i = 0; i < houses.size(); i++) {

		int mind = 1000000;

		// �����ִ� ���Ե� �� ���� ����� �� ����.
		for (int j = 0; j < opened.size(); j++) 
			mind = MIN(mind, GetDistance(houses[i], opened[j]));
		
		// �� ������ ġŲ�Ÿ��� ��.
		sum += mind;
	}
	// ���� ������ ġŲ �Ÿ��� ���� ���� ��
	MinSum = MIN(MinSum, sum);
}

// BackTracking���� ����.
void OpenStore(int start, int cnt) {
	if (cnt == M)
	{
		CheckMinDistance();
		return;
	}

	// �� �κ�!!!!
	// �����̱� ������ �ߺ��Ͽ� ����� �ʿ䰡 ����.
	// �̶� 1. �˻��� ������ ���� ������, 2. �ٽ� Ȯ���� �κ��� i + 1
	// �ΰ��� �ٸ�.
	for (int i = start; i < stores.size(); i++) {
		opened.push_back(stores[i]);
		OpenStore(i + 1, cnt + 1);
		opened.pop_back();
	}
}

int main() {

	int num;
	cin >> N >> M;

	// �迭�� ���� ���� ����� ����.
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> num;

			if (num == 1)
				houses.emplace_back(i, j);
			else if (num == 2)
				stores.emplace_back(i, j);
		}

	OpenStore(0,0);

	cout << MinSum;

	return 0;
}