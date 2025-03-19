#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;

vector<int> SSSP(int v, vector<vector<int>> &cost, int n, vector<int> &dist)
{
    vector<bool> flag(n, false);
    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[v][i];
        flag[i] = false;
    }
    dist[v]=0;
    flag[v] = true;

    for (int j = 1; j < n; j++)
    {
        int u = -1;
    int min_dist = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!flag[i] && dist[i] < min_dist)
            {
                min_dist = dist[i];
                u = i;
            }
        }

        if(u == -1) break;  // there is no more node from this node that are reachable 
        flag[u] = true;

        for (int w = 0; w<n; w++)
        {
            if (!flag[w] && cost[u][w] != INT_MAX)
            {
                if (dist[w] > dist[u] + cost[u][w])
                {
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }
    }
    return dist ;
}
    int main()
    {
        int n;
        cout << "the number of the vertices " << endl;
        cin >> n;

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    int c = rand() % 25 + 1;
                    cost[i][j] = (c > 10) ? INT_MAX : c;
                }
                else
                {
                    cost[i][j] = 0; 
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < n; j++)
            {
                if (cost[i][j] == INT_MAX)
                    cout << "INF  ";
                else
                    cout << cost[i][j] << "   ";
            }
            cout << endl;
        }

        int v;
        cout << "the starting edge for the calculation  :" << endl;
        cin >> v;
    

        vector<int> dist(n);

      vector<int> x=   SSSP(v, cost, n, dist);

      for(int i=0 ;i<n;i++){
        cout<< i+1<<" : " << x[i] <<"  ";
      }

        return 0;
    }
