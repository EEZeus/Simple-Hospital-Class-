#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "date.h"
#include "DataType.h"
#include <fstream>
using namespace std;

class Person {
	string title = "none";
	string givenName;
	string middleName;
	string familyName;
	FullName fullname{ givenName,middleName,familyName };
	Date birthDate;
	Gender gender; ///Gender
	Address homeAddress;// ??Address
	Phones phone;
public:
	virtual void setTitle(string _title) {
		title = _title;
	}
	string getTitle() {
		return title;
	}

	virtual void setGivenName(string _givenName) {
		givenName = _givenName;
		fullname.setFullName(givenName, middleName, familyName);
	}
	string getGivenName() {
		return givenName;
	}
	virtual void setMiddleName(string _middleName) {
		middleName = _middleName;
		fullname.setFullName(givenName, middleName, familyName);
	}
	virtual string getMiddleName() {
		return middleName;
	}
	virtual void setFamilyName(string _familyName) {
		familyName = _familyName;
		fullname.setFullName(givenName, middleName, familyName);
	}
	virtual string getFamilyName() {
		return familyName;
	}
	virtual FullName getFullName() {
		return fullname;
	}
	virtual void setHomeAddress(Address _homeAddress) {
		homeAddress = _homeAddress;
	}
	virtual Address getHomeAddress() {
		return homeAddress;
	}
	virtual void setBirthDate(Date _birthDate) {
		birthDate = _birthDate;
	}
	virtual Date getBirthDate() {
		return birthDate;
	}
	virtual void setGender(Gender _gender) {
		gender = _gender;
	}
	virtual Gender getGender() {
		return gender;
	}
	virtual void setPhone(Phones _phone) {
		phone = _phone;
	}
	virtual Phones getPhone() {
		return phone;
	}
};
class Staff :public Person {
	Date joined;
	vector <string> education;
	vector <string> certification;
	vector <string> languages;
public:
	virtual void addSpecialty(string _specialty) = 0;
	virtual string getSpecialtyByIndex(size_t index) = 0;
	virtual void addLocation(string _Location) = 0;
	virtual string getLocationByIndex(size_t index) = 0;
	virtual int getSpecialtySizeOfList() = 0;
	virtual int getLocationSizeOfList() = 0;
	virtual void setJoined(Date _joined) {
		joined = _joined;
	}
	virtual Date getJoined() {
		return joined;
	}
	virtual void addEducation(string _education) {
		education.push_back(_education);
	}
	virtual string get_EducationsByIndex(size_t index) {
		return education[index];
	}
	virtual void addCertification(string _certification) {
		certification.push_back(_certification);
	}
	virtual string getCertificationByIndex(size_t index) {
		return certification[index];
	}
	virtual void addLanguage(string _Language) {
		languages.push_back(_Language);
	}
	virtual string getLanguageByIndex(size_t index) {
		return languages[index];
	}
	virtual int getEducationSizeOfList() {
		return education.size();
	}
	virtual int getCertificationSizeOfList() {
		return certification.size();
	}
	virtual int getLanguagesSizeOfList() {
		return languages.size();
	}
};
class Hospital {
	string name;
	Address address;
	Phones phone;
public:
	Staff* staff;
	
	void setName(string id){
		name = id;
	}
	string getName() {
		return name;
	}
	void setAddress(Address _address) {
		address = _address;
	}
	Address getAddress() {
		return address;
	}
	void setPhone(Phones _phone) {
		phone = _phone;
	}
	Phones getPhone() {
		return phone;
	}

	~Hospital() {
		ofstream out_file("Hospital_Information.txt");
		if (!out_file) {
			cout << "can't open file !";
			return ;
		}
		out_file << getName() << "#" << getAddress().getAddress() << "$" << getPhone().getPhoneNum() << endl;
		out_file.close();
	}
};
class Patient :public Person {
	string id;
	int age;
	Date accepted;
	History sickness;
	vector <string> prescriptions;
	vector <string> allergies;
	vector <string> specialReqs;
public:
	
	virtual void setId(string _id) {
		id = _id;
	}
	virtual string getId() {
		return id;
	}
	virtual void setAge(int _age) {
		age = _age;
	}
	virtual int getAge() {
		return age;
	}
	virtual void setAccepted(Date _accepted) {
		accepted = _accepted;
	}
	virtual Date getAccepted() {
		return accepted;
	}
	virtual void setSickness(History _sickness) {
		sickness = _sickness;
	}
	virtual History getSickness() {
		return sickness;
	}
	virtual void addPrescriptions(string _prescription) {
		prescriptions.push_back(_prescription);
	}
	virtual string getPrescriptionByIndex(size_t index) {
		return prescriptions[index];
	}
	virtual void addAllergies(string _allergy) {
		allergies.push_back(_allergy);
	}
	virtual string getAllergiesByIndex(size_t index) {
		return allergies[index];
	}

	virtual void addSpecialReqs(string _specialReqs) {
		specialReqs.push_back(_specialReqs);
	}
	virtual string getSpecialReqsByIndex(size_t index) {
		return specialReqs[index];
	}
	virtual int getPrescriptionsSizeOfList() {
		return prescriptions.size();
	}
	virtual int getAllergiesSizeOfList() {
		return allergies.size();
	}
	virtual int getSpecialReqsSizeOfList() {
		return specialReqs.size();
	}
};
class OperationsStaff :public Staff {
};
class Nurse :public OperationsStaff {
public:
	virtual void addSpecialty(string _specialty) {}
	virtual string getSpecialtyByIndex(size_t index) { return ""; }
	virtual void addLocation(string _Location) {}
	virtual string getLocationByIndex(size_t index) { return ""; }
	virtual int getSpecialtySizeOfList() { return 0; }
	virtual int getLocationSizeOfList() { return 0; }
};
class Doctor :public OperationsStaff {
	vector <string> specialty;
	vector <string> locations;
public:
	
	virtual void addSpecialty(string _specialty) {
		specialty.push_back(_specialty);
	}
	virtual string getSpecialtyByIndex(size_t index) {
		return specialty[index];
	}
	virtual void addLocation(string _Location) {
		locations.push_back(_Location);
	}
	virtual string getLocationByIndex(size_t index) {
		return locations[index];
	}
	virtual int getSpecialtySizeOfList() {
		return specialty.size();
	}
	virtual int getLocationSizeOfList() {
		return locations.size();
	}
};
class Surgeon :public Doctor {
public:
	
};
class AdministrativeStaff :public Staff {
public:
	virtual void addSpecialty(string _specialty) {}
	virtual string getSpecialtyByIndex(size_t index) { return ""; }
	virtual void addLocation(string _Location) {}
	virtual string getLocationByIndex(size_t index) { return ""; }
	virtual int getSpecialtySizeOfList() { return 0; }
	virtual int getLocationSizeOfList() { return 0; }
};
class FrontDeskStaff :public AdministrativeStaff {
public:

};
class Receptionist :public FrontDeskStaff {
public:
	
};
class TechnicalStaff :public Staff {
public:
	virtual void addSpecialty(string _specialty) {}
	virtual string getSpecialtyByIndex(size_t index) { return ""; }
	virtual void addLocation(string _Location) {}
	virtual string getLocationByIndex(size_t index) { return ""; }
	virtual int getSpecialtySizeOfList() { return 0; }
	virtual int getLocationSizeOfList() { return 0; }
};
class Technician :public TechnicalStaff {
public:
	
};
class Technologist :public TechnicalStaff {
public:
	
};
class SurgicalTechnologist :public Technologist {
public:
	
};



