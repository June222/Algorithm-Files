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

// 집부터 가게까지 거리 구하는 함수
int GetDistance(Pair house, Pair store) {
	return abs(house.first - store.first) + abs(house.second - store.second);
}

// 가게를 고른 이후 도시의 치킨거리 구하기.
void CheckMinDistance() {
	int sum = 0;

	// 모든 집에서 계산
	for (int i = 0; i < houses.size(); i++) {

		int mind = 1000000;

		// 열려있는 가게들 중 가장 가까운 것 고르기.
		for (int j = 0; j < opened.size(); j++) 
			mind = MIN(mind, GetDistance(houses[i], opened[j]));
		
		// 집 마다의 치킨거리의 합.
		sum += mind;
	}
	// 계산된 도시의 치킨 거리중 가장 작은 값
	MinSum = MIN(MinSum, sum);
}

// BackTracking으로 구현.
void OpenStore(int start, int cnt) {
	if (cnt == M)
	{
		CheckMinDistance();
		return;
	}

	// 이 부분!!!!
	// 조합이기 때문에 중복하여 계산할 필요가 없음.
	// 이때 1. 검사의 시작은 들어온 갑부터, 2. 다시 확인할 부분은 i + 1
	// 두개가 다름.
	for (int i = start; i < stores.size(); i++) {
		opened.push_back(stores[i]);
		OpenStore(i + 1, cnt + 1);
		opened.pop_back();
	}
}

int main() {

	int num;
	cin >> N >> M;

	// 배열을 쓰면 맵이 상관이 없음.
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