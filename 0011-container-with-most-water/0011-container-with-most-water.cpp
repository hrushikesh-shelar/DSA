class Solution {
public:
    int maxArea(vector<int>& height) {
        int result;
        
        int leftPtr=0, rightPtr=height.size()-1;
        result = (rightPtr-leftPtr)*min(height[leftPtr], height[rightPtr]); 
        
        while(leftPtr<rightPtr) {
            result = max(
                result,    
                (rightPtr-leftPtr)*min(height[leftPtr], height[rightPtr])
            ); 
            if(height[leftPtr] < height[rightPtr]) {
                leftPtr++;
            } else if(height[leftPtr] > height[rightPtr]) {
                rightPtr--;
            } else {
                leftPtr++; rightPtr--;
            }
        }
        return result;
    }
};