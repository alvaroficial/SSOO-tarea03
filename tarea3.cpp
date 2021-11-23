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
        cout<<"Sucesión n°:"<<n<<" Número fibonacci:"<<b<<" PPID:"<<getpid()<<endl;
        n++;
        std::this_thread::sleep_for(2000ms);
        
    }   
}

void nprimos(){
    int n=1;
    int a=1;
    while (n<=50)
    {
        if(a%2 != 0)
        {
            cout<<"Iteración n°:"<<n<<" Número primo:"<<a<<" PID:"<<getpid()<<endl;
            n++;
            std::this_thread::sleep_for(2000ms);
            
        }
        a++;
    }
}

void controlador(int sig){
    cout<<"accion denegada"<<sig<<endl;
}


int main(){

    pid_t a = fork();
    signal(SIGTSTP, controlador);
    signal(SIGINT, controlador);
    if(a > 0){
        fibonacci();
        /*cout<<"Parent Process:"<<endl;
        cout<<"Pid:"<<getpid()<<endl;
        cout<<"Parent PID:"<<getppid()<<endl;
        cout<<endl;*/
    }
    else if(a == 0){
        nprimos();
        /*cout<<"Child Process:"<<endl;
        cout<<"Pid:"<<getpid()<<endl;
        cout<<"Parent PID:"<<getppid()<<endl;
        cout<<endl;*/
    }

    return 0;
}