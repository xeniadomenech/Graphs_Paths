//
//
//
//    VERTEX COLORING
//  - by Brelaz method
//  - by backtracking method

#include "graph.h"
#include "wgraph.h"
// include typedef unsigned int color;

//
//  Vertex-coloring of one vertex
//

color
Vertex1Coloring( graph& G, vector<color>& Gc, color cn, vertex v, color oc  )
{
    vertex n = G.size();
    // avc (adjacent vertex colors, used colors) : vector of booleans
    vector<bool> avc( cn+1, false );
    for( indice i=0; i<G[v].size(); i++ )
        if(G[v][i]<v) //Tots els vertex menors tenen color assignat
            avc[Gc[G[v][i]]]=true;

        //  First color from oc not in previous adjacent vertex
    indice k=0;
    color c;
    for( c=oc; c<=cn; c++ )
        if(avc[c]==false){
            Gc[v]=c;
            k=1;
        }
    if (k==0){
        Gc[v]=cn+1;
        cn++;
    }
    return cn;
}

color
BrelazColoring( graph& G, vector<color>& Gc )
{
    color cn; //numero de colors que usem
    vertex n = G.size();
    //  Color vertex 0 with color 1
    Gc[0] = cn = 1;
    //  Brelaz coloring: color other vertices with colors from 1
    for( vertex v=1; v<n; v++ )
        cn = Vertex1Coloring( G, Gc, cn, v, 1 );
    return cn;
}

//
//  Vertex Coloring of Graph
//

color
MinimalVertexColoring( graph& G, ofstream& fout )
{
    vertex vn = G.size();
    //  Prepare initial Brelaz coloring
    vector<color> Gc(vn, 0);
    vector<color> Gpc(vn,0);
    color cn = BrelazColoring( G, Gpc );
    
    do {
        //  Provisionally accept and write current coloring, saved in Gc
        //  Save it as proving coloring Gpc
        //  Try successive reduction of color number cn
        fout  << "Coloration with " << cn << " colors\n";
        cout  << "Coloration with " << cn << " colors\n";
        for( vertex v=0; v<vn; v++ ) {
            Gc[v] = Gpc[v];
            fout << "Vertex " << v << "   ->   Color " << Gc[v] << endl;
        }
        
        //************ For every color, print here all
        //************ the vertices with that color. Example:
        //************ Color 1: v0, v3, v5, v6.
        //************ Color 2: v1, v2, v4, v8. etc.
        for(color c=1; c<=cn; c++){
            fout << "Color " << c << ": ";
            for(vertex v=0; v<vn; v++){
                if(c==Gc[v])
                    fout << v << " ";
            }
            fout <<endl;
        }
        //************ Check that the coloration Gc is correct.
        //************ That is, if there are two vertices which are neighbors
        //************     and have the same color, print "Coloring error:" and
        //************    specify the two neighbor vertices.
        for(vertex v=0; v<vn; v++)
            for(vertex i=0; i<G[v].size(); i++)
                if(Gc[v]==Gc[G[v][i]])
                    fout << "Error de coloració." <<endl << "El vertex " << v << " i el " << G[v][i] << " tenen el mateix color."<<endl;
        
        
        //  Search first vertex cnv with current maximum color cn
        vertex cnv;
        for( cnv=0; cnv<vn; cnv++ )
            if( Gpc[cnv] == cn )
                break;
        while( cnv<vn ){
            //  Try possible reduction of cn to cn-1
            //  Backtrack vertex from cnv:
            //  - find cnv to be colored with first color bigger than its color
            do {
                //  Take previous bcnv if possible
                cnv--;
                if ( cnv == 0 ) {
                    //  When backtracking reaches original vertex all possibilities exhausted:
                    //  last coloring Gc was ok
                    fout  << "\nMinimal vertex coloring found\n";
                    return cn;
                }
                Vertex1Coloring( G, Gpc, cn, cnv, Gpc[cnv]+1 );
            } while( Gpc[cnv]>=cn );
            //  Try to color posterior vertices to bcnv without color cn
            //  until a vertex cnv cannot be colored with cn-1 colors
            //  new vertex to backtrack
            for( ++cnv; cnv<vn; cnv++ ) {
                Vertex1Coloring( G, Gpc, cn, cnv, 1 );
                if ( Gpc[cnv]>= cn ) {
                    break;
                }
            }
        }
        cn--;
    } while( true );
}
