class Solution {
public:
	//compare function
    static bool compare(string s1,string s2){
		string aa = s1.substr(s1.find(' '));
        string bb = s2.substr(s2.find(' '));
        
        return aa == bb ? s1 < s2 : aa < bb;
    }
	
	//main function
    vector<string> reorderLogFiles(vector<string>& logs) {
        
		//result vector
        vector<string> result;
        int count = 0;
        
		//iterate over the logs vector once
        for(auto log : logs){
			if(log.back() <= 'z' and log.back() >= 'a') {
                result.insert(result.begin(),log);
                count++;
            }
            else {
                result.push_back(log);
            }
        }
        
		//sort the first "count" number of elements
        sort(result.begin(),result.begin()+count,compare);
		//return the result
        return result;
    }
};
