//
// Created by karthik on 10/3/24.
//

#include "RubikCube.h"

class RubikCube3DRep : public RubikCube {
public:
    char cube[6][3][3] = {};

    RubikCube3DRep() {
        for (int i = 0; i < 6; i++) {
            char col = getColorletter(COLOR(i));
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = col;
                }
            }
        }
    }

    COLOR getColor(FACE face, int row, int col) const override {
        switch (cube[(int) face][row][col]) {
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

    bool isSolved() override {
        for (int i = 0; i < 6; i++) {
            char col;
            switch (i) {
                case 0:
                    col = 'W';
                    break;
                case 1:
                    col = 'G';
                    break;
                case 2:
                    col = 'R';
                    break;
                case 3:
                    col = 'B';
                    break;
                case 4:
                    col = 'O';
                    break;
                default:
                    col = 'Y';
            }
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (cube[i][j][k] != col)
                        return false;
                }
            }
        }
        return true;
    }

    void rotateFace(int face) {
        char temp[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[i][j] = cube[face][i][j];
            }
        }
        cube[face][0][0] = temp[2][0];
        cube[face][0][1] = temp[1][0];
        cube[face][0][2] = temp[0][0];
        cube[face][1][0] = temp[2][1];
        cube[face][1][2] = temp[0][1];
        cube[face][2][0] = temp[2][2];
        cube[face][2][1] = temp[1][2];
        cube[face][2][2] = temp[0][2];
    }

    RubikCube &l() override {
//        cout<<"L\n";
        rotateFace(1);
        char temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2][i][0];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][i][0] = cube[0][i][0];
            cube[0][i][0] = cube[4][2 - i][2];
            cube[4][2 - i][2] = cube[5][i][0];
            cube[5][i][0] = temp[i];
        }
        return *this;
    }

    RubikCube &lp() override {
//        cout<<"LP\n";
        l();
        l();
        l();
        return *this;
    }

    RubikCube &l2() override {
//        cout<<"L2\n";
        l();
        l();
        return *this;
    }

    RubikCube &r() override {
//        cout<<"R\n";
        rotateFace(3);
        char temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][i][2] = cube[5][i][2];
            cube[5][i][2] = cube[4][2 - i][0];
            cube[4][2 - i][0] = cube[0][i][2];
            cube[0][i][2] = temp[i];
        }
        return *this;
    }

    RubikCube &rp() override {
//        cout<<"RP\n";
        r();
        r();
        r();
        return *this;
    }

    RubikCube &r2() override {
//        cout<<"R2\n";
        r();
        r();
        return *this;
    }

    RubikCube &f() override {
//        cout<<"F\n";
        rotateFace(2);
        char temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[1][i][2];
        }
        for (int i = 0; i < 3; i++) {
            cube[1][i][2] = cube[5][0][i];
            cube[5][0][i] = cube[3][2 - i][0];
            cube[3][2 - i][0] = cube[0][2][2 - i];
            cube[0][2][2 - i] = temp[i];
        }
        return *this;
    }

    RubikCube &fp() override {
//        cout<<"FP\n";
        f();
        f();
        f();
        return *this;
    }

    RubikCube &f2() override {
//        cout<<"F2\n";
        f();
        f();
        return *this;
    }

    RubikCube &b() override {
//        cout<<"B\n";
        rotateFace(4);
        char temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[0][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[0][0][i] = cube[3][i][2];
            cube[3][i][2] = cube[5][2][2 - i];
            cube[5][2][2 - i] = cube[1][2 - i][0];
            cube[1][2 - i][0] = temp[i];
        }
        return *this;
    }

    RubikCube &bp() override {
//        cout<<"BP\n";
        b();
        b();
        b();
        return *this;
    }

    RubikCube &b2() override {
//        cout<<"B2\n";
        b();
        b();
        return *this;
    }

    RubikCube &u() override {
//        cout<<"U\n";
        rotateFace(0);
        char temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2][0][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][0][i] = cube[3][0][i];
            cube[3][0][i] = cube[4][0][i];
            cube[4][0][i] = cube[1][0][i];
            cube[1][0][i] = temp[i];
        }
        return *this;
    }

    RubikCube &up() override {
//        cout<<"UP\n";
        u();
        u();
        u();
        return *this;
    }

    RubikCube &u2() override {
//        cout<<"U2\n";
        u();
        u();
        return *this;
    }

    RubikCube &d() override {
//        cout<<"D\n";
        rotateFace(5);
        char temp[3];
        for (int i = 0; i < 3; i++) {
            temp[i] = cube[2][2][i];
        }
        for (int i = 0; i < 3; i++) {
            cube[2][2][i] = cube[1][2][i];
            cube[1][2][i] = cube[4][2][i];
            cube[4][2][i] = cube[3][2][i];
            cube[3][2][i] = temp[i];
        }
        return *this;
    }

    RubikCube &dp() override {
//        cout<<"DP\n";
        d();
        d();
        d();
        return *this;
    }

    RubikCube &d2() override {
//        cout<<"D2\n";
        d();
        d();
        return *this;
    }

    bool operator==(const RubikCube3DRep &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubikCube3DRep &operator=(const RubikCube3DRep &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};
    //    ************************************** Custom hash function for unordered map ( have to change later )**********************************

struct hash3D{
    size_t operator()(const RubikCube3DRep &r1) const{
        string ans = "";
        for(int i=0;i<6;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    ans+=r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(ans);
    }
};


