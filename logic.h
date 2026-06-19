#pragma once

#include <string>

std::string getSeatCategory(int seatNum);

bool validCardNumber(std::string cardNumber);

bool validCVV(std::string cvv);

bool validExpiryMonth(int month);

bool sufficientCash(int paid, int amount);