#include <iostream>
//using std::cout; //�u��cout�n�M��std���F��A�o�ؼg�k�i�H�F���O�@���@��
using namespace std; //��ݭn�Ψ�std������@���]�w�W�h 


float sum (float a, float b){
	cout << "�B�I�ƪ���" << endl;  //��X���G 
	return a + b;
}

int sum (int a, int b){
	cout << "��ƪ���" << endl;   //��X���G 
	return a + b;
}

int main(){
    float a, b;
//    int a, b;
	cin >> a >> b; //��J�Ѽ� 
	cout << "Sum: " << sum(a,b)<< endl;   //��X���G 
	return 0;
}
