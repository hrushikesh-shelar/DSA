class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stack.top() != -1 and heights[stack.top()] >= heights[i]) {
                int current_height = heights[stack.top()];
                stack.pop();
                int current_width = i - stack.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stack.push(i);
        }
        while (stack.top() != -1) {
            int current_height = heights[stack.top()];
            stack.pop();
            int current_width = heights.size() - stack.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }
};