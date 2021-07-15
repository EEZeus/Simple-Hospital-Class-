#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include "Header.h"
#include "DataType.h"
using namespace std;

void printForm() {
	cout << "\n1 :" << "ADD Hospital." << endl;
	cout << "2 :" << "ADD Patient." << endl;
	cout << "3 :" << "ADD Doctor." << endl;
	cout << "4 :" << "ADD Surgeon." << endl;
	cout << "5 :" << "ADD Nurse." << endl;
	cout << "6 :" << "ADD Receptionist." << endl;
	cout << "7 :" << "ADD Technician." << endl;
	cout << "8 :" << "ADD Surgical Technologist." << endl;
	cout << "9 :" << "Delete Hospital By Name ." << endl;
	cout << "10 :" << "Delete Member By FullName." << endl;
	cout << "11 :" << "Find Member(Patient By Id | Staff By FullName)." << endl;
	cout << "12 :" << "Find ALL Technical Staffs Who Have Been Sick Before A Specefic Date." << endl;
	cout << "13 :" << "Find ALL Doctors Who Are Also Patient." << endl;
	cout << "14 :" << "Find ALL Surgeons." << endl;
	cout << "15 :" << "Find ALL Nurses Who Are Also Patient." << endl;
	cout << "16 :" << "Find ALL Patients  Who Have Been Sick In Two Specefic Dates." << endl;
	cout << "17 :" << "Graph Of All Diseases Type And Percentage Of Each Disease." << endl;
	cout << "18 :" << "Getting Percentage Of People Infected By A Specefic Disease." << endl;
	cout << "19 :" << "Getting Percentage Of Doctors Who Are Infected By A Specefic Disease." << endl;
	cout << "20 :" << "Exit." << endl;
}
void addHospitalInfoIntoVector(vector<Hospital*> &_hospitals) {
	_hospitals.clear();
	ifstream in_file("Hospital_Info.txt");
	if (!in_file) {
		cout << "File Can't Be Opened !\n";
		return;
	}
	string line;
	while (getline(in_file, line)) {
		_hospitals.push_back(new Hospital);
		int index1;
		int index2;
		string c;
		index1 = line.find("name$") + 5;
		index2 = line.find("#address$");
		for (int i = index1; i < index2; i++) {
			c += line[i];
		}
		_hospitals[_hospitals.size() - 1]->setName(c);
		index1 = index2 + 9;
		index2 = line.find("#phone$");
		c = "";
		for (int i = index1; i < index2; i++) {
			c += line[i];
		}
		Address* a1 = new Address();
		a1->setAddress(c);
		_hospitals[_hospitals.size() - 1]->setAddress(*a1);

		index1 = index2 + 7;
		index2 = line.size();
		c = "";
		for (int i = index1; i < index2; i++) {
			c += line[i];
		}
		Phones* p1 = new Phones;
		long long num = stoll(c);
		p1->setPhoneNum(num);
		_hospitals[_hospitals.size() - 1]->setPhone(*p1);
	}
	in_file.close();
}
void addHospital(vector<Hospital*> &_hospitals) {
	Hospital* h1 = new Hospital;
	string input;
	cout << "Enter Hospital Name : ";
	cin >> input;
	h1->setName(input);
	cout << "Enter Hospital Address : ";
	cin >> input;
	Address* a1=new Address;
	a1->setAddress(input);
	h1->setAddress(*a1);
	cout << "Enter Hospital Phone : ";
	long long number;
	cin >> number;
	Phones* phone1 = new Phones;
	phone1->setPhoneNum(number);
	h1->setPhone (*phone1);
	ofstream out_file("Hospital_Info.txt", ios::app);
	if (!out_file) {
		cout << "File Can't Be Opened !";
		return;
	}
	out_file << "name$" << h1->getName() << "#address$" << h1->getAddress().getAddress() << "#phone$" << h1->getPhone().getPhoneNum() << endl;
	out_file.close();
	addHospitalInfoIntoVector(_hospitals);
}
void addPatient(){
	Patient* p1 = new Patient();
	p1->setTitle("patient");
	string input;
	int num;
	cout << "Enter The ID Of Patient : ";
	cin >> input;
	p1->setId(input);
	cout << "Enter The Age Of Patient(ex : 18) : ";
	cin >> num;
	p1->setAge(num);
	cout << "Enter Patient Given Name ALL In Small Case: ";
	cin >> input;
	p1->setGivenName(input);
	cout << "Enter Patient Middle Name ALL In Small Case: ";
	cin >> input;
	p1->setMiddleName(input);
	cout << "Enter Patient Family Name ALL In Small Case: ";
	cin >> input;
	p1->setFamilyName(input);
	
	int day, month, year;

	cout << "Enter Day , Month And Year Of Patient's BirthDate Seperated By Single Spaces : ";
	cin >> day >> month >> year;
	Date *d1 = new Date(day, month, year);
	p1->setBirthDate(*d1);
	cout << "Enter Day , Month And Year Of Patient's Accepted Date Seperated By Single Spaces : ";
	cin >> day >> month >> year;
	d1 = new Date(day,month,year);
	p1->setAccepted(*d1);
	History* sickness = new History();
	cout << "How Many Siknesses Patient Has?";
	
	cin >> num;
	for (size_t i = 0; i < num;i++) {
		cout << "Enter Title Of Patient's Sickness : ";
		cin >> input;
		sickness->addSickness(input);
	}
	p1->setSickness(*sickness);
	cout << "Enter Gender Of Patient : ";
	cin >> input;
	Gender *gender = new Gender;
	gender->setGender(input);
	p1->setGender(*gender);
	cout << "Enter Address Of Patient : ";
	cin >> input;
	Address *address = new Address;
	address->setAddress(input);
	p1->setHomeAddress(*address);
	cout << "Enter Patient's Phone Number(+98922***9155) : ";
	long long number;
	cin >> number;
	Phones *phone = new Phones;
	phone->setPhoneNum(number);
	p1->setPhone(*phone);
	cout << "How Many prescriptions Titles Do You Want To Add : " << endl;
	cin >>num;
	for (size_t i = 0; i < num;i++) {
		cout << "Enter Title Of Patients Prescription : ";
		cin >> input;
		p1->addPrescriptions(input);
	}
	cout << "How Many Allergy Titles Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Patients Allergy : ";
		cin >> input;
		p1->addAllergies(input);
	}
	cout << "How Many Speacial Request Titles Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Patients Speacial Request : ";
		cin >> input;
		p1->addSpecialReqs(input);
	}
	ofstream out_file("Person_Info.txt",ios::app);
		if (!out_file) {
			cout << "File Can't Be Opened !";
				return;
		}
		out_file << "title$" << p1->getTitle() << "#" << "fullname$" << p1->getFullName().getFullName() << "#" << "birthdate$"
			<< p1->getBirthDate().display() << "#" << "gender$" << p1->getGender().getGender() << "#" << "homeaddress$" << p1->getHomeAddress().getAddress()
			<< "#" << "phone$" << p1->getPhone().getPhoneNum() << "#" << "id$" << p1->getId() << "#" << "age$" << p1->getAge() << "#"
			<< "accepted$" << p1->getAccepted().display() << "#"<<"sickness";
		for (size_t i = 0; i < p1->getSickness().getSicknessListSize(); i++) {
			out_file << "$" << p1->getSickness().getSicknessByIndex(i);
		}
		out_file << "#prescriptions";
		for (size_t i = 0; i < p1->getPrescriptionsSizeOfList(); i++) {
			out_file << "$" << p1->getPrescriptionByIndex(i);
		}
		out_file << "#allergies";
		for (size_t i = 0; i < p1->getAllergiesSizeOfList(); i++) {
			out_file << "$" << p1->getAllergiesByIndex(i);
		}
		out_file << "#specialReqs";
		for (size_t i = 0; i < p1->getSpecialReqsSizeOfList(); i++) {
			out_file << "$" << p1->getSpecialReqsByIndex(i);
		}
		out_file << endl;
		out_file.close();
}
void addDoctor(vector<Hospital*>& _hospitals) {
	string nameOfHospital;
	int indexHospital = -1;
	cout << "Enter The Name Of Doctor's Hospital :";
	cin >> nameOfHospital;
	for (int i = 0; i < _hospitals.size(); i++) {
		if (nameOfHospital == _hospitals.at(i)->getName()) {
			indexHospital = i;
			break;
		}
	}
	if (indexHospital != -1) {
		string input;
	_hospitals.at(indexHospital)->staff = new Doctor;
	_hospitals.at(indexHospital)->staff->setTitle("doctor");
	cout << "Enter Doctor Given Name ALL In Small Case: ";
	cin >> input;
	_hospitals.at(indexHospital)->staff->setGivenName(input);
	cout << "Enter Doctor Middle Name ALL In Small Case: ";
	cin >> input;
	_hospitals.at(indexHospital)->staff->setMiddleName(input);
	cout << "Enter Doctor Family Name ALL In Small Case: ";
	cin >> input;
	_hospitals.at(indexHospital)->staff->setFamilyName(input);
	int day, month, year;
	cout << "Enter Day , Month And Year Of Doctor's BirthDate Seperated By Single Spaces : ";
	cin >> day >> month >> year;
	Date* d1 = new Date(day, month, year);
	_hospitals.at(indexHospital)->staff->setBirthDate(*d1);
	cout << "Enter Gender Of Doctor : ";
	cin >> input;
	Gender* gender = new Gender;
	gender->setGender(input);
	_hospitals.at(indexHospital)->staff->setGender(*gender);
	cout << "Enter Address Of Doctor : ";
	cin >> input;
	Address* address = new Address;
	address->setAddress(input);
	_hospitals.at(indexHospital)->staff->setHomeAddress(*address);
	cout << "Enter Doctor's Phone Number(+98922***9155) : ";
	long long number;
	cin >> number;
	Phones* phone = new Phones;
	phone->setPhoneNum(number);
	_hospitals.at(indexHospital)->staff->setPhone(*phone);
	cout << "Enter Day , Month And Year Of Doctor's Joined Date Seperated By Single Spaces : ";
	cin >> day >> month >> year;
	d1 = new Date(day, month, year);
	_hospitals.at(indexHospital)->staff->setJoined(*d1);
	int num;
	cout << "How Many Eduacation Titles Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Doctors Education : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addEducation(input);
	}
	cout << "How Many Certification Titles Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Doctors Certification : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addCertification(input);
	}
	cout << "How Many Languages Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Doctors Language : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addLanguage(input);
	}
	cout << "How Many Specialties Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Doctor's Specialty : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addSpecialty(input);
	}
	cout << "How Many Locations Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Doctor's Location : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addLocation(input);
	}

	ofstream out_file("Person_Info.txt", ios::app);
	if (!out_file) {
		cout << "File Can't Be Opened !";
		return;
	}
	out_file << "hospital$" << nameOfHospital << "#title$" << _hospitals.at(indexHospital)->staff->getTitle() << "#" << "fullname$" << _hospitals.at(indexHospital)->staff->getFullName().getFullName() << "#" << "birthdate$"
		<< _hospitals.at(indexHospital)->staff->getBirthDate().display() << "#" << "gender$" << _hospitals.at(indexHospital)->staff->getGender().getGender() << "#" << "homeaddress$" << _hospitals.at(indexHospital)->staff->getHomeAddress().getAddress()
		<< "#" << "phone$" << _hospitals.at(indexHospital)->staff->getPhone().getPhoneNum() << "#" << "joined$" << _hospitals.at(indexHospital)->staff->getJoined().display() << "#"
		<< "education";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getEducationSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->get_EducationsByIndex(i);
	}
	out_file << "#certification";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getCertificationSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getCertificationByIndex(i);
	}
	out_file << "#languages";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLanguagesSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getLanguageByIndex(i);
	}
	out_file << "#specialty";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getSpecialtySizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getSpecialtyByIndex(i);
	}
	out_file << "#location";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLocationSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getLocationByIndex(i);
	}
	out_file << endl;
	out_file.close();
	}
	else {
	cout << "Invalid Hospital Name !";
}
}
void addSurgeon(vector<Hospital*>& _hospitals) {
	string nameOfHospital;
	int indexHospital = -1;	cout << "Enter The Name Of Surgeon's Hospital :";
	cin >> nameOfHospital;
	for (int i = 0; i < _hospitals.size(); i++) {
		if (nameOfHospital == _hospitals.at(i)->getName()) {
			indexHospital = i;
			break;
		}
	}
	if (indexHospital != -1) {
	string input;
	_hospitals.at(indexHospital)->staff = new Surgeon;
	_hospitals.at(indexHospital)->staff->setTitle("surgeon");
	cout << "Enter Surgeon's Given Name ALL In Small Case: ";
	cin >> input;
	_hospitals.at(indexHospital)->staff->setGivenName(input);
	cout << "Enter Surgeon's Middle Name ALL In Small Case: ";
	cin >> input;
	_hospitals.at(indexHospital)->staff->setMiddleName(input);
	cout << "Enter Surgeon's Family Name ALL In Small Case: ";
	cin >> input;
	_hospitals.at(indexHospital)->staff->setFamilyName(input);
	int day, month, year;
	cout << "Enter Day , Month And Year Of Surgeon's BirthDate Seperated By Single Spaces : ";
	cin >> day >> month >> year;
	Date* d1 = new Date(day, month, year);
	_hospitals.at(indexHospital)->staff->setBirthDate(*d1);
	cout << "Enter Gender Of Surgeon : ";
	cin >> input;
	Gender* gender = new Gender;
	gender->setGender(input);
	_hospitals.at(indexHospital)->staff->setGender(*gender);
	cout << "Enter Address Of Surgeon : ";
	cin >> input;
	Address* address = new Address;
	address->setAddress(input);
	_hospitals.at(indexHospital)->staff->setHomeAddress(*address);
	cout << "Enter Surgeon's Phone Number(+98922***9155) : ";
	long long number;
	cin >> number;
	Phones* phone = new Phones;
	phone->setPhoneNum(number);
	_hospitals.at(indexHospital)->staff->setPhone(*phone);
	cout << "Enter Day , Month And Year Of Surgeon's Joined Date Seperated By Single Spaces : ";
	cin >> day >> month >> year;
	d1 = new Date(day, month, year);
	_hospitals.at(indexHospital)->staff->setJoined(*d1);
	int num;
	cout << "How Many Eduacation Titles Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Surgeon's Education : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addEducation(input);
	}
	cout << "How Many Certification Titles Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Surgeon's Certification : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addCertification(input);
	}
	cout << "How Many Languages Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Surgeon's Language : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addLanguage(input);
	}
	cout << "How Many Specialties Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Surgeon's Specialty : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addSpecialty(input);
	}
	cout << "How Many Locations Do You Want To Add : " << endl;
	cin >> num;
	for (size_t i = 0; i < num; i++) {
		cout << "Enter Title Of Surgeon's Location : ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->addLocation(input);
	}

	ofstream out_file("Person_Info.txt", ios::app);
	if (!out_file) {
		cout << "File Can't Be Opened !";
		return;
	}
	out_file << "hospital$" << nameOfHospital << "#title$" << _hospitals.at(indexHospital)->staff->getTitle() << "#" << "fullname$" << _hospitals.at(indexHospital)->staff->getFullName().getFullName()<< "#" << "birthdate$"
		<< _hospitals.at(indexHospital)->staff->getBirthDate().display() << "#" << "gender$" << _hospitals.at(indexHospital)->staff->getGender().getGender() << "#" << "homeaddress$" << _hospitals.at(indexHospital)->staff->getHomeAddress().getAddress()
		<< "#" << "phone$" << _hospitals.at(indexHospital)->staff->getPhone().getPhoneNum() << "#" << "joined$" << _hospitals.at(indexHospital)->staff->getJoined().display() << "#"
		<< "education";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getEducationSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->get_EducationsByIndex(i);
	}
	out_file << "#certification";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getCertificationSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getCertificationByIndex(i);
	}
	out_file << "#languages";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLanguagesSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getLanguageByIndex(i);
	}
	out_file << "#specialty";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getSpecialtySizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getSpecialtyByIndex(i);
	}
	out_file << "#location";
	for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLocationSizeOfList(); i++) {
		out_file << "$" << _hospitals.at(indexHospital)->staff->getLocationByIndex(i);
	}
	out_file << endl;
	out_file.close();
	}
	else {
	cout << "Invalid Hospital Name !";
}
}
void addNurse(vector<Hospital*>& _hospitals) {
	string nameOfHospital;
	int indexHospital = -1;
	cout << "Enter The Name Of Nurse's Hospital :";
	cin >> nameOfHospital;
	for (int i = 0; i < _hospitals.size(); i++) {
		if (nameOfHospital == _hospitals.at(i)->getName()) {
			indexHospital = i;
			break;
		}
	}
	if (indexHospital != -1) {
		string input;
		_hospitals.at(indexHospital)->staff = new Nurse;
		_hospitals.at(indexHospital)->staff->setTitle("nurse");
		cout << "Enter Nurse Given Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setGivenName(input);
		cout << "Enter Nurse Middle Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setMiddleName(input);
		cout << "Enter Nurse Family Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setFamilyName(input);
		int day, month, year;
		cout << "Enter Day , Month And Year Of Nurse's BirthDate Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		Date* d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setBirthDate(*d1);
		cout << "Enter Gender Of Nurse : ";
		cin >> input;
		Gender* gender = new Gender;
		gender->setGender(input);
		_hospitals.at(indexHospital)->staff->setGender(*gender);
		cout << "Enter Address Of Nurse : ";
		cin >> input;
		Address* address = new Address;
		address->setAddress(input);
		_hospitals.at(indexHospital)->staff->setHomeAddress(*address);
		cout << "Enter Nurse's Phone Number(+98922***9155) : ";
		long long number;
		cin >> number;
		Phones* phone = new Phones;
		phone->setPhoneNum(number);
		_hospitals.at(indexHospital)->staff->setPhone(*phone);
		cout << "Enter Day , Month And Year Of Nurse's Joined Date Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setJoined(*d1);
		int num;
		cout << "How Many Eduacation Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Nurse's Education : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addEducation(input);
		}
		cout << "How Many Certification Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Nurse's Certification : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addCertification(input);
		}
		cout << "How Many Languages Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Nurse's Language : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addLanguage(input);
		}
		ofstream out_file("Person_Info.txt", ios::app);
		if (!out_file) {
			cout << "File Can't Be Opened !";
			return;
		}
		out_file << "hospital$" << nameOfHospital << "#title$" << _hospitals.at(indexHospital)->staff->getTitle() << "#" << "fullname$" << _hospitals.at(indexHospital)->staff->getFullName().getFullName() << "#" << "birthdate$"
			<< _hospitals.at(indexHospital)->staff->getBirthDate().display() << "#" << "gender$" << _hospitals.at(indexHospital)->staff->getGender().getGender() << "#" << "homeaddress$" << _hospitals.at(indexHospital)->staff->getHomeAddress().getAddress()
			<< "#" << "phone$" << _hospitals.at(indexHospital)->staff->getPhone().getPhoneNum() << "#" << "joined$" << _hospitals.at(indexHospital)->staff->getJoined().display() << "#"
			<< "education";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getEducationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->get_EducationsByIndex(i);
		}
		out_file << "#certification";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getCertificationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getCertificationByIndex(i);
		}
		out_file << "#languages";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLanguagesSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getLanguageByIndex(i);
		}
		out_file << endl;
		out_file.close();
	}
	else {
		cout << "Invalid Hospital Name !";
	}
}
void addReceptionist(vector<Hospital*>& _hospitals) {
	string nameOfHospital;
	int indexHospital = -1;
	cout << "Enter The Name Of Receptionist's Hospital :";
	cin >> nameOfHospital;
	for (int i = 0; i < _hospitals.size(); i++) {
		if (nameOfHospital == _hospitals.at(i)->getName()) {
			indexHospital = i;
			break;
		}
	}
	if (indexHospital != -1) {
		string input;
		_hospitals.at(indexHospital)->staff = new Receptionist;
		_hospitals.at(indexHospital)->staff->setTitle("receptionist");
		cout << "Enter Receptionist Given Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setGivenName(input);
		cout << "Enter Receptionist Middle Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setMiddleName(input);
		cout << "Enter Receptionist Family Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setFamilyName(input);
		int day, month, year;
		cout << "Enter Day , Month And Year Of Receptionist's BirthDate Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		Date* d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setBirthDate(*d1);
		cout << "Enter Gender Of Receptionist : ";
		cin >> input;
		Gender* gender = new Gender;
		gender->setGender(input);
		_hospitals.at(indexHospital)->staff->setGender(*gender);
		cout << "Enter Address Of Receptionist : ";
		cin >> input;
		Address* address = new Address;
		address->setAddress(input);
		_hospitals.at(indexHospital)->staff->setHomeAddress(*address);
		cout << "Enter Receptionist's Phone Number(+98922***9155) : ";
		long long number;
		cin >> number;
		Phones* phone = new Phones;
		phone->setPhoneNum(number);
		_hospitals.at(indexHospital)->staff->setPhone(*phone);
		cout << "Enter Day , Month And Year Of Receptionist's Joined Date Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setJoined(*d1);
		int num;
		cout << "How Many Eduacation Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Receptionist's Education : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addEducation(input);
		}
		cout << "How Many Certification Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Receptionist's Certification : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addCertification(input);
		}
		cout << "How Many Languages Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Receptionist's Language : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addLanguage(input);
		}
		ofstream out_file("Person_Info.txt", ios::app);
		if (!out_file) {
			cout << "File Can't Be Opened !";
			return;
		}
		out_file << "hospital$" << nameOfHospital << "#title$" << _hospitals.at(indexHospital)->staff->getTitle() << "#" << "fullname$" << _hospitals.at(indexHospital)->staff->getFullName().getFullName() << "#" << "birthdate$"
			<< _hospitals.at(indexHospital)->staff->getBirthDate().display() << "#" << "gender$" << _hospitals.at(indexHospital)->staff->getGender().getGender() << "#" << "homeaddress$" << _hospitals.at(indexHospital)->staff->getHomeAddress().getAddress()
			<< "#" << "phone$" << _hospitals.at(indexHospital)->staff->getPhone().getPhoneNum() << "#" << "joined$" << _hospitals.at(indexHospital)->staff->getJoined().display() << "#"
			<< "education";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getEducationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->get_EducationsByIndex(i);
		}
		out_file << "#certification";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getCertificationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getCertificationByIndex(i);
		}
		out_file << "#languages";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLanguagesSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getLanguageByIndex(i);
		}
		out_file << endl;
		out_file.close();
	}
	else {
		cout << "Invalid Hospital Name !";
	}
}
void addTechnician(vector<Hospital*>& _hospitals) {
	string nameOfHospital;
	int indexHospital = -1;
	cout << "Enter The Name Of Technician's Hospital :";
	cin >> nameOfHospital;
	for (int i = 0; i < _hospitals.size(); i++) {
		if (nameOfHospital == _hospitals.at(i)->getName()) {
			indexHospital = i;
			break;
		}
	}
	if (indexHospital != -1) {
		string input;
		_hospitals.at(indexHospital)->staff = new Technician;
		_hospitals.at(indexHospital)->staff->setTitle("technician");
		cout << "Enter Technician Given Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setGivenName(input);
		cout << "Enter Technician Middle Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setMiddleName(input);
		cout << "Enter Technician Family Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setFamilyName(input);
		int day, month, year;
		cout << "Enter Day , Month And Year Of Technician's BirthDate Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		Date* d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setBirthDate(*d1);
		cout << "Enter Gender Of Technician : ";
		cin >> input;
		Gender* gender = new Gender;
		gender->setGender(input);
		_hospitals.at(indexHospital)->staff->setGender(*gender);
		cout << "Enter Address Of Technician : ";
		cin >> input;
		Address* address = new Address;
		address->setAddress(input);
		_hospitals.at(indexHospital)->staff->setHomeAddress(*address);
		cout << "Enter Technician's Phone Number(+98922***9155) : ";
		long long number;
		cin >> number;
		Phones* phone = new Phones;
		phone->setPhoneNum(number);
		_hospitals.at(indexHospital)->staff->setPhone(*phone);
		cout << "Enter Day , Month And Year Of Technician's Joined Date Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setJoined(*d1);
		int num;
		cout << "How Many Eduacation Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Technician's Education : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addEducation(input);
		}
		cout << "How Many Certification Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Technician's Certification : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addCertification(input);
		}
		cout << "How Many Languages Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of Technician's Language : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addLanguage(input);
		}
		ofstream out_file("Person_Info.txt", ios::app);
		if (!out_file) {
			cout << "File Can't Be Opened !";
			return;
		}
		out_file << "hospital$" << nameOfHospital << "#title$" << _hospitals.at(indexHospital)->staff->getTitle() << "#" << "fullname$" << _hospitals.at(indexHospital)->staff->getFullName().getFullName() << "#" << "birthdate$"
			<< _hospitals.at(indexHospital)->staff->getBirthDate().display() << "#" << "gender$" << _hospitals.at(indexHospital)->staff->getGender().getGender() << "#" << "homeaddress$" << _hospitals.at(indexHospital)->staff->getHomeAddress().getAddress()
			<< "#" << "phone$" << _hospitals.at(indexHospital)->staff->getPhone().getPhoneNum() << "#" << "joined$" << _hospitals.at(indexHospital)->staff->getJoined().display() << "#"
			<< "education";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getEducationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->get_EducationsByIndex(i);
		}
		out_file << "#certification";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getCertificationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getCertificationByIndex(i);
		}
		out_file << "#languages";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLanguagesSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getLanguageByIndex(i);
		}
		out_file << endl;
		out_file.close();
	}
	else {
		cout << "Invalid Hospital Name !";
	}
}
void addSurgicalTechnologist(vector<Hospital*>& _hospitals) {
	string nameOfHospital;
	int indexHospital = -1;
	cout << "Enter The Name Of Surgical Technologist's Hospital :";
	cin >> nameOfHospital;
	for (int i = 0; i < _hospitals.size(); i++) {
		if (nameOfHospital == _hospitals.at(i)->getName()) {
			indexHospital = i;
			break;
		}
	}
	if (indexHospital != -1) {
		string input;
		_hospitals.at(indexHospital)->staff = new SurgicalTechnologist;
		_hospitals.at(indexHospital)->staff->setTitle("surgicaltechnologist");
		cout << "Enter SurgicalTechnologist Given Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setGivenName(input);
		cout << "Enter SurgicalTechnologist Middle Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setMiddleName(input);
		cout << "Enter SurgicalTechnologist Family Name ALL In Small Case: ";
		cin >> input;
		_hospitals.at(indexHospital)->staff->setFamilyName(input);
		int day, month, year;
		cout << "Enter Day , Month And Year Of SurgicalTechnologist's BirthDate Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		Date* d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setBirthDate(*d1);
		cout << "Enter Gender Of SurgicalTechnologist : ";
		cin >> input;
		Gender* gender = new Gender;
		gender->setGender(input);
		_hospitals.at(indexHospital)->staff->setGender(*gender);
		cout << "Enter Address Of SurgicalTechnologist : ";
		cin >> input;
		Address* address = new Address;
		address->setAddress(input);
		_hospitals.at(indexHospital)->staff->setHomeAddress(*address);
		cout << "Enter SurgicalTechnologist's Phone Number(+98922***9155) : ";
		long long number;
		cin >> number;
		Phones* phone = new Phones;
		phone->setPhoneNum(number);
		_hospitals.at(indexHospital)->staff->setPhone(*phone);
		cout << "Enter Day , Month And Year Of SurgicalTechnologist's Joined Date Seperated By Single Spaces : ";
		cin >> day >> month >> year;
		d1 = new Date(day, month, year);
		_hospitals.at(indexHospital)->staff->setJoined(*d1);
		int num;
		cout << "How Many Eduacation Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of SurgicalTechnologist's Education : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addEducation(input);
		}
		cout << "How Many Certification Titles Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of SurgicalTechnologist's Certification : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addCertification(input);
		}
		cout << "How Many Languages Do You Want To Add : " << endl;
		cin >> num;
		for (size_t i = 0; i < num; i++) {
			cout << "Enter Title Of SurgicalTechnologist's Language : ";
			cin >> input;
			_hospitals.at(indexHospital)->staff->addLanguage(input);
		}
		ofstream out_file("Person_Info.txt", ios::app);
		if (!out_file) {
			cout << "File Can't Be Opened !";
			return;
		}
		out_file << "hospital$" << nameOfHospital << "title$" << _hospitals.at(indexHospital)->staff->getTitle() << "#" << "fullname$" << _hospitals.at(indexHospital)->staff->getFullName().getFullName() << "#" << "birthdate$"
			<< _hospitals.at(indexHospital)->staff->getBirthDate().display() << "#" << "gender$" << _hospitals.at(indexHospital)->staff->getGender().getGender() << "#" << "homeaddress$" << _hospitals.at(indexHospital)->staff->getHomeAddress().getAddress()
			<< "#" << "phone$" << _hospitals.at(indexHospital)->staff->getPhone().getPhoneNum() << "#" << "joined$" << _hospitals.at(indexHospital)->staff->getJoined().display() << "#"
			<< "education";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getEducationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->get_EducationsByIndex(i);
		}
		out_file << "#certification";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getCertificationSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getCertificationByIndex(i);
		}
		out_file << "#languages";
		for (size_t i = 0; i < _hospitals.at(indexHospital)->staff->getLanguagesSizeOfList(); i++) {
			out_file << "$" << _hospitals.at(indexHospital)->staff->getLanguageByIndex(i);
		}
		out_file << endl;
		out_file.close();
	}
	else {
		cout << "Invalid Hospital Name !";
	}
}
void deleteHospitalByName() {
	string name;
	cout << "Enter Hospital Name: ";
	cin >> name;
	ifstream in_file("Hospital_Info.txt");
	if (!in_file) {
		cout << "File Can't Be Opened !";
		return;
	}
	vector <string> temp;
	string line;
	int index1;
	int index2;
	string c;
	while (getline(in_file, line)) {
		c = "";
		index1 = line.find("name$") + 5;
		index2 = line.find("#address$");
		for (int i = index1; i < index2; i++) {
			c += line[i];
		}
		if (c != name) {
			temp.push_back(line);
		}
		
	}
	ofstream out_file("Hospital_Info.txt");
	if (!out_file) {
		cout << "File Can't Be Opened !";
		return;
	}
	for (int i = 0; i < temp.size(); i++) {
		out_file << temp.at(i) << endl;
	}
	out_file.close();
	in_file.close();
	temp.clear();
	/// <summary>
	/// /////
	/// </summary>
	/// <param name="name"></param>
	ifstream in_file2("Person_Info.txt");
	if (!in_file2) {
		cout << "File Can't Be Opened !";
		return;
	}
	
	while (getline(in_file2, line)) {
		c = "";
		string check = "";
		for (int i = 0; i < 9; i++) {
			check += line[i];
		}
		if (check == "hospital$") {
			index1 = 9;
			index2 = line.find("#title$");
			for (int i = index1; i < index2; i++) {
				c += line[i];
			}
			if (c != name) {
				temp.push_back(line);
			}

		}
		else if (check != "hospital$") {
			temp.push_back(line);
		}
	}
		ofstream out_file2("Person_Info.txt");
		if (!out_file2) {
			cout << "File Can't Be Opened !";
			return;
		}
		for (int i = 0; i < temp.size(); i++) {
			out_file2 << temp.at(i) << endl;
		}
		out_file2.close();
		in_file2.close();
		temp.clear();
	}
