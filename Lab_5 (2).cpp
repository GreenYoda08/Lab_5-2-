#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  
    char food_choice;
    char size_choice;
    int quantity;
    char member;

    string food_name = "";
    double unit_price = 0.0;

    double sub_total = 0.0;
    double discount = 0.0;

    double ar_tax_rate = 0.065;
    double faulkner_tax_rate = 0.005;
    double conway_tax_rate = 0.02125;

    double ar_tax = 0.0;
    double faulkner_tax = 0.0;
    double conway_tax = 0.0;
    double total_tax = 0.0;

    char tip_choice;
    double tip_amount = 0.0;
    double total = 0.0;

    cout << left << setw(18) << "Drink"
        << setw(15) << "Small (s)"
        << setw(15) << "Medium (m)"
        << setw(15) << "Large (l)" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << left << setw(18) << "A. Apple Juice"
        << setw(15) << "$2.50"
        << setw(15) << "$3.50"
        << setw(15) << "$4.50" << endl;
    cout << left << setw(18) << "B. Beer"
        << setw(15) << "$5.00"
        << setw(15) << "$7.00"
        << setw(15) << "$9.00" << endl;
    cout << left << setw(18) << "C. Smoothie"
        << setw(15) << "$3.00"
        << setw(15) << "$4.00"
        << setw(15) << "$5.00" << endl;

    cout << "\nSelect an option (A, B, or C): ";
    cin >> food_choice;

    cout << "Select a size (s for small, m for medium, l for large): ";
    cin >> size_choice;

    switch (food_choice) {
    case 'A':
    case 'a':
        food_name = "Apple Juice";
        if (size_choice == 's' || size_choice == 'S') unit_price = 2.50;
        else if (size_choice == 'm' || size_choice == 'M') unit_price = 3.50;
        else if (size_choice == 'l' || size_choice == 'L') unit_price = 4.50;
        break;
    case 'B':
    case 'b':
        food_name = "Beer";
        if (size_choice == 's' || size_choice == 'S') unit_price = 5.00;
        else if (size_choice == 'm' || size_choice == 'M') unit_price = 7.00;
        else if (size_choice == 'l' || size_choice == 'L') unit_price = 9.00;
        break;
    case 'C':
    case 'c':
        food_name = "Smoothie";
        if (size_choice == 's' || size_choice == 'S') unit_price = 3.00;
        else if (size_choice == 'm' || size_choice == 'M') unit_price = 4.00;
        else if (size_choice == 'l' || size_choice == 'L') unit_price = 5.00;
        break;
    default:
        food_name = "Unknown";
        unit_price = 0.0;
    }

    cout << "How many items: ";
    cin >> quantity;

    cout << "Are you a member (y/n): ";
    cin >> member;

    cout << fixed << setprecision(2);
    cout << "\n--- Order Summary ---" << endl;
    cout << left << setw(18) << food_name << endl;
    cout << right << setw(6) << quantity << endl;
    cout << right << setw(7) << unit_price << endl;


    sub_total = unit_price * quantity;
    discount = 0.10 * sub_total;

    if (member == 'y' || member == 'Y') {
        sub_total = sub_total - discount;
    }

    ar_tax = sub_total * ar_tax_rate;
    faulkner_tax = sub_total * faulkner_tax_rate;
    conway_tax = sub_total * conway_tax_rate;
    total_tax = ar_tax + faulkner_tax + conway_tax;

    cout << "\n--- Tax Breakdown ---" << endl;
    cout << left << setw(22) << "Tax Name" << setw(12) << "Percentage" << "Amount" << endl;
    cout << left << setw(22) << "Arkansas State Tax" << setw(12) << "6.5%" << "$" << ar_tax << endl;
    cout << left << setw(22) << "Faulkner County Tax" << setw(12) << "0.5%" << "$" << faulkner_tax << endl;
    cout << left << setw(22) << "Conway Municipal Tax" << setw(12) << "2.125%" << "$" << conway_tax << endl;


    cout << "\n--- Tip Selection ---" << endl;
    cout << left << setw(20) << "Tip Selection" << "Amount" << endl;
    cout << left << setw(20) << "A. 15%" << "$" << (sub_total * 0.15) << endl;
    cout << left << setw(20) << "B. 20%" << "$" << (sub_total * 0.20) << endl;
    cout << left << setw(20) << "C. 25%" << "$" << (sub_total * 0.25) << endl;
    cout << left << setw(20) << "D. Other Amount" << endl;

    cout << "What tip do you choose? ";
    cin >> tip_choice;

    if (tip_choice == 'A' || tip_choice == 'a') {
        tip_amount = sub_total * 0.15;
    }
    else if (tip_choice == 'B' || tip_choice == 'b') {
        tip_amount = sub_total * 0.20;
    }
    else if (tip_choice == 'C' || tip_choice == 'c') {
        tip_amount = sub_total * 0.25;
    }
    else if (tip_choice == 'D' || tip_choice == 'd') {
        cout << "How much would you like to tip? $";
        cin >> tip_amount;
    }
    else {
        tip_amount = 0.0;
    }

    total = sub_total + total_tax + tip_amount;

    cout << "\n----------------------------" << endl;
    cout << left << setw(18) << "Final Total:" << "$" << total << endl;

    return 0;
}
