// #include <string>
// #include "linkedlist/singlylinkedlist.h"

// // ------------------- Student Struct -------------------
// struct Student {
//     int rollNo;
//     string name;
//     float marks;

//     Student() : rollNo(0), name(""), marks(0.0) {}
//     Student(int r, string n, float m) : rollNo(r), name(n), marks(m) {}

//     bool operator<(const Student& other) const { return rollNo < other.rollNo; }
//     bool operator==(const Student& other) const { return rollNo == other.rollNo; }
// };

// // Overload << for printing Student
// ostream& operator<<(ostream& os, const Student& s) {
//     os << "RollNo=" << s.rollNo << ", Name=" << s.name << ", Marks=" << s.marks;
//     return os;
// }


// // ------------------- Student Record System -------------------
// class StudentRecordSystem {
// private:
//     MySinglyLinkedList<Student> list;

//     Node<Student>* findNodeByRollNo(int rollNo) {
//         Node<Student>* ptr = list.head;
//         while (ptr != nullptr) {
//             if (ptr->data.rollNo == rollNo) return ptr;
//             ptr = ptr->next;
//         }
//         return nullptr;
//     }

//     int findIndexByRollNo(int rollNo) {
//         Node<Student>* ptr = list.head;
//         int index = 0;
//         while (ptr != nullptr) {
//             if (ptr->data.rollNo == rollNo) return index;
//             ptr = ptr->next;
//             index++;
//         }
//         return -1;
//     }

// public:
//     void insertAtHead(const Student& s) { list.insertAtHead(s); }
//     void insertAtTail(const Student& s) { list.insertAtTail(s); }

//     void insertAfterRollNo(int rollNo, const Student& s) {
//         int index = findIndexByRollNo(rollNo);
//         if (index == -1) { cout << "Roll number " << rollNo << " not found.\n"; return; }
//         list.insertAtPosition(s, index + 1);
//     }

//     void deleteByRollNo(int rollNo) { list.deleteValue(Student(rollNo, "", 0.0)); }

//     void display() {
//         if (list.isEmpty()) cout << "No student records.\n";
//         else list.display();
//     }

//     void searchByRollNo(int rollNo) {
//         Node<Student>* ptr = findNodeByRollNo(rollNo);
//         if (ptr) cout << "Found: " << ptr->data << "\n";
//         else cout << "Roll number " << rollNo << " not found.\n";
//     }

//     void updateByRollNo(int rollNo, const string& newName, float newMarks) {
//         int index = findIndexByRollNo(rollNo);
//         if (index == -1) { cout << "Roll number " << rollNo << " not found.\n"; return; }
//         list.updateNode(index, Student(rollNo, newName, newMarks));
//     }

//     void calculateStatistics() {
//         if (list.isEmpty()) { cout << "No student records.\n"; return; }
//         Node<Student>* ptr = list.head;
//         float sum = 0, maxMarks = ptr->data.marks, minMarks = ptr->data.marks;
//         int count = 0;
//         while (ptr != nullptr) {
//             sum += ptr->data.marks;
//             if (ptr->data.marks > maxMarks) maxMarks = ptr->data.marks;
//             if (ptr->data.marks < minMarks) minMarks = ptr->data.marks;
//             count++;
//             ptr = ptr->next;
//         }
//         cout << "Highest Marks: " << maxMarks << "\n";
//         cout << "Lowest Marks: " << minMarks << "\n";
//         cout << "Average Marks: " << (sum / count) << "\n";
//     }
// };

// // ------------------- Menu -------------------
// int main() {
//     StudentRecordSystem system;
//     int choice;

//     do {
//         cout << "\n--- Student Record Management ---\n";
//         cout << "1. Insert at head\n2. Insert at tail\n3. Insert after roll number\n4. Delete by roll number\n";
//         cout << "5. Display all students\n6. Search by roll number\n7. Update student record\n8. Statistics\n0. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         int rollNo, afterRoll;
//         string name;
//         float marks;