void deleteMemberByName() {
	cout << "Enter Members Job in smallcase : ";
	string job_name;
	cin >> job_name;
	cout << "Enter Members FullName : ";
	string temp_fullname;
	cin.ignore();
	getline(cin,temp_fullname);
	string fullname = "";
	for (int i = 0; i < temp_fullname.size();i++) {
		if(temp_fullname[i]!=' ')
		fullname += temp_fullname[i];
	}
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !" << endl;
		return;
	}
	string line;
	string check_job;
	string check_fullname;
	int index1;
	int index2;
	vector <string> temp;
	while (getline(in_file,line)) {
		check_job = "";
		check_fullname = "";
		index1 = line.find("title$")+6;
		index2 = line.find("#fullname");
		for (int i = index1; i < index2;i++) {
			check_job += line[i];
		}
		if (check_job == job_name) {
			index1 = line.find("fullname$")+9;
			index2 = line.find("#birthdate$");
			for (int i = index1; i < index2; i++) {
				if(line[i]!=' ')
				check_fullname += line[i];
			}
			if (check_fullname != fullname) {
				temp.push_back(line);
			}
		}
		else {
			temp.push_back(line);
		}
	}
	ofstream out_file("Person_Info.txt");
	if (!out_file) {
		cout << "can't open file !" << endl;
		return;
	}
	for (int i = 0; i < temp.size();i++) {
		out_file << temp[i] << endl;
	}
	out_file.close();
	in_file.close();
}
void findMember() {
	cout << "Patient Or Staff(All In SmallCase) ? ";
	string patient_staff;
	string job_title;
	string id;
	string temp_fullname;
	string fullname;
	cin >> patient_staff;
	if (patient_staff == "staff") {
		cout << "Enter Job Title : ";
		cin >> job_title;
		cout << "Enter Staff's FullName All In Small Case :";
		cin.ignore();
		getline(cin, temp_fullname);
		string fullname = "";
		for (int i = 0; i < temp_fullname.size(); i++) {
			if (temp_fullname[i] != ' ')
				fullname += temp_fullname[i];
		}
		ifstream in_file("Person_Info.txt");
		if (!in_file) {
			cout << "can't open file !" << endl;
			return;
		}
		string line;
		string check_job;
		string check_fullname;
		int index1;
		int index2;
		while (getline(in_file, line)) {
			check_job = "";
			check_fullname = "";
			index1 = line.find("title$") + 6;
			index2 = line.find("#fullname");
			for (int i = index1; i < index2; i++) {
				check_job += line[i];
			}
			if (check_job == job_title) {
				index1 = line.find("fullname$") + 9;
				index2 = line.find("#birthdate$");
				for (int i = index1; i < index2; i++) {
					if (line[i] != ' ')
						check_fullname += line[i];
				}
				if (check_fullname == fullname) {
					string line_replaced="";
					for (int i = 0; i < line.size();i++) {
						if (line[i]=='$') {
							line_replaced += " : ";
						}
						else if(line[i] == '#') {
							line_replaced += "\n";
						}
						else {
							line_replaced += line[i];
						}
					}
					cout << endl << line_replaced <<endl;
					ofstream out_file("Member_Search_Output.txt",ios::app);
					if (!out_file) {
						cout << "can't open file ! \n";
						return;
					}
					out_file << line_replaced << "\n-------------------------------------\n";
				}
			}
		}
	}
	else {
		job_title = "patient";
		cout << "Enter Patient's Id : ";
		cin >> id;
		ifstream in_file("Person_Info.txt");
		if (!in_file) {
			cout << "can't open file !" << endl;
			return;
		}
		string line;
		string check_job;
		string check_id;
		int index1;
		int index2;
		while (getline(in_file, line)) {
			check_job = "";
			check_id = "";
			index1 = line.find("title$") + 6;
			index2 = line.find("#fullname");
			for (int i = index1; i < index2; i++) {
				check_job += line[i];
			}
			if (check_job == job_title) {
				index1 = line.find("id$") + 3;
				index2 = line.find("#age$");
				for (int i = index1; i < index2; i++) {
						check_id += line[i];
				}
				if (check_id == id) {
					string line_replaced = "";
					for (int i = 0; i < line.size(); i++) {
						if (line[i] == '$') {
							line_replaced += " : ";
						}
						else if (line[i] == '#') {
							line_replaced += "\n";
						}
						else {
							line_replaced += line[i];
						}
					}
						cout << endl << line_replaced << endl;
					ofstream out_file("Member_Search_Output.txt", ios::app);
					if (!out_file) {
						cout << "can't open file ! \n";
						return;
					}
					out_file << line_replaced << "\n-------------------------------------\n";
				}
			}
		}
	}
}
void findSickTechnicalStaff() {
	int day;
	int month;
	int year;
	cout << "Enter Date Seperated By Single Spaces (dd/mm/yy) : ";
	cin >>day>>month>>year;
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	int index1;
	int index2;
	int check_day;
	int check_month;
	int check_year;
	string date;
	string date_devision;
	vector <string> patient_candidates;
	string check_title;
	while (getline(in_file, line)) {
		check_title = "";
		date = "";
		date_devision = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname$");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient"){
			index1 = line.find("accepted$") + 9;
		index2 = line.find("#sickness$");
		int index_date;
		for (int i = index1; i < index2; i++) {
			date += line[i];
		}
		for (int i = 0; i < date.size(); i++) {
			if (date[i] == '|') {
				index_date = i + 1;
				break;
			}
			date_devision += date[i];
		}
		check_month = getMonth(date_devision);
		date_devision = "";
		for (int i = index_date; i < date.size(); i++) {
			if (date[i] == '|') {
				index_date = i + 1;
				break;
			}
			date_devision += date[i];
		}
		check_day = stoi(date_devision);
		date_devision = "";
		for (int i = index_date; i < date.size(); i++) {
			date_devision += date[i];
		}
		check_year = stoi(date_devision);
		if (year >= check_year) {
			if (year > check_year) {
				patient_candidates.push_back(line);
			}
			else if (year == check_year) {
				if (month >= check_month) {
					if (month > check_month) {
						patient_candidates.push_back(line);
					}
					else if (month = check_month) {
						if (day >= check_day) {
							if (day > check_day) {
								patient_candidates.push_back(line);
							}
						}
					}
				}
			}
		}
	}
	}
	in_file.close();
		for (int i = 0; i < patient_candidates.size();i++) {
			int index1 = patient_candidates[i].find("fullname$")+9;
			int index2 = patient_candidates[i].find("#birthdate$");
			string vec_fullname = "";
			for (int j = index1; j < index2;j++) {
				vec_fullname +=patient_candidates[i][j];
			}
			string temp_fullname = vec_fullname;
			string fullname;
			 fullname = "";
				for (int i = 0; i < temp_fullname.size(); i++) {
					if (temp_fullname[i] != ' ')
						fullname += temp_fullname[i];
				}
				ifstream in_file2("Person_Info.txt");
				if (!in_file2) {
					cout << "can't open file !" << endl;
					return;
				}
				string line;
				string check_job;
				string check_fullname;
				while (!in_file2.eof()) {
					getline(in_file2,line);
					check_job = "";
					check_fullname = "";
					index1 = line.find("title$") + 6;
					index2 = line.find("#fullname");
					for (int i = index1; i < index2; i++) {
						check_job += line[i];
					}
					if (check_job == "technician" or check_job=="surgicaltechnologist") {
						index1 = line.find("fullname$") + 9;
						index2 = line.find("#birthdate$");
						for (int i = index1; i < index2; i++) {
							if (line[i] != ' ')
								check_fullname += line[i];
						}
						if (check_fullname == fullname) {
							string line_replaced = "";
							for (int i = 0; i < line.size(); i++) {
								if (line[i] == '$') {
									line_replaced += " : ";
								}
								else if (line[i] == '#') {
									line_replaced += "\n";
								}
								else {
									line_replaced += line[i];
								}
							}
							cout << endl << line_replaced << endl;
							ofstream out_file("Member_Search_Output.txt", ios::app);
							if (!out_file) {
								cout << "can't open file ! \n";
								return;
							}
							out_file << line_replaced << "\n-------------------------------------\n";
							out_file.close();
						}
					}
				}	
				in_file2.close();
			}
	
		}
