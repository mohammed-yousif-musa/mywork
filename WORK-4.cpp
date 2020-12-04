/*
 * Name: mohammed yousif musa idress
 * Class: 2
 * Department: Computer Engineer
 */
#include<iostream>  // including input/output library for user input and preview
#include<conio.h>
#include<math.h>
// including math library before heading towards the program
// perciesly we're using it here just for the square root function
using namespace std;
// this line litreally sets us free from writing std:: each time
// for input/output operations 
class shape {          //main class  
     protected:
          float ar, prmtr;  // definition of float so we can deal with fractions
     public:
          virtual void area()=0;
          virtual void parimeter()=0;
};
class square : public shape {
     private:
          float side;          
     public:
          square(){      
              ar=prmtr=side=0;
          }
          void get(){         
              cout<<"Enter a side of square : "<<endl; //enter any number
              cin>>side;
          }
          void area(){
              ar=side*side;       
              cout<<"Area of the square is : "<<ar;  //calculate the area 
          }
          void parimeter(){
              prmtr=4*side;       
              cout<<endl<<"The perimeter of the square is : "<<prmtr; //calculate perimeter
          }
};
class triangle : public shape {
     private:
          float base, height, hyp;  
     public:
          triangle(){             
              ar=prmtr=base=height=hyp=0;
          }
          void input(){            
              cout<<endl<<"Enter three sides of Right triangle : "<<endl; //enter any number
              cin>>base>>height>>hyp;
          }
          void area(){
              ar=0.5*base*height; 
              cout<<endl<<"The area of Right Triangle is : "<<ar;  //calculate the area 
          }
          void parimeter(){
              prmtr=base+height+hyp;   
              cout<<endl<<"The parimeter of Right Triangle id : "<<prmtr; //calculate perimeter
          }
};
class rectangle : public shape {
	private:
		float length, width;
	public:
		rectangle(){
			ar=prmtr=length=width=0;
		}
		void enter(){
			cout<<endl<<"Enter length and width of rectanle : "<<endl; //enter any number
			cin>>length>>width;
		}
		void area(){
			ar=length*width;
			cout<<"The are of rectangle is : "<<ar<<endl;  //calculate the area 
		}
		void parimeter(){
			prmtr=2*(length+width);
			cout<<"The parimeter of rectangle is : "<<prmtr<<endl; //calculate perimeter
		}	
};
class circle : public shape {
	private:
		float radius;
	public:
		circle(){
			ar=prmtr=radius=0;
		}
		void get(){
			cout<<endl<<"Enter radius of circle : "<<endl; //enter any number
			cin>>radius;
		}
		void area(){
			ar=3.14*radius*radius;
			cout<<"The are of circle is : "<<ar<<endl;  //calculate the area 
		}
		void parimeter(){
			prmtr=2*3.14*radius;
			cout<<"The parimeter of circle is : "<<prmtr<<endl; //calculate perimeter
		}	
};

int main(){
     square s1;
     triangle t1;
     rectangle r1;
     circle c1;
     s1.get();
     s1.area();
     s1.parimeter();
     t1.input();
     t1.area();
     t1.parimeter();
     r1.enter();
     r1.area();
     r1.parimeter();
     c1.get();
     c1.area();
     c1.parimeter();
     getch();
     return 0; // returning to the main() a success sign, getting it ready to terminate  
    
}
