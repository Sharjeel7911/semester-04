#include "course.h"

int main() {
    Course<int>* cr1 = new OnlineCourse<int>(3, 40);
    Course<int>* cr2 = new OfflineCourse<int>(4, 8);

    cr1->duration();
    cr2->duration();

    cout << "\n\n";

    OnlineCourse<int>* cr3 = new OnlineCourse<int>(3, 30);
    OfflineCourse<int>* cr4 = new OfflineCourse<int>(3, 9);

    cr3->duration();
    cr4->duration();

    cout << "\n\n";

    cr3->area();
    cr4->area();

    delete cr1, delete cr2, delete cr3, delete cr4;
    return 0;
}