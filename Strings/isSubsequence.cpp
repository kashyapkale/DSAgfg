//https://practice.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/0
bool isSubSequence(string A, string B){
    int i = 0;
    int j = 0;

    while (i < B.length()) {
        if (A[j] == B[i])
            j++;

        i++;
        if (j == A.length())
            return true;
    }
    return false;
}
