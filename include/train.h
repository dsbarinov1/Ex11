// Copyright 2020 DBarinov
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <ctime>

class Cage {
private:
    bool light; // ��������� ����� � ������ (���/����)

public:
    Cage* next; // ��������� �� ��������� �����
    Cage* prev; // ��������� �� ���������� �����
    Cage() : light(false), next(nullptr), prev(nullptr) {} // ����������� ������
    void on() { light = true; } // ��� ����
    void off() { light = false; } // ���� ����
    bool get() const { return light; }
};

class Train {
 private:
    Cage* first; // ��������� �� ������ ����� 
    Cage* last; // ��������� �� ��������� �����

 public:
    Train(); // ����������� 
    explicit Train(size_t n); // ������ ������ ������� n

    void add_cage(bool light = false); // ���������� ������ 
    void print_cages_status(); // ������ ��������� ���� ������� � ������
    size_t train_length(); // ����� ���������� ����� ������

    void print_length(); // ����������� ����� ������

    Cage* getFirst() {
        return first;
    }

    Cage* getLast() {
        return last;
    }
};



#endif  // INCLUDE_TRAIN_H_