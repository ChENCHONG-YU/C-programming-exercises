#include <iostream>
using namespace std;

class Square{		
	public:
		int len;
		int area(){
			return len * len;
		};		
};

int main(){
	Square len[2] = {
		{10},{20}
	};
	for (int i = 0; i < 2; i++){
		
		cout << "�����" << len[i].len << "������έ��n�G" <<len[i].area() << endl;
	}
	
	
	return 0;
}
