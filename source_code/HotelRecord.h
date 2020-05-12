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

#ifndef _HOTEL_RECORD_H_
#define _HOTEL_RECORD_H_

#include <math.h>
#include <stdio.h>

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class HotelRecord
{

public:
  HotelRecord(); // constructor function
  HotelRecord(const HotelRecord &hotelRecord); // copy constructor function
  ~HotelRecord(); // destructor function

  void setLocatorId(const string); // Automatically generated string serves as unique identifier for reservation. Must be in form LLNNN-LL (L = character A to Z; N = number 0 to 9)
  string getLocatorId() const;

  void setCheckInDate(const string); //Date guest will check in. Must be in format mm/dd/yyyy. INPUT VALIDATION REQUIRED!
  string getCheckInDate() const;

  void setCheckOutDate(const string); //Date guest will check out. Must be in format mm/dd/yyyy. INPUT VALIDATION REQUIRED!
  string getCheckOutDate() const;

  void setNumberOfDays(const int); // Total number of days that guest will be staying
  int getNumberOfDays() const;

  void setNumberOfOccupants(const int); // Total number of occupants staying in the room
  int getNumberOfOccupants() const;

  void setRate(const double); //dollar amount charge per day for the room
  double getRate() const;

  void setRoomType(const int); // 1 = one king bed; 2 = two king beds; 3 = one queen bed; 4 = two queen beds; 5 = suite; 6 = special request;  INPUT VALIDATION REQUIRED!
  int getRoomType() const;

  void setRoomDescription(const string); // 1 = one king bed; 2 = two king beds; 3 = one queen bed; 4 = two queen beds; 5 = suite; 6 = special request;  INPUT VALIDATION REQUIRED!
  string getRoomDescription() const;

  void setFirstName(const string);
  string getFirstName() const;

  void setLastName(const string);
  string getLastName() const;

  void setStreet(const string);
  string getStreet() const;

  void setCity(const string);
  string getCity() const;

  void setState(const string); // 2-character state abbreviation of where guest resides;  INPUT VALIDATION REQUIRED! (Must be 2 characters)
  string getState() const;

  void setZip(const string); // Zip code where guest resides; INPUT VALIDATION REQUIRED! (Must be five-digit number)
  string getZip() const;

  void setEmail(const string); // Guest's email address; INPUT VALIDATION REQUIRED! (must contain @ character)
  string getEmail() const;

  void setPhoneNumber(const string); // Guest's email address; INPUT VALIDATION REQUIRED! (must contain @ character)
  string getPhoneNumber() const;


private:
  static int reservationCount; // Static variable keeps running count of # of reservation records in the list
  string locatorId = "LOCATOR ID NOT YET ASSIGNED";
  string checkInDate = "mm/dd/yyyy";
  string checkOutDate = "mm/dd/yyyy";
  int numberOfDays = 1;
  int numberOfOccupants = 1;
  double rate = 0.00;
  int roomType = 1;
  string roomDescription = "";
  string firstName = "";
  string lastName =  "";
  string street =  "";
  string city =  "";
  string state =  "";
  string zip =  "";
  string emailAddress =  "";
  string phoneNumber =  "";
};

#endif


