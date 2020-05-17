// Harbour Space University
// Educational Codeforces Round 87 (Rated for Div. 2)
// B Ternary String 

#include<bits/stdc++.h> 
using namespace std; 

const int no_of_chars = 256; 
string findSubString(string str, string pat) { 
	int len1 = str.length(); 
	int len2 = pat.length(); 
	if (len1 < len2) { 
		//cout << "No such window exists"; 
		return ""; 
	} 

	int hash_pat[no_of_chars] = {0}; 
	int hash_str[no_of_chars] = {0}; 

	// store occurrence ofs characters of pattern 
	for (int i = 0; i < len2; i++) 
		hash_pat[pat[i]]++; 

	int start = 0, start_index = -1, min_len = INT_MAX; 

	// start traversing the string 
	int count = 0; // count of characters 
	for (int j = 0; j < len1 ; j++) { 
		// count occurrence of characters of string 
		hash_str[str[j]]++; 

		// If string's char matches with pattern's char 
		// then increment count 
		if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]] ) 
			count++; 

		// if all the characters are matched 
		if (count == len2) { 
			// Try to minimize the window i.e., check if 
			// any character is occurring more no. of times 
			// than its occurrence in pattern, if yes 
			// then remove it from starting and also remove 
			// the useless characters. 
			while ( hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) { 
				if (hash_str[str[start]] > hash_pat[str[start]]) 
					hash_str[str[start]]--; 
				start++; 
			} 

			// update window size 
			int len_window = j - start + 1; 
			if (min_len > len_window) { 
				min_len = len_window; 
				start_index = start; 
			} 
		} 
	} 

	// If no window found 
	if (start_index == -1) { 
	//cout << "No such window exists"; 
	return ""; 
	} 

	// Return substring starting from start_index 
	// and length min_len 
	return str.substr(start_index, min_len); 
} 

// Driver code 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCases;
    cin>>testCases;
    for(int t=0;t<testCases;t++){
        string str;
        cin>>str;
        string pat = "123"; 
        string ans = findSubString(str, pat);
        //long long int lengthS = ans.size();
        cout<< ans.size() <<endl; 
    }
	return 0; 
} 
