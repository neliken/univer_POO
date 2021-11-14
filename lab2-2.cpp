#include <iostream>
#include <string>
#include <list>
using namespace std;

class Queue {
    int marime;
    int max_size;
    bool is_limited;
    list <int> elements;

public:

    Queue () {
        this -> marime = 0;
        this -> is_limited = false; }

    Queue (int max_size) {
        this -> marime = 0;
        this -> is_limited = true;
        this -> max_size = max_size; }

    bool is_empty () {
        return this -> marime == 0 ? true : false; }

    bool is_full () {
        if (this -> is_limited == false)
            cout << "Queue is never full" << endl;

        return this -> marime == this -> max_size; }

    int size () {
        return this -> marime; }

    int front () {
        return this -> elements.front(); }

    int back () {
        return this -> elements.back(); }

    void push (int value) {

        if (this -> is_limited && this -> marime == this -> max_size)
            return;

        this -> elements.push_back (value);
        this -> marime++; }

    void pop () {

        this -> elements.pop_front ();
        this -> marime--; }
} ;

int main () {

    Queue first_queue (3);
    first_queue.push (1);
    first_queue.push (2);
    first_queue.push (3);

    cout << " " << first_queue.front () << endl;

    while (!first_queue.is_empty() ) {
        cout << " " << first_queue.front();
        first_queue.pop(); }
    cout << endl;

    Queue second_queue;
    second_queue.is_full ();

    return 0; }
