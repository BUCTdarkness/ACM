#include<iostream>
using namespace std;
class Cla_Base{
    public:
        void fun_Dispaly(long num){
        cout<<"class Cla_Base:"<<num<<endl;}
        void fun_Dispaly(char *str){
        cout<<"class Cla_Base:"<<str<<endl;}
        void fun_Dispaly(){
        cout<<"Dispaly in class Cla_Base without parameter!\n";}

};

class Cla_Sub:public Cla_Base{
    private:
        static int obj_n;
    public:
        Cla_Sub(){obj_n++;}
        ~Cla_Sub(){obj_n--;}
        static int GetObj_n(){return obj_n;}
        void fun_Dispaly(long num){
        cout<<"class Cla_Sub:"<<num<<endl;}
        void fun_Dispaly(char *str){
        cout<<"class Cla_Sub:"<<str<<endl;}
        void fun_Dispaly(){
        cout<<"Dispaly in class Cla_Sub without parameter!\n";}

};

int Cla_Sub::obj_n=0;

int main(){
     Cla_Base *pBase;
     Cla_Sub Sub1,*pSub=new Cla_Sub[5];
     pBase=&Sub1;
     pBase->fun_Dispaly("Hello!");
     return 0;
}
