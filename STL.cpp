// STL  

#include<iostream>
#include <bits/stdc++.h>
#include<vector>
#include<set>
#include<map>

using namespace std;

bool f(int x,int y){
    return x > y;
}

void vectorDemo(){

    vector<int> A = { 11, 2, 3, 14 }; 
    //cout<< A[1]<<endl;
    
    sort(A.begin(),A.end()); // O(NlogN)
    /* 2,3,11,14 */

    bool present = binary_search(A.begin(), A.end(), 3); //(start,end,value to be searched)
    present = binary_search(A.begin(), A.end(), 4); //false

    A.push_back(100);
    present = binary_search(A.begin(),A.end(),100); // true

    /* 2,3,11,14,100 */
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    //2,3,11,14,100*, 100,100,100,100,123**

    /*
    vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100); // >=
    // return 100*

    vector<int>::iterator it2 = upper_bound(A.begin(),A.end(), 100); // >
    // return 123**

    cout << *it <<" "<< *it2 << endl;
    cout<< it2 - it <<endl;
    */

    // number of time 100 is occuring
    // int count = it2 - it - 1; 


    // Sort in reverse order
    sort(A.begin(),A.end(),f);
    vector<int>::iterator it3;
    for(it3 = A.begin();it3 != A.end();it3++){
        cout<< *it3 <<" ";
    }
    cout<<endl;

    // In this vector valus wont be changed 
    for(int x:A){
        cout<< x <<" ";
    }

    auto it = lower_bound(A.begin(), A.end(), 100); // >=
    auto it2 = upper_bound(A.begin(),A.end(), 100); // >

    // For handling values
    // to change values in vector iterate with reference
    for(int &x: A){ // reference
        x++;
        cout<< x<<" ";
    }

}

void setDemo(){

    // In set every operation insertion and deletion takes Log(n) time
    // but in this the elements are always sorted at any point of time

    set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for(int x: S){
        cout<< x << " ";
    }
    cout<<endl;

    // -10 -1 1 2

    auto it = S.find(-1);
    if( it == S.end() ){
        cout<<"Element not present\n";
    }else{
        cout<<"Element is present\n";
        cout<< *it <<endl;
    }
    
    
    /* set of pair
    
    std::pair<int,int> p1(1,0);
    std::pair<int,int> p2(2,1);
    std::set<std::pair<int,int>> s;
    s.insert(p1);
    s.insert(p2);
    auto it = s.find(p1);
    std::cout << it->first << "," << it->second <<std::endl;
    */
    
    // Lower bound and upper bound
    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);
    cout<< *it2 << " " << *it3 << endl;

    auto it4 = S.upper_bound(2);
    if(it4 == S.end()){
        cout<<"oops! Cant find something like that\n";
    }

    // Erasing a element
    cout<<"\nBefore Erasing:\n";
    for(int x:S){
        cout<<x<<" ";
    }
    S.erase(1);
    cout<<endl<<"After Erasing\n";
    for(int x:S){
        cout<<x<<" ";
    }
}

void mapDemo(){
    map<int,int> A;
    A[1] = 100;
    A[2] = -1;
    A[3] = 200;
    A[12837] = 1;

    map<char, int>cnt;
    string x = "Aditya Mahajan";

    for(char c:x){
        cnt[c]++;
    }

    cout<< cnt['a'] << " " << cnt['z'] <<endl;


    /*
    int n =5;
    map< int,int > arr;
    for(int i=0;i<n;i++){
        long long temp;
        cin>>temp;
        auto it = arr.find(temp);
        if (it != arr.end()){
            int count = it->second;
            it->second = count + 1;
        }
        else{
            arr.insert({temp,1});
        }
    }
    int flag = 0;
    for (auto itr = arr.begin(); itr != arr.end(); ++itr){
        if(itr->second > 2){
            cout<<"NO"<<endl;
            flag = 1;
            break;
        }
        if(itr == prev(arr.end())){
            if(itr->second > 1){
                cout<<"NO"<<endl;
                flag = 1;
                //cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
                break;
            }
        }
    }
    cout<<"YES"<<endl;
    for (auto itr = arr.begin(); itr != arr.end(); ++itr){
        cout<< itr->first <<" ";
        itr->second = itr->second - 1;
    }   
    */

}

void powerofStl(){
    // [x,y]
    /*
        add[2,3]
        add[10,20]
        add[30,400]
        add[401,450]
        give me the interval 401
    */

    set< pair<int,int> > S;

    S.insert({2,3});
    S.insert({10,20});
    S.insert({30,400});
    S.insert({401,450});

    /*
        comparing 2 pairs
        pair {a,b} is smaller than pair {c,d}
        iff (a<c) then
            {a,b} < {c,d} 
        or if(a==c and b<d)
            {a,b} < {c,d}
    */ 

    //2,3
    //10,20
    //30,400
    //401,450

    int point = 50;

    auto it = S.upper_bound({point,INT_MAX});
    if(it == S.begin()){
        cout<<"The point is not lying in any interval.. \n";
        return;
    }

    it--;
    pair<int,int> current = *it;
    if(current.first <= point && point <= current.second){
        cout<<"yes its present:" <<current.first <<" "<<current.second <<endl;
    }else{
        cout<<"The given point is not lying in any interval.. \n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
        sets, vector
        sort vector of structs,set of structs
    */

    //setDemo();


    cout<<endl;
    return 0;
}
