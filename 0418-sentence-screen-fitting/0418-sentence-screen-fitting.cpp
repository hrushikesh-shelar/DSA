class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string sen;
        for (auto & word : sentence) {
            sen += word + " ";
        }
        int len = sen.size(), start = 0;
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (sen[start % len] == ' ') {
                start++;
            } else {
                while (start > 0 && sen[(start-1) % len] != ' ') {
                    start--;
                }
            }
        }
        return start / len;
    }
};