//         switch (choice) {
//         case 1:
//             cout << "Enter Roll No, Name, Marks: ";
//             cin >> rollNo >> ws;
//             getline(cin, name);
//             cin >> marks;
//             system.insertAtHead(Student(rollNo, name, marks));
//             break;
//         case 2:
//             cout << "Enter Roll No, Name, Marks: ";
//             cin >> rollNo >> ws;
//             getline(cin, name);
//             cin >> marks;
//             system.insertAtTail(Student(rollNo, name, marks));
//             break;
//         case 3:
//             cout << "Enter roll number after which to insert: ";
//             cin >> afterRoll;
//             cout << "Enter Roll No, Name, Marks: ";
//             cin >> rollNo >> ws;
//             getline(cin, name);
//             cin >> marks;
//             system.insertAfterRollNo(afterRoll, Student(rollNo, name, marks));
//             break;
//         case 4:
//             cout << "Enter Roll No to delete: ";
//             cin >> rollNo;
//             system.deleteByRollNo(rollNo);
//             break;
//         case 5:
//             system.display();
//             break;
//         case 6:
//             cout << "Enter Roll No to search: ";
//             cin >> rollNo;
//             system.searchByRollNo(rollNo);
//             break;
//         case 7:
//             cout << "Enter Roll No to update: ";
//             cin >> rollNo;
//             cout << "Enter new Name: ";
//             cin >> ws;
//             getline(cin, name);
//             cout << "Enter new Marks: ";
//             cin >> marks;
//             system.updateByRollNo(rollNo, name, marks);
//             break;
//         case 8:
//             system.calculateStatistics();
//             break;
//         case 0:
//             cout << "Exiting...\n";
//             break;
//         default:
//             cout << "Invalid choice!\n";
//         }

//     }
//     while (choice != 0);

//     return 0;
// }






























// #ifndef STUDENT_MANAGEMENT_H
// #define STUDENT_MANAGEMENT_H

// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <cmath>
// #include "mysinglylinkedlist.h"

// using namespace std;

// // Student structure containing roll number, name, and marks
// struct Student {
//     int rollNo;
//     string name;
//     double marks;

//     // Constructor
//     Student() : rollNo(0), name(""), marks(0.0) {}
//     Student(int roll, string n, double m) : rollNo(roll), name(n), marks(m) {}

//     // Overload operators for comparison and output
//     bool operator==(const Student& other) const {
//         return rollNo == other.rollNo;
//     }

//     bool operator<(const Student& other) const {
//         return rollNo < other.rollNo;
//     }

//     bool operator>(const Student& other) const {
//         return rollNo > other.rollNo;
//     }

//     friend ostream& operator<<(ostream& out, const Student& student) {
//         out << student.rollNo << " | " << setw(20) << left << student.name
//             << " | " << fixed << setprecision(2) << student.marks;
//         return out;
//     }
// };

// // Student Record Management System - Wrapper class around MySinglyLinkedList
// class StudentManagementSystem {
// private:
//     MySinglyLinkedList<Student> studentList;

// public:
//     // Constructor
//     StudentManagementSystem() {}

//     // ============ INSERT OPERATIONS ============
//     void Insert(int rollNo, string name, double marks) {
//         // Check if student with same roll number already exists
//         if (studentList.search(Student(rollNo, "", 0))) {
//             cout << "\n❌ ERROR: Student with Roll No. " << rollNo << " already exists!" << endl;
//             return;
//         }

//         // Validate inputs
//         if (rollNo <= 0) {
//             cout << "\n❌ ERROR: Roll number must be positive!" << endl;
//             return;
//         }

//         if (name.empty()) {
//             cout << "\n❌ ERROR: Name cannot be empty!" << endl;
//             return;
//         }

//         if (marks < 0 || marks > 100) {
//             cout << "\n❌ ERROR: Marks must be between 0 and 100!" << endl;
//             return;
//         }

//         // Create student object and insert in sorted order (by roll number)
//         Student newStudent(rollNo, name, marks);
//         studentList.insertSorted(newStudent);

//         cout << "\n✅ SUCCESS: Student record inserted successfully!" << endl;
//         cout << "   Roll No: " << rollNo << " | Name: " << name << " | Marks: " << marks << endl;
//     }

//     // ============ DELETE OPERATIONS ============
//     void Delete(int rollNo) {
//         if (studentList.isEmpty()) {
//             cout << "\n❌ ERROR: Student list is empty! Nothing to delete." << endl;
//             return;
//         }

//         // Search for student with given roll number
//         Student searchStudent(rollNo, "", 0);
//         if (!studentList.search(searchStudent)) {
//             cout << "\n❌ ERROR: Student with Roll No. " << rollNo << " not found!" << endl;
//             return;
//         }

//         // Delete the student record
//         studentList.deleteValue(searchStudent);
//         cout << "\n✅ SUCCESS: Student with Roll No. " << rollNo << " deleted successfully!" << endl;
//     }

