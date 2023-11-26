class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> currMeetingsEndTimes;
        currMeetingsEndTimes.push(intervals[0][1]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=currMeetingsEndTimes.top()) {
                currMeetingsEndTimes.pop();
            }
            currMeetingsEndTimes.push(intervals[i][1]);
        }
        return currMeetingsEndTimes.size();
    }
};