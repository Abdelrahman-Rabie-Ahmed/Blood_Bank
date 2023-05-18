#include <iostream>
#include <string>
#include <fstream>
using namespace std;
fstream fp;
class volunteer{
private:
	string name;
	string id;
	string sex;
	string city;
	string address;
	string phon;
	string mail;
	int blood;
public:
	void creat_volunteer(){
		asd:
		cout << "Enter your name\n"; cin >> name;
		for (int i = 0; i < name.size(); i++) {
			if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))) {
				cout << "\033[1;31minvalid name\033[0m" << endl;
				goto asd;
			}
		}
		sex1:
		cout << "Enter your sex\n"; 
		cout << "1-Male				2-Female\n";
		cin >> sex;
		if (sex != "1" && sex != "2") {
			cout << "\033[1;31minvalid sex\033[0m" << endl;
			goto sex1;
		}
		if (sex == "1") {
			sex = "Male";
		}
		else {
			sex = "Female";
		}
		blood1:
		cout << "Enter your blood\n"; 
		cout << "1-(O+)		2-(A+)		3-(B+)		4-(AB+)\n";
		cout << "5-(O-)		6-(A-)		7-(B-)		8-(AB-)\n";
		cin >> blood;
		if (!(blood >= 1 && blood <= 8)) {
			cout << "\033[1;31minvalid blood\033[0m" << endl;
			goto blood1;
		}
		id1:
		cout << "Enter your id\n"; cin >> id;
		if (id.size() != 14) {
			cout << "\033[1;31minvalid id\033[0m" << endl;
			goto id1;
		}
		for (int i = 0; i < id.size(); i++) {
			if (!(id[i] >= '0' && id[i] <= '9')) {
				cout << "invalid id" << endl;
				goto id1;
			}
		}
		cout << "Enter your phon\n"; cin >> phon;
		cout << "Enter your city\n"; cin >> city;
		cout << "Enter your address\n"; cin >> address;
		cout << "Enter your mail\n"; cin >> mail;
	}
	void r_search(){
		cout << "\n  The volunteer\'s name\t\t:" << name;
		cout << "\n  The volunteer\'s sex\t\t:" << sex;
		cout << "\n  The volunteer\'s blood\t\t:";
		switch (blood) {
		case 1:
			cout << "O+";
			break;
		case 2:
			cout << "A+";
			break;
		case 3:
			cout << "B+";
			break;
		case 4:
			cout << "AB+";
			break;
		case 5:
			cout << "O-";
			break;
		case 6:
			cout << "A-";
			break;
		case 7:
			cout << "B-";
			break;
		case 8:
			cout << "AB-";
			break;
		}
		cout << "\n  The volunteer\'s id\t\t:" << id;
		cout << "\n  The volunteer\'s phon\t\t:" << phon;
		cout << "\n  The volunteer\'s city\t\t:" << city;
		cout << "\n  The volunteer\'s address\t\t:" << address;
		cout << "\n  The volunteer\'s mail\t\t:" << mail << endl;

	}
	string c_ity()
	{
		return city;
	}
	int b_lood()
	{
		return blood;
	}
	string n_ame()
	{
		return name;
	}
};
volunteer no;
void write_volunteer(){
	fp.open("blood bank.txt", ios::out | ios::app);
	no.creat_volunteer();
	fp.write((char*)&no, sizeof(volunteer));
	fp.close();
	cout << "\t\t Thank you\n";
	cout << "\t          \3     \3\n";
	cout << "\t        \3    \3    \3\n";
	cout << "\t        \3         \3\n";
	cout << "\t         \3       \3\n";
	cout << "\t             \3 \n";
}
void report(){
	fp.open("blood bank.txt", ios::in);
	while (fp.read((char*)&no, sizeof(volunteer)))
	{
		no.r_search();
		cout << "\n  ==============================\n";
	}
	fp.close();
}
void search(int blood){
	bool flag = false;
	fp.open("blood bank.txt", ios::in);
	while (fp.read((char*)&no, sizeof(volunteer)))
	{
		if ((no.b_lood() == 1 || no.b_lood() == 5 || no.b_lood() == blood + 4) && (blood == 1 || blood == 2 || blood == 3 || blood == 4)) {
			no.r_search();
			cout << "\n ******************************\n";
			flag = true;
		}
		else if (blood == 4) {
			no.r_search();
			cout << "\n ******************************\n";
			flag = true;
		}
		else if ((no.b_lood() == 5 || no.b_lood() == blood) && (blood == 5 || blood == 6 || blood == 7)) {
			no.r_search();
			cout << "\n ******************************\n";
			flag = true;
		}
		else if (blood == 8 && no.b_lood() > 4) {
			no.r_search();
			cout << "\n ******************************\n";
			flag = true;
		}
	}
	fp.close();
	if (flag == false){
		cout << "\n it\'s bad news no one have this kind of blood\n" << endl;
	}
}
void delete_volunteer(){
	string name;
	cout << "\n Enter the volunteer\'s name want to deleted\n"; cin >> name;
	fp.open("blood bank.txt",ios::in);
	fstream fp2;
	fp2.open("temp.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&no, sizeof(volunteer)))
	{
		if (no.n_ame() != name)
		{
			fp2.write((char*)&no, sizeof(volunteer));
		}
	}
	fp2.close();
	fp.close();
	remove("blood bank.txt");
	rename("temp.txt", "blood bank.txt");
	cout << "\n The Volunteer Deleted\n";
}
int main(){
	char x = 5;
	int blood;
	do {
		cout << "\n  ==============================\n";
		cout << "\n\t Main Menu";
		cout << "\n\t _________\n";
		cout << "\n\n 1-Add New Volunteer";
		cout << "\n\n 2-report about all Volunteers";
		cout << "\n\n 3-search with the kind of blood";
		cout << "\n\n 4-Delete a Volunteer";
		cout << "\n\n 5-Exit";
		cout << "\n\n 0-clear";
		cout << "\n\n please Enter your choise(0-5)\n";
		cin >> x;
		switch (x){
		case'0':
			system("cls");
			break;
		case'1':
			cout << "\n\n 1-Add New Volunteer\n";
			cout << "\n\t Hint\: When you write the data of the new Volunteer,Don\'t use white space and you must use camel sytle\n";
			cout << "\n\t like that\: addNewVolunteer , AbdelrahmanRabie\n";
			cout << "\n  ==============================\n";
			write_volunteer();
			break;
		case'2':
			cout << "\n\n 2-report about all Volunteers\n";
			cout << "\n  ==============================\n";
			report();
			break;
		case'3':
			cout << "\n\n 3-search with the kind of blood\n";
			cout << "\n  ==============================\n";
			cout << "  Enter your kind of blood\n";
			cout << "1-(O+)		2-(A+)		3-(B+)		4-(AB+)\n";
			cout << "5-(O-)		6-(A-)		7-(B-)		8-(AB-)\n";
			cin >> blood;
			search(blood);
			break;
		case'4':
			cout << "\n\n 4-Delete a Volunteer\n";
			cout << "\n  ==============================\n";
			delete_volunteer();
			break;
		case'5':
			exit(0);
			break;
		default:
			cout << "    \t Error\n";
		}
	} while (1);
	system("pause");
	return 0;
}