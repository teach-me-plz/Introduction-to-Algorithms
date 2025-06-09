
/*
	BOJ 1030

	exercise of divide-and-conquer,

	fill the blanks to solve the problem.
*/

#include <iostream>
#include <cmath>
using ll = long long;

ll s, N, K, R1, R2, C1, C2;

bool is_mid(ll quot)
{
	ll offset = (N - K) / 2;
	if (offset <= quot && quot < offset + K)
	{
		return true;
	}
	return false;
}

bool is_black(ll r, ll c, ll cur_len)
{
	// base 1
	ll cur_div = cur_len / N;
	if (/* ??? */)
	{
		return false;
	}
	// base 2
	if (/* ??? */)
	{
		return true;
	}

	// divide
	r &= /* ??? */;
	c &= /* ??? */;

	// conquer sub problem
	return is_black(r, c, /* ??? */);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
	for (ll r = R1; r <= R2; ++r)
	{
		for (ll c = C1; c <= C2; ++c)
		{
			if (is_black(r, c, std::pow(N, s)))
			{
				std::cout << '1';
			}
			else
			{
				std::cout << '0';
			}
		}
		std::cout << '\n';
	}
}
