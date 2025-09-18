class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
    };
    
    struct Compare {
        bool operator()(const Task& a, const Task& b) const {
            if (a.priority == b.priority) 
                return a.taskId < b.taskId; // larger taskId first
            return a.priority < b.priority; // higher priority first
        }
    };
    
    unordered_map<int, pair<int,int>> taskInfo; // taskId -> {userId, priority}
    priority_queue<Task, vector<Task>, Compare> pq;
    
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskInfo[taskId] = {userId, priority};
            pq.push({priority, taskId, userId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = taskInfo[taskId];
        taskInfo[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }
    
    void rmv(int taskId) {
        taskInfo.erase(taskId); // mark as removed
    }
    
    int execTop() {
        while (!pq.empty()) {
            Task top = pq.top();
            pq.pop();
            auto it = taskInfo.find(top.taskId);
            if (it != taskInfo.end() && it->second.second == top.priority) {
                int userId = it->second.first;
                taskInfo.erase(it); // remove executed task
                return userId;
            }
        }
        return -1; // no tasks left
    }
};