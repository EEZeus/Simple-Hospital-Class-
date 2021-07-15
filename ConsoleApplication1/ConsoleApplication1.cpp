#include <iostream>
#include<string>
#include <vector>
#include "date.h"
#include "Header.h"
#include "SecondaryFunctions.h"
#include <iomanip>
vector <Hospital*> Hospitals;
int main() {
	bool progress = true;
	bool hospital_added = false;
	ifstream in_file("Hospital_Info.txt");
	if (!in_file){
		cout << "can't open file !";
			return 1;
	}
	string line;
	while (getline(in_file, line)) {
		bool hospital_added = true;
	}
	in_file.close();
	bool member_added = false;
	ifstream in_file2("Person_Info.txt");
	if (!in_file2) {
		cout << "can't open file !";
		return 1;
	}
	while (getline(in_file2, line)) {
		 member_added = true;
	}
	in_file2.close();
	do {
		addHospitalInfoIntoVector(Hospitals);
		int choice;
		printForm();
		if (cin>>choice) {
		}
		switch (choice) {
		case 1:
			system("CLS");
			addHospital(Hospitals);
			hospital_added = true;
			break;
		case 2:
			member_added = true;
			system("CLS");
			addPatient();
			break;
		case 3:
			member_added = true;
			system("CLS");
			if (hospital_added)
				addDoctor(Hospitals);
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 4:
			member_added = true;
			system("CLS");
			if (hospital_added)
				addSurgeon(Hospitals);
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 5:
			member_added = true;
			system("CLS");
			if (hospital_added)
				addNurse(Hospitals);
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 6:
			member_added = true;
			system("CLS");
			if (hospital_added)
				addReceptionist(Hospitals);
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 7:
			member_added = true;
			system("CLS");
			if (hospital_added)
				addTechnician(Hospitals);
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 8:
			member_added = true;
			system("CLS");
			if (hospital_added)
				addSurgicalTechnologist(Hospitals);
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 9:
			system("CLS");
			if (hospital_added)
				deleteHospitalByName();
			else
				cout << "You Need To Add Hospital First!\n";
			break;
		case 10:
			system("CLS");
			if (member_added)
				deleteMemberByName();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 11:
			system("CLS");
			if (member_added)
				findMember();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 12:
			system("CLS");
			if (member_added)
				findSickTechnicalStaff();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 13:
			system("CLS");
			if (member_added)
				findSickDoctors();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 14:
			system("CLS");
			if (member_added)
				findSurgeons();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 15:
			system("CLS");
			if (member_added)
				findSickNurses();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 16:
			system("CLS");
			if (member_added)
				findPatientsInTwoDates();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 17:
			system("CLS");
			if (member_added)
				findPercentageOfAllDiseasesAndPrintGraph();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 18:
			system("CLS");
			if (member_added)
				getDiseasePercentage();
			else
				cout << "You Need To Add Member First!\n";
		case 19:
			system("CLS");
			if (member_added)
				getDoctorsDisesasePercentage();
			else
				cout << "You Need To Add Member First!\n";
			break;
		case 20:
			system("CLS");
			progress = false;
			break;
		}
	}while (progress);
}


