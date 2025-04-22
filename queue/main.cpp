#include "function.h"
#include <iostream>
using namespace std;
int main()
{
    vector<Client> clientQueue;
    int lastTicketNumber = 0;
    int choice;
    do
    {
        cout << "\n=============================================\n";
        cout << "     CINEVO ELECTRONIC QUEUE SYSTEM     \n";
        cout << "=============================================\n";
        cout << "1 - Add client(s) to queue\n";
        cout << "2 - Call next client\n";
        cout << "3 - Show current queue\n";
        cout << "4 - Exit system\n";
        cout << "---------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addClient(clientQueue, lastTicketNumber);
            break;
        case 2:
            callNextClient(clientQueue);
            break;
        case 3:
            showQueue(clientQueue);
            break;
        case 4:
            cout << "\nExiting system. Have a healthy day!\n";
            break;
        default:
			if (cin.fail())
            {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
            cout << "Invalid choice. Please enter a number from 1 to 4.\n";
        }
    } while (choice != 4);
    return 0;
}