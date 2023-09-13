#ifndef _die_h_
#define _die_h_

class Die {
    int n;
    int sides;
public:
    int get_n() const { return n; }
    int roll(int num) {
        this->sides = num;
        this->n = rand() % this->sides + 1;
        return n;
    }
    friend ostream& operator<<(ostream& os, Die& d) {
        return os << d.n;
    }

};
#endif // !_die_h_
