#include "3bim.h"

int main()
{
    int c=22;
    char us=' ';//a tecla que o usuario entra
    int colisao,pastilha,movimentacao;
    int inicio;

    gotoxy(35,1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<" pac man "<<endl<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<" digite seu nome:  ";
    cin>>usu.nome;
    limpatela();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<endl<<endl<<" para jogar digite 1 \n Para salvar seu jogo digite 2 \n Para continuar jogando digite 3 \n Para ver o hall da fama digite 4"<<endl<<endl;
    cin>>us1;
    limpatela();

    switch(us1)
    {

    case 1:

        for(int i=0; i<19; i++)//impressao do mapa
        {
            gotoxy(x,y);

            for(int j=0; j<33; j++)
            {
                if(mp.m[i][j]=='°') //da pra fazer com switch case
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    cout<<mp.m[i][j];
                }
                else if(((mp.m[i][j]=='z')||(mp.m[i][j]=='|'))||(mp.m[i][j]=='_'))
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
                    cout<<mp.m[i][j];
                }
                else if(mp.m[i][j]=='O')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout<<mp.m[i][j];
                }
                else if(mp.m[i][j]=='X')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                    cout<<mp.m[i][j];
                }
                else if(mp.m[i][j]=='P')
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout<<mp.m[i][j];
                }
            }
            y++;
            cout<<endl;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        gotoxy(0,25);
        cout<<"pontucao: "<<endl<<"vidas: "<<endl<<"fase: ";

        inicio=time(NULL);

        do
        {
            gotoxy(11,25);
            cout<<usu.pontuacaoUs;
            gotoxy(7,26);
            cout<<vida;
            gotoxy(6,27);
            cout<<fase;

            us=getch();//entrada da tecla do usuario

            if(vida>0)
            {

                if(((us=='w')||(us=='W'))||(us=='1'))//movimentacao para cima
                {
                    pcy--;//colisao do pacman

                    if(((mp.m[pcy][pcx]=='z')||(mp.m[pcy][pcx]=='|'))||(mp.m[pcy][pcx]=='_'))//verificacao de colisao
                    {
                        cout<<"colisaooo";
                        //us=getch();
                        pcy++;
                    }
                    else if(mp.m[pcy][pcx]=='P')//verificacao de colisao com uma pastilha magica
                    {
                        cout<<"pastilhaaaa";
                        pastilha=time(NULL);//pastilha recebe tempo em que o pac comeu a pastilha

                        gotoxy(px,py);
                        mp.m[py][px]=' ';
                        cout<<mp.m[py][px];
                        py--;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                        gotoxy(px,py);
                        mp.m[py][px]='O';
                        cout<<mp.m[py][px];
                        pontuacao++;
                        usu.pontuacaoUs++;

                    }
                    else if(mp.m[py][px]=='X')
                    {
                        cout<<"fantat";
                        colisao=time(NULL);//recebe o tempo em que o pac colidiu com o fantasma

                        if((colisao-pastilha)<9) //temporizador
                        {
                            cout<<"tununu morre";
                            pontuacao++;
                            usu.pontuacaoUs++;
                            // reiniciacao da variavel para o fantasminha que morreu
                            if(mp.m[py][px]==mp.m[fy1][fx1])
                            {
                                mp.m[fy1][fx1]=' ';
                                fx1=mf1.xf;
                                fy1=mf1.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy2][fx2])
                            {
                                mp.m[fy2][fx2]=' ';
                                fx2=mf2.xf;
                                fy2=mf2.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy3][fx3])
                            {
                                mp.m[fy3][fx3]=' ';
                                fx3=mf3.xf;
                                fy3=mf3.yf;
                            }
                            else if (mp.m[py][px]==mp.m[fy4][fx4])
                            {
                                mp.m[fy4][fx4]=' ';
                                fx4=mf4.xf;
                                fy4=mf4.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy5][fx5])
                            {
                                mp.m[fy5][fx5]=' ';
                                fx5=mf5.xf;
                                fy5=mf5.yf;
                            }
                        }//fecha chaves do temporizador
                        else//caso o efeito da pastilha ja tenha passado
                        {
                            cout<<"perdeu";
                            vida--;
                            gotoxy(px,py);
                            cout<<' ';
                            py=pac.py;
                            px=pac.px;
                            pcy=pac.cy;
                            pcx=pac.cx;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            gotoxy(px,py);
                            cout<<'O';

                        }//fecha chaves do else
                    }//fecha chaves do verificador de colisao com o fantasminha
                    else if(us=='p')
                    {
                        cout<<"pausou";
                        us1=2;
                    }
                    else//movimentacao padrao do pacman
                    {
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        py--;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;
                    }//fecha chaves da movimentacao padrao

                }//fecha chaves da movimentacao para cima
                else if(((us=='d')||(us=='D'))||(us=='4'))//movimentacao para o lado direito
                {

                    pcx++;//colisao do pacman

                    if(((mp.m[pcy][pcx]=='z')||(mp.m[pcy][pcx]=='|'))||(mp.m[pcy][pcx]=='_'))//verificacao de colisao
                    {

                        //us=getch();
                        pcx--;

                    }//fecha chaves verificacao de colisao
                    else if(mp.m[pcy][pcx]=='P')//colisao do pac com a pastilha
                    {
                        pastilha=time(NULL);//pastilha recebe tempo em que o pac comeu a pastilha

                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        py--;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;

                    }//fecha chaves colisao da pastilha
                    else if(mp.m[py][px]=='X')//colisao com o fantasma
                    {
                        colisao=time(NULL);//recebe o tempo em que o pac colidiu com o fantasma
                        usu.pontuacaoUs++;

                        if((colisao-pastilha)<9) //temporizador
                        {
                            pontuacao++;
                            usu.pontuacaoUs++;

                            // reiniciacao da variavel para o fantasminha que morreu
                            if(mp.m[py][px]==mp.m[fy1][fx1])
                            {
                                mp.m[fy1][fx1]=' ';
                                fx1=mf1.xf;
                                fy1=mf1.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy2][fx2])
                            {
                                mp.m[fy2][fx2]=' ';
                                fx2=mf2.xf;
                                fy2=mf2.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy3][fx3])
                            {
                                mp.m[fy3][fx3]=' ';
                                fx3=mf3.xf;
                                fy3=mf3.yf;
                            }
                            else if (mp.m[py][px]==mp.m[fy4][fx4])
                            {
                                mp.m[fy4][fx4]=' ';
                                fx4=mf4.xf;
                                fy4=mf4.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy5][fx5])
                            {
                                mp.m[fy5][fx5]=' ';
                                fx5=mf5.xf;
                                fy5=mf5.yf;
                            }
                        }//fecha chaves do temporizador
                        else//caso o efeito da pastilha tenha acabado
                        {
                            vida--;
                            gotoxy(px,py);
                            cout<<' ';
                            py=pac.py;
                            px=pac.px;
                            pcy=pac.cy;
                            pcx=pac.cx;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            gotoxy(px,py);
                            cout<<'O';
                        }//fecha chaves do else
                    }//fecha chaves da colisao com o fantasma
                    else if(us=='p')
                    {
                        us1=2;
                    }
                    else//movimentacao padrao do pacman
                    {
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        px++;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;
                    }//fecha chaves da movimentacao padrao do pacman

                }//fecha chaves do movimento para a direita
                else if(((us=='s')||(us=='S'))||(us=='2'))//movimentacao para baixo
                {
                    pcy++;//colisao do pacman

                    if(((mp.m[pcy][pcx]=='z')||(mp.m[pcy][pcx]=='|'))||(mp.m[pcy][pcx]=='_'))//verificacao de colisao
                    {

                        //us=getch();
                        pcy--;

                    }//fecha chaves da verificacao de colisao
                    else if(mp.m[pcy][pcx]=='P')//colisao com pastilha
                    {
                        pastilha=time(NULL);
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        py--;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;

                    }//fecha chaves colisao com pastilha
                    else if(mp.m[py][px]=='X')//colisao com fantasma
                    {
                        colisao=time(NULL);
                        if((colisao-pastilha)<9) //temporizador
                        {
                            pontuacao++;
                            usu.pontuacaoUs++;
                            if(mp.m[py][px]==mp.m[fy1][fx1])
                            {
                                mp.m[fy1][fx1]=' ';
                                fx1=mf1.xf;
                                fy1=mf1.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy2][fx2])
                            {
                                mp.m[fy2][fx2]=' ';
                                fx2=mf2.xf;
                                fy2=mf2.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy3][fx3])
                            {
                                mp.m[fy3][fx3]=' ';
                                fx3=mf3.xf;
                                fy3=mf3.yf;
                            }
                            else if (mp.m[py][px]==mp.m[fy4][fx4])
                            {
                                mp.m[fy4][fx4]=' ';
                                fx4=mf4.xf;
                                fy4=mf4.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy5][fx5])
                            {
                                mp.m[fy5][fx5]=' ';
                                fx5=mf5.xf;
                                fy5=mf5.yf;
                            }
                        }//fecha chaves do temporizador
                        else//cado o efeito da pastilha temnha acabado
                        {
                            vida--;
                            gotoxy(px,py);
                            cout<<' ';
                            py=pac.py;
                            px=pac.px;
                            pcy=pac.cy;
                            pcx=pac.cx;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            gotoxy(px,py);
                            cout<<'O';
                        }//efeito da pastilha
                    }//colisao com o fantasma
                    else if(us=='p')
                    {
                        us1=2;
                    }
                    else//movimentacao padrao
                    {
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        py++;
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;
                    }//movimentacao padrao

                }//movimento para baixo
                else if(((us=='a')||(us=='A'))||(us=='3'))//movimento para esquerda
                {
                    pcx--;//colisao do pacman

                    if(((mp.m[pcy][pcx]=='z')||(mp.m[pcy][pcx]=='|'))||(mp.m[pcy][pcx]=='_'))//colisao
                    {
                        //us=getch();
                        pcx++;

                    }//colisao
                    else if(mp.m[pcy][pcx]=='P')//pastilha magica
                    {
                        pastilha=time(NULL);
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        py--;
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;

                    }//pastilha magica
                    else if(mp.m[py][px]=='X')//colisao fantasminha
                    {
                        colisao=time(NULL);

                        if((colisao-pastilha)<sp) //temporizador
                        {
                            pontuacao++;
                            usu.pontuacaoUs++;

                            if(mp.m[py][px]==mp.m[fy1][fx1])
                            {
                                mp.m[fy1][fx1]=' ';
                                fx1=mf1.xf;
                                fy1=mf1.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy2][fx2])
                            {
                                mp.m[fy2][fx2]=' ';
                                fx2=mf2.xf;
                                fy2=mf2.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy3][fx3])
                            {
                                mp.m[fy3][fx3]=' ';
                                fx3=mf3.xf;
                                fy3=mf3.yf;
                            }
                            else if (mp.m[py][px]==mp.m[fy4][fx4])
                            {
                                mp.m[fy4][fx4]=' ';
                                fx4=mf4.xf;
                                fy4=mf4.yf;
                            }
                            else if(mp.m[py][px]==mp.m[fy5][fx5])
                            {
                                mp.m[fy5][fx5]=' ';
                                fx5=mf5.xf;
                                fy5=mf5.yf;
                            }
                        }//temporizador
                        else//efeito pastilha
                        {
                            vida--;
                            gotoxy(px,py);
                            cout<<' ';
                            py=pac.py;
                            px=pac.px;
                            pcy=pac.cy;
                            pcx=pac.cx;
                            gotoxy(px,py);
                            cout<<'O';
                        }//efeito pastilha
                    }//colisao fantasminha
                    else if(us=='p')
                    {
                        us1=2;
                    }
                    else//movimetacao padrao
                    {
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]=' ');
                        px--;
                        gotoxy(px,py);
                        cout<<(mp.m[py][px]='O');
                        pontuacao++;
                        usu.pontuacaoUs++;
                    }//movimetacao padrao

                }
                else
                {
                    cout<<"opcao invalida"<<endl;
                    pausar();
                    gotoxy(0,26);
                    cout<<"                                              "<<endl;
                    //us=getch();
                }

                if((time(NULL)- inicio)>s)//movimento dos fantasmas
                {
                    ft1();//fucao do movimento dos fantasmas->funcao esta na biblioteca
                    ft2();
                    ft3();
                    ft4();
                    ft5();
                    inicio=time(NULL);
                }
            }

        }
        while(pontuacao<402);

        pontuacao=0;
        fase++;
        s--;
        sp--;
        break;

    case 2:
        variaveis();
        hall();
        cout<<"seu jogo foi salvo"<<endl;
        return 0;

        break;
    case 3:
        le.open("save.txt");
        if(le.is_open())
        {
            while(!le.eof())
            {
                le >>s>>sp>>pontuacao>>fx1>>fx2>>fx3>>fx4>>fx5>>fy1>>fy2>>fy3>>fy4>>fy5>>py>>px>>pcy>>pcx>>vida>>usu.pontuacaoUs>>fase;
                for(int i=0; i<19; i++)
                {
                    for(int j=0; j<33 ; j++)
                    {
                        le>>mp.m[i][j];
                    }
                }

                for(int i=0; i<5 ; i++)
                {
                    le>>usu.nome[i];
                }
            }
            le.close();
            us1=1;
            cout<<us1;
        }
        else
        {
            cout << "Falha ao abrir o arquivo para leitura!";
            abort();
        }

        break;

    case 4:
        gotoxy(35,1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout<<" Hall da Fama "<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        le.open("hall.txt");
        if(le.is_open())
        {
            while(!le.eof())
            {
                le>>n1>>p1>>n2>>p2>>n3>>p3>>n4>>p4>>n5>>p5;
                cout<<n1<<'-'<<p1<<endl<<n2<<'-'<<p2<<endl<<n3<<'-'<<p3<<endl<<n4<<'-'<<p4<<endl<<n5<<'-'<<p5<<endl;
            }
            le.close();
        }
        else
        {
            cout << "Falha ao abrir o arquivo para leitura!";
            abort();
        }
        break;

    default:
        cout<<"opcao invalda"<<endl;
        cin>>us1;
        break;

    }
    return 0;
}
