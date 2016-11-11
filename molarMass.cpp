#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage error: please use one command line argument.\n";
		return 1;
	}
	map<string, double> massMap;
	massMap["H"] = 1.008;
	massMap["He"] = 4.00;
	massMap["Li"] = 6.94;
	massMap["Be"] = 9.01;
	massMap["B"] = 10.81;
	massMap["C"] = 12.01;
	massMap["N"] = 14.01;
	massMap["O"] = 16.00;
	massMap["F"] = 19.00;
	massMap["Ne"] = 20.18;
	massMap["Na"] = 22.99;

	string molecule = argv[1];
	cout << molecule << endl;
	string elementName = "";
	string elementN = "";
	double mass = 0;
	for (int i = 0; i < molecule.length(); i++) {
		if (isupper(molecule[i])) {
			if (elementName != "") {
				if (elementN == "") {
					mass += massMap.at(elementName);
					//cout << "Increasing mass by 1 " << elementName << endl;
				} else {
					mass += massMap.at(elementName)*stoi(elementN);
					//cout << "Increasing mass by " << stoi(elementN) << " " << elementName << endl;
				}
				elementName = molecule[i];
				elementN = "";
			} else {
				elementName = molecule[i];
				//cout << "Found the first character of the element name: " << elementName << endl;
			}
		} else if (islower(molecule[i])) {
			if (elementName.length() != 1) {
				//cout << "this lowerase letter does not follow an uppercase letter";
				return 1;
			}
			elementName += molecule[i];
			//cout << "Added a lowercase letter to the element name: " << elementName << endl;
		} else if (isdigit(molecule[i])) {
			if (elementName.length() == 0) {
				//cout << "There needs to be something for a number to follow\n";
				return 1;
			}
			elementN += molecule[i];
			//cout << "Set the element number of the element " << elementName << " to " << elementN << endl;
		}
	}
	if (elementN == "") {
		mass += massMap.at(elementName);
		//cout << "Increasing mass by 1 " << elementName << endl;
	} else {
		mass += massMap.at(elementName)*stoi(elementN);
		//cout << "Increasing mass by " << stoi(elementN) << " " << elementName << endl;
	}
	cout << "Molar Mass: " << mass << endl;
	return 0;
}
