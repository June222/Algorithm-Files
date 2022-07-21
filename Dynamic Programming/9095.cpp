#include <iostream>

using namespace std;

int Count = 0;
int main()
{
	int tc, num;
	cin >> tc;
	while (tc--) {
		int numof123[4] = { 0 };
		Count = 0; int factorialN = 0;
		int temp1, temp2, temp3;

		cin >> num;
		int temp_sum = 1;
		int temp_num = num;

		numof123[3] = temp_num / 3;

		while (numof123[3] >= 0) {
			factorialN = 0;
			numof123[1] = 0; numof123[2] = 0;

			temp_num = num;
			temp_num -= 3 * numof123[3];

			numof123[2] = temp_num / 2;
			temp_num -= 2 * numof123[2];

			temp_num -= numof123[1] = temp_num / 1;

			while (numof123[2] >= 0) {
				factorialN = 0; temp_sum = 1;

				for (int i = 1; i <= 3; i++) {
					factorialN += numof123[i];
				}
				temp1 = numof123[1]; temp2 = numof123[2]; temp3 = numof123[3];
				while (factorialN) {
					temp_sum *= factorialN--;
				}
				while (temp1) {
					temp_sum /= temp1--;
				}
				while (temp2) {
					temp_sum /= temp2--;
				}
				while (temp3) {
					temp_sum /= temp3--;
				}
				Count += temp_sum;
				if (--numof123[2] < 0) {
					numof123[2]++;
					break;
				}
				numof123[1] += 2;
			}


			numof123[3]--;
		}

		cout << Count << '\n';
	}




	return 0;
}