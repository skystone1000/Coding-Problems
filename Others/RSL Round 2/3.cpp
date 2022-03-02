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
