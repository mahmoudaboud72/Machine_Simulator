
/*
 FCAI - OOP Programming - 2023 - Assignment 2

zip file Name: A2_Task1&2&3  _S24_ 20220320 .zip

Name-----> Mahmoud Mohamed Mahmoud 20220320

Teaching Assistant: Eng/ Mohamed Talaat Saad Farrag.
*/



#include <iostream>
using namespace std;
#include <bits/stdc++.h>


#ifndef MACHINE_SIMULATOR_MACHINE_SIMULATOR_H
#define MACHINE_SIMULATOR_MACHINE_SIMULATOR_H


class memory{
protected:
    int counter;
    string memory[265];


};


class Register{
protected:
    string reg[16];
};


class instuactions : public memory , public Register{
public:
    void load1();
    void load2();
    void store();
};


class Machine_Simulator : public instuactions  {
private:
    int start_addres;
public:
    Machine_Simulator();
    void menu();
    void fetch();
    void execute();
    void print();

};

#endif //MACHINE_SIMULATOR_MACHINE_SIMULATOR_H
