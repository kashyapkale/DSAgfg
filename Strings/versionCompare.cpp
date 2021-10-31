//https://practice.geeksforgeeks.org/problems/compare-version-number/1
int VersionCompare(string v1, string v2){
	int n = v1.length();
	int m = v2.length();
	int i = 0;
	int j = 0;

	while (i < n || j < m) {
		string ch1 = "";
		string ch2 = "";
		while (v1[i] != '.' ) {
			if (i >= n) {
				if (ch1 == "") {
					ch1 += "0";
				}
				break;
			}
			else
				ch1 += v1[i];
			i++;
		}
		while (v2[j] != '.') {
			if (j >= m) {
				if (ch2 == "") {
					ch2 += "0";
				}
				break;
			}
			else
				ch2 += v2[j];
			j++;
		}
		int n1 = stoi(ch1);
		int n2 = stoi(ch2);
		//cout<<n1<<" "<<n2<<endl;
		if (n1 < n2)
			return -1;
		if (n1 > n2)
			return 1;
		i++;
		j++;
	}
	return 0;
}