//     // ============ DISPLAY OPERATIONS ============
//     void Display() {
//         if (studentList.isEmpty()) {
//             cout << "\n❌ The student list is empty. No records to display." << endl;
//             return;
//         }

//         cout << "\n" << string(70, '=') << endl;
//         cout << "                    STUDENT RECORDS" << endl;
//         cout << string(70, '=') << endl;
//         cout << left << setw(12) << "Roll No" << "| " << setw(20) << "Name" << "| " << "Marks" << endl;
//         cout << string(70, '-') << endl;

//         studentList.display();

//         cout << string(70, '=') << endl;
//     }

//     // ============ SEARCH OPERATIONS ============
//     void Search(int rollNo) {
//         if (studentList.isEmpty()) {
//             cout << "\nERROR: Student list is empty!" << endl;
//             return;
//         }

//         Student searchStudent(rollNo, "", 0);

//         if (studentList.search(searchStudent)) {
//             cout << "\n✅ FOUND: Student record located!" << endl;
//             cout << string(50, '-') << endl;
//             cout << "Roll No: " << rollNo << endl;

//             // Manual search to display full details
//             FindAndDisplayStudent(rollNo);
//             cout << string(50, '-') << endl;
//         }
//         else {
//             cout << "\n❌ ERROR: Student with Roll No. " << rollNo << " not found!" << endl;
//         }
//     }

//     // ============ UPDATE OPERATIONS ============
//     void Update(int rollNo, string newName = "", double newMarks = -1) {
//         if (studentList.isEmpty()) {
//             cout << "\n❌ ERROR: Student list is empty!" << endl;
//             return;
//         }

//         Student searchStudent(rollNo, "", 0);
//         if (!studentList.search(searchStudent)) {
//             cout << "\n❌ ERROR: Student with Roll No. " << rollNo << " not found!" << endl;
//             return;
//         }

//         if (newName.empty() && newMarks < 0) {
//             cout << "\n❌ ERROR: Nothing to update! Please provide name and/or marks." << endl;
//             return;
//         }

//         if (newMarks >= 0 && (newMarks < 0 || newMarks > 100)) {
//             cout << "\n❌ ERROR: Marks must be between 0 and 100!" << endl;
//             return;
//         }

//         // Find the node and update it
//         UpdateStudentRecord(rollNo, newName, newMarks);
//     }

//     // ============ STATISTICS OPERATIONS ============
//     void Statistics() {
//         if (studentList.isEmpty()) {
//             cout << "\n❌ ERROR: Student list is empty! Cannot calculate statistics." << endl;
//             return;
//         }

//         double highestMarks = -1, lowestMarks = 101, totalMarks = 0;
//         string topStudent = "", bottomStudent = "";
//         int count = 0;

//         CalculateStats(highestMarks, lowestMarks, totalMarks, topStudent, bottomStudent, count);

//         double averageMarks = totalMarks / count;

//         cout << "\n" << string(60, '=') << endl;
//         cout << "                  CLASS STATISTICS" << endl;
//         cout << string(60, '=') << endl;
//         cout << "Total Students: " << count << endl;
//         cout << "Highest Marks: " << fixed << setprecision(2) << highestMarks
//             << " (" << topStudent << ")" << endl;
//         cout << "Lowest Marks: " << fixed << setprecision(2) << lowestMarks
//             << " (" << bottomStudent << ")" << endl;
//         cout << "Average Marks: " << fixed << setprecision(2) << averageMarks << endl;
//         cout << string(60, '=') << endl;
//     }

//     // ============ HELPER FUNCTIONS (Private-like but inside class) ============
//     void FindAndDisplayStudent(int rollNo) {
//         // Helper function to display complete student details
//         // This manually traverses the list since we have access to head
//         if (studentList.head == nullptr) return;

//         Node<Student>* tempPtr = studentList.head;
//         while (tempPtr != nullptr) {
//             if (tempPtr->data.rollNo == rollNo) {
//                 cout << "Name: " << tempPtr->data.name << endl;
//                 cout << "Marks: " << fixed << setprecision(2) << tempPtr->data.marks << endl;
//                 return;
//             }
//             tempPtr = tempPtr->next;
//         }
//     }

//     void UpdateStudentRecord(int rollNo, string newName, double newMarks) {
//         Node<Student>* tempPtr = studentList.head;

