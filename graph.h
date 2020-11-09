#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 using namespace std;
 typedef unsigned int vertex;
 typedef unsigned int indice;
 typedef unsigned int edge;
 typedef vector<vector<vertex> > graph;
 typedef unsigned int color;
 graph graph_read( string fname );
 void graph_write(  graph& G, ofstream& fout );
 graph graph_complete( indice n );
 graph graph_cycle( indice n );
 graph graph_star( indice n );
 graph graph_wheel( indice n );
 graph graph_bipartit( indice n1, indice n2 );
 graph graph_knight(indice n1, indice n2);
 bool HamiltonianCycle( graph &G, ofstream& fout );
 indice HamiltonianCycles( graph &G, ofstream& fout );
 color Vertex1Coloring( graph& G, vector<color>& Gc, color cn, vertex v, color oc  );
 color BrelazColoring( graph& G, vector<color>& Gc );
 color MinimalVertexColoring( graph& G, ofstream& fout );
