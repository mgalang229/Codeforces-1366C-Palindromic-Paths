#include <bits/stdc++.h>
using namespace std;

/*

3 7
1 0 1 1 1 1 1
0 0 0 0 0 0 0
1 1 1 1 1 0 1

there are (n + m - 1) groups
=> take each diagonal in the matrix

	0 1 2 3 4 5 6
   ---------------
0 | 1 0 1 1 1 1 1
1 | 0 0 0 0 0 0 0
2 | 1 1 1 1 1 0 1

3 5
1 0 1 0 0
1 1 1 1 0
0 0 1 0 0

1 0 1 0 1
0 1 1 1 0
1 0 1 0 1

*/

void test_case(int& tc) {
	int n, m;
	cin >> n >> m;
	int mat[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	// n + m - 1 = groups (distance from origin, diagonal)
	int cnt[n+m-1][2];
	for (int i = 0; i < n + m - 1; i++)
		memset(cnt[i], 0, sizeof(cnt[i]));

	// in every group count 1s and 0s
	// i+j = distance of current cell from origin (0, 0)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt[i+j][mat[i][j]]++;

	int ans = 0;
	for (int i = 0; i <= n + m - 2; i++) {
		int j = n + m - 2 - i; // like (n - 1 - i) in the normal palindrome
		if (i >= j)
			continue; // only process up to (n + m - 2) / 2 - 1

		// either make i and (n + m - 2 - i) all equal to 0 or all equal to 1
		ans += min(cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
