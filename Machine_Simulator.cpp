
/*
 FCAI - OOP Programming - 2023 - Assignment 2

zip file Name: A2_Task1&2&3  _S24_ 20220320 .zip

Name-----> Mahmoud Mohamed Mahmoud 20220320

Teaching Assistant: Eng/ Mohamed Talaat Saad Farrag.
*/

#include <iostream>
#include <fstream>
#include <bits/stdc++.h>



using namespace std;
#include "Machine_Simulator.h"




Machine_Simulator ::Machine_Simulator(){

    menu();
    fetch();
    execute();
}

void Machine_Simulator::menu() {
    cout<<"Welcome to our Machine Language Simulator\n";
    cout<<"_____________________________________________________________________\n"
          "The program in the file should be entered like this e.g.(0x1 0x0 0xFF)\n"
          "If there is any mistake in the program will not be executed correctly\n"
          "_____________________________________________________________________\n";

    cout<<"Enter the address you want to start from(hexadecimal):\n";
    string s;
    cin>>s;
    istringstream(s) >> hex >>start_addres; //store instructions from the file into memory (mem) array

}


void Machine_Simulator::fetch() {
    ifstream input_file("Input.txt");
    string s;
    int counter = start_addres;
    while(getline(input_file,s)){
        memory[counter] += s[2];
        memory[counter++] += s[6];
        memory[counter++] = s.substr(10,2);
    }
    input_file.close();

}


void Machine_Simulator::execute() {
    counter = start_addres;

    // Execute instructions until a halt instruction ("C0")
    while (memory[counter]!="C0"){
        switch (memory[counter][0]) {
            case '1':
                load1();
                break;
            case '2':
                load2();
                break;
            case '3':
                store();
                break;

            default:
            {
                cout << "invalid input\n";
                break;
            }
        }
        char s;
        do{
            cout<<"do you want to print any thing (y/n)";
            cin>>s;
            if(s=='y')
                print();
            else
                return ;
        }
        while(s == 'y');
        counter+=2;  // Move to the next instruction in memory
    }
}


// Function to load a value from memory into a register
void instuactions ::load1() {
    int a,b;
    string x="",y="";

    x+=memory[counter][1];
    y+=memory[counter+1];

    istringstream(y) >> hex >>b;
    istringstream(x) >> hex >>a;
    reg[a]=memory[b];

}

// Function to load values from memory into registers
void instuactions ::load2() {
    int a,b;
    string x = "", y = "";

    x+=memory[counter][1];
    y+=memory[counter][1];

    istringstream(x) >> hex >>a;
    istringstream(y) >> hex >>b;

    reg[a] = memory[counter+1][0];
    reg[b] += memory[counter+1][1];

}

// Function to store a value from a register back into memory
void instuactions ::store() {
    int a,b;
    string x="",y="";

    x += memory[counter][1];
    y += memory[counter+1];

    istringstream(y) >> hex >>b;
    istringstream(x) >> hex >>a;
    memory[b] = reg[a];

    if (b==0)
        cout<<memory[b] << endl;

}


void Machine_Simulator ::print() {
    cout<<"1-Registers\n"
          "2-Address\n"
          "3-Screen\n"
          "Enter choice:\n";
    int x; cin>>x;
    switch (x) {

        // Case 1: Print register values
        case 1:{
            cout<<"Which register you want to print:\n";
            int idx; cin>>idx;
            if(idx < 16 && idx >= 0)
                cout<<"register "<<idx<< " = "<<hex<<reg[idx]<<'\n';
            break;
        }

        // Case 2: Print memory address values
        case 2:{
            cout<<"Which address you want to print:\n";
            int idx; cin>>idx;
            if(idx < 256 && idx >= 0)
                cout<<"address "<<idx<< " = "<<memory[idx]<<'\n';
            break;
        }

        // Case 3: Print screen content
        case 3:{
            cout<<"screen = "<<memory[0]<<'\n';
            break;
        }

        default:{
            cout<<"invalid input\n";
            break;
        }
    }
}






