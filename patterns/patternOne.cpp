#include<bits/stdc++.h>
#define lli long long
using namespace std;

void printPattern(lli N) {
	for (int i = N; i > 0; i--) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				cout << j << " ";
				continue;
			}
			cout << "  ";
		}
		for (int j = N - 1; j > 0; j--) {
			if (i == j) {
				cout << j << " ";
				continue;
			}
			cout << "  ";
		}
		cout << endl;
	}

	for (int k = 2; k <= N; k++) {
		for (int j = 1; j <= N; j++) {
			if (k == j) {
				cout << j << " ";
				continue;
			}
			cout << "  ";
		}
		for (int j = N - 1; j > 0; j--) {
			if (k == j) {
				cout << j << " ";
				continue;
			}
			cout << "  ";
		}
		cout << endl;
	}

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	lli T;
	cin >> T;
	printPattern(T);
	return 0;
}




/*Output

                  10                   
                9   9                 
              8       8               
            7           7             
          6               6           
        5                   5         
      4                       4       
    3                           3     
  2                               2   
1                                   1 
  2                               2   
    3                           3     
      4                       4       
        5                   5         
          6               6           
            7           7             
              8       8               
                9   9                 
                  10                   
*/
