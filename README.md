# Apartment-Management
This is the assignment description: 

Write a program that manages the apartments in an apartment complex. First, create a struct named apartment (all lowercase), each apartment struct will have:

number: the apartment's number

monthly_rent: the monthly rent amount for this apartment

max_tenants : the maximum number of tenants the apartment can hold

num_tenants: how many tenants the apartment currently holds

tenants: a string array that holds the name of each tenant (max 10)


Note that while each apartment has its apartment number, the apartment number is not the same as the index of the apartment inside the apartments array! For example, given an array of 4 apartments, the apartment numbers could be 4,2,1,3 (why? because the apartment array will be sorted based on the rent price). The apartment number here is a unique identifier for that apartment, like a name to a person.

The data on the entire apartment complex is stored inside a single file. Write a load function to read in all the apartment information from this file. This function should first take in a string for the filename of the file to load, an array of apartment structs (that will be updated with the corresponding apartments after the function finish loading), and the number of apartments (as this value should reflect the number of districts read from the file, it should be passed in as reference). The function declaration should look like:

void load(string fname, apartment apartments[], int &num)
(Note, to pass the unit tests, make sure the parameter types of all functions to be in correct order, and the function name must be exactly the same!).

Next, read in the file with that name. The file will be in this format:


<NUMBER OF APARTMENTS>
  
<APARTMENT 1's NUMBER>
             
<APARTMENT 1's MONTHLY RENT>
  
<APARTMENT 1's MAX TENANTS>
             
<APARTMENT 1's NUMBER OF TENANTS>
  
<APARTMENT 1's TENANT 1's NAME>
  
<APARTMENT 1's TENANT 2's NAME>
  
<APARTMENT 2s NUMBER>
  
<...>
  
Here is an example input file:

  
2
  
1
  
800
  
3
  
2
  
Anna Ann
  
Johny Joe
  
2
  
800
  
3
  
0
  
After the apartments are read, in order to assist the user with prioritizing districts, sort them in ascending order based on each apartment's monthly rent!

The next function to be implemented is the save() function. This function should have the same parameters as the load() function, except none of the parameters should be passed in as reference. The function will take in the string file name of the save file and an array of apartment structs, the number of apartments. Then it saves all the information into the save file in the same format provided above.

void save(string fname, apartment apartments[], int num)
The third function is list_all_apartments() which will print out the information of each apartment in the following format:

Apartment #<APARTMENT 1's NUMBER>:
  
Monthly Rent: <APARTMENT 1's MONTHLY RENT>
  
Max # of Tenants: <APARTMENT 1's MAX TENANTS>
  
Number of Tenants: <APARTMENT 1's NUMBER OF TENANTS>
  
Tenants: <APARTMENT 1's TENANT 1's NAME>, <APARTMENT 1's TENANT 2's NAME>, <...>
  
---
  
<APARTMENT 2s NUMBER>
  
<...>
Total Monthly Rent Collected: $<TOTAL MONTHLY RENT>
  
Number of occupied units: <OCCUPIED APARTMENTS>/<ALL APARTMENTS>
  
---
  
  
An example output is:

Apartment #1:
  
Monthly Rent: $800
  
Max # of Tenants: 2
  
Number of Tenants: 2
  
Tenants: Bobby bob, Anna Ann
  
---
  
Apartment #2:
  
Monthly Rent: $900
  
Max # of Tenants: 4
  
Number of Tenants: 0
  
---
  
Total Monthly Rent Collected: $800
  
Number of occupied units: 1/2
  
---
  
  
If the apartment has 0 tenants then do not display the Tenants: line for that apartment. Also note that the monthly rent collected for each occupied apartment is the same regardless of how many tenants it has.

  
The next function is list_available_apartments() which will print only the apartments that has room (tenants less than max_tenants). An example output is:

Apartment #2:
  
Monthly Rent: $900
  
Max # of Tenants: 4
  
Number of Tenants: 0
  
  
Then write a move_in() function that takes in the following parameters: the name of the tenant, the apartment number they're moving into, the appartment array, and the number of apartments in the array. If that apartment is already full then print "Error, the apartment cannot hold any more tenants!". Otherwise add that tenant into the apartment's tenants array and update its num_tenants, then print "Successfully moved in!".

  
The function should be defined as:

  
void move_in(string tenant_name, int apartment_num, apartment apartments[], int num_apartments)
  
  
Next write a move_out() function that takes in the following parameters: the name of the tenant, the appartment array, and the number of apartments in the array. This function tries to find the tenant with that name in all of the apartments, and if found, remove that tenant from the apartment's tenants array and print "Successfully moved out.", if no such tenant is found, print "Error, there are no tenants with that name!".

The function should be defined as:

void move_out(string tenant_name, apartment apartments[], int num_apartments)
Lastly write the main() function as follows:

First ask the user to enter the name of the file to load: "Please enter the name of the file to load:"
Get the file name from cin and load the file
Print the information of all apartments
Then start a menu loop. This menu loop should repeat indefinitely until the user selects the exit option:
  
Main Menu
  
1- List All Apartments
  
2- List Available Apartments
  
3- Move In
  
4- Move Out
  
5- Find Tenant
  
6- Save
  
7- Load
  
8- Exit
  
  
If the user entered an invalid option, print "Invalid option!"
  
Option 1 will print all apartments information
  
Option 2 will print only the apartments that are available for rent
  
Option 3 will first ask the user "Enter the apartment number to move in:"
  
Then ask the user"Enter the name of the tenant:"
  
Then call the move_in() function with the correct parameters
  
Option 4 will first ask the user ""Enter the name of the tenant moving out:"
  
Then call the move_out() function with the correct parameters
  
Option 5 will first ask the user for the name of the tenant "Enter the name of the tenant to search for:"
  
If there is an apartment with that tenant then output "<NAME> in apartment #<APARTMENT NUMBER>!" otherwise print "Error, tenant not found!"
  
Option 6 will prompt the user to enter the file name "Enter the file name to save to:" and save everything to that file
  
Option 7 will prompt the user to enter the file name "Enter the file name to load from:" and load everything from that file
  
Option 8 will terminate the program
