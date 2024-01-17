class FileSystem {
    unordered_map<string, int> pathValue;
    
    string getParentPath(string path) {
        int i;
        for(i = path.size()-1; i>=0; i--) {
            if(path[i]=='/') {
                break;
            }
        }
        return path.substr(0, i);
    }
public:
    FileSystem() {}
    
    bool createPath(string path, int value) {
        if(path.size()==0 || path=="/" || pathValue.find(path)!=pathValue.end()) {
            return false;
        }
        string parent = getParentPath(path);
        if(parent.size()==0 || pathValue.find(parent)!=pathValue.end()) {
            pathValue[path] = value;
            return true;
        }
        return false;
    }
    
    int get(string path) {
        if(pathValue.find(path)!=pathValue.end()) {
            return pathValue[path];
        }
        return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */