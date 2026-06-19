#include "logic.h"
#include <string>
using namespace std;

string getSeatCategory(int seatNum)
{
    if(seatNum >= 1 && seatNum <= 30)
        return "Silver";
    else if(seatNum >= 31 && seatNum <= 50)
        return "Gold";
    else
        return "Platinum";
}

bool validCardNumber(string cardNumber)
{
    return cardNumber.length() == 16;
}

bool validCVV(string cvv)
{
    return cvv.length() == 3;
}

bool validExpiryMonth(int month)
{
    return month >= 1 && month <= 12;
}

bool sufficientCash(int paid, int amount)
{
    return paid >= amount;
}
