#include <bits/stdc++.h>
using namespace std;
#define N 100200

vector<int> gr[N];

// Function to add edge
void Add_edge(int x, int y)
{
	gr[x].push_back(y);
	gr[y].push_back(x);
}

int shortest_cycle(int n)
{
	int ans = INT_MAX;

	for (int i = 0; i < n; i++) //making every node as source node and doing bfs because shortest cycle can be identified if the source node is a part of cycle
    {
		vector<int> dist(n, INT_MAX);
		dist[i] = 0;

		queue<int> q;
		q.push(i);

		while (!q.empty()) 
        {
			int x = q.front();
			q.pop();

			for (int child : gr[x]) 
			{
				if (dist[child] == INT_MAX) 
				{
					dist[child] = 1 + dist[x];
					q.push(child);
				}
				else if (dist[child]>=dist[x])   //if any child is visited and has distance greater than or equal to parent then it is a backedge
					ans = min(ans, dist[x] + dist[child] + 1);
			}
		}
	}

	if (ans == INT_MAX)
		return -1;
	else
		return ans;
}

int main()
{
	int n = 5;

    Add_edge(0, 1);
    Add_edge(0, 2);
    Add_edge(1, 3);
    Add_edge(1, 4);
    Add_edge(3, 4);
    Add_edge(4, 2);

	cout << shortest_cycle(n);
}
