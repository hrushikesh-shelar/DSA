class Logger {
    unordered_map<string, int> messageLastTime;
    int timeDifference;
public:
    Logger() {
        this->timeDifference = 10;
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        bool isMessageAlreadyPrinted = messageLastTime.count(message)>0;
        if(isMessageAlreadyPrinted and messageLastTime[message]>(timestamp-this->timeDifference)) {
                return false;
        }
        messageLastTime[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */