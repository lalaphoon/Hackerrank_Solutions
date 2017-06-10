#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
using namespace std;
set<int>::const_iterator pos;
class Graph {
    vector<set<int>> alist;
    list<int> queue;
    public:
        Graph(int n) {
            alist.resize(n);
        }
    
        void add_edge(int u, int v) {
            alist[u].insert(v);
            alist[v].insert(u);
        }
    
        vector<int> shortest_reach(int start) {
            bool visited[alist.size() ] = {false};
           // int distance[alist.size() +1] = {0};
            vector<int> distance(alist.size() );
            for (int i = 0; i < alist.size(); i++){
                distance[i] = 0;
            }
            queue.push_back(start);
            visited[start] = true;
            while(!queue.empty()){
                int node = queue.front();
                for (pos = alist[node].begin(); pos!= alist[node].end(); ++pos){
                    if (!visited[*pos]){
                        queue.push_back(*pos);
                        distance[*pos]+=(distance[node]+6);
                        visited[*pos] = true;
                    }
                }
                queue.pop_front();
            }
            return distance;
            
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                if(distances[i] == 0){
                    cout << "-1 ";
                } else {
                cout << distances[i] << " ";
            }
            }
        }
        cout << endl;
    }
    
    return 0;
}

