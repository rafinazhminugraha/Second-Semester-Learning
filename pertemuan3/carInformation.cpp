#include <iostream>

using namespace std;


struct CAR
{
    string brand;
    string type;
    string fuel;
    string year;
    int price;
    bool transmission;
};

CAR sport;
CAR family;

int main()
{
    family.brand = "Toyota";
    family.type = "avanza";
    family.fuel = "pertamax";
    family.year = "2018";
    family.price = 450000000;
    family.transmission = true;

    

    cout << "--------Car Information--------\n";
    cout << "\n Brand          : " << family.brand << "\n";
    cout << "\n Type           : " << family.type << "\n";
    cout << "\n Fuel           : " << family.fuel << "\n";
    cout << "\n Year           : " << family.year << "\n";
    cout << "\n Price          : Rp." << family.price << "\n";
    family.transmission ? cout << "\n Transmission   : " << "Yes\n" : cout << "\n Automation  : " << "No\n";
    cout << "\n--------------------------------\n";
}

