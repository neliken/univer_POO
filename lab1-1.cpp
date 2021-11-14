/*  - Create a program where you can manipulate a monitor object which has color, dimensions and resolution.
    Perform the following steps:
    1. Create a monitor.
    2. Update the monitor's properties.
    3. Create second monitor and then compare with first one created above.*/
#include <iostream>
#include <string>
using namespace std;

class Monitor{
    private:
    string color;
    int dimension;
    int resolution;

    public:
        void setColor(string setC){
        this->color = setC;
        }
    public:
        void setDimension(int setD){
        this->dimension = setD;
    }
    public:
        void setResolution(int setR){
        this->resolution = setR;
    }


    public:
        updateMonitor(string setC, int setD, int setR){
        this->color = setC;
        this->dimension = setD;
        this->resolution = setR;
        }
    public:
        string getColor(){
        return this->color;
    }
    public:
        int getDimension(){
        return this->dimension;
    }
    public:
        int getResolution(){
        return this->resolution;
    }
};

int main(){
    Monitor myMonitor1;

    myMonitor1.setColor("Red");
    myMonitor1.setDimension(1080);
    myMonitor1.setResolution(720);

    cout<<"The first monitor"<<endl;
    cout<<"The monitor color: "<< myMonitor1.getColor() <<endl;
    cout<<"The monitor dimension: "<< myMonitor1.getDimension() <<endl;
    cout<<"The monitor resolution: "<< myMonitor1.getResolution() <<endl;
    cout<<"\n\n";

    myMonitor1.updateMonitor("White", 1600, 1200);
    cout<<"The first monitor updated"<<endl;
    cout<<"The monitor color: "<< myMonitor1.getColor() <<endl;
    cout<<"The monitor dimension: "<< myMonitor1.getDimension() <<endl;
    cout<<"The monitor resolution: "<< myMonitor1.getResolution() <<endl;
    cout<<"\n\n";

    Monitor myMonitor2;
    myMonitor2.setColor("White");
    myMonitor2.setDimension(1600);
    myMonitor2.setResolution(1200);

    cout<<"The second monitor"<<endl;
    cout<<"The monitor color: "<< myMonitor2.getColor() <<endl;
    cout<<"The monitor dimension: "<< myMonitor2.getDimension() <<endl;
    cout<<"The monitor resolution: "<< myMonitor2.getResolution() <<endl;
    cout<<"\n\n";

    if(myMonitor1.getColor() == myMonitor2.getColor()){
        cout<<"Culoarea la monitoare este la fel";
     }else{
     cout<<"Culoarea la monitoare nu este la fel\n\n";
     }

     if(myMonitor1.getDimension()  == myMonitor2.getDimension()) {
        cout<<"\n\nDimensiunea la monitoare este la fel";
        cout<<"\n\n";
     }else{
     cout<<"Dimensiunea la monitoare nu este la fel";
     cout<<"\n\n";
     }

     if(myMonitor1.getResolution() == myMonitor2.getResolution()){
        cout<<"Resolutia la monitoare este la fel";
        cout<<"\n\n";
     }else{
     cout<<"Resolutia la monitoare nu este la fel";
     cout<<"\n\n";
     }
    return 0;
}
