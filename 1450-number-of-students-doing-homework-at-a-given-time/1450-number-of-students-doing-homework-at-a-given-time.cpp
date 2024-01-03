class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res=0;
        for(int i=0; i<startTime.size(); i++) {
            if(queryTime<=endTime[i] && queryTime>=startTime[i]) {
                res++;
            }
        }
        return res;
    }
};