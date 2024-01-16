class UndergroundSystem {
    public:
    unordered_map<int, pair<string,int>> checkedIn ;
    unordered_map<string, pair<double,int>> stationTime;

    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkedIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto checkIn = checkedIn[id];
        checkedIn.erase(id);
        string routeName = checkIn.first + "_" + stationName;
        stationTime[routeName].first += t - checkIn.second;
        stationTime[routeName].second +=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = stationTime[routeName];
        return route.first/route.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */