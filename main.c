#include <stdio.h>
#include <graphics.h>


void DrawStart();       //малює заставку гри
void menu();            //викликає меню гри
void point(int choice); //змінює колір курсорів на пункти меню
void PointChoice(int choice, int flag, int flagAfter); //змінює колір курсорів під час самої гри
void Game();            //головна функція гри
void instruction();      //виводить на екран правила гри
void exchange(int, int); //функція для зміни розташування кілець на башнях
void counter(int);       //функція для підрахунку та виводу на екран кількості зроблених ходів

struct Pointer{       //координаты переключателей в меню
    int pointer1[10];
    int pointer2[10];
    int pointer3[10];
}pointer = {{90,95,100,85,110,95,100,105,90,95},{90,175,100,165,110,175,100,185,90,175},{90,255,100,245,110,255,100,265,90,255}};

struct drawTower{     //координаты столбов башен
    int tower1[10];
    int tower2[10];
    int tower3[10];
}tower = {{135,95, 150,95, 150,325, 135,325, 135,95},{315,95, 330,95, 330,325, 315,325, 315,95},{495,95, 510,95, 510,325, 495,325, 349,95}};

struct BackGroundForTowers{
    int backGr1[10];
    int backGr2[10];
    int backGr3[10];
}backGround = {{0,70, 230,70, 230,340, 0,340, 0,70},{240,70, 420,70, 420,340, 240,340, 240,70},{430,70, 600,70, 600,340, 430,340, 430,70}};

struct Button{       //координаты переключателей в игре
    int button1[10];
    int button2[10];
    int button3[10];
}button = {{143,360, 173,390, 143,420, 113,390, 143,360},{143+180,360, 173+180,390, 143+180,420, 113+180,390, 143+180,360},{143+360,360, 173+360,390, 143+360,420, 113+360,390, 143+360,360}};

struct BAKHNA{       //последовательность и вес колец башен
    int rings1[8];
    int rings2[8];
    int rings3[8];
}bakhna = {{},{},{}};

struct Arr{          //координаты центров колец башен
    int arr1[9];
    int arr2[9];
    int arr3[9];
    int radius[8];
}arr = {{0,0,0,0,0,0,0,0,143}, {0,0,0,0,0,0,0,0,322},{0,0,0,0,0,0,0,0,502}, {0,0,0,0,0,0,0,0}};

int win[10] = {80,80, 560,80, 560,200, 80,200, 80,80};

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    char key;
    int choice = 0;
    //фон
    DrawStart();
    getch();
    clearviewport();
    do{
        setlinestyle(0,2,1);
        line(15,15,610,15);
        line(610,15,610,465);
        menu();
        key=getch();
        switch(key){
            case 'P':{
                choice++;
                if (choice == 3) choice = 0;
                point(choice);
                break;
            }
            case 'H':{
                choice--;
                if (choice == -1) choice = 2;
                point(choice);
                break;
            }
            case 13:{
                if (choice == 0){
                    clearviewport();
                    Game();
                    clearviewport();
                }
                else if(choice == 1){
                    clearviewport();
                    instruction();
                    clearviewport();
                }
                else if (choice == 2){
                    key = 27;
                }
            }
        }
    }while(key!=27);


    closegraph();
    return 0;
}

void point(int choice){
    if (choice == 0){
        setfillstyle(1,WHITE);
        fillpoly(4,pointer.pointer1);
        setfillstyle(1,RED);
        fillpoly(4,pointer.pointer2);
        fillpoly(4,pointer.pointer3);
    }
    else if(choice == 1){
        setfillstyle(1,WHITE);
        fillpoly(4,pointer.pointer2);
        setfillstyle(1,RED);
        fillpoly(4,pointer.pointer1);
        fillpoly(4,pointer.pointer3);
    }
    else if(choice == 2){
        setfillstyle(1,WHITE);
        fillpoly(4,pointer.pointer3);
        setfillstyle(1,RED);
        fillpoly(4,pointer.pointer2);
        fillpoly(4,pointer.pointer1);
    }
}


void DrawStart(){
    setfillstyle(1,4);
    bar(0,0,640,480);
    setcolor(YELLOW);
    setbkcolor(4);
    outtextxy(400,10,"made by Trofimtsov Dmytro");
    settextstyle(6,0,5);
    outtextxy(165,100,"WELCOME");
    outtextxy(230,150,"to game");
    settextstyle(10,0,4);
    outtextxy(180,220,"\"Tower of Hanoi\"");
}

void menu(){
    outtextxy(120,80, "start");
    outtextxy(120,160, "how to play");
    outtextxy(120,240,"exit");
}

void PointChoice(int choice, int flag, int flagAfter){
    if (flag == 0){
        if (choice == 0){
            setfillstyle(1,WHITE);
            fillpoly(4,button.button1);
            setfillstyle(1,YELLOW);
            fillpoly(4,button.button2);
            fillpoly(4,button.button3);
        }
        else if (choice == 1){
            setfillstyle(1,WHITE);
            fillpoly(4,button.button2);
            setfillstyle(1,YELLOW);
            fillpoly(4,button.button1);
            fillpoly(4,button.button3);
        }
        else if (choice == 2){
            setfillstyle(1,WHITE);
            fillpoly(4,button.button3);
            setfillstyle(1,YELLOW);
            fillpoly(4,button.button1);
            fillpoly(4,button.button2);
        }
    }
        else if (flag == 1){
            if (flagAfter == 0){
                if (choice == 0){
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button3);
                    fillpoly(4,button.button2);
                }
                else if (choice == 1){
                    setfillstyle(1,WHITE);
                    fillpoly(4,button.button2);
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button3);
                }
                else if (choice == 2){
                    setfillstyle(1,WHITE);
                    fillpoly(4,button.button3);
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button2);
                }
            }
            else if (flagAfter == 1){
                if (choice == 0){
                    setfillstyle(1,WHITE);
                    fillpoly(4,button.button1);
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button3);
                }
                else if (choice == 1){
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button1);
                    fillpoly(4,button.button3);
                }
                else if (choice == 2){
                    setfillstyle(1,WHITE);
                    fillpoly(4,button.button3);
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button1);
                }
            }
            else if(flagAfter == 2){
                if (choice == 0){
                    setfillstyle(1,WHITE);
                    fillpoly(4,button.button1);
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button2);
                }
                else if (choice == 1){
                    setfillstyle(1,WHITE);
                    fillpoly(4,button.button2);
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button1);
                }
                else if (choice == 2){
                    setfillstyle(1,YELLOW);
                    fillpoly(4,button.button2);
                    fillpoly(4,button.button1);
                }
            }
        }
        else {
            setfillstyle(1,YELLOW);
            fillpoly(4,button.button2);
            fillpoly(4,button.button1);
            fillpoly(4,button.button2);
        }
}



void Game(){
    setlinestyle(0,2,1);
    line(15,15,610,15);
    line(610,15,610,465);
    int i;
    int number = 0;
    for (i = 0; i < 8; i++){
        bakhna.rings1[i] = 8 - i;
        bakhna.rings2[i] = 0;
        bakhna.rings3[i] = 0;
    }
    setcolor(RED);
    setfillstyle(1,RED);
    fillpoly(4,backGround.backGr1);
    fillpoly(4,backGround.backGr2);
    fillpoly(4,backGround.backGr3);
    setcolor(WHITE);
    setfillstyle(1,GREEN);
    fillpoly(4,tower.tower1);
    fillpoly(4,tower.tower2);
    fillpoly(4,tower.tower3);
    int k = 80, flag = 0, flagAfter = -1;
    char key;
    for (int j = 312, j1 = 0; j > 112; j -= 25, j1++){
        for (i = k; i>=5; i -=2){
            ellipse(143,j,90,90,i,13);
        }
    arr.arr1[j1] = j;
    arr.arr2[j1] = j;
    arr.arr3[j1] = j;
    arr.radius[j1] = k;
    k-=10;
    }
    setcolor(YELLOW);

    outtextxy(15,30,"Number of steps:");

    setfillstyle(1,YELLOW);
    fillpoly(4,button.button1);
    fillpoly(4,button.button2);
    fillpoly(4,button.button3);
    int choice = 0;
    do{

        key = getch();
        switch(key){
            case 'M':{
                choice++;
                if (choice == 3) choice = 0;
                PointChoice(choice,flag,flagAfter);
                break;

            }
            case 'K':{
                choice--;
                if (choice == -1) choice = 2;
                PointChoice(choice,flag,flagAfter);
                break;
            }
            case 13:{
                if (choice == 0){
                    if (flag == 0){    //запоминаем первый выбор
                        flag = 1;
                        flagAfter = choice;    //запоминаем какой сделали первый выбор
                        setcolor(BLUE);
                        setfillstyle(1,BLUE);
                        fillpoly(4,button.button1);
                    }
                    else if(flag == 1 && flagAfter != 0){
                        exchange(choice, flagAfter);
                        number++;
                        counter(number);
                        if (bakhna.rings2[7] == 1 || bakhna.rings3[7] == 1){
                            setcolor(YELLOW);
                            setfillstyle(1,RED);
                            fillpoly(4,win);
                            outtextxy(100,100,"CONGRATULATION!!!!");
                            outtextxy(100,140,"YOU WIN");
                            getch();
                            return;
                        }
                        flag = 0; flagAfter = -1;
                        setcolor(YELLOW);
                        setfillstyle(1,YELLOW);
                        fillpoly(4,button.button1);
                        fillpoly(4,button.button2);
                        fillpoly(4,button.button3);
                    }
                }
                else if (choice == 1){
                    if (flag == 0){    //запоминаем первый выбор
                        flag = 1;
                        flagAfter = choice;    //запоминаем какой сделали выбор
                        setcolor(BLUE);
                        setfillstyle(1,BLUE);
                        fillpoly(4,button.button2);
                    }
                    else if(flag == 1 && flagAfter != 1){
                        exchange(choice, flagAfter);
                        number++;
                        counter(number);
                        if (bakhna.rings2[7] == 1 || bakhna.rings3[7] == 1){
                            setcolor(YELLOW);
                            setfillstyle(1,RED);
                            fillpoly(4,win);
                            outtextxy(100,100,"CONGRATULATION!!!!");
                            outtextxy(100,140,"YOU WIN");
                            getch();
                            return;
                        }
                        flag = 0; flagAfter = -1;
                        setcolor(YELLOW);
                        setfillstyle(1,YELLOW);
                        fillpoly(4,button.button1);
                        fillpoly(4,button.button2);
                        fillpoly(4,button.button3);
                    }
                }
                else if(choice == 2){
                    if (flag == 0){    //запоминаем первый выбор
                        flag = 1;
                        flagAfter = choice;    //запоминаем какой сделали выбор
                        setcolor(BLUE);
                        setfillstyle(1,BLUE);
                        fillpoly(4,button.button3);
                    }
                    else if(flag == 1 && flagAfter != 2){
                        exchange(choice, flagAfter);
                        number++;
                        counter(number);
                        if (bakhna.rings2[7] == 1 || bakhna.rings3[7] == 1){
                            setcolor(YELLOW);
                            setfillstyle(1,RED);
                            fillpoly(4,win);
                            outtextxy(100,100,"CONGRATULATION!!!!");
                            outtextxy(100,140,"YOU WIN");
                            getch();
                            return;
                        }
                        flag = 0; flagAfter = -1;
                        setcolor(YELLOW);
                        setfillstyle(1,YELLOW);
                        fillpoly(4,button.button1);
                        fillpoly(4,button.button2);
                        fillpoly(4,button.button3);
                    }
                }
            }
    }

    }while(key!=27);



 setcolor(YELLOW);
}

void exchange(int choice, int flagAfter){
    int i, firstCircle = 20, ifirst, secondCircle = 20, isecond;
    int *P1, *N1, *M1, *K1,                               //первая башня
        *P2, *N2;                                         //вторая башня
    if (flagAfter == 0) {P1 = bakhna.rings1; N1 = arr.arr1; M1 = backGround.backGr1; K1 = tower.tower1;}
    else if (flagAfter == 1) {P1 = bakhna.rings2; N1 = arr.arr2; M1 = backGround.backGr2; K1 = tower.tower2;}
    else if (flagAfter == 2) {P1 = bakhna.rings3; N1 = arr.arr3; M1 = backGround.backGr3; K1 = tower.tower3;}
    if (choice == 0) {P2 = bakhna.rings1;N2 = arr.arr1;}
    else if (choice == 1) {P2 = bakhna.rings2; N2 = arr.arr2;}
    else if (choice == 2) {P2 = bakhna.rings3; N2 = arr.arr3;}

    for (i = 0; i < 8; i++){
        if (P1[7 - i] != 0){
            firstCircle = P1[7 - i];
            ifirst = 7 - i;
            break;
        }
    }
    if (firstCircle == 20) return;
    for (i = 0; i < 8; i++){
        if (P2[i] == 0){
            if (i == 0) {isecond = 0;
                         break;}
            else {  secondCircle = P2[i - 1];
                    isecond = i;
                    break;}
        }
    }
    if (isecond == 0 || firstCircle < secondCircle){
        P2[isecond] = P1[ifirst];
        P1[ifirst] = 0;
        setcolor(WHITE);
        for (i = arr.radius[8 - firstCircle]; i >= 5; i-=2){
            ellipse(N2[8],N2[isecond],90,90,i,13);
        }
    }
    setcolor(RED);
    setfillstyle(1,RED);
    fillpoly(4,M1);
    setcolor(WHITE);
    setfillstyle(1,GREEN);
    fillpoly(4,K1);
    int rad, k = 0;
    setcolor(WHITE);
    for (int j = 312, rad = P1[k]; P1[k]!= 0; j-=25, k++){
        for (i = P1[k] * 10; i >= 5; i-=2){
            ellipse(N1[8],j,90,90,i,13);
        }
    }
}

void counter(int number){
    setcolor(YELLOW);
    int flagh = 0, i = 0, k = 0;
    char kek[10] = {0};
    itoa(number, &kek[0], 10);
    outtextxy(350,30,kek);
}

void instruction(){
    setcolor(YELLOW);
    setlinestyle(0,2,1);
    line(15,15,610,15);
    line(610,15,610,465);
    line(15,15,610,15);
    line(15,15,610,15);
    settextstyle(10,0,2);
    outtextxy(20,30,"The Hanoi tower is one of popular puzzles");
    outtextxy(20,60,"of the 19th century. Three cores on one");
    outtextxy(20,90,"of which eight rings are strung are given,");
    outtextxy(20,120," and rings differ in the size and lie");
    outtextxy(20,150,"smaller on bigger. The task consists");
    outtextxy(20,180,"in transferring a pyramid from eight");
    outtextxy(20,210,"rings for the smallest number of the");
    outtextxy(20,240,"courses to other core.");
    settextstyle(10,0,4);
    getch();
}
