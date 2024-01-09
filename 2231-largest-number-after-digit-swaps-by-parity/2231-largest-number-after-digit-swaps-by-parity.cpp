class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> oddDigits, evenDigits;
        string numString = to_string(num);
        for(int i=0; i<numString.size(); i++) {
            int digit = numString[i]-'0';
            if(digit%2) {
                oddDigits.push(digit);
            } else {
                evenDigits.push(digit);
            }
        }
        for(int i=0; i<numString.size(); i++) {
            int digit = numString[i]-'0';
            if(digit%2) {
                numString[i] = '0'+oddDigits.top();
                oddDigits.pop();
            } else {
                numString[i] = '0'+evenDigits.top();
                evenDigits.pop();
            }
        }
        return stoi(numString);
    }
};