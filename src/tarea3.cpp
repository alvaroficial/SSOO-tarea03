//Alvaro Martinez Diaz 20.725.370-7
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<thread>
#include<chrono>
#include<csignal>

using namespace std;
using namespace std::chrono_literals;
    
void fibonacci(){
    int n=1;
    int a=0;
    int b=1;
    int aux=0;
    while (n<=50)
    {
        aux = b;
        b = b+a;
        a = aux;
        cout<<"Numero fibonacci:"<<b<<" PPID:"<<getpid()<<endl;
        n++;
        std::this_thread::sleep_for(2000ms);
        
    }   
}

void numimpar(){
    int n=1;
    int a=1;
    while (n<=50)
    {
        if(a%2 != 0)
        {
            cout<<"Valor impar:"<<a<<" PID:"<<getpid()<<endl;
            n++;
            std::this_thread::sleep_for(2000ms);
            
        }
        a++;
    }
}

void controlador(int sig){
    cout<<"Detencion no permitida"<<sig<<endl;
}

int main(){

    pid_t a = fork();
    signal(SIGTSTP, controlador);
    signal(SIGINT, controlador);
    if(a > 0){
        fibonacci();
        
    }
    else if(a == 0){
        numimpar();
        
    }

    return 0;
}