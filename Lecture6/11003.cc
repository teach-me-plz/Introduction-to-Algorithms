
#include <iostream>
#include <vector>
#include <deque>

using Pii = std::pair<int, int>;	// q1) what is this?

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// input
	int N, L;
	std::cin >> N >> L;
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i)
		std::cin >> A[i];

	// count result
	std::vector<int> D(N);  // keep decreesing order, push front
	std::deque<Pii> cnd;	// q2) increasing? decreasing?
	for (int cur_pos = 0; cur_pos < N; ++cur_pos)
	{
		// keeping monotonicity
		while (/* q3) how to keep monotonicity? */)
		{
			cnd.pop_front();
		}
		cnd.push_front(std::make_pair(cur_pos, A[cur_pos]));

		// erase
		int end_pos = cur_pos - L;
		if (/* q4) how to keep the number of candidate under L? */)
			cnd.pop_back();

		D[cur_pos] = cnd.back().second;
	}

	// print D
	for (auto const d : D)
		std::cout << d << ' ';
}
