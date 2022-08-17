### ���� ����
	: ������ �� �̻��� ���� ������ ������ ������ �ذ��Ϸ��� �˰������� �Ʒ� 3�ܰ踦 ������.

	��. ����: �� �̻� ���������� ���� ������ ������ ������ ������ ���� ���� �������� ������ �ɰ��� ����.
	��. ����: ���� ���� ������ ���� �������� �ذ��Ͽ� ������.
	��. ����: �ذ�� ���� �������� ����� ���� ������ ���� ����� �����Ѵ�.

### Divide-and-Conquer
	Divide-and-Conquer is Algorithm that tries to solve problem by dividing it into two or more sub-problem with following 3-steps.

	a. Divide: Divide the problem down to the smallest Unit of the same type until it can no longer be divided.
	b. Conquer: Conquer by solving the subproblem of the smallest unit.
	c. Combine: Combine the results of subproblem was solved to result for the original problem.


# * �߿� *
	1. �� �̻��� ������ ���� �� �ڿ������� ����� �־���Ѵ�.
	2. �Ϲ� ��� ȣ��� �ٸ� ���� ���� ���� ũ�Ⱑ ���� ���ٴ� ���̴�.
	3. ������ �� �� ȿ������ ����� �־���Ѵ�.(���� ������ ���ٰ� �׻� ȿ�������� �ʴ�.)
	4. ������ ������ �����ؾ��Ѵ�.

# * Important *
	1. There should be natural way to divide it into two or more sub-problems.
	2. The difference from regular recursion call is that the size of divsion is almost same.
	3. There should be efficient computation when doing combination.(It is not always efficient to use Divide-and-Conquer.)
	4. The condition of Conquer should be simple.


# ����
	return_type Function(x)
	{
		if F(x)�� �����ϸ� :
			return result;

		else :
			x�� x1�� x2�� ����;
			return F(x1), F(x2)�� ���� F(x)��;
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