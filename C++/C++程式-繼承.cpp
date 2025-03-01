#include <iostream>
#include <string>
using namespace std;

class Person{
	private:
		string _name;
		string _blood;
		string _star;
	public:
		void Input(){
			cout << "�п�J�m�W�G";
			cin >> _name;
			cout << "�п�J�嫬�G";
			cin >> _blood;
			cout << "�п�J�P�y�G";
			cin >> _star;
		}
		
		void Output(){
			cout << "�m�W�G" << _name << endl; 
			cout << "�嫬�G" << _blood << endl; 
			cout << "�P�y�G" << _star << endl; 
		}
		
};
//Student�~�� Person
class Student : public Person{
	private:
		string _studentId;
	public:
		void Input(){
			Person::Input();   //�~�ӤU�Ӫ����ӤH(Person)��Input
			cout << "�п�J�Ǹ��G";
			cin >> _studentId;
		}
		
		void Output(){
			Person::Output();   //�~�ӤU�Ӫ����ӤH(Person)��Output
			cout << "�Ǹ��G" << _studentId << endl; 
		}
		
		
		 
	
	
};
//Teacher�~�� Person
class Teacher : public Person{
	private:
		
		string _title;
	public:
		void Input(){
			Person::Input();   //�~�ӤU�Ӫ����ӤH(Person)��Input
			cout << "�п�J¾�١G";
			cin >> _title;
		}
		
		void Output(){
			Person::Output();  //�~�ӤU�Ӫ����ӤH(Person)��Output
			cout << "¾�١G" << _title << endl; 
		}
};


int main(){
	Person sonic;
	Student tails;
	Teacher amy;
	
	sonic.Input();
	tails.Input();
	amy.Input();
	
	sonic.Output();
	tails.Output();
	amy.Output();
	
	return 0;
}
