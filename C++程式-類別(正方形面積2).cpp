#include <iostream>
using namespace std;

class Square{
	private:
		int len;	
	public:
		Square(){   //�غc����l�ȳ]�w 
			len = 5;
		}
		~Square(){ //�Ѻc��Ƚm�� 
			cout << "���n�p�⵲�G�p�W�A�{������!!!" << endl; 
		} 
		void setLen(int n){
			if(n <= 0){
				cout << "������t�Ʃ�0�ܩ_��......" << endl; 
				len = 0;
				return;
			}
			len = n;
		}
		int getLen(){
			return len;
		}
		int area(){
			return len * len;
		};		
};

int main(){
	Square a;
	a.setLen(10);
	cout << "�����" << a.getLen() << "������έ��n���G" << a.area() << endl;
	a.setLen(20);
	cout << "�����" << a.getLen() << "������έ��n���G" << a.area() << endl; 
	
	
	return 0;
}
