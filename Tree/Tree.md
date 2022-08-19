### 트리 구조
	: 그래프의 일종으로 한 노드에서 시작해서 다른 정점들을 순회하는 (자신에게 돌아오는 순환이 없는) 연결 그래프이며 다음 조건들을 가진다.

	ㄱ. 트리에서 최상위 노드를 루트 노드라고 한다.
	ㄴ. 노드 A가 노드 B를 가르킬 때, A를 B의 부모 노드, B를 A의 자식 노드라고 한다.
	ㄷ. 자식 노드가 없는 노드를 잎 노드 혹은 말단 노드라고 한다.
	ㄹ. 말단 노드가 아닌 노드를 내부 노드라고 한다.

### Tree Structure
	: As a kind of Graph, it is connected Graph that starts at one node and traverses other vertices (without no cycle that returns to itself), and has following conditions.

	a. The top node of tree is called the Root node.
	b. When node A points to node B, A is called Parent node of node B, B is called Child node of node A.
	c. The node that has no child is called Leaf node or Terminal node.
	d. The node that is not Terminal node is called internal node.


# * 중요 *
	1. DAG(Directed Acyclic Graphs, 방향성이 있는 비순환 그래프)의 한 종류이다.
	2. 루프나, circuit이 없다. 즉, 사이클이 없다.
	3. 임의의 두 노드 간의 경로가 유일하다.
	4. 한 개의 루트 노드만이 존재하며 모든 자식 노드는 한 개의 부모 노드만을 가진다.
	5. 이진 트리, 이진 탐색 트리, 균형 트리(AVL 트리, red-black 트리), 이진 힙(최대 힙, 최소 힙) 등이 있다.

# * Important *
	1. This is a type of DAG. (Directed Acyclic Graphs)
	2. There is no loop of circuit. That is, there is no cycle.
	3. A path between any two nodes is unique.
	4. There is only one root nodes and every childs node has only one parent node.
	5. Trees include Binary Tree, Binary Search Tree, Balanced Tree(AVL Tree, red-black Tree), Binary Heap(max-heap, min-heap).

# 구현
	1. 인접 배열 이용
	-> 1) 1차원 배열에 자신의 부모 노드만 저장하는 방법.

	-> 2) 2차원 배열에 자식 노드를 저장하는 방법.
	-> A[i][0] = 왼쪽 자식, A[i][1] = 오른쪽 자식


	2. 인접 리스트 이용
	-> 1) 가중치가 없는 트리
	-> 단순 1차원 리스트로 구현 가능

	-> 2) 가중치가 있는 트리
	-> class node {
		int 노드 번호;
		int 비용;
	}
# Implementation
	1. Using Adjcent Arrays
	-> 1) How to store it's parent node only in One-Dimensional array.

	-> 2) How to store it's child node in two-Dimensional array.
	-> A[i][0] = left child, A[i][1] = right child


	2. Using linked list
	-> 1) Unweighted Tree
	-> Can be implemented as a simple one-Dimensional list.

	-> 2) Weighted Tree
	-> class node{
		int num;
		int cost;
	}