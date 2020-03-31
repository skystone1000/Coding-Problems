#include<iostream>
#include <iomanip> 
using namespace std;

int main(){
	long int testCases,n;
	cin>>testCases;
	for(int t=0;t<testCases;t++){
		cin>>n;
		switch (n) 
	    { 
	        case 0: 
	        	cout<<"0.000000"<<endl; 
	            break; 
	        case 1: 
	        	cout<<setprecision(6)<<3.0/7.0<<endl; 
	            break; 
	       	case 2: 
	       		cout<<setprecision(6)<<4.0/7.0<<endl; 
	            break;
	        case 3: 
	       		cout<<setprecision(6)<<5.0/7.0<<endl; 
	            break;
	        case 4: 
	       		cout<<setprecision(6)<<6.0/7.0<<endl; 
	            break;     
	       	default: 
	       		cout<<"1.000000"<<endl;
	            break;   
	    } 
	}
	return 0;
}