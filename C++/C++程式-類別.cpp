#include <iostream>
using namespace std;

class Student{
	public:
		//���(�ݩʡB�ܼ�)
		char name[100];
	 	int age;
	 	int blood;
	 	int chineseScore;
	 	int mathScore;
	 	int englishScore;
	 	
	 	//�ާ@(��k�B�禡)
		 
		void print(){  
			char bloodTable[4][5]=
			{ "A", "B", "O", "AB"};
			cout << "�ǥ�" << name << "(" << age << ")�G" << endl;
			cout << "�嫬��" <<  bloodTable[blood] << endl;
			cout << "���妨�Z�G" << chineseScore << "," << endl;
			cout << "�ƾǦ��Z�G" << mathScore << "," << endl;
			cout << "�^�妨�Z�G" << englishScore << endl;
			
		} 
};

int main(){
	Student students[2] ={
		{"Sonic", 30, 1, 80, 50, 95},
		{"Tails", 28, 2, 75, 98, 92}	
	};
	for (int i = 0; i < 2; i++){
		students[i].print();
	}
	
	
	return 0;
}
