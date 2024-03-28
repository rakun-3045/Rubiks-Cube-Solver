//
// Created by karthik on 22/3/24.
//

#include "patternDB.h"


using namespace std;

PatternDB::PatternDB(const size_t size) : db(size,0xFF),size(size),num_items(0){}

PatternDB::PatternDB(const size_t size, uint8_t init_val) : db(size,init_val), size(size), num_items(0){}


// If the index is already set, it does nothing and returns false
// Else it sets ind and returns true

bool PatternDB::setNumMoves(const uint32_t ind, const uint8_t numMoves) {
    uint8_t oldMoves = this->getNumMoves(ind);

//    New item is getting added
    if(oldMoves == 0xF){
        ++this->num_items;
    }

    if(oldMoves > numMoves){
        this->db.set(ind, numMoves);
        return true;
    }
    return false;

}

bool PatternDB::setNumMoves(const RubikCube &cube, const uint8_t numMoves) {
    return this->setNumMoves(this->getDatabaseIndex(cube), numMoves);
}

uint8_t PatternDB::getNumMoves(const uint32_t ind) const {
    return this->db.get(ind);
}

uint8_t PatternDB::getNumMoves(const RubikCube &cube) const {
    return this->getNumMoves(this->getDatabaseIndex(cube));
}

size_t PatternDB::getSize() const {
    return this->size;
}

size_t PatternDB::getNumItems() const {
    return this->num_items;
}

bool PatternDB::isFull() const {
    return this->num_items == this->size;
}

void PatternDB::toFile(const string &filePath) const {

    ofstream writer(filePath, ios::out | ios::binary | ios::trunc);

    if(!writer.is_open())
        throw "Failed to open the file to write";

    writer.write(
            reinterpret_cast<const char*>(this->db.data()),
            this->db.storageSize()
    );

    writer.close();
}

// Returns true of database is loaded successfully
// else return false

bool PatternDB::fromFile(const string &filePath) {
    ifstream reader(filePath, ios::in | ios::ate);

    if(!reader.is_open())
        return false;

    size_t fileSize = reader.tellg();
//    cout<<"Done\n";
    if(fileSize != this->db.storageSize()){
        reader.close();
        throw "Database corrupt! Failed to open Reader";
    }

    reader.seekg(0, ios::beg);
    reader.read(
            reinterpret_cast<char*> (this->db.data()),
            this->db.storageSize()
    );
    reader.close();
    this->num_items = this->size;

    return true;
}



vector<uint8_t> PatternDB::inflate() const {
    vector<uint8_t> inflated;
    this->db.inflate(inflated);
    return inflated;
}

void PatternDB::reset() {
    if(this->num_items != 0){
        this->db.reset(0xFF);
        this->num_items = 0;
    }
}
