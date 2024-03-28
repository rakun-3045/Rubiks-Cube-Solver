//
// Created by karthik on 12/3/24.
//

#include <bits/stdc++.h>
#include "RubikCube.h"
using namespace std;

#ifndef RUBIKCUBESOLVER_BFSSOLVER_H
#define RUBIKCUBESOLVER_BFSSOLVER_H

template<typename T,typename H>
class BFSSolver {
public:
    T r;
    vector<RubikCube::MOVE>moves;
    unordered_map<T,RubikCube::MOVE,H>cube_moves;
    explicit BFSSolver(T r1){
        r=r1;
    }

    T bfs(){
        queue<T>q;
        unordered_map<T,bool,H>vis;
        q.push(r);
        vis[r]=true;
        while(!q.empty()){
            T cur = q.front();
            q.pop();
//            cur.print();
            if(cur.isSolved()) return cur;
            for(int i=0;i<18;i++){
                cur.trigger_move(RubikCube::MOVE(i));
                if(!vis[cur]){
                    vis[cur]=true;
                    q.push(cur);
                    cube_moves[cur]=RubikCube::MOVE(i);
                }
                cur.invert_move(RubikCube::MOVE(i));
            }
        }
        return r;
    }

    vector<RubikCube::MOVE> solve(){
        T temp = bfs();
        while( !(temp == r)){
            moves.push_back(cube_moves[temp]);
            temp.invert_move(cube_moves[temp]);
//            cout<<int(cube_moves[temp])<<endl;
        }
        reverse(moves.begin(),moves.end());
        return moves;
    }

};

#endif //RUBIKCUBESOLVER_BFSSOLVER_H
