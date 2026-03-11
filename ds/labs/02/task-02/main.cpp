#include "employee.h"

int main() {
    FullTimeEmployee<int>* em1 = new FullTimeEmployee<int>(10000);
    PartTimeEmployee<int>* em2 = new PartTimeEmployee<int>(40, 400);

    cout << "Salary of full time: " << em1->calculateSalary();
    cout << endl;
    cout << "Salary of part time: " << em2->calculateSalary();
    cout << endl;

    delete em1, delete em2;
    return 0;
}