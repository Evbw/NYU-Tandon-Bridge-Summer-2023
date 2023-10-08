#include <iostream>
#include <vector>

class Grid {
    public:
        int row;
        int column;
};

class Organism {
    private:

    public:
        Organism(const Grid& position);
        virtual void move();
        virtual void breed();
        virtual void die();
};