#include <iostream>
#include <string>

using namespace std;

class Person{
	public:
		Person()
		{
			name = "No name";
			height = 0;
			weight = 0;
		};
		Person(string n, int h, int w){  //�p�G�n�w�q�w�]�ȥu�n�[�b�ܼƫ᭱(EX�GPerson(string n, int h, int w = 0)) 
			name = n;
			height = h;
			weight = w;
		};
		void input(){
			cin >> name;
			cin >> height;
			cin >> weight;
		};
		void output(){
			cout << "Name�G" << name << endl;
			cout << "Height�G" << height << "cm" << endl;
			cout << "Weight�G" << weight << "km" << endl;
		};
		private:
			string name;
			int height;
			int weight;
};

int main(){
	Person p1;
	
	//�o��|���������A�]���W��禡�w�q�N�O�n��J�T�ӭȡA���D�b�W���w�q�@�ӹw�]�ȵ{���~���|���� 
//	Person p2("Andy", 180);   

	Person p2("Andy", 180, 80);
	
	p1.output();
	p2.output();
	
	return 0;
}
