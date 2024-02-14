class Solution {
    bool isPalindrome(string word) {
        int n = word.size();
        for(int i=0; i<n/2; i++) {
            if(word[i]!=word[n-1-i]) {
                return false;
            }
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            if(isPalindrome(words[i])) {
                return words[i];
            }
        }
        return "";
    }
};