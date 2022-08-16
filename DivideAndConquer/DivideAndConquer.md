### Divide & Conquer

	1) 우리말로 분할 정복은 다음과 같은 방식으로 문제를 풀어내려는 알고리즘이다.
		en) In Korean, 분할 정복 is Algorithm that tries to solve problem the following ways.

	2) 분할 정복 구현(Implementation)

		data_type Function(data) {

			if F(x)가 간단하면 :
				en) F(x) is simple

				return result;

			else :
				x를 x1과 x2로 분할;
				en) Divide x down to x1 & x2;

				return F(x1), F(x2)로 구한 F(x)값;
				en) return F(x) value obtained by F(x1), F(x2);
		}

#* 중요 *
	ㄱ. 분할: 더 이상 나누어지지 않을 때까지 동일한 유형의 문제로 가장 작은 단위까지 문제를 쪼개어 나눔.
	ㄴ. 정복: 가장 작은 단위의 하위 문제들을 해결하여 정복함.
	ㄷ. 조합: 해결된 하위 문제들의 결과를 원래 문제에 대한 결과로 조합한다.

	* Important *
	a. Divide: Divide the problem down to the smallest Unit of the same type until it can no longer be divided.
	b. Conquer: Conquer by solving the subproblem of the smallest unit.
	c. Combine: Combine the results of subproblem was solved to result for the original problem.