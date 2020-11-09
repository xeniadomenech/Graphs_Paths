#include "graph.h"
//
//Complete
//
graph
graph_complete( indice n )
{
    vertex vn = n;
    graph Kn( vn );
    for( vertex v=0; v<vn; v++)
        for( vertex u=v+1; u<vn; u++ ) {
            Kn[v].push_back( u );
            Kn[u].push_back( v );
        }
    return Kn;
}
//
//Cycle
//
graph
graph_cycle( indice n )
{
    vertex vn = n;
    graph Cn( vn );
    for( vertex v=0; v<vn-1; v++){
        Cn[v].push_back( v+1 );
        Cn[v+1].push_back( v );
    }
    Cn[vn-1].push_back( 0 );
    Cn[0].push_back( vn-1 );
    return Cn;
}
//
//Star
//
graph
graph_star( indice n )
{
    vertex vn = n;
    graph Sn( vn );
    for( vertex v=0; v<vn-1; v++){
        Sn[v].push_back( vn-1 );
        Sn[vn-1].push_back( v );
    }
    return Sn;
}
//
//Wheel (unió de cycle i star)
//
graph
graph_wheel( indice n )
{
    vertex vn = n+1;
    graph Wn( vn );
    for( vertex v=1; v<vn-1; v++){
        Wn[v-1].push_back( v );
        Wn[v].push_back( v-1 );
    }
    Wn[0].push_back( n-1 );
    Wn[n-1].push_back( 0 );
    for( vertex v=0; v<vn-1; v++){
        Wn[vn-1].push_back( v );
        Wn[v].push_back( vn-1 );
    }
    return Wn;
}
//
//Bipartit complet
//
graph
graph_bipartit( indice n1, indice n2 )
{
    vertex vn = n1 + n2;
    graph Bn(vn);
    for(vertex v=0; v<n1; v++){
        for(vertex u=n1; u<vn; u++){
            Bn[v].push_back(u);
            Bn[u].push_back(v);
        }
    }
    return Bn;
}
graph
graph_read( string fname )
{
    ifstream fin;
    fin.open( fname.c_str() );
    if( fin.fail() ) {
        cerr << "No s'ha pogut obrir " << fname.c_str() << " per la llectura." << endl;
        exit( 1 );
    }
    vertex vn;
    edge en;
    fin >> vn >> en;
    graph G( vn );
    for( edge e=0; e<en; e++ ) {
        vertex v, u;
        fin >> v >> u;
        G[v].push_back(u);
        if( u != v )
            G[u].push_back(v);
    }
    return G;
}
//
//  Write from adjacencies lists (graph) to stream
//  - vertices and edges numbers
//  - edges
void
graph_write(  graph& G, ofstream& fout )
{
    //  Vertices number
    vertex vn = G.size();
    //  Count edges number from adjacencies lists
    //  PLEASE CORRECT WHEN THERE ARE LOOPS(CREC QUE JA ESTÀ REVISAT)
    edge en = 0;
    for( vertex v = 0; v < vn; v++ )
        for( indice i = 0; i < G[v].size(); i++ )
            if( v <= G[v][i] )
                en++;
    //  Write edges
    fout << "Graf amb " << vn << " vertex i " << en << " arestes " << endl;
    fout << "Llista d'adjacència " << endl;
    for( vertex v=0; v<vn; v++ )  {
        fout << v << "\t:";
        for( indice i=0; i<G[v].size(); i++)
            fout << "\t" << G[v][i];
        fout << endl;
    }
    fout << "Arestes" << endl;
    for( vertex v = 0; v < vn; v++ )
        for( indice i = 0; i < G[v].size(); i++ )
            if( v <= G[v][i] )
                fout << v << "-" << G[v][i] << endl;
}
//
//CAVALL
//
graph
graph_knight(indice n1, indice n2)
{
    graph Kn(n1*n2);
    for (indice i1 = 0; i1 < n1; i1++) {
        for (indice i2 = 0; i2 < n2; i2++) {
            vertex v = i1*n2 + i2;
            //En aquest if faig el moviment del cavall quan avança 2 horitzontalment
            if(i1 < n1-1){
                //I un verticalment
                if(i2 < n2-2){
                    Kn[v].push_back((i1+1)*n2 + (i2+2));
                    Kn[(i1+1)*n2 + (i2+2)].push_back(v);
                }
                //I avança un verticalment
                if(i2 > 1){
                    Kn[v].push_back((i1+1)*n2 + (i2-2));
                    Kn[(i1+1)*n2 + (i2-2)].push_back(v);
                }
            }
            //En aquest if faig els moviment del cavall quan avança 2 verticalment
            if(i1 < n1-2){
                //I avança un horitzontalment
                if(i2 < n2-1){
                    Kn[v].push_back((i1+2)*n2 + (i2+1));
                    Kn[(i1+2)*n2 + (i2+1)].push_back(v);
                }
                //I retrocedeix un horitzontalment
                if(i2 > 0){
                    Kn[v].push_back((i1+2)*n2 + (i2-1));
                    Kn[(i1+2)*n2 + (i2-1)].push_back(v);
                }
            }
        }
    }
    return Kn;
}
