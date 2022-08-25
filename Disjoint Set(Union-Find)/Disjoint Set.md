### 분리 집합
	: 노드간의 연결이 아닌 그룹간의 연결을 나타내는 알고리즘으로 다음 방식을 따른다.

	ㄱ. 각 그룹을 트리의 형태로 표현한다.
	ㄴ. 모든 노드는 부모 노드의 번호를 저장하고 있다.(초기값은 자기자신)
	ㄷ. 모든 그룹은 하나의 루트 노드를 가지며 루트 노드는 부모 노드의 번호가 자기 자신인 것으로 찾을 수 있다.
	ㄹ. 다른 그룹간의 노드가 서로 연결될 경우, 한 루트 노드의 부모 번호를 다른 루트 노드의 번호로 바꾸어 병합한다.


### Disjoint Set
	: It is Algorithm that represent the connection between groups, not the connection between nodes, following method below.

	a. Represent each group as form of tree.
	b. All nodes store number of parent node(initial value is itself)
	c. All nodes have one root node, root node can be found as the number of parent node which is same as it's number.
	d. If nodes between diffent groups are connected, the number of parent of one root node is replaced with number of other root node and merged.


# * 중요 *
	1. 모든 분리집합은 공통된 원소를 지니지 않는다.(공통된 원소를 가진 순간 같은 그룹이 된다.)

	2. 알고리즘의 수행을 위해 다음 두가지 작업이 필요하다.
		1) 그룹 비교 (루트 노드 찾기)
		2) 그룹 합침 (두 그룹 병합하기)
	
# * Important *
	1. All Disjoint Set have no common element.

	2. Following two tasks are needed for performance of algorithm.
		1) Group Comparison (Find the Root node)
		2) Group Combination (Merge two groups)

# 구현
	int Find(int num)
	{
		if (num == Parent[num])
			return num;

		return Find(Parent[num]);
		// 재귀적으로 부모의 번호가 자기 자신과 같을 때까지(루트 노드) 찾아서 반환한다. 
		// 하지만 이 방식은 매우 느릴 수 있다.

		return Parent[num] = Find(Parent[num]);
		// 찾음과 동시에 저장하면 다음 번에는 루트 노드로 한 번에 움직일 수 있다.

	}

	// 이 부분은 아직 최적화 과정이 남은 것 이 있다!!

	void Union(int a, int b)
	{
		int root1 = Find(a); int root2 = Find(b);
		// 각 그룹의 루트 노드를 찾는다.
		
		if (root1 == root2)
		{
			return;
			// 그룹이 같으면 합칠 필요 없다.
		}

		Parent[root2] = root1;
	}
}


# Implementation
	int Find(int num)
	{
		if (num == Parent[num])
			return num;

		return Find(Parent[num]);
		// Return Root node by finding recursionly. 
		// But this method can be slow easily.

		return Parent[num] = Find(Parent[num]);
		// If you find and store at the same time, you can move to root node at once next time.
	}
		
	// This part is still in optimization process.

	void Union(int a, int b)
	{
		int root1 = Find(a); int root2 = Find(b);
		// Find the root nodes of each groups.
		
		if (root1 == root2)
		{
			return;
			// If groups are same, merging isn't needed.
		}

		Parent[root2] = root1;
	}
