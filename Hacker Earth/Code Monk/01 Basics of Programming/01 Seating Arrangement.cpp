// 01 Seating Arrangements

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        int seat;
        cin>>seat;
        int rem = seat % 12;
        
        switch(rem){
            case 1:
                cout<<seat+11<<" WS\n";
                break; 
            case 2:
                cout<<seat+9<<" MS\n"; 
                break;
            case 3:
                cout<<seat+7<<" AS\n"; 
                break;
            case 4:
                cout<<seat+5<<" AS\n"; 
                break;
            case 5:
                cout<<seat+3<<" MS\n"; 
                break;
            case 6:
                cout<<seat+1<<" WS\n";
                break;
            case 7:
                cout<<seat-1<<" WS\n";
                break; 
            case 8:
                cout<<seat-3<<" MS\n"; 
                break;
            case 9:
                cout<<seat-5<<" AS\n"; 
                break;
            case 10:
                cout<<seat-7<<" AS\n"; 
                break;
            case 11:
                cout<<seat-9<<" MS\n"; 
                break;
            case 0:
                cout<<seat-11<<" WS\n";
                break;
            default:
                break;
        }
    }
    return 0;
}