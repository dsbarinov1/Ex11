// Copyright 2020 DBarinov
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <ctime>

class Cage {
private:
    bool light; // состояние света в вагоне (вкл/выкл)

public:
    Cage* next; // указатель на следующий вагон
    Cage* prev; // указатель на предыдущий вагон
    Cage() : light(false), next(nullptr), prev(nullptr) {} // конструктор вагона
    void on() { light = true; } // ВКЛ свет
    void off() { light = false; } // ВЫКЛ свет
    bool get() const { return light; }
};

class Train {
 private:
    Cage* first; // указатель на первый вагон 
    Cage* last; // указатель на последний вагон

 public:
    Train(); // конструктор 
    explicit Train(size_t n); // создаём массив размера n

    void add_cage(bool light = false); // добавление вагона 
    void print_cages_status(); // печать состояния всех вагонов в поезде
    size_t train_length(); // метод нахождения длины поезда

    void print_length(); // распечатать длину поезда

    Cage* getFirst() {
        return first;
    }

    Cage* getLast() {
        return last;
    }
};



#endif  // INCLUDE_TRAIN_H_