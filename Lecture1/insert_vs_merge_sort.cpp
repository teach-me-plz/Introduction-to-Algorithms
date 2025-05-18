
#include <iostream>
#include <vector>

/*
	init : i == 0���� loop invariant�� �����Ǵ��� Ȯ��
	...
	maintanance : i == k�� ���ؼ� ..�� �����Ǵ��� Ȯ��

	termination : i == n�� �Ǿ����� Ȯ��

	�̻� 3���� Ȯ���ϸ� => �˰����� �ǹٸ���.

	f(n) = (c1 + c3)*n2 + (2 * c1 + c2) * n1
*/

void sort_vec_insertion(std::vector<int>& vec) {
	// ��������
	for (int i = 0; i < vec.size(); i++) {
		int right_hand = vec[i];	// ���� �տ� ī�带 �Ű� �ΰ�... c1
		int j = i - 1;	// j�� ���ĵ� ī������� ��ġ�� �ǹ���. c2
		while (j >= 0 && vec[j] > right_hand) {	// ���ĵ� ���̸� ��ȸ�ϸ鼭, ���ĵ� ���̿��� ���� ������ ī�庸�� ���� ī�带 ���� ��
			// �� ���� ���ĵ� ī�带 �� �徿 ���ϸ鼭,
			// ���� ���� ī�� ���� ū ī��� �ѱ��,
			vec[j + 1] = vec[j]; // c1
			j--;	// c3
		}
		// ���� ���� ī�庸�� ���� ī�带 ������,
		// �� ���� ��ġ�� ���� ���� ī�带 �����Ѵ�.
		vec[j + 1] = right_hand; // c1
	}
}

/*
	O(N log N)
*/
void sort_vec_merge(std::vector<int>& vec)
{
	// base case
	// ���� 1���� ���ĵǾ��� �� �� ����.
	// n���� ���Ҹ� �����ϴ� ���� N^2�� �� �� ������,
	// 1���� ���Ҹ� �����ϴ� ���� 1��.
	if (vec.size() == 1)
	{
		return;
	}

	// split - O(N)
	// ���⼭ ��κ��� ����� �߻���.
	// merge������ ���簡 �߻�������, allocation�� ���.
	int mid = vec.size() >> 1;
	std::vector<int> left = std::vector<int>(vec.begin(), vec.begin() + mid);
	sort_vec_merge(left);

	std::vector<int> right = std::vector<int>(vec.begin() + mid, vec.end());
	sort_vec_merge(right);

	// merge - O(N)
	int lidx = 0, ridx = 0;
	for (int i = 0; i < vec.size(); ++i)
	{
		if (lidx == left.size())
		{
			vec[i] = right[ridx++];
		}
		else if (ridx == right.size())
		{
			vec[i] = left[lidx++];
		}
		else
		{
			if (left[lidx] <= right[ridx])
			{
				vec[i] = left[lidx++];
			}
			else
			{
				vec[i] = right[ridx++];
			}
		}
	}
	return;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> A(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> A[i];
	}
	//	sort_vec_insertion(A);
	sort_vec_merge(A);
	for (int i = 0; i < n; i++) std::cout << A[i] << '\n';
}
