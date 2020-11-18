//// Codeforces Round 646
//// A. Odd Selection
//#include<iostream>
//#include<vector>
////#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int testCases;
//    cin >> testCases;
//    for (int t = 0; t < testCases; t++) {
//        long long n, x;
//        cin >> n >> x;
//        vector<long long> arr;
//        long long evenC = 0, oddC = 0;
//        for (int i = 0; i < n; i++) {
//            long long temp;
//            cin >> temp;
//            if (temp % 2 == 0) {
//                evenC++;
//            }
//            else {
//                oddC++;
//            }
//            arr.push_back(temp);
//        }
//
//        if (x % 2 == 0) {
//            oddC--;
//            evenC--;
//            if (oddC < 0 || evenC < 0) {
//                cout << "No" << endl;
//                continue;
//            }
//            if (oddC >= x - 2 || evenC >= x - 2 || oddC/2 + evenC/2 >= x/2-1) {
//                cout << "Yes" << endl;
//                continue;
//            }
//            else {
//                cout << "No" << endl;
//                continue;
//            }
//        }
//        else {
//            oddC--;
//            if (oddC < 0) {
//                cout << "No" << endl;
//                continue;
//            }
//            if (oddC >= x - 1 || evenC >= x - 1 || oddC / 2 + evenC / 2 >=  (x - 1)/2) {
//                cout << "Yes" << endl;
//                continue;
//            }
//            else {
//                cout << "No" << endl;
//            }
//
//        }
//
//
//    }
//    return 0;
//}