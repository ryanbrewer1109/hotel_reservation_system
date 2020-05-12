/*
 * M. Ryan Brewer & Hayden Gray
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 * PROJECT 2
 * LAST UPDATED: 07-22-2018  @6:40pm by RB; does not include HG's updated code for modify reservation and modularized validation functions
 *
 *  HotelRecord.h - Class definition for a hotel record.
 *                  This class will be a single node in the linked list.
 *                  ATTRIBUTION NOTE: This code recycles much of the code provided in BookRecord.h
 *
 */


#include "HotelRecord.h"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <math.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


//Global constants (Room Rates)
double RATE_1 = 120.00;
double RATE_2 = 150.00;
double RATE_3 = 100.00;
double RATE_4 = 130.00;
double RATE_5 = 180.00;
double RATE_6 = 140.00;

HotelRecord::HotelRecord()
{
    this-> locatorId = "UNASSIGNED";
    this-> checkInDate = "UNASSIGNED";
    this-> checkOutDate = "UNASSIGNED";
    this-> numberOfDays = 0;
    this-> numberOfOccupants = 0;
    this-> rate = 0.00;
    this-> roomType = 0;
    //Guest Info
    this-> roomDescription = "UNASSIGNED";
    this-> firstName = "UNASSIGNED";
    this-> lastName = "UNASSIGNED";
    this-> street = "UNASSIGNED";
    this-> city = "UNASSIGNED";
    this-> state = "UNASSIGNED";
    this-> zip = "UNASSIGNED";
    this-> emailAddress = "UNASSIGNED";
    this-> phoneNumber = "UNASSIGNED";
}

// Copy constructor
HotelRecord::HotelRecord(const HotelRecord &hotelRecord)
{
  this-> locatorId = hotelRecord.locatorId;
  this-> checkInDate = hotelRecord.checkInDate;
  this-> checkOutDate = hotelRecord.checkOutDate;
  this-> numberOfDays = hotelRecord.numberOfDays;
  this-> numberOfOccupants = hotelRecord.numberOfOccupants;
  this-> rate = hotelRecord.rate;
  this-> roomType = hotelRecord.roomType;
  //Guest Info
  this-> firstName = hotelRecord.firstName;
  this-> lastName = hotelRecord.lastName;
  this-> street = hotelRecord.street;
  this-> city = hotelRecord.city;
  this-> state = hotelRecord.state;
  this-> zip = hotelRecord.zip;
  this-> emailAddress = hotelRecord.emailAddress;
  this-> phoneNumber = hotelRecord.phoneNumber;
}

// Object destructor
HotelRecord::~HotelRecord()
{
    // Currently does nothing else...
}

// Must be unique, and in format LLNNN-LL (L = character A to Z; N = number 0 to 9)
void HotelRecord::setLocatorId(const string locId)
{
 this->locatorId = locId ;
}

string HotelRecord::getLocatorId() const
{
  return locatorId;
}

void HotelRecord::setCheckInDate(const string checkIn) //Date guest will check in. Must be in format mm/dd/yyyy. INPUT VALIDATION REQUIRED!
{
 this->checkInDate = checkIn ;
}

string HotelRecord::getCheckInDate() const
{
    return checkInDate;
}

void HotelRecord::setCheckOutDate(const string checkOut) //Date guest will check out. Must be in format mm/dd/yyyy. INPUT VALIDATION REQUIRED!
{
this-> checkOutDate = checkOut;
}
  string HotelRecord::getCheckOutDate() const
{
    return checkOutDate;
}

void HotelRecord::setNumberOfDays(const int numDays) // Total number of days that guest will be staying
{
this->numberOfDays = numDays;
}
int HotelRecord::getNumberOfDays() const
{
    return numberOfDays;
}

void HotelRecord::setNumberOfOccupants(const int numOccupants) // Total number of occupants staying in the room
{
this-> numberOfOccupants = numOccupants;
}
int HotelRecord::getNumberOfOccupants() const
{
    return numberOfOccupants;
}

