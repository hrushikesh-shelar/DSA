class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int p1Score = 0;
        for(int i=0; i<player1.size(); i++) {
            bool isMaxHit = (i-1>=0 && player1[i-1]==10) || (i-2>=0 && player1[i-2]==10);
            p1Score += (isMaxHit ? 2: 1)*player1[i];
            
        }
        int p2Score = 0;
        for(int i=0; i<player2.size(); i++) {
            bool isMaxHit = (i-1>=0 && player2[i-1]==10) || (i-2>=0 && player2[i-2]==10);
            p2Score += (isMaxHit ? 2: 1)*player2[i];
            
        }
        if(p1Score==p2Score) return 0;
        if(p1Score>p2Score) return 1;
        return 2;
    }
};