/*
 * Name:		Mohammed yousif musa idress
 * Class:		second year
 * Department:	Computer Engineering
*/

#include <iostream> //stand for standard input-output
#include <string>   //to use the string type
using namespace std;  //to define the the context in which names are defined
class contact{  //class of contacts 
	private:    // just apprear for coder
		string name, family, phone, gender, email, location;
	public:  // anyone can see this section
		contact *next;
		contact(){
		};
		contact(string name, string phone, string family, string email,string gender, string location){
			this -> name = name ; this -> family = family ; this -> phone = phone; this -> gender = gender; this -> location = location ; this -> email = email ; next = NULL;
		}
		string getName(){ // to get srting
			return name;  //return name
		}
		string getFamily(){
			return family;
		}
		string getEmail(){
			return email;
		}
		string getPhone(){
			return phone;
		}
		string getGender(){
			return gender;
		}
		string getlocation(){
			return location;
		}
		void setContact(string name, string phone, string family, string email, string gender, string location){ // to set data of contacts
			this -> name = name; this -> family = family; this -> phone = phone; this -> email = email; this -> gender = gender; this -> location = location;
		}
		void getContact(){
			cout << name << "   " << family << "   " << phone << "   " << location << "   " << gender << "   " << email << endl;
		}
};
class contactsList{  //class of contcts list
	private:
		contact *head;
		contact *last;
		int size;
	public:
		contactsList();
		contact* find(string);
		void add(string, string, string, string, string, string);
		void deleteContact(string);
		contact* findContact(string);
		void showContacts();
	};
contactsList::contactsList(){
	head = NULL ; last = NULL; size = 0;
}
void contactsList::add(string name, string phone, string family, string email, string gender, string location){  //function of addition
	contact* new_contact = new contact(name, family, phone, email, gender, location);
	if (last == NULL || head == NULL){
		head = new_contact;
		last = new_contact;
	}
	else {
		new_contact -> next = head;
		head = new_contact;
	}
	size++;
}
contact* contactsList::find(string serachQuery ){ //to find contacts 
	contact* n = NULL;
	for( n = head ; n != NULL ; n = n->next)
		if (n -> getName() == serachQuery || n -> getFamily() == serachQuery || ( n -> getName() + " " + n -> getFamily() ) == serachQuery || n -> getEmail() == serachQuery || n -> getlocation() == serachQuery || n -> getGender() == serachQuery) {
			return n;
		}
	return n;
}
contact* contactsList::findContact(string serachQuery){
	contact* f = find(serachQuery);
	if (f == NULL){
		cout << "\n\nDoes't found!" << endl;
	}
	else {
		cout << "\n\n------------------------------------" << endl;
		f -> getContact();
		cout << "-----------------------------------" << endl;
	}
	return f;
}
void contactsList::deleteContact(string serachQuery){ //function of delete
	if( head->getName() == serachQuery || head->getFamily() == serachQuery || ( head->getName() + " " + head->getFamily() ) == serachQuery )  {
		contact* temp = head->next;
		delete head;
		head = temp;
		size--;
		return;
	}
	contact* temp = head;
	if( temp->next == NULL ){
		 cout << "\n\nNot found!" << endl;
		 return;
	}
	while(temp -> next -> getName() != serachQuery && temp -> next -> getFamily() != serachQuery && ( head -> getName() + " " + head -> getFamily() ) != serachQuery && temp != NULL ){ 
		temp = temp -> next;
		if ( temp -> next == NULL ) {
			 cout << "\n\nNot found!" << endl;
			 return;
		};
	}
    if(temp != NULL){
	contact* temp2 = temp -> next;
	temp -> next = temp2 -> next;
	delete temp2;
	if( last -> getName() == serachQuery || last -> getFamily() == serachQuery || ( last->getName() + " " + last->getFamily() ) == serachQuery ) {
		last = temp;
	}
	size--;
	}
}
void contactsList::showContacts(){   //function of disp;ay
	cout << "\n\n" << endl;
	if (last == NULL || head == NULL){
		throw "No contacts!";
	}
	int l = 1;
	for (contact* n = head; n != NULL ; n = n -> next) {
		cout << l << ") "; l++;
		n -> getContact();
		cout << "-------------------------------------------\n\n" << endl;
	}
};
contact* f;
bool menu();
int main(){       //
	int n;
	string name, family, phone,location , email, gender, search;
	contactsList a;
	while(menu()){
		cout << "\nYour option: ";
		cin >> n;
		switch(n){                    //to switch between data of contacts 
			case 1:
				cout << "\nName: ";
				cin >> name;
				cout << "Family: ";
				cin >> family;
				cout << "Phone: ";
				cin >> phone;
				cout << "Gender: ";
				cin >> gender;
				cout << "E-Mail: ";
				cin >> email;
				cout << "location: ";
				cin >> location;
				a.add(name,family,phone,email,gender,location);
				break;
			case 2:
				a.showContacts();
				break;
			case 3:
				cout << "\nSearch a Contact Using any Term: ";
				cin >> search;
				f = a.findContact(search);
			case 4:
				cout << "Name Or Family Name of the Contact to Delete: ";
				cin >> search;
				a.deleteContact(search);		
			case 6:
				exit(1);
			default:
				break;
		}
	}
	return 0;
}
bool menu(){ 
// the menu of crud
	cout << "\nThe list:" << endl;  
	cout << "\n1\ Add a Contact" << endl;   //to add contact
	cout << "2\ display Contacts" << endl;  //to display contact
	cout << "3\ Search a Contact" << endl;  //to search about contect
	cout << "4\ Delete a Contact" << endl;  //to delete contect
	cout << "5\ Exit" << endl;              //to exit from the menu
	return true;  //to return statement when run a method of bool
}
