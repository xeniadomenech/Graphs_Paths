//
//
//
//
#include "graph.h"
#include "wgraph.h"
#include <math.h>
#include <time.h>
#include <stdlib.h>
//
//
//
int main(void){
    ofstream fout;
    bool sol;
    int HC;
    weight TSP;
    color cn;
    //EXERCICI 18
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Kn.out" );
    graph Kn = graph_complete(6);
    graph_write( Kn, fout );
    sol=HamiltonianCycle(Kn, fout);
    fout << "**********************" <<endl;
    HC=HamiltonianCycles(Kn, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Kn, fout);
    fout << cn <<endl;
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Knn.out" );
    graph Knn = graph_bipartit(3,3);
    graph_write( Knn, fout );
    sol=HamiltonianCycle(Knn, fout);
    fout << "**********************" <<endl;
    HC=HamiltonianCycles(Knn, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Knn, fout);
    fout << cn <<endl;
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Cn.out" );
    graph Cn = graph_cycle(6);
    graph_write( Cn, fout );
    sol=HamiltonianCycle(Cn, fout);
    fout << "**********************" <<endl;
    HC=HamiltonianCycles(Cn, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Cn, fout);
    fout << cn <<endl;
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Sn.out" );
    graph Sn = graph_star(6);
    graph_write( Sn, fout );
    sol=HamiltonianCycle(Sn, fout);
    fout << "**********************" <<endl;
    HC=HamiltonianCycles(Sn, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Sn, fout);
    fout << cn <<endl;
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Wn.out" );
    graph Wn = graph_wheel(6);
    graph_write( Wn, fout );
    sol=HamiltonianCycle(Wn, fout);
    fout << "**********************" <<endl;
    HC=HamiltonianCycles(Wn, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Wn, fout);
    fout << cn <<endl;
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Ktn1_n2.out" );
    graph Ktn1_n2 = graph_knight(5, 5);
    graph_write( Ktn1_n2, fout );
    sol=HamiltonianCycle(Ktn1_n2, fout);
    fout << "**********************" <<endl;
    HC=HamiltonianCycles(Ktn1_n2, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Ktn1_n2, fout);
    fout << cn <<endl;
    fout.close();
    //
    //EXERCICI 19
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/WKn.out" );
    wgraph WKn = wgraph_complete(6, 50);
    wgraph_write( WKn, fout );
    TSP=TravellingSalesmanProblem(WKn, fout);
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/WKnn.out" );
    wgraph WKnn = wgraph_bipartit(3, 3, 50);
    wgraph_write( WKnn, fout );
    TSP=TravellingSalesmanProblem(WKnn, fout);
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/WCn.out" );
    wgraph WCn = wgraph_cycle(6, 50);
    wgraph_write( WCn, fout );
    TSP=TravellingSalesmanProblem(WCn, fout);
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/WSn.out" );
    wgraph WSn = wgraph_star(6, 50);
    wgraph_write( WSn, fout );
    TSP=TravellingSalesmanProblem(WSn, fout);
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/WWn.out" );
    wgraph WWn = wgraph_wheel(6, 50);
    wgraph_write( WWn, fout );
    TSP=TravellingSalesmanProblem(WWn, fout);
    fout.close();
    //
    //EXERCICI 20
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/cities1.out" );
    wgraph C1 = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Entrades/cities1.in");
    wgraph_write(C1, fout);
    TSP=TravellingSalesmanProblem(C1, fout);
    fout.close();
    //
    //EXERCICI 21
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Dodecaedre.out" );
    wgraph D = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Entrades/Dodecaedre.in");
    wgraph_write(D, fout);
    TSP=TravellingSalesmanProblem(D, fout);
    //EXERCICI 22
    graph DD=convertToUnweightedGraph(D);
    cn=MinimalVertexColoring(DD, fout);
    fout << cn <<endl;
    fout.close();
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Icosaedre.out" );
    wgraph I = wgraph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Entrades/Icosaedre.in");
    wgraph_write(I, fout);
    TSP=TravellingSalesmanProblem(I, fout);
    //EXERCICI 22
    graph II=convertToUnweightedGraph(I);
    cn=MinimalVertexColoring(II, fout);
    fout << cn <<endl;
    fout.close();
    //
    //EXERCICI 23
    //
    fout.open("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Sortides/Comarques.out" );
    graph Comarques = graph_read("/Users/xeniadomenech/Documents/UNIVERSITAT/Segon/Graphs/GPrc4_DomenechXenia.cpp/Entrades/Comarques.in");
    graph_write(Comarques, fout);
    //EXERCICI 22
    cn=MinimalVertexColoring(Comarques, fout);
    fout << cn <<endl;
    fout.close();
    //
    //  Ending
    //
    cout << "Press enter to finish..." << endl;
    cin.get();
}
