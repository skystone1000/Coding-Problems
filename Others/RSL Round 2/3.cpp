/*
A-3: ​Write a program to print the frequency of these characters b, f, j, p, v in a given string and 
also print the total count of these characters. (Ignore the character cases, it can be lower or upper case)

The function will take 1 parameter which will be a String (you do not have to write code to get 
the input parameter from the user). You can also choose to take a character array as input parameter, 
instead of string, if you like.

int frequencyOfCharacters(String input) {
    // TODO:
}

Example:
Input: rajasoftwarelabs Output: b=1, f=1, j=1, Total=3
Input: Buffet Output: b=1, f=2, Total=3 
========================================
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int frequencyOfCharacters(string input) {
    map<char, int>cnt;
    int total = 0;
    for(char c:input){
        if(c == 'b' || c == 'f' || c == 'j' || c == 'p' || c == 'v' || 
            c == 'B' || c == 'F' || c == 'J' || c == 'P' || c == 'V' ){
            cnt[c]++;
            total++;
        }
    }

    for(auto el1: cnt){
		cout << el1.first << " " << el1.second <<endl;
	}
    cout<<"Total = "<<total<<endl;
    return total;
}

int main(){
    // string inp = "rajasoftwarelabs";
    string inp = "Buffet";
    frequencyOfCharacters(inp);
    return 0;
}
