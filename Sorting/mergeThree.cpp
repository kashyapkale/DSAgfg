
void merge(vector<int>& temp1, vector<int>& temp2, vector<int>& ans, int len1, int len2, int p, int q) {
	while (p < len1 && q < len2) {
		int minimum = min(temp1[p], temp2[q]);
		ans.push_back(minimum);
		if (temp1[p] == minimum) {
			p++;
			continue;
		}

		if (temp2[q] == minimum) {
			q++;
			continue;
		}
	}

	while (p < len1) {
		ans.push_back(temp1[p]);
		p++;
	}

	while (q < len2) {
		ans.push_back(temp2[q]);
		q++;
	}
}



vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C)
{
	int len_A = A.size();
	int len_B = B.size();
	int len_C = C.size();
	int i = 0, j = 0, k = 0;
	vector<int> ans;
	while (i < len_A && j < len_B && k < len_C) {
		int minimum = min(A[i], min(B[j], C[k]));
		ans.push_back(minimum);
		if (A[i] == minimum) {
			i++;
			continue;
		}
		if (B[j] == minimum) {
			j++;
			continue;
		}
		if (C[k] == minimum) {
			k++;
			continue;
		}
	}


	if (i == len_A)
		merge(B, C, ans, len_B, len_C, j, k);

	else if (j == len_B)
		merge(A, C, ans, len_A, len_C, i, k);

	else
		merge(A, B, ans, len_A, len_B, i, j);


	return ans;
}
