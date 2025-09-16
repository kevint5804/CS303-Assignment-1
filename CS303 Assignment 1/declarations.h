#include <string>

int getInputFile(const std::string& path, int arr[], int& size, int capacity);

bool findFirst(const int arr[], int size, int value, int& indexOutOfBounds);

int modify(int arr[], int size, int index, int newValue);

void addToEnd(int arr[], int& size, int capacity, int value);

int removeAt(int arr[], int& size, int index);