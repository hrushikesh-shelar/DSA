class AuthenticationManager {
    int tokenLifeTime;
    map<string, int> tokenExpiry;
public:
    AuthenticationManager(int timeToLive) {
        tokenLifeTime = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokenExpiry[tokenId]=currentTime+tokenLifeTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokenExpiry.find(tokenId)!=tokenExpiry.end() && tokenExpiry[tokenId]>currentTime)
            tokenExpiry[tokenId]=currentTime+tokenLifeTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res=0;
        for(auto it=tokenExpiry.begin(); it!=tokenExpiry.end(); it++) {
            if(it->second>currentTime) {
                res++;
            }
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */