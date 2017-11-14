/*
 *
 * There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
 *
 */

class Solution {
public:
    
    //
    // my own solution
    //
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> G(numCourses);
        vector<int> degrees(numCourses, 0);
        queue<int> startNodes; // nodes with 0 degree / no incoming edge
        vector<int> order; // result, the order of nodes
        
        vector<int> empty;
        
        // build graph. e.g.: pre: [0, 1] -- 0 <--- 1
        for (auto& pre : prerequisites)
        {
            G[pre.second].emplace_back(pre.first);
            degrees[pre.first]++;
        }
        
        // initialize startNodes
        for (int i = 0; i < numCourses; i++)
        {
            if (degrees[i] == 0)
            {
                startNodes.push(i);
            }
        }
        
        // travel from each node without any incoming edge
        while (!startNodes.empty())
        {
            int m = startNodes.front();
            startNodes.pop();
            
            order.emplace_back(m);
            for (int x : G[m])
            {
                if (--degrees[x] == 0)
                {
                    startNodes.push(x);
                }
            }
        }
        
        if (order.size() != numCourses)
        {
            return empty;
        }
        
        return order;
            
    }
};
