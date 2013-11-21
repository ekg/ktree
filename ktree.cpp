#include "ktree.hpp"

using namespace std;

namespace ktree {

    // if i == s.size()-1 and 
    // if any children have the same label as s[i], add s to them
    // else, add a new node(this, s[i])

    node* node::addSequence(string& s, size_t i) {
        //cout << "adding " << s << " @ " << i << endl;
        // base case
        if (i == s.size())
            return this;
        // recursion
        node* mc = NULL; // matching child
        for (vector<node*>::iterator c = children.begin();
             c != children.end(); ++c) {
            if ((*c)->label == s[i]) {
                mc = *c; break;
            }
        }
        if (!mc) {
            mc = new node(s[i]);
            children.push_back(mc);
        }
        return mc->addSequence(s, i+1);
    }

    long int node::size(void) {
        long int s = 0;
        ++s; // count self
        for (vector<node*>::iterator c = children.begin();
             c != children.end(); ++c) {
            s += (*c)->size();
        }
        return s;
    }

    bool node::isLeaf(void) {
        return children.size() == 0;
    }

    /*
    bool node::isRoot(void) {
        return parent == NULL;

    }
    */

    long int node::nLeaves(void) {
        long int s = 0;
        if (isLeaf()) {
            ++s; // counts self if leaf
        } else {
            for (vector<node*>::iterator c = children.begin();
                 c != children.end(); ++c) {
                s += (*c)->size();
            }
        }
        return s;
    }

    void node::print(string p) {
        //cout << "node " << this << " " << label << " with " << children.size() << " children" << endl;
        cout << "<" << label << ">";
        if (isLeaf()) {
            if (!data) { cerr << "error, no data attached to leaf node" << endl; }
            vector<uint64_t>* v = (vector<uint64_t>*) data;
            vector<uint64_t>::iterator p = v->begin();
            cout << *p;
            for ( ;  p != v->end(); ++p) {
                cout << "," << *p;
            }
            //cout << p << label << endl;
        } else {
            string _p = p + string(1, label);
            for (vector<node*>::iterator c = children.begin();
                 c != children.end(); ++c) {
                (*c)->print(_p);
            }
        }
        cout << "</" << label << ">";
    }

}
