// Copyright 2020 DBarinov
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <ctime>


class Cage {
 private:
    bool light;  // the state of the light in the cage (on/off)

 public:
    Cage* next;  // pointer to the next cage
    Cage* prev;  // pointer to the prev cage
    Cage() : light(false), next(nullptr), prev(nullptr) {}  // cage builder
    void on() { light = true; }  //  ON light
    void off() { light = false; }  //  OFF light
    bool get() const { return light; }
};

class Train {
 private:
    Cage* first;  // pointer to the first cage
    Cage* last;  // pointer to the last cage

 public:
    Train();  // builder
    explicit Train(size_t n);  // create an array of size n
    void add_cage(bool light = false);  // add a cage
    void print_cages_status();  // Print the status of all cages in the train
    size_t train_length();  // method of finding the train length
    void print_length();  // print the length of the train
    Cage* getFirst() {
        return first;
    }
    Cage* getLast() {
        return last;
    }
};

#endif  // INCLUDE_TRAIN_H_
