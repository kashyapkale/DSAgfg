//https://practice.geeksforgeeks.org/problems/the-modified-string-1587115621/1
int modified(string a){
    int i = 0, j = 0;
    int cnt = 0;

    for (int i = 1; i < a.length() - 1;) {
        if (a[i] == a[i - 1] && a[i] == a[i + 1]) {
            cnt ++;
            i += 2;
            continue;
        }
        i++;
    }

    return cnt;
}
