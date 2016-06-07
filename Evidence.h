#include "Traits.h"

#include <bitset>
#include <istream>
#include <cctype>

class Evidence
{
    // Negative and positive evidence.
    std::bitset<(int)trait_count> pos;
    std::bitset<(int)trait_count> neg;
    
  public:
    Evidence() {}
    // Initialize the pos and neg bit vectors from the given integers.
    Evidence(int pos, int neg) : pos(pos), neg(neg) {}

    bool isAmbiguous(Traits which)
    { return isAmbiguous((int)which); }

    bool isAmbiguous(unsigned int which)
    { return !pos[which] && !neg[which]; }

    bool isTrue(Traits which)
    { return isTrue((int) which); }

    bool isTrue(unsigned int which)
    { return pos[which] && !neg[which]; }

    bool isFalse(Traits which)
    { return isFalse((int) which); }

    bool isFalse(unsigned int which)
    { return !pos[(int) which] && neg[(int) which]; }

    bool isConflicting(Traits which)
    { return isConflicting((int) which); }

    bool isConflicting(unsigned int which)
    { return pos[(int) which] && neg[(int) which]; }

    void addpos(Traits which)
    { addpos((int) which); }

    void addpos(unsigned int which)
    { pos.set(which); }
    
    void addneg(Traits which)
    { addneg((int) which); }

    void addneg(unsigned int which)
    { neg.set(which); }

    unsigned int size()
    { return (int) trait_count;}

    friend std::istream& operator>>(std::istream& is, Evidence& e);
};

// Reads in evidence from a stream.
// Traits are expected to be separated by white space.
// The result of an trial on each trait are represented by one of the following.
//  + positive evidence
//  - negative evidence
//  * conflicting evidence
//  0 no evidence
std::istream& operator>>(std::istream& is, Evidence& e) {
    char c;
    for (unsigned int i = 0; i < e.size(); ++i) {
        while (!is.eof()) {
            is >> c;
            // Skip any leading white space
            if (isspace(c)) continue;
        }
        switch(c) {
          default:
            // Treat junk as conflicting.
            // (fallthrough)
          case '*':
            e.addpos(i);
            e.addneg(i);
            break;
          case '0':
            // do nothing
            break;
          case '+':
            e.addpos(i);
            break;
          case '-':
            e.addneg(i);
            break;
        }
    }
    return is;
}
