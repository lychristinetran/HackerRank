#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

/*
    Approach: 
    - a DFS function that returns num of component
    - each DFS returns the size of the connected component
    - compare num of TOTAL components*cost+c_lib with clib*numofcomponents
    - calculate extra components that don't have connected roads * c_lib
    - min cost = min of cost plus extra cost
    
*/

std::unordered_map<int, vector<int>> buildGraph(vector<vector<int>> cities){
    std::unordered_map<int, vector<int>> graph;
    for (auto edge : cities){
        int a = edge[0];
        int b = edge[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
        
    }
    return graph;
}

long DFS (std::unordered_map<int, vector<int>> &graph, int city, std::unordered_set<int> &visited){
    // check if it's visited

    visited.insert(city);
    long size = 1;
    for (auto c : graph[city]){
        if (visited.count(c) == 0)
            size += DFS(graph, c, visited);
    }
    
    return size;
}


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    std::unordered_map<int, vector<int>> graph = buildGraph(cities);
    long long  min_cost = 0;
    long long total_components = 0;
    std::unordered_set<int> visited;
    int cost_lib = c_lib;
    int cost_road = c_road;
    
    
    for (auto path = graph.begin(); path != graph.end(); path++){
        if (visited.count(path->first) == 0){
            int curr_components = DFS(graph, path->first, visited);
            total_components += curr_components;
            min_cost += min((curr_components-1)*cost_road+cost_lib, cost_lib*curr_components);
        }
    }
    
    if (n > total_components)
        min_cost += (n - total_components)*cost_lib;
    
    return min_cost;
}
