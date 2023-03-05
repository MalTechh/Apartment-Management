#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>

using namespace std;

struct apartment
{
    int number;
    int monthly_rent;
    int max_tenants;
    int num_tenants;
    string tenants[10];
};

void load(string fname, apartment apartments[], int &num)
{
    ifstream inFile;
    int i;
    apartment temp;
    int j;
    inFile.open(fname);
    if (!inFile.is_open())
    {
        cout << "File not found" << endl;
    };
    inFile >> num;
    inFile.ignore();
    for (i = 0; i < num; i++)
    {
        inFile >> apartments[i].number;
        inFile.ignore();
        inFile >> apartments[i].monthly_rent;
        inFile.ignore();
        inFile >> apartments[i].max_tenants;
        inFile.ignore();
        inFile >> apartments[i].num_tenants;
        inFile.ignore();
        if (apartments[i].num_tenants > 0)
        {
            for (j = 0; j < apartments[i].num_tenants; j++)
            {
                getline(inFile, apartments[i].tenants[j]);
            }
        }
    };
    inFile.close();
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - 1 - i; j++)
        {
            if (apartments[j].monthly_rent > apartments[j + 1].monthly_rent)
            {
                temp = apartments[j];
                apartments[j] = apartments[j + 1];
                apartments[j + 1] = temp;
            }
        }
    }
};

void save(string fname, apartment apartments[], int num)
{
    ofstream output;
    int i;
    int j;
    output.open(fname);
    if (!output.is_open())
    {
        cout << "Couldn't open output file." << endl;
    }
    output << num << endl;
    for (i = 0; i < num; i++)
    {
        output << apartments[i].number << endl;
        output << apartments[i].monthly_rent << endl;
        output << apartments[i].max_tenants << endl;
        output << apartments[i].num_tenants << endl;
        if (apartments[i].num_tenants > 0)
        {
            for (j = 0; j < apartments[i].num_tenants; j++)
            {
                output << apartments[i].tenants[j] << endl;
            }
        }
    };
};

void list_all_apartments(apartment apart[10], int numApartments)
{
    int i;
    int j;
    int rented = 0;
    int rentMoney = 0;
    for (i = 0; i < numApartments; i++)
    {
        cout << "Apartment #" << apart[i].number << ":" << endl
             << "Monthly Rent: $" << apart[i].monthly_rent << endl
             << "Max # of tenants: " << apart[i].max_tenants << endl
             << "Number of Tenants: " << apart[i].num_tenants << endl;
        if (apart[i].num_tenants == 0)
        {
            cout << "---" << endl;
            continue;
        };
        cout << "Tenants: ";
        for (j = 0; j < apart[i].num_tenants; j++)
        {
            if (apart[i].tenants[j] != "")
            {
                if (j + 1 == apart[i].num_tenants)
                {
                    cout << apart[i].tenants[j];
                }
                else
                {
                    cout << apart[i].tenants[j] << ", ";
                };
            };
        };
        cout << endl
             << "---" << endl;
        rented += 1;
        rentMoney += apart[i].monthly_rent;
    };
    cout << "Total Monthly Rent Collected: $" << rentMoney << endl
         << "Number of occupied units: " << rented << "/" << numApartments << endl
         << "---" << endl;
};

void list_available_apartments(apartment apart[10], int numApartments)
{
    int i;
    for (i = 0; i < numApartments; i++)
    {
        if (apart[i].max_tenants > apart[i].num_tenants)
        {
            cout << "Apartment #" << apart[i].number << ":" << endl
                 << "Monthly Rent: $" << apart[i].monthly_rent << endl
                 << "Max # of Tenants: " << apart[i].max_tenants << endl;
            cout << "---" << endl;
        };
    };
};
string find_tentant(string name, apartment apart[], int numApartments)
{
    int i;
    int j;
    bool found = false;
    for (i = 0; i < numApartments; i++)
    {
        if (apart[i].num_tenants == 0)
        {
            continue;
        }
        int length = sizeof(apart[i].tenants) / sizeof(apart[i].tenants[0]);
        for (j = 0; j < length; j++)
        {
            if (name == apart[i].tenants[j])
            {
                found = true;
                cout << name << " is in apartment #" << apart[i].number << "!" << endl;
            }
        }
    }
    if (!found)
    {
        cout << "Error, tenant not found!" << endl;
    };
    return "";
};

