//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/0
void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i =0,j=0,k=n-1;
            while(i<=k && j<m){
                    if(arr1[i]<arr2[j])
                            i++;
                    else{
                        swap(arr2[j],arr1[k]);
                        j++;
                        k--;
                    }
            }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 


//Merge two arrays without using any extra sace
//Dryrun the logic on testcase to understand
/*Testcase
Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
*/
