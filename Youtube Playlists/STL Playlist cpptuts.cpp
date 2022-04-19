// STL Playlist cpptuts




/*

==========================================================
03 Vector in Cpp

NOTES:
	1. std::vector is a sequence container and also known as Dynamic Array or Array List.
	2. Its size can grow and shrink dynamically, and no nedd to provide size at compile time

ELEMENT ACCESS
	obj.at()  - Useful for bound checking
	obj[]
	obj.front()
	obj.back()
	obj.data

MODIFIERS
	insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

*/

#include <iostream>
#include <vector>

using namespace std;

int VectorDemo(){
	
	// Declarations
	std::vector<int> arr1;
	std::vector<int> arr2 (5, 20); // vector of size 50 and fill 20 in all places
	std::vector<int> arr3 = {1, 2, 3, 4, 5}; // initializer list
	std::vector<int> arr4 {1, 2, 3, 4, 5}; // uniform initialization
	
	// Accessing Elements
	arr2[3] = 10;
	arr2.at(3) = 10; 

}


/*

==========================================================
09 MultiMap
SYNTAX: 
	multi/imap<T1, T2> obj; // where T1 is key and T2 is value type. 

Notes:
1. Multimap is an associative container that contains a sorted list of key-value
	pairs, while permitting multiple entries with the same key.
2. It store key value pair in sorted order on the basis of key (ascending/descending).
	syntax:
		std::multimap<char, int, std::greater<> > Multimap;
3. Data Structure used in multimap is not defined by standard, but red-black tree is 
	assumed by most of the people.
4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
5. We dont have at() and [] functions to get the element like we had in std::map

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int MultimapDemo(){
	std::multimap<char, int> Multimap;
	Multimap.insert(make_pair('a', 1));
	Multimap.insert(pair<char, int> ('a',1));
	Multimap.insert(make_pair('a', 2));
	Multimap.insert(make_pair('a', 3));
	Multimap.insert(make_pair('a', 4));
	Multimap.insert(make_pair('a', 5));
	Multimap.insert(make_pair('b', 1));

	// count
	cout << Multimap.count('a');

	// find
	auto pair = Multimap.find('a');
	cout << pair->first << " " << pair->second << endl;

	// lower_bound
	auto range = Multimap.lower_bound('a');
	cout << range->first << " " << range->second << endl;  
	// output - a,1


	// upper_bound
	auto range = Multimap.upper_bound('a');
	cout << range->first << " " << range->second << endl;  
	// output - b,1


	// Iterate over multimap
	for(auto &elm:Multimap){
		cout << elm.first << " " << elm.second <<endl;
	}

	// Get all the pairs of given key
	auto range = Multimap.equal_range('a');
	for(auto it = range.first; it!=range.second; it++){
		cout << it->first << " " << it->second << endl;
	}

	return 0;

}



/*

==========================================================
14 std::deque in C++

Topic : std::deque in C++ ( Double Ended Queue )

Notes
0. std::deque is an indexed sequence container.
1. It allows fast insertion at both beginning and end.
2. Unlike vector elements of deque are not stored contigious.
3. It uses individual allocated fixed size array, with additional book keeping , 
meaning index based access to deque must perform two pointer derefrence, 
but in vector we get in one derefrence.
4. The storage of deque is automatically expanded and contracted as needed.
5. Expansion of deque is cheaper than expansion of vector.
6. A deque holding just one element has to allocated its full internal array 
(e.g 
8 times the object size on 64-bit libstdc++; 
16 times the object size or 4096 bytes, whichever is larger on 64-bit libc++
)

TIME COMPLEXITY:
Random Access - constant O(1)
Insertion or Removal of elements at the end or beginning - constant O(1)
Insertion or Removal of elements - linear O(n)

*/

#include<iostream>
#include<deque>
using namespace std;

void print(const deque<int> &dqu){
	for(int num:dqu){
		cout<<num<<" ";
	}
	cout<<endl;
}

int DequeDemo(){
	
	deque<int> dqu = {2,3,4};
	dqu.push_front(1);
	dqu.push_back(5);
	print(dqu);

	deque<int> dqu = {2,3,4};
	dqu.pop_front();
	dqu.pop_back();
	print(dqu);

	return 0;
}

/*
	OUTPUT:
	1 2 3 4 5
	3
*/



