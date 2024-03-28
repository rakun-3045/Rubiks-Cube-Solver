//
// Created by karthik on 22/3/24.
//

#ifndef RUBIKCUBESOLVER_PATTERNDB_H
#define RUBIKCUBESOLVER_PATTERNDB_H

#include "../RubikCube.h"
#include "NibbleArray.h"
#include "bits/stdc++.h"

using namespace std;

class PatternDB {

    NibbleArray db;
    size_t size;
    size_t num_items;

    PatternDB();

public:
    PatternDB(const size_t size);

    PatternDB(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const RubikCube &cube) const = 0;

    virtual bool setNumMoves(const RubikCube &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const RubikCube &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};

#endif //RUBIKCUBESOLVER_PATTERNDB_H
