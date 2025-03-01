#include <iostream>
#include <string>
using namespace std;

class Person{
	private:
		string _name;
		string _blood;
		string _star;
	public:
		/*
		   void Input()�b�e���[�Wvirtual�A �o�˦b�ϥ� Person ���O�����ЮɡA
		   �s�� Input() �M Output() �禡���ɭԡAC++ �N�|���D�n�h������~�����O��
		    Input() �M Output()��
		*/
		virtual void Input(){
			cout << "�п�J�m�W�G";
			cin >> _name;
			cout << "�п�J�嫬�G";
			cin >> _blood;
			cout << "�п�J�P�y�G";
			cin >> _star;
		}
		
		virtual void Output(){
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
	int peopleAmount = 3;
	 Person* People[peopleAmount] = {
	 	new Person(),
	 	new Student(),
	 	new Teacher()
	 };
	 
	 for(int i = 0; i < peopleAmount; i++){
	 	cout << "�п�J��" << (i+1) << "�ӤH����ơG" << endl; 
		(*People[i]).Input(); //�]��Person�O�@�Ӧs�O�����m�����СA�ҥH�o�䥲���ϥΨ��ȲŸ����o�L���Ȥ~���Input 
		cout << "��J����!" << endl; 
	 }
	  for(int i = 0; i < peopleAmount; i++){
	 	cout << "��X��" << (i+1) << "�ӤH����ơG" << endl; 
		(*People[i]).Output(); //�]��Person�O�@�Ӧs�O�����m�����СA�ҥH�o�䥲���ϥΨ��ȲŸ����o�L���Ȥ~���Output
		cout << "��J����!" << endl; 
	 }
	 //�]���e����new�s���O����t�m�A�ҥH�o��ݭn��delete����O����Ŷ� 
	 for(int i = 0; i < peopleAmount; i++){
	 	delete People[i]; 
	 }
	 
	 
	
	return 0;
}
