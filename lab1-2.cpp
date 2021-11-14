/*Advanced Level_ (mark 7 || 8):
    - Implement a program where you should create and and modify the following objects: `university` and `student`.
    You should be able to create students that have name, age and mark (from their courses) and also to create universities which have name,
    foundationYear and a list of students created earlier.

  - _Advanced Level_ (mark 9 || 10):
    - In main program you should be able to create 3 universities with some students in it and calculate the average media between them and print the result in console.*/
#include <iostream>
#include <list>
#include <string>
using namespace std;
class Student {
    string name;
    int age;
    float mark;

public:
    Student () {}
    Student (string name, int age, float mark) {
        this -> name = name;
        this -> age = age;
        this -> mark = mark; }

    void inputstudata();
    void displaystudata();

    float getMark() {
        return this -> mark; }
};

void Student::inputstudata() {
    cout<<"----------------------------------";
    cout<<"\n> Enter Student Name : "; fflush (stdin); cin >> this -> name;
    cout<<"\n> Enter Student Age : "; cin >> this -> age;

    cout << "\n> Enter Student Mark : "; cin >> mark; }

void Student::displaystudata() {
    cout<<"----------------------------------" << endl;
    cout<<"********** Student Data **********" << endl;
    cout<<"----------------------------------";
    cout<<"\n> Student Name : " << this -> name << endl;
    cout<<"\n> Student Age : "<< this -> age << endl; }

class University {
    string univerName;
    int foundationYear;
    list <Student> StudList;

public:
    University () {}
    University (string univerName, int foundationYear, list <Student> StudList) {
        this -> univerName = univerName;
        this -> foundationYear = foundationYear;
        this -> StudList = StudList; }

    void inputuniverdata();
    void displayuniverdata();

    float calculate () {

        if (this -> StudList.size() == 0) { return 0; }

        float s = 0;
        for (Student i : this -> StudList)
            s += i.getMark();

        return (float) s / this -> StudList.size(); }
} ;

void University::inputuniverdata() {
    Student temp;
    int n;
    cout<<"----------------------------------";
    cout<<"\n> Enter University Name : "; fflush (stdin); cin >> this -> univerName;
    cout<<"\n> Enter Foundation Year : "; cin >> this -> foundationYear;
    cout << "\n> Number of Students : "; cin >> n;

    for (int i = 0; i < n; i++) {
        temp.inputstudata();
        this -> StudList.push_back (temp); }
}

void University::displayuniverdata() {
    cout<<"----------------------------------" << endl;
    cout<<"******** University  Data ********" << endl;
    cout<<"----------------------------------" << endl;
    cout<<"> University Name : " << this -> univerName << endl << endl;
    cout<<"> Foundation Year : " << this -> foundationYear << endl << endl; }

int main() {

    University firstUniv;
    firstUniv.inputuniverdata();
    firstUniv.displayuniverdata();
    cout << "> Average : " << firstUniv.calculate () << endl;

    University secondUniv;
    secondUniv.inputuniverdata();
    secondUniv.displayuniverdata();
    cout << "> Average : " << secondUniv.calculate () << endl;

    University thirdUniv;
    thirdUniv.inputuniverdata();
    thirdUniv.displayuniverdata();
    cout << "> Average : " << thirdUniv.calculate () << endl;

    float generalMean = (float) ((firstUniv.calculate() + secondUniv.calculate() + thirdUniv.calculate()) / 3.0);
    cout << "> General average : " << generalMean << endl;

    return 0; }
