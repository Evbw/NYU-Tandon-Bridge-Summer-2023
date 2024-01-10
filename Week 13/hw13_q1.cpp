#include <iostream>
#include <vector>

// For Gem Random Number For Position
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int getRandomInRange(int min, int max);

int getRandomInRange(int min, int max) {
    return rand() % (max - min + 1) + min;
}
// Organism

class Organism {
    pair<int, int> position = make_pair(0, 0);
    int ageCounter = 0;
    int breedCounter = 0;
    bool isDead = false;

   public:
    Organism(){};
    pair<int, int> getPosition() { return position; };
    void setPosition(pair<int, int> pos) { position = pos; };
    virtual void growUp() {
        ageCounter += 1;
        breedCounter += 1;
    }
    virtual bool canBreed() const { return breedCounter >= 3; };
    bool isOrganismDead() { return isDead; }
    void kill() { isDead = true; }
    // This virtual function defines how an organism moves.
    // It should return a pair of integers representing the movement offset.
    // The first element in the pair corresponds to the vertical offset, and the second element to the horizontal offset.
    // By default, organisms can move in four directions: up (-1, 0), down (1, 0), left (0, -1), and right (0, 1).
    // For example, if the organism wants to move up and to the right in one step, it should return (-1, 1).
    virtual pair<int, int> move() {
        vector<std::pair<int, int>> defaultMove = {
            make_pair(-1, 0),  // Move up
            make_pair(1, 0),   // Move down
            make_pair(0, -1),  // Move left
            make_pair(0, 1)    // Move right
        };
        return defaultMove[getRandomInRange(0, defaultMove.size() - 1)];
    };
    int getBreedCounter() const {
        return breedCounter;
    };
    void setBreedCounter(int count) {
        breedCounter = count;
    };
};
// Ant

class Ant : public Organism {
   public:
    Ant() : Organism(){};
    bool canBreed() const override { return getBreedCounter() >= 3; };
    Ant Breed() {
        setBreedCounter(0);
        Ant newAnt;
        return newAnt;
    }
};
// Doodlebug

class Doodlebug : public Organism {
    int starveCounter = 0;

   public:
    Doodlebug() : Organism(){};
    void eatAnt() { starveCounter = 0; }
    void growStarve() { starveCounter += 1; };
    bool canBreed() const override { return getBreedCounter() >= 8; };
    bool isStarve() const { return starveCounter >= 3; };
    Doodlebug Breed() {
        setBreedCounter(0);
        Doodlebug newDoodlebug;
        return newDoodlebug;
    }
};

class Cell {
    // Organism* organismPtr; // segmentation fault
    Ant* antPtr;
    Doodlebug* doodlebugPtr;

   public:
    Cell() : antPtr(nullptr), doodlebugPtr(nullptr){};
    bool isEmpty() { return antPtr == nullptr && doodlebugPtr == nullptr; };
    bool isAntIn() { return antPtr != nullptr; };
    bool isDoodlebugIn() { return doodlebugPtr != nullptr; };
    Ant* getAntPtr() { return antPtr; };
    Doodlebug* getDoodlebugPtr() { return doodlebugPtr; };
    void cleanCell() {
        if (!isEmpty()) {
            antPtr = nullptr;
            doodlebugPtr = nullptr;
        }
    }
    void replaceWith(Ant* ptr) {
        cleanCell();
        antPtr = ptr;
    }
    void replaceWith(Doodlebug* ptr) {
        cleanCell();
        doodlebugPtr = ptr;
    }
};

class PlayGround {
    vector<vector<Cell>> grid;
    vector<Doodlebug> doodlebugs;
    vector<Ant> ants;
    void assignInitPosition();

