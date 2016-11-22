/** ###
 * 这个题是一个directed graph的top sort问题
 * 可以使用bfs和dfs两种方法来完成
 * graph的表示方法使用adjacent list
 * bfs还需要indgree信息
 * dfs还需要visited信息
 */

//bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> graph; //adjacent list
        vector<int> indgrees(numCourses,0);
        for(auto &p : prerequisites) {
            graph[p.second].push_back(p.first);
            indgrees[p.first]++;
        }
        
        int count=0; //record how many nodes pushed into Q
        queue<int> Q;
        //initial: indgree=0 nodes pushed into Q
        for(int i=0;i<numCourses;i++) {
            if(!indgrees[i]) {
                Q.push(i);
                count++;
            }
        }
        while(!Q.empty()) {
            int t=Q.front(); Q.pop();
            for(auto &i : graph[t]) {
                indgrees[i]--;
                if(!indgrees[i]) {
                    Q.push(i);
                    count++;
                }
            }
        }
        
        return count == numCourses;
    }
};

//dfs
class Solution {
public:
    bool dfs(int t,map<int,vector<int>> &graph,vector<int> &visited) {
        //cycle detected
        if(visited[t]==2)
            return false;
        visited[t]=2; //path record 
        for(auto &i : graph[t]) {
            //here 0 and 2 all show unvisited
            if(visited[i]!=1 && !dfs(i,graph,visited))
                return false;
        }
        visited[t]=1; //visited
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int,vector<int>> graph;
        vector<int> visited(numCourses,0); //0:unvisited 1:visited 2:in current path
        for(auto &p : prerequisites) {
            graph[p.second].push_back(p.first);
        }
        for(int i=0;i<numCourses;i++) {
            if(visited[i]!=1 && !dfs(i,graph,visited))
                return false;
        }
        return true;
    }
};