void move_in(string tenant_name, int apartment_num,
             apartment apartments[], int num_apartments)
{
    int i;
    int current_tenants;
    for (i = 0; i < num_apartments; i++)
    {
        if (apartments[i].number == apartment_num)
        {
            current_tenants = apartments[i].num_tenants;
            if (current_tenants == apartments[i].max_tenants)
            {
                cout << "Error, the apartment cannot hold any more tenants!" << endl;
                break;
            }
            else
            {
                apartments[i].tenants[current_tenants] = tenant_name;
                apartments[i].num_tenants += 1;
                cout << "Successfully moved in!" << endl;
            }
        }
    }
};

void move_out(string tenant_name, apartment apartments[], int num_apartments)
{
    bool skip;
    if (tenant_name == "\0")
    {
        cout << "Error, there are no tenants with that name!" << endl;
        skip = true;
    }
    if (!(skip))
    {
        int i;
        int j;
        int k;
        bool found = false;
        string tenanthold[10];
        for (i = 0; i < num_apartments; i++)
        {
            if (apartments[i].num_tenants == 0)
            {
                continue;
            }
            int length = sizeof(apartments[i].tenants) / sizeof(apartments[i].tenants[0]);
            for (j = 0; j < length; j++)
            {
                if (tenant_name == apartments[i].tenants[j])
                {
                    found = true;
                    for (k = j; k < apartments[i].num_tenants; k++)
                    {
                        apartments[i].tenants[j] = apartments[i].tenants[j + 1];
                    };
                    apartments[i].num_tenants -= 1;
                    cout << "Successfully moved out." << endl;
                    break;
                }
                if (found)
                {
                    break;
                };
            };
        };
        if (!found)
        {
            cout << "Error, there are no tenants with that name!" << endl;
        };
    };
};

int main()
{
    int input = 0;
    string savefilename;
    int apart_num;
    string tenant;
    string filename;
    int numApartments = 0;
    apartment apart[10];
    cout << "Please enter the name of the file to load:" << endl;
    cin >> filename;
    load(filename, apart, numApartments);
    list_all_apartments(apart, numApartments);
    while (input != 8)
    {
        cout << "Main Menu" << endl
             << "1- List All Apartments" << endl
             << "2- List Available Apartments" << endl
             << "3- Move In" << endl
             << "4- Move Out" << endl
             << "5- Find Tenant" << endl
             << "6- Save" << endl
             << "7- Load" << endl
             << "8- Exit" << endl
             << "Please enter your choice:" << endl;

        while (!(cin >> input))
        {
            cout << "Invalid option!" << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
        switch (input)
        {
        case 1:
            list_all_apartments(apart, numApartments);
            break;
        case 2:
            list_available_apartments(apart, numApartments);
            break;
        case 3:
            cout << "Enter the apartment number to move in:" << endl;
            while (!(cin >> apart_num))
            {
                cout << "Please enter an apartment number:" << endl;
                cin.clear();
                cin.ignore(123, '\n');
            }
            cin.ignore();
            cout << "Enter the name of the tenant:" << endl;
            getline(cin, tenant);
            move_in(tenant, apart_num, apart, numApartments);
            break;
        case 4:
            cout << "Enter the name of the tenant moving out:" << endl;
            cin.ignore();
            getline(cin, tenant);
            move_out(tenant, apart, numApartments);
            break;
        case 5:
            cout << "Enter the name of the tenant to search for:" << endl;
            cin.ignore();
            getline(cin, tenant);
            find_tentant(tenant, apart, numApartments);
            break;
        case 6:
            cout << "Enter the filename to save to:" << endl;
            cin >> savefilename;
            save(savefilename, apart, numApartments);
            break;
        case 7:
            cout << "Enter the file name to load from:" << endl;
            cin >> filename;
            numApartments = 0;
            load(filename, apart, numApartments);
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid option" << endl;
        };
    };
}