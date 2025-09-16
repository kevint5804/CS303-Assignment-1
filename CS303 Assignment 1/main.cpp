#include "declarations.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
const int arraySize = 111;


//Open the text file
int getInputFile(const string& path, int arr[], int& size, int capacity) {
    ifstream in(path.c_str());
    if (!in)
        throw runtime_error("Could not open file: " + path);

 //Reads all the integers in the file until the file ends
    int x = 0;
    int count = 0;
    while (in >> x) {
        arr[size++] = x;
        ++count;
    }
    return count;
}

//Checks if the input value is in the array or not
bool findNum(const int arr[], int size, int value, int& index) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            index = i;
            return true;
        }
    }
    return false;
}
//Changes the value at the index putted and replaces it with the new value inputted
int modify(int arr[], int size, int index, int newValue) {
    if (index < 0 || index >= size)
        throw out_of_range("Out of range");
    int oldVal = arr[index];
    arr[index] = newValue;
    return oldVal;
}

//Adds a new integer to the end of the array while updating the array size
void addToEnd(int arr[], int& size, int capacity, int value) {
    arr[size++] = value;
}

//Removes the value at the inputted index and shifts the integers on the right side of it to the left
int removeIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Out of range");
    int removed = arr[index];
    //Shifts to the left
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
    return removed;
}

int main() {
    int a[arraySize];
    int size = 0;
    string path;

    //Gets the string of the input file path
    cout << "Enter input file name: ";
    getline(cin, path);

    //Opens the text file and reads all the integers in the file until the file ends
    try {
        int loaded = getInputFile(path, a, size, arraySize);
        cout << "There are " << loaded << " integers.\n";
    }
    catch (const exception& e) {
        cout << "File Error: " << e.what() << "\n";
        return 1;
    }

    //ensures that the input is an integer and prompts the user if not
    cout << "Enter a number 1-100 to find its index: ";
    int firstNum;
    if (!(cin >> firstNum)) { 
        cout << "Invalid input.\n";
        return 0;
    }

    //Checks if the input value is in the array or not and returns the index
    int index;
    if (findNum(a, size, firstNum, index)) {
        cout << "Found " << firstNum << " at position " << index << "\n";
    }
    else {
        cout << firstNum << " not found.\n";
    }

    
    cout << "Enter an index and a number, respectively, to replace the value at index: ";
    try {
        int mIndex, newVal;

        //makes sure 2 integers are input
        if (!(cin >> mIndex >> newVal)) {
            throw invalid_argument("Invalid. You need two integers.");
        }
        //Changes the value at the index putted and replaces it with the new value inputted 
        int oldVal = modify(a, size, mIndex, newVal);
        cout << "Modified index " << mIndex << ": " << oldVal << " changed to " << newVal << "\n";
    }
    //prompts error
    catch (const exception& e) {
        cout << "Error handled: " << e.what() << "\n";
    }

    
    cout << "Enter a value to add to the end of the array: ";
    try {
        int numToAdd;
        if (!(cin >> numToAdd)) { //checks if user input is an int
            throw invalid_argument("Invalid. Please enter an integer."); 
        }
        addToEnd(a, size, arraySize, numToAdd); //adds user input to end of array 
        cout << "New size: " << size << "\n";
    }
    //prompts error
    catch (const exception& e) {
        cout << "Error handled: " << e.what() << "\n";
    }

    cout << "Enter an index to remove the value: ";
    int toRemove;
    if (cin >> toRemove) {
        try {
            int removed = removeIndex(a, size, toRemove); //removes value at the index inputted and shifts values to the right of it over to the left by 1, updates array size
            cout << "Removed value: " << removed << ". New array size: " << size << "\n";
        }
        catch (const exception& e) {
            cout << "Error handled: " << e.what() << "\n";
        }
    }

    cout << "Done.";
    return 0;
}
