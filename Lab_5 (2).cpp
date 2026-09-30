#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string food_name;
    char code;
    int quantity;
    double price;
    char member;
    string yeno;
    double total;
    double tax;
    double sub_total;
    double discount;
    double taxp;
    string notes;


    cout << "Enter the food name: ";
    cin >> food_name;

    cout << "Enter the item code: ";
    cin >> code;

    cout << "How many fruits: ";
    cin >> quantity;

    cout << "What is the price: ";
    cin >> price;

    cout << "Are you a member(y/n): ";
    cin >> member;




    cout << right << setw(9) << food_name << endl;
    cout << right << setw(7) << code << endl;
    cout << right << setw(7) << quantity << endl;
    cout << right << setw(9) << setprecision(2) << fixed << price << endl;
    cout << right << setw(7) << member << endl;

    sub_total = price * quantity;
    discount = .1 * sub_total;
    tax = 0.06;

    if (member == 'y') {
        sub_total = sub_total - discount;
        taxp = tax * sub_total;
        total = sub_total + taxp;
    }
    else {
        tax = tax * sub_total;
        total = sub_total;
    }

    cout << right << setw(9) << setprecision(2) << fixed << total << endl;
    cout << "Enter cashier notes: " << endl;;
    getline(cin, notes);

    cout << right << setw(8) << "Notes: " << notes << endl;

    cout << left << setw(18) << "Pears" << endl;
    cout << right << setw(6) << 20 << endl;
    cout << right << setw(7) << 4.99 << endl;

    cout << left << setw(18) << "Apples" << endl;
    cout << right << setw(6) << 20 << endl;
    cout << right << setw(7) << 5.99 << endl;

}