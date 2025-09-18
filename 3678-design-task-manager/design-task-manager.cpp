#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    // Max-heap: {priority, {taskId, userId}}
    priority_queue<pair<int, pair<int, int>>> pq;
    // Latest valid state for each taskId -> {priority, userId}
    unordered_map<int, pair<int,int>> taskMap;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &it : tasks) {
            pq.push({it[2], {it[1], it[0]}});
            taskMap[it[1]] = {it[2], it[0]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, {taskId, userId}});
        taskMap[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        if (taskMap.find(taskId) == taskMap.end()) return; // no such task
        int userId = taskMap[taskId].second;
        pq.push({newPriority, {taskId, userId}});
        taskMap[taskId] = {newPriority, userId};
    }
    
    void rmv(int taskId) {
        if (taskMap.find(taskId) == taskMap.end()) return; // no such task
        taskMap.erase(taskId); // mark removed
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top(); 
            int pri = top.first;
            int tId = top.second.first;
            int uId = top.second.second;

            // Check if top is valid
            if (taskMap.find(tId) != taskMap.end() && 
                taskMap[tId].first == pri && 
                taskMap[tId].second == uId) {
                pq.pop();
                taskMap.erase(tId); // executed -> remove
                return uId;
            }
            // Otherwise stale entry, skip
            pq.pop();
        }
        return -1; // no task left
    }
};
