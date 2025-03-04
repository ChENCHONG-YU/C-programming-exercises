#include <iostream>
#include <unordered_map>
using namespace std;

// �إ߭^��r�������Ʀr���M�g��
/*
1.unordered_map<char, int> �O C++ �зǨ禡�w <unordered_map> ���Ѫ��@�� ����� (Hash Table) �e���A
�����@������ �r�� (Dictionary)�A�i�H���ڭ̨ϥ� �� (key) �ֳt�d������� �� (value)�C
2.unordered_map �O�@�� �M�g�e�� (Mapping Container)�A�����\�ڭ̫إߡu��ȹ� (Key-Value Pair)�v�����Y�C
char �O�� (Key)�G�o�̪���O �r�� (A-Z)�A�Ψӹ����x�W�����Ҧr�����Ĥ@�Ӧr���C
int �O�� (Value)�G�o�̪��ȬO �������Ʀr�N�X�A�Ҧp 'A' �N�� 10�B'B' �N�� 11�C 

*/ 
unordered_map<char, int> letterMap = {
    {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 34}, {'J', 18},
    {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22}, {'O', 35}, {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27},
    {'U', 28}, {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33}
};

// ���ҥx�W�����Ҧr���O�_�X�k
bool validateTaiwanID(const string &id) {
    if (id.length() != 10 || !isalpha(id[0])) return false; // �T�O���׬� 10 �B�Ĥ@�X���^��r��
    /*
	1.isalpha(id[0])�OC++�зǨ禡�w<cctype>���Ѫ��禡�A���Ψ��ˬd�@�Ӧr�ŬO�_���^��r��(A~Z��a~z)�C
	id[0]�N���J�������Ҧr�����Ĥ@�Ӧr���C 
	2. !isalpha(id[0]): ��isalpha(id[0])�^��true(�N��id[0]�O�^��r��)�ɡA�[�W!�� �ܦ�false�A��ܲŦX
	�W�h�C
	3.�� isalpha(id[0])�^��false(�N��id[0]���O�^��r���A�Ҧp�Ʀr�βŸ�)�ɡA�[�W!���ܦ�true �A��ܳo�O
	�@�ӵL�Ī������Ҹ��X�C 
	*/ 
    
    
    int num = letterMap[id[0]]; // ���o�^��r���������Ʀr
    int sum = (num % 10) * 9 + (num / 10); // �p��^��r���ƭȡG�Ӧ�� * 9 + �Q��� 
    /*
	(num % 10) * 9 + (num / 10); �o�̧@�k���N�O��Ĥ@�Ӫ��^��r���������Ʀr �Q��� + �Ӧ�� *9
	EX:�p�G�Ĥ@�ӭ^��Ʀr�OA�������Ʀr�O10 �p��覡�N�O 1 + 0 * 9  = 1�A
	�p�G�OB�������Ʀr�O11 �p��覡�N�O 1 + 1 * 9  = 10�C 
    */
    
    for (int i = 1; i < 9; ++i) { // �q�ĤG��}�l�B�z�Ʀr
        if (!isdigit(id[i])) return false; // �T�O�Ҧ��Ʀr�������Ʀr
        sum += (id[i] - '0') * (9 - i); // �̧ǭ��H 8, 7, 6, ..., 1�A�ò֥[���`�M �Cid[i] - '0'��ܧ�쥻���r�ꫬ�A�ন�Ʀr 
    }
    
    // �̫�@�X (�ˬd�X)
    if (!isdigit(id[9])) return false; // �T�O�̫�@�X���Ʀr
    sum += (id[9] - '0'); // �[�W�̫�@�X
    
    return sum % 10 == 0; // �Y�`�M��Q 10 �㰣�A�h���X�k�����Ҧr��
}

int main() {
    string id;
    while (cin >> id) { // ����Ū����J���� EOF
        cout << (validateTaiwanID(id) ? "real" : "fake") << endl; // ��X�P�_���G
    }
    return 0; // �����{��
}
