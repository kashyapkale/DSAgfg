//https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
//Moores Voing Algorithm
int majorityElement(int a[], int size)
{

	int cnt = 1, max_elem = a[0];
	for (int i = 0; i < size; i++) {

		if (a[i] == max_elem)
			cnt++;
		else
			cnt--;

		if (cnt == 0)
			max_elem = a[i];
	}

	if (cnt == 0)
		return -1;

	cnt = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == max_elem)
			cnt++;

	return (cnt > (size / 2)) ? max_elem : -1;


}
