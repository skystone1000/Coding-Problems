#include<iostream>

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int testCases;
	cin>>testCases;
	for(int t=0;t<testCases;t++){
		int in1,in2;
		cin>>in1>>in2;
		int initsum = in1+in2;
		int a1,a2;
		int b1,b2;
		if(in1 < 9){
			a1 = 0;
			a2 = in1;
		} else {
			a2 = in1 % 10;
			in1 = in1 / 10;
			a1 = in1 % 10;
		}

		if(in2 < 9){
			b1 = 0;
			b2 = in2;
		} else {
			b2 = in2 % 10;
			in2 = in2 / 10;
			b1 = in2 % 10;
		}

		//cout<<a1 <<"\t"<<a2<<endl;
		//cout<<b1 <<"\t"<<b2;

		int ans[3];
		ans[0] = -1000;
		ans[1] = -1000;
		ans[2] = -1000;
		ans[0] = initsum;

		if(a1 == 0 && b1 == 0){

		} else if (a1 == 0){
			ans[2] = a1*10 + b1 + a2*10 + b2;
		} else if (b1 == 0){
			ans[1] = b2*10 + a2 + b1*10 + a1;
		} else {
			ans[1] = b2*10 + a2 + b1*10 + a1;
			ans[2] = a1*10 + b1 + a2*10 + b2;
		}
		int large = -1000;
		for(int i=0;i<3;i++){
			if (ans[i] > large){
				large = ans[i];
			}
		}

		cout<<large;


	}
	return 0;
}