#include "graph.h"
#include "wgraph.h"
//
//
//Ens dona un únic cicle Hamiltonià
bool
HamiltonianCycle( graph &G, ofstream& fout )
{
    vertex vn = G.size();
    vector<vertex> HCv( vn );
    vector<bool> HCl( vn, false );
    vector<indice> ind( vn, 0 );
    indice HCi = 0;
    vertex v = 0;
    //  Initialize cycle from vertex 0
    HCv[HCi++] = v;
    HCl[v] = true;
    do {
        //  Forward
        while( ind[v] < G[v].size() ) {
            if( !HCl[G[v][ind[v]]] ) {//if es FALSE
                //  Continue cycle with edge to new vertex, renamed v
                v = G[v][ind[v]++];
                HCv[HCi++] = v;
                HCl[v] = true;
            }
            else ind[v]++;
        }
        if( HCi==vn ) { //Vol dir que hem completat HCv
            //  Full vertices vector
            for( indice i=0; i<G[v].size(); i++ ) {
                if(G[v][i]==0){
                    fout << "El primer camí Hamiltonians trobat és:" <<endl;
                // check if Hamiltonian cycle completed with edge to 0,
                // Per comprovar si es Hamiltonian hem de veure que l'ultim vertex esta connectat al primer.
                // In that case print the Hamiltonian cycle
                // that is iterate over HCv
                    for(indice i=0; i<vn; i++)
                        fout << HCv[i] << "-";
                    fout << "0" <<endl;
                    return true;
                }
            }
        }
        //  Backward
        HCi--;
        if( HCi==0 )
            //  Hamiltonian cycle not found
            return false;
        HCl[v] = false;
        ind[v]= 0;
        v = HCv[HCi-1];
    } while( true );
}
//
//  Robert and Flores method for hamiltonian cycles
//  Ens dona tots el Hamiltonian cycles que hi ha
indice
HamiltonianCycles( graph &G, ofstream& fout )
{
    vertex vn = G.size();
    vector<vertex> HCv( vn );
    vector<bool> HCl( vn, false );
    vector<indice> ind( vn, 0 );
    vertex v = 0;
    indice HCi = 0, HCn = 0;
    HCv[HCi++] = v;
    HCl[v] = true;
    fout<< "Camins Hamiltonians: " <<endl;
    do{
        //  Forward
        while( ind[v] < G[v].size() ){
            if( HCl[G[v][ind[v]]]== false){
                v = G[v][ind[v]++];
                HCv[HCi++] = v;
                HCl[v] = true;
            }
            else ind[v]++;
        }
        if( HCi==vn ) {
            for( indice i=0; i<G[v].size(); i++ ){
                // Fill in this space
                // Make sure you update HCn every time you find a cycle
                if(G[v][i]==0){
                        fout << "(";
                        for(indice j=0; j<vn; j++)
                            fout << HCv[j] << ", ";
                        fout << "0)" <<endl;
                HCn++;
                }
            }
        }
        //  Backward
        HCi--;
        if(HCi==0){
            fout << "Hi ha " << HCn << " cicles Hamiltonians." << endl;
            return HCn;
        }
        HCl[v] = false;
        ind[v] = 0;
        v = HCv[HCi-1];
    } while( true );
        return HCn;
}

weight
TravellingSalesmanProblem( wgraph &G, ofstream &fout)
    {
        vertex vn = G.size();
        indice HCi = 0, HCn = 0;
        vector<vertex> HCv( vn );
        vector<bool> HCl( vn, false );
        vector<indice> ind( vn, 0 );
        //  Index of minimal Hamiltonian cycle found
        indice mHCn;
        //  Minimal Hamiltonian cycle weight (minimum)
        weight mHCw = UINT_MAX;
        //  Minimal Hamiltonian cycle vertices
        vector<vertex> mHCv( vn );
        //  Current hamiltonian cycle weight
        weight HCw = 0;
        //  Initialize vertices vector with vertex 0
        vertex v = 0;
        HCv[HCi++] = v;
        HCl[v] = true;
        do{
            //  Forward BRANCH
            while( ind[v] < G[v].size() ){
                if( !HCl[G[v][ind[v]].first] ){
                    //  Continue cycle with edge to new vertex
                    HCw += G[v][ind[v]].second;
                    
                    if( HCw > mHCw ) {
                        //  BOUND
                        HCw -= G[v][ind[v]].second;
                        break;
                    }
                    v = G[v][ind[v]++].first;
                    HCv[HCi++] = v;
                    HCl[v] = true;
                }
                else ind[v]++;
            }
            if( HCi==vn ) {
                //  Full
                for( indice i=0;i<G[v].size(); i++ ){
                    if( G[v][i].first==0 ){
                        HCw += G[v][i].second;
                        //  Cycle completed with edge to 0
                        HCn++;
                        fout << "Hamiltonian cycle " << HCn << " with weight [" << HCw << "]: ";
                        for( indice HCj=0; HCj<vn; HCj++ )
                            fout << HCv[HCj] << "-" ;
                        fout << "0" << endl;
                        //  Test minimum weight
                        if(mHCw > HCw){
                            mHCw=HCw;
                            // mHCw es el minimum weight
                            for(indice i=0; i<vn; i++)
                                mHCv[i]=HCv[i];
                        }
                        // Keep the minimum Hamiltonian cycle (if the current is not the minimum update)
                        
                        HCw -= G[v][i].second;
                        break;
                    }
                }
            }
            //  Backward
            HCi--;
            if( HCi==0 ){
                
                
                // Complete this part
                // If a hamiltonian cycle exist print it (and print the minimum) and return its total weight
                // If not return 0.
                graph GP=convertToUnweightedGraph(G);
        
                if(HamiltonianCycle(GP, fout)==true){
                    fout << "El minimum Hamiltonian cycle és: [";
                    for(indice i=0; i<vn; i++)
                        fout << mHCv[i] << ", ";
                    fout << "0]"<<endl;
                    return mHCw;
                }
                else{
                    fout << "No hi ha cicles Hamiltonians." <<endl;
                    return 0;
                }
    
            }
            HCl[v] = false;
            ind[v] = 0;
            v = HCv[HCi-1]; //Si no podem continuar el H cycle a partir de l'ultima aresta, en aquesta variable estem borrant el pes de la ultima aresta que hem sumat i que hem vist que no serveix per trobar el H cycle.
            HCw -= G[v][ind[v]-1].second;
        } while( true );
}

graph convertToUnweightedGraph(wgraph &G)
{
    vertex vn = G.size();
    graph GP (vn);
    for(indice v=0; v<vn; v++)
        for(indice i=0; i<G[v].size(); i++)
            GP[v].push_back( G[v][i].first );
    return GP;
    
}
