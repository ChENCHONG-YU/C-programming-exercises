#include <iostream>
using namespace std;
void f(int &b){
	b = 3;
} 
int main(){
	int a = 5;
	//int &b = a;  //��a�ܼƨ��@�ӧO�W��b�A�N��O���o���ܼ�b�O�ѷө�a(�o�̪�&�P���Ъ�&�������@��) 
	f(a);         //�۷��int &b = a; 
	
	cout << "a = " << a << endl;
	return 0;
}
