#include <bits/stdc++.h>
using namespace std;

struct liczba
{
    int wartosc;
    liczba *next;
};

int init(liczba **root)
{
    int x, ile=rand()%10+1;
    for(int i=1; i<=ile; i++)
    {
        x=rand()%100+1;
        liczba *nowa=new liczba;
        nowa->wartosc = x;
        nowa->next=*root;
        *root=nowa;
    }
    return ile;
}

void push (liczba **root, int a)
{
    liczba *nowa=new liczba;
    nowa->wartosc=a;
    nowa->next=*root;
    *root=nowa;
}

void pop (liczba **root)
{
        liczba *temp=*root;
        *root=(*root)->next;
        delete temp;
}

bool isEmpty (liczba **root)
{
   if (*root) return false;
   else return true;
}

bool full (liczba **root)
{
    return false;
}

int top (liczba **root)
{
    if(*root) {
        liczba *temp=*root;
        return temp->wartosc;
    }
    else return INT_MAX;
}

int destroy(liczba **root)
{
    while(*root)
    {
        liczba *temp=*root;
        cout<<temp->wartosc<<endl;
        *root=(*root)->next;
        delete temp;
    }
}

void koniec(liczba **root)
{
    exit(0);
}

int main()
{
    char warunek; int x;
    liczba *root=NULL, *nowa = NULL;
    srand(time(NULL));

    cout<<"Stworzono stos o rozmiarze: "<<init(&root)<<endl;

    cout<<"Co chcesz teraz zrobic?\n";
    cout << "A. push\n";
    cout << "B. pop\n";
    cout << "C. top\n";
    cout << "D. isEmpty\n";
    cout << "E. full\n";
    cout << "F. destroy\n";
    cout << "0. Wyjscie\n";



    while (cin>>warunek)
    {
        switch (warunek)
        {
            case 'A':
            {
                cout<<"Podaj liczbe, ktora chcialbys polozyc na stosie: ";
                cin>>x;
                push(&root, x);
            }
            break;
            case 'B':
            {
                if(!isEmpty(&root))
                {
                    cout<<"Usuwam wierzcholek stosu - liczbe ";
                    cout<<top(&root)<<endl;
                    pop(&root);
                }
                else cout<<"Nie ma zadnej liczby na stosie, wiec nie moge nic usunac\n";
            }
            break;
            case 'C':
            {
                if(top(&root)==INT_MAX) cout<<"Nie ma zadnej liczby na stosie\n";
                else cout<<top(&root)<<endl;
            }
            break;
            case 'D':
            {
                if(isEmpty(&root)) cout<<"Stos jest pusty\n";
                else cout<<"Stos nie jest pusty\n";
            }
            break;
            case 'E':
            {
                if(full(&root)) cout<<"Stos jest pelny\n";
                else cout<<"Stos nie jest pelny\n";
            }
            break;
            case 'F':
            {
                if(!isEmpty(&root))
                {
                    cout<<"Niszcze stos. Oto jego elementy:\n";
                    destroy(&root);
                }
                else cout<<"Nie ma zadnej liczby na stosie, wiec nie moge po nim posprzatac\n";
            }
            break;
            case '0':
            {
                cout<<"Koniec programu!\nDziekuje za skorzystanie z mojego stosu i zapraszam ponownie";
                koniec(&root);
            }
            break;
            default:
                cout<<"Nie ma takiej opcji. Wybierz inna\n";
        }
    }
}
