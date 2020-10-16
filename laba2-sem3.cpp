#include <iostream>
#include <string>
#include "test_Sorted_seq.h"
#include "test_sorts.h"
#include "test_BST.h"
#include "test_dictionary.h"
#include "test_sparce_vector.h"
#include "test_histogram.h"





int main()
{
    TEST_ALL_SORTED_SEQ();
    TEST_ALL_SORTS();
    TEST_ALL_BST();
    TEST_ALL_DICTIONARY();
    TEST_ALL_SPARCE_VECTOR();
    TEST_ALL_HISTOGRAM();
    

    return 0;
}
