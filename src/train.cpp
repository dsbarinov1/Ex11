// Copyright 2020 DBarinov

#include <iostream>
#include "train.h"


Train::Train() {  // Builder by default
    this->first = nullptr;
    this->last = nullptr;
}

Train::Train(size_t n) {  // Builder + generation
    this->first = nullptr;
    this->last = nullptr;
    unsigned int gen = std::time(NULL);
    for (size_t i = 0; i < n; i++) {
        Cage* this_cage = new Cage;
        int status = rand_r(&gen) % 2; 
        if (status == 1) {
            this->add_cage(true);
        } else {
            this->add_cage();
        }
    }
}

void Train::add_cage(bool light) {  // method of adding a cage
    Cage* this_cage = new Cage;
    if (light == true) {
        this_cage->on();
    } else {
        this_cage->off();
    }
    if (this->first == nullptr) {
        this->first = this_cage;
        this->last = this_cage;
    }
    if (this->first == this->last) {
        this->last = this_cage;
        this->first->next = this_cage;
        this->first->prev = this_cage;
        this->last->next = this->first;
        this->last->prev = this->first;
    } else {
        this_cage->prev = this->last;
        this->last->next = this_cage;
        this->last = this_cage;
        this->first->prev = this->last;
        this->last->next = this->first;
    }
}

void Train::print_cages_status() {  // printing the status of all cages
    Cage* temp = this->first;
    size_t count = 1;
    while (temp != this->last) {
        std::cout << "Status of cage number " << count << " is: "
            << temp->get() << std::endl;
        count++;
        temp = temp->next;
    }
    std::cout << "Status of cage number " << count << " is: " << temp->get();
    std::cout << std::endl;
}

size_t Train::train_length() {  // train length
    size_t lgth = 0;
    Cage* temp_cage = this->first;
    if (temp_cage == nullptr) return 0;
    temp_cage->off();
    lgth++;
    while (true) {
        for (size_t i = 1; i <= lgth; i++) {
            temp_cage = temp_cage->next;
            temp_cage->on();
        }

        for (size_t i = 1; i <= lgth; i++) {
            temp_cage = temp_cage->prev;
        }

        if (temp_cage->get() == true) break;
        lgth++;
    }
    return lgth;
}

void Train::print_length() {
    std::cout << "Length of train is: " << this->train_length();
}
