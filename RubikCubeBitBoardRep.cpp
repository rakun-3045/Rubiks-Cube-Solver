//
// Created by karthik on 11/3/24.
//

#include "RubikCube.h"
#define ll uint64_t

class RubikCubeBitBoardRep: public RubikCube {
private:
    int arr[3][3] = {{0,1,2},{7,8,3},{6,5,4}};
public:
    ll bitboard[6]{};
    RubikCubeBitBoardRep(){
        for(int i=0;i<6;i++) bitboard[i]=0;
        for(int i=0;i<6;i++){
            ll col = 1LL<<i;
            for(int j=0;j<8;j++){
                 bitboard[i] |= col<<(j*8);
            }
        }
    }

    bool isSolved() override{
        for(int i=0;i<6;i++){
            ll col = 1LL<<i;
            ll ans=0;
            for(int j=0;j<8;j++){
                ans |= col<<(j*8);
            }
            if(ans!=bitboard[i]) return false;
        }
        return true;
    }

    COLOR getColor(FACE face,int row,int col) const override{
        int j = arr[row][col];
        if(j==8){
            return COLOR(face);
        }
        ll x =bitboard[int(face)];
        x >>= (j*8);
        ll num = (1LL<<8)-1;
        x &= num;
        switch(x){
            case 1:
                return RubikCube::COLOR::WHITE;
            case 2:
                return RubikCube::COLOR::GREEN;
            case 4:
                return RubikCube::COLOR::RED;
            case 8:
                return RubikCube::COLOR::BLUE;
            case 16:
                return RubikCube::COLOR::ORANGE;
            case 32:
                return RubikCube::COLOR::YELLOW;
            default:RubikCube::COLOR::YELLOW;
        }
        return RubikCube::COLOR::YELLOW;
    }


    void rotateFace(int ind){
        ll x = bitboard[ind]<<16;
        ll y = bitboard[ind]>>48;
        bitboard[ind] = x|y;
    }

    ll getColorBits(int face,int j){
        return ((bitboard[face]>>(j*8))&((1LL<<8)-1));
    }

    void changeCube(int df,int di1,int di2,int di3,int sf,int si1,int si2,int si3){
        bitboard[df] = (bitboard[df] & ~(((1LL<<8)-1)<<(di1*8))) | (getColorBits(sf,si1)<<(di1*8));
        bitboard[df] = (bitboard[df] & ~(((1LL<<8)-1)<<(di2*8))) | (getColorBits(sf,si2)<<(di2*8));
        bitboard[df] = (bitboard[df] & ~(((1LL<<8)-1)<<(di3*8))) | (getColorBits(sf,si3)<<(di3*8));
    }

    RubikCube &l() override{
        rotateFace(1);
        ll c1 = getColorBits(2,0);
        ll c2 = getColorBits(2,7);
        ll c3 = getColorBits(2,6);

        changeCube(2,0,7,6,0,0,7,6);
        changeCube(0,0,7,6,4,4,3,2);
        changeCube(4,4,3,2,5,0,7,6);

        bitboard[5] = (bitboard[5] & ~(((1LL<<8)-1)<<(0*8))) | (c1<<(0*8));
        bitboard[5] = (bitboard[5] & ~(((1LL<<8)-1)<<(7*8))) | (c2<<(7*8));
        bitboard[5] = (bitboard[5] & ~(((1LL<<8)-1)<<(6*8))) | (c3<<(6*8));
        return *this;
    }

    RubikCube &lp() override{
        l();
        l();
        l();
        return *this;
    }

    RubikCube &l2() override {
        l();
        l();
        return *this;
    }

