#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int rollNumber;

public:
    Person() : name(""), rollNumber(0) {}
    
    Person(const string& name, int rollNumber) : name(name), rollNumber(rollNumber) {}

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Student : public virtual Person {
protected:
    string course1, course2, course3;

public:
    Student() : course1(""), course2(""), course3("") {}

    Student(const string& name, int rollNumber, const string& course1, const string& course2, const string& course3)
        : Person(name, rollNumber), course1(course1), course2(course2), course3(course3) {}

    void displayStudent() {
        Person::displayPerson();
        cout << "Courses taken: " << course1 << ", " << course2 << ", " << course3 << endl;
    }
};

class ResearchStudent : public virtual Person {
protected:
    string researchArea, course;

public:
    ResearchStudent() : researchArea(""), course("") {}

    ResearchStudent(const string& name, int rollNumber, const string& course, const string& researchArea)
        : Person(name, rollNumber), course(course), researchArea(researchArea) {}

    void displayResearchStudent() {
        Person::displayPerson();
        cout << "Course taken: " << course << endl;
        cout << "Research Area: " << researchArea << endl;
    }
};

class TeachingAssistant : public Student, public ResearchStudent {
protected:
    string role;

public:
    TeachingAssistant() : role("") {}

    TeachingAssistant(const string& name, int rollNumber, const string& course1, const string& course2, const string& course3, 
                      const string& assignedCourse, const string& role)
        : Student(name, rollNumber, course1, course2, course3), ResearchStudent(name, rollNumber, assignedCourse, ""),
          role(role) {}

    TeachingAssistant(const string& name, int rollNumber, const string& course, const string& researchArea, const string& assignedCourse, const string& role)
        : Student(name, rollNumber, "", "", ""), ResearchStudent(name, rollNumber, assignedCourse, researchArea),
          role(role) {}

    void displayTeachingAssistant() {
        cout << "Teaching Assistant Info:" << endl;
        cout << "Role: " << role << endl;
        if (role == "Student") {
            displayStudent();
            cout << "Assigned Course: " << ResearchStudent::course << endl;
        }
        else if (role == "ResearchStudent") {
            displayResearchStudent();
            cout << "Assigned Course: " << ResearchStudent::course << endl;
        }
    }
};

int main() {
    string name, course, researchArea, assignedCourse, role;
    int rollNumber;

    cout << "Enter TA details:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Roll Number: ";
    cin >> rollNumber;
    cout << "Role (Student/ResearchStudent): ";
    cin >> role;

    if (role == "Student") {
        cout << "Enter 3 courses (separated by spaces): ";
        cin >> course;
    }
    else if (role == "ResearchStudent") {
        cout << "Enter research area: ";
        cin >> researchArea;
    }

    cout << "Enter assigned course: ";
    cin >> assignedCourse;

    TeachingAssistant ta(name, rollNumber, course, researchArea, assignedCourse, role);
    
    cout << "Teaching Assistant Details:" << endl;
    ta.displayTeachingAssistant();

    return 0;
}
