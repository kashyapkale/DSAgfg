//https://practice.geeksforgeeks.org/problems/excel-sheet5448/0
string ExcelColumn(int N){
    string ans = "";

    while (N) {
        char c = 'A' + (N - 1) % 26;
        ans = c + ans;
        N = (N - 1) / 26;
    }
    return ans;
}
