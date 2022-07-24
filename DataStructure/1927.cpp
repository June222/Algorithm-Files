#include <iostream>

using namespace std;

typedef struct Heap {
	int arr[100001];
	int size;
public:
	Heap() {}
	void init();
	void enHeap(int x);
	void print_remove();
	bool isEmpty();
}Heap;

void Heap::init() {
	for (int i = 1; i <= 100000; i++)
		arr[i] = -1;
	size = 0;
}

void Heap::enHeap(int x){
	int curr = ++size;
	int parent = curr / 2;
	arr[curr] = x;

	while (parent) {
		if (arr[parent] > arr[curr]) {
			int temp = arr[parent];
			arr[parent] = arr[curr];
			arr[curr] = temp;
			curr = parent; parent = curr / 2;
			continue;
		}
		return;
	}
}

void Heap::print_remove() {

	if (isEmpty())
		cout << 0 << '\n';

	else {
		cout << arr[1] << '\n';
		arr[1] = arr[size--];
		int curr = 1; int child = 2;

		while (child <= size) {

			// 오른쪽 자식 존재하고, 오른쪽 자식이 크면 오른쪽 자식을 대상으로 변경
			if (child + 1 <= size && arr[child] > arr[child + 1])
				child++;

			if (arr[curr] > arr[child]) {
				int temp = arr[curr];
				arr[curr] = arr[child];
				arr[child] = temp;
				curr = child;	child = 2 * curr;
				continue;
			}

			return;
		}
	}
}

bool Heap::isEmpty() {
	return size == 0;
}

Heap heap;
int N;

void solution(int x) {
	if (x)
		heap.enHeap(x);

	else
		heap.print_remove();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	heap.init();
	int x;
	cin >> N;
	while (N--) {
		cin >> x;
		solution(x);
	}

	return 0;
}