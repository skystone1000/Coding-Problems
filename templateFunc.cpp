#include <bits/stdc++.h>

using namespace std;

class Solution{
public:	
	int solve (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	}
};

int main ()
{
    int t; cin >> t;
    while (t--){

        // INPUTS
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;

        // SOLUTION
        Solution ob;
        cout << ob.solve (arr, n, m, x) << endl;
    }
}