class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> ans = new ArrayList();
        Arrays.sort(arr);
        int diff = Integer.MAX_VALUE; 
        for(int i=0; i<arr.length-1; i++) {
            if((arr[i+1]-arr[i])<diff) {
                diff = arr[i+1]-arr[i];
                ans.clear();
                ans.add(Arrays.asList(arr[i], arr[i + 1]));
            } else if((arr[i+1]-arr[i])==diff){
                ans.add(Arrays.asList(arr[i], arr[i + 1]));
            }
        }
        return ans;
    }
}