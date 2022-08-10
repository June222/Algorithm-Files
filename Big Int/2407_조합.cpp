#include <iostream>

using namespace std;

string answer[101][101];

int N, M;

string Sum(string s1, string s2)
{
	// 큰 수를 왼쪽에 둠
	if (s1.size() < s2.size())
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	string result = "";

	// 포인터로 사용될 변수
	int index1 = s1.size() - 1, index2 = s2.size() - 1;

	// 올림 수 유무
	int r = 0;

	// 포인터가 큰 수의 맨 앞자리 숫자를 넘어갈 때까지
	while (index1 >= 0)
	{
		// char -> int
		int a = s1[index1] - '0';

		// 올림수와 끝자리수 합하기
		int c = a + r;

		// 올림수 초기화
		r = 0;
		
		// 두번째 수도 된다면 똑같이 실행
		if (index2 >= 0)
		{
			int b = s2[index2] - '0';
			c += b;
		}

		// 끝자리 수를 합한 것이 10을 넘어가면 올림
		if (c >= 10)
		{
			c -= 10;
			r = 1;
		}

		// 결과에 char형태로 추가하고
		result = (c + '0') + result;

		// 다음 자리 수 계산
		index1--; index2--;
	}

	// while 문을 탈출했지만 올림수가 있을 수 있음. ex) 2자리 수 + 2자리 수 = 3자리 수
	if (r) 
		result = (r + '0') + result;

	return result;
}

int main()
{
	// 초기화
	answer[1][0] = "1"; answer[1][1] = "1";

	cin >> N >> M;
	for (int i = 2; i <= N; i++)
		for (int j = 0; j <= M; j++)
			// 파스칼의 삼각형 이용 (Dynamic Programming)
		{
			if (j == 0 && j == i)
				answer[i][j] = "1";

			else
				answer[i][j] = Sum(answer[i - 1][j - 1], answer[i - 1][j]);
		}


	return 0;
}