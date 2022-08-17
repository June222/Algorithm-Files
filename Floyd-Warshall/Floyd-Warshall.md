### 플로이드 와샬
	: 그래프의 모든 정점간의 최소 거리를 구하는 알고리즘이며, 아래 방식을 따른다.

	ㄱ. 단방향 그래프에서 가능하다.
	ㄴ. 특정 정점에서 구한 거리가 최소라면 테이블을 업데이트한다.
	ㄷ. 이미 구한 값을 이용하여 새로운 거리를 구해나간다.
	

### Floyd-Warshall
	: It is Algorithm to find Minimum Distance between all vertices of graph, and follows the method below 

	a. This is possible in One-Way Graph.
	b. If the distance obtained from specific vertex is minimum, the Table is Updated.
	c. New distance is calculated using Already obtained value.

# * 중요 *
	1. 단방향 그래프에서 가능하다.
	2. 다익스트라 알고리즘에선 구현하기 힘든 음수 가중치 처리도 가능하다.(사이클이 없는 경우에 한하여.)
	3. 시간 복잡도가 O(V^3)(V는 노드의 개수)이다.
	4. 공간 복잡도가 O(V^2)이다.

# * Important *
	1. This is possible in One-Way Graph.
	2. It is also possible to handle negative weights, which is hard to implement in dijkstra's Algorithm.(if there is no cycle.)
	3. Time Complexity is O(V^3)(V is number of vertecies).
	4. Space Complexity is O(V^2).


# 장점
	1. 구현이 쉽다.
	2. 음수 가중치 처리가 가능하다.(사이클이 없는 경우)
# Advantages
	1. This is simple to implement.
	2. It is possible to handle negative weights.(if there is no cycle.)


# 단점
	1. 시간 복잡도가 너무 크다. 따라서 100개 이상의 자료에는 부적합하다.
# DisAdvantages
	1. Time Complexity is too large. Therefore, It is not suitable for more than 100 data.


# 구현
	ㄱ. 단순히 반복문 3개를 돌며 최단 거리를 구한다.
	ㄴ. DP 방식을 이용한다.

	return_type Function(x)
	{
		for (int i = 1; i <= N; i++) // i를 경유지로 하는 경우
		{
			for (int i = j; j <= N; j++) // 출발 노드
			{
				for (int k = 1; k <= N; k++) // 도착 노드
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