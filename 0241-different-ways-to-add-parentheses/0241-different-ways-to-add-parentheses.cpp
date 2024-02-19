class Solution {
    int operate(int x, int y, char oper){
        if(oper=='+') return x+y;
        if(oper=='-') return x-y;
        if(oper=='*') return x*y;
        return 0;
    }
    public: 
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isNum=true;
        for(int i=0;i<expression.size();i++){
            if(!isdigit(expression[i])){
                isNum=false;
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1, expression.size()));
                for(int x: left){
                    for(int y: right){
                        ans.push_back(operate(x,y,expression[i]));
                    }
                }
            }
        }
        if(isNum) ans.push_back(stoi(expression));
        return ans;  
    }
};