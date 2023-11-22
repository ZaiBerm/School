#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <ctime>
#include <windows.h>
using namespace std;


class food {
private:

    string name;
    double price = 0.0;
    double quant = 0.0;
    int size = 1;
    int category = 0;
    double ordertotal = 0.0;

public:

    //setter of name and price
    void setfinfo(string a, double b, double ewan, int sizeo, int cat)
    {
        name = a;
        price = b;
        quant = ewan;
        size = sizeo;
        category = cat;
    }

    void settotal(double x)
    {
        ordertotal = x;
    }

    void setsize(int x)
    {
        size = x;
    }

    void setquant(double x)
    {
        quant = x;
    }

    //getter of name
    string getname()
    {
        return name;
    }

    //getter of price
    double getfprice()
    {
        double tmpprice = price;
        if (category == 3)
        {
            if (name == "COLA")
            {
                for (int i = 1; i < size; i++)
                {
                    tmpprice += 5;
                }
            }
            else
            {
                for (int i = 1; i < size; i++)
                {
                    tmpprice += 10;
                }
            }

        }

        return tmpprice;
    }

    //getter of quant
    double getquantity()
    {
        return quant;
    }

    //getter of size
    int getsize()
    {
        return size;
    }
    //getter of category
    int getcategory()
    {
        return category;
    }

    //getter of total
    double get_total()
    {
        
        ordertotal = getfprice() * quant;

        return ordertotal;
    }

    
};

string lborder = "                          ";
string hborder = "             ";

//FUNCTION THAT PRINTS
void front_page();
void loading();
void menu();
void burgers_menu();
void hotdogs_menu();
void bev_menu();
void print_orders(vector <food> orders, double *bill);
void print_ordersreceipt(vector <food> orders, double bill, double balance, double change);

//FUNCTION THAT ASSIGN A VALUE ON THE TEMPORARY VARIABLES
void process_order(int category, int selector, double num_of_order, int size, string* tmpname, double* tmpprice, double* tmpquant);



