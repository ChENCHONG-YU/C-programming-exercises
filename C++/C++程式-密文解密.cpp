#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   string str;
   int i;
   
   /*
   1.getline(cin ,str);   // �Ω�q�зǿ�J����@���r��A�]�A�Ů�A�A�X�Ψ�Ū���a���Ů檺�Τ��J�C
   2.Ū���S��r�� getline(cin, str, '#') �i�H�ϥβĤT�ӰѼƫ��w�����Ÿ��A
   �b���Ҥ��|Ū������J��'#'����C
   3.�M����J�w�İ� �Y�b�ϥ� getline() �e����L��J�A�i�H�� cin.ignore()
    �M���w�İϡA�_�h�i��|���L���ܿ�J�C
   */   
   getline(cin ,str);
   
   for(i = 0; i < str.size(); i++){
       cout << char(str[i] - 7);
   }
    return 0;
}
