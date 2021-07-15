#pragma once
#include <string>
#include <vector>
using namespace std;
class Address {
	string value;
public:

	void setAddress(string _value) {
		value = _value;
	}
	string getAddress() {
		return value;
	}
};
class Phones {
	long long phoneNum;
public:

	void setPhoneNum(long long _phoneNum) {
		phoneNum = _phoneNum;
	}
	long long getPhoneNum(){
	return phoneNum;
	}
};
class Gender {
	string value;
public:
	void setGender(string _value) {
		value = _value;
	}
	string getGender() {
		return value;
	}
};
class FullName {
	string value;
public:
	FullName(string given, string middle, string family) {
		value = given + " " + middle + " " + " " + family;
	}
	void setFullName(string given,string middle,string family) {
		value = given + " " + middle + " " + " " + family;
	}
	
	string getFullName() const{
		return value;
	}
};
class History {
	vector<string> sicknessList;
public:
	void addSickness(string sickness) {
		sicknessList.push_back(sickness);
	}
	string getSicknessByIndex(size_t i) {
		return sicknessList[i];
	}
	int getSicknessListSize() {
		return sicknessList.size();
	}
};

int getMonth(string month) {
	if (month == "January") {
		return 1;
	}
	else if (month =="February" ) {
		return 2;

	}
	else if (month == "March") {
		return 3;

	}
	else if (month == "April") {
		return 4;

	}
	else if (month == "May") {
		return 5;

	}
	else if (month == "June") {
		return 6;

	}
	else if (month =="July" ) {
		return 7;

	}
	else if (month == "August") {
		return 8;

	}
	else if (month =="September" ) {
		return 9;

	}
	else if (month == "October") {
		return 10;

	}
	else if (month == "November") {
		return 11;

	}
	else if (month == "December") {
		return 12;

	}
}