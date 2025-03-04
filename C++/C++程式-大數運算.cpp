#include <algorithm>
#include <iostream>
#include <string>
 
// �Ynum1<num2�Asign�h�|��true�A�Ϥ���false�C
bool compare(const std::string &num1, const std::string &num2) {
    if (num1.length() > num2.length()) {
        return false;
    }
    else if (num1.length() < num2.length()) {
        return true;
    }
    else {
        for (int i = 0; i < num1.length(); ++i) { // �Y�Onum1�Mnum2���׬ۦP�h�@�@����C��bit����
            if (num1[i] < num2[i]) {
                return true;
            }
            else if (num1[i] > num2[i]) {
                return false;
            }
        }
    }
    return false; // num1 == num2���ܴN�|��o��A��sign�]��false�N��۴���t
}
 
// �[�k
std::string add(std::string num1, std::string num2) {
    if (compare(num1, num2)) // ���num1�Mnum2�j�p�A��num1>=num2�A��K�᭱�p��
        std::swap(num1, num2);
    int index1 = num1.length(), index2 = num2.length(), carry = 0; // carry�N��i��Abit�ۥ[���G>9��1�A�Ϥ�carry��0
    std::string ans = "";
 
    while (index1 > 0 || index2 > 0) { // num1�Mnum1���q���ݶ}�l�ۥ[
        --index1, --index2;
        int n = num1[index1] - '0' + carry;
        if (index2 > -1) { // �ѩ�bwhile()�e�I�scompare()�Mstd::swap�A�]��num1��>=num2�A�Ynum2�[���F�N���A�[
            n += num2[index2] - '0';
        }
        carry = n / 10;
        n %= 10;
        ans += (n + '0');
    }
    if (carry > 0) // �B�z 999 + 1 = "1"000 �o�ضi����D
        ans += '1';
 
    reverse(ans.begin(), ans.end()); // ans�O�̤pbit���s�J�A�ҥH���׭n�ϧǿ�X
    return ans;
}
 
// ��k
std::string sub(std::string num1, std::string num2) {
    bool is_negative = compare(num1, num2); // �ΥH�P�_�۴�O�_���t
    if (is_negative)                        // ���num1�Mnum2�j�p�A��num1>=num2�A��K�᭱�p��
        std::swap(num1, num2);
    int index1 = num1.length(), index2 = num2.length(), carry = 0; // carry�N��i��Abit�۴�G<0��-1�A�Ϥ�carry��0
    std::string ans = "";
 
    while (index1 > 0 || index2 > 0) { // num1�Mnum1���q���ݶ}�l�۴�
        --index1, --index2;
        int n = num1[index1] - '0' + carry;
        if (index2 > -1) { // �ѩ�bwhile()�e�I�scompare()�Mstd::swap�A�]��num1��>=num2�A�Ynum2��F�N���A��
            n -= num2[index2] - '0';
        }
        if (n < 0) { // ��ebit�۴�t�A�n�V�e�ɦ�
            carry = -1;
            n += 10;
        }
        else {
            carry = 0; // ��ebit�۴���A���έɦ�
        }
        ans += (n + '0');
    }
    reverse(ans.begin(), ans.end());         // ans�O�̤pbit���s�J�A�ҥH���׭n�ϧǿ�X
    for (int i = 0; i < ans.length(); ++i) { // �B�z�}�Y��0�A���O00021354�n�ܦ�21354
        if (ans[i] != '0') {                 // �J�줣��0�ɡA��e����0��������
            ans.erase(0, i);
            break;
        }
        else if (i == ans.length() - 1) // �Y������0�h��X���0�A���O000000000�n��X0
            return "0";
    }
    if (is_negative) // �쥻��num1-num2���t�ơA�}�Y�[�ӭt��
        ans = '-' + ans;
    return ans;
}
 
