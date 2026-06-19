#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool processPayment(int amount);
bool cardPayment(int amount);
bool cashPayment(int amount);

int ticketCounter = 1000;

string generateTicketID()
{
    return "TID" + to_string(ticketCounter++);
}

class Seat
{
public:
    int seatNumber;
    bool booked;
    string customerID;
    string ticketID;
    string category;

    Seat* next;
    Seat* prev;

    Seat(int num)
    {
        seatNumber = num;
        booked = false;
        customerID = "";
        ticketID = "";

        if(num >= 1 && num <= 30)
            category = "Silver";
        else if(num >= 31 && num <= 50)
            category = "Gold";
        else
            category = "Platinum";

        next = NULL;
        prev = NULL;
    }
};
class Movie
{

    void generateReceipt
(
    string ticketID,
    string customerID,
    int seatNum,
    string category,
    int amount
)
{
    ofstream file(
        ("Receipt_" + ticketID + ".txt").c_str()
    );

    file << "=================================\n";
    file << "         CINEMA RECEIPT\n";
    file << "=================================\n";
    file << "Ticket ID : " << ticketID << endl;
    file << "Customer  : " << customerID << endl;
    file << "Movie     : " << movieName << endl;
    file << "Timing    : " << timing << endl;
    file << "Seat No   : " << seatNum << endl;
    file << "Category  : " << category << endl;
    file << "Amount    : Rs. " << amount << endl;
    file << "=================================\n";

    file.close();
}
private:
    string movieName;
    string timing;

    Seat* head;
    Seat* tail;

    int revenue;

public:
    Movie()
    {
        movieName = "";
        timing = "";
        head = NULL;
        tail = NULL;
        revenue = 0;
    }
    Movie(string name, string time)
    {
        movieName = name;
        timing = time;
        head = NULL;
        tail = NULL;
        revenue = 0;

        createSeats();
    }

    void createSeats()
    {
        for(int i = 1; i <= 70; i++)
        {
            Seat* newSeat = new Seat(i);

            if(head == NULL)
            {
                head = tail = newSeat;
            }
            else
            {
                tail->next = newSeat;
                newSeat->prev = tail;
                tail = newSeat;
            }
        }
        tail->next = head;
        head->prev = tail;
    }

    void displayMovie()
    {
        cout << "\nMovie: " << movieName;
        cout << "\nTiming: " << timing << endl;
    }

void displaySeats()
{
    Seat* temp = head;

    cout << "\n================ SCREEN ================\n\n";

    cout << "Silver Seats   : 1 - 30   (Rs. 800)\n";
    cout << "Gold Seats     : 31 - 50  (Rs. 1500)\n";
    cout << "Platinum Seats : 51 - 70  (Rs. 2500)\n\n";

    for(int i = 1; i <= 70; i++)
    {
        if(temp->booked)
            cout << left << setw(6) << "X";
        else
            cout << left << setw(6) << temp->seatNumber;

        if(i % 10 == 0)
            cout << endl;
        temp = temp->next;
    }
    cout << endl;
}
    void bookSeat()
    {
        int seatNum;
        string customer;

        cout << "\nEnter Seat Number (1-70): ";
        cin >> seatNum;

        cout << "Enter Customer ID: ";
        cin >> customer;

        Seat* temp = head;

        do
        {
            if(temp->seatNumber == seatNum)
            {
                if(temp->booked)
                {
                    cout << "\nSeat already booked!\n";
                    return;
                }

               int price;
string category;

if(seatNum >= 1 && seatNum <= 30)
{
    category = "Silver";
    price = 800;
}
else if(seatNum >= 31 && seatNum <= 50)
{
    category = "Gold";
    price = 1500;
}
else
{
    category = "Platinum";
    price = 2500;
}

bool paymentStatus = processPayment(price);

if(!paymentStatus)
{
    cout << "\nBooking Failed Due To Payment Error!\n";
    return;
}

temp->booked = true;
temp->customerID = customer;
temp->ticketID = generateTicketID();

revenue += price;

cout << "\n================================";
cout << "\n      BOOKING CONFIRMED";
cout << "\n================================";

cout << "\nCategory : "
     << category;

cout << "\nSeat No  : "
     << seatNum;

cout << "\nTicket ID: "
     << temp->ticketID;

cout << "\nAmount Paid: Rs. "
     << price << endl;

saveBooking(temp);
generateReceipt(
    temp->ticketID,
    customer,
    seatNum,
    category,
    price
);

cout << "\nReceipt Generated Successfully!\n";
return;
}
            temp = temp->next;
        } while(temp != head);
        cout << "\nInvalid Seat Number!\n";
    }
    void cancelSeat()
    {
        string ticket;

        cout << "\nEnter Ticket ID: ";
        cin >> ticket;
        Seat* temp = head;

        do
        {
            if(temp->ticketID == ticket)
            {
                temp->booked = false;
                temp->customerID = "";
                temp->ticketID = "";

                cout << "\nBooking Cancelled Successfully!\n";
                return;
            }
            temp = temp->next;
        } 
        while(temp != head);
        cout << "\nTicket Not Found!\n";
    }
    void searchTicket()
    {
        string ticket;

        cout << "\nEnter Ticket ID: ";
        cin >> ticket;
        
        Seat* temp = head;
        do
        {
            if(temp->ticketID == ticket)
            {
                cout << "\nBooking Found\n";
                cout << "Seat Number: "
                     << temp->seatNumber << endl;

                cout << "Customer ID: "
                     << temp->customerID << endl;

                return;
            }
            temp = temp->next;
        } while(temp != head);

        cout << "\nTicket Not Found!\n";
    }