void findSickDoctors() {
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	int index1;
	int index2;
	int check_day;
	int check_month;
	int check_year;
	string date;
	string date_devision;
	vector <string> patient_candidates;
	string check_title;
	while (getline(in_file, line)) {
		check_title = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname$");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient") {
			patient_candidates.push_back(line);
		}
	}
	in_file.close();
	for (int i = 0; i < patient_candidates.size(); i++) {
		int index1 = patient_candidates[i].find("fullname$") + 9;
		int index2 = patient_candidates[i].find("#birthdate$");
		string vec_fullname = "";
		for (int j = index1; j < index2; j++) {
			vec_fullname += patient_candidates[i][j];
		}
		string temp_fullname = vec_fullname;
		string fullname;
		fullname = "";
		for (int i = 0; i < temp_fullname.size(); i++) {
			if (temp_fullname[i] != ' ')
				fullname += temp_fullname[i];
		}
		ifstream in_file2("Person_Info.txt");
		if (!in_file2) {
			cout << "can't open file !" << endl;
			return;
		}
		string line;
		string check_job;
		string check_fullname;
		while (!in_file2.eof()) {
			getline(in_file2, line);
			check_job = "";
			check_fullname = "";
			index1 = line.find("title$") + 6;
			index2 = line.find("#fullname");
			for (int i = index1; i < index2; i++) {
				check_job += line[i];
			}
			if (check_job == "doctor") {
				index1 = line.find("fullname$") + 9;
				index2 = line.find("#birthdate$");
				for (int i = index1; i < index2; i++) {
					if (line[i] != ' ')
						check_fullname += line[i];
				}
				if (check_fullname == fullname) {
					string line_replaced = "";
					for (int i = 0; i < line.size(); i++) {
						if (line[i] == '$') {
							line_replaced += " : ";
						}
						else if (line[i] == '#') {
							line_replaced += "\n";
						}
						else {
							line_replaced += line[i];
						}
					}
					cout << endl << line_replaced << endl;
					ofstream out_file("Member_Search_Output.txt", ios::app);
					if (!out_file) {
						cout << "can't open file ! \n";
						return;
					}
					out_file << line_replaced << "\n-------------------------------------\n";
					out_file.close();
				}
			}
		}
		in_file2.close();
	}
}
void findSurgeons() {
	string job_title;
	job_title = "surgeon";
		ifstream in_file("Person_Info.txt");
		if (!in_file) {
			cout << "can't open file !" << endl;
			return;
		}
		string line;
		string check_job;
		int index1;
		int index2;
		while (getline(in_file, line)) {
			check_job = "";
			index1 = line.find("title$") + 6;
			index2 = line.find("#fullname");
			for (int i = index1; i < index2; i++) {
				check_job += line[i];
			}
			if (check_job == job_title) {
					string line_replaced = "";
					for (int i = 0; i < line.size(); i++) {
						if (line[i] == '$') {
							line_replaced += " : ";
						}
						else if (line[i] == '#') {
							line_replaced += "\n";
						}
						else {
							line_replaced += line[i];
						}
					}
					cout << endl << line_replaced << endl;
					ofstream out_file("Member_Search_Output.txt", ios::app);
					if (!out_file) {
						cout << "can't open file ! \n";
						return;
					}
					out_file << line_replaced << "\n-------------------------------------\n";
				
			}
		}
	}
