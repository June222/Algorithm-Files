### ���� ����
	1) ���� ������ ������ ���� ������� ������ Ǯ����� �˰����̴�.

	2) ���� ���� ����

		data_type Function(data) {

			if F(x)�� �����ϸ� :
				return result;

			else :
				x�� x1�� x2�� ����;
				return F(x1), F(x2)�� ���� F(x)��;
		}

### Divide & Conquer
	1) Divide-and-Conquer is Algorithm that tries to solve problem the following ways.

	2) Divide-and-Conquer Implementation 

		data_type Function(data) {

			if F(x) is simple :
				return result;

			else :
				Divide x down to x1 & x2;
				return F(x) value obtained by F(x1), F(x2);
		}

# * �߿� *
	��. ����: �� �̻� ���������� ���� ������ ������ ������ ������ ���� ���� �������� ������ �ɰ��� ����.
	��. ����: ���� ���� ������ ���� �������� �ذ��Ͽ� ������.
	��. ����: �ذ�� ���� �������� ����� ���� ������ ���� ����� �����Ѵ�.

# * Important *
	a. Divide: Divide the problem down to the smallest Unit of the same type until it can no longer be divided.
	b. Conquer: Conquer by solving the subproblem of the smallest unit.
	c. Combine: Combine the results of subproblem was solved to result for the original problem.