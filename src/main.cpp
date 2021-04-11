// Copyright 2020 DBarinov

#include <iostream>
#include <string>
#include <train.h>

int main() {
    unsigned int gen = std::time(NULL);  // Generation
    size_t num_train = rand_r(&gen) % 100;  // Generation

    Train MyTrain(num_train);  // Creating an object of class Train

    MyTrain.print_cages_status();  // Print all the obtained information
    MyTrain.print_length();
    std::cout << std::endl;
    std::cout << "Length = " << num_train << std::endl;
    return 0;
}
