#include <iostream>
#include <vector>
using namespace std;

class Organism;

class Grid {
    public:
        Grid (int row, int column);
        void initialize();
        void update();
        void display() const;
    private:
        int row;
        int column;
        vector<Organism*> cell;
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

int main() {

}

void Grid::initialize() {
    for ( int i ; i < 20 ; i++ ) {
        for ( int j ; j < 20 ; j++ ) {
            cell.push_back(nullptr);
        }
    }
}