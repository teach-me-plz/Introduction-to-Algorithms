
#include <iostream>
#include <vector>

/*
	init : i == 0에서 loop invariant가 유지되는지 확인
	...
	maintanance : i == k에 대해서 ..가 유지되는지 확인

	termination : i == n이 되었는지 확인

	이상 3종을 확인하면 => 알고리즘이 옳바르다.

	f(n) = (c1 + c3)*n2 + (2 * c1 + c2) * n1
*/

void sort_vec_insertion(std::vector<int>& vec) {
	// 삽입정렬
	for (int i = 0; i < vec.size(); i++) {
		int right_hand = vec[i];	// 오른 손에 카드를 옮겨 두고... c1
		int j = i - 1;	// j는 정렬된 카드더미의 위치를 의미함. c2
		while (j >= 0 && vec[j] > right_hand) {	// 정렬된 더미를 순회하면서, 정렬된 더미에서 현재 삽입할 카드보다 작은 카드를 만날 때
			// 왼 손의 정렬된 카드를 한 장씩 비교하면서,
			// 오른 손의 카드 보다 큰 카드는 넘기고,
			vec[j + 1] = vec[j]; // c1
			j--;	// c3
		}
		// 오른 손의 카드보다 작은 카드를 만나면,
		// 그 다음 위치에 오른 손의 카드를 삽입한다.
		vec[j + 1] = right_hand; // c1
	}
}

/*
	O(N log N)
*/
void sort_vec_merge(std::vector<int>& vec)
{
	// base case
	// 원소 1개는 정렬되었다 할 수 있음.
	// n개의 원소를 정렬하는 것은 N^2이 들 수 있지만,
	// 1개의 원소를 정렬하는 것은 1임.
	if (vec.size() == 1)
	{
		return;
	}

	// split - O(N)
	// 여기서 대부분의 비용이 발생함.
	// merge에서도 복사가 발생하지만, allocation이 비쌈.
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
