### Ʈ�� ����
	: �׷����� �������� �� ��忡�� �����ؼ� �ٸ� �������� ��ȸ�ϴ� (�ڽſ��� ���ƿ��� ��ȯ�� ����) ���� �׷����̸� ���� ���ǵ��� ������.

	��. Ʈ������ �ֻ��� ��带 ��Ʈ ����� �Ѵ�.
	��. ��� A�� ��� B�� ����ų ��, A�� B�� �θ� ���, B�� A�� �ڽ� ����� �Ѵ�.
	��. �ڽ� ��尡 ���� ��带 �� ��� Ȥ�� ���� ����� �Ѵ�.
	��. ���� ��尡 �ƴ� ��带 ���� ����� �Ѵ�.

### Tree Structure
	: As a kind of Graph, it is connected Graph that starts at one node and traverses other vertices (without no cycle that returns to itself), and has following conditions.

	a. The top node of tree is called the Root node.
	b. When node A points to node B, A is called Parent node of node B, B is called Child node of node A.
	c. The node that has no child is called Leaf node or Terminal node.
	d. The node that is not Terminal node is called internal node.


# * �߿� *
	1. DAG(Directed Acyclic Graphs, ���⼺�� �ִ� ���ȯ �׷���)�� �� �����̴�.
	2. ������, circuit�� ����. ��, ����Ŭ�� ����.
	3. ������ �� ��� ���� ��ΰ� �����ϴ�.
	4. �� ���� ��Ʈ ��常�� �����ϸ� ��� �ڽ� ���� �� ���� �θ� ��常�� ������.
	5. ���� Ʈ��, ���� Ž�� Ʈ��, ���� Ʈ��(AVL Ʈ��, red-black Ʈ��), ���� ��(�ִ� ��, �ּ� ��) ���� �ִ�.

# * Important *
	1. This is a type of DAG. (Directed Acyclic Graphs)
	2. There is no loop of circuit. That is, there is no cycle.
	3. A path between any two nodes is unique.
	4. There is only one root nodes and every childs node has only one parent node.
	5. Trees include Binary Tree, Binary Search Tree, Balanced Tree(AVL Tree, red-black Tree), Binary Heap(max-heap, min-heap).

# ����
	1. ���� �迭 �̿�
	-> 1) 1���� �迭�� �ڽ��� �θ� ��常 �����ϴ� ���.

	-> 2) 2���� �迭�� �ڽ� ��带 �����ϴ� ���.
	-> A[i][0] = ���� �ڽ�, A[i][1] = ������ �ڽ�


	2. ���� ����Ʈ �̿�
	-> 1) ����ġ�� ���� Ʈ��
	-> �ܼ� 1���� ����Ʈ�� ���� ����

	-> 2) ����ġ�� �ִ� Ʈ��
	-> class node {
		int ��� ��ȣ;
		int ���;
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