#include<bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<int>graph[], vector<int>cost[], int n_node, int s_node) {
    vector<int>distance;
    distance.push_back(0);

    for(int i = 1; i <= n_node; i++)
        distance.push_back(9999);

    queue<int>q;
    q.push(s_node);
    distance[s_node] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int cost_u_v = cost[u][i];

            if(distance[u] + cost_u_v < distance[v]) {
                distance[v] = distance[u] + cost_u_v;
                q.push(v);
            }
        }
    }

    return distance;
}

int main()
{
    int n_node, n_edge;

    n_node = 6;
    n_edge = 9;

    ifstream input;
    vector<int>graph[n_node + 1], cost[n_node + 1];
    queue<int>q;

    input.open("edge.txt", ios::in);

    for(int i = 1; i <= n_edge; i++) {
        int u, v, c;

        input >> u >> v >> c;

        graph[u].push_back(v);
        cost[u].push_back(c);
    }

    vector<int>distance = shortest_path(graph, cost, n_node, 1);

    for(int i = 1; i <= n_node; i++)
        cout << distance[i] << endl;

    return 0;
}
