#include<bits/stdc++.h>
using namespace std;

// long long countOfPossibleProfit (int Y, int X, int N) {
//    // Write your code here
//    // long long ans = Y-X+1;
//    set<int> profits;
//    dfs(Y, X, N, 0, 0, profits);

//    return profits.size();
// }

void dfs(int y, int x, int n, int curr, int sum, set<long long>& profits){
   if(curr == n){
      profits.insert(sum);
      return;
   }

   for(int i=x;i<=y;i++){
      if(curr == 0){
         dfs(y, x, n, curr+1, sum+x, profits);
         break;
      }
      else if(curr == n-1){
         dfs(y, x, n, curr+1, sum+y, profits);
         break;
      }
      dfs(y, x, n, curr+1, sum+i, profits);
   }
}

long long countOfPossibleProfit( int Y, int X, int N) {
   set<long long> profits;
   dfs(Y, X, N, 0, 0, profits);

   // for(auto ele:profits){
   //    cout<<ele<<endl;
   // }
   return profits.size();
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int X;
    cin >> X;
    int Y;
    cin >> Y;

    long long out_;
    out_ = countOfPossibleProfit(Y, X, N);
    cout << out_;
}