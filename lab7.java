//part 1-2
package com.company;
import java.util.Collections; // Framework pentru manipularea obiectelor
import java.util.Comparator; // Pentru compararea obiectelor
import java.util.List; // Modul pentru lucrul cu listele

//Import static java.lang.Math.*; // Va importa toți membrii statici ai clasei Math. Nu-i sens sa importam toata clasa Math si toate metodele, daca avem nevoie doar de pow si pi
import static java.lang.Math.pow; // Importam functia pow ()
import static java.lang.Math.PI; // Importam variabila PI

abstract class GeometricBody {
    abstract double getSurface (); // In c++ double getSurface () = 0;
    abstract double getVolume (); // In c++ double getVolume () = 0;
}

class Cub extends GeometricBody { // In c++ mostenirea = extends
    double length;

    public Cub (double length) {
        this.length = length;
    }

    public double getSurface() {
        return 6 * (pow (this.length, 2) );
    }

    public double getVolume() {
        return pow (this.length, 3);
    }
}

class Sphere extends GeometricBody {
    double radius;

    public Sphere (double radius) {
        this.radius = radius;
    }

    public double getSurface() {
        return 4 * PI * pow (this.radius, 2);
    }

    public double getVolume() {
        return 4 * PI * pow (this.radius, 3) / 3;
    }
}

class Parallelepiped extends GeometricBody {
    double width;
    double length;
    double height;

    public Parallelepiped (double width, double length, double height) {
        this.width = width;
        this.length = length;
        this.height = height;
    }

    public double getSurface() {
        return 2 * (this.length * this.height + this.width * this.height + this.length * this.width);
    }

    public double getVolume() {
        return this.length * this.width * this.height;
    }
}

class GeometricBodyController {
    public double maxVolume (List <GeometricBody> maxVol) { // Lista ca parametru
        GeometricBody maxV =  Collections.max (maxVol, Comparator.comparing (GeometricBody::getVolume) ); // Apelam metoda Collections.max () care va compara
        return maxV.getVolume (); // obiectele doar dupa metoda getVolume ()
    }
    public double maxSurface (List <GeometricBody> maxSur) {
        GeometricBody maxS = Collections.max(maxSur, Comparator.comparing(GeometricBody::getSurface));
        return maxS.getSurface();
    }
}

public class Main {

    public static void main(String[] args) {

        GeometricBody cub = new Cub (24);
        GeometricBody sphere = new Sphere (12);
        GeometricBody parallelepiped = new Parallelepiped (3, 4, 5);

        GeometricBody[] arr = {cub, sphere, parallelepiped}; // Array de obiecte

        GeometricBodyController control = new GeometricBodyController (); // Obiect de tip GeometricBodyController
        System.out.println ("Max Volume : " + control.maxVolume (List.of (arr) ) );
        System.out.println ("Max Surface : " + control.maxSurface (List.of (arr) ) );
    }
}
//part 3
package com.company;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

import static java.lang.Math.pow;
import static java.lang.Math.PI;

interface GeometricBody { // Din abstract in interface
    double getSurface (); // Metodele nu-s abstracte
    double getVolume ();
}

class Cub implements GeometricBody { // Extends in implements
    double length;

    public Cub (double length) {
        this.length = length;
    }

    public double getSurface() {
        return 6 * (pow (this.length, 2) );
    }

    public double getVolume() {
        return pow (this.length, 3);
    }
}

class Sphere implements GeometricBody { // Extends in implements
    double radius;

    public Sphere (double radius) {
        this.radius = radius;
    }

    public double getSurface() {
        return 4 * PI * pow (this.radius, 2);
    }

    public double getVolume() {
        return 4 * PI * pow (this.radius, 3) / 3;
    }
}

class Parallelepiped implements GeometricBody { // Extends in implements
    double width;
    double length;
    double height;

    public Parallelepiped (double width, double length, double height) {
        this.width = width;
        this.length = length;
        this.height = height;
    }

    public double getSurface() {
        return 2 * (this.length * this.height + this.width * this.height + this.length * this.width);
    }

    public double getVolume() {
        return this.length * this.width * this.height;
    }
}

class GeometricBodyController {
    public double maxVolume (List <GeometricBody> maxVol) {
        GeometricBody maxV =  Collections.max (maxVol, Comparator.comparing (GeometricBody::getVolume) );
        return maxV.getVolume ();
    }
    public double maxSurface (List <GeometricBody> maxSur) {
        GeometricBody maxS =  Collections.max (maxSur, Comparator.comparing (GeometricBody::getSurface) );
        return maxS.getSurface ();
    }
}

public class Main {

    public static void main(String[] args) {

        GeometricBody cub = new Cub (24);
        GeometricBody sphere = new Sphere (12);
        GeometricBody parallelepiped = new Parallelepiped (3, 4, 5);

        GeometricBody[] arr = {cub, sphere, parallelepiped};

        GeometricBodyController control = new GeometricBodyController ();
        System.out.println ("Max Volume : " + control.maxVolume (List.of (arr) ) );
        System.out.println ("Max Surface : " + control.maxSurface (List.of (arr) ) );
    }
}
