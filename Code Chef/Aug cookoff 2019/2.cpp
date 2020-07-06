#include<iostream>

using namespace std;

int main(){
	int testCases;
	cin>>testCases;
	for (int t=0;t<testCases;t++){
		int n,m,k,l,r;
		cin>>n>>m>>k>>l>>r;
		int temp[n];
		int price[n];
		for(int i=0;i<n;i++){
			cin>>temp[n]>>price[n];
		}
		int finalTemp[n];
		for (int i=0;i<n;i++){
			int diff;
			if (temp[i]<k){
				diff=k-temp[i];
				if(diff>m){
					finalTemp[i]=temp[i]+m;
				}
				else{
					finalTemp[i]=k;
				}
			}
			else if(temp[i]>k){
				diff=temp[i]-k;
				if(diff>m){
					finalTemp[i]=temp[i]-m;
				}
				else{
					finalTemp[i]=k;
				}
			}
			else {
				finalTemp[i]=k;
			}
		}
		int possible[n];
		possible[0]=-1;
		int j=0;
		for(int i=0;i<n;i++){
			if(finalTemp[i]>=l && finalTemp[i]<=r){
				cout<<"final temp of "<<i<<" = "<<finalTemp[i];
				finalTemp[i]=1;
				possible[j]=price[i];
				j++;
			}
			else{
				finalTemp[i]=0;
			}
		}
		if (j>0){
			int smallest=1000000;
			for(int i=0;i<j;i++){
				if(smallest<possible[i])
					smallest=possible[i];
			}
			cout<<smallest;
		}
		else{
			cout<<possible[0];
		}


	}
	return 0;
}