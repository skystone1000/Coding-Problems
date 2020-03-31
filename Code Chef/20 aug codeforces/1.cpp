
//BowWow and the Timetable
#include <iostream> 
using namespace std; 

int main() 
{ 

	long int num;// = 10101001; 
	cin>>num;
	long int dec_value = 0; 

	int base = 1; 

	long int temp = num; 
	while (temp) { 
		int last_digit = temp % 10; 
		temp = temp / 10; 
		dec_value += last_digit * base; 
		base = base * 2; 
	} 
	cout << dec_value << endl;
	
	int train=1;
	int count=0;
	while (train<dec_value){
		count++;
		train = train * 4;
	}
	cout<<count;
	return 0; 
} 
