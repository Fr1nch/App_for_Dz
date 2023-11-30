#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
typedef vector < vector<edge> > graph;

const int infinity = INT_MAX;

int Levit()
{
    int out,
        numberOfVertices = 8,
        startVertex = 1,
        finishVertex = 8;
    edge a1(2, 4);
    edge a2(4, 1);
    edge b1(1, 4);
    edge b2(3, 1);
    edge b3(5, 8);
    edge c1(2, 1);
    edge d1(1, 1);
    edge d2(5, 10);
    edge d3(6, 3);
    edge e1(2, 8);
    edge e2(4, 10);
    edge e3(7, 3);
    edge e4(8, 2);
    edge f1(4, 3);
    edge f2(7, 3);
    edge g1(5, 3);
    edge g2(6, 3);
    edge h1(5, 2);
    graph g = { {}, {a1, a2}, {b1, b2, b3}, {c1}, {d1, d2, d3}, {e1, e2, e3, e4}, {f1, f2}, {g1, g2}, {h1} };


    vector<int> d(numberOfVertices + 1, infinity);
    d[startVertex] = 0;

    vector<int> state(numberOfVertices + 1, 2);
    state[startVertex] = 1;

    deque<int> q;
    q.push_back(startVertex);

    vector<int> p(numberOfVertices + 1, -1);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop_front();
        state[vertex] = 0;
        for (size_t i = 0; i < g[vertex].size(); ++i)
        {
            int to = g[vertex][i].first,
                length = g[vertex][i].second;
            if (d[to] > d[vertex] + length)
            {
                d[to] = d[vertex] + length;
                if (state[to] == 2)
                    q.push_back(to);
                else if (state[to] == 0)
                    q.push_front(to);
                p[to] = vertex;
                state[to] = 1;
            }
        }
    }
    if (p[finishVertex] == -1)
    {
        out = 1;
    }
    else
    {
        /*vector<int> path;
        for (int vertex = finishVertex; vertex != -1; vertex = p[vertex])
            path.push_back(vertex);
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';*/
            //cout << endl << d[finishVertex];
        out = d[finishVertex];
    }
    return out;
}