// 03 Parenting
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int activities;
        cin>>activities;
        int timing[activities][4]; // start - end - rank - assign
        char ans[activities];
        for(int i=0;i<activities;i++){
            cin>>timing[i][0]>>timing[i][1];
            timing[i][2] = i;
            timing[i][3] = 0;
        }
        
        //int i, j;  
        // sorted acording to finish time
        for (int i = 0; i < activities-1; i++){     
            // Last i elements are already in place  
            for (int j = 0; j < activities-i-1; j++){ 
                if (timing[j][1] > timing[j+1][1]){  
                    int temp = timing[j+1][1];
                    timing[j+1][1] = timing[j][1];
                    timing[j][1] = temp;

                    temp = timing[j+1][0];
                    timing[j+1][0] = timing[j][0];
                    timing[j][0] = temp;

                    temp = timing[j+1][2];
                    timing[j+1][2] = timing[j][2];
                    timing[j][2] = temp; 
                }
            }
        }

        
        for(int i=0;i<activities;i++){
            //cout<<timing[i][0]<<"\t"<<timing[i][1]<<"\t"<<timing[i][2]<<"\t"<<timing[i][3]<<"\n";
        }

        // First Activity to James(1)
        timing[0][3] = 1;
        int i=0;
        for (int j = 1; j < activities; j++) { 
            if (timing[j][0] >= timing[i][1]) {
                timing[j][3] = 1;
                i = j;
            }
        }

        // Finding first remaining activity
        int firstC;
        for(int k=0;k<activities;k++){
            if(timing[k][3] != 1){
                firstC=k;
                break;
            }
        }

        // First Activity to Car(2)
        timing[firstC][3] = 2;
        i=0;
        for (int j = 1; j < activities; j++) { 
            if (timing[j][0] >= timing[i][1] && timing[j][3] != 1) { 
                timing[j][3] = 2;
                i = j;
            }
        }

        cout<<"Case #"<<t+1<<": ";
        // Finding if any remaining activity
        int poss=0;
        for(int k=0;k<activities;k++){
            int lst = timing[k][3] != 2;
            if(timing[k][3] != 1 && timing[k][3] != 2){
                cout<<"IMPOSSIBLE";
                poss =1;
                break;
            }
        }
        /*
        // sorted acording to input
        for (i = 0; i < activities-1; i++){     
            // Last i elements are already in place  
            for (j = 0; j < activities-i-1; j++){ 
                if (timing[j][2] > timing[j+1][2]){  

                    int temp3 = timing[j+1][2];
                    timing[j+1][2] = timing[j][2];
                    timing[j][2] = temp3; 

                    int temp = timing[j+1][1];
                    timing[j+1][1] = timing[j][1];
                    timing[j][1] = temp;

                    int temp2 = timing[j+1][0];
                    timing[j+1][0] = timing[j][0];
                    timing[j][0] = temp2;

                }
            }
        }*/

        cout<<"\n========================\nTiming Table\n";
        cout<<"start \t end \t rank \t assign\n";
        for(int i=0;i<activities;i++){
            cout<<timing[i][0]<<"\t"<<timing[i][1]<<"\t"<<timing[i][2]<<"\t"<<timing[i][3]<<"\n";
        }

        if(poss != 1){
            for(int i=0;i<activities;i++){
                for(int j=0;j<activities;j++){
                    if(timing[j][2] == i){
                        if(timing[j][3] == 1){
                            cout<<"J";
                        }else if(timing[j][3] == 2){
                            cout<<"C";
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}