#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y){
    COORD point;
    point.X = x;
    point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}


int main(){

int x=10;
int y=3;
int pontuacao=0;
char us=' ';
int px=0;
int py=9;
int cx=0;
int cy=9;
char mp[19][33]={{'z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z'},
                {'z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','z'},
                {'z','�','�','�','_','�','�','�','�','�','�','�','�','�','�','|','�','�','|','�','�','�','�','�','�','�','�','�','-','�','�','�','z'},
                {'z','�','�','|','_','|','�','�','�','�','�','�','�','�','�','|','�','�','|','�','�','�','�','�','�','�','�','|','_','|','�','�','z'},
                {'z','�','�','�','�','�','�','�','�','_','_','_','_','�','�','|','�','�','|','�','_','_','_','_','�','�','�','�','�','�','�','�','z'},
                {'z','�','�','_','_','_','�','�','�','|','�','�','�','�','�','�','�','�','�','�','�','�','�','|','�','�','_','_','_','�','�','�','z'},
                {'z','�','�','�','�','�','�','�','�','|','�','�','�','_','_','_','�','�','_','_','_','�','�','|','�','�','�','�','�','�','�','�','z'},
                {'z','�','�','�','�','�','�','�','�','|','�','�','�','|','�','�','�','�','�','�','|','�','�','|','�','�','�','�','�','�','�','�','z'},
                {'z','z','z','z','�','�','�','�','�','|','�','�','�','|','�','�','�','�','�','�','|','�','�','|','�','�','�','�','�','z','z','z','z'},
                {'O','�','�','�','�','�','�','�','�','|','�','�','�','|','�','�','�','�','�','�','|','�','�','|','�','�','�','�','�','�','�','�','�'},
                {'z','z','z','z','�','�','�','�','�','|','�','�','�','|','_','_','_','_','_','_','|','�','�','|','�','�','�','�','�','z','z','z','z'},
                {'z','�','�','�','�','�','�','�','�','|','�','�','�','�','�','�','�','�','�','�','�','�','�','|','�','�','�','�','�','�','�','�','z'},
                {'z','�','�','_','_','_','�','�','�','|','_','_','�','�','�','�','�','�','�','�','�','_','_','|','�','�','_','_','_','�','�','�','z'},
                {'z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','|','�','�','|','�','�','�','�','�','�','�','�','�','�','�','�','�','z'},
                {'z','�','�','�','�','�','�','�','�','�','�','|','�','�','�','|','�','�','|','�','�','�','�','�','|','�','�','�','�','�','�','�','z'},
                {'z','�','�','�','_','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','_','�','�','�','z'},
                {'z','�','�','|','_','|','�','�','_','_','_','_','_','_','_','_','�','�','�','_','_','_','_','_','_','�','�','|','_','|','�','�','z'},
                {'z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','z'},
                {'z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z'}};


do{
    for(int i=0;i<19;i++){

            gotoxy(x,y);

            for(int j=0;j<33;j++){
            cout<<mp[i][j];
            }
        y++;
        cout<<endl;
        }

    cin>>us;

   // getch(us);-> ver se o getch pode ser usado com char

    if(((us=='w')||(us=='W'))||(us=='1')){
            cy--;

        if(((mp[cy][cx]=='z')||(mp[cy][cx]=='|'))||(mp[cy][cx]=='_')){
            cout<<system("color c4")<<"opcao invalida"<<endl;
            Sleep(600);
            system("color 07");
            cout<<"continue o jogo"<<endl;
            cin>>us;
            cy++;

        }else{
            mp[py][px]=' ';
            py--;
            mp[py][px]='O';
            pontuacao++;
        }

    }else if(((us=='d')||(us=='D'))||(us=='2')){
        cx++;

        if(((mp[cy][cx]=='z')||(mp[cy][cx]=='|'))||(mp[cy][cx]=='_')){
            cout<<system("color c4")<<"opcao invalida"<<endl;
            Sleep(600);
            system("color 07");
            cout<<"continue o jogo"<<endl;
            cin>>us;
            cx--;

        }else{
        mp[py][px]=' ';
        px++;
        mp[py][px]='O';
        pontuacao++;
        }

    }else if(((us=='s')||(us=='S'))||(us=='3')){
        cy++;

        if(((mp[cy][cx]=='z')||(mp[cy][cx]=='|'))||(mp[cy][cx]=='_')){
            cout<<system("color c4")<<"opcao invalida"<<endl;
            Sleep(600);
            system("color 07");
            cout<<"continue o jogo"<<endl;
            cin>>us;
            cy--;

        }else{
        mp[py][px]=' ';
        py++;
        mp[py][px]='O';
        pontuacao++;
        }

    }else if(((us=='a')||(us=='A'))||(us=='4')){
        cx--;

        if(((mp[cy][cx]=='z')||(mp[cy][cx]=='|'))||(mp[cy][cx]=='_')){
            cout<<system("system c4")<<"opcao invalida"<<endl;
            Sleep(600);
            system("color 07");
            cout<<"continue o jogo"<<endl;
            cin>>us;
            cx++;

        }else{
      mp[py][px]=' ';
      px--;
      mp[py][px]='O';
      pontuacao++;
        }

    }else{
        cout<<"opcao invalida";
    }

    cout<<"pontucao: "<<pontuacao<<endl;

    Sleep(150);
    system("cls");

}while(pontuacao<411);

return 0;
}
