/*
 *There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 *
 *
 */

class Solution {
public:
    
    //
    // the algorithm is from wiki, sort order DFS.
    // Code is by myself.
    //
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> G(numCourses);
        queue<int> Q; // nodes with 0 incoming edge
        vector<int> inCount(numCourses, 0);
        vector<int> color(numCourses, 0); // 0: not visit, 1: temp visit, 2: visited
        
        // build graph and inCount vector
        for (auto& p : prerequisites)
        {
            // e.g.: [0, 1] : 1-->0
            G[p.second].emplace_back(p.first);
            inCount[p.first]++;
        }
        
        // build the queue that contains the nodes with 0 incoming edge
        for (int i = 0; i < numCourses; i++)
        {
            if (inCount[i] == 0)
            {
                Q.push(i);
            }
        }
        
        // travel
        while (!Q.empty())
        {
            int n = Q.front();
            Q.pop();
            if (!visit(G, Q, inCount, color, n))
            {
                return false;
            }
        }
        
        // check if any node is not visited
        for (auto c : color)
        {
            if (c != 2)
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool visit(vector<list<int>>& G, queue<int>& startNodes, vector<int>& inCount, vector<int>& color, int n)
    {
        if (color[n] == 2) // visited
        {
            return true;
        }
        
        if (color[n] == 1) // temp visited
        {
            return false; // not DAG
        }
        
        color[n] = 1; // temp visit
 
        // visit each node that n points to
        for (auto &m : G[n])
        {
            if (--inCount[m] == 0)
            {
                startNodes.emplace(m);
            }
            
            if (!visit(G, startNodes, inCount, color, m))
            {
                return false;
            }
        }
            
        color[n] = 2; // visited
        return true;
    }
};