void findSickNurses() {
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	int index1;
	int index2;
	vector <string> patient_candidates;
	string check_title;
	while (getline(in_file, line)) {
		check_title = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname$");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient") {
			patient_candidates.push_back(line);
		}
	}
	in_file.close();
	for (int i = 0; i < patient_candidates.size(); i++) {
		int index1 = patient_candidates[i].find("fullname$") + 9;
		int index2 = patient_candidates[i].find("#birthdate$");
		string vec_fullname = "";
		for (int j = index1; j < index2; j++) {
			vec_fullname += patient_candidates[i][j];
		}
		string temp_fullname = vec_fullname;
		string fullname;
		fullname = "";
		for (int i = 0; i < temp_fullname.size(); i++) {
			if (temp_fullname[i] != ' ')
				fullname += temp_fullname[i];
		}
		ifstream in_file2("Person_Info.txt");
		if (!in_file2) {
			cout << "can't open file !" << endl;
			return;
		}
		string line;
		string check_job;
		string check_fullname;
		while (!in_file2.eof()) {
			getline(in_file2, line);
			check_job = "";
			check_fullname = "";
			index1 = line.find("title$") + 6;
			index2 = line.find("#fullname");
			for (int i = index1; i < index2; i++) {
				check_job += line[i];
			}
			if (check_job == "nurse") {
				index1 = line.find("fullname$") + 9;
				index2 = line.find("#birthdate$");
				for (int i = index1; i < index2; i++) {
					if (line[i] != ' ')
						check_fullname += line[i];
				}
				if (check_fullname == fullname) {
					string line_replaced = "";
					for (int i = 0; i < line.size(); i++) {
						if (line[i] == '$') {
							line_replaced += " : ";
						}
						else if (line[i] == '#') {
							line_replaced += "\n";
						}
						else {
							line_replaced += line[i];
						}
					}
					cout << endl << line_replaced << endl;
					ofstream out_file("Member_Search_Output.txt", ios::app);
					if (!out_file) {
						cout << "can't open file ! \n";
						return;
					}
					out_file << line_replaced << "\n-------------------------------------\n";
					out_file.close();
				}
			}
		}
		in_file2.close();
	}
}
void findPatientsInTwoDates() {
	int day1,day2;
	int month1,month2;
	int year1,year2;
	cout << "Enter Date1 And Date2 Seperated By *Enter* And Each Date's Parts Seperated By Single Spaces (dd/mm/yy) : ";
	cin >> day1 >> month1 >> year1;
	cin >> day2 >> month2 >> year2;
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	int index1;
	int index2;
	int check_day;
	int check_month;
	int check_year;
	string date;
	string date_devision;
	vector <string> patient_candidates;
	string check_title;
	while (getline(in_file, line)) {
		check_title = "";
		date = "";
		date_devision = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname$");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient") {
			index1 = line.find("accepted$") + 9;
			index2 = line.find("#sickness$");
			int index_date;
			for (int i = index1; i < index2; i++) {
				date += line[i];
			}
			for (int i = 0; i < date.size(); i++) {
				if (date[i] == '|') {
					index_date = i + 1;
					break;
				}
				date_devision += date[i];
			}
			check_month = getMonth(date_devision);
			date_devision = "";
			for (int i = index_date; i < date.size(); i++) {
				if (date[i] == '|') {
					index_date = i + 1;
					break;
				}
				date_devision += date[i];
			}
			check_day = stoi(date_devision);
			date_devision = "";
			for (int i = index_date; i < date.size(); i++) {
				date_devision += date[i];
			}
			check_year = stoi(date_devision);
			if ((check_day == day1 && check_month == month1 && check_year == year1)or(check_day == day2 && check_month == month2 && check_year == year2)) {
				patient_candidates.push_back(line);
			}
		}
	}
	in_file.close();
	for (int j = 0; j < patient_candidates.size();j++) {
		string line_replaced = "";
		for (int i = 0; i < patient_candidates[j].size(); i++) {
			if (patient_candidates[j][i] == '$') {
				line_replaced += " : ";
			}
			else if (patient_candidates[j][i] == '#') {
				line_replaced += "\n";
			}
			else {
				line_replaced += patient_candidates[j][i];
			}
		}
		cout << endl << line_replaced << endl;
		ofstream out_file("Member_Search_Output.txt", ios::app);
		if (!out_file) {
			cout << "can't open file ! \n";
			return;
		}
		out_file << line_replaced << "\n-------------------------------------\n";
		out_file.close();
	}
					
	}
