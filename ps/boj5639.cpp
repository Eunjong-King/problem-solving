#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node{
    struct node* left;
    struct node* right;
    int value;
} Node;

Node* realHead;

void back(Node* now){
    if((*now).left != nullptr){
        back((*now).left);
    }
    if((*now).right != nullptr){
        back((*now).right);
    }
    printf("%d\n", (*now).value);

    delete now;
}

int main(void){
    int inp;
    scanf("%d", &inp);
    realHead = new Node{nullptr, nullptr, inp};

    while(cin >> inp){
        Node* temp = new Node{nullptr, nullptr, inp};
        Node* head = realHead;
        while(true){
            if((*head).value > inp){
                if((*head).left != nullptr){
                    head = (*head).left;
                }
                else{
                    (*head).left = temp;
                    break;
                }
            }
            else{
                if((*head).right != nullptr){
                    head = (*head).right;
                }
                else{
                    (*head).right = temp;
                    break;
                }
            }
        }
    }

    back(realHead);

    return 0;
}