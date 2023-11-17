class Solution {
public:
    string removeStars(string str) {
        stack<char> stak;
        for(int i=0; i<str.size(); i++) {
            if(str[i]=='*') {
                if(!stak.empty()) {
                    stak.pop();
                }
            } else {
                stak.push(str[i]);
            }
        }
        string res;
        while(!stak.empty()) {
            res.push_back(stak.top());
            stak.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};