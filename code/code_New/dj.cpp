#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define INFINITY 99999

using namespace std;

class Graph
{
    int q[20][20], w[20][20], n;
    string city[20];

public:
    void initialize()
    {
        cout << "\nEnter number of cities: ";
        cin >> n;
        cout << "\nEnter names of cities: ";
        for (int i = 0; i < n; i++)
        {
            cin >> city[i];
        }
        cout << "\nEnter weighted matrix:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "\nEnter distance between " << city[i] << " to " << city[j] << ": ";
                cin >> w[i][j];
                if (w[i][j] == 0 && i != j)
                {
                    w[i][j] = INFINITY;
                }
            }
        }
    }

    void displayWeightedMatrix()
    {
        cout << "\nWeighted Matrix:\n   ";
        for (int i = 0; i < n; i++)
        {
            cout << city[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << city[i] << " ";
            for (int j = 0; j < n; j++)
            {
                if (w[i][j] == INFINITY)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << w[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }

    int index(const string &str)
    {
        for (int i = 0; i < n; i++)
        {
            if (str == city[i])
            {
                return i;
            }
        }
        return -1; 
    }

    void dijkstra()
    {
        string source, dest;
        int choice, si, di;

        // Initialize shortest path matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                q[i][j] = w[i][j];
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    q[i][j] = min(q[i][j], q[i][k] + q[k][j]);
                }
            }
        }

        cout << "\nShortest Path Matrix:\n   ";
        for (int i = 0; i < n; i++)
        {
            cout << city[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << city[i] << " ";
            for (int j = 0; j < n; j++)
            {
                if (q[i][j] == INFINITY)
                {
                    cout << "INF ";
                }
                else
                {
                    cout << q[i][j] << " ";
                }
            }
            cout << "\n";
        }

        do
        {
            cout << "\n1. One source to one destination path.";
            cout << "\n2. One source to all destinations.";
            cout << "\n3. Exit.";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nEnter source and destination: ";
                cin >> source >> dest;
                si = index(source);
                di = index(dest);
                if (si == -1 || di == -1)
                {
                    cout << "\nInvalid cities entered.\n";
                    break;
                }
                cout << "\nShortest distance from " << city[si] << " to " << city[di] << " is: "
                     << (q[si][di] == INFINITY ? "INF" : to_string(q[si][di])) << "\n";
                break;

            case 2:
                cout << "\nEnter source: ";
                cin >> source;
                si = index(source);
                if (si == -1)
                {
                    cout << "\nInvalid city entered.\n";
                    break;
                }
                for (int j = 0; j < n; j++)
                {
                    cout << "\nShortest distance from " << city[si] << " to " << city[j] << " is: "
                         << (q[si][j] == INFINITY ? "INF" : to_string(q[si][j]));
                }
                cout << "\n";
                break;

            case 3:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }
};

int main()
{
    Graph g;
    g.initialize();
    g.displayWeightedMatrix();
    g.dijkstra();
    return 0;
}
