#include <iostream>
using namespace std;
typedef struct{
    char name[30];
    int height;
    int weight;
} Person;

void show(Person x){
    cout << "�m�W�G" << x.name << endl;
    cout << "�����G" << x.height << endl;
    cout << "�魫�G" << x.weight << endl;
}

int main()
{
     Person persons[2] = {
        {"Tom",165,60},
        {"Amy",157,65}
    };

    for(int i = 0; i < 2; i++ ){
        show(persons[i]);
    }
    return 0;
}
