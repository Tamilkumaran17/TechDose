#include <bits/stdc++.h>
using namespace std;

#define n 5

int arr[n];
int top = 0;

void push(int data) {
    if (top == n)
        cout << "OVERFLOW\n";
    else {
        arr[top] = data;
        top++;
        cout << "Element " << data << " pushed" << endl;
    }
}

int pop() {
    if (top == 0) {
        cout << "UNDERFLOW" << endl;
        return -1; 
    } else {
        
        int topval = arr[top]; 
        top--; 
        return topval;
    }
}

int peak() {
    if (top == 0) {
        cout << "UNDERFLOW" << endl;
        return -1; 
    } else {
        return arr[top - 1]; 
    }
}

void display() {
    if (top == 0) {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = top - 1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int op;
    while(op) {
        cout << "\nEnter the number to perform the operations \n 1--> push \n 2--> pop \n 3--> peak \n 4--> display \n 5--> exit \n Enter the option: ";
        cin >> op;

        switch (op) {
            case 1: {
                int data;
                cout << "Enter the data to push: ";
                cin >> data;
                push(data);
                break;
            }
            case 2: {
                int popped = pop();
                if (popped != -1)
                    cout << "The popped element is: " << popped << endl;
                break;
            }
            case 3: {
                int topElem = peak();
                if (topElem != -1)
                    cout << "The top element is: " << topElem << endl;
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid option. Try again.\n";
            }
        }
    } 

    return 0;
}