    RubikCube &r() override {
        rotateFace(3);
        int face = 2;
        ll c1 = getColorBits(face,2);
        ll c2 = getColorBits(face,3);
        ll c3 = getColorBits(face,4);

        changeCube(2,2,3,4,5,2,3,4);
        changeCube(5,2,3,4,4,6,7,0);
        changeCube(4,6,7,0,0,2,3,4);

        face=0;
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(2*8))) | (c1<<(2*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(3*8))) | (c2<<(3*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(4*8))) | (c3<<(4*8));
        return *this;
    }

    RubikCube &rp() override {
        r();
        r();
        r();
        return *this;
    }

    RubikCube &r2() override {
        r();
        r();
        return *this;
    }

    RubikCube &f() override {
        rotateFace(2);
        int face = 1;
        ll c1 = getColorBits(face,2);
        ll c2 = getColorBits(face,3);
        ll c3 = getColorBits(face,4);

        changeCube(1,2,3,4,5,0,1,2);
        changeCube(5,0,1,2,3,6,7,0);
        changeCube(3,6,7,0,0,4,5,6);

        face=0;
        int a=4,b=5,c=6;
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(a*8))) | (c1<<(a*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(b*8))) | (c2<<(b*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(c*8))) | (c3<<(c*8));
        return *this;
    }

    RubikCube &fp() override {
        f();
        f();
        f();
        return *this;
    }

    RubikCube &f2() override {
        f();
        f();
        return *this;
    }

    RubikCube &b() override {
        rotateFace(4);
        int face = 0;
        ll c1 = getColorBits(face,0);
        ll c2 = getColorBits(face,1);
        ll c3 = getColorBits(face,2);

        changeCube(0,0,1,2,3,2,3,4);
        changeCube(3,2,3,4,5,4,5,6);
        changeCube(5,4,5,6,1,6,7,0);

        face=1;
        int a=6,b=7,c=0;
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(a*8))) | (c1<<(a*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(b*8))) | (c2<<(b*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(c*8))) | (c3<<(c*8));
        return *this;
    }

    RubikCube &bp() override {
        b();
        b();
        b();
        return *this;
    }

    RubikCube &b2() override {
        b();
        b();
        return *this;
    }

    RubikCube &u() override {
        rotateFace(0);
        int face = 2;
        ll c1 = getColorBits(face,0);
        ll c2 = getColorBits(face,1);
        ll c3 = getColorBits(face,2);

        changeCube(2,0,1,2,3,0,1,2);
        changeCube(3,0,1,2,4,0,1,2);
        changeCube(4,0,1,2,1,0,1,2);

        face=1;
        int a=0,b=1,c=2;
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(a*8))) | (c1<<(a*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(b*8))) | (c2<<(b*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(c*8))) | (c3<<(c*8));
        return *this;
    }

    RubikCube &up() override {
        u();
        u();
        u();
        return *this;
    }

    RubikCube &u2() override {
        u();
        u();
        return *this;
    }

    RubikCube &d() override {
        rotateFace(5);
        int face = 2;
        ll c1 = getColorBits(face,4);
        ll c2 = getColorBits(face,5);
        ll c3 = getColorBits(face,6);

        changeCube(2,4,5,6,3,4,5,6);
        changeCube(3,4,5,6,4,4,5,6);
        changeCube(4,4,5,6,1,4,5,6);

        face=1;
        int a=4,b=5,c=6;
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(a*8))) | (c1<<(a*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(b*8))) | (c2<<(b*8));
        bitboard[face] = (bitboard[face] & ~(((1LL<<8)-1)<<(c*8))) | (c3<<(c*8));
        return *this;
    }

    RubikCube &dp() override {
        d();
        d();
        d();
        return *this;
    }

    RubikCube &d2() override {
        d();
        d();
        return *this;
    }

    RubikCubeBitBoardRep &operator=(const RubikCubeBitBoardRep &r1){
        for(int i=0;i<6;i++){
            bitboard[i] = r1.bitboard[i];
        }
        return *this;
    }

    bool operator==(const RubikCubeBitBoardRep &r1) const{
        for(int i=0;i<6;i++){
            if(bitboard[i]!=r1.bitboard[i]) return false;
        }
        return true;
    }


};

//    ************************************** Custom hash function for unordered map ( have to change later )**********************************
struct hashbitboard{
    size_t operator()(const RubikCubeBitBoardRep &r1) const{
        ll ans = r1.bitboard[0];
        for(int i=1;i<6;i++) ans ^= r1.bitboard[i];
        return (size_t) ans;
    }
};