// ���k�A�Ϊ����k�p��A�H�h���I�sadd()����
std::string mul(std::string num1, std::string num2) {
    std::string ans = "";
    for (int i = num2.length() - 1; i > -1; --i) { // �q����(num2)���̫�@bit�}�l�A
        for (int j = 0; j < num2[i] - '0'; ++j) {  // �֥[num2[i]��num1
            // �ѩ�C���i�Jadd()���|�I�scompare()�Mstd::swap()�A��add()����num1>=num2�A���F����mul()����num1�Q���ȡA�ҥH��temp�ӥN��num1�i�Jadd()
            std::string temp = num1;
            ans = add(ans, temp);
        }
        num1 += "0"; // �C�����@���ۥ[��A�Q���ƭn����1bit�A�]�N�O���H10
    }
    return ans; // �ѩ�O�z�L�h���I�sadd()�ӧ��������k�Aadd()��^��string�w�g��reverse�F�A�ҥH�o��i�H������Xans
}
 
// ���k�A�Ϊ����k�p��A�H�h���I�ssub()����
std::string div(std::string num1, std::string num2) {
    if (compare(num1, num2)) // �Y��J��num1<num2����return 0
        return "0";
    // index�ΥH�p��num1��index�A���]num1 = 1234�Anum2 = 11�A�@�}�lnow = ""�Aindex = 0�A
    // ���U��now�֥[num1[index]�ܦ�1�Aindex + 1�A���h�Mnum2����A�Y��num2�p�h�~��֥[num1[index]�A
    // ����now = 12�A���h��num2����A�Ǧ^�Ӫ�sign��false�N��num1>=num2�A�N�i�H�i��۴�A12 - 11 = 1
    // �Anow = 1�A�o��ans_count + 1�A�A��now = 1�h�Mnum2 = 11����A�o�{�񰣼Ƥp�A�]����ans_count��
    // �Jans���A�M��now�֥[num1[index]�A�H���@�����ƨ�num1�Q�֥[���Ҧ�bit�C
    int index = 0, ans_count = 0; // index�Onum1��index�A�@�}�l��0�A�H�ۨC�����t�̥��䪺bit��now�Aindex�|�[1
    std::string ans = "", now = "";
    while (true) {
        if (compare(now, num2)) { // �i�����A�Ysign��true�N��now(�Q����) < num2(����)�A�n�֥[1��num1�̥��䪺bit��now
            ans += ans_count + '0'; // ��W���۴����(�]�N�O��)�[�ians���A�ѩ�@�}�lnow��""�A�ҥH�|���ƭ�0�}�Y
            ans_count = 0;          // ���mans_count
            if (index == num1.length()) // �Ynum1��bit���Q�֥[���A�h���Xwhile�j��
                break;
            now += num1[index]; // ��now�֥[num1�̥��䪺bit
            ++index;            // �֥[��num1��index���k��
        }
        else {
            ++ans_count;          // �C���۴�᳣�[1
            now = sub(now, num2); // now = �۴�᪺���G
            if (now == "0")       // �Y�O�۴��n��0�A�h��now�]��""
                now = "";
        }
    }
    for (int i = 0; i < ans.length(); ++i) { // �����}�Y��0�A�Ҧp:000123�n�ܦ�123
        if (ans[i] != '0') {
            ans.erase(0, i);
            break;
        }
    }
    return ans; // �ѩ�O�z�L�h���I�ssub()�ӧ��������k�Asub()��^��string�w�g��reverse�F�A�ҥH�o��i�H������Xans
}
 
int main() {
    char op;
    std::string num1, num2;
    while (std::cin >> num1 >> op >> num2) {
        if (op == '+')
            std::cout << add(num1, num2) << '\n';
        else if (op == '-')
            std::cout << sub(num1, num2) << '\n';
        else if (op == '*')
            std::cout << mul(num1, num2) << '\n';
        else if (op == '/')
            std::cout << div(num1, num2) << '\n';
    }
    return 0;
}
