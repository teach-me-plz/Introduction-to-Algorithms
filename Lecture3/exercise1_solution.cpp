
/*
	BOJ 1074

	exercise of divide-and-conquer,

	fill the blanks to solve the problem.
*/

#include <iostream>

int solve(int level, int row, int col)
{
	// 0. baes case
	if (level == 0)
	{
		return 1;
	}

	// 1. divide
	int const quadrant_len = (1 << (level - 1));
	int const quadrant_size = quadrant_len * quadrant_len;
	int const offset = (row / quadrant_len) * 2 * quadrant_size + (col / quadrant_len) * quadrant_size;

	// 2. conquer
	// conquer sub problem
	row %= quadrant_len;
	col %= quadrant_len;
	int const sub_result = solve(level - 1, row, col);

	// merge
	return sub_result + offset;
}

int main()
{
	int n, r, c;
	std::cin >> n >> r >> c;			// input : n, row, colum
	std::cout << solve(n, r, c) - 1;	// output : arrival order, starts from 0
}