int main()
{
    int selector;
    food order;
    vector<food> orders;
    int size = 0;
    double num_of_order = 0.0;
    int category = 0;
    string tmpname;
    double tmpprice;
    double tmpquant;
    bool runner = true;
    double totalbill = 0;
    double balance = 0;
    double change = 0;

    front_page();

    do
    {
        cout << "\t\t\t\t\t\t ENTER: ";
        cin >> selector;

        if (selector == 2)
        {
            return 1;
        }
        else if (selector == 1)
        {
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\t\tINVALID INPUT" << endl;
        }

    } while (selector != 1 && selector != 2);


    system("cls");

    loading();

categ:

    system("cls");

    menu();

    cout << endl << endl << endl;

    do
    {
        cout << hborder << "IN WHAT CATEGORY WOULD YOU LIKE TO ORDER? ";
        cin >> selector;

        if (selector >= 1 && selector <= 2)
        {
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\t\tINVALID INPUT" << endl;
        }

    } while (selector != 1 && selector != 2 && selector != 3);

    system("cls");

    if (selector == 1)
    {
    burg:
        burgers_menu();
        category = 1;
        size = 1;

        Sleep(800);
            
        do
        {
            cout << "\t\t\t\t ENTER ORDER: ";
            cin >> selector;
        } while (selector < 1 || selector > 5);

        Sleep(300);
      
        cout << "\t\t\t\t HOW MANY: ";
        cin >> num_of_order;
    }
    else if (selector == 2)
    {
    dog:
        hotdogs_menu();
        category = 2;
        size = 1;
        
        Sleep(800);

        do
        {
            cout << "\t\t\t\t ENTER ORDER: ";
            cin >> selector;
        } while (selector < 1 || selector > 4);

        Sleep(300);

        cout << "\t\t\t\t HOW MANY: ";
        cin >> num_of_order;
    }
    else if (selector == 3)
    {
    bev:
        bev_menu();
        category = 3;

        Sleep(800);

        do
        {
            cout << "\t\t\t\t ENTER SIZE [1]SMALL, [2]MEDIUM, [3]LARGE: ";
            cin >> size;
        } while (size < 1 || size > 3);

        Sleep(300);
            
        do
        {
            cout << "\t\t\t\t ENTER ORDER: ";
            cin >> selector;
        } while (selector < 1 || selector > 4);

        Sleep(300);

        cout << "\t\t\t\t HOW MANY: ";
        cin >> num_of_order;
    }

    process_order(category, selector, num_of_order, size, &tmpname, &tmpprice, &tmpquant);

    order.setfinfo(tmpname, tmpprice, tmpquant, size, category);

    orders.push_back(order);

    Sleep(500);

    do
    {
        cout << lborder << lborder << lborder << "BUY MORE? [1]YES, [2]NO: ";
        cin >> selector;

    } while (selector != 1 && selector != 2);

    if (selector == 1)
    {
        do
        {
            cout << lborder << lborder << lborder << "IN THE SAME CATEGORY? [1]YES, [2]NO: ";
            cin >> selector;
        } while (selector != 1 && selector != 2);

        if (selector == 1)
        {
            system("cls");

            if (category == 1)
            {
                goto burg;
            }
            else if (category == 2)
            {
                goto dog;
            }
            else if (category == 3)
            {
                goto bev;
            }
        }
        else if (selector == 2)
        {
            goto categ;
        }
    }

checkout:

    system("cls");

    print_orders(orders, &totalbill);
    
    cout << endl << endl;

    cout << hborder << "[1]CONFIRM ITEM, [2]EDIT ITEM, [3]CLEAR ALL ITEMS AND GO TO THE MENU PAGE " << endl << endl;

    do
    {
        cout << hborder << "ENTER: ";
        cin >> selector;
    } while (selector != 1 && selector != 2 && selector != 3);

    cout << endl << endl;

    if (selector == 1)
    {
        system("cls");

        print_orders(orders, &totalbill);

        cout << lborder << lborder << hborder << "\t   YOUR BALANCE: ";
        cin >> balance;

        if (balance >= totalbill)
        {
            change = balance - totalbill;

            cout << endl << lborder << lborder << hborder << "\t   YOUR CHANGE: " << change << endl << endl;

            do
            {
                cout << hborder << "PRINT THE RECEIPT? [1]YES, [2]NO: ";
                cin >> selector;

            } while (selector != 1 && selector != 2);
            
            system("cls");

            if (selector == 1)
            {
                print_ordersreceipt(orders, totalbill, balance, change);
                cout << endl;
                cout << hborder;
                system("pause");
                return 0;
            }
            
        }
        else
        {
            cout << lborder << lborder << hborder << "\t                 INSUFFICENT BALANCE" << endl;
        }

    }
    else if (selector == 2)
    {

    editpage:

        system("cls");
        print_orders(orders, &totalbill);

        cout << endl << endl << hborder << "[1]DECREASE ITEM, [2]INCREASE ITEM, [3]ADD ITEM, [4]BACK" << endl << endl;

        do
        {
            cout << hborder << "ENTER: ";
            cin >> selector;
        } while (selector != 1 && selector != 2 && selector != 3 && selector != 4);

        if (selector == 1)
        {
            do
            {
                system("cls");

                print_orders(orders, &totalbill);

                cout << endl << endl << hborder << "ENTER THE ID OF THE ITEM YOU WANT TO DECREASE. " << endl;
                cout << hborder << "[" << orders.size() + 1 << "] BACK" << endl << endl;

                do
                {
                    cout << hborder << "ENTER: ";
                    cin >> selector;
                } while (selector <= 0 || selector > orders.size() + 1);
                
                if (selector != orders.size() + 1)
                {
                    orders[selector - 1].setquant(orders[selector - 1].getquantity() - 1);
                }

                for (int i = 0; i < orders.size(); i++)
                {
                    if (orders[i].getquantity() == 0)
                    {
                        orders.erase(orders.begin() + i);
                    }
                }

            } while (selector != orders.size() + 1);
           
        }
        else if (selector == 2)
        {
            do
            {
                system("cls");

                print_orders(orders, &totalbill);

                cout << endl << endl << hborder << "ENTER THE ID OF THE ITEM YOU WANT TO INCREASE. " << endl;
                cout << hborder << "[" << orders.size() + 1 << "] BACK" << endl << endl;

                do
                {
                    cout << hborder << "ENTER: ";
                    cin >> selector;
                } while (selector <= 0 || selector > orders.size() + 1);
               

                if (selector != orders.size() + 1)
                    orders[selector - 1].setquant(orders[selector - 1].getquantity() + 1);

            } while (selector != orders.size() + 1);
        }
        else if (selector == 3)
        {
            goto categ;
        }
        else
        {
            goto checkout;
        }

        goto editpage;
    }
    else if (selector == 3)
    {
        while (orders.size() != 0)
        {
            orders.pop_back();
        }
        goto categ;
    }
}





