#include <iostream>
using namespace std;

template <class T>
class Course {
public:
    virtual void duration() = 0;
};

//-------------------------------------------------------------------------------------

template <class T>
class OnlineCourse : public Course<T> {
private:
    T weeks;
    T hourPerWeek;
public:
    OnlineCourse(T, T);
    void duration();
    void area();
};

template <class T>
OnlineCourse<T>::OnlineCourse(T weeks, T hourPerWeek) {
    this->weeks = weeks;
    this->hourPerWeek = hourPerWeek;
}

template <typename T>
void OnlineCourse<T>::duration() {
    cout << "Weeks: " << weeks << ", Hours per week: " << hourPerWeek << endl;
}

template <typename T>
void OnlineCourse<T>::area() {
    cout << "This is area function of online." << endl;
}

//-------------------------------------------------------------------------------------

template <class T>
class OfflineCourse : public Course<T> {
private:
    T months;
    T hoursPerDay;
public:
    OfflineCourse(T, T);
    void duration();
    void area();
};

template <class T>
OfflineCourse<T>::OfflineCourse(T months, T hoursPerDay) {
    this->months = months;
    this->hoursPerDay = hoursPerDay;
}

template <typename T>
void OfflineCourse<T>::duration() {
    cout << "Months: " << months << ", Hours per day: " << hoursPerDay << endl;
}

template <typename T>
void OfflineCourse<T>::area() {
    cout << "This is area function of offline." << endl;
}