// Warriors

#include<iostream>

using namespace std;

//sort en[]
void swap(long int* a,long  int* b)  
{  
    long int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
long int partition (long int arr[],long int low,long int high)  
{  
    long int pivot = arr[high]; // pivot  
    long int i = (low - 1); // Index of smaller element  
  
    for (long int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] <= pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
 
void quickSort(long int arr[],long int low, long int high)  
{  
    if (low < high)  
    {  
        long int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
} 


int main(){
	int testCases;
	cin>>testCases;
	for (int t=0;t<testCases;t++){
		long int n,q;
		cin>>n>>q;
		long int en[n],que[q];
		
		for (int i=0;i<n;i++){
			cin>>en[i];
		}

		for (int i=0;i<q;i++){
			cin>>que[i];
		}

		/* check
		cout<<n<<endl;
		cout<<q<<endl;
		for(int i=0;i<n;i++){
			cout<<en[i]<<" ";
		}
		for(int i=0;i<q;i++){
			cout<<que[i]<<endl;
		}
		*/

		//sort enemy array
		quickSort(en,0,n-1);

		/* check for sorted
		for(int i=0;i<n;i++){
			cout<<en[i]<<" ";
		}
	 	*/

	 	for (int i=0;i<q;i++){
	 		int count =0;
	 		int j=0;
	 		while(que[i]>0){
	 			if (que[i]>en[j]){
	 				que[i] = 2*(que[i]-en[j]);
	 				count++;
	 				j++;
	 			}
	 			else{
	 				break;
	 			}
	 		}
	 		cout<<count<<endl;
	 	}
	}
	return 0;
}
