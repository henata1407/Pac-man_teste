#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <random>
#include <cstdlib>
#include <locale>
#include <stdio.h>
#include <math.h>
#include <string>

//srand(time(NULL));

using namespace std;

typedef struct
{
    int mf=0;//variavel para o sorteio do movimento do fantasminha
    int yf=13;//y onde o fantasma nasce
    int xf=24;//x onde o fantasma nasce
    char pp=' ';//variavel para armazenar o valor do mapa/pastilha
} f1;
typedef struct
{
    int mf=0;
    int yf=14;
    int xf=25;
    char pp=' ';
} f2;
typedef struct
{
    int mf=0;
    int yf=13;
    int xf=26;
    char pp=' ';
} f3;
typedef struct
{
    int mf=0;
    int yf=14;
    int xf=28;
    char pp=' ';
} f4;
typedef struct
{
    int mf=0;
    int yf=13;
    int xf=29;
    char pp=' ';
} f5;

typedef struct
{
    int px=10;//posicao pac man eixo x
    int py=14;//posicao pac man eixo y
    int cx=0;//posicao coliisao do pac man eixo x
    int cy=9;//posicao colisao pac man eixo y
    int vida=3;
} pacman;

typedef struct
{
    string nome;
    int pontuacaoUs;
} u;

typedef struct
{
    char m[19][33]= {{'z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z'},
        {'z','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','z'},
        {'z','P','°','°','_','°','°','°','°','°','°','°','°','°','°','|','°','°','|','°','°','°','°','°','°','°','°','°','-','°','°','P','z'},
        {'z','°','°','|','_','|','°','°','°','°','°','°','°','°','°','|','°','°','|','°','°','°','°','°','°','°','°','|','_','|','°','°','z'},
        {'z','°','°','°','°','°','°','°','°','_','_','_','_','°','°','|','°','°','|','°','_','_','_','_','°','°','°','°','°','°','°','°','z'},
        {'z','°','°','_','_','_','°','°','°','|','°','°','°','°','°','°','°','°','°','°','°','°','°','|','°','°','_','_','_','°','°','°','z'},
        {'z','°','°','°','°','°','°','°','°','|','°','°','°','_','_','_','°','°','_','_','_','°','°','|','°','°','°','°','°','°','°','°','z'},
        {'z','°','°','°','°','°','°','°','°','|','°','°','°','|','°','°','°','°','°','°','|','°','°','|','°','°','°','°','°','°','°','°','z'},
        {'z','z','z','z','°','°','°','°','°','|','°','°','°','|','X','°','X','°','°','X','|','°','°','|','°','°','°','°','°','z','z','z','z'},
        {'O','°','°','°','°','°','°','°','°','|','°','°','°','|','°','X','°','°','X','°','|','°','°','|','°','°','°','°','°','°','°','°','°'},
        {'z','z','z','z','°','°','°','°','°','|','°','°','°','|','_','_','_','_','_','_','|','°','°','|','°','°','°','°','°','z','z','z','z'},
        {'z','°','°','°','°','°','°','°','°','|','°','°','°','°','°','°','°','°','°','°','°','°','°','|','°','°','°','°','°','°','°','°','z'},
        {'z','°','°','_','_','_','°','°','°','|','_','_','°','°','°','°','°','°','°','°','°','_','_','|','°','°','_','_','_','°','°','°','z'},
        {'z','°','°','°','°','°','°','°','°','°','°','°','°','°','°','|','°','°','|','°','°','°','°','°','°','°','°','°','°','°','°','°','z'},
        {'z','°','°','°','°','°','°','°','°','°','°','|','°','°','°','|','°','°','|','°','°','°','°','°','|','°','°','°','°','°','°','°','z'},
        {'z','°','°','°','_','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','_','°','°','°','z'},
        {'z','P','°','|','_','|','°','°','_','_','_','_','_','_','_','_','°','°','°','_','_','_','_','_','_','°','°','|','_','|','°','P','z'},
        {'z','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','°','z'},
        {'z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z'}
    };
} mm;

f1 mf1;//movimentacao dos fantasminhas
f2 mf2;
f3 mf3;
f4 mf4;
f5 mf5;
pacman pac;
mm mp;
u usu;

