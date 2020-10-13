#pragma once
#include "BST.h"


template<class Tkey, class Telement>
class Dictionary {
public:
    struct Tpair_for_dict {
        Tkey key;
        Telement element;
    };

private:
    BST<Tpair_for_dict>* tree;
    int (*cmp)(Tpair_for_dict, Tpair_for_dict);

public:
    Dictionary(Tkey keys, Telement elements, int (*cmp)(Tpair_for_dict, Tpair_for_dict)) {
        this->tree = new BST<Tpair_for_dict>(cmp);
        Tpair_for_dict initial{ keys, elements };
        this->tree->insert(initial);
        this->cmp = cmp;
    }

    Dictionary(int (*cmp)(Tpair_for_dict, Tpair_for_dict)) {
        this->tree = new BST<Tpair_for_dict>(cmp);
        this->cmp = cmp;
    }

    ~Dictionary() {
        delete tree;
    }

    int Count() {
        return tree->check_count();
    }

    Telement Get(Tkey input_key) {
        Tpair_for_dict for_search_pair;
        for_search_pair.key = input_key;
        if (tree->search(for_search_pair))
            return tree->what_in_node(tree->search(for_search_pair)).element;
        throw out_of_range(IndexOutOfRangeEx);
    }

    bool ContainsKey(Tkey input_key) {
        Tpair_for_dict for_contain_pair;
        for_contain_pair.key = input_key;
        if (tree->search(for_contain_pair))
            return 1;
        return 0;
    }

    void Add(Tkey input_key, Telement input_element) {
        Tpair_for_dict for_add_pair{ input_key, input_element };
        tree->insert(for_add_pair);
    }

    void Remove(Tkey input_key) {
        Tpair_for_dict for_remove_pair;
        for_remove_pair.key = input_key;
        int length = tree->check_count();
        tree->delete_item(for_remove_pair);
    }

    void Print() {
        vector<Tpair_for_dict>* vector_print = tree->LKP();
        for (size_t i = 0; i < vector_print->size(); i++) {
            cout << (*vector_print)[i].key << " - " <<
                (*vector_print)[i].element << endl;
        }
    }
};