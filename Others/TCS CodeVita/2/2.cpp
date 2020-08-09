// 
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>
#include<string>
#include <iomanip>

#define ll long long
#define pb push_back
#define deb(x) cout<<#x<<" = "<<x<<endl
#define deb2(x,y) cout<<#x<<" = "<<x <<", "<<#y<<" = "<<y<<endl
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Save output to a file
    // freopen ("myfile.txt","w",stdout);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        map<string,int> inv_dic;
        map<string,int> cart;
        map<string,double> cost;

        while(true){
            /*
            cout<<"------------------------------"<<endl;

            cout<<"============= Inv ==============="<<endl;
            for(auto element:inv_dic)
                cout<<element.first<<" "<<element.second<<endl;
            
            cout<<"============= Cost =============="<<endl;
            for(auto element:cost)
                cout<<element.first<<" "<<element.second<<endl;

            cout<<"============= Cart =============="<<endl;
            for(auto element:cart)
                cout<<element.first<<" "<<element.second<<endl;
            */

            for(auto element:inv_dic)
                if(element.second <= 0)
                    inv_dic.erase(element.first);

            std::map<string,int>::iterator it;

            string command;
            // cout<<"Waiting for command"<<endl;
            cin>>command;
            // cout<<command<<endl;
            if(command == "END"){
                break;
            }
            string user;
            cin>>user;
            string function;
            cin>>function;
            
            if(user == "SM"){
                string item;
                cin>>item;
                if( function == "ADD"){
                    int val;
                    cin>>val;
                    try{
                        it=inv_dic.find(item);
                        if(it != inv_dic.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        if (val>0){
                            inv_dic[item] += val;
                            cout<<val<<endl;
                        }
                        else
                            cout<<"-1"<<endl;
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "REMOVE"){
                    try{
                        it=inv_dic.find(item);
                        if(it == inv_dic.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        inv_dic.erase(item);
                        cout<<"1"<<endl;
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "INCR"){
                    int val;
                    cin>>val;
                    try{
                        //=================================
                        it=inv_dic.find(item);
                        if(it == inv_dic.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        if(val>0)
                            inv_dic[item] = inv_dic[item]+val;
                        cout<<val<<endl;
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "DCR"){
                    int val;
                    cin>>val;
                    try{
                        if (val<inv_dic[item]){
                            //========================================
                            // inv_dic[item] = inv_dic.get(item,0)-val;
                            it=inv_dic.find(item);
                            if(it == inv_dic.end()){
                                cout<<"-1"<<endl;
                                continue;
                            }
                            inv_dic[item] = inv_dic[item]-val;
                            cout<<val<<endl;
                        }
                        else if (val==inv_dic[item]){
                            inv_dic.erase(item);
                            cout<<val<<endl;
                        }
                        else{
                            inv_dic.erase(item);
                            cout<<"-1"<<endl;
                        }
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "SET_COST"){
                    double fval;
                    cin>>fval;
                    try{
                        //===========================
                        cost[item] = fval;
                        cout << fixed << std::setprecision(1) << fval<<endl;
                        continue;
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "GET_QTY"){
                    try{
                        //-=========================================
                        
                        it=inv_dic.find(item);
                        if(it == inv_dic.end()){
                            cout<<"0"<<endl;
                            continue;
                        }
                        cout<<inv_dic[item]<<endl;
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
            }
            else if(user == "S"){

                if (function == "ADD"){
                    string item;
                    cin>>item;
                    int val;
                    cin>>val;
                    try{
                        it=cart.find(item);
                        if(it != cart.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        if (val>0 && inv_dic[item] >= val){
                            cart[item] += val;
                            cout<<val<<endl;
                            inv_dic[item] = inv_dic[item] - val;
                            if(inv_dic[item] <= 0){
                                inv_dic.erase(item);
                            }
                        }else{
                            cout<<"-1"<<endl;
                        }
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }

                else if ( function == "REMOVE"){
                    string item;
                    cin>>item;
                    try{
                        it=cart.find(item);
                        if(it == cart.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        inv_dic[item] = inv_dic[item] + cart[item];
                        cart.erase(item);
                        cout<<"1"<<endl;
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "INCR"){
                    string item;
                    cin>>item;                    
                    int val;
                    cin>>val;
                    try{
                        it=cart.find(item);
                        if(it == cart.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        if (val>0 && inv_dic[item] >= val){
                            cart[item] = cart[item]+val;
                            cout<<val<<endl;
                            inv_dic[item] = inv_dic[item] - val;
                            if(inv_dic[item] <= 0){
                                inv_dic.erase(item);
                            }
                        }
                        else{
                            cout<<"-1"<<endl;
                        }
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                else if ( function == "DCR"){
                    string item;
                    cin>>item;
                    int val;
                    cin>>val;
                    try{
                        it=cart.find(item);
                        if(it == cart.end()){
                            cout<<"-1"<<endl;
                            continue;
                        }
                        if (val<cart[item]){
                            inv_dic[item] = inv_dic[item] + val;
                            cart[item] = cart[item]-val;
                            cout<<val<<endl;
                            
                        }
                        else if(val==cart[item]){
                            inv_dic[item] = inv_dic[item] + cart[item];
                            cart.erase(item);
                            cout<<val<<endl;
                        }
                        else{
                            // cart.erase(item);
                            cout<<"-1"<<endl;
                        }
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }  
                else if ( function == "GET_ORDER_AMOUNT"){
                    double out = 0.00;
                    try{
                        for (auto i : cart){
                            out+= (cost[i.first] * i.second);
                            // cout<<i.first<<" "<<i.second<<endl;
                        }
                        // cout<<"done";
                        cout << fixed << std::setprecision(2) << round(out)<<endl;
                        // print("{:.2f}".format(out))
                    }catch(exception e){
                        cout<<"-1"<<endl;
                    }
                }
                
            }



        }
    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
