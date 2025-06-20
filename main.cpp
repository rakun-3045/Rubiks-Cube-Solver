#include <iostream>
#include <vector>
#include <string>
#include "RubikCube.h"
#include "RubikCube3DRep.cpp"
#include "RubikCube1DRep.cpp"
#include "RubikCubeBitBoardRep.cpp"
#include "IDAstar.h"
#include "DFSsolver.h"
#include "BFSsolver.h"
#include "IDDFSsolver.h"

#include "Pattern_dbs/CornerPatternDB.h"
#include "Pattern_dbs/patternDB.cpp"
#include "Pattern_dbs/CornerPatternDB.cpp"
#include "Pattern_dbs/NibbleArray.cpp"
#include "Pattern_dbs/math.cpp"
using namespace std;

int main() {
    // Use relative path instead of absolute path
    string fileName = "DBS/cornerDepth5V1.txt";

    try {
        RubikCubeBitBoardRep cube;
        auto shuffleMoves = cube.RandomShuffle(10);
        cube.print();
        cout << "Shuffle moves: ";
        for (auto move: shuffleMoves) cout << cube.getMoveString(move) << " ";
        cout << "\n";

        IDAstar<RubikCubeBitBoardRep, hashbitboard> idaStarSolver(cube, fileName);
        vector<RubikCube::MOVE> moves = idaStarSolver.solve();

        cout << "Solved cube state:\n";
        idaStarSolver.rubiksCube.print();
        cout << "Solution moves: ";
        for (auto move: moves) cout << cube.getMoveString(move) << " ";
        cout << "\n";
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
