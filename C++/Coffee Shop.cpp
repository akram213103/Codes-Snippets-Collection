#include <iostream>
using namespace std;

// constant cup sizes
#define Small_Cup_Size 9
#define Medium_Cup_Size 12
#define Large_Cup_Size 15

// constant cup prices
#define Small_Cup_Price 1.75
#define Medium_Cup_Price 1.90
#define Large_Cup_Price 2.00

// user can buy coffee as much as cup they want
void buy_coffee(int& small_cup, int& medium_cup, int& large_cup)
{
    int input = 0;
    float total_amount = 0;
    int input_cups = 0;

    while (true)
    {
        cout << "1: Enter 1 to buy coffee in a small cup size (9 oz)\n"
            << "2: Enter 2 to buy coffee in a medium cup size (12 oz)\n"
            << "3: Enter 3 to buy coffee in a large cup size (15 oz)\n"
            << "9: Enter 9 to exit\n";

        cin >> input;

        if (input == 9)
        {
            printf("Please pay $%.2f\n", total_amount);
            return;
        }

        cout << "Enter number of cups:";
        cin >> input_cups;

        if (input == 1)
        {
            small_cup += input_cups;
            total_amount += input_cups * Small_Cup_Price;
        }
        else if (input == 2)
        {
            medium_cup += input_cups;
            total_amount += input_cups * Medium_Cup_Price;
        }
        else if (input == 3)
        {
            large_cup += input_cups;
            total_amount += input_cups * Large_Cup_Price;
        }
    }
}

// printing number of cup of each size sold
void each_cup_sold(int small_cup, int medium_cup, int large_cup)
{
    printf("Small cup count: %d\n", small_cup);
    printf("Medium cup count: %d\n", medium_cup);
    printf("Large cup count: %d\n", large_cup);
}

// calculating and printing total amount of coffee sold
void total_coffee_sold(int small_cup, int medium_cup, int large_cup)
{
    int total_coffee = small_cup * Small_Cup_Size + medium_cup * Medium_Cup_Size + large_cup * Large_Cup_Size;
    printf("Total amount of coffee sold: %doz\n", total_coffee);
}

// calculating and printing total money made
void total_money(int small_cup, int medium_cup, int large_cup)
{
    float total_money = small_cup * Small_Cup_Price + medium_cup * Medium_Cup_Price + large_cup * Large_Cup_Price;
    printf("Total money made: $%.2f\n", total_money);
}

int main()
{
    int small_cup_count = 0, medium_cup_count = 0, large_cup_count = 0;

    // MENU for user
    while (true)
    {
        cout << "1: Enter 1 to order coffee.\n"
            << "2: Enter 2 to check the total money made up to this time.\n"
            << "3: Enter 3 to check the total amount of coffee sold up to this time.\n"
            << "4: Enter 4 to check the number of cups of coffee of each size sold.\n"
            << "5: Enter 5 to print the data.\n"
            << "9: Enter 9 to exit the program.\n";
        int option;
        cin >> option; // getting option input

        if (option == 9) // exit
            break;
        else if (option == 1) // buy coffee
            buy_coffee(small_cup_count, medium_cup_count, large_cup_count);
        else if (option == 4) // print number of cup of each size sold
            each_cup_sold(small_cup_count, medium_cup_count, large_cup_count);
        else if (option == 3) // print total amount of coffee sold
            total_coffee_sold(small_cup_count, medium_cup_count, large_cup_count);
        else if (option == 2) // print total money made
            total_money(small_cup_count, medium_cup_count, large_cup_count);
        else if (option == 5)
        {
            each_cup_sold(small_cup_count, medium_cup_count, large_cup_count);
            total_coffee_sold(small_cup_count, medium_cup_count, large_cup_count);
            total_money(small_cup_count, medium_cup_count, large_cup_count);
        }
    }

    // exiting
    cout << "Enter any key to continue . . .\n";

    return 0;
}