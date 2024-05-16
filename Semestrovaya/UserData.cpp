#include "UserData.h"

using namespace System;



UserData::UserData() : lName(""), yearStartUp(0), phone(""), street(""), house(0), numberApart(0) {}

UserData::UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart)
	: lName(l_name), yearStartUp(year_start_up), phone(phone), street(street), house(house),
	numberApart(number_apart) {}
