//
// Created by karthik on 27/3/24.
//

#include "CornerDBMaker.h"

using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDB(init_val);
}

bool CornerDBMaker::bfsAndStore() {
    RubikCubeBitBoardRep cube;
    queue<RubikCubeBitBoardRep> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
        curr_depth++;
        if (curr_depth == 9) break;
        for (int counter = 0; counter < n; counter++) {
            RubikCubeBitBoardRep node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubikCube::MOVE(i);
                node.trigger_move(curr_move);
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invert_move(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}