#include <iostream>
#include<conio.h>
#include<stdio.h>
#include"Stack.h"
using namespace std;
Stack S,T,D;
void printAll();
void towerOfHon();
int disks,element, result;
char choice, input;
int main()
{
    cout << "\t" << "\t" << "\t" << "\t" << "\t" << "\t" << "TOWER OF HONOI" << endl;
    cout << "What are the number of disks? : "; cin >> disks; 
    
    while(true)
        towerOfHon();
    

    return 0;
}
void printAll() {
    cout << "Stack S: "; S.print(); cout << endl;
    cout << "Stack T: "; T.print(); cout << endl;
    cout << "Stack D: "; D.print(); cout << endl;
    cout << endl;
}
void towerOfHon() {
    for (int i = disks; i > 0; i--)                                             //pushing the disks in decending order 3,2,1
        S.push(i);
    while (true) {
        if (D.checkIfWon(disks)) {                                                 //if destination stack equals no of disks user won
            cout << "CONGRATULATIONS YOU WON." << endl;
            for (int i = disks; i > 0; i--)
                D.pop(&result);
            disks++;
            cout << endl << "Level UP - " << disks << endl;;
            break;
        }
        cout << "press 0 to exit." << endl;
        cout << "press 1 to view all stack." << endl;
        cout << "select a source stack to shift from (S, T, D) : "; cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {
        case'0': exit(0);
        case'1': printAll();
            break;
        case'S':
            cout << "select a destination Stack: (T, D) "; cin >> input;
            input = toupper(input);
            if (input == 'S')
                cout << "sourse and destination cannot be same:" << endl << endl;
            else if (input == 'T') {
                if ((T.isEmpty())) {
                    S.pop(&element);
                    T.push(element);
                    cout << "Disk is successfully shifted." << endl << endl;
                }
                else {
                    if (T.peek() > S.peek()) {                                        //destination peek > source peek
                        S.pop(&element);
                        T.push(element);
                        cout << "Disk is successfully shifted." << endl << endl;
                    }
                    else
                        cout << "cannot shift this disk." << endl << endl;
                }
            }
            else if (input == 'D') {
                if (D.isEmpty()) {
                    S.pop(&element);
                    D.push(element);
                    cout << "Disk is successfully shifted." << endl << endl;
                }
                else {
                    if (D.peek() > S.peek()) {
                        S.pop(&element);
                        D.push(element);
                        cout << "Disk is successfully shifted." << endl << endl;
                    }

                    else
                        cout << "You cannot shift larger disk over small." << endl;

                }
            }
            else
                cout << "Invalid Entry." << endl << endl;
            break;
        case'T':
            if (!T.isEmpty()) {
                cout << "select a destination Stack: (S, D) "; cin >> input;
                input = toupper(input);
                if (input == 'T')
                    cout << "source and destination cannot be same." << endl << endl;
                else if (input == 'S') {
                    if (S.isEmpty()) {
                        T.pop(&element);
                        S.push(element);
                        cout << "Disk is successfully shifted." << endl << endl;
                    }
                    else {
                        if (S.peek() > T.peek()) {
                            T.pop(&element);
                            S.push(element);
                            cout << "Disk is successfully shifted." << endl << endl;
                        }
                        else
                            cout << "You cannot shift larger disk over small." << endl;
                    }
                }
                else if (input == 'D') {
                    if (D.isEmpty()) {
                        T.pop(&element);
                        D.push(element);
                        cout << "Disk is successfully shifted." << endl << endl;
                    }
                    else {
                        if (D.peek() > T.peek()) {
                            T.pop(&element);
                            D.push(element);
                            cout << "Disk is successfully shifted." << endl << endl;
                        }
                        else
                            cout << "You cannot shift larger disk over small." << endl;


                    }
                }
                else
                    cout << "Invalid Entry" << endl << endl;
                break;
            }
            else cout << "You cannot shift disk from empty stack" << endl << endl;
        case'D':
            if (!D.isEmpty()) {
                cout << "select a destination Stack (S, T) : "; cin >> input;
                input = toupper(input);
                if (input == 'D')
                    cout << "source and destination cannot be same." << endl << endl;
                else if (input == 'S') {
                    if (S.isEmpty()) {
                        D.pop(&element);
                        S.push(element);
                        cout << "Disk is successfully shifted." << endl << endl;
                    }
                    else {
                        if (S.peek() > D.peek()) {
                            D.pop(&element);
                            S.push(element);
                            cout << "Disk is successfully shifted." << endl << endl;
                        }
                        else
                            cout << "You cannot shift larger disk over small." << endl;
                    }

                }
                else if (input == 'T') {
                    if (T.isEmpty()) {
                        D.pop(&element);
                        T.push(element);
                        cout << "Disk is successfully shifted." << endl << endl;
                    }
                    else {
                        if (T.peek() > D.peek()) {
                            D.pop(&element);
                            T.push(element);
                            cout << "Disk is successfully shifted." << endl << endl;
                        }
                        else
                            cout << "You cannot shift larger disk over small." << endl;
                    }
                }
                else
                    cout << "Invalid Entry" << endl << endl;
                break;
            }
            else cout << "You cannot shift Disk from empty Stack "<<endl;
        default:
            cout << "invalid Entry." << endl << endl;
            break;
        }


    }
}



