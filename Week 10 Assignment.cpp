#include <iostream>
using namespace std;

class Employee {
protected:
    string fname;
    char initial;
    string lname;

public:
    Employee(string f, char i, string l)
        : fname(f), initial(i), lname(l) {}

    virtual double getSalary() = 0;

    virtual void display() {
        cout << fname << " " << initial << ". " << lname << endl;
    }
};

class SalaryEmployee : public Employee {
    double salary;

public:
    SalaryEmployee(string f, char i, string l, double s)
        : Employee(f, i, l), salary(s) {}

    double getSalary() {
        return salary;
    }
};

class HourlyEmployee : public Employee {
    int hours;
    double rate;

public:
    HourlyEmployee(string f, char i, string l, int h, double r)
        : Employee(f, i, l), hours(h), rate(r) {}

    double getSalary() {
        return hours * rate;
    }
};

int main() {
    Employee* e1 = new SalaryEmployee("John", 'A', "Doe", 50000);
    Employee* e2 = new HourlyEmployee("Jane", 'B', "Smith", 160, 300);

    e1->display();
    cout << "Salary: " << e1->getSalary() << endl << endl;

    e2->display();
    cout << "Salary: " << e2->getSalary() << endl;

    delete e1;
    delete e2;

    return 0;
}