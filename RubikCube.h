//
// Created by karthik on 10/3/24.
//

#ifndef RUBIKCUBESOLVER_RUBIKCUBE_H
#define RUBIKCUBESOLVER_RUBIKCUBE_H

#include "bits/stdc++.h"
using namespace std;

class RubikCube {
public:

    enum class FACE {
        UP,LEFT,FRONT,RIGHT,BACK,DOWN
    };

    enum class COLOR {
        WHITE,GREEN,RED,BLUE,ORANGE,YELLOW
    };

    enum class MOVE {
        L,LP,L2,R,RP,R2,U,UP,U2,D,DP,D2,F,FP,F2,B,BP,B2
    };

    virtual COLOR getColor(FACE face,int row,int col) const =0;

    vector<MOVE> RandomShuffle(int times)  ;

    string getMoveString(MOVE move);

   RubikCube &trigger_move(MOVE move);
   RubikCube &invert_move(MOVE move);

   uint8_t getCornerIndex(uint8_t ind) const;

   uint8_t getCornerOrientation(uint8_t ind) const;

   string getCornerString(uint8_t ind) const;

    char getColorletter(COLOR col) const;

    virtual bool isSolved() =0;

    void print() const;

    // 18 operations (rotations)
    virtual RubikCube &l() = 0;
    virtual RubikCube &r() = 0;
    virtual RubikCube &u() = 0;
    virtual RubikCube &d() = 0;
    virtual RubikCube &b() = 0;
    virtual RubikCube &f() = 0;
    virtual RubikCube &lp() = 0;
    virtual RubikCube &rp() = 0;
    virtual RubikCube &up() = 0;
    virtual RubikCube &dp() = 0;
    virtual RubikCube &bp() = 0;
    virtual RubikCube &fp() = 0;
    virtual RubikCube &f2() = 0;
    virtual RubikCube &b2() = 0;
    virtual RubikCube &l2() = 0;
    virtual RubikCube &r2() = 0;
    virtual RubikCube &u2() = 0;
    virtual RubikCube &d2() = 0;


    virtual ~RubikCube() = default;
};


#endif //RUBIKCUBESOLVER_RUBIKCUBE_H
