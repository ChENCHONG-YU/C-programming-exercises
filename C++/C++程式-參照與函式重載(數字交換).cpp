#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 10;
	int b = 5;
	cout << "�洫�e��a = " << a << endl;
	cout << "�洫�e��b = " << b << endl;
	swap(a,b);
	cout << "�g�L�洫�᪺a = " << a << endl;
	cout << "�g�L�洫�᪺b = " << b << endl; 
	 
	return 0;
}
