#pragma once
#include "Sparce_vector.h"
#include <cassert>


void test_1_vector_sparce_vector() {
    int* a = new int[10];
    for (int i = 0; i < 10; i++) {
        if (i % 2)
            a[i] = i + 3;
        else
            a[i] = 0;
    }
    Sparce_vector<int>* sparce_vector = new Sparce_vector<int>(a, 10, compare_pairs);
    for (int i = 0; i < 10; i++) {
        assert(a[i] == sparce_vector->Get_sparce_vector()[i]);
    }
    assert(10 == sparce_vector->Get_size());
}

void test_2_vector_sparce_vector() {
    int* a = new int[14];
    for (int i = 0; i < 14; i++) {
        a[i] = 0;
    }
    Sparce_vector<int>* sparce_vector = new Sparce_vector<int>(a, 14, compare_pairs);
    for (int i = 0; i < 14; i++) {
        assert(a[i] == sparce_vector->Get_sparce_vector()[i]);
    }
    assert(14 == sparce_vector->Get_size());
}

void test_3_vector_sparce_vector() {
    int* a = new int[9];
    for (int i = 0; i < 9; i++) {
        a[i] = i * 5;
    }
    Sparce_vector<int>* sparce_vector = new Sparce_vector<int>(a, 9, compare_pairs);
    for (int i = 0; i < 9; i++) {
        assert(a[i] == sparce_vector->Get_sparce_vector()[i]);
    }
}

void test_4_count_sparce_vector() {
    int* a = new int[9];
    for (int i = 0; i < 9; i++) {
        a[i] = i * 5;
    }
    Sparce_vector<int>* sparce_vector = new Sparce_vector<int>(a, 9, compare_pairs);
    assert(9 == sparce_vector->Get_size());
}

void test_5_count_sparce_vector() {
    int* a = new int[1];
    for (int i = 0; i < 1; i++) {
        a[i] = i * 5;
    }
    Sparce_vector<int>* sparce_vector = new Sparce_vector<int>(a, 0, compare_pairs);
    assert(0 == sparce_vector->Get_size());
}

void TEST_ALL_SPARSE_VECTOR() {
    test_1_vector_sparce_vector();
    test_2_vector_sparce_vector();
    test_3_vector_sparce_vector();
    test_4_count_sparce_vector();
    test_5_count_sparce_vector();
}