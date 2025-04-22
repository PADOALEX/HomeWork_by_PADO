#include "function.h"
#include <queue>
bool compareClients(const Client& a, const Client& b)
{
    if (a.priority == b.priority)
        return a.ticketNumber < b.ticketNumber;
    return a.priority > b.priority;
}
void explainPriority()
{
    cout << "\n Priority Levels:\n";
    cout << "   0 - Normal (regular appointment)\n";
    cout << "   1 - Urgent (needs faster service)\n";
    cout << "   2 - Emergency examination (served first)\n";
    cout << "--------------------------------------\n";
}
void addClient(vector<Client>& queue, int& lastTicketNumber)
{
    int count;
    cout << "\nHow many clients would you like to add? ";
    cin >> count;
	while (!cin || count <= 0)
    {
		cout << "Invalid input. Please enter a positive number: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> count;
	}
    cin.ignore();
    for (int i = 0; i < count; ++i)
    {
        Client c;
        cout << "\n--- Adding client #" << (i + 1) << " ---" << endl;
        cout << "Enter client name: ";
        getline(cin, c.name);
        explainPriority();
        cout << "Enter priority (0, 1, or 2): ";
        while (!(cin >> c.priority) || c.priority < 0 || c.priority > 2)
        {
            cout << "Invalid input. Please enter 0, 1, or 2: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore();
        c.ticketNumber = ++lastTicketNumber;
        queue.push_back(c);
        cout << "Client added: " << c.name << " [Ticket " << c.ticketNumber << "] (Priority: " << c.priority << ")\n";
    }
    sort(queue.begin(), queue.end(), compareClients);
    cout << "\nAll clients added successfully.\n";
}
void callNextClient(vector<Client>& queue)
{
    if (queue.empty())
    {
        cout << "\nThe queue is empty. No clients to call.\n";
        return;
    }
    Client next = queue.front();
    cout << "\nNow serving: " << next.name << " [Ticket " << next.ticketNumber << "] (Priority: " << next.priority << ")\n";
    queue.erase(queue.begin());
}
void showQueue(const vector<Client>& queue)
{
    if (queue.empty())
    {
        cout << "\nQueue is currently empty.\n";
        return;
    }
    cout << "\nCurrent Queue:\n";
    cout << "---------------------------------------------\n";
    cout << "| Ticket  |        Name        | Priority   |\n";
    cout << "---------------------------------------------\n";
    for (const Client& c : queue)
    {
        string pText = (c.priority == 2 ? "Emergency examination" : (c.priority == 1 ? "Urgent" : "Normal"));
        printf("|   %-6d | %-18s | %-9s |\n", c.ticketNumber, c.name.c_str(), pText.c_str());
    }
    cout << "---------------------------------------------\n";
}