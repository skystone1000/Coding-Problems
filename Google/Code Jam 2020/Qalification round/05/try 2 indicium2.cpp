// 05 indicium
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int n,k;
        cin>>n>>k;
        int mat[n][n];

        int diag = k/n;

        int val[n-1];
        int j=0;
        for (int i=0;i<n;i++){
            if(i+1 != diag){
                val[j] = i+1;
                j++;
            }
        }
        /*
        for(int i=0;i<n;i++){
            cout<<val[i]<<" ";
        }
        */
        cout<<"Case #"<<t+1<<": ";
        if(k%n != 0){
            if(n == 2){
                if(k == 3 || k < n || k > n*n){
                    cout<<"IMPOSSIBLE"<<endl;
                    continue;
                }
            }
            else if(n == 3){
                if(k == 4 || k == 5 || k == 7 || k == 8 || k < n || k > n*n){
                    cout<<"IMPOSSIBLE"<<endl;
                    continue;
                }
            }
            else if(n == 4){
                if(k == 5 || k == 15 || k < n || k > n*n){
                    cout<<"IMPOSSIBLE"<<endl;
                    continue;
                }
                else if(k==6){
                    cout<<"POSSIBLE"<<endl;
                    cout<<1<<" "<<2<<" "<<4<<" "<<3<<endl;
                    cout<<2<<" "<<1<<" "<<3<<" "<<4<<endl;
                    cout<<4<<" "<<3<<" "<<2<<" "<<1<<endl;
                    cout<<3<<" "<<4<<" "<<1<<" "<<2<<endl;
                    continue;
                }else if(k==7){
                    cout<<"POSSIBLE"<<endl;
                    cout<<1<<" "<<3<<" "<<4<<" "<<2<<endl;
                    cout<<2<<" "<<1<<" "<<3<<" "<<4<<endl;
                    cout<<3<<" "<<4<<" "<<2<<" "<<1<<endl;
                    cout<<4<<" "<<2<<" "<<1<<" "<<3<<endl;
                    continue;
                }else if(k==9){
                    cout<<"POSSIBLE"<<endl;
                    cout<<3<<" "<<1<<" "<<4<<" "<<2<<endl;
                    cout<<2<<" "<<3<<" "<<1<<" "<<4<<endl;
                    cout<<1<<" "<<4<<" "<<2<<" "<<3<<endl;
                    cout<<4<<" "<<2<<" "<<3<<" "<<1<<endl;
                    continue;
                }else if(k==10){
                    cout<<"POSSIBLE"<<endl;
                    cout<<4<<" "<<1<<" "<<3<<" "<<2<<endl;
                    cout<<1<<" "<<4<<" "<<2<<" "<<3<<endl;
                    cout<<2<<" "<<3<<" "<<1<<" "<<4<<endl;
                    cout<<3<<" "<<2<<" "<<4<<" "<<1<<endl;
                    continue;
                }else if(k==11){
                    cout<<"POSSIBLE"<<endl;
                    cout<<4<<" "<<2<<" "<<3<<" "<<1<<endl;
                    cout<<1<<" "<<4<<" "<<2<<" "<<3<<endl;
                    cout<<2<<" "<<3<<" "<<1<<" "<<4<<endl;
                    cout<<3<<" "<<1<<" "<<4<<" "<<2<<endl;
                    continue;
                }else if(k==13){
                    cout<<"POSSIBLE"<<endl;
                    cout<<4<<" "<<2<<" "<<1<<" "<<3<<endl;
                    cout<<3<<" "<<4<<" "<<2<<" "<<1<<endl;
                    cout<<2<<" "<<1<<" "<<3<<" "<<4<<endl;
                    cout<<1<<" "<<3<<" "<<4<<" "<<2<<endl;
                    continue;
                }else if(k==14){
                    cout<<"POSSIBLE"<<endl;
                    cout<<4<<" "<<3<<" "<<2<<" "<<1<<endl;
                    cout<<3<<" "<<4<<" "<<1<<" "<<2<<endl;
                    cout<<2<<" "<<1<<" "<<3<<" "<<4<<endl;
                    cout<<1<<" "<<2<<" "<<4<<" "<<3<<endl;
                    continue;
                }
            }
            else if(n == 5){
                if(k == 6 || k == 24 || k < n || k > n*n){
                    cout<<"IMPOSSIBLE"<<endl;
                    continue;
                }
                else if(k==7){
                    cout<<"POSSIBLE"<<endl;
                    cout<<1<<" "<<4<<" "<<2<<" "<<5<<" "<<3<<endl;
                    cout<<2<<" "<<1<<" "<<5<<" "<<3<<" "<<4<<endl;
                    cout<<3<<" "<<2<<" "<<1<<" "<<4<<" "<<5<<endl;
                    cout<<4<<" "<<5<<" "<<3<<" "<<2<<" "<<1<<endl;
                    cout<<5<<" "<<3<<" "<<4<<" "<<1<<" "<<2<<endl;  
                    continue;                  
                }else if(k==8){
                    cout<<"POSSIBLE"<<endl;
                    cout<<1<<" "<<3<<" "<<5<<" "<<4<<" "<<2<<endl;
                    cout<<3<<" "<<1<<" "<<2<<" "<<5<<" "<<4<<endl;
                    cout<<4<<" "<<2<<" "<<1<<" "<<3<<" "<<5<<endl;
                    cout<<5<<" "<<4<<" "<<3<<" "<<2<<" "<<1<<endl;
                    cout<<2<<" "<<5<<" "<<4<<" "<<1<<" "<<3<<endl;  
                    continue;                    
                }else if(k==9){
                    cout<<"POSSIBLE"<<endl;
                    cout<<1<<" "<<4<<" "<<3<<" "<<5<<" "<<2<<endl;
                    cout<<3<<" "<<1<<" "<<5<<" "<<2<<" "<<4<<endl;
                    cout<<2<<" "<<3<<" "<<1<<" "<<4<<" "<<5<<endl;
                    cout<<4<<" "<<5<<" "<<2<<" "<<3<<" "<<1<<endl;
                    cout<<5<<" "<<2<<" "<<4<<" "<<1<<" "<<3<<endl; 
                    continue; 
                }else if(k==11){
                    cout<<"POSSIBLE"<<endl;
                    cout<<2<<" "<<4<<" "<<3<<" "<<5<<" "<<1<<endl;
                    cout<<1<<" "<<2<<" "<<4<<" "<<3<<" "<<5<<endl;
                    cout<<5<<" "<<1<<" "<<2<<" "<<4<<" "<<3<<endl;
                    cout<<4<<" "<<3<<" "<<5<<" "<<1<<" "<<2<<endl;
                    cout<<3<<" "<<5<<" "<<1<<" "<<2<<" "<<4<<endl; 
                    continue; 
                }else if(k==12){
                    cout<<"POSSIBLE"<<endl;
                    cout<<1<<" "<<5<<" "<<3<<" "<<4<<" "<<2<<endl;
                    cout<<5<<" "<<3<<" "<<4<<" "<<2<<" "<<1<<endl;
                    cout<<3<<" "<<4<<" "<<2<<" "<<1<<" "<<5<<endl;
                    cout<<2<<" "<<1<<" "<<5<<" "<<3<<" "<<4<<endl;
                    cout<<4<<" "<<2<<" "<<1<<" "<<5<<" "<<3<<endl; 
                    continue; 
                }else if(k==13){
                    cout<<"POSSIBLE"<<endl;
                    cout<<3<<" "<<4<<" "<<2<<" "<<5<<" "<<1<<endl;
                    cout<<2<<" "<<3<<" "<<5<<" "<<1<<" "<<4<<endl;
                    cout<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<endl;
                    cout<<4<<" "<<5<<" "<<1<<" "<<2<<" "<<3<<endl;
                    cout<<5<<" "<<1<<" "<<4<<" "<<3<<" "<<2<<endl; 
                    continue; 
                }else if(k==14){
                    cout<<"POSSIBLE"<<endl;
                    cout<<2<<" "<<4<<" "<<5<<" "<<3<<" "<<1<<endl;
                    cout<<4<<" "<<5<<" "<<2<<" "<<1<<" "<<3<<endl;
                    cout<<5<<" "<<3<<" "<<1<<" "<<2<<" "<<4<<endl;
                    cout<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<endl;
                    cout<<3<<" "<<1<<" "<<4<<" "<<5<<" "<<2<<endl;
                    continue;  
                }else if(k==16){
                    cout<<"POSSIBLE"<<endl;
                    cout<<3<<" "<<5<<" "<<1<<" "<<4<<" "<<2<<endl;
                    cout<<5<<" "<<3<<" "<<2<<" "<<1<<" "<<4<<endl;
                    cout<<4<<" "<<2<<" "<<3<<" "<<5<<" "<<1<<endl;
                    cout<<1<<" "<<4<<" "<<5<<" "<<2<<" "<<3<<endl;
                    cout<<2<<" "<<1<<" "<<4<<" "<<3<<" "<<5<<endl;  
                    continue;
                }else if(k==17){
                    cout<<"POSSIBLE"<<endl;
                    cout<<3<<" "<<1<<" "<<2<<" "<<5<<" "<<4<<endl;
                    cout<<2<<" "<<3<<" "<<5<<" "<<4<<" "<<1<<endl;
                    cout<<1<<" "<<5<<" "<<4<<" "<<3<<" "<<2<<endl;
                    cout<<5<<" "<<4<<" "<<1<<" "<<2<<" "<<3<<endl;
                    cout<<4<<" "<<2<<" "<<3<<" "<<1<<" "<<5<<endl; 
                    continue; 
                }else if(k==18){
                    cout<<"POSSIBLE"<<endl;
                    cout<<3<<" "<<1<<" "<<2<<" "<<4<<" "<<5<<endl;
                    cout<<5<<" "<<3<<" "<<1<<" "<<2<<" "<<4<<endl;
                    cout<<4<<" "<<2<<" "<<5<<" "<<1<<" "<<3<<endl;
                    cout<<2<<" "<<4<<" "<<3<<" "<<5<<" "<<1<<endl;
                    cout<<1<<" "<<5<<" "<<4<<" "<<3<<" "<<2<<endl;  
                    continue;
                }else if(k==19){
                    cout<<"POSSIBLE"<<endl;
                    cout<<5<<" "<<4<<" "<<2<<" "<<3<<" "<<1<<endl;
                    cout<<2<<" "<<5<<" "<<3<<" "<<1<<" "<<4<<endl;
                    cout<<1<<" "<<2<<" "<<5<<" "<<4<<" "<<3<<endl;
                    cout<<4<<" "<<3<<" "<<1<<" "<<2<<" "<<5<<endl;
                    cout<<3<<" "<<1<<" "<<4<<" "<<5<<" "<<2<<endl; 
                    continue; 
                }else if(k==21){
                    cout<<"POSSIBLE"<<endl;
                    cout<<5<<" "<<4<<" "<<3<<" "<<1<<" "<<2<<endl;
                    cout<<3<<" "<<5<<" "<<2<<" "<<4<<" "<<1<<endl;
                    cout<<1<<" "<<3<<" "<<5<<" "<<2<<" "<<4<<endl;
                    cout<<2<<" "<<1<<" "<<4<<" "<<3<<" "<<5<<endl;
                    cout<<4<<" "<<2<<" "<<1<<" "<<5<<" "<<3<<endl;
                    continue;  
                }else if(k==22){
                    cout<<"POSSIBLE"<<endl;
                    cout<<5<<" "<<1<<" "<<3<<" "<<4<<" "<<2<<endl;
                    cout<<2<<" "<<5<<" "<<4<<" "<<1<<" "<<3<<endl;
                    cout<<4<<" "<<3<<" "<<5<<" "<<2<<" "<<1<<endl;
                    cout<<1<<" "<<4<<" "<<2<<" "<<3<<" "<<5<<endl;
                    cout<<3<<" "<<2<<" "<<1<<" "<<5<<" "<<4<<endl;  
                    continue;
                }else if(k==23){
                    cout<<"POSSIBLE"<<endl;
                    cout<<5<<" "<<2<<" "<<4<<" "<<3<<" "<<1<<endl;
                    cout<<4<<" "<<5<<" "<<3<<" "<<1<<" "<<2<<endl;
                    cout<<1<<" "<<4<<" "<<5<<" "<<2<<" "<<3<<endl;
                    cout<<2<<" "<<3<<" "<<1<<" "<<4<<" "<<5<<endl;
                    cout<<3<<" "<<1<<" "<<2<<" "<<5<<" "<<4<<endl; 
                    continue; 
                }

            }
        }
        for(int i=0;i<n;i++){            
            int g=0+i;
            for(int j=0;j<n;j++){
                if(i==j){
                    mat[i][j] = diag;
                } else {
                    
                    for(int f=0;f<i;f++){
                        if(g>n-2){
                            g=0;
                        }

                        if(mat[f][j] == val[g]){
                            g++;
                            if(g>n-2){
                                g=0;
                            }
                        }
                    }
                    
                    if(g>n-1){
                        g=0;
                    }
                    mat[i][j] = val[g] ; 
                    g++;
                }
            }
        }

        cout<<"POSSIBLE"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}