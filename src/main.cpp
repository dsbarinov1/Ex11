// Copyright 2020 DBarinov

#include <iostream>
#include <string>
#include <train.h>

using namespace std;

int main() {
    unsigned int gen = time(NULL); // ���������
    size_t num_train = rand_r(&gen) % 100; // ���������

    Train MyTrain(num_train); // ������ ������ ������ Train

    MyTrain.print_cages_status(); // ������� ��� ���������� ����������
    MyTrain.print_length();
    cout << endl;
    cout << "Length = " << num_train << endl;
    return 0;
}