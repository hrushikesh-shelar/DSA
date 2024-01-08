/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
    int search(BinaryMatrix &binaryMatrix, int row, int low, int high) {
        int resIdx = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(binaryMatrix.get(row, mid)==1) {
                resIdx = mid;
                high=mid-1;
            } else {
                low = mid+1;
            }
        }
        return resIdx;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int nRows = dimensions[0], nCols = dimensions[1];
        int res = nCols;
        for(int row=0; row<nRows; row++) {
            if(binaryMatrix.get(row, res-1)==1) {
                // cout<<"row:"<<row<<" ";
                res = min(res, search(binaryMatrix, row, 0, res-1));
                // cout<<"res:"<<res<<endl;
                if(res==0) {
                    return res;
                }
            }
        }
        return res==nCols ? -1 : res;
    }
};