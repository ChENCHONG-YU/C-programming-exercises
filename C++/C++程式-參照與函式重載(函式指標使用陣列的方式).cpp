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
int mod(int a, int b){
	return a % b;
}

int main(){
	int a = 1;
	int b = 3;
	
	int (*calculate[5])(int a, int b)=
	 { add, subtract, multiple, divide, mod};
	 
	for(int i = 0 ; i < 5; i++){
		cout << "result:" << calculate[i](a, b) << endl;
	}
		
	return 0;
}
