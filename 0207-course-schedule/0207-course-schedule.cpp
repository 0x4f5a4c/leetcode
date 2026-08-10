class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        // form one directed graph
        for (auto &pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];

            graph[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        // kahn's algorithm
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            // now process the neighbours
            for (int nbr : graph[curr]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return count == numCourses;
    }
};