    void showRevenue()
    {
        cout << "\n================================";
        cout << "\nMovie   : " << movieName;
        cout << "\nRevenue : Rs. " << revenue;
        cout << "\n================================\n";
    }
    void saveBooking(Seat* seat)
    {
        ofstream file("bookings.txt", ios::app);
        file << movieName << " "
        << seat->seatNumber << " "
        << seat->category << " "
        << seat->customerID << " "
        << seat->ticketID << endl;

        file.close();
    }
    string getMovieName()
    {
        return movieName;
    }
};

bool cardPayment(int amount)
{
    string cardNumber;
    string cardHolder;
    string cvv;
    int expiryMonth;
    int expiryYear;

    cout << "\n========== CARD PAYMENT ==========\n";

    cout << "Card Holder Name: ";
    cin.ignore();
    getline(cin, cardHolder);

    cout << "Card Number (16 digits): ";
    cin >> cardNumber;

    if(cardNumber.length() != 16)
    {
        cout << "Invalid Card Number!\n";
        return false;
    }

    cout << "Expiry Month (MM): ";
    cin >> expiryMonth;

    if(expiryMonth < 1 || expiryMonth > 12)
    {
        cout << "Invalid Expiry Month!\n";
        return false;
    }

    cout << "Expiry Year (YYYY): ";
    cin >> expiryYear;

    if(expiryYear < 2025)
    {
        cout << "Card Expired!\n";
        return false;
    }

    cout << "CVV (3 digits): ";
    cin >> cvv;

    if(cvv.length() != 3)
    {
        cout << "Invalid CVV!\n";
        return false;
    }

    cout << "\nProcessing Payment";

    for(int i = 0; i < 3; i++)
    {
        cout << ".";
    }

    cout << "\nPayment Successful!\n";
    cout << "Amount Paid: Rs. " << amount << endl;

    return true;
}

bool cashPayment(int amount)
{
    int paid;

    cout << "\n========== CASH PAYMENT ==========\n";
    cout << "Amount Required: Rs. "
         << amount << endl;

    cout << "Enter Amount Given: Rs. ";
    cin >> paid;

    if(paid < amount)
    {
        cout << "Insufficient Amount!\n";
        return false;
    }

    cout << "Change Returned: Rs. "
         << paid - amount << endl;

    cout << "Payment Successful!\n";

    return true;
}

bool processPayment(int amount)
{
    int choice;

    cout << "\n========== PAYMENT MENU ==========\n";
    cout << "1. Card Payment\n";
    cout << "2. Cash Payment\n";

    cout << "Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            return cardPayment(amount);

        case 2:
            return cashPayment(amount);

        default:
            cout << "Invalid Payment Method!\n";
            return false;
    }
}

int main()
{

    bool processPayment(int amount);
    bool cardPayment(int amount);
    bool cashPayment(int amount);
    
    Movie movies[2] =
    {
        Movie(
            "The_Nutcracker",
            "8:00AM-9:50AM"
        ),
        Movie(
            "Do_Patti",
            "9:00AM-11:10AM"
        ),
    };
    int choice;
    do
    {
        cout << "\n=================================";
        cout << "\n      CINEMA BOOKING SYSTEM";
        cout << "\n=================================";

        cout << "\n1. View Movies";
        cout << "\n2. Book Seat";
        cout << "\n3. Cancel Booking";
        cout << "\n4. Search Ticket";
        cout << "\n5. View Revenue";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                for(int i = 0; i < 2; i++)
                {
                    cout << "\nMovie "
                         << i + 1 << endl;

                    movies[i].displayMovie();
                }
                break;
            }
            case 2:
            {
                int movieChoice;

                cout << "\nSelect Movie";
                cout << "\n1. The Nutcracker";
                cout << "\n2. Do Patti";

                cout << "\nChoice: ";
                cin >> movieChoice;

                if(movieChoice >= 1 &&
                   movieChoice <= 2)
                {
                    movies[movieChoice - 1]
                        .displaySeats();

                    movies[movieChoice - 1]
                        .bookSeat();
                }
                else
                {
                    cout << "\nInvalid Movie!";
                }
                break;
            }
            case 3:
            {
                int movieChoice;

                cout << "\nSelect Movie";
                cout << "\n1. The Nutcracker";
                cout << "\n2. Do Patti";

                cout << "\nChoice: ";
                cin >> movieChoice;

                if(movieChoice >= 1 &&
                   movieChoice <= 2)
                {
                    movies[movieChoice - 1]
                        .cancelSeat();
                }
                break;
            }
            case 4:
            {
                int movieChoice;

                cout << "\nSelect Movie";
                cout << "\n1. The Nutcracker";
                cout << "\n2. Do Patti";

                cout << "\nChoice: ";
                cin >> movieChoice;

                if(movieChoice >= 1 &&
                   movieChoice <= 2)
                {
                    movies[movieChoice - 1]
                        .searchTicket();
                }
                break;
            }
            case 5:
            {
                movies[0].showRevenue();
                movies[1].showRevenue();
                break;
            }
            case 6:
            {
                cout << "\nThank You For Visiting!\n";
                break;
            }
            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }
    }
    while(choice != 6);
    return 0;
}