#include <iostream>  // TO ALLOWS US TO DISPLAY OUTPUT & INPUT
using namespace std;  //TO USE STANDARD LIBRARIES
struct student        // THIS IS STRUCTURE OF THE STUDENT 
{              
	char name[50];     // INPUT SHOULD BE CHARACTER
	int ID;           //INPUT ID SHOULD BE INTEGER
};

int main()             //TO EXECUTION THE CODE FROM START OF FUNCTION
{      
    student s;
	cout<<"Enter your name: ";     // FOR DISPLAYING OUTPUT
	cin>>s.name;                   // INPUT WE WANT
	cout<<"\nEnter your university ID number: "; 
	cin>>s.ID;
	int mark; // THE INPUT SHOULD B INTEGER
	cout<<"\nPlease enter your mark: ";  
	cin>>mark;
	if(mark >=50 && mark < 60) //IF THE MARK BIGGER THAN 50 AND SMALLER THAN 60
	    cout<<"F";
	if(mark >=60 && mark < 70)
	    cout<<"D";	 
	if(mark >=70 && mark < 80)
	    cout<<"C";     
	if(mark >=80 && mark < 90)
	    cout<<"B";    
	if(mark >=90 && mark <= 100)
	    cout<<"A";
	char ch = 'A';'T';                    //INPUT IS CHATACTER JUST
	cout<<"\nENTER YOUR MAJORING: ";
    cin>>ch;
    switch(ch) {                   // TO SWITCH THE CHARACTER
    	case 'A': cout<<"control"<<endl;  // ENDL IS USED TO INSERT A NEW LINE 
    	break;                                // BREAK IS USED TO PREVENT THE CODE RUNNING INTO THE NEXT CODE 
    	case 'T': cout<<"communication"<<endl;
		break;
		default: cout<<"not of range"<<endl;      // I USED DEFAULT BECAUSE I WANT TO EQUIVALENT BTWEEN TWO STATEMNTS 
		break;                                 
	}    
	    
	return 0; //EXIT STATUS OF THE MAIN() FUNCTION
}
