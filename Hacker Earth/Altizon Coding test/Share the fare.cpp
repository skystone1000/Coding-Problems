// Problem - Share the fare
// https://www.hackerearth.com/problem/algorithm/sharethefare-1/

#include <bits/stdc++.h>
using namespace std;

map < string , int > paid;
map < string , int >  correct;
map < int , string > order;

int main()
{
    int t , n ,  m , q, amount, money;
    string s , c;

    cin >> t;

    while(t--){
        cin >> n >> q;

        correct.clear();        // reset for each case
        paid.clear();
        order.clear();

        for(int i = 0; i < n; i++){
            cin >> s;
            order[i] = s;                               // memorize the order of the input
        }

        for(int i = 0; i < q; i++){
            cin >> s;
            cin >> amount >> m;
            money = amount / (m + 1) + amount % (m + 1);        // the extra amount of money added to the first
            paid[s] += amount;                                  // actual paid money
            correct[s] += money;                                // oney supposed to pay

            money = amount / (m + 1);
            for(int j = 0; j < m; j++){
                cin >> s;
                correct[s] += money;                            // amount of money that other memebers in the transaction should pay
            }
        }

        for(int i = 0; i < n; i++){                             // output the names in the order given in the Question
            s = order[i];
            amount = correct[s] - paid[s];                      // supposed paid money - actual paid money

            if(amount == 0) cout << s << " neither owes nor is owed\n";     
            else if (amount > 0) cout << s << " owes " << amount << "\n";
            else cout << s << " is owed " << -amount << "\n";
        }
    }

    return 0;
}