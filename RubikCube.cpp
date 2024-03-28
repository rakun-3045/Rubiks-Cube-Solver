//
// Created by karthik on 10/3/24.
//

#include "RubikCube.h"

string RubikCube::getMoveString(MOVE move){
    switch (move){
        case MOVE::L:
            return "L";
        case MOVE::LP:
            return "LP";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RP:
            return "RP";
        case MOVE::R2:
            return "R2";
        case MOVE::F:
            return "F";
        case MOVE::FP:
            return "FP";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BP:
            return "BP";
        case MOVE::B2:
            return "B2";
        case MOVE::U:
            return "U";
        case MOVE::UP:
            return "UP";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DP:
            return "DP";
        case MOVE::D2:
            return "D2";
    }
    return "";
}

vector<RubikCube::MOVE> RubikCube::RandomShuffle(int times)  {
    srand(time(0));
    vector<MOVE>ans;
    for(int i=0;i<times;i++){
        int randMove = rand()%18;
        ans.push_back(MOVE(randMove));
        MOVE move = MOVE(randMove);
        switch (move){
            case MOVE::L:
                l();
                break;
            case MOVE::LP:
                lp();
                break;
            case MOVE::L2:
                l2();
                break;
            case MOVE::R:
                r();
                break;
            case MOVE::RP:
                rp();
                break;
            case MOVE::R2:
                r2();
                break;
            case MOVE::U:
                u();
                break;
            case MOVE::UP:
                up();
                break;
            case MOVE::U2:
                u2();
                break;
            case MOVE::D:
                d();
                break;
            case MOVE::DP:
                dp();
                break;
            case MOVE::D2:
                d2();
                break;
            case MOVE::F:
                f();
                break;
            case MOVE::FP:
                fp();
                break;
            case MOVE::F2:
                f2();
                break;
            case MOVE::B:
                b();
                break;
            case MOVE::BP:
                bp();
                break;
            case MOVE::B2:
                b2();
                break;
        }
//        print();
    }
    return ans;
}

RubikCube &RubikCube::trigger_move(RubikCube::MOVE move){
    switch(move){
        case RubikCube::MOVE::L:
            return l();
        case RubikCube::MOVE::LP:
            return lp();
        case RubikCube::MOVE::L2:
            return l2();
        case RubikCube::MOVE::R:
            return r();
        case RubikCube::MOVE::RP:
            return rp();
        case RubikCube::MOVE::R2:
            return r2();
        case RubikCube::MOVE::U:
            return u();
        case RubikCube::MOVE::UP:
            return up();
        case RubikCube::MOVE::U2:
            return u2();
        case RubikCube::MOVE::D:
            return d();
        case RubikCube::MOVE::DP:
            return dp();
        case RubikCube::MOVE::D2:
            return d2();
        case RubikCube::MOVE::F:
            return f();
        case RubikCube::MOVE::FP:
            return fp();
        case RubikCube::MOVE::F2:
            return f2();
        case RubikCube::MOVE::B:
            return b();
        case RubikCube::MOVE::BP:
            return bp();
        case RubikCube::MOVE::B2:
            return b2();
    }
}

RubikCube &RubikCube::invert_move(RubikCube::MOVE move) {
    switch(move){
        case MOVE::L:
            return lp();
        case MOVE::LP:
            return l();
        case MOVE::L2:
            return l2();
        case MOVE::R:
            return rp();
        case MOVE::RP:
            return r();
        case MOVE::R2:
            return r2();
        case MOVE::U:
            return up();
        case MOVE::UP:
            return u();
        case MOVE::U2:
            return u2();
        case MOVE::D:
            return dp();
        case MOVE::DP:
            return d();
        case MOVE::D2:
            return d2();
        case MOVE::F:
            return fp();
        case MOVE::FP:
            return f();
        case MOVE::F2:
            return f2();
        case MOVE::B:
            return bp();
        case MOVE::BP:
            return b();
        case MOVE::B2:
            return b2();
    }
}

char RubikCube :: getColorletter(RubikCube::COLOR col) const{
    switch(col){
        case COLOR::BLUE:
            return 'B';
        case COLOR::GREEN:
            return 'G';
        case COLOR::WHITE:
            return 'W';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::RED:
            return 'R';
        case COLOR::ORANGE:
            return 'O';
    }
    return 'O';
}

void RubikCube::print() const {
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<"  ";
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorletter(getColor(FACE(0),i,j))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<getColorletter(getColor(FACE(1),i,j))<<" ";
        }
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorletter(getColor(FACE(2),i,j))<<" ";
        }
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorletter(getColor(FACE(3),i,j))<<" ";
        }
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorletter(getColor(FACE(4),i,j))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) cout<<"  ";
        cout<<" ";
        for(int j=0;j<3;j++){
            cout<<getColorletter(getColor(FACE(5),i,j))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

string RubikCube::getCornerString(uint8_t ind) const {
    string ans="";
    switch (ind) {
        //UFR
        case 0:
            ans += getColorletter(getColor(FACE::UP,2,2));
            ans += getColorletter(getColor(FACE::FRONT,0,2));
            ans += getColorletter(getColor(FACE::RIGHT,0,0));
            break;
        //UFL
        case 1:
            ans += getColorletter(getColor(FACE::UP,2,0));
            ans += getColorletter(getColor(FACE::FRONT,0,0));
            ans += getColorletter(getColor(FACE::LEFT,0,2));
            break;
        //UBL
        case 2:
            ans += getColorletter(getColor(FACE::UP,0,0));
            ans += getColorletter(getColor(FACE::BACK,0,2));
            ans += getColorletter(getColor(FACE::LEFT,0,0));
            break;
        //UBR
        case 3:
            ans += getColorletter(getColor(FACE::UP,0,2));
            ans += getColorletter(getColor(FACE::BACK,0,0));
            ans += getColorletter(getColor(FACE::RIGHT,0,2));
            break;
        //DFR
        case 4:
            ans += getColorletter(getColor(FACE::DOWN,0,2));
            ans += getColorletter(getColor(FACE::FRONT,2,2));
            ans += getColorletter(getColor(FACE::RIGHT,2,0));
            break;
        //DFL
        case 5:
            ans += getColorletter(getColor(FACE::DOWN,0,0));
            ans += getColorletter(getColor(FACE::FRONT,2,0));
            ans += getColorletter(getColor(FACE::LEFT,2,2));
            break;
        //DBR
        case 6:
            ans += getColorletter(getColor(FACE::DOWN,2,2));
            ans += getColorletter(getColor(FACE::BACK,2,0));
            ans += getColorletter(getColor(FACE::RIGHT,2,2));
            break;
        //DBL
        case 7:
            ans += getColorletter(getColor(FACE::DOWN,2,0));
            ans += getColorletter(getColor(FACE::BACK,2,2));
            ans += getColorletter(getColor(FACE::LEFT,2,0));
            break;

    }
    return ans;
}

//**************************************************************************************************************
uint8_t RubikCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerString(ind);
    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubikCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}
//*********************************************************************************************************************