//         while (tempPtr != nullptr) {
//             if (tempPtr->data.rollNo == rollNo) {
//                 cout << "\n✅ SUCCESS: Student record updated!" << endl;
//                 cout << "Previous Record:" << endl;
//                 cout << "  Name: " << tempPtr->data.name << " | Marks: " << tempPtr->data.marks << endl;

//                 if (!newName.empty()) {
//                     tempPtr->data.name = newName;
//                 }
//                 if (newMarks >= 0) {
//                     tempPtr->data.marks = newMarks;
//                 }

//                 cout << "Updated Record:" << endl;
//                 cout << "  Name: " << tempPtr->data.name << " | Marks: " << tempPtr->data.marks << endl;
//                 return;
//             }
//             tempPtr = tempPtr->next;
//         }
//     }

//     void CalculateStats(double& highest, double& lowest, double& total,
//         string& topStudent, string& bottomStudent, int& count) {
//         Node<Student>* tempPtr = studentList.head;

//         while (tempPtr != nullptr) {
//             double marks = tempPtr->data.marks;
//             total += marks;
//             count++;

//             if (marks > highest) {
//                 highest = marks;
//                 topStudent = tempPtr->data.name;
//             }
//             if (marks < lowest) {
//                 lowest = marks;
//                 bottomStudent = tempPtr->data.name;
//             }

//             tempPtr = tempPtr->next;
//         }
//     }

//     // Check if list is empty
//     bool IsEmpty() {
//         return studentList.isEmpty();
//     }
// };

// #endif // STUDENT_MANAGEMENT_H





// #include <iostream>
// #include <limits>
// #include <cctype>
// #include "studentmanagement.h"

// using namespace std;

// // Function to clear input buffer
// void clearInputBuffer() {
//     cin.clear();
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
// }

// // Function to display main menu
// void displayMainMenu() {
//     cout << "\n" << string(60, '=') << endl;
//     cout << "        STUDENT RECORD MANAGEMENT SYSTEM" << endl;
//     cout << string(60, '=') << endl;
//     cout << "\n1. Insert Student Record" << endl;
//     cout << "2. Delete Student Record" << endl;
//     cout << "3. Display All Records" << endl;
//     cout << "4. Search Student" << endl;
//     cout << "5. Update Student Record" << endl;
//     cout << "6. Display Statistics" << endl;
//     cout << "7. Exit" << endl;
//     cout << "\nEnter your choice (1-7): ";
// }

// // Function to safely get integer input
// int getIntInput(const string& prompt) {
//     int value;
//     while (true) {
//         cout << prompt;
//         if (cin >> value) {
//             clearInputBuffer();
//             return value;
//         }
//         else {
//             cout << "❌ Invalid input! Please enter a valid number." << endl;
//             clearInputBuffer();
//         }
//     }
// }

// // Function to safely get double input
// double getDoubleInput(const string& prompt) {
//     double value;
//     while (true) {
//         cout << prompt;
//         if (cin >> value) {
//             clearInputBuffer();
//             return value;
//         }
//         else {
//             cout << "❌ Invalid input! Please enter a valid number." << endl;
//             clearInputBuffer();
//         }
//     }
// }

// // Function to get string input
// string getStringInput(const string& prompt) {
//     string value;
//     cout << prompt;
//     getline(cin, value);
//     return value;
// }

// // Insert operation with user input
// void insertOperation(StudentManagementSystem& system) {
//     cout << "\n" << string(60, '-') << endl;
//     cout << "           INSERT STUDENT RECORD" << endl;
//     cout << string(60, '-') << endl;

//     int rollNo = getIntInput("Enter Roll Number: ");

//     string name = getStringInput("Enter Student Name: ");
//     if (name.empty()) {
//         cout << "❌ ERROR: Name cannot be empty!" << endl;
//         return;
//     }

//     double marks = getDoubleInput("Enter Marks (0-100): ");

//     system.Insert(rollNo, name, marks);
// }

// // Delete operation with user input
// void deleteOperation(StudentManagementSystem& system) {
//     cout << "\n" << string(60, '-') << endl;
//     cout << "           DELETE STUDENT RECORD" << endl;
//     cout << string(60, '-') << endl;

//     if (system.IsEmpty()) {
//         cout << "\n❌ ERROR: Student list is empty! Nothing to delete." << endl;
//         return;
//     }

//     cout << "\nCurrent Records:" << endl;
//     system.Display();

//     int rollNo = getIntInput("\nEnter Roll Number to delete: ");
//     system.Delete(rollNo);
// }

