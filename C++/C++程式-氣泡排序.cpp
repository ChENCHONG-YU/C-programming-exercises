#include <iostream>
using namespace std;
int main(){
	int amount,tmp;  //�ŧi�ܼ� 
	cout << "Enter the sequence size" << endl;  //�����������X�o�q�åB���� (cout�O��X���N��) 
	cin >> amount;    //��J�Ʀr���W�� EX:10�άO20 (cin����J���N��) 
	cout << "Input value" << endl;    //��X Input value��r�åB���� 
	int * m_Sequence = new int[amount];  //�ŧi�ʺA�}�C 
	for(int i = 0;i < amount ;i++){
		cin >> m_Sequence[i];   //��J�Ʀr�}�C EX: 5 20 -100 3 7 57 9 (�p�G�W�X�d��N���|����W�X������) 
	} 
	
	//��w�Ƨ� (�Ʀr�Ѥp��j��z��z) EX;���] m_Sequence[i]��X[0]=2,m_Sequence[i+1]��X[1]=1
	for(int i = 0; i < (amount-1);i++){
		if(m_Sequence[i] > m_Sequence[i+1])  //�p�G�e���Ʀr��᭱�Ʀr�j 
		{
			tmp = m_Sequence[i];  // �NX[0]�����e�Ȧs��tmp 
			m_Sequence[i] = m_Sequence[i+1];  //�M��A��X[1]���e���X[0] 
			m_Sequence[i+1] = tmp; //�̫�A��Ȧs�btmp�����e���X[1]
			i = -1; 
		}
	}
	//�g�L�H�W��z�A���]����X���G��1 2  
	
	//�N��z�������G��X 
	for(int i = 0; i < amount; i++){
	    cout << m_Sequence[i] << endl;
    }

    delete [] m_Sequence;  //�R���ʺA�}�C 
    return 0; //�{������ 
	
}


