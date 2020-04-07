// 
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
        }
        
        int i, j;  
        // sorted acording to finish time
        for (i = 0; i < activities-1; i++){     
            // Last i elements are already in place  
            for (j = 0; j < activities-i-1; j++){ 
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
        cout<<"================Sorted\n";
        for(int i=0;i<activities;i++){
            cout<<timing[i][0]<<" "<<timing[i][1]<<endl;
        }
        cout<<"================\nActivities for james\n";

        // First Activity to James(1)
        timing[0][3] = 1;
        cout<<"Activity 0 Start: "<<timing[0][0]<<" end: "<<timing[0][1]<<" slot:"<<timing[0][3]<<endl; 
        i=0;
        for (int j = 1; j < activities; j++) { 
            cout<<"\n j: "<<j<<endl;
            if (timing[j][0] >= timing[i][1]) { 
                timing[j][3] = 1;
                cout<<"Activity "<<j<<" Start: "<<timing[j][0]<<" end: "<<timing[j][1]<<" slot:"<<timing[j][3]<<endl;   
                i = j;
                cout<<"i: "<<i<<endl;
            }


                
            cout<<"\n========================\nTiming Table\n";
            cout<<"start \t end \t rank \t assign\n";
            for(int i=0;i<activities;i++){
                cout<<timing[i][0]<<"\t"<<timing[i][1]<<"\t"<<timing[i][2]<<"\t"<<timing[i][3]<<"\n";
            }
        }

        // Finding first remaining activity
        int firstC;
        cout<<"Line 63";
        for(int k=0;k<activities;k++){
            if(timing[k][3] != 1){
                firstC=k;
                break;
            }
        }

        cout<<"================\nActivities for Caroll\n";

        // First Activity to James(1)
        timing[firstC][3] = 2;
        cout<<"Activity "<<firstC<<" Start: "<<timing[firstC][0]<<" end: "<<timing[firstC][1]<<" slot:"<<timing[firstC][3]<<endl; 
        i=0;
        for (int j = 1; j < activities; j++) { 
            if (timing[j][0] >= timing[i][1] && timing[j][3] != 1) { 
                timing[j][3] = 2;
                cout<<"Activity "<<j<<" Start: "<<timing[j][0]<<" end: "<<timing[j][1]<<" slot:"<<timing[j][3]<<endl;   
                i = j;
            }
        }


        // Finding if any remaining activity
        for(int k=0;k<activities;k++){
            //cout<<"\n"<<timing[k][3]<<endl;
            if(timing[k][3] != 1 || timing[k][3] != 2){
                cout<<"IMPOSSIBLE";
                break;
            }
        }

        cout<<"\n========================\nTiming Table\n";
        cout<<"start \t end \t rank \t assign\n";
        for(int i=0;i<activities;i++){
            cout<<timing[i][0]<<"\t"<<timing[i][1]<<"\t"<<timing[i][2]<<"\t"<<timing[i][3]<<"\n";
        }


    }
    return 0;
}