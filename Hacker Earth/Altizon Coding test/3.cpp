#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking Input
    string temp;
    cout<<"Enter date in YYYYMMDD format: ";
    cin>>temp;

    int year = stoi(temp.substr(0,4));
    int month = stoi(temp.substr(4,2));
    int day = stoi(temp.substr(6,2));
    // cout<<year<<" "<<month<<" "<<day<<endl;

    map<int, string> Months{
        { 1 , "January" },
        { 2 , "February" },
        { 3 , "March" },
        { 4 , "April" },
        { 5 , "May" },
        { 6 , "June" },
        { 7 , "July" },
        { 8 , "August" },
        { 9 , "September" },
        { 10 , "October" },
        { 11 , "November" },
        { 12 , "December" }
    };

    map<int, int> DaysInMonth{
        { 1 , 31 },
        { 2 , 28 },
        { 3 , 31},
        { 4 , 30 },
        { 5 , 31 },
        { 6 , 30 },
        { 7 , 31 },
        { 8 , 31},
        { 9 , 30 },
        { 10 , 31 },
        { 11 , 30 },
        { 12 , 31 }
    };

    // Validation
    int invalid = 0;
    if(month > 12)
        invalid = 1;

    int leap = 0;
    if(month == 2){
        // Leap CHeck
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                    leap = 1;
                else 
                    leap = 0;
            } else
                leap = 1;
        } else {
            leap = 0;
        }

        if(leap == 1){
            if(day > 29)
                invalid = 1;
        } else {
            if(day > 28)
                invalid = 1;
        }

    }else{
        if(day > DaysInMonth[month])
            invalid = 1;
    }

    // Output new format
    if( invalid == 1)
        cout<<"Invalid Date"<<endl;
    else{
        string ans = "";
        ans += Months[month] + " " + to_string(day) + ", " + to_string(year);
        cout<<ans<<endl;
    }

    return 0;
}