/*

==========================================================
15 std::queue in C++ STL


TOPIC: std::queue in C++

Notes:
0. std::queue class is a container adapter that gives the programmer the functionality of a queue
1. queue is a FIFO (First In, First Out) data structure.
2. std::queue provides only specific set of functions.
3. std::queue allows to push(insert) at back and pop(remove) from front.
4. std::queue gives front, back, push, pop, empty, size.

*/

#include<iostream>
#include<queue>

using namespace std;

void print(queue<int> que){
	while(!que.empty()){
		cout<<que.front()<<" ";
		que.pop();
	}
	cout<<endl;
}

int QueueDemo(){

	queue<int> que;
	que.push(2);
	que.push(3);
	que.push(4);

	print(que);

	return 0;
}


/*

==========================================================
17 std::priority queue

// TOPIC: std::priority_queue in C++ (Priority Queue)

// What is it ??
MIN HEAP - MAX HEAP
Keep (TOP k) or (BOTTOM K) elements 

0. std::priority_queue is a container adaptor that provides constant
	time loopup of the largest OR smallest element.
1. By default std::vector is the container used inside.
2. Cost of insertion and extraction is logarithmic.
3. std::priority_queue is implemented using std::make_heap, std::push_heap,
	std::pop_heap functions.

*/

// Program
#include <functional>
#include <queue>
#include <vector>
#include <iostream>

template<typename T> void print_queue(T& q){
	while(!q.empty()){
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout<<endl;
}

int PriorityQueueDemo(){
	// ============================================
	// MAX HEAP
	std::priority_queue<int> q;
	for(int elm: {1,8,5,6,3,4,0,9,7,2}){
		q.push(elm);
	}
	print_queue(q);
	// OUTPUT: 9,8,7,6,5,4,3,2,1,0


	
	// ============================================
	// MIN Heap
	std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
	for(int elm : {1,8,5,6,3,4,0,9,7,2}){
		q2.push(elm);
	}
	print_queue(q2);
	// OUTPUT: 0,1,2,3,4,5,6,7,8,9


	// Using Lambda to compare elements.
	auto cmp = [](int left, int right){
		return (left) < (right);
	};
	std::priority_queue<int, std::vector<int>, decltype(cmp) > q3(cmp);
	for(int elm : {1,8,5,6,3,4,0,9,7,2}){
		q3.push(elm);
	}
	print_queue(q3);
	// OUTPUT: 9,8,7,6,5,4,3,2,1,0
}








/*

==========================================================
18 Unordered Set

Notes std::unordered_set
0. Unordered set is a associative container that contains set of unique objects.
1. Search, insertion and removal have average constant-time complexity.
2. Internally, the elemants are organized into buckets.
3. It uses hashing to insert elements into bucket.
4. This allows fast access to individual elements, since once a hash is computed,
   it refers to the exact bucket the element is placed into.

Why UNORDERED SET ?
Maintains a collection of unique items with fast insertion and removal.

*/

#include<iostream>
#include<unordered_set>

using namespace std;

int UnorderedSetDemo(){
	std::unordered_set<int> uset = {4, 1, 2, 3, 4, 2, 3};
	auto search = uset.find(2);
	if(search != uset.end()){
		std::cout<<"Found "<<(*search)<<"\n";
	} else{
		std::cout<<"Not Found\n";
	}

	for(auto& elm:uset){
		std::cout<<elm<<" ";
	}
	cout<<endl;
	return 0;
} 



/*
==========================================================
08 Map

Notes:
1. Syntax: 
	map<T1,T2> obj;
where T1 is key type and T2 is value type.

2. std:map is associative container that store elements
in key value combination where key should be unique, 
otherwise it overrides the previous value.

3. It is implemented using Self-Balance Binary search Tree
(AVL/Red Black Tree).

4. It store key value pair in sorted order on the basis
of key (Ascending / Descending).

5. std::map is generally used in Dictonary type problems

Example : Dictionary.

*/

#include <iostream>
#include <map>
#include <functional>
#include <vector>

using namespace std;

int MapDemo(){
	std::map <string,int > Map;
	Map["Chotu"] = 90939208;
	Map["Amit"] = 82396497;

	Map.insert(std::make_pair("Bot",28736872));

	// Traversing the Map
	for(auto el1: Map){
		cout << el1.first << " " << el1.second <<endl;
	}

	// Access using [] Operator
	cout<< Map["Chotu"] << endl;
	return 0;

}