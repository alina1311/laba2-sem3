#include "Dictionary.h"
#include <cassert>


int compare_int_int_pairs(Dictionary<int, int>::Tpair_for_dict a,
    Dictionary<int, int>::Tpair_for_dict b) {
    if (a.key > b.key)
        return 1;
    return 0;
}

void test_1_count_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(compare_int_int_pairs);
    assert(0 == testing_dict->Count());
    testing_dict->Add(3, 14);
    testing_dict->Add(1, 14);
    testing_dict->Add(5, 141);
    assert(3 == testing_dict->Count());
    testing_dict->Add(6, 142);
    testing_dict->Add(8, 1213);
    assert(5 == testing_dict->Count());
}

void test_2_count_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(compare_int_int_pairs);
    testing_dict->Add(3, 14);
    testing_dict->Add(5, 14);
    testing_dict->Add(15, 14);
    assert(3 == testing_dict->Count());
    testing_dict->Add(3, 14);
    assert(3 == testing_dict->Count());
    testing_dict->Add(3, 1224);
    assert(3 == testing_dict->Count());
}

void test_3_add_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(compare_int_int_pairs);
    testing_dict->Add(3, 15);
    assert(1 == testing_dict->Count());
    testing_dict->Add(3, 15);
    testing_dict->Add(3, 15);
    testing_dict->Add(3, 15);
    assert(1 == testing_dict->Count());
}

void test_4_add_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(compare_int_int_pairs);
    testing_dict->Add(7, 362);
    testing_dict->Add(13, 52);
    testing_dict->Add(6161, -32);
    testing_dict->Add(3, 0);
    testing_dict->Add(8, 132);
    assert(testing_dict->Count() == 5);
}

void test_5_get_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(compare_int_int_pairs);
    testing_dict->Add(7, 362);
    testing_dict->Add(13, 52);
    testing_dict->Add(6161, -32);
    testing_dict->Add(3, 0);
    testing_dict->Add(8, 132);
    assert(132 == testing_dict->Get(8));
    assert(362 == testing_dict->Get(7));
    assert(0 == testing_dict->Get(3));
}

void test_6_contain_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(4, 5, compare_int_int_pairs);
    assert(testing_dict->ContainsKey(4));
    assert(!testing_dict->ContainsKey(2));
    testing_dict->Add(3, 14);
    assert(testing_dict->ContainsKey(3));
    assert(!testing_dict->ContainsKey(14));
}

void test_7_remove_dic() {
    Dictionary<int, int>* testing_dict = new Dictionary<int, int>(4, 5, compare_int_int_pairs);
    testing_dict->Add(7, 362);
    testing_dict->Add(13, 52);
    testing_dict->Add(6161, -32);
    testing_dict->Add(3, 0);
    testing_dict->Add(8, 132);
    assert(testing_dict->Count() == 6);
    testing_dict->Remove(13);
    assert(testing_dict->Count() == 5);
    testing_dict->Remove(13);
    assert(testing_dict->Count() == 5);
    testing_dict->Remove(19);
    assert(testing_dict->Count() == 5);
}

void TEST_ALL_DICTIONARY() {
    test_1_count_dic();
    test_2_count_dic();
    test_3_add_dic();
    test_4_add_dic();
    test_5_get_dic();
    test_6_contain_dic();
    test_7_remove_dic();
}