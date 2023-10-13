#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int GRIDSIZE = 20;
const int ANTS = 100;
const int DOODLEBUGS = 5;

class Organism;
class Ant;
class Doodlebug;

class Grid {
    public:
        Grid();
        Organism* getOrganism(const Grid* cell) const;
        void update();
        void display() const;
        void move_organism(const Grid& currentCell, const Grid& nextCell);
        friend ostream& operator<<(ostream& outs, const Grid& cell);
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
        // virtual void breed() = 0;
        // virtual void die() = 0;
        int get_x() const { return x; }
        int get_y() const { return y; }
        void set_x( int new_x ) { x = new_x; }
        void set_y( int new_y ) { y = new_y; }
        virtual void print(ostream& outs) const = 0;
        friend ostream& operator <<(ostream& outs, const Organism& organism);
};

ostream& operator <<(ostream& outs, const Organism& organism) {
    organism.print(outs);
    return outs;
}

class Ant : public Organism {
    private:
        int breedTimer = 3;
    public:
        Grid* cell;
        Ant(Grid* cell) : Organism(get_x(), get_y(), cell) {};
        Ant(int x, int y, Grid* cell) : Organism(x, y, cell) {};
        Ant() {};
        void setAnt(Organism& cell) {};
        virtual void move();
        // virtual void breed(int breedTimer);
        // virtual void die();
        virtual void print(ostream& outs) const override;
};

class Doodlebug : public Organism {
    private:
        int breedTimer = 8;
        int starveTimer = 3;
    public:
        Grid* cell;
        Doodlebug(Grid* cell) : Organism(get_x(), get_y(), cell) {};
        Doodlebug(int x, int y, Grid* cell) : Organism(x, y, cell) {};
        Doodlebug() {};
        virtual void move();
        // virtual void breed();
        // virtual void die();
        virtual void print(ostream& outs) const override;
};

int main() {
    srand(time(NULL));
    Grid grid;
    int time = 0;

    while (true) {
        cout<<"World at time "<<time<<endl;
        grid.display();
        cout<<endl;
        time++;
    }
    return 0;
}

Grid::Grid () {
    for ( int i = 0 ; i < GRIDSIZE ; i++ ) {
        for ( int j = 0 ; j < GRIDSIZE ; j++ ) {
            cell[i][j] = nullptr;
        }
    }

    for ( int i = 0; i < DOODLEBUGS; i++ ) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;

        while (cell[x][y] != nullptr) {
            x = rand() % GRIDSIZE;
            y = rand() % GRIDSIZE;
        }

        cell[x][y] = new Doodlebug(x, y, this);
    }

    for ( int i = 0; i < ANTS; i++ ) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;

        while (cell[x][y] != nullptr) {
            x = rand() % GRIDSIZE;
            y = rand() % GRIDSIZE;
        }

        cell[x][y] = new Ant(x, y, this);
    }
}

ostream& operator<<(ostream& outs, const Grid& cell) {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (cell.cell[i][j] == nullptr) {
                outs << '-';
            }
            else {
                outs<<*(cell.cell[i][j]);
            }
            outs <<' ';
        }
        outs<<endl;
    }
    return outs;
}

void Grid::display() const {
    for (int i = 0; i < GRIDSIZE; i++ ) {
        for (int j = 0; j < GRIDSIZE; j++ ) {
            if (cell[i][j] == nullptr) {
                cout<<'-';
            }
            else {
                cell[i][j]->print(cout);
            }

            cout<<' ';
        }
        cout<<endl;
    }
}

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

// void Ant::breed(int breedTimer) {
//     if ( breedTimer <= 0 ) {

//     }
// }

void Ant::print (ostream& outs) const {
    outs<<'o';
}

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
        default:
            cout<<"Whoopsy doodle(bug)"<<endl;
            exit(1);
    }
}

void Doodlebug::print (ostream& outs) const {
    outs<<'X';
}