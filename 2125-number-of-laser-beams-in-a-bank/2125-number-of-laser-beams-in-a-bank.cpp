class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0;
        int prevDevices = 0;
        int currDevices = 0;
        for(int row=0; row<bank.size(); row++) {
            currDevices=0;
            for(int col=0; col<bank[row].size(); col++) {
                if(bank[row][col]=='1') {
                    currDevices++;
                }
            }
            if(currDevices!=0) {
                res += prevDevices*currDevices;
                prevDevices = currDevices;   
            }
        }
        return res;
    }
};