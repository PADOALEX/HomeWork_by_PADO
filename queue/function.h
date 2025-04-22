#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Client
{
    int ticketNumber;
    string name;
    int priority;
};
void addClient(vector<Client>& queue, int& lastTicketNumber);
void callNextClient(vector<Client>& queue);
void showQueue(const vector<Client>& queue);