#include <iostream>
#include <string>
#include "test_Sorted_seq.h"
#include "test_sorts.h"
#include "test_BST.h"
#include "test_dictionary.h"
#include "test_sparce_vector.h"
#include "test_histogram.h"
#include "Search_often_sub.h"

int compare_string_int(Tpair_for_dict<string, int> a, Tpair_for_dict<string, int> b) {
    if (a.key > b.key)
        return 1;
    return 0;
}


int main()
{
    TEST_ALL_SORTED_SEQ();
    TEST_ALL_SORTS();
    TEST_ALL_BST();
    TEST_ALL_DICTIONARY();
    TEST_ALL_SPARCE_VECTOR();
    TEST_ALL_HISTOGRAM();
    
    ArraySequence<char> arr;
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('a');
    arr.Append('a');
    arr.Append('b');
    arr.Append('a');
    arr.Append('b');
    arr.Append('c');
    arr.Append('a');
    arr.Append('c');
    arr.Append('a');

    Sequence<char>* seq;
    seq = &arr;

    Search_often_sub blyat(seq, 2, 3, compare_string_int);//, bubble_sort, compare_sorted_decrease);
    cout << blyat.Get("abc") << endl;
    cout << blyat.Get("ca") << endl;
    cout << blyat.Get("bab") << endl;
    cout << blyat.Get("ab") << endl;
    cout << blyat.Get_max_count() << "  "  << endl;
    blyat.print();
    cout << "dadadadawddawd" << endl;
    Sequence<Tpair_for_dict<string, int>>* new_seq = blyat.output_seq();
    print_seq(new_seq);
    cout << blyat.Get_max_count() << endl;
    print_seq(blyat.Get_max());
    return 0;
}
