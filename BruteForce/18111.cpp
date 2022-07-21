#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> land_height;
long long block_i_have = 0;
int top_height = 0;
int needed_time = INT_MAX;
long long B = 0;
long long gap = 0;

bool doHaveEnoughBlock(int height) {
	long long sum = B;
	for (int i = 0; i < land_height.size(); i++) {
		sum += land_height[i] - height;
	}
	if (sum >= 0) return true;
	else return false;
}

long long checktime(int height) {
	long long time = 0;
	for (int i = 0; i < land_height.size(); i++) {
		gap = abs(land_height[i] - height);
		if (land_height[i] > height) { time += 2 * gap; }
		else if (land_height[i] < height) { time += gap; }
	}
	return time;
}

void solution(int start, int end) {
	if (start > end) { return; }
	long long mid_height = (long long)(land_height[start] + land_height[end]) / 2;
	int mid = (start + end) / 2;
	if (doHaveEnoughBlock(mid_height)) {
		if (needed_time >= checktime(mid_height)) {
			needed_time = checktime(mid_height);
			if (top_height <= mid_height) {
				top_height = mid_height;

			}
		}
		solution(mid + 1, end);
	}
	else solution(start, mid - 1);
}

int main() {
	int row, col;
	long long height;
	cin >> row >> col >> B;
	block_i_have += B;
	for (int i = 0; i < row * col; i++) {
		cin >> height;
		land_height.push_back(height);
	}
	sort(land_height.begin(), land_height.end());
	solution(0, land_height.size() - 1);

	cout << needed_time << " " << top_height;

	return 0;
}