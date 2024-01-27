#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;


void taskA(){
    for (int i = 0; i < 10;i++){
        sleep(1);
        cout <<"TaskA : "<<i;
    }
}
void taskB(){
    for (int i = 0; i < 10;i++){
        sleep(1);
        cout <<"TaskB : "<<i;
    }
}

int main(){
    // this section is pending
}