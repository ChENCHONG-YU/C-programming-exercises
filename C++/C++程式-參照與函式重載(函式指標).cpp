#include <iostream>
//using std::cout; //�u��cout�n�M��std���F��A�o�ؼg�k�i�H�F���O�@���@��
using namespace std; //��ݭn�Ψ�std������@���]�w�W�h 

int add(int a, int b){
	return a + b;
}

int subtract(int a, int b){
	return a - b;
}
int multiple(int a, int b){
	return a * b;
}
int divide(int a, int b){
	return a / b;
}

int main(){
	int a = 1;
	int b = 3;
	
	int select;
	cout << "1�P3���B��(�[�k�п�J1�B��k�п�J2�B���k�п�J3�B���k�п�J4)�G"; 
	cin >> select; 
	
	int (*calculate)(int a, int b) = add;   //�禡����
	switch(select){
		case 1:
			calculate = add;
			cout << a << " + " << b << " = " <<calculate(a,b) << endl;
			break;
		case 2:
			calculate = subtract;
			cout << a << " - " << b << " = " <<calculate(a,b) << endl;
			break;
		case 3:
			calculate = multiple;
			cout << a << " * " << b << " = " <<calculate(a,b) << endl;
			break;
		case 4:
			calculate = divide;
			cout << a << " / " << b << " = " <<calculate(a,b) << endl;
			break;
		default:
			calculate = add;
			cout << a << " + " << b << " = " <<calculate(a,b) << endl;
			break;
	}	
	
	
	
	return 0;
}