//reiniciacao das variaveis

ofstream escreve;
ifstream le;

int fx1=mf1.xf;
int fy1=mf1.yf;
int fx2=mf2.xf;
int fy2=mf2.yf;
int fx3=mf3.xf;
int fy3=mf3.yf;
int fx4=mf4.xf;
int fy4=mf4.yf;
int fx5=mf5.xf;
int fy5=mf5.yf;

string n1;
string n2;
string n3;
string n4;
string n5;
int p1=0;
int p2=0;
int p3=0;
int p4=0;
int p5=0;

int s=4;
int sp=9;
int py=pac.py;
int px=pac.px;
int pcy=pac.cy;
int pcx=pac.cx;
int vida=pac.vida;
int x=10;//x do gotoxy para a impressao do mapa
int y=5;//y do gotoxy para a impressao do mapa
int pontuacao=0;
int us1=0;
int fase=1;

void gotoxy(int x, int y)
{
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}

void pausar()
{
    system("pause");
}

void espaco()
{
    cout<<endl;
}
void limpatela()
{
    system("cls");
}

void ft1()
{
    mf1.mf=(rand()%4)+1;

    if(mf1.mf==1)//movimentacao para cima
    {
        if(((mp.m[fy1-1][fx1]=='z')||(mp.m[fy1-1][fx1]=='|'))||(mp.m[fy1-1][fx1]=='_'))//colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1+1][fx1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            fy1++;
            mp.m[fy1][fx1]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';

        }//colisao
        else//sem colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1-1][fx1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            fy1--;
            mp.m[fy1][fx1]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';
        }//sem colisao

    }//movimentacao para cima
    else if(mf1.mf==2)//movimentacao para baixo
    {
        if(((mp.m[fy1+1][fx1]=='z')||(mp.m[fy1+1][fx1]=='|'))||(mp.m[fy1+1][fx1]=='_'))//colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1-1][fx1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            mp.m[fy1--][fx1]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1+1][fx1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            mp.m[fy1++][fx1]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';
        }//sem colisao
    }//movimentacao para baixo
    else if(mf1.mf==3)//movimentacao para a esquerda
    {
        if(((mp.m[fy1][fx1-1]=='z')||(mp.m[fy1][fx1-1]=='|'))||(mp.m[fy1][fx1-1]=='_'))//colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1][fx1+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            mp.m[fy1][fx1++]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1][fx1-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            mp.m[fy1][fx1--]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';
        }//sem colisao
    }//movimentacao para a esquerda
    else if(mf1.mf==4)//movimentacao para a direita
    {
        if(((mp.m[fy1][fx1+1]=='z')||(mp.m[fy1][fx1+1]=='|'))||(mp.m[fy1][fx1+1]=='_'))//colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1][fx1-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            mp.m[fy1][fx1--]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx1,fy1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy1][fx1-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy1][fx1];
            mp.m[fy1][fx1--]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx1,fy1);
            cout<<'X';

        }//sem colisao
    }//movimentacao para direita
}

