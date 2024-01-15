class Leaderboard {
    public:
    unordered_map<int,int> id_to_score;
    map<int, int> points_to_ids;

    Leaderboard() {
    }

    void addScore(int playerId, int score) {
        int prevScore = id_to_score[playerId];
        points_to_ids[prevScore]--;
        if(points_to_ids[prevScore]==0) {
            points_to_ids.erase(prevScore);
        }
        id_to_score[playerId] += score;
        points_to_ids[id_to_score[playerId]]++;
    }

    int top(int K) {
        // cout<<"Size:"<<points_to_ids.size()<<endl;
        // for(auto start = points_to_ids.rbegin(); start != points_to_ids.rend(); start++) {
        //     cout<<"loop1 "<<start->first<<" "<<start->second<<endl;
        // }
        int total_sum = 0;

        for(auto start = points_to_ids.rbegin(); start != points_to_ids.rend(); start++) {
            total_sum += min(start->second, K)*start->first;
            K -= start->second;
        
            if(K <= 0)
                return total_sum;
        
        }
        return total_sum;
    
    }

    void reset(int playerId) {
        int prevScore = id_to_score[playerId];
        points_to_ids[prevScore]--;
        if(points_to_ids[prevScore]==0) {
            points_to_ids.erase(prevScore);
        }
        id_to_score.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */