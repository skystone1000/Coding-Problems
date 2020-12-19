// Company Amazon
// 17 #0929. Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(string email:emails){
            string address = "";
            for(int i=0;i<email.size();i++){
                char c = email[i];
                if(c == '@'){
                    int rem = email.size() - i;
                    address += email.substr(i,rem);
                    break;
                }else if(c == '+'){
                    while(email[i] != '@'){
                        i++;
                    }
                    int rem = email.size() - i;
                    address += email.substr(i,rem);
                    break;
                } else if(c == '.'){
                    continue;
                } else {
                    address += c;
                }
            }
            
            ans.insert(address);
        }
        for(auto ele:ans){
            cout<<ele<<endl;
        }
        
        return ans.size();
    }
};