//
// Created by karthik on 27/3/24.
//

#ifndef RUBIKCUBESOLVER_CORNERDBMAKER_H
#define RUBIKCUBESOLVER_CORNERDBMAKER_H
#include "CornerPatternDB.h"
#include "../RubikCubeBitBoardRep.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDB cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};
#endif //RUBIKCUBESOLVER_CORNERDBMAKER_H
