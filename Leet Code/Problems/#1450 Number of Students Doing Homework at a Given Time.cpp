// Number of Students Doing Homework at a Given Time

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int busy=0;
        for(int i=0;i<startTime.size();i++){
            if(queryTime>=startTime[i] && queryTime<=endTime[i]){
                busy++;
            }
        }
        return busy;
    }
};