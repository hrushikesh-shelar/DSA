class Solution {

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> maxHeap;
        for(int row=0; row<matrix.size(); row++) {
            for(int col=0; col<matrix[0].size(); col++) {
                if(maxHeap.size() < k)
                    maxHeap.push(matrix[row][col]);
                else {
                    if(matrix[row][col]<maxHeap.top()) {
                        maxHeap.pop();
                        maxHeap.push(matrix[row][col]);
                    }
                }
            }
        }
        return maxHeap.top();
    }
};