#include<iostream>
#include<vector>
using namespace std;

string repFunc() {
    string a = "i.like.this.program.very.much";
    // cin>>a;
    string word = "";
    string finalStr = "";
	int wordCount = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != '.'){
            word += a[i];
        }else{
			if(wordCount % 2 == 0){
				finalStr += word + ".";
				word = "";	
			}else{
				finalStr += "abc.";
				word = "";	
			}
			wordCount++;
        }
    }

	if(word != ""){
		if(wordCount % 2 == 0){
			finalStr += word;
			word = "";	
		}else{
			finalStr += "abc";
			word = "";	
		}
	}
    return finalStr;
}


int main(){

    // string a = "i.like.this.program.very.much";
    
    string finalStr = repFunc();
    cout<<finalStr<<endl;

    return 0;
}
