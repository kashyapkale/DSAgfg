//https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#
//most optimized approach
//Reference video : https://youtu.be/TocJOW6vx_I


int longestSubsequence(int n, int a[])
{
	vector<int> ans;
	ans.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		int size = ans.size();
		if (a[i] > ans[size - 1])
			ans.push_back(a[i]);
		else {
			int index = lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
			ans[index] = a[i];
		}
	}

	return ans.size();
}





//Alternative to lowerbound write similar function of binary search
//still some error in binary search function
/*int binarySearch(vector<int> &v, int high, int low, int target) {
	//cout << "target : " << target << endl;
	while (low <= high) {
		int mid = (high + low) / 2;
		//cout << mid << endl;
		//cout << "Low : " << low << "High : " << high << endl;
		if (low == high) {
			if (v[low] < target)
				return low + 1;
			else
				return low;
		}

		if (v[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}
*/
