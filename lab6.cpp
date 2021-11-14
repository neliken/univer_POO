#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::string;
using std::endl;
using std::list;

class Department;
class Operations_Staff;
class Person;
class Staff;

class Hospital {

    string name;
    string address;
    string phone;

    list <Person> personList;
    list <Department> departmentList;

};


class Person {

    string title;
    string givenName;
    string middleName;
    string familyName;
    string name;

    string birthDate;
    string gender;
    string homeAddress;
    string phone;

    list <Hospital> hospitalList;

};




class Patient: public Person {

    string id;
    string name;
    string gender;
    string birthDate;

    int age;
    string accepted;
    list <string> sickness;
    list <string> prescriptions;
    list <string> allergies;
    list <string> specialReqs;
    list <Operations_Staff> oprstaffList;

};




class Department {

    Hospital hospital;
    list <Staff> staffList;

};




class Staff : public Person {

    string joined;
    list <string> education;
    list <string> certification;
    list <string> languages;

};




class Operations_Staff : public Staff {

    list <Patient> patientList;

};




class Doctor : public Operations_Staff {

    list <string> speciality;
    list <string> locations;

};


class Nurse : public Operations_Staff {};

class Surgeon : public Doctor {};

class Administrative_Staff : public Staff {};

class Front_Desk_Staff : public Administrative_Staff {};

class Receptionist : public Front_Desk_Staff {};

class Technical_Staff : public Staff {};

class Technician : public Technical_Staff {};

class Technologist : public Technical_Staff {};

class Surgical_Technologist : public Technical_Staff {};


int main () {

    return 0; }
