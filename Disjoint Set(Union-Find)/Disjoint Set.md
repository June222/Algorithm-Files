### �и� ����
	: ��尣�� ������ �ƴ� �׷찣�� ������ ��Ÿ���� �˰������� ���� ����� ������.

	��. �� �׷��� Ʈ���� ���·� ǥ���Ѵ�.
	��. ��� ���� �θ� ����� ��ȣ�� �����ϰ� �ִ�.(�ʱⰪ�� �ڱ��ڽ�)
	��. ��� �׷��� �ϳ��� ��Ʈ ��带 ������ ��Ʈ ���� �θ� ����� ��ȣ�� �ڱ� �ڽ��� ������ ã�� �� �ִ�.
	��. �ٸ� �׷찣�� ��尡 ���� ����� ���, �� ��Ʈ ����� �θ� ��ȣ�� �ٸ� ��Ʈ ����� ��ȣ�� �ٲپ� �����Ѵ�.


### Disjoint Set
	: It is Algorithm that represent the connection between groups, not the connection between nodes, following method below.

	a. Represent each group as form of tree.
	b. All nodes store number of parent node(initial value is itself)
	c. All nodes have one root node, root node can be found as the number of parent node which is same as it's number.
	d. If nodes between diffent groups are connected, the number of parent of one root node is replaced with number of other root node and merged.


# * �߿� *
	1. ��� �и������� ����� ���Ҹ� ������ �ʴ´�.(����� ���Ҹ� ���� ���� ���� �׷��� �ȴ�.)

	2. �˰����� ������ ���� ���� �ΰ��� �۾��� �ʿ��ϴ�.
		1) �׷� �� (��Ʈ ��� ã��)
		2) �׷� ��ħ (�� �׷� �����ϱ�)
	
# * Important *
	1. All Disjoint Set have no common element.

	2. Following two tasks are needed for performance of algorithm.
		1) Group Comparison (Find the Root node)
		2) Group Combination (Merge two groups)

# ����
	int Find(int num)
	{
		if (num == Parent[num])
			return num;

		return Find(Parent[num]);
		// ��������� �θ��� ��ȣ�� �ڱ� �ڽŰ� ���� ������(��Ʈ ���) ã�Ƽ� ��ȯ�Ѵ�. 
		// ������ �� ����� �ſ� ���� �� �ִ�.

		return Parent[num] = Find(Parent[num]);
		// ã���� ���ÿ� �����ϸ� ���� ������ ��Ʈ ���� �� ���� ������ �� �ִ�.

	}

	// �� �κ��� ���� ����ȭ ������ ���� �� �� �ִ�!!

	void Union(int a, int b)
	{
		int root1 = Find(a); int root2 = Find(b);
		// �� �׷��� ��Ʈ ��带 ã�´�.
		
		if (root1 == root2)
		{
			return;
			// �׷��� ������ ��ĥ �ʿ� ����.
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
