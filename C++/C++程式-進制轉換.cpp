#include <iostream>
//using std::cout; //�u��cout�n�M��std���F��A�o�ؼg�k�i�H�F���O�@���@��
using namespace std; //��ݭn�Ψ�std������@���]�w�W�h 

int main(){
	int a;
	cout <<"�Q�i��Ʀr:";
	cin >> a ;
	cout << "�K�i��Ʀr:"<< oct << a << endl;   //�K�i��
	cout << "�Q���i��Ʀr:"<< hex << a << endl;   //�Q���i��
	cout << showbase << hex <<uppercase << a << endl;  //showbase��ܶi��� uppercase��ܧ� 0x��x�ܦ��j�gX
	cout << "��^�Q�i��Ʀr:"<< dec << a << endl; //��^�Q�i��
	return 0;
}
