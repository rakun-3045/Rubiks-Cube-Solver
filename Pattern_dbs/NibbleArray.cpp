//
// Created by karthik on 22/3/24.
//

#include "NibbleArray.h"

using namespace std;

NibbleArray::NibbleArray(const size_t size, const uint8_t val) : size(size) {
    arr.resize(size/2+1);
    for(unsigned char & i : arr)
        i = val;
}

uint8_t NibbleArray::get(const size_t pos) const {
    assert(pos <= size);
    uint8_t cur = arr[pos/2];
    if(pos&1){
        return cur & 0x0F;
    }
    return cur>>4;
}

void NibbleArray::set(const size_t pos, const uint8_t val) {

    assert(pos <= size);
    uint8_t  cur = arr[pos/2];
    if(pos&1){
        arr[pos/2] = (cur & 0xF0) | (val & 0x0F);
    }else{
        arr[pos/2] = (cur & 0x0F) | (val<<4);
    }
}

//*********************************************************************************************************************
//Get pointer to underlying array

uint8_t *NibbleArray::data() {
    return this->arr.data();
}

const uint8_t *NibbleArray::data() const {
    return this->arr.data();
}

size_t NibbleArray::storageSize() const {
    return this->arr.size();
}

// Move all the moves to a vector. This doubles the size, but is faster to access,
// since there is no bitwise operation needed.

void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);

    for (unsigned i = 0; i < this->size; ++i)
        dest.push_back(this->get(i));
}

// Reset the array
void NibbleArray::reset(const uint8_t val) {
    fill(this->arr.begin(), this->arr.end(), val);
}

//*********************************************************************************************************************