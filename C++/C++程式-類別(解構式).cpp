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
		
		/*�bmain��k���u�n�����return 0�N��{�������A�{�������ɦ^��main��k���w�q��p1�A
		���b�^��p1���P�ɴN�|�I�s�o�q�Ѻc�禡
		�Ѻc�禡�g�k�N�O�b�禡�W�٪��e���[�W�@�� "~"�Ÿ� 
		*/
		~Person(){
			cout << "BeyBey" << endl;   //���󵲧��ɦL�XBeyBey
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
	p1.output();
	
	return 0;
}
