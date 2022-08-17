### �÷��̵� �ͼ�
	: �׷����� ��� �������� �ּ� �Ÿ��� ���ϴ� �˰����̸�, �Ʒ� ����� ������.

	��. �ܹ��� �׷������� �����ϴ�.
	��. Ư�� �������� ���� �Ÿ��� �ּҶ�� ���̺��� ������Ʈ�Ѵ�.
	��. �̹� ���� ���� �̿��Ͽ� ���ο� �Ÿ��� ���س�����.
	

### Floyd-Warshall
	: It is Algorithm to find Minimum Distance between all vertices of graph, and follows the method below 

	a. This is possible in One-Way Graph.
	b. If the distance obtained from specific vertex is minimum, the Table is Updated.
	c. New distance is calculated using Already obtained value.

# * �߿� *
	1. �ܹ��� �׷������� �����ϴ�.
	2. ���ͽ�Ʈ�� �˰��򿡼� �����ϱ� ���� ���� ����ġ ó���� �����ϴ�.(����Ŭ�� ���� ��쿡 ���Ͽ�.)
	3. �ð� ���⵵�� O(V^3)(V�� ����� ����)�̴�.
	4. ���� ���⵵�� O(V^2)�̴�.

# * Important *
	1. This is possible in One-Way Graph.
	2. It is also possible to handle negative weights, which is hard to implement in dijkstra's Algorithm.(if there is no cycle.)
	3. Time Complexity is O(V^3)(V is number of vertecies).
	4. Space Complexity is O(V^2).


# ����
	1. ������ ����.
	2. ���� ����ġ ó���� �����ϴ�.(����Ŭ�� ���� ���)
# Advantages
	1. This is simple to implement.
	2. It is possible to handle negative weights.(if there is no cycle.)


# ����
	1. �ð� ���⵵�� �ʹ� ũ��. ���� 100�� �̻��� �ڷῡ�� �������ϴ�.
# DisAdvantages
	1. Time Complexity is too large. Therefore, It is not suitable for more than 100 data.


# ����
	��. �ܼ��� �ݺ��� 3���� ���� �ִ� �Ÿ��� ���Ѵ�.
	��. DP ����� �̿��Ѵ�.

	return_type Function(x)
	{
		for (int i = 1; i <= N; i++) // i�� �������� �ϴ� ���
		{
			for (int i = j; j <= N; j++) // ��� ���
			{
				for (int k = 1; k <= N; k++) // ���� ���
				{
					if (Cost[j][i] != INF && Cost[i][k] != INF)
					{
						if (Cost[j][k] > Cost[j][i] + Cost[i][k])
						{
							Cost[j][k] = Cost[j][i] + Cost[i][k];
						}
					}
				}
			}
		}
	}

# Implementation
	a. Simply loop 3 loops find Minimum Distance.
	b. Dynamic-Programming is used.