void front_page()
{
    cout << endl;

    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl;

    cout << hborder << "CREATOR:" << lborder << "  BERMILLO ZAIRUS V." << endl;
    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    cout << lborder << "XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX" << endl;
    cout << lborder << "XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX" << endl;
    cout << lborder << "           XXXXX       XXXXX        XXXXX     XXXXX             " << endl;
    cout << lborder << "         XXXXX         XXXXX        XXXXX     XXXXX             " << endl;
    cout << lborder << "       XXXXX           XXXXX        XXXXX     XXXXXXXXXXXXXXXXXX" << endl;
    cout << lborder << "     XXXXX             XXXXX        XXXXX     XXXXXXXXXXXXXXXXXX" << endl;
    cout << lborder << "   XXXXX               XXXXX        XXXXX                  XXXXX" << endl;
    cout << lborder << " XXXXX                 XXXXX        XXXXX                  XXXXX" << endl;
    cout << lborder << "XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX" << endl;
    cout << lborder << "XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXX" << endl;
    cout << endl;
    cout << lborder << "       ZAI'S                ORDERING                SYSTEM      " << endl;
    cout << endl;


    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl << endl;

    cout << lborder;
    for (int i = 0; i < 66; i++)
    {
        cout << "-";
    }
    cout << endl << endl;

    cout << lborder << "                      [1] TO CONTINUE" << endl;
    cout << lborder << "                      [2] TO EXIT THE PROGRAM" << endl << endl;

    cout << lborder;
    for (int i = 0; i < 66; i++)
    {
        cout << "-";
    }
    cout << endl << endl;
}

void loading()
{
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

    cout << lborder << hborder << "\t\t  PLEASE WAIT A MOMENT";
    Sleep(800);
    cout << ".";
    Sleep(800);
    cout << ".";
    Sleep(800);
    cout << ".";
    Sleep(800);

    cout << endl << endl;

    cout << lborder << hborder << "\t      THANK YOU FOR YOUR PATIENCE!!!";
    Sleep(1000);
}

void menu()
{
    cout << endl;

    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl;

    cout << lborder << lborder << "== MENU ==" << endl;

    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    cout << lborder << "[1] --BURGERS--\t\t\t\t     [2] --HOTDOGS--" << endl << endl;
    cout << hborder << "[CODE]\t\t\t    [PRICE]\t\t[CODE]\t\t\t       [PRICE]" << endl;
    cout << hborder << "- [-] HAMBURGER                  43.5\t\t- [-] NEW YORK DOG               55.5" << endl;
    cout << hborder << "- [-] CHEESEBURGER               53.5\t\t- [-] CHICAGO DOG                59.0" << endl;
    cout << hborder << "- [-] DOUBLE BURGER              57.5\t\t- [-] CHEESE DOG                 64.5" << endl;
    cout << hborder << "- [-] DOUBLE CH.BURGER           62.0\t\t- [-] BACON DOG                  70.0" << endl;
    cout << hborder << "- [-] PARRY MELT                 64.0" << endl;
    cout << endl << endl;

    cout << lborder << "\t\t          " << "[3] --BEVERAGES--" << endl << endl;
    cout << lborder << "[CODE]" << "\t\t\t\t" << "[SMALL]    [MEDIUM]    [LARGE]" << endl;
    cout << lborder << "- [-] COFFEE  " << "\t\t\t" << "   45         55          65" << endl;
    cout << lborder << "- [-] ICED TEA" << "\t\t\t" << "   35         45          55" << endl;
    cout << lborder << "- [-] MILK TEA" << "\t\t\t" << "   29         39          49" << endl;
    cout << lborder << "- [-] COLA    " << "\t\t\t" << "   25         30          35" << endl;
}