void findPercentageOfAllDiseasesAndPrintGraph() {
	vector<string>all_diseases;
	vector<float>percentages;
	vector<int> diseases_num;
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	string diseases;
	string disease;
	string check_title;
	int index1;
	int index2;
	while (getline(in_file,line)) {
		diseases = "";
		disease = "";
		check_title = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient") {
			index1 = line.find("sickness$") + 9;
			index2 = line.find("#prescriptions");
			for (int i = index1; i < index2; i++) {
				diseases += line[i];
			}
			for (int i = 0; i < diseases.size(); i++) {
				if (diseases[i] == '$') {
					all_diseases.push_back(disease);
					disease = "";
					continue;
				}
				disease += diseases[i];
			}
			all_diseases.push_back(disease);
		}
	}
	in_file.close();
	for (int i = 0; i < all_diseases.size();i++) {
		float count_temp = count(all_diseases.begin(), all_diseases.end(), all_diseases[i]);
			diseases_num.push_back(count_temp);
			float percentage_temp = (count_temp / all_diseases.size()) * 100 ;
			percentages.push_back(percentage_temp);
	}
	for (int i = 0; i < all_diseases.size();i++) {
		for (int j = i+1; j < all_diseases.size(); j++) {
			if (all_diseases[i] == all_diseases[j]) {
				all_diseases.erase(all_diseases.begin() + j);
				percentages.erase(percentages.begin() + j);
				diseases_num.erase(diseases_num.begin() + j);

			}
		}
	}
	string temp;
	string output = "\nPercentages : \n\n";
	for (int i = 0; i < all_diseases.size(); i++) {
		output += all_diseases[i];
		output += " : ";
		temp = to_string(percentages[i]);
		for (int j = 0; j < 5;j++) {
			output += temp[j];
		}
		output += " % ";
		output += "\n";
	}
	output += "\nGraphs : \n\n";
	for (int i = 0; i < percentages.size(); i++) {
		output += all_diseases[i];
		output += " : ";
		for (int j = 0; j <diseases_num[i]; j++) {
			output += "*";
		}
		output += "\n";
	}
	output += "----------------------------------------------------";
	cout << output;
	ofstream out_file("Graph&Percentage.txt",ios::app);
	if (!out_file)
	{
		cout << "can't open file !";
		return;
	}
	out_file << output;
	out_file.close();
}
void getDiseasePercentage() {
	double count_patients = 0;
	string input_disease;
	cout << "Enter Disease : ";
	cin >> input_disease;
	vector<string>all_diseases;
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	string diseases;
	string disease;
	string check_title;
	int index1;
	int index2;
	while (getline(in_file, line)) {
		diseases = "";
		disease = "";
		check_title = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient") {
			count_patients++;
			index1 = line.find("sickness$") + 9;
			index2 = line.find("#prescriptions");
			for (int i = index1; i < index2; i++) {
				diseases += line[i];
			}
			for (int i = 0; i < diseases.size(); i++) {
				if (diseases[i] == '$') {
					all_diseases.push_back(disease);
					disease = "";
					continue;
				}
				disease += diseases[i];
			}
			all_diseases.push_back(disease);
		}
	}
	in_file.close();
	double count_disease = count(all_diseases.begin(),all_diseases.end(),input_disease);
	double percentage = (count_disease / count_patients) * 100;
	string temp;
	string output = "\nPercentage : \n\n";
		output += input_disease;
		output += " : ";
		temp = to_string(percentage);
		for (int j = 0; j < 5; j++) {
			output += temp[j];
		}
		output += " % ";
		output += "\n";
		output += "----------------------------------------------------";
		cout << output;
		ofstream out_file("Graph&Percentage.txt", ios::app);
		if (!out_file)
		{
			cout << "can't open file !";
			return;
		}
		out_file << output;
		out_file.close();
	}