   public:
    PlayGround() {}
    PlayGround(int areaColumn, int areaRow, int doodlebugAmount, int antAmount = 0) {
        grid.resize(areaColumn, vector<Cell>(areaRow));
        doodlebugs.resize(doodlebugAmount);
        ants.resize(antAmount);
        assignInitPosition();
    }
    vector<pair<int, int>> getEmptyCellAround(pair<int, int> curr);
    void movedoodlebugs();
    void breedDoodlebugs();
    void checkDoodlebugsStatus();
    void moveAnts();
    void breedAnts();
    bool checkGameIsEnd();
    void printMap();
};
void PlayGround::assignInitPosition() {
    int maxColumn = this->grid.size() - 1;
    int maxRow = this->grid[0].size() - 1;
    for (int i = 0; i < this->doodlebugs.size(); i++) {
        bool gotCell = false;
        while (!gotCell) {
            int column = getRandomInRange(0, maxColumn);
            int row = getRandomInRange(0, maxRow);
            Cell& cell = this->grid[column][row];
            if (cell.isEmpty()) {
                cell.replaceWith(&this->doodlebugs[i]);
                this->doodlebugs[i].setPosition(make_pair(column, row));
                // cout << "BUG CELL: " << column << "-" << row << endl;
                gotCell = true;
            }
        }
    }
    for (int i = 0; i < this->ants.size(); i++) {
        bool gotCell = false;
        while (!gotCell) {
            int column = getRandomInRange(0, maxColumn);
            int row = getRandomInRange(0, maxRow);
            Cell& cell = this->grid[column][row];
            cout << column << row << cell.isEmpty() << endl;
            if (cell.isEmpty()) {
                cell.replaceWith(&this->ants[i]);
                this->ants[i].setPosition(make_pair(column, row));
                // cout << "ANT CELL: " << column << "-" << row << endl;

                gotCell = true;
            }
        }
    }
}
vector<pair<int, int>> PlayGround::getEmptyCellAround(pair<int, int> curr) {
    vector<pair<int, int>> directions = {
        make_pair(-1, 0),  // Move up
        make_pair(1, 0),   // Move down
        make_pair(0, -1),  // Move left
        make_pair(0, 1)    // Move right
    };
    vector<pair<int, int>> temp;
    for (int i = 0; i < directions.size(); i++) {
        int targetColumn = curr.first + directions[i].first;
        int targetRow = curr.second + directions[i].second;

        if ((targetColumn < 0 || targetColumn >= this->grid.size()) || (targetRow < 0 || targetRow >= this->grid[0].size())) {
        } else {
            if (this->grid[targetColumn][targetRow].isEmpty()) {
                temp.push_back(make_pair(targetColumn, targetRow));
            }
        }
    }
    return temp;
}

void PlayGround::movedoodlebugs() {
    for (int i = 0; i < this->doodlebugs.size(); i++) {
        Doodlebug& currBug = this->doodlebugs[i];
        bool isEatAnt = false;
        if (currBug.isOrganismDead())
            continue;

        pair<int, int> direction = currBug.move();
        pair<int, int> currPosition = currBug.getPosition();

        int targetColumn = direction.first + currPosition.first;
        int targetRow = direction.second + currPosition.second;
        if ((targetColumn < 0 || targetColumn >= this->grid.size()) || (targetRow < 0 || targetRow >= this->grid[0].size())) {
            // target position out of grid range.
        } else {
            if (!this->grid[targetColumn][targetRow].isEmpty()) {
                if (this->grid[targetColumn][targetRow].isAntIn()) {
                    // Eat Ant.
                    this->grid[targetColumn][targetRow].getAntPtr()->kill();
                    this->grid[targetColumn][targetRow].replaceWith(&currBug);
                    currBug.eatAnt();
                    currBug.setPosition(make_pair(targetColumn, targetRow));
                    this->grid[currPosition.first][currPosition.second].cleanCell();
                    isEatAnt = true;
                } else {
                    // target position is a doodlebug
                }
            } else {
                this->grid[targetColumn][targetRow].replaceWith(&currBug);
                currBug.setPosition(make_pair(targetColumn, targetRow));
                this->grid[currPosition.first][currPosition.second].cleanCell();
            }
        }
        currBug.growUp();
        if (!isEatAnt)
            currBug.growStarve();
    }
}
void PlayGround::breedDoodlebugs() {
    for (int i = 0; i < this->doodlebugs.size(); i++) {
        Doodlebug& currBug = this->doodlebugs[i];

        if (currBug.isOrganismDead())
            continue;

        if (currBug.canBreed()) {
            vector<pair<int, int>> spaces = getEmptyCellAround(currBug.getPosition());
            if (spaces.size() > 0) {
                pair<int, int> bornPosition = spaces[getRandomInRange(0, spaces.size() - 1)];
                Doodlebug newBug = currBug.Breed();
                newBug.setPosition(bornPosition);
                this->grid[bornPosition.first][bornPosition.second].replaceWith(&newBug);
                doodlebugs.push_back(newBug);
            }
        }
    }
}
void PlayGround::checkDoodlebugsStatus() {
    for (int i = 0; i < this->doodlebugs.size(); i++) {
        Doodlebug& currBug = this->doodlebugs[i];

        if (currBug.isOrganismDead())
            continue;

        if (currBug.isStarve()) {
            currBug.kill();
            pair<int, int> currPosition = currBug.getPosition();
            this->grid[currPosition.first][currPosition.second].cleanCell();
        }
    }
}
void PlayGround::moveAnts() {
    for (int i = 0; i < this->ants.size(); i++) {
        Ant& currAnt = this->ants[i];
        if (currAnt.isOrganismDead())
            continue;

        pair<int, int> direction = currAnt.move();
        pair<int, int> currPosition = currAnt.getPosition();

        int targetColumn = direction.first + currPosition.first;
        int targetRow = direction.second + currPosition.second;
        if ((targetColumn < 0 || targetColumn >= this->grid.size()) || (targetRow < 0 || targetRow >= this->grid[0].size())) {
            // target position out of grid range.
        } else {
            if (!this->grid[targetColumn][targetRow].isEmpty()) {
                // target position is not empty

            } else {
                this->grid[targetColumn][targetRow].replaceWith(&currAnt);
                currAnt.setPosition(make_pair(targetColumn, targetRow));
                this->grid[currPosition.first][currPosition.second].cleanCell();
            }
        }
        currAnt.growUp();
    }
}
void PlayGround::breedAnts() {
    for (int i = 0; i < this->ants.size(); i++) {
        Ant& currAnt = this->ants[i];

        if (currAnt.isOrganismDead())
            continue;

        if (currAnt.canBreed()) {
            vector<pair<int, int>> spaces = getEmptyCellAround(currAnt.getPosition());
            if (spaces.size() > 0) {
                pair<int, int> bornPosition = spaces[getRandomInRange(0, spaces.size() - 1)];
                Ant newAnt = currAnt.Breed();
                newAnt.setPosition(bornPosition);
                this->grid[bornPosition.first][bornPosition.second].replaceWith(&newAnt);
                ants.push_back(newAnt);
            }
        }
    }
}
void PlayGround::printMap() {
    const char ANT_CHAR = 'o';
    const char DOODLEBUG_CHAR = 'X';
    const char EMPTY_SPACE_CHAR = '-';
    for (int i = 0; i < this->grid.size(); i++) {
        for (int j = 0; j < this->grid[0].size(); j++) {
            Cell cell = this->grid[i][j];
            char sign;
            if (cell.isEmpty()) {
                sign = EMPTY_SPACE_CHAR;
            } else if (cell.isAntIn()) {
                sign = ANT_CHAR;
            } else if (cell.isDoodlebugIn()) {
                sign = DOODLEBUG_CHAR;
            }
            cout << sign << (j == this->grid[0].size() - 1 ? "\n" : " ");
        }
    }
    cout << endl;
}
bool PlayGround::checkGameIsEnd() {
    int livingAnts = 0;
    int livingDoodlebugs = 0;
    for (int i = 0; i < this->ants.size(); i++) {
        if (!this->ants[i].isOrganismDead()) {
            livingAnts++;
        }
    }

    for (int i = 0; i < this->doodlebugs.size(); i++) {
        if (!this->doodlebugs[i].isOrganismDead()) {
            livingDoodlebugs++;
        }
    }

    if (livingAnts == 0) {
        cout << "All Ants die. Dominant by Doodlebugs.\n";
        return true;

    } else if (livingDoodlebugs == 0) {
        cout << "All Doodlebugs die. Dominant by Ants.\n";
        return true;
    } else {
        return false;
    }
}
// Main
void setupGameEnv(int& areaColumn, int& areaRow, int& doodlebugAmount, int& antAmount);
void startGame(PlayGround& playGround);

