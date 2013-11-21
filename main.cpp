#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ktree.hpp"

using namespace std;

int main(int argc, char** argv) {

    if (argc != 3) {
        cerr << "usage: " << argv[0] << " [k] [sequence]" << endl;
        return 1;
    }

    // set up tree
    ktree::node* tree = new ktree::node();

    size_t k = atoi(argv[1]);

    fstream infile(argv[2], fstream::in);
    // read each char in file
    char ch;
    string buf;

    while (buf.size() < k && infile.get(ch)) {
        buf.append(string(1, ch));
    }
    ktree::node* n = tree->addSequence(buf);

    uint64_t position = k;

    if (!n->data) {
        n->data = new vector<long>();
    }
    vector<uint64_t>* v = (vector<uint64_t>*) n->data;
    v->push_back(position);

    uint64_t bufcount = 1;

    while (infile.get(ch)) {

        buf = buf.substr(1) + string(1, ch);
        ++bufcount;
        ++position;
        n = tree->addSequence(buf);

        if (!n->data) {
            n->data = new vector<uint64_t>();
        }

        vector<uint64_t>* v = (vector<uint64_t>*) n->data;
        v->push_back(position);

    }

    // count the nodes in the tree
    /*
    cout << "kmers inserted: " << bufcount << endl;
    cout << "tree size: " << tree->size() << endl;
    cout << "tree leaves: " << tree->nLeaves() << endl;
    cout << "tree: " << endl;
    */
    tree->print();  // XML output of tree
    cout << endl;

    // we should clean up the tree..
    //delete tree;

    return 0;

}