void getDoctorsDisesasePercentage() {
	string input_disease;
	vector<string>all_diseases;
	double count_disease = 0;
	cout << "Enter Disease : ";
	cin >> input_disease;
	ifstream in_file("Person_Info.txt");
	if (!in_file) {
		cout << "can't open file !\n";
		return;
	}
	string line;
	int index1;
	int index2;
	int check_day;
	int check_month;
	int check_year;
	string date;
	string date_devision;
	vector <string> patient_candidates;
	string check_title;
	double count_doctor = 0;
	while (getline(in_file, line)) {
		check_title = "";
		index1 = line.find("title$") + 6;
		index2 = line.find("#fullname$");
		for (int i = index1; i < index2; i++) {
			check_title += line[i];
		}
		if (check_title == "patient") {
			patient_candidates.push_back(line);
		}
	}
	in_file.close();
	for (int i = 0; i < patient_candidates.size(); i++) {
		int index1 = patient_candidates[i].find("fullname$") + 9;
		int index2 = patient_candidates[i].find("#birthdate$");
		string vec_fullname = "";
		for (int j = index1; j < index2; j++) {
			vec_fullname += patient_candidates[i][j];
		}
		string temp_fullname = vec_fullname;
		string fullname;
		fullname = "";
		for (int i = 0; i < temp_fullname.size(); i++) {
			if (temp_fullname[i] != ' ')
				fullname += temp_fullname[i];
		}
		ifstream in_file2("Person_Info.txt");
		if (!in_file2) {
			cout << "can't open file !" << endl;
			return;
		}
		string line;
		string check_job;
		string check_fullname;
		
		while (!in_file2.eof()) {
			getline(in_file2, line);
			check_job = "";
			check_fullname = "";
			index1 = line.find("title$") + 6;
			index2 = line.find("#fullname");
			for (int i = index1; i < index2; i++) {
				check_job += line[i];
			}
			if (check_job == "doctor") {
				count_doctor++;
				index1 = line.find("fullname$") + 9;
				index2 = line.find("#birthdate$");
				for (int i = index1; i < index2; i++) {
					if (line[i] != ' ')
						check_fullname += line[i];
				}
				if (check_fullname == fullname) {
					if (patient_candidates[i].find("$"+input_disease) != -1) {
						count_disease++;
					}
				}
				}
			}
		in_file2.close();
		}
	in_file.close();
	double percentage = (count_disease / patient_candidates.size()) * 100;
	string temp;
	string output = "\nPercentage : \n\n";
	output += input_disease;
	output += " : ";
	temp = to_string(percentage);
	for (int j = 0; j < 5; j++) {
		output += temp[j];
	}
	output += " % ";
	output += "\n";
	output += "----------------------------------------------------";
	cout << output;
	ofstream out_file("Graph&Percentage.txt", ios::app);
	if (!out_file)
	{
		cout << "can't open file !";
		return;
	}
	out_file << output;
	out_file.close();
}
