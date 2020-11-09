#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned int weight;
typedef unsigned int vertex;
typedef unsigned int indice;
typedef unsigned int edge;
typedef vector<vector<vertex>> graph;
typedef vector<vector<pair<vertex,weight>> > wgraph;
wgraph wgraph_complete( indice n,  weight Mw );
wgraph wgraph_cycle( indice n,  weight Mw );
wgraph wgraph_star( indice n,  weight Mw );
wgraph wgraph_wheel( indice n,  weight Mw );
wgraph wgraph_bipartit( indice n1, indice n2,  weight Mw );
wgraph wgraph_read( string fname );
void wgraph_write(  wgraph& G, ofstream& fout );
weight TravellingSalesmanProblem( wgraph &G, ofstream &fout );
graph convertToUnweightedGraph( wgraph &G);
