#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<int> block_height;
long long block_i_have = 0;
long long needed_time = INT_MAX;
int top_height = -1;
int B;

void solution() {
	for (int i = block_height[0]; i <= block_height[block_height.size() - 1]; i++) {
		block_i_have = B;
		int height = i;
		int time = 0;

		for (int j = 0; j < block_height.size(); j++) {
			int gap = block_height[j] - height;

			if (gap < 0) {
				block_i_have += gap;
				time += -gap;
			}
			else if (gap >= 0) {
				block_i_have += gap;
				time += 2 * gap;
			}
		}
		if (block_i_have < 0) { continue; }
		else {

			if (needed_time >= time) {
				needed_time = time;
				top_height = height;
			}
		}
	}
}

int main() {
	int row, col;
	int h;
	cin >> row >> col >> B;
	for (int i = 0; i < row * col; i++) {
		cin >> h;
		block_height.push_back(h);
	}
	sort(block_height.begin(), block_height.end());
	solution();

	cout << needed_time << " " << top_height;

	return 0;
}