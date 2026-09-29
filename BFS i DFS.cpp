#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int u;
    int v;
};

void bfsAdjMatrix(vector<vector<bool>>& adjMatrix, int v, int n)
{
    vector<bool> visited(n,false);
    queue<int> q;

    visited[v]=true;
    q.push(v);

    cout<<"BFS (Adj Matrix): ";
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";
        for (int y=0;y<n;y++)
        {
            if(adjMatrix[x][y]==1 && !visited[y])
            {
                visited[y]=true;
                q.push(y);
            }
        }
    }
    cout<<"\n";
}

void dfsAdjMatrix1(vector<vector<bool>>& adjMatrix,int x,int n,vector<bool>& visited)
{
    visited[x]=true;
    cout<<x<<" ";
    for (int y=0;y<n;y++)
    {
        if (adjMatrix[x][y]==1 && !visited[y])
        {
            dfsAdjMatrix1(adjMatrix,y,n,visited);
        }
    }
}

void dfsAdjMatrix(vector<vector<bool>>& adjMatrix,int v,int n)
{
    vector<bool> visited(n,false);
    cout<<"DFS (Adj Matrix): ";
    dfsAdjMatrix1(adjMatrix,v,n,visited);
    cout<<"\n";
}

void bfsAdjList(vector<vector<int>>& adjList, int v, int n)
{
    vector<bool> visited(n,false);
    queue<int> q;

    visited[v] = true;
    q.push(v);

    cout<<"BFS (Adj List):   ";
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<< " ";
        for(int y:adjList[x])
        {
            if(!visited[y])
            {
                visited[y]=true;
                q.push(y);
            }
        }
    }
    cout<<"\n";
}

void dfsAdjList1(vector<vector<int>>& adjList,int x,vector<bool>& visited)
{
    visited[x]=true;
    cout<<x<<" ";

    for(int y:adjList[x])
    {
        if(!visited[y])
        {
            dfsAdjList1(adjList,y,visited);
        }
    }
}

void dfsAdjList(vector<vector<int>>& adjList, int v, int n)
{
    vector<bool> visited(n,false);
    cout<<"DFS (Adj List):   ";
    dfsAdjList1(adjList,v,visited);
    cout<<"\n";
}

void bfsEdgeList(vector<Edge>& edgeList,int v,int n)
{
    vector<bool> visited(n,false);
    queue<int> q;

    visited[v]=true;
    q.push(v);

    cout<<"BFS (Edge List):  ";
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<" ";

        for(auto &edge:edgeList)
        {
            int y=-1;
            if(edge.u==x)y=edge.v;
            else if(edge.v==x)y=edge.u;

            if(y!=-1 && !visited[y])
            {
                visited[y]=true;
                q.push(y);
            }
        }
    }
    cout<<"\n";
}

void dfsEdgeList1(vector<Edge>& edgeList,int x,vector<bool>& visited)
{
    visited[x]=true;
    cout<<x<<" ";

    for(auto &edge:edgeList)
    {
        int y=-1;
        if(edge.u==x)y=edge.v;
        else if(edge.v==x)y=edge.u;

        if(y!=-1 && !visited[y])
        {
            dfsEdgeList1(edgeList,y,visited);
        }
    }
}

void dfsEdgeList(vector<Edge>& edgeList,int v,int n)
{
    vector<bool> visited(n,false);
    cout<<"DFS (Edge List):  ";
    dfsEdgeList1(edgeList,v, visited);
    cout<<"\n";
}

int main()
{
    int n = 5;
    int v = 0;

    /*
       Graph Structure (Undirected):
           0 --- 1
           | \   |
           |  \  |
           2 --- 3
           |
           4
    */

    // 1. Adjacency Matrix
    vector<vector<bool>> adjMatrix = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // 2. Adjacency List
    vector<vector<int>> adjList = {
        {1, 2, 3}, // ys of 0
        {0, 3},    // ys of 1
        {0, 3, 4}, // ys of 2
        {0, 1, 2}, // ys of 3
        {2}        // ys of 4
    };

    // 3. Edge List
    vector<Edge> edgeList = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 3}, {2, 3}, {2, 4}
    };

    cout<<"BFS"<<endl;
    bfsAdjMatrix(adjMatrix,v,n);
    bfsAdjList(adjList,v,n);
    bfsEdgeList(edgeList,v,n);

    cout<<"DFS"<<endl;
    dfsAdjMatrix(adjMatrix,v,n);
    dfsAdjList(adjList,v,n);
    dfsEdgeList(edgeList,v,n);

    return 0;
}