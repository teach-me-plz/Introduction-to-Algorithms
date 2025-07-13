#include <iostream>
#include <limits>
#include <vector>
#include <stack> // monoton stack
using ll = long long;
using pll = std::pair<ll, ll>; // q1) pll의 의미는 무엇인가?
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// input
	int N;
	std::cin >> N;
	std::vector<ll> nums(N);
	for (int i = 0; i < N; ++i)
	{
		std::cin >> nums[i];
	}

	// solve
	ll pairCnt = 0;
	std::stack<pll> st;	// q2) 단조 증가/감소?
	for (auto itr = nums.begin(); itr != nums.end(); ++itr)
	{
		const int& curVal = *itr;
		while (/* q3) 단조성을 유지하기 위한 조건은 ? */) // monotonisity를 유지
		{
			pairCnt += st.top().second; // 오르쪽이 크고, 왼 쪽이 작은 쌍의 개수
			st.pop();
		}
		if (st.empty() || curVal < st.top().first)
		{
			if (!st.empty())	// 인접한 두 사람은 반드시 쌍을 이룸
				pairCnt++;
			st.push(std::make_pair(curVal, 1));
		}
		else if (curVal == st.top().first)	// 동등한 키의 사람 끼리 쌍을 이룸
		{
			if (/* */)	// 	???
				pairCnt++;
			pairCnt += st.top().second; // 키가 같은 사람이 이루는 쌍
			st.top().second++;
		}
	}

	// print
	std::cout << pairCnt;
}
