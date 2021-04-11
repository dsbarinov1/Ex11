// Copyright 2021 DBarinov

#include <gtest/gtest.h>
#include <ctime>
#include <string>
#include "train.h"

TEST(CreateTest, test1) {
    Train test_train_1;
    EXPECT_EQ(0, test_train_1.train_length());
    Train test_train_2(5);
    EXPECT_EQ(5, test_train_2.train_length());
}

TEST(AddCageTest, test2) {
    Train test_train;
    test_train.add_cage(true);
    EXPECT_EQ(1, test_train.train_length());
    test_train.add_cage(false);
    EXPECT_EQ(true, test_train.getFirst()->get());
}

TEST(RoundTest, test3) {
    Train test_train(5);
    Cage* temp = test_train.getLast();
    if (temp->next == test_train.getFirst()) {
        EXPECT_EQ(1, 1);
    } else {
        EXPECT_EQ(0, 1);
    }
}

TEST(FindLenTest, test4) {
    unsigned int gen = std::time(NULL);
    size_t num_train = rand_r(&gen) % 1000;
    Train test_train(num_train);
    EXPECT_EQ(num_train, test_train.train_length());
}

TEST(LightTest, test5) {
    Train test_train;
    test_train.add_cage(true);
    EXPECT_EQ(true, test_train.getFirst()->get());
    test_train.getFirst()->off();
    EXPECT_EQ(false, test_train.getFirst()->get());
}
