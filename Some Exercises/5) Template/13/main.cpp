#include <iostream>
#include "Product.h"
#include "Customer.h"
#include "Employee.h"
#include "Storage.h"
#include <string>
#include "Product.cpp"
#include "Customer.cpp"
#include "Employee.cpp"
#include "Storage.cpp"

using namespace std;

int main()
{
    Product p1("Pencil" , 10);
    Product p2("Notebook" , 50);
    Employee e1("Alice" , 1000);
    Employee e2("Bob" , 1200);
    Customer c1("Charlie" , 300);
    Customer c2("David" , 500);

    Storage <Product , Employee> prodEmpStore;
    prodEmpStore.add(p1 , e1);
    prodEmpStore.add(p2 , e2);

    cout<<"Pencil managed by : "<< prodEmpStore.get(p1).name << "\n";

    prodEmpStore.update(p1 , Employee("Eve" , 1500));
    cout<<"Pencil updated manager : "<< prodEmpStore.get(p1).name<<endl;

    cout<<"Min Key Product : "<<prodEmpStore.minkey().name<<"\n";

    prodEmpStore.remove(p2);
    cout<<"Notebook exists  ? "<< ( (prodEmpStore.exists(p2)) ? "Yes" : "No") <<endl;

    Storage <Customer ,Product > custProdStore;
    custProdStore.add(c1 , p1);
    custProdStore.add(c2 , p2);
    cout<<"Charlie Purchased : "<< custProdStore.get(c1).name <<endl;

    return 0;
}