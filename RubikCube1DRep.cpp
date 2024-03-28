//
// Created by karthik on 11/3/24.
//
#include "RubikCube.h"

class RubikCube1DRep : public RubikCube {
private:
    int getIndex(int face,int row,int col){
        return 9*face+row*3+col;
    }
public:
    char cube[54]={};
    RubikCube1DRep(){
        for(int i=0;i<54;i++){
            cube[i] = getColorletter(COLOR(i/9));
        }
    }

    COLOR getColor(FACE face,int row,int col) const override{
        int ind = 9*int(face);
        ind += col+3*row;
        switch (cube[ind]){
            case 'G':
                return RubikCube::COLOR::GREEN;
            case 'B':
                return RubikCube::COLOR::BLUE;
            case 'W':
                return RubikCube::COLOR::WHITE;
            case 'Y':
                return RubikCube::COLOR::YELLOW;
            case 'R':
                return RubikCube::COLOR::RED;
            case 'O':
                return RubikCube::COLOR::ORANGE;
        }
        return RubikCube::COLOR::ORANGE;
    }

    bool isSolved() override{
        for(int i=0;i<6;i++){
            int ind = i*9;
            char col = getColorletter(COLOR(i));
            for(int j=0;j<9;j++){
                if(cube[ind+j]!=col) return false;
            }
        }
        return true;
    }

    void rotateFace(int ind){
        ind = 9*ind;
        char temp = cube[ind];
        cube[ind] = cube[ind+6];
        cube[ind+6] = cube[ind+8];
        cube[ind+8] = cube[ind+2];
        cube[ind+2] = temp;
        temp = cube[ind+1];
        cube[ind+1] = cube[ind+3];
        cube[ind+3] = cube[ind+7];
        cube[ind+7] = cube[ind+5];
        cube[ind+5] = temp;
    }

    RubikCube &l() override{
        rotateFace(1);
        char temp[3];
        for(int i=0;i<3;i++){
            temp[i] = cube[2*9+i*3];
        }
        for(int i=0;i<3;i++){
            cube[2*9+i*3] = cube[i*3];
            cube[i*3] = cube[4*9+2+(2-i)*3];
            cube[4*9+2+(2-i)*3] = cube[5*9 + 3*i];
            cube[5*9 + 3*i] = temp[i];
        }
    }

    RubikCube &lp() override{
        l();
        l();
        l();
    }

    RubikCube &l2() override {
        l();
        l();
    }



    RubikCube &r() override {
        rotateFace(3);
        char temp[3];
        for(int i=0;i<3;i++){
            temp[i] = cube[getIndex(2,i,2)];
        }
        for(int i=0;i<3;i++){
            cube[getIndex(2,i,2)] = cube[getIndex(5,i,2)];
            cube[getIndex(5,i,2)] = cube[getIndex(4,2-i,0)];
            cube[getIndex(4,2-i,0)] = cube[getIndex(0,i,2)];
            cube[getIndex(0,i,2)]= temp[i];
        }
    }

    RubikCube &rp() override {
        r();
        r();
        r();
    }

    RubikCube &r2() override {
        r();
        r();
    }

    RubikCube &f() override {
        rotateFace(2);
        char temp[3];
        for(int i=0;i<3;i++){
            temp[i]=cube[getIndex(1,i,2)];
        }
        for(int i=0;i<3;i++){
            cube[getIndex(1,i,2)] = cube[getIndex(5,0,i)];
            cube[getIndex(5,0,i)] = cube[getIndex(3,2-i,0)];
            cube[getIndex(3,2-i,0)] = cube[getIndex(0,2,2-i)];
            cube[getIndex(0,2,2-i)] = temp[i];
        }
    }

    RubikCube &fp() override {
        f();
        f();
        f();
    }

    RubikCube &f2() override {
        f();
        f();
    }

    RubikCube &b() override {
        rotateFace(4);
        char temp[3];
        for(int i=0;i<3;i++){
            temp[i]=cube[getIndex(0,0,i)];
        }
        for(int i=0;i<3;i++){
            cube[getIndex(0,0,i)] = cube[getIndex(3,i,2)];
            cube[getIndex(3,i,2)] = cube[getIndex(5,2,2-i)];
            cube[getIndex(5,2,2-i)] = cube[getIndex(1,2-i,0)];
            cube[getIndex(1,2-i,0)] = temp[i];
        }
    }

    RubikCube &bp() override {
        b();
        b();
        b();
    }

    RubikCube &b2() override {
        b();
        b();
    }

    RubikCube &u() override {
        rotateFace(0);
        char temp[3];
        for(int i=0;i<3;i++){
            temp[i]=cube[getIndex(2,0,i)];
        }
        for(int i=0;i<3;i++){
            cube[getIndex(2,0,i)] = cube[getIndex(3,0,i)];
            cube[getIndex(3,0,i)] = cube[getIndex(4,0,i)];
            cube[getIndex(4,0,i)] = cube[getIndex(1,0,i)];
            cube[getIndex(1,0,i)] = temp[i];
        }
    }

    RubikCube &up() override {
        u();
        u();
        u();
    }

    RubikCube &u2() override {
        u();
        u();
    }

    RubikCube &d() override {
        rotateFace(5);
        char temp[3];
        for(int i=0;i<3;i++){
            temp[i]=cube[getIndex(2,2,i)];
        }
        for(int i=0;i<3;i++){
            cube[getIndex(2,2,i)] = cube[getIndex(1,2,i)];
            cube[getIndex(1,2,i)] = cube[getIndex(4,2,i)];
            cube[getIndex(4,2,i)] = cube[getIndex(3,2,i)];
            cube[getIndex(3,2,i)] = temp[i];
        }
    }

    RubikCube &dp() override {
        d();
        d();
        d();
    }

    RubikCube &d2() override {
        d();
        d();
    }

    bool operator==(const RubikCube1DRep &r1) const{
        for(int i=0;i<54;i++){
            if(cube[i]!=r1.cube[i]) return false;
        }
        return true;
    }

    RubikCube1DRep &operator=(const RubikCube1DRep &r1){
        for(int i=0;i<54;i++){
            cube[i] = r1.cube[i];
        }
        return *this;
    }

};

//    ************************************** Custom hash function for unordered map ( have to change later )**********************************

struct hash1D{
    size_t operator()(const RubikCube1DRep &r1) const{
        string ans = "";
        for(int i=0;i<54;i++) ans += r1.cube[i];
        return hash<string>()(ans);
    }
};
