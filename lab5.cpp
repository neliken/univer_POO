#include <iostream>

using std::string;

class X {
private:
    string x;
public:
    X (string x): x (x) {}

    string x_text () {
        return x; }
};

class A {
protected:
    string a;
    X x = *new X ("clasa X");
public:
    A (string a, X x): a (a), x (x) {}
};

class B: protected A {
protected:
    string b;
public:
    B (string a, string b, X x): A (a, x), b (b) {}
};

class C: protected B {
protected:
    string c;
public:
    C (string a, string b, string c, X x): B (a, b, x), c (c) {}
};

class D: protected C {
protected:
    string d;
//    X x = *new X ("class D");
public:
    D (string a, string b, string c, string d, X x): C (a, b, c, x), d (d) {}
};

class E: protected D {
protected:
    string e;
public:
    E (string a, string b, string c, string d, string e, X x): D (a, b, c, d, x), e (e) {}
};

class F: protected E {
protected:
    string f;
public:
    F (string a, string b, string c, string d, string e, string f, X x): E (a, b, c, d, e, x), f (f) {}
};

class G: protected F {
protected:
    string g;
public:
    G (string a, string b, string c, string d, string e, string f, string g, X x): F (a, b, c, d, e, f, x), g (g) {}
};

class H: protected G {
protected:
    string h;
//private:
   // X x = *new X ("class H");
public:
    H (string a, string b, string c, string d, string e, string f, string g, string h, X x): G (a, b, c, d, e, f, g, x), h (h) {}

  //  friend class J;
};

class I: protected H {
protected:
    string i;
public:
    I (string a, string b, string c, string d, string e, string f, string g, string h, string i, X x): H (a, b, c, d, e, f, g, h, x), i (i) {}
};

class J: protected I {
protected:
    string j;
public:
    J (string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, X x): I (a, b, c, d, e, f, g, h, i, x), j (j) {}

    string print () {
        return (a + b + c + d + e + f + g + h + i + j + x.x_text () ); }
};

int main () {

    J obj = *new J ("a", "b", "c", "d", "e", "f", "g", "h", "i", "j", *new X ("xxx") );

    std::cout << obj.print ();

    return 0; }
