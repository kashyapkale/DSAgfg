//https://www.geeksforgeeks.org/program-addition-two-matrices/
vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B){
    int n1 = A.size();
    int m1 = A[0].size();
    int n2 = B.size();
    int m2 = B[0].size();
    vector<vector<int> > ans( n1, vector<int> (m1, 0));

    if (n1 == 0 || m1 == 0 || n1 != n2 || m1 != m2) {
        vector<vector<int> > ans1;
        return ans1;
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            ans[i][j] = A[i][j] + B[i][j];
        }
    }
    return ans;
}
