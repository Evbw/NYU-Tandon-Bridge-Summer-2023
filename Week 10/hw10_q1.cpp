#include <iostream>
using namespace std;

//Declare functions
string* createWordsArray(string sentence, int& outWordsArrSize);
void printArray(int* arr, int arrSize);

int main() {
   string line;
   int arrSize = 0;
   string* stringarr = new string;

   cout<<"Please enter a sentence: "<<endl;
   getline(cin, line);

   stringarr = createWordsArray(line, arrSize);

    delete [] stringarr;
    stringarr = nullptr;
}

void printArray(int* arr, int arrSize) {
    for ( int i = 0; i < arrSize; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string word;

}