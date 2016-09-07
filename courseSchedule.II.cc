/** ###
 * 这个题是graph的topological sort
 * bfs和dfs都可以完成，bfs直接使用I中的程序修改即可
 * 这里只给出dfs的解法，dfs主要是需要再添加一个result来record排序结果
 * result中保证后面的先进入，所以最后需要reverse
 */

//dfs
class Solution {
public:
    bool dfs(int t,map<int,vector<int>> &graph,vector<int> &visited,vector<int> &result) {
        if(visited[t] == 2) {
            return false;
        }
        visited[t]=2;
        for(auto &i : graph[t]) {
            if(visited[i]!=1 && !dfs(i,graph,visited,result)) {
                return false;
            }
        }
        if(visited[t] != 1) {
            visited[t]=1;
            result.push_back(t);
        }
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> graph;
        vector<int> visited(numCourses,0);
        vector<int> indgrees(numCourses,0);
        for(auto &p : prerequisites) {
            graph[p.second].push_back(p.first);
            indgrees[p.first]++;
        }
        
        vector<int> result;
        for(int i=0;i<numCourses;i++) {
            if(!indgrees[i] && visited[i]!=1 && !dfs(i,graph,visited,result))
                return vector<int>();
        }
        //notice:a cycle may all not be visited!
        for (int i=0;i<numCourses;i++){
            if (!visited[i]) 
                return vector<int>();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
