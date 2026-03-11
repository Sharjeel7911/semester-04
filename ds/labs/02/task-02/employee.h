#include <iostream>
using namespace std;

template <class T>
class Employee {
public:
    virtual T calculateSalary() = 0;
};

//------------------------------------------------------------------------------------

template <class T>
class FullTimeEmployee : public Employee<T> {
private:
    T fixedSal;
public:
    FullTimeEmployee(T);
    T calculateSalary();
};

template <class T>
FullTimeEmployee<T>::FullTimeEmployee(T fixedSal) {
    this->fixedSal = fixedSal;
}

template <typename T>
T FullTimeEmployee<T>::calculateSalary() {
    return fixedSal;
}

//-----------------------------------------------------------------------------------

template <class T>
class PartTimeEmployee : public Employee<T> {
private:
    T hoursWorked;
    T hourlyRate;
public:
    PartTimeEmployee(T, T);
    T calculateSalary();
};

template <class  T>
PartTimeEmployee<T>::PartTimeEmployee(T hoursWorked, T hourlyRate) {
    this->hoursWorked = hoursWorked;
    this->hourlyRate = hourlyRate;
}

template <typename T>
T PartTimeEmployee<T>::calculateSalary() {
    return hourlyRate * hoursWorked;
}