#ifndef ktree_hpp
#define ktree_hpp

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>

using namespace std;

namespace ktree {

    class node {

    public:

        char label;
        void* data;
        //node* parent;
        vector<node*> children;
        //bool isRoot(void);
        bool isLeaf(void);
        //void addChild(node*);
        long int size(void);
        long int nLeaves(void);
        void print(string p = "");

        /*
        node(char c,
             node* p)
            : label(c)
            , parent(p)
            { }
        */
        node(char c) : label(c), data(NULL) { }

        node(void) // root node constructor
            : label('Z')
            //, parent(NULL)
            , data(NULL)
            { }

        node(const node& n) {
            label = n.label;
            //parent = n.parent;
            children = n.children;
        }

        ~node(void) {
            for (vector<node*>::iterator c = children.begin();
                 c != children.end(); ++c) {
                delete *c;
            }
        }

        // adds sequence to tree.  node* t points to the node corresponding to the last
        // node in the sequence's path through the labeled tree.
        node* addSequence(string& s, size_t i = 0);

        // returns the last node matched by t.  n is set to the number of matched characters in the path.
        node* findSequence(string& s, int& n, size_t i = 0);

    };

}

#endif
