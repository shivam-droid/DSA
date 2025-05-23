class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adjList(numCourses);
            for(auto it:prerequisites)
            {
                adjList[it[1]].push_back(it[0]); // directed edge from it[1] to it[0]
            }
            vector<int> indegree(numCourses);
            for(int i=0;i<numCourses;i++)
            {
                for(auto it:adjList[i])
                {
                    indegree[it]++;
                }
            }
            queue<int> q;
            for(int i=0;i<numCourses;i++)
            {
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
            vector<int> topo;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                topo.push_back(node);
                for(auto it:adjList[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)q.push(it);
                }
            }
            if(topo.size()==numCourses)return topo;
            return {};
        }
    };