//https://practice.geeksforgeeks.org/problems/maximum-water-between-two-buildings/0
int maxWater(int height[], int n)
{
	int left = 0, right = n - 1;
	int maximum = INT_MIN;
	while (left <= right) {
		int water = (right - left - 1) * min(height[left], height[right]);
		maximum = max(maximum, area);

		if (height[right] < height[left])
			right--;
		else
			left++;
	}

	return maximum;
}
