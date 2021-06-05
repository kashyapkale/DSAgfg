//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#
int dp[1005][1005];

int lcs(int x, int y, string &s1, string &s2)
{
	if (x == s1.size() && y == s2.size()) {
		memset(dp, -1, sizeof(dp));
	}
	if (dp[x][y] != -1)
		return dp[x][y];

	if (x == 0 || y == 0)
		return dp[x][y] = 0;

	if (s1[x - 1] == s2[y - 1])
		return dp[x][y] = 1 + lcs(x - 1, y - 1, s1, s2);
	else
		return dp[x][y] = max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2));
}
