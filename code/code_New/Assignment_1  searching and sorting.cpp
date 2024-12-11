
#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    float sgpa;
};

void bubbleSortByRoll(Student students[], int n){
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - i - 1; ++j){
            if (students[j].rollNo > students[j + 1].rollNo) swap(students[j], students[j + 1]);
        }
    }
}

void insertionSortByName(Student students[], int n) {
    for (int i = 1; i < n; ++i) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].name > key.name)
        {
            students[j + 1] = students[j];
            --j;
        }
        students[j + 1] = key;
    }
}

int partition(Student students[], int low, int high){
    float pivot = students[high].sgpa; // At the end of this process, the pivot is placed in its correct sorted position.
    int i = low - 1;
    for (int j = low; j < high; ++j){
        if (students[j].sgpa > pivot){
            ++i;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSortBySGPA(Student students[], int low, int high){
    if (low < high){
        int pi = partition(students, low, high);
        quickSortBySGPA(students, low, pi - 1);
        quickSortBySGPA(students, pi + 1, high);
    }
}

void printStudents( Student students[], int n){
    for (int i = 0; i < n; ++i){
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }
}

void searchBySGPA( Student students[], int n, float sgpa)
{
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (students[i].sgpa == sgpa){
            cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            found = true;
        }
    }
    if (not found) cout << "No student found with SGPA: " << sgpa << endl;
}

int binarySearchByName( Student students[], int n,  string &name){
    int low = 0, high = n - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (students[mid].name == name) return mid;
        else if (students[mid].name < name) low = mid + 1;
        else    high = mid - 1;
    }
    return -1;
}

int main(){
    int n = 10;
    Student students[n] = {
        {101, "Vishal", 9.1}, {102, "pratic", 8.3}, {103, "prath", 9.4}, {104, "David", 8.9}, {105, "Rathna", 9.7}, {106, "Soni", 8.6}, {107, "Aniket", 9.2}, {108, "ankit", 9.8}, {109, "Lilian", 8.4}, {110, "fuck", 9.3}};

    cout << "Students sorted by Roll Number (Bubble Sort):" << endl;
    bubbleSortByRoll(students, n);
    printStudents(students, n);

    cout << "\nStudents sorted by Name (Insertion Sort):" << endl;
    insertionSortByName(students, n);
    printStudents(students, n);

    cout << "\nTop 10 students by SGPA (Quick Sort):" << endl;
    quickSortBySGPA(students, 0, n - 1);
    for (int i = 0; i < min(10, n); ++i)
    {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
    }

    float sgpaToSearch;
    cout << "\nEnter SGPA to search: ";
    cin >> sgpaToSearch;
    searchBySGPA(students, n, sgpaToSearch);

    string nameToSearch;
    cout << "\nEnter name to search: ";
    cin >> nameToSearch;
    insertionSortByName(students, n); // Ensure sorted by name for binary search
    int index = binarySearchByName(students, n, nameToSearch);
    if (index != -1)
    {
        cout << "Student found: Roll No: " << students[index].rollNo << ", Name: " << students[index].name << ", SGPA: " << students[index].sgpa << endl;
    }
    else
    {
        cout << "Student with name " << nameToSearch << " not found." << endl;
    }
}
