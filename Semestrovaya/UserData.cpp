#include "UserData.h"

using namespace System;



UserData::UserData() : l_name(""), year_start_up(0), phone(""), street(""), house(0), number_apart(0) {}

UserData::UserData(String^ l_name, int year_start_up, String^ phone, String^ street, int house, int number_apart)
	: l_name(l_name), year_start_up(year_start_up), phone(phone), street(street), house(house),
	number_apart(number_apart) {}
