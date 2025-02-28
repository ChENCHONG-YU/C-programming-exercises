#include <iostream>
#include <cmath>
using namespace std;

class Vector{
	private:
	//���(�ܼ�) 
	float x;
	float y;
	
	public:
	//�ާ@�B��k(�禡)
	Vector(){
		x = 0;
		y = 0;
	}
	Vector(float newx, float newy){
		x = newx;
		y = newy;
	}
	
	float getLenght(){
		return sqrt(x*x + y*y);
	}
	
	Vector add(Vector other){
		Vector result(x + other.x, y + other.y);
		return result;
	}
	/*
	operator�U�W��q�N�O�B��l���N�� 
	operator() �i�H�Ψӭ����禡�I�s�B��l�A
	�ϱo����i�H���禡�@�˳Q�եΡA�o�O�@�ر`�����Ϊk�C
	operator+ �i�H��ܻ��ڭn�w�q�@�ӥ[�k�B��l���N��C 
	*/
	Vector operator+(Vector& other){
		//�o�̨��]�i�H���ΦA�ŧi�@���ܼƥi�H������Vector()�g�breturn�N�i�H�F (�o�̺�������) 
		Vector result(x + other.x, y + other.y);
		return result;
	} 
	
	Vector operator*(float vlaue){
		//�o�̨��]�i�H���ΦA�ŧi�@���ܼƥi�H������Vector()�g�breturn�N�i�H�F (�o�̨ϥγo�ؤ覡) 
		return Vector(x * vlaue, y * vlaue);
	}
	
};

int main(){
	
	Vector v1(1,1), v2(2,3);
//	Vector sumVector = v1.add(v2);

	/*
	�[�k�쥻���w�q���bC�y��C++�̭��쥻�w�g�w�q�n���F��L���w�q�L�ۤv���[���欰�A���O�o�̦ۤv����
	Vector�O�S���w�q�[�k�欰���A�ҥH�o�̪�v1 + v2�{�������D�o�̬O�n�p��[�A�쩳�O�nx+x?�٬Oy+y?
	�ҥH�p�G�Q�n�o�򰵴N�����b�W���ۤv�w�q�ۤv��Vector�A��O�b�W��N�w�q�Foperator�禡�A�o��@��
	 v1 + v2�N�i�H���`�ϥΤF�C 
	 */ 
//	Vector sumVector = v1 + v2; //�]�۵���Vector sumVector =  v1.operator+(v2);
	Vector sumVector = (v1 + v2) * 3.0; //�]�۷�� Vector sumVector = (v1 + v2).operator*(3.0);
	cout << "V�V�q�����סG" << sumVector.getLenght() << endl;  
	
	return 0;
}