int main() {
    srand(time(0));

    int areaColumn = 20;
    int areaRow = 20;
    int doodlebugAmount = 5;
    int antAmount = 100;
    // setupGameEnv(areaColumn, areaRow, doodlebugAmount, antAmount);

    PlayGround playGround = PlayGround(areaColumn, areaRow, doodlebugAmount, antAmount);

    startGame(playGround);
    return 0;
}

void setupGameEnv(int& areaColumn, int& areaRow, int& doodlebugAmount, int& antAmount) {
    int height;
    int width;
    int doodlebugCount;
    int antCount;
    cout << "Please Enter The Initialize Grid's Size (Example 20 height * 15 width area: 20 15):\n";
    cin >> height >> width;
    cout << endl;

    cout << "Please Enter The Initialize Predators's Amount & Ant's Amount (Example 5 Predators & 100 Ants: 5 100):\n";
    cin >> doodlebugCount >> antCount;
    cout << endl;

    areaColumn = height;
    areaRow = width;
    doodlebugAmount = doodlebugCount;
    antAmount = antCount;
}

void startGame(PlayGround& playGround) {
    int step = 0;
    bool isEnd = false;

    while (!isEnd) {
        cout << "Step Counter: " << step << endl
             << endl;
        if (step != 0) {
            playGround.movedoodlebugs();
            playGround.breedDoodlebugs();
            playGround.checkDoodlebugsStatus();

            playGround.moveAnts();
            playGround.breedAnts();
        }
        playGround.printMap();
        if (playGround.checkGameIsEnd()) {
            isEnd = true;
            break;
        }

        step += 1;
        cout << "Enter Any Value To Continue, -1 To Leave.\n";
        string input;
        cin >> input;
        if (input == "-1")
            isEnd = true;
    }
}
