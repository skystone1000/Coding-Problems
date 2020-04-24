//卐 Ganesha's Pattern

#include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=1;i<n+1;i++){
		if(i<(n+1)/2){
			cout<<"*";
			if(i == 1){
				for(int j=1;j<n;j++){
					if(j>(n/2)-1){
						cout<<"*";
					}else{
						cout<<" ";
					}
				}
				cout<<endl;
			}
			else {
				for(int j=1;j<n;j++){
					if(j==(n/2)){
						cout<<"*";
					}else{
						cout<<" ";
					}
				}
				cout<<endl;
			}

		}else if(i>(n+1)/2){
			if(i == n){
				for(int j=1;j<n;j++){
					if(j<=(n/2)+1){
						cout<<"*";
					}else{
						cout<<" ";
					}
				}
			}
			else {
				for(int j=1;j<n;j++){
					if(j==(n/2)+1){
						cout<<"*";
					}else{
						cout<<" ";
					}
				}
			}
			cout<<"*";
			cout<<endl;
		}else{
			for(int j=0;j<n;j++){
				cout<<"*";
			}
			cout<<endl;
		}

	}

	return 0;
}