void burgers_menu()
{
    cout << endl << endl << endl;

    cout << hborder << "   ";
    for (int i = 0; i < 88; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    cout << lborder << lborder << "   --BURGERS--" << endl << endl;
    cout << lborder << hborder << "   [CODE]\t\t\t[PRICE] " << endl;
    cout << lborder << hborder << "  - [1] HAMBURGER                  43.5   " << endl;
    cout << lborder << hborder << "  - [2] CHEESEBURGER               53.5   " << endl;
    cout << lborder << hborder << "  - [3] DOUBLE BURGER              57.5   " << endl;
    cout << lborder << hborder << "  - [4] DOUBLE CH.BURGER           62.0   " << endl;
    cout << lborder << hborder << "  - [5] PARRY MELT                 64.0   " << endl << endl << endl;

    cout << hborder << "   ";
    for (int i = 0; i < 88; i++)
    {
        cout << "=";
    }
    cout << endl << endl << endl;
}

void hotdogs_menu()
{
    cout << endl << endl << endl;

    cout << hborder << "   ";
    for (int i = 0; i < 88; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    cout << lborder << lborder << "   --HOTDOGS--" << endl << endl;
    cout << lborder << hborder << "   [CODE]\t\t\t[PRICE] " << endl;
    cout << lborder << hborder << "  - [1] NEW YORK DOG               55.5   " << endl;
    cout << lborder << hborder << "  - [2] CHICAGO DOG                60.0   " << endl;
    cout << lborder << hborder << "  - [3] CHEESEDOG                  64.5   " << endl;
    cout << lborder << hborder << "  - [4] BACON DOG                  70.0   " << endl << endl << endl;

    cout << hborder << "   ";
    for (int i = 0; i < 88; i++)
    {
        cout << "=";
    }
    cout << endl << endl << endl;
}

void bev_menu()
{
    cout << endl << endl << endl;

    cout << hborder << "   ";
    for (int i = 0; i < 88; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    cout << lborder << "\t\t          " << "   --BEVERAGES--" << endl << endl;
    cout << lborder << "[CODE]" << "\t\t\t\t" << "[SMALL]    [MEDIUM]    [LARGE]" << endl;
    cout << lborder << "- [1] COFFEE  " << "\t\t\t" << "   45         55          65" << endl;
    cout << lborder << "- [2] ICED TEA" << "\t\t\t" << "   35         45          55" << endl;
    cout << lborder << "- [3] MILK TEA" << "\t\t\t" << "   29         39          49" << endl;
    cout << lborder << "- [4] COLA    " << "\t\t\t" << "   25         30          35" << endl << endl << endl;

    cout << hborder << "   ";
    for (int i = 0; i < 88; i++)
    {
        cout << "=";
    }
    cout << endl << endl << endl;
}

void process_order(int category, int selector, double num_of_order, int size, string* tmpname, double* tmpprice, double* tmpquant)
{
   
    switch (category)
    {
    case 1:
        switch (selector)
        {
        case 1:
            *tmpname = "HAMBURGER";
            *tmpprice = 43.5;
            *tmpquant = num_of_order;
            break;
        case 2:
            *tmpname = "CHEESEBURGER";
            *tmpprice = 53.5;
            *tmpquant = num_of_order;
            break;
        case 3:
            *tmpname = "DOUBLE BURGER";
            *tmpprice = 57.5;
            *tmpquant = num_of_order;
            break;
        case 4:
            *tmpname = "DOUBLE CH.BURGER";
            *tmpprice = 62.0;
            *tmpquant = num_of_order;
            break;
        case 5:
            *tmpname = "PATTY MELT";
            *tmpprice = 64.0;
            *tmpquant = num_of_order;
            break;
        }
        break;

    case 2:
        switch (selector)
        {
        case 1:
            *tmpname = "NEW YORK DOG";
            *tmpprice = 55.5;
            *tmpquant = num_of_order;
            break;
        case 2:
            *tmpname = "CHICAGO DOG";
            *tmpprice = 60.0;
            *tmpquant = num_of_order;
            break;
        case 3:
            *tmpname = "CHEESEDOG";
            *tmpprice = 64.5;
            *tmpquant = num_of_order;
            break;
        case 4:
            *tmpname = "BACON DOG";
            *tmpprice = 70.0;
            *tmpquant = num_of_order;
            break;
        }
        break;
        
    case 3:
        switch (selector)
        {
        case 1:
            *tmpname = "COFFEE";
            *tmpprice = 45.0;
            *tmpquant = num_of_order;
            break;
        case 2:
            *tmpname = "ICED TEA";
            *tmpprice = 35.0;
            *tmpquant = num_of_order;
            break;
        case 3:
            *tmpname = "MILK TEA";
            *tmpprice = 29.0;
            *tmpquant = num_of_order;
            break;
        case 4:
            *tmpname = "COLA";
            *tmpprice = 25.0;
            *tmpquant = num_of_order;
            break;
        }
        break;
    
    }
}

void print_orders(vector <food> orders, double *bill)
{
    *bill = 0;

    cout << endl << endl;

    cout << hborder << "YOUR ORDERS: " << endl << endl;

    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    

    cout << lborder << "[ID]   [NAME] \t      [SIZE]    [PRICE]    [QUANT]    [TOTAL]" << endl << endl;

    for (int i = 0; i < orders.size(); i++)
    {
        int quantlength = 0;
        int lop = orders[i].getquantity();

        do
        {
            quantlength++;
            lop = lop / 10;
        } while (lop > 0);

        if (orders[i].getcategory() != 3)
        {
            orders[i].setsize(0);
        }
        
        cout << lborder << " " << i + 1 << ".     " << orders[i].getname();

        for (int j = 0; j < 22 - orders[i].getname().size(); j++)
        {
            cout << " ";
        }

        cout << orders[i].getsize();

        cout << fixed << setprecision(1) << "         " << orders[i].getfprice();

        cout << setprecision(0) << "       " << orders[i].getquantity() << "x";

        for (int j = 0; j < 9 - quantlength; j++)
        {
            cout << " ";
        }

        cout << fixed << setprecision(1) << orders[i].get_total() << endl;
        
    }

    for (int i = 0; i < orders.size(); i++)
    {
        *bill += orders[i].get_total();
    }

    cout << endl;
    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl;
        
    cout << lborder << lborder << hborder << "\t   TOTAL BILL: " << * bill << endl;


}

void print_ordersreceipt(vector <food> orders, double bill, double balance, double change)
{
    cout << endl << endl;
    cout << lborder << hborder << "\t  THANK YOU FOR YOUR PURCHASE!!!" << endl;
    cout << lborder << hborder << "\t  THANK YOU FOR YOUR PURCHASE!!!" << endl;
    cout << lborder << hborder << "\t  THANK YOU FOR YOUR PURCHASE!!!" << endl << endl;
    cout << hborder << "   \t       \t \t\t\t\t\t          DATE: " << __DATE__ << endl;
    cout << hborder << "   RECEIPT RECEIPT \t\t\t\t\t\t  TIME: " << __TIME__ << endl << endl;

    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    cout << lborder << "[ID]   [NAME] \t      [SIZE]    [PRICE]    [QUANT]    [TOTAL]" << endl << endl;

    for (int i = 0; i < orders.size(); i++)
    {
        int quantlength = 0;
        int lop = orders[i].getquantity();

        do
        {
            quantlength++;
            lop = lop / 10;
        } while (lop > 0);

        for (double j = orders[i].getquantity(); j > 0;)
        {
            j = j / 10;
            quantlength++;
        }

        if (orders[i].getcategory() != 3)
        {
            orders[i].setsize(0);
        }

        cout << lborder << " " << i + 1 << ".     " << orders[i].getname();

        for (int j = 0; j < 22 - orders[i].getname().size(); j++)
        {
            cout << " ";
        }

        cout << orders[i].getsize();

        cout << fixed << setprecision(1) << "         " << orders[i].getfprice();

        cout << setprecision(0) << "       " << orders[i].getquantity() << "x";

        for (int j = 0; j < 9 - quantlength; j++)
        {
            cout << " ";
        }

        cout << fixed << setprecision(1) << orders[i].get_total() << endl;

    }


    cout << endl;
    cout << hborder;
    for (int i = 0; i < 90; i++)
    {
        cout << "=";
    }
    cout << endl << endl;

    

    cout << lborder << lborder << hborder << "\t   TOTAL BILL: " << bill << endl;
    cout << lborder << lborder << hborder << "\t      BALANCE: " << balance << endl;
    cout << lborder << lborder << hborder << "\t       CHANGE: " << change << endl;
}
