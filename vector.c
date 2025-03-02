#include <stdio.h>
#include <limits.h>

#define V 5  
#define E 8  


void BellmanFord(int graph[E][3], int src) {
    int dis[V],i,j,u,v,weight;

    
    for (i = 0; i < V; i++)
	dis[i] = INT_MAX;


    dis[src] = 0;

   
    for (i = 0; i < V - 1; i++) {
	for (j = 0; j < E; j++) {
	    int u = graph[j][0];
	    int v = graph[j][1];
	    int weight = graph[j][2];
	    if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
		dis[v] = dis[u] + weight;
	}
    }

    
    for ( i = 0; i < E; i++) {
	 u = graph[i][0];
	 v = graph[i][1];
	 weight = graph[i][2];
	if (dis[u] != INT_MAX && dis[u] + weight < dis[v]) {
	    printf("Graph contains negative weight cycle\n");
	    return;
	}
    }


    printf("Vertex Distance from Source\n");
    for (i = 0; i < V; i++)
	printf("%d\t\t%d\n", i, dis[i]);
}


int main() {
    /* Every edge has three values (u, v, w) where
       the edge is from vertex u to v with weight w */
    int graph[E][3] = {
	{ 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 },
	{ 1, 3, 2 }, { 1, 4, 2 }, { 3, 2, 5 },
	{ 3, 1, 1 }, { 4, 3, -3 }
    };

    BellmanFord(graph, 0); /* Run the algorithm from source vertex 0 */

    return 0;
}