void ft2()
{
    mf2.mf=(rand()%4)+1;

    if(mf2.mf==1)//movimentacao para cima
    {
        if(((mp.m[fy2-1][fx2]=='z')||(mp.m[fy2-1][fx2]=='|'))||(mp.m[fy2-1][fx2]=='_'))//colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2+1][fx2]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2++][fx2]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2-1][fx2]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2--][fx2]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//sem colisao
    }//movimentacao para cima
    else if(mf2.mf==2)//movimentacao para baixo
    {
        if(((mp.m[fy2+1][fx2]=='z')||(mp.m[fy2+1][fx2]=='|'))||(mp.m[fy2+1][fx2]=='_'))//colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2-1][fx2]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2--][fx2]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2+1][fx2]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2++][fx2]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//sem colisao
    }//movimentacao para baixo
    else if(mf2.mf==3)//movimentacao para esquerda
    {
        if(((mp.m[fy2][fx2-1]=='z')||(mp.m[fy2][fx2-1]=='|'))||(mp.m[fy2][fx2-1]=='_'))//colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2][fx2+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2][fx2++]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2][fx2-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2][fx2--]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//sem colisao
    }//moviemntacao para a esquerda
    else if(mf2.mf==4)//movimentacao para a direita
    {
        if(((mp.m[fy2][fx2+1]=='z')||(mp.m[fy2][fx2+1]=='|'))||(mp.m[fy2][fx2+1]=='_'))//colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2][fx2-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2][fx2--]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
        }//colisao
        else//sem colisao
        {
            gotoxy(fx2,fy2);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy2][fx2+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout<<mp.m[fy2][fx2];
            mp.m[fy2][fx2++]='X';
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(fx2,fy2);
            cout<<'X';
//                }
        }//sem colisao
    }//movimentacao para a direita
}//f2
void ft3()
{
    mf3.mf=(rand()%4)+1;

    if(mf3.mf==1)//movimentacao
    {
        if(((mp.m[fy3-1][fx3]=='z')||(mp.m[fy3-1][fx3]=='|'))||(mp.m[fy3-1][fx3]=='_'))
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3+1][fx3]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3++][fx3]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
        else
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3-1][fx3]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3--][fx3]='X';
            gotoxy(fx3,fy3);
            cout<<'X';

        }

    }
    else if(mf3.mf==2)
    {
        if(((mp.m[fy3+1][fx3]=='z')||(mp.m[fy3+1][fx3]=='|'))||(mp.m[fy3+1][fx3]=='_'))
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3-1][fx3]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3--][fx3]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
        else
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3+1][fx3]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3++][fx3]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
    }
    else if(mf3.mf==3)
    {
        if(((mp.m[fy3][fx3-1]=='z')||(mp.m[fy3][fx3-1]=='|'))||(mp.m[fy3][fx3-1]=='_'))
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3][fx3+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3][fx3++]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
        else
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3][fx3-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3][fx3--]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
    }
    else if(mf3.mf==4)
    {
        if(((mp.m[fy3][fx3+1]=='z')||(mp.m[fy3][fx3+1]=='|'))||(mp.m[fy3][fx3+1]=='_'))
        {
            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3][fx3-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3][fx3--]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
        else
        {

            gotoxy(fx3,fy3);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy3][fx3+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy3][fx3];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy3][fx3++]='X';
            gotoxy(fx3,fy3);
            cout<<'X';
        }
    }
}
void ft4()
{
    mf4.mf=(rand()%4)+1;

    if(mf4.mf==1)
    {
        if(((mp.m[fy4-1][fx4]=='z')||(mp.m[fy4-1][fx4]=='|'))||(mp.m[fy4-1][fx4]=='_'))
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4+1][fx4]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4++][fx4]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
        else
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4-1][fx4]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4--][fx4]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
    }

    else if(mf4.mf==2)
    {
        if(((mp.m[fy4+1][fx4]=='z')||(mp.m[fy4+1][fx4]=='|'))||(mp.m[fy4+1][fx4]=='_'))
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4-1][fx4]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4--][fx4]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
        else
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4+1][fx4]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4++][fx4]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
    }
    else if(mf4.mf==3)
    {
        if(((mp.m[fy4][fx4-1]=='z')||(mp.m[fy4][fx4-1]=='|'))||(mp.m[fy4][fx4-1]=='_'))
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4][fx4+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4][fx4++]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
        else
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4][fx4-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4][fx4--]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
    }

    else if(mf4.mf==4)
    {
        if(((mp.m[fy4][fx4+1]=='z')||(mp.m[fy4][fx4+1]=='|'))||(mp.m[fy4][fx4+1]=='_'))
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4][fx4-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4][fx4--]='X';
            gotoxy(fx4,fy4);
            cout<<'X';
        }
        else
        {
            gotoxy(fx4,fy4);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy4][fx4+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy4][fx4];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy4][fx4++]='X';
            gotoxy(fx4,fy4);
            cout<<'X';

        }
    }
}
void ft5()
{

    mf5.mf=(rand()%4)+1;

    if(mf5.mf==1)
    {
        if(((mp.m[fy5-1][fx5]=='z')||(mp.m[fy5-1][fx5]=='|'))||(mp.m[fy5-1][fx5]=='_'))
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5+1][fx5]=='°' ? mf5.pp='°' : mf5.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5++][fx5]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
        else
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5-1][fx5]=='°' ? mf5.pp='°' : mf5.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5--][fx5]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
    }

    else if(mf5.mf==2)
    {
        if(((mp.m[fy5+1][fx5]=='z')||(mp.m[fy5+1][fx5]=='|'))||(mp.m[fy5+1][fx5]=='_'))
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5-1][fx5]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5--][fx5]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
        else
        {

            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5+1][fx5]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5++][fx5]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
    }
    else if(mf5.mf==3)
    {
        if(((mp.m[fy5][fx5-1]=='z')||(mp.m[fy5][fx5-1]=='|'))||(mp.m[fy5][fx5-1]=='_'))
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5][fx5+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5][fx5++]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
        else
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5][fx5-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5][fx5--]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
    }
    else if(mf5.mf==4)
    {
        if(((mp.m[fy5][fx5+1]=='z')||(mp.m[fy5][fx5+1]=='|'))||(mp.m[fy5][fx5+1]=='_'))
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5][fx5-1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5][fx5--]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
        else
        {
            gotoxy(fx5,fy5);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            mp.m[fy1][fx1]=mf1.pp;
            mp.m[fy5][fx5+1]=='°' ? mf1.pp='°' : mf1.pp=' ';
            cout<<mp.m[fy5][fx5];
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            mp.m[fy5][fx5++]='X';
            gotoxy(fx5,fy5);
            cout<<'X';
        }
    }
}

