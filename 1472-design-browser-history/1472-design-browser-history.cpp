class BrowserHistory {
    stack<string> history;
    stack<string> future;
    string current;
public:
    BrowserHistory(string homepage) {
            current = homepage; 
    }
    
    void visit(string url) {
        history.push(current);
        current = url;
        future = stack<string>();
    }
    
    string back(int steps) {
        while(steps && history.size()>0) {
            future.push(current);
            current = history.top();
            history.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while(steps && future.size()>0) {
            history.push(current);
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */