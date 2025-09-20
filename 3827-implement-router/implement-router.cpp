class Router {
    int limit = 0;
    map<vector<int>, bool> seen;
    queue<vector<int>> q; 
    unordered_map<int, deque<int>> dmap;
    
public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> vec = {source, destination, timestamp};
        if(seen.count(vec)){
            return false;
        }

        if(q.size() == limit){
            auto front = q.front(); q.pop();
            seen.erase(front);
            dmap[front[1]].pop_front();
        }
        
        q.push(vec);
        seen[vec] = true;
        dmap[vec[1]].push_back(vec[2]);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }
        auto front = q.front();
        q.pop();
        seen.erase(front);
        dmap[front[1]].pop_front();

        return front;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!dmap.count(destination)){
            return 0;
        }
        
        deque<int>& dTime = dmap[destination];
        auto startPos = lower_bound(dTime.begin(), dTime.end(), startTime); 
        auto endPos = upper_bound(dTime.begin(), dTime.end(), endTime); 

        return int(endPos - startPos);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */