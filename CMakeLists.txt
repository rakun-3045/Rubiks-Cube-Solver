cmake_minimum_required(VERSION 3.27)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp
        RubikCubeBitBoardRep.cpp
        RubikCube3DRep.cpp
        RubikCube1DRep.cpp
        RubikCube.cpp
        IDDFSsolver.h
        BFSsolver.h
        DFSsolver.h
        Pattern_dbs/PermutationIndexer.h
        Pattern_dbs/patternDB.cpp
        Pattern_dbs/math.h
        Pattern_dbs/math.cpp
        Pattern_dbs/NibbleArray.cpp
        Pattern_dbs/CornerPatternDB.cpp
        Pattern_dbs/CornerDBMaker.cpp
)
