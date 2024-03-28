//
// Created by karthik on 12/3/24.
//
#include "RubikCube.h"
#include "DFSsolver.h"

#include <bits/stdc++.h>

#ifndef RUBIKCUBESOLVER_IDDFSSOLVER_H
#define RUBIKCUBESOLVER_IDDFSSOLVER_H

template<typename T,typename H>
class IDDFSsolver{
public:
    T r;
    int max_moves;

    IDDFSsolver(T R,int moves){
        cout<<"Strting...\n";
        r = R;
        max_moves = min(21,moves);
    }
    vector<RubikCube::MOVE> solve(){
        for(int i=1;i<=max_moves;i++){
            DFSsolver<T,H> dfsSolver(r,i);
            vector<RubikCube::MOVE> moves;
            moves = dfsSolver.solve();
            if(!moves.empty()){
                return moves;
            }
        }
        return {};
    }
};


#endif //RUBIKCUBESOLVER_IDDFSSOLVER_H
