
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

	// ��� ��û
	if (n == 0) {

		// ���� ����ִ� ����� ��� ��û(����)
		if (isEmpty())
			cout << 0 << '\n';

		// ���� ������� ���� ����� ��� ��û
		else {
			cout << arr[1] << '\n';

			// ������ ��� ���� �� ������ --;
			int last = arr[size--];



			// ���� �ּ�
			int curr_index = 1;

			// root�� ����
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





			//// ���� �ڽ��� �ִ� ��쿡��
			//while (curr_index * 2 <= size) {

			//	// ���� �ڽĺ��� ���簪�� ũ�ٸ� ���ʰ� switch 
			//	if (arr[curr_index * 2] < last) {

			//		// �ڽİ� ����
			//		int child_left = arr[curr_index * 2];

			//		// �ڽ��� ���� �ø���
			//		arr[curr_index] = child_left;

			//		// ���� ��ġ ����
			//		curr_index = 2 * curr_index;

			//		// �ֱ�
			//		arr[curr_index] = last;
			//	}

			//	// ������ �ڽ��� �ְ�, ������ �ڽ� ���� ���簪�� ũ�ٸ� �����ʰ� switch
			//	else if (curr_index * 2 + 1 <= size && arr[curr_index * 2 + 1] < last) {

			//		// �ڽİ� ����
			//		int child_right = arr[curr_index * 2];

			//		// �ڽ��� ���� �ø���
			//		arr[curr_index] = child_right;

			//		// ���� ��ġ ����
			//		curr_index = 2 * curr_index + 1;

			//		// �ֱ�
			//		arr[curr_index] = last;

			//	}

			//	// �ڽ��� �ִµ� �� �ڽĺ��� ũ�� �ʴٸ� while Ż��
			//	else
			//		break;
			//}

		}
	}

	// ��� ���� ��
	else {

		int curr_index = ++size;
		// ���� ��ġ�� ��� ����
		arr[curr_index] = n;

		// ��Ʈ�� �Ǳ� �������� && �θ𺸴� ���� ���, ���� �ø�
		while (curr_index != 1 && n < arr[curr_index / 2]) {

			// �θ��� Data ����
			int parent = arr[curr_index / 2];

			// ���� ���� ��ġ�� �θ� �ű��
			arr[curr_index] = parent;

			// ���� ��ġ ����
			curr_index /= 2;

			// �θ��� ��ġ�� Data ����ֱ�
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
