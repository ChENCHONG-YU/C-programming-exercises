#include <iostream>
using namespace std;

int main(){
	int row, column; 
	while((cin >> row >> column)){
		int matrix[row][column];
		//��J�x�}��� 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < column; j++){
				cin >> matrix[i][j];
			}
		}
		//��X�x�}½�� 
		for(int j = 0; j < column; j++){
			for(int i = 0; i < row; i++){
				cout << matrix[i][j] << ' ';
			}
			cout << endl;
		}
	}
	
	return 0;
} 
