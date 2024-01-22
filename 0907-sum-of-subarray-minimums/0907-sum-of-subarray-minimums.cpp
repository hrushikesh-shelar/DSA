class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         int MOD = 1000000007;

        stack<int> stack;
        long sumOfMinimums = 0;

        // building monotonically increasing stack
        for (int i = 0; i <= arr.size(); i++) {

            // when i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining
            // elements in the stack should now be popped out.

            while (!stack.empty() && (i == arr.size() || arr[stack.top()] >= arr[i])) {

                // Notice the sign ">=", This ensures that no contribution
                // is counted twice. rightBoundary takes equal or smaller 
                // elements into account while leftBoundary takes only the
                // strictly smaller elements into account

                int mid = stack.top();
                stack.pop();
                int leftBoundary = stack.empty() ? -1 : stack.top();
                int rightBoundary = i;

                // count of subarrays where mid is the minimum element
                long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;

                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            stack.push(i);
        }

        return (int) (sumOfMinimums);
    }
};