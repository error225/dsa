
#include <iostream>
#include <cstring>
#include <string>
#define HIGH 99999
using namespace std;

class graph
{
    int g[10][10], n;
    bool v_array[10];
    string dept[10];

public:
    void initialize()
    {
        cout << "\nEnter total departments: ";
        cin >> n;
        cout << "\nEnter department names: ";
        for (int i = 0; i < n; i++)
        {
            cin >> dept[i];
        }
        cout << "\nEnter distance matrix (0 for no direct connection):\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "Distance between " << dept[i] << " and " << dept[j] << ": ";
                cin >> g[i][j];
                if (i != j && g[i][j] == 0)
                {
                    g[i][j] = HIGH; // Set to HIGH if no direct edge
                }
            }
        }
    }

    void display()
    {
        cout << "\nDistance Matrix:\n\t";
        for (int i = 0; i < n; i++)
        {
            cout << dept[i] << "\t";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << dept[i] << "\t";
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == HIGH)
                {
                    cout << "INF\t";
                }
                else
                {
                    cout << g[i][j] << "\t";
                }
            }
            cout << "\n";
        }
    }

    void prims()
    {
        int cost = 0;
        memset(v_array, false, sizeof(v_array));
        v_array[0] = true; 
        cout << "\nEdges in Minimum Spanning Tree:\n";
        int n_edges = 0;

        while (n_edges < n - 1)
        {
            int min = HIGH;
            int r = 0, c = 0;
            for (int i = 0; i < n; i++)
            {
                if (v_array[i])
                { 
                    for (int j = 0; j < n; j++)
                    {
                        if (!v_array[j] && g[i][j] < min)
                        { 
                            min = g[i][j];
                            r = i;
                            c = j;
                        }
                    }
                }
            }
            cout << dept[r] << " - " << dept[c] << ": " << g[r][c] << "\n";
            cost += g[r][c];
            v_array[c] = true;
            n_edges++;
        }
        cout << "\nCost of Minimum Spanning Tree using Prim's Algorithm: " << cost << "\n";
    }
};

int main()
{
    graph g;
    g.initialize();
    g.display();
    g.prims();
    return 0;
}
