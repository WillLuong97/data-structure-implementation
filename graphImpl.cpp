/* A C++ program to implement graph structure in code
    To implement, we will create two list to store the vertices and edges of the graph

    if |V| = n;
    then 0 <= |E| <= n(n - 1), if directed
         0 <= |E| <= (n(n-1))/2, if undirected            |V|: number of vertices, |E|: number of edges. 

    Cost of Operation: 
        Time complexity: 
        Space complexity: O(V) ; v: number of vertices 
                          O(E) ; e: number of edges
        It is cheaper to store pointer to the actual data rather making a copy of that data and store it elsewhere.
        How much time will you need to find all node adjacent to a given node? 
            + Scan the whole edge list and see if the start and end nodes are the given node or not
            => O(E): number of edges. 
        
        How much time will you take to find if two given nodes are connected? 
            + Perform a linear search on the edge list, and on the worst case, we will have to look at
            all element in the tree to find if two nodes are connected. 
        
*/ 

#include<iostream>
using namespace std; 


// Edge constructor: 
struct Edge
{
    //edge properties
    int *startVertex; //start and end vertices are stored as memories address rather than the data values.
    int *endVertex; 
    int weight; //in case for weighted graph
}

//string and vertex list: 
string vertex_list[MAX_SIZE]; 
Edge edge_list[MAX_SIZE];