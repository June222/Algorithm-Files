### 분할 정복
	: 문제를 둘 이상의 하위 문제로 나누어 문제를 해결하려는 알고리즘으로 아래 3단계를 따른다.

	ㄱ. 분할: 더 이상 나누어지지 않을 때까지 동일한 유형의 문제로 가장 작은 단위까지 문제를 쪼개어 나눔.
	ㄴ. 정복: 가장 작은 단위의 하위 문제들을 해결하여 정복함.
	ㄷ. 조합: 해결된 하위 문제들의 결과를 원래 문제에 대한 결과로 조합한다.

### Divide-and-Conquer
	Divide-and-Conquer is Algorithm that tries to solve problem by dividing it into two or more sub-problem with following 3-steps.

	a. Divide: Divide the problem down to the smallest Unit of the same type until it can no longer be divided.
	b. Conquer: Conquer by solving the subproblem of the smallest unit.
	c. Combine: Combine the results of subproblem was solved to result for the original problem.


# * 중요 *
	1. 둘 이상의 문제로 나눌 때 자연스러운 방법이 있어야한다.
	2. 일반 재귀 호출과 다른 점은 나눌 때의 크기가 거의 같다는 것이다.
	3. 조합을 할 때 효율적인 계산이 있어야한다.(분할 정복을 쓴다고 항상 효율적이진 않다.)
	4. 정복의 조건은 간단해야한다.

# * Important *
	1. There should be natural way to divide it into two or more sub-problems.
	2. The difference from regular recursion call is that the size of divsion is almost same.
	3. There should be efficient computation when doing combination.(It is not always efficient to use Divide-and-Conquer.)
	4. The condition of Conquer should be simple.


# 구현
	return_type Function(x)
	{
		if F(x)가 간단하면 :
			return result;

		else :
			x를 x1과 x2로 분할;
			return F(x1), F(x2)로 구한 F(x)값;
	}

# Implementation
	return_type Function(x)
	{
		if F(x) is simple :
			return result;

		else :
			Divide x down to x1 & x2;
			return F(x) value obtained by F(x1), F(x2);
	}