// Company Amazon
// 52 #0735. Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i=0;
        while(i<asteroids.size()){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            } else {
                while( !st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                } else if(st.top() == abs(asteroids[i])){
                    st.pop();
                }
            }
            i++;
        }
        
        vector<int> remaining(st.size());
        for(int i=st.size()-1; i>=0 ; i--){
            remaining[i] = st.top();
            st.pop();
        }
        return remaining;
    }
};