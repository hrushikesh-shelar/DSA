class Solution {
    public void setZeroes(int[][] matrix) {
        int rows = matrix.length, cols = matrix[0].length;
        boolean rows0 = false, cols0 = false;
        if(matrix[0][0] == 0) {
            rows0 = true; cols0 = true;
        } else {
            for(int i = 1; i<rows; i++) {
                if(matrix[i][0]==0) {
                    cols0 = true;
                    break;
                }
            }
            for(int i = 1; i<cols; i++) {
                if(matrix[0][i]==0) {
                    rows0 = true;
                    break;
                }
            }    
        }
        
        for(int i = 1; i<rows; i++) {
            for(int j=1; j<cols; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<rows; i++) {
            if(matrix[i][0] == 0) {
                for(int j=1; j<cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int j = 1; j<cols; j++) {
            if(matrix[0][j] == 0) {
                for(int i=1; i<rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(rows0) {
            for(int i=0; i<cols; i++) {
                    matrix[0][i] = 0;
                }
        }
        
        if(cols0) {
            for(int i=0; i<rows; i++) {
                    matrix[i][0] = 0;
                }
        }
        
        
    }
}