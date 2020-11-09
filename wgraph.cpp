
#include "wgraph.h"
//
//Complete
//
wgraph
wgraph_complete( indice n,  weight Mw )
{
    vertex vn = n;
    wgraph WKn( vn );
    for( vertex v = 0; v < vn; v++ )
        for( vertex u = v+1; u<vn; u++ ) {
            weight w = rand()%Mw+1;
            WKn[v].push_back(pair<vertex,weight>(u,w));
            WKn[u].push_back(pair<vertex,weight>(v,w));
        }
    return WKn;
}
//
//Cycle
//
wgraph
wgraph_cycle( indice n, weight Mw )
{
    vertex vn = n;
    wgraph WCn( vn );
    for( vertex v=0; v<vn-1; v++){
        weight w = rand()%Mw+1;
        WCn[v].push_back(pair<vertex,weight>(v+1,w));
        WCn[v+1].push_back(pair<vertex,weight>(v,w));
    }
    weight w = rand()%Mw+1;
    WCn[vn-1].push_back(pair<vertex,weight>(0,w));
    WCn[0].push_back(pair<vertex,weight>(vn-1,w));
    return WCn;
}
//
//Star
//
wgraph
wgraph_star( indice n, weight Mw )
{
    vertex vn = n;
    wgraph WSn( vn );
    for( vertex v=0; v<vn-1; v++){
        weight w = rand()%Mw+1;
        WSn[v].push_back(pair<vertex,weight>(vn-1,w));
        WSn[vn-1].push_back(pair<vertex,weight>(v,w));
    }
    return WSn;
}
//
//Wheel (unió de cycle i star)
//
wgraph
wgraph_wheel( indice n, weight Mw )
{
    vertex vn = n;
    wgraph WWn( vn );
    for( vertex v=0; v<vn-1; v++){
        weight w = rand()%Mw+1;
        WWn[v].push_back(pair<vertex,weight>(v+1,w));
        WWn[v].push_back(pair<vertex,weight>(vn-1,w));
        WWn[v+1].push_back(pair<vertex,weight>(v,w));
        WWn[vn-1].push_back(pair<vertex,weight>(v,w));
    }
    weight w = rand()%Mw+1;
    WWn[vn-1].push_back(pair<vertex,weight>(vn-2,w));
    WWn[vn-2].push_back(pair<vertex,weight>(vn-1,w));
    w = rand()%Mw+1;
    WWn[0].push_back(pair<vertex,weight>(vn-2,w));
    WWn[vn-2].push_back(pair<vertex,weight>(0,w));
    return WWn;
}
//
//Bipartit complet
//
wgraph
wgraph_bipartit( indice n1, indice n2, weight Mw)
{
    vertex vn = n1 + n2;
    wgraph WBn(vn);
    for(vertex v=0; v<n1; v++){
        for(vertex u=n1; u<vn; u++){
            weight w = rand()%Mw+1;
            WBn[v].push_back(pair<vertex,weight>(u,w));
            WBn[u].push_back(pair<vertex,weight>(v,w));
        }
    }
    return WBn;
}
//
//
//
wgraph
wgraph_read( string fname )
{
    ifstream fin;
    fin.open(fname.c_str());
    if (fin.fail()) {
        cerr << "No s'ha pogut obrir " << fname.c_str() << " per la lectura." << endl;
        exit(1);
    }
    vertex vn;
    edge en;
    fin >> vn >> en;
    wgraph G( vn );
    for( edge e=0; e<en; e++ ) {
        vertex u, v;
        weight w;
        fin >> u >> v >> w;
        G[u].push_back(pair<vertex,weight>(v,w));
        if( u != v )
            G[v].push_back(pair<vertex,weight>(u,w));
    }
    return G;
}
//
//
//
void
wgraph_write( wgraph& G, ofstream& fout )
{
    vertex vn = G.size();
    edge en = 0;
    for( vertex v = 0; v < vn; v++)
        en += G[v].size();
    en /= 2;
    fout << "WGraf amb " << vn << " vertexs i " << en << " arestes " << endl;
    fout << "Llista d'adjacència amb pes " << endl;
    for( vertex v = 0; v < vn; v++ ) {
        fout << v << ":";
        for( indice i = 0; i < G[v].size(); i++)
            fout << " " << G[v][i].first << "[" << G[v][i].second << "] ";
        fout << endl;
    }
    fout << endl;
    fout << "Arestes amb pes " << endl;
    for( vertex v = 0; v < vn; v++ )
        for( indice i = 0; i < G[v].size(); i++)
            if( v <= G[v][i].first )
                fout << v << "-" << G[v][i].first <<  "[" << G[v][i].second << "] " << endl;
    
}
