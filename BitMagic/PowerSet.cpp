//https://practice.geeksforgeeks.org/problems/power-set-using-recursion/1
vector<string> powerSet(string s)
{
	vector<string> vAns;
	int len = s.length();
	int bitlen = pow(2, len) - 1;

	for (int i = bitlen; i >= 0; i--) {
		int index = 0, cnt = i;
		string ans = "";
		while (cnt) {
			if (cnt & 1)
				ans += s[index];
			cnt = cnt >> 1;
			index++;
		}
		vAns.push_back(ans);
	}
	sort(vAns.begin(), vAns.end());
	return vAns;
}
