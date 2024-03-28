//
// Created by karthik on 13/3/24.
//


#ifndef RUBIKCUBESOLVER_IDASTAR_H
#define RUBIKCUBESOLVER_IDASTAR_H
#include<bits/stdc++.h>
#include "RubikCube.h"
#include "Pattern_dbs/CornerPatternDB.h"

template<typename T, typename H>
class IDAstar {
private:
    CornerPatternDB cornerDB;
    vector<RubikCube::MOVE> moves;
    unordered_map<T, RubikCube::MOVE, H> move_done;
    unordered_map<T, bool, H> visited;
    struct Node {
        T cube;
        int depth;
        int estimate;
        Node(T c, int d, int e) : cube(c), depth(d), estimate(e) {};
    };

    struct compareCube {
        bool operator()(pair<Node, int> const &p1, pair<Node, int> const &p2) {
            auto n1 = p1.first, n2 = p2.first;
            if (n1.depth + n1.estimate == n2.depth + n2.estimate) {
                return n1.estimate > n2.estimate;
            } else return n1.depth + n1.estimate > n2.depth + n2.estimate;
        }
    };

    void resetStructure() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }


    pair<T,int> IDAstarAlgo(int max_bound){
        priority_queue<pair<Node,int>, vector<pair<Node,int>>, compareCube> pq;
        Node sc = Node(rubiksCube,0,cornerDB.getNumMoves(rubiksCube));
        unordered_map<T, bool, H> vis;
        pq.push({sc, 0});
        int next_bound = 100;
        while(!pq.empty()){
            auto cur = pq.top();
            Node node = cur.first;
            pq.pop();
            if(vis[node.cube]) continue;
            vis[node.cube] = true;
            move_done[node.cube] = RubikCube::MOVE(cur.second);
            if(node.cube.isSolved()) return {node.cube,max_bound};
            node.depth++;
            for(int i=0;i<18;i++){
                auto move = RubikCube::MOVE (i);
                node.cube.trigger_move(move);
                if(!vis[node.cube]){
                    node.estimate = cornerDB.getNumMoves(node.cube);
                    if(node.depth+1+node.estimate>max_bound){
                        next_bound = min(next_bound,node.depth+1+node.estimate);
                    }else{
                        pq.push({node, i});
                    }
                }
                node.cube.invert_move(move);

            }
        }
        return {rubiksCube,next_bound};
    }

public:
    T rubiksCube;

    IDAstar(T rub, string fn) {
        rubiksCube = rub;
        cornerDB.fromFile(fn); //
    }

    vector<RubikCube::MOVE>solve(){
        int max_bound = 1;
        auto temp = IDAstarAlgo(max_bound);
        while(temp.second!=max_bound){
            resetStructure();
            max_bound = temp.second;
            temp = IDAstarAlgo(max_bound);
        }
        T cube = temp.first;
        while(!(cube == rubiksCube)){
            auto move = move_done[cube];
            moves.push_back(move);
            cube.invert_move(move);
        }
        rubiksCube = temp.first;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};


#endif //RUBIKCUBESOLVER_IDASTAR_H
