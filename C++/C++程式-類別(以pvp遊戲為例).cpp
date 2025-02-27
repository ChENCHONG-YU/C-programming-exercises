#include <iostream>
#include <string> 
#include <cstdlib>  //�ޥ�C�y�����禡�w�A�bC�N�Ostdlib.h
#include <ctime>   //�ޥ�C�y�����禡�w�A�bC�N�Otime.h (�H����)

using namespace std;

class Player{
	private:
		//���
		 string name;  //�W�r 
		 int hp;	   //��q 
		 int atk;      //�����O 
	public:
		//�欰
		
		//�����ݩ� 
		 Player(string n, int h, int a){
		 	name = n;
		 	hp = h;
		 	atk = a;
		 } 
		 
		 //�����ʧ@ 
		 void attack(Player& p2){
		 	p2.setHp(getHp() - atk);   //p2��HP����� 
		 	
		 	cout << "---------------------" << endl;
		 	cout << name << "�����F" << p2.name << endl;
			cout << p2.name << "����F" << atk << "�I���ˮ`" << endl;
			cout << p2.name << "�ѤU" << p2.hp << "����q" << endl;
			cout << "---------------------" << endl;
			cout << endl;
		 }
		 
		 //�O�@hp���|�X�{�t�� 
		 void setHp(int h){
		 	if(h < 0){
		 		hp = 0;
		 		return;
			 }
			 hp = h;
		 }
		 
		 int getHp(){
		 	return hp;
		 }
		 string getName(){
		 	return name;
		 }
		 
		 /*
		    C++�Gbool
			bool a = true;
			bool b = false; 
		 */
		 bool isAlive(){
		 	if(hp > 0){
		 		return true;
			 }else{
			 	return false;
			 }
		 }
		 
		 
};

int main(){
	
	/* 
	1. srand() ��ƥΩ�]�m rand() �ͦ��H���ƪ��ؤl�A�T�O�H���ƧǦC���i���{�ʡC
	2. srand(time(NULL));�i�H�b�C���B��{���ɥͦ����P���H���ơC�o�˥i�H�T�O�C�����ͪ��H���ƦC���O���@�˪��C
	3. �ϥ�time()�o�Ө禡�i�H����ثe���ɶ��A�q�`�̭����|�a�@��NULL�C 
	4. srand()�̭����@�w�n�ϥήɶ��A�o�̥u�n�Q��k���L�C���}�{�����ɭԥL�൹�X���@�˪��ȴN�i�H�F�A�o�̨ϥ�
	   �ɶ����覡���²��C
	5. srand()�̭����ȳq�`���n���O�ЩʡA�p�G�S���O�ЩʴN���i���W�����椣�@�ˡA�p�G�n��W�����檺���@��
	�N�����n���W�����檺�����A�ɶ��N�O���o�˪��S�ʡA�ɶ��O�@�Ӭ����b�q���̭��L�b���A��tick�A�ҥH�ɶ��O��
	�O�Щʪ��C 
	*/
	srand(time(NULL));
	
	//rand() % 1000 + 1:���H���� 1 ~ 1000 ���� �A�p�G�O�g rand() % 1000�N��ܨ��H���� 0 ~ 999 ���� 
	Player p1("�i��",rand() % 1000 + 1,rand() % 1000 + 1);
	Player p2("�@�ٮ�a�]���@",rand() % 1000 + 1,rand() % 1000 + 1);
	
	//��p1�Pp2���٦s�����ɭ�p1�i�H����p2�Bp2�i�H����p1 
	while(p1.isAlive() && p2.isAlive()){
		p1.attack(p2);
		p2.attack(p1);
	}
	//�p�G p1.isAlive() = true �hp1Ĺ�A�_�h�p�Gp2.isAlive() = true �hp2Ĺ�A�_�h����(��ܨ�ӳ�����false) 
	if(p1.isAlive()){
	    cout << p1.getName() << "WIN!" << endl;
	}else if(p2.isAlive()){
		cout << p2.getName() << "WIN!" << endl;
	}else{
		cout << "����" << endl; 
	}
	
	return 0;	
}
