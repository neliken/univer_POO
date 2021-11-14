#include <iostream>
#include <string>
#include <list>

using namespace std;

class Box {
    double height;
    double width;
    double depth;

public:

    Box () {
        this -> height = this -> width = this -> depth = 1; }

    Box (double height) {
        this -> height = height;
        this -> width = this -> depth = 3.5; }

    Box (double height, double width, double depth) {
        this -> height = height;
        this -> width = width;
        this -> depth = depth; }

    void display () {
        cout << "\t>> Height : " << this -> height << endl;
        cout << "\t>> Width : " << this -> width << endl;
        cout << "\t>> Depth : " << this -> depth << endl; }

    double area () {
        return (double) (width * height + height * depth + width * depth) * 2; }

    double volume () {
        return width * height * depth; }
};

int main () {

    Box b1;
    cout << ">> Box 1" << endl;
    b1.display();
    cout << "\t>> Area of Box 1 : " << b1.area() << endl << "\t>> Volume of Box 1 : " << b1.volume() << endl << endl;

    Box b2 (3.5);
    cout << ">> Box 2" << endl;
    b2.display();
    cout << "\t>> Area of Box 2 : " << b2.area() << endl << "\t>> Volume of Box 2 : " << b2.volume() << endl << endl;

    Box b3 (4, 8, 12);
    cout << ">> Box 3" << endl;
    b3.display();
    cout << "\t>> Area of Box 3 : " << b3.area() << endl << "\t>> Volume of Box 3 : " << b3.volume() << endl << endl;

    return 0; }
