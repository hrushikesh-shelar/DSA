class Solution {
    
    
    // 1-> (<2 live neighbor) -> convert to 0   // convert to -1 in first itr
    // 1-> (2/3 live neighbor)  -> stays as 1   
    // 1-> (>3 live neighbor ) -> convert to 0  // convert to -1 in first itr
    // 0 -> 3 live neighbor -> convert to 1      // convert to 2 in first itr
    
    private:
    vector<vector<int>> DIR = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1,1}, {1, -1}, {-1, 1}, {-1, -1}};

    bool isValid(int x, int y, int X, int Y) {
        if(x<0 || x>=X || y<0 || y>=Y) {
            return false;
        }
        return true;
    }
    int getLiveNeighbors(vector<vector<int>>& board, int x, int y) {
        int neighbors=0;
        for(auto dir: DIR) {
            if(isValid(x+dir[0], y+dir[1], board.size(), board[0].size())) {
                if(board[x+dir[0]][y+dir[1]]==1 || board[x+dir[0]][y+dir[1]]==-1 ) {
                    neighbors++;
                }
            }
        }
        return neighbors;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                int neighbors = getLiveNeighbors(board, i, j);
                // cout<<"i:"<<i<<" j:"<<j<<endl;
                // cout<<"initial:"<<board[i][j]<<endl;
                // cout<<"neighbors:"<<neighbors<<endl;
                if(board[i][j]==0 && neighbors==3) {
                    board[i][j]=2;   
                }
                if(board[i][j]==1) {
                    if(neighbors<2 || neighbors>3) {
                        board[i][j]=-1;
                    }   
                }
                // cout<<"final:"<<board[i][j]<<endl;
            }
        }
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==2) {
                    board[i][j]=1;   
                }
                if(board[i][j]==-1) {
                    board[i][j]=0;   
                }
            }
        }
    }
};