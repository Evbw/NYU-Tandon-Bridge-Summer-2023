#include <iostream>
#include <cstdlib>
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
        void move_organism(const Grid& currentCell, const Grid& nextCell);
        int row;
        int column;
        Organism* cell[GRIDSIZE][GRIDSIZE];   
};

class Organism {
    private:
        int x, y;
    public:
        Grid* cell;
        Organism(int x, int y, Grid* cell) : x(x), y(y), cell(cell) {};
        Organism() {};
        Grid get_location() { return *cell;}
        virtual void move() = 0;
        virtual void breed() = 0;
        virtual void die() = 0;
        // int get_x() const { return x; }
        // int get_y() const { return y; }
        // void set_x( int new_x ) { x = new_x; }
        // void set_y( int new_y ) { y = new_y; }
        virtual void print(ostream& outs) const = 0;
        friend ostream& operator <<(ostream& outs, const Organism& organism); 
};

ostream& operator<<(ostream& outs, const Organism& organism) {
    organism.print(outs);
    return outs;
}

class Ant : public Organism {
    private:
        int breedTimer = 3;
    public:
        Grid* cell;
        Ant(Grid* cell) : cell(cell) {};
        Ant() {};
        void setAnt(Organism& cell) {};
        virtual void move();
        // virtual void breed(int breedTimer);
        // virtual void die();
        virtual void print(ostream& outs) const;
};

void Ant::move() {
    int direction = rand() % 4;
    Grid currentCell = get_location();
    Grid nextCell = currentCell;

    switch (direction) {
        case 0:
            nextCell.row--;
            break;
        case 1:
            nextCell.column++;
            break;
        case 2:
            nextCell.row++;
            break;
        case 3:
            nextCell.column--;
            break;
        default:
            cout<<"Whoops"<<endl;
            exit(1);
    }

}

void Ant::print (ostream& outs) const {
    outs<<'o';
}

class Doodlebug : public Organism {
    private:
        int breedTimer = 8;
        int starveTimer = 3;
    public:
        Grid* cell;
        Doodlebug(Grid* cell) : cell(cell) {};
        Doodlebug() {};
        virtual void move();
        // virtual void breed();
        // virtual void die();
        virtual void print(ostream& outs) const;
};

void Doodlebug::move() {
    int direction = rand() % 4;
    Grid currentCell = get_location();
    Grid nextCell = currentCell;

    switch (direction) {
        case 0:
            nextCell.row--;
            break;
        case 1:
            nextCell.column++;
            break;
        case 2:
            nextCell.row++;
            break;
        case 3:
            nextCell.column--;
            break;
    }
}

void Doodlebug::print (ostream& outs) const {
    outs<<'X';
}

int main() {

    Grid grid;
    int time = 0;

    while (true) {
        cout<<"World at time "<<time<<endl;
        grid.display();
        time++;
    }
}

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