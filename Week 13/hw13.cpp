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
        Organism();
        virtual void move();
        virtual void breed();
        virtual void die();
};

class Ant {
    private:
        int breed;
        int starve;
    public:
        Ant(const Grid& position);
        Ant();
        virtual void move();
        virtual void breed();
        virtual void die();
};

class Doodlebug {
    private:
        int breed;
        int starve;
    public:
        Doodlebug(const Grid& position);
        Doodlebug();
        virtual void move();
        virtual void breed();
        virtual void die();
};