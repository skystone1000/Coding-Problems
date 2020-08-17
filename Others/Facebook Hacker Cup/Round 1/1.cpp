// 
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<iterator> 
#include<algorithm>
#include<cmath>
#include<unordered_map>

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

        ll N,K;
        int W;
        cin>>N>>K>>W;
        vector<ll> L(N);
        for(int i=0;i<K;i++){
            cin>>L[i];
        }

        ll AL,BL,CL,DL;
        cin>>AL>>BL>>CL>>DL;
        vector<ll> H(N);
        for(int i=0;i<K;i++){
            cin>>H[i];
        }

        ll AH,BH,CH,DH;
        cin>>AH>>BH>>CH>>DH;

        for(int i=K;i<N;i++){
            // deb(i);
            L[i] = ((AL * L[i-2] + BL * L[i-1] + CL) % DL) + 1;
            H[i] = ((AH * H[i-2] + BH * H[i-1] + CH) % DH) + 1;
        }

        
        cout<<endl;
        cout<<"N = "<<N<<" K = "<<K<<" W = "<<W<<endl;
        /*
        cout<<"Vector L ---------------------------------\n";
        for(auto &x: L){
            cout<<x<<" ";
        }

        cout<<endl;
        cout<<"Vector H ---------------------------------\n";
        for(auto &x: H){
            cout<<x<<" ";
        }*/
        for(int i=0;i<L.size();i++){
            cout<<"Count "<<i+1<<": l="<<L[i]<<" h="<<H[i]<<endl;
        }

        cout<<"\n==========================================\n";
        

        ll output = 1;
        for(int numRec = 1 ; numRec <= L.size();numRec++){
            map<ll,ll> connected;
            ll start = 0;
            ll ymax = 0;
            vector<ll> connectedHei;
            for(int i=0;i<numRec;i++){
                if(i == 0){
                    start = L[i];
                    connected[start] = 0;
                    ymax = H[i];
                }

                if(ymax<H[i]){
                    ymax = H[i];
                }
                
                if( L[i+1] - L[i] > W || i == numRec-1){
                    connected[start] = L[i] + W;
                    connectedHei.pb(ymax);
                    ymax = H[i+1];
                    start = L[i+1];
                }

                // if(i == numRec-1){
                //     connected[start] = L[i] + W;
                //     connectedHei.pb(ymax);
                // }
            }
        
            
            int i = 0;
            ll peri = 0;
            for(auto ele:connected){
                cout<<ele.first<<"  "<<ele.second<<"  "<<connectedHei[i]<<endl;
                peri = peri + (ele.second - ele.first + connectedHei[i]) * 2;
                i++;
            }
            deb2(peri,output);
            output = (output * peri) % 1000000007; 
            cout<<"\n--------------------\n";
        }

        cout<<"Case #"<<t+1<<": "<<output<<endl;
        // cout<<"======================\n";
    }

    // Save Output to file
    // fclose (stdout);
    return 0;
}
