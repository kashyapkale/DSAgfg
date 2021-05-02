//https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-array-1587115620/1
void insertAns(int k,vector<int> &v){
	int len = v.size();
	if(len==0){
		v.push_back(k);
		return;
	}

	if(k>v[len-1])
		v.push_back(k);

	return;
}


vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
	int i=0,j=0;
	vector<int> v;
	while((i!=n) && (j!=m)){
		if(arr1[i] == arr2[j]){
			insertAns(arr1[i],v);
			i++;
			j++;
			continue;
		}

		if(arr1[i]<arr2[j]){
		    insertAns(arr1[i],v);
			i++;
			continue;
		}

		if(arr2[j]<arr1[i]){
		    insertAns(arr2[j],v);
			j++;
			continue;
		}
	}
	
	while(i!=n){
	    insertAns(arr1[i],v);
	    i++;
	}
	
	while(j!=m){
	    insertAns(arr2[j],v);
	    j++;
	}

	return v;
}