void HotelRecord::setRoomType(const int room) // 1 = one king bed; 2 = two king beds; 3 = one queen bed; 4 = two queen beds; 5 = suite; 6 = special request;  INPUT VALIDATION REQUIRED!
{

    this->roomType = room;
    switch(roomType) // Set rate for room based on type of room requested
    {
        case 1:
            HotelRecord::setRoomDescription ("One King-size Bed");
 /* Following lines of code used for troubleshooting purposes only
            cout << "The setRoomDesciption function was called with argument 'OneKing-sizeBed'.\n";
            cout << "The roomDescription variable now has the following value: " << getRoomDescription() << endl;
*/
            HotelRecord::setRate(RATE_1); // Removed the const int before RATE, compiler thought it was declaration - HG
            break; //optional
        case 2:
            HotelRecord::setRoomDescription ("Two King-size Beds");
            HotelRecord::setRate(RATE_2); // Removed the const int before RATE, compiler thought it was declaration - HG
            break; //optional
        case 3:
            HotelRecord::setRoomDescription ("One Queen-size Bed");
            HotelRecord::setRate(RATE_3); // Removed the const int before RATE, compiler thought it was declaration - HG
            break; //optional
        case 4:
            HotelRecord::setRoomDescription ("Two Queen-size Beds");
            HotelRecord::setRate(RATE_4); // Removed the const int before RATE, compiler thought it was declaration - HG
            break; //optional
        case 5:
            HotelRecord::setRoomDescription ("Suite");
            HotelRecord::setRate(RATE_5); // Removed the const int before RATE, compiler thought it was declaration - HG
              break; //optional
        case 6:
            HotelRecord::setRoomDescription ("Special Request");
            HotelRecord::setRate(RATE_6); // Removed the const int before RATE, compiler thought it was declaration - HG // This room type is "special request;" This code assumes this is a standard rate (e.g., handicap accessible room). If rate should be adjustable, may need to prompt user to enter applicable rate.
            break; //optional
        } // End switch statement
/*
        double dailyCost = HotelRecord::getRate();
        cout << "Room Description: " << roomDescription << endl;
        cout << "Daily Room Rate: $" << fixed << setprecision(2) << dailyCost << endl;
        cout << "Subtotal for Stay: $" << setprecision(2) << dailyCost * numberOfDays<< endl;
*/
} // End setRoomType function

int HotelRecord::getRoomType() const
{
    return roomType;
}


void HotelRecord::setRoomDescription(const string beds) // 1 = one king bed; 2 = two king beds; 3 = one queen bed; 4 = two queen beds; 5 = suite; 6 = special request;  INPUT VALIDATION REQUIRED!
{
    this->roomDescription = beds;
}

string HotelRecord::getRoomDescription() const
{
    return roomDescription;
}


void HotelRecord::setRate(const double dailyRate) //Dollar amount charge per day for the room; allows user to manually override default rates.
{
this-> rate = dailyRate;
}
double HotelRecord::getRate() const
{
    return rate;
}

void HotelRecord::setFirstName(const string firstNm)
{
this-> firstName = firstNm;
}
string HotelRecord::getFirstName() const
{
    return firstName;
}

void HotelRecord::setLastName(const string lastNm)
{
this-> lastName = lastNm ;
}
string HotelRecord::getLastName() const
{
    return lastName;
}

void HotelRecord::setStreet(const string streetAddress)
{
this-> street = streetAddress;
}
string HotelRecord::getStreet() const
{
    return street;
}

void HotelRecord::setCity(const string cityAddress)
{
this-> city = cityAddress ;
}
string HotelRecord::getCity() const
{
    return city;
}

void HotelRecord::setState(const string stateAddress) // 2-character state abbreviation of where guest resides;  INPUT VALIDATION REQUIRED! (Must be 2 characters)
{
this-> state = stateAddress ;
}
string HotelRecord::getState() const
{
    return state;
}

void HotelRecord::setZip(const string zipCode) // Zip code where guest resides; INPUT VALIDATION REQUIRED! (Must be five-digit number)
{
this->  zip = zipCode;
}
string HotelRecord::getZip() const
{
    return zip;
}

void HotelRecord::setEmail(const string email) // Guest's email address; INPUT VALIDATION REQUIRED! (must contain @ character)
{
this-> emailAddress = email;
}
string HotelRecord::getEmail() const
{
    return emailAddress;
}

void HotelRecord::setPhoneNumber(const string phoneNum) // Guest's email address; INPUT VALIDATION REQUIRED! (must contain @ character)
{
this-> phoneNumber = phoneNum;

}
string HotelRecord::getPhoneNumber() const
{
    return phoneNumber;
}