void variaveis()
{
    escreve.open("save.txt");

    if(escreve.is_open())
    {
        escreve <<s<<endl<<sp<<endl<<pontuacao<<endl<<fx1<<endl<<fx2<<endl<<fx3<<endl<<fx4<<endl<<fx5<<endl<<fy1<<endl<<fy2<<endl<<fy3<<endl<<fy4<<endl<<fy5<<endl;
        escreve<<py<<endl<<px<<endl<<pcy<<endl<<pcx<<endl<<vida<<endl<<usu.pontuacaoUs<<endl<<fase<<endl;
        for(int i=0; i<19; i++)
        {
            for(int j=0; j<33 ; j++)
            {
                escreve<<mp.m[i][j]<<endl;
            }
        }
        for(int i=0; i<5 ; i++)
        {
            escreve<<usu.nome[i];
        }
        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo para escrita!";
        abort();
    }
}

void hall()
{
    le.open("hall.txt");
    if(le.is_open())
    {
        while(!le.eof())
        {
            le>>n1>>p1>>n2>>p2>>n3>>p3>>n4>>p4>>n5>>p5;
        }
        le.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo para leitura!";
        abort();
    }
    escreve.open("hall.txt");

    if(escreve.is_open())
    {
        if(usu.pontuacaoUs >p1)
        {
            p5=p4;
            n5=n4;
            p4=p3;
            n4=n3;
            p3=p2;
            n3=n2;
            p2=p1;
            n2=n1;
            p1=usu.pontuacaoUs;
            n1=usu.nome;
        }
        else if(usu.pontuacaoUs>p2)
        {
            p5=p4;
            n5=n4;
            p4=p3;
            n4=n3;
            p3=p2;
            n3=n2;
            p2=usu.pontuacaoUs;
            n2=usu.nome;
        }
        else if(usu.pontuacaoUs>p3)
        {
            p5=p4;
            n5=n4;
            p4=p3;
            n4=n3;
            p3=usu.pontuacaoUs;
            n3=usu.nome;
        }
        else if(usu.pontuacaoUs>p4)
        {
            p5=p4;
            n5=n4;
            p4=usu.pontuacaoUs;
            n4=usu.nome;
        }
        else if(usu.pontuacaoUs>p5)
        {
            p5=usu.pontuacaoUs;
            n5=usu.nome;
        }

        escreve<<p1<<endl<<n1<<endl<<p2<<endl<<n2<<endl<<p3<<endl<<n3<<endl<<p4<<endl<<n4<<endl<<p5<<endl<<n5;

        escreve.close();
    }
    else
    {
        cout << "Falha ao abrir o arquivo para escrita!";
        abort();
    }
}
