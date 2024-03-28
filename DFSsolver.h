
//
// Created by karthik on 12/3/24.
//

#include<bits/stdc++.h>
#include "RubikCube.h"


#ifndef RUBIKCUBESOLVER_DFSSOLVER_H
#define RUBIKCUBESOLVER_DFSSOLVER_H

template<typename T,typename H>
class DFSsolver{
public:
    T r;
    int max_depth;
    vector<RubikCube::MOVE> moves;

    DFSsolver(T r1,int max_moves){
        r=r1;
        max_depth=min(max_moves,21);
    }
    bool dfs(int d,T p){
        if(d>max_depth) return false;
        if(r.isSolved()) return true;
        T cur = r;
//        cur.print();
        for(int i=0;i<18;i++){
            r.trigger_move(RubikCube::MOVE(i));
            if(r==p){
                r.invert_move(RubikCube::MOVE(i));
                continue;
            }
            moves.push_back(RubikCube::MOVE(i));
            bool o = dfs(d+1,cur);
            if(o) return true;
            moves.pop_back();
            r.invert_move(RubikCube::MOVE(i));
        }
        return false;
    }
    vector<RubikCube::MOVE> solve(){

        if(dfs(1,r)) return moves;
        return {};
    }
};

#endif //RUBIKCUBESOLVER_DFSSOLVER_H
