#include <iostream>
#include <string>
using namespace std;

struct Car 
{
    short num;
    string car_brand;
    string model;
    float mileage;
    float consumption;
    float price;
};

struct Tot_price 
{
    int days;
    float total_price;
    float discount;
    Car fp;
};

struct customer 
{
    string full_name;
    int password;
    int phone_number;
    int driver_licence_id;
    string address;
    Tot_price pr;
};

void signin();
void see_cars(Car electric[], Car diesel[], Car &fp);
float calc_price(Car &, Tot_price &);
void add_pi(customer, Tot_price);
void display();

int main() 
{
    display();

    return 0;
}
void display()
{
    signin();
    Tot_price calc;
    Car fp;

    Car electric[5] = 
	{
        {1, "toyota", "CH4", 224000, 400, 6000},
        {2, "vols wagen", "ID6", 345678, 400, 7000},
        {3, "tesla", "model 3", 67896, 400, 8000},
        {4, "audi", "Q5 PHEV", 43567, 400, 9000},
        {5, "hyundai", "ionic 4", 12779, 400, 10000}
    };
    Car diesel[5] = 
	{
        {1, "Hyundai", "Elantra", 104000, 400, 2500},
        {2, "toyota", "vitz", 124000, 400, 1800},
        {3, "ford", "F150", 200000, 400, 6500},
        {4, "marchedis", "A-class", 678900, 400, 5000},
        {5, "volvo", "TR670", 478900, 400, 4000}
    };
    see_cars(electric, diesel, fp);
    calc.fp = fp;
    
    calc_price(fp, calc);

    customer info;
    add_pi(info, calc);	
}

void signin() 
{
	customer cus1;
    a: cout << "\n\n\n\n\n\n\n\n\t\t\t"
            << "\n\t\t\t------------------"
            << "\n\t\t\tCAR RENTAL SYSTEM\n"
            << "\t\t\t------------------\n\n"
            << "\tWELCOME!" << endl;
    cout << "\t------------------------------";
    cout << "\n\tLOGIN \n";
    cout << "\tusername:";
    cin >> cus1.full_name;
    cout << endl << "\tpassword:";
    cin >> cus1.password;

    if (cus1.password != 1234) {
        cout << "\n\tWRONG password" << endl
             << "\n\taccess NOT granted.\n\tTry again\n\n\n\n\n";
        system("pause");
        system("cls");
        goto a;
    } else {
        cout << "\n\tACCESS GRANTED!\n\n";
        system("pause");
        system("cls");
    }
}

void see_cars(Car electric[], Car diesel[], Car &fp) {
    int opt;
    cout << "\n\n\t\t\t\t========================================"
         << "\n\t\t\t\tEnter 1 to see list of our electric cars \n"
         << "\t\t\t\tEnter 2 to see list of our diesel cars"
         << "\n\t\t\t\t========================================\n";
    cout << "\t\tENTER HERE:";
    cin >> opt;

    if (opt == 1) {
        cout << "\t\t\t\t\tElectric cars to rent" << endl;
        cout << "\t\t\t\t\t---------------------" << endl;

        for (int i = 0; i < 5; i++) {
            cout << endl << "\t\t\t\t" << electric[i].num << "   |   " << electric[i].car_brand << "   |   " << electric[i].model << "   |   " << electric[i].mileage << "   |   " << electric[i].consumption << "   |   " << electric[i].price << "   |   " << endl;
            cout << "\t\t\t\t" << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }

        int choice;
        cout << "\n\n\t\t\t\tEnter the number of the car you want to rent:";
        cin >> choice;

        for (int i = 0; i < 5; i++) {
            if (choice == electric[i].num) {
                fp = electric[i];
            }
        }
    } else if (opt == 2) {
        cout << "\t\t\t\t\tDiesel cars to rent" << endl;
        cout << "\t\t\t\t\t-------------------" << endl;

        for (int i = 0; i < 5; i++) {
            cout << endl << "\t\t\t\t" << diesel[i].num << "   |   " << diesel[i].car_brand << "   |   " << diesel[i].model << "   |   " << diesel[i].mileage << "   |   " << diesel[i].consumption << "   |   " << diesel[i].price << "   |   " << endl;
            cout << "\t\t\t\t" << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }

        int choice;
        cout << "\n\n\t\t\t\tEnter the number of the car you want to rent:";
        cin >> choice;

        for (int i = 0; i < 5; i++) {
            if (choice == diesel[i].num) {
                fp = diesel[i];
            }
        }
    } else {
        cout << "\n\t\t\t\tInvalid option" << endl;
    }
}

float calc_price(Car &fp, Tot_price &calc) {
    cout << "\n\n\n\t\tHow many days will you rent this car? :";
    cin >> calc.days;
    float price = fp.price;
    calc.total_price = price * calc.days;
  system("CLS");
  
  if (calc.days < 10)
  {
 //cout<<calc.total_price<<" birr"<<endl;	
  }
    else if (calc.days >= 10 && calc.days<=29) 
	{
        calc.discount = calc.total_price * 0.05;
        calc.total_price -= calc.discount;
        cout << "\n\n\t\t\t\tYou get a 5% discount for renting for 10 or more days" << endl;
    }
    
    else
	{
    	calc.discount = calc.total_price * 0.15;
        calc.total_price -= calc.discount;
        cout << "\n\n\t\t\t\tYou get a 15% discount for renting for 30 or more days" << endl;
	}

    cout << "\n\n\t\t\t\tThe total price is: " << calc.total_price <<"birr"<< endl;

    return calc.total_price;
}

void add_pi(customer info, Tot_price calc) {
    cout << "\n\n\n\t\tEnter your full name:";
    cin.ignore();
    getline(cin, info.full_name);
    cout << "\n\t\tEnter your password:";
    cin >> info.password;
    cout << "\n\t\tEnter your phone number:";
    cin >> info.phone_number;
    cout << "\n\t\tEnter your driver licence number:";
    cin >> info.driver_licence_id;
    cout << "\n\t\tEnter your address:";
    cin.ignore();
    getline(cin, info.address);
    info.pr = calc;
    cout << "\n\n\t\t the car is now reserved for you so come soon and take your car " << endl;
    cout << "\n\n\t\t\t\tThank You for using our service  " << endl;
}

