//https://practice.geeksforgeeks.org/problems/binary-array-sorting-1587115620/0
void binSort(int A[], int N)
{
   int one =0;
   int zero =0;
   
   for(int i=0;i<N;i++)
        (A[i]==1)?one++:zero++;
    
    int index = 0;
    
    while(zero--){
        A[index] = 0;
        index++;
    }
        
    while(one--){
        A[index] = 1;
        index++;
    }
    
}
