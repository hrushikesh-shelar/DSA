class FileSharing {
    
public:
    FileSharing(int m) : chunks(m+1){}
    
    int join(vector<int> ownedChunks) {
        int id = -1;
        if(unusedIds.empty()){
            id = maxId++;
        }
        else{
            id = *unusedIds.begin();
            unusedIds.erase(unusedIds.begin());
        }
        users[id] = ownedChunks;
        for(auto chunk:ownedChunks)
            chunks[chunk].insert(id);
        return id;
    }
    
    void leave(int userID) {
        unusedIds.insert(userID);
        for(auto chunk:users[userID]) chunks[chunk].erase(userID);
        users[userID].clear();        
    }
    
    vector<int> request(int userID, int chunkID) {
        users[userID].push_back(chunkID);
        auto& ids = chunks[chunkID];
        if(ids.empty()) return {};
        auto res = vector<int>(ids.begin(), ids.end());       
        ids.insert(userID);
        return res;
    }
    
private:
    unordered_map<int, vector<int>> users;
    vector<set<int>> chunks;
    int maxId = 1;
    set<int> unusedIds;
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */