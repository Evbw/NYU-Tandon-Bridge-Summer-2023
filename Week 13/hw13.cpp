#include <iostream>
#include <vector>
using namespace std;

const int GRIDSIZE = 20;
const int ANTS = 100;
const int DOODLEBUGS = 5;

class Organism;

class Grid {
    public:
        Grid (int row, int column);
        void initialize() {
            for ( int i = 0 ; i < GRIDSIZE ; i++ ) {
                for ( int j = 0 ; j < GRIDSIZE ; j++ ) {
                    cell[i][j] = nullptr;
                }
            }
        }
        Grid() {};
        void update();
        void display() const;

        int row;
        int column;
        Organism* cell[GRIDSIZE][GRIDSIZE];   

        ostream& operator <<(ostream& outs, const Grid& location);     
};

void Grid::display() const {
    for (int i = 0; i < GRIDSIZE; i++ ) {
        for (int j = 0; j < GRIDSIZE; j++ ) {
            if (cell[i][j] == nullptr) {
                cout<<'-';
            }
            else {
                cout<<*cell[i][j];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

class Organism {
    private:
        int x, y;
    public:
        Grid* cell;
        Organism(int x, int y, Grid* cell) : x(x), y(y), cell(cell) {};
        Organism() {};
        Grid get_location() const;
        virtual void move() = 0;
        virtual void breed() = 0;
        virtual void die() = 0;
        int get_x() const { return x; }
        int get_y() const { return y; }
        void set_x( int new_x ) const { x = new_x; }
        void set_y( int new_y ) const { y = new_y; }
};

class Ant : public Organism {
    private:
        int breedTimer = 3;
    public:
        Ant(int x, int y, Grid* cell) : x(x), y(y), cell(cell) {};
        Ant() {};
        void setAnt(Organism& cell) {};
        virtual void move(Grid& location);
        virtual void breed(int breedTimer);
        virtual void die(int starveTimer);
};

Ant::move() {
    int a = 0, b = 0;
    int direction = rand() % 4;
    Grid currentCell = get_cell();
    Grid nextCell = currentCell;

    switch (direction) {
        case 0:
            nextCell.row--;
            break;
        case 1:
            nextCell.col++;
            break;
        case 2:
            nextCell.row++;
            break;
        case 3:
            nextCell.col--;
            break;
    }
}

class Doodlebug : public Organism {
    private:
        int breedTimer = 8;
        int starveTimer = 3;
    public:
        Doodlebug(const Grid& cell) : cell(cell) {};
        Doodlebug() {};
        virtual void move() {};
        virtual void breed();
        virtual void die();
};

Doodlebug::move() {

}

int main() {

}