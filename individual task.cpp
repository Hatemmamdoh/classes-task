#include <iostream>
#include <string>

using namespace std;
class Person
{
public:
    Person()
    {
      name = "None" ;
    }
    Person(string PersonName)
    {
    name = PersonName ;
    }
    Person (const Person& theObject ): name(theObject.name) {}
    string getName()
    {
      return name ;
    }
    print ()
    {
        cout << "The Owner Name :" << name << endl ;
    }

private:
    string name;
};
class Vehicle
{
  protected :
      string manufacturer ;
      int cyl ;
      Person owner ;
  public :

    Vehicle () : manufacturer ("None") , cyl (0) {}
    Vehicle (string m , int c  ) : manufacturer (m) , cyl (c) {}
    Vehicle(const Vehicle& theObject) : manufacturer (theObject.manufacturer) , cyl(theObject.cyl) , owner (theObject.owner) {} ;

    void setManufacturerName ( string Manufacturer )
     {
        manufacturer = Manufacturer ;
     }
     void setCylnumber (int Cyl)
     {
       cyl = Cyl ;
     }
     void setPersonOwner ( Person p )
     {
       owner = p ;
     }
     string getManufacturerName ()
     {
        return manufacturer ;
     }
     int getCylnumber ()
     {
       return cyl ;
     }
     PrintInformation ()
     {
       cout << " ManufacturerName :" << manufacturer << "\n" << "Cylnumber : " << cyl << "\n"  << endl ;
     }
};
class truck : public Vehicle
{
  private :
      double loadCapacity ;
      int towingCapacity ;
  public :
    truck () : loadCapacity(0.0),towingCapacity(0), Vehicle() {}
    truck (string m, int cyl, double load, int tow ) : loadCapacity (load) , towingCapacity(tow) , Vehicle( m, cyl) {}
    truck(const truck& theObject) : loadCapacity(theObject.loadCapacity), towingCapacity(theObject.towingCapacity), Vehicle(theObject) {};


    void setloadCapacity (double l)
    {
      loadCapacity = l ;
    }
    void settowingCapacity (int t)
    {
      towingCapacity = t ;
    }
    gettowingCapacity ()
    {
      return towingCapacity ;
    }
    getloadCapacity ()
    {
      return loadCapacity ;
    }
    PrintInformation ()
    {
      cout << "ManufacturerName :" << manufacturer << "\n" << "Cylnumber : " << cyl << "\n"  << "load capacity in tons : " << loadCapacity << "\n" << "towing capacity in pounds : " << towingCapacity << endl  ;
    }

};

int main()
{
    string ownerName;
    string manufacturerName;
    int numCyl;
    double loadcapacity ;
    int towingcapacity ;
    cout << "First create 3 trucks..." << endl;
    cout << "\n" ;
    cout << "|--------------------------------------------------------------|" << endl ;
    cout << " " << "First We will Print Truck A Information with mutator functions " << endl ;
    cout << "|--------------------------------------------------------------|" ;
    cout << "\n" << "\n" ;
    cout << "Please enter the information of Truck B to create it : " << endl ;
    cout << "Truck A ... " << endl;
    cout << "Enter the name of the owner: ";
    cin >> ownerName;
    cout << "Enter the number of cylinders: ";
    cin >> numCyl;
    cout << "Enter the name of the manufacturer: ";
    cin >> manufacturerName;
    cout << "Enter the load capacity in tons : " ;
    cin >> loadcapacity ;
    cout << "Enter The towing capacity in pounds : " ;
    cin >> towingcapacity ;
    Person ownerA (ownerName) ;
    truck TruckA  ;

    // create Truck A with mutator functions

    cout << "\n" ;
    cout << "|-----------|" << endl ;
    cout << "  Truck A : " << " " << endl ;
    cout << "|-----------|" ;
    cout << "\n" << "\n" ;
    TruckA.setloadCapacity (loadcapacity) ;
    TruckA.settowingCapacity (towingcapacity) ;
    TruckA.setCylnumber (numCyl) ;
    TruckA.setManufacturerName (manufacturerName) ;
    ownerA.print() ;
    TruckA.PrintInformation () ;

    // Create truck B With constructor
    cout << "\n" ;
    cout << "|---------------------------------------------------------------------------------|" << endl ;
    cout << "    " << "Now we will create Truck B with Constructor and print it's information " << endl ;
    cout << "|---------------------------------------------------------------------------------|" ;
    cout << "\n" << "\n" ;
    cout << "Please enter the information of Truck B to create it : " << endl ;
    cout << "Truck B ... " << endl ;
    cout << "Enter the name of the owner: ";
    cin >> ownerName;
    cout << "Enter the number of cylinders: ";
    cin >> numCyl;
    cout << "Enter the name of the manufacturer: ";
    cin >> manufacturerName;
    cout << "Enter the load capacity in tons : " ;
    cin >> loadcapacity ;
    cout << "Enter The towing capacity in pounds : " ;
    cin >> towingcapacity ;
    cout << "\n" ;
    cout << "|-----------|" << endl ;
    cout << "  Truck B : " << " " << endl ;
    cout << "|-----------|" ;
    cout << "\n" << "\n" ;
    Person ownerB (ownerName) ;
    truck TruckB (manufacturerName , numCyl , loadcapacity , towingcapacity) ;
    ownerB.print() ;
    TruckB.PrintInformation () ;
    cout << "\n" ;
    cout << "\n" ;
    cout << "|--------------------------------------------------------------|" << endl ;
    cout << "        " << "Now we will create Truck C as a copy of Truck A "  << endl ;
    cout << "|--------------------------------------------------------------|" << endl ;

    // Create Truck C as copy of truck A with copy constructor
    Person ownerc(ownerA) ;
    truck TruckC(TruckA);
    cout << "\n" ;
    cout << "|-----------|" << endl ;
    cout << "  Truck C : " << " " << endl ;
    cout << "|-----------|" ;
    cout << "\n" << "\n" ;
    ownerc.print() ;
    TruckC.PrintInformation () ;

    // use Assignment operator to copy the contents of Truck B in truck A
    cout << "\n" ;
    cout << "\n" ;
    cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl ;
    cout << "    " << "Now we will Copy the contents of Truck B in Truck A with assignment operator and print Truck A after changes "  << endl ;
    cout << "|-----------------------------------------------------------------------------------------------------------------------|" << endl ;
    TruckA = TruckB ;
    ownerA = ownerB ;


    cout << "\n" ;
    cout << "|-----------|" << endl ;
    cout << "  Truck A : " << " " << endl ;
    cout << "|-----------|" ;
    cout << "\n" << "\n" ;
    ownerA.print() ;
    TruckA.PrintInformation () ;

    return 0;
}
