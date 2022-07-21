#include <iostream>
using namespace std;
int Count = 0;

// 그리디 알고리즘으로 풀 생각을 함
//
// 왜? 10 팩토리얼이 오버플로우가 일어나지 않기 때문.

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

			// 초기화 
			factorialN = 0;
			numof123[1] = 0; numof123[2] = 0;

			// 3으로 나눈 몫
			temp_num = num;
			temp_num -= 3 * numof123[3];
			 
			// 3으로 나눈 나머지를 2로 나눈 몫
			numof123[2] = temp_num / 2;
			temp_num -= 2 * numof123[2];

			// 2로 나눈 나머지를 1로 나눈 몫
			temp_num -= numof123[1] = temp_num / 1;

			// 2부터 1씩 줄여나가며 시행
			while (numof123[2] >= 0) {
				factorialN = 0; temp_sum = 1;

				// 팩토리얼을 쓰기 위한 총 숫자의 개수
				for (int i = 1; i <= 3; i++) 
					factorialN += numof123[i];
				
				temp1 = numof123[1]; temp2 = numof123[2]; temp3 = numof123[3];

				// 같은 것이 있는 수열
				while (factorialN) 
					temp_sum *= factorialN--;
				
				while (temp1) 
					temp_sum /= temp1--;
				
				while (temp2) 
					temp_sum /= temp2--;
				
				while (temp3) 
					temp_sum /= temp3--;
				
				Count += temp_sum;

				// 2의 개수가 0 보다 작아지면 3의 개수 줄이기
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