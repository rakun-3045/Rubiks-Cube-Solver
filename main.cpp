#include <bits/stdc++.h>
#include "RubikCube3DRep.cpp"
#include "RubikCube1DRep.cpp"
#include "RubikCubeBitBoardRep.cpp"
#include "IDAstar.h"
#include "DFSsolver.h"
#include "BFSsolver.h"
#include "IDDFSsolver.h"

//#include "Pattern dbs/CornerPatternDB.h"
//#include "Pattern dbs/CornerDBMaker.h"
using namespace std;

int main() {
    string fileName = "/home/karthik/CLionProjects/RubikCubeSolver/DBS/cornerDepth5V1.txt";

    RubikCubeBitBoardRep cube;
    auto shuffleMoves = cube.RandomShuffle(10);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMoveString(move) << " ";
    cout << "\n";

    IDAstar<RubikCubeBitBoardRep, hashbitboard> idaStarSolver(cube, fileName);
    vector<RubikCube::MOVE> moves = idaStarSolver.solve();

    idaStarSolver.rubiksCube.print();
    for (auto move: moves) cout << cube.getMoveString(move) << " ";
    cout << "\n";
    return 0;
}