// // Search operation with user input
// void searchOperation(StudentManagementSystem& system) {
//     cout << "\n" << string(60, '-') << endl;
//     cout << "           SEARCH STUDENT RECORD" << endl;
//     cout << string(60, '-') << endl;

//     if (system.IsEmpty()) {
//         cout << "\n❌ ERROR: Student list is empty!" << endl;
//         return;
//     }

//     int rollNo = getIntInput("Enter Roll Number to search: ");
//     system.Search(rollNo);
// }

// // Update operation with user input
// void updateOperation(StudentManagementSystem& system) {
//     cout << "\n" << string(60, '-') << endl;
//     cout << "           UPDATE STUDENT RECORD" << endl;
//     cout << string(60, '-') << endl;

//     if (system.IsEmpty()) {
//         cout << "\n❌ ERROR: Student list is empty!" << endl;
//         return;
//     }

//     cout << "\nCurrent Records:" << endl;
//     system.Display();

//     int rollNo = getIntInput("\nEnter Roll Number to update: ");

//     cout << "\nWhat would you like to update?" << endl;
//     cout << "1. Update Name Only" << endl;
//     cout << "2. Update Marks Only" << endl;
//     cout << "3. Update Both Name and Marks" << endl;
//     cout << "Enter your choice (1-3): ";

//     int updateChoice;
//     cin >> updateChoice;
//     clearInputBuffer();

//     string newName = "";
//     double newMarks = -1;

//     switch (updateChoice) {
//     case 1:
//         newName = getStringInput("Enter new name: ");
//         system.Update(rollNo, newName, -1);
//         break;
//     case 2:
//         newMarks = getDoubleInput("Enter new marks (0-100): ");
//         system.Update(rollNo, "", newMarks);
//         break;
//     case 3:
//         newName = getStringInput("Enter new name: ");
//         newMarks = getDoubleInput("Enter new marks (0-100): ");
//         system.Update(rollNo, newName, newMarks);
//         break;
//     default:
//         cout << "❌ Invalid choice! Please try again." << endl;
//     }
// }

// // Demo function to populate with sample data
// void loadSampleData(StudentManagementSystem& system) {
//     cout << "\nLoading sample student data..." << endl;

//     system.Insert(101, "Ali Ahmed", 85.5);
//     system.Insert(105, "Fatima Khan", 92.0);
//     system.Insert(103, "Hassan Malik", 78.5);
//     system.Insert(102, "Ayesha Qureshi", 88.0);
//     system.Insert(104, "Usman Raza", 95.0);
//     system.Insert(106, "Zainab Ahmed", 81.5);

//     cout << "\n✅ Sample data loaded successfully!" << endl;
// }

// // Main function
// int main() {
//     StudentManagementSystem system;
//     int choice;
//     bool running = true;

//     cout << "\n" << string(70, '*') << endl;
//     cout << "*" << string(68, ' ') << "*" << endl;
//     cout << "*     WELCOME TO STUDENT RECORD MANAGEMENT SYSTEM" << string(20, ' ') << "*" << endl;
//     cout << "*     Powered by Singly Linked List Data Structure" << string(13, ' ') << "*" << endl;
//     cout << "*" << string(68, ' ') << "*" << endl;
//     cout << string(70, '*') << endl;

//     cout << "\nWould you like to load sample student data? (y/n): ";
//     char loadSample;
//     cin >> loadSample;
//     clearInputBuffer();

//     if (tolower(loadSample) == 'y') {
//         loadSampleData(system);
//     }

//     // Main menu loop
//     while (running) {
//         displayMainMenu();
//         cin >> choice;
//         clearInputBuffer();

//         switch (choice) {
//         case 1:
//             insertOperation(system);
//             break;

//         case 2:
//             deleteOperation(system);
//             break;

//         case 3:
//             system.Display();
//             break;

//         case 4:
//             searchOperation(system);
//             break;

//         case 5:
//             updateOperation(system);
//             break;

//         case 6:
//             system.Statistics();
//             break;

//         case 7:
//             cout << "\n" << string(60, '=') << endl;
//             cout << "Thank you for using Student Record Management System!" << endl;
//             cout << "Goodbye!" << endl;
//             cout << string(60, '=') << endl << endl;
//             running = false;
//             break;

//         default:
//             cout << "\n❌ Invalid choice! Please enter a number between 1 and 7." << endl;
//         }
//     }

//     return 0;
// }
