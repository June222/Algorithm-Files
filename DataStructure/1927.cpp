
#include <iostream>
using namespace std;

int arr[100001] = { 0 };

typedef struct Heap {
	int* arr;
	int size;
public:
	bool isEmpty();
	void command(int n);
}Heap;

bool Heap::isEmpty() {
	return size == 0;
}

void Heap::command(int n) {

	// 출력 요청
	if (n == 0) {

		// 힙이 비어있는 경우의 출력 요청(예외)
		if (isEmpty())
			cout << 0 << '\n';

		// 힙이 비어있지 않은 경우의 출력 요청
		else {
			cout << arr[1] << '\n';

			// 마지막 노드 복사 후 사이즈 --;
			int last = arr[size--];



			// 넣을 주소
			int curr_index = 1;

			// root로 변경
			arr[1] = last;

			while (1) {
				if (curr_index * 2 + 1 <= size) {
					int min_data =
						((arr[curr_index * 2] > arr[curr_index * 2 + 1]) ?
							arr[curr_index * 2 + 1] : (arr[curr_index * 2]));


				}
				else if (curr_index * 2 <= size) {

				}
				else {
					break;
				}
			}





			//// 왼쪽 자식이 있는 경우에만
			//while (curr_index * 2 <= size) {

			//	// 왼쪽 자식보다 현재값이 크다면 왼쪽과 switch 
			//	if (arr[curr_index * 2] < last) {

			//		// 자식값 복사
			//		int child_left = arr[curr_index * 2];

			//		// 자식을 위로 올리기
			//		arr[curr_index] = child_left;

			//		// 현재 위치 수정
			//		curr_index = 2 * curr_index;

			//		// 넣기
			//		arr[curr_index] = last;
			//	}

			//	// 오른쪽 자식이 있고, 오른쪽 자식 보다 현재값이 크다면 오른쪽과 switch
			//	else if (curr_index * 2 + 1 <= size && arr[curr_index * 2 + 1] < last) {

			//		// 자식값 복사
			//		int child_right = arr[curr_index * 2];

			//		// 자식을 위로 올리기
			//		arr[curr_index] = child_right;

			//		// 현재 위치 수정
			//		curr_index = 2 * curr_index + 1;

			//		// 넣기
			//		arr[curr_index] = last;

			//	}

			//	// 자식은 있는데 두 자식보다 크지 않다면 while 탈출
			//	else
			//		break;
			//}

		}
	}

	// 노드 생성 시
	else {

		int curr_index = ++size;
		// 현재 위치에 노드 생성
		arr[curr_index] = n;

		// 루트가 되기 이전까지 && 부모보다 작을 경우, 위로 올림
		while (curr_index != 1 && n < arr[curr_index / 2]) {

			// 부모의 Data 복사
			int parent = arr[curr_index / 2];

			// 현재 나의 위치에 부모 옮기기
			arr[curr_index] = parent;

			// 현재 위치 수정
			curr_index /= 2;

			// 부모의 위치에 Data 집어넣기
			arr[curr_index] = n;
		}
	}
}

int N;

int main()
{
	Heap heap{ arr,0 };
	int number;
	cin >> N;
	for (int i = 0; i < N; i++) {
		/*cin >> number;*/
		number = 0;
		heap.command(number);
	}

	return 0;
}
