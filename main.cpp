#include <bits/stdc++.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <mmsystem.h>
#define ii pair<long,long>
//#pragma comment(lib,"winmm.lib")
std::mt19937_64 rd;
using namespace std;
const long Max_Y=44,Max_X=165;
long meoltx,meolty,meordx,meordy,hpnyltx,hpnylty,hpnyrdx,hpnyrdy,bannerltx,bannerlty,bannerrdx,bannerrdy;
vector<pair<ii,ii> > firework;
string num[10][17]={
    {
            "                     ",
            "      000000000      ",
            "    00:::::::::00    ",
            "  00:::::::::::::00  ",
            " 0:::::::000:::::::0 ",
            " 0::::::0   0::::::0 ",
            " 0:::::0     0:::::0 ",
            " 0:::::0     0:::::0 ",
            " 0:::::0 000 0:::::0 ",
            " 0:::::0     0:::::0 ",
            " 0:::::0     0:::::0 ",
            " 0::::::0   0::::::0 ",
            " 0:::::::000:::::::0 ",
            "  00:::::::::::::00  ",
            "    00:::::::::00    ",
            "      000000000      ",""
    },
    {
            "                     ",
            "       1111111       ",
            "      1::::::1       ",
            "     1:::::::1       ",
            "     111:::::1       ",
            "        1::::1       ",
            "        1::::1       ",
            "        1::::1       ",
            "        1::::l       ",
            "        1::::l       ",
            "        1::::l       ",
            "        1::::l       ",
            "     111::::::111    ",
            "     1::::::::::1    ",
            "     1::::::::::1    ",
            "     111111111111    ",""
    },
    {
            "                     ",
            " 222222222222222     ",
            " 2:::::::::::::::22  ",
            " 2::::::222222:::::2 ",
            " 2222222     2:::::2 ",
            "             2:::::2 ",
            "             2:::::2 ",
            "          2222::::2  ",
            "     22222::::::22   ",
            "   22::::::::222     ",
            "  2:::::22222        ",
            " 2:::::2             ",
            " 2:::::2       222222",
            " 2::::::2222222:::::2",
            " 2::::::::::::::::::2",
            " 22222222222222222222",""
    },
    {
            "                     ",
            " 3333333333333333    ",
            " 3:::::::::::::::33  ",
            " 3::::::33333::::::3 ",
            " 3333333     3:::::3 ",
            "             3:::::3 ",
            "             3:::::3 ",
            "     33333333:::::3  ",
            "     3:::::::::::3   ",
            "     33333333:::::3  ",
            "             3:::::3 ",
            "             3:::::3 ",
            " 3333333     3:::::3 ",
            " 3::::::33333::::::3 ",
            " 3:::::::::::::::33  ",
            "  333333333333333    ",""
    },
    {
            "                     ",
            "        444444444    ",
            "       4::::::::4    ",
            "      4:::::::::4    ",
            "     4::::44::::4    ",
            "    4::::4 4::::4    ",
            "   4::::4  4::::4    ",
            "  4::::4   4::::4    ",
            " 4::::444444::::444  ",
            " 4::::::::::::::::4  ",
            " 4444444444:::::444  ",
            "           4::::4    ",
            "           4::::4    ",
            "         44::::::44  ",
            "         4::::::::4  ",
            "         4444444444  ",""
    },
    {
            "                     ",
            " 555555555555555555  ",
            " 5::::::::::::::::5  ",
            " 5:::::555555555555  ",
            " 5:::::5             ",
            " 5:::::5             ",
            " 5:::::5555555555    ",
            " 5:::::::::::::::5   ",
            " 555555555555:::::5  ",
            "             5:::::5 ",
            "             5:::::5 ",
            " 5555555     5:::::5 ",
            " 5::::::55555::::::5 ",
            "  55:::::::::::::55  ",
            "    55:::::::::55    ",
            "      555555555      ",""
    },
    {
            "                     ",
            "         66666666    ",
            "        6::::::6     ",
            "       6::::::6      ",
            "      6::::::6       ",
            "     6::::::6        ",
            "    6::::::6         ",
            "   6::::::::66666    ",
            "  6::::::::::::::6   ",
            " 6::::::66666:::::6  ",
            " 6:::::6     6:::::6 ",
            " 6:::::6     6:::::6 ",
            " 6::::::66666::::::6 ",
            "  66:::::::::::::66  ",
            "    66:::::::::66    ",
            "      666666666      ",""
    },
    {
            "                     ",
            " 77777777777777777777",
            " 7::::::::::::::::::7",
            " 7::::::::::::::::::7",
            " 777777777777:::::::7",
            "            7::::::7 ",
            "           7::::::7  ",
            "          7::::::7   ",
            "         7::::::7    ",
            "        7::::::7     ",
            "       7::::::7      ",
            "      7::::::7       ",
            "     7::::::7        ",
            "    7::::::7         ",
            "   7::::::7          ",
            "  77777777           ",""
    },
    {
            "                     ",
            "      888888888      ",
            "    88:::::::::88    ",
            "  88:::::::::::::88  ",
            " 8::::::88888::::::8 ",
            " 8:::::8     8:::::8 ",
            " 8:::::8     8:::::8 ",
            "  8:::::88888:::::8  ",
            "   8:::::::::::::8   ",
            "  8:::::88888:::::8  ",
            " 8:::::8     8:::::8 ",
            " 8:::::8     8:::::8 ",
            " 8::::::88888::::::8 ",
            "  88:::::::::::::88  ",
            "    88:::::::::88    ",
            "      888888888      ",""
    },
    {
		"                     ",
		"      999999999      ",
		"    99:::::::::99    ",
		"  99:::::::::::::99  ",
		" 9::::::99999::::::9 ",
		" 9:::::9     9:::::9 ",
		" 9:::::9     9:::::9 ",
		"  9:::::99999::::::9 ",
		"   99::::::::::::::9 ",
		"     99999::::::::9  ",
		"          9::::::9   ",
		"         9::::::9    ",
		"        9::::::9     ",
		"       9:::::9       ",
		"      9:::::9        ",
		"     9999999         ",""
    }
};
const string HappyNewYear[] ={
		"                                                                         ",
		"  __    __       ___      .______   .______    ____     ____              ",
		" |  |  |  |     /   \\     |   _  \\  |   _  \\   \\   \\   /  \/          ",
		" |  |__|  |    /  ^  \\    |  |_)  | |  |_)  |   \\   \\_/  /             ",
		" |   __   |   /  /_\\  \\   |   ___/  |   ___/     \\_    _/             ",
		" |  |  |  |  /  _____  \\  |  |      |  |           |  |                  ",
		" |__|  |__| /__/     \\__\\ | _|      | _|           |__|                 ",
		"                                                                         ",
		"            .__   __.  ___________    __    ____                         ",
		"            |  \\ |  | |   ____\\   \\  /  \\  /   /                     ",
		"            |   \\|  | |  |__   \\   \\/    \\/   /                      ",
		"            |  . \`  | |   __|   \\            /                         ",
		"            |  |\\   | |  |____   \\    /\\    /                         ",
		"            |__| \\__| |_______|   \\__/  \\__/                          ",
		"                                                                         ",
		"                    ____    ____  _______     ___       .______          ",
		"                    \\   \\  /   / |   ____|   /   \\      |   _  \\     ",
		"                     \\   \\/   /  |  |__     /  ^  \\     |  |_)  |     ",
		"                      \\_    _/   |   __|   /  /_\\  \\    |      /      ",
		"                        |  |     |  |____ /  _____  \\   |  |\\  \\----. ",
		"                        |__|     |_______/__/     \\__\\  | _| \`._____| ",
		"                                                                         ",""
};
const string banner[] = {
		"                                                 ",
		"                                                 ",
		":\'#######::::\'#####::::\'#######:::\'#######:: ",
		"\'##.... ##::\'##..  ##::\'##....##:\'##.... ## :",
		"..:::: :##:\'##:::: ##:..::::: ##:..::::: ##:    ",
		":\'#######:: ##:::: ##::'#######:: :\'#######::  ",
		"\'##:::::::: ##:::: ##:\'##:::::::: : ......## : ",
		" ##::::::::. ##:: ##:: ##::::::::\'##::::  ##:   ",
		" #########::. #####:: :######### : #######::     ",
		".........::::.....::::.........:: : .......:: :  ",
		"                                                 ",""
};
const string animal[] = {
	"       *     ,MMM8&&.      *",
	"            MMMM88&&&&      ",
	"           MMMM88&&&&&&     ",
	"*          MMM88&&&&&&&     ",
	"           MMMM88&&&&&&     ",
	"            \'MMM88&&&&\'   ",
	"              \'MM8&&\'     ",
	"     |\\___/|               ",
	"     )     (      .       \'",
	"    =\\     /=              ",
	"      )===(             *   ",
	"     /     \\               ",
	"     |     |                ",
	"    /       \\              ",
	"    \\       /              ",
    "_/\\_/\\__  _/_/\\_/\\_/\\_/\\_",
    "|  |   ( (     |  |  |  |   ",
    "|  |    ) )    |  |  |  |   ",
    "|  |   (_(     |  |  |  |   ",
    "|  |           |  |  |  |   ",
    "Meoww Meoww    |  |  |  |   ",""
};
void Textcolor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void HideCursor(){
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
long random(long l,long r) {
    long len=r-l+1;
    return l+rd()%len;
}
void make_countdown(void) {
    long x,y;
    for(long countdown=9;countdown>=0;countdown--) {
        for(long index=0;num[countdown][index]!="";index++) {
            x=Max_X/2.5;y=Max_Y/3;
            GoTo(x,y+index);
            Textcolor(countdown);
            if (countdown==0) Textcolor(index);
            cout<<num[countdown][index]<<'\n';
        }
        sleep(1);
    }
}
void make_background(void) {
    long x,y;
    Textcolor(4);
    hpnyltx=1;hpnylty=2;hpnyrdx=72;hpnyrdy=24;
    for(long index=0;HappyNewYear[index]!="";index++) {
        x=1;y=2+index;
        GoTo(x,y);
        cout<<HappyNewYear[index]<<'\n';
    }
    Textcolor(2);
    bannerltx=2*Max_X/3;bannerlty=Max_Y/12;
    bannerrdx=2*Max_X/3+49;bannerrdy=Max_Y/12+7;
    for(long index=0;banner[index]!="";index++) {
        x=2*Max_X/3;y=Max_Y/12+index;
        GoTo(x,y);
        cout<<banner[index]<<'\n';
    }
    Textcolor(6);
    meoltx=Max_X/2+4;meolty=Max_Y/2.5;
    meordx=Max_X/2+35;meordy=Max_Y/2.5+20;
    for(long index=0;animal[index]!="";index++) {
        x=Max_X/2+4;y=Max_Y/2.5+index;
        GoTo(x,y);
        cout<<animal[index]<<'\n';
    }
}
/*void Bum_chiu(long x,long y,long delay=20) {
    long len=5;
    //the firework is in 0ms
    GoTo(x,y);Textcolor(rd()%9+1);if (out()) cout<<'$';Sleep(delay);
    //the firework is in delay ms
    GoTo(x,y);if (out()) cout<<' ';
    GoTo(x-1,y);Textcolor(rd()%9+1);if (out()) cout<<'*';
    GoTo(x,y+1);Textcolor(rd()%9+1);if (out()) cout<<'*';
    GoTo(x+1,y);Textcolor(rd()%9+1);if (out()) cout<<'*';
    GoTo(x,y-1);Textcolor(rd()%9+1);if (out()) cout<<'*';
    Sleep(delay);
    // the firework is in other ms
    for(long index=2;index<=len;index++) {
        if (y-index>=0) {
            GoTo(x,y-index+1);if (out()) cout<<' ';
            GoTo(x,y-index);Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (x+(index-1)<=Max_X&&y-(index-1)>=0) {
            GoTo(x+(index-1)-1,y-(index-1)+1);if (out()) cout<<' ';
            GoTo(x+(index-1),y-(index-1));Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (x+index<=Max_X) {
            GoTo(x+index-1,y);if (out()) cout<<' ';
            GoTo(x+index,y);Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (x+(index-1)<=Max_X&&y+(index-1)<=Max_Y) {
            GoTo(x+(index-1)-1,y+(index-1)-1);if (out()) cout<<' ';
            GoTo(x+(index-1),y+(index-1));Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (y+index<=Max_Y) {
            GoTo(x,y+index-1);if (out()) cout<<' ';
            GoTo(x,y+index);Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (x-(index-1)>=0&&y+(index-1)<=Max_Y) {
            GoTo(x-(index-1)+1,y+(index-1)-1);if (out()) cout<<' ';
            GoTo(x-(index-1),y+(index-1));Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (x-index>=0) {
            GoTo(x-index+1,y);if (out()) cout<<' ';
            GoTo(x-index,y);Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        if (x-index>=0&&y-index>=0) {
            GoTo(x-(index-1)+1,y-(index-1)+1);if (out()) cout<<' ';
            GoTo(x-(index-1),y-(index-1));Textcolor(rd()%9+1);if (out()) cout<<'*';
        }
        Sleep(delay);
    }
    long index=len+1;
    if (y-index>=0) {
        GoTo(x,y-index+1);if (out()) cout<<' ';
    }
    if (x+(index-1)<=Max_X&&y-(index-1)>=0) {
        GoTo(x+(index-1)-1,y-(index-1)+1);if (out()) cout<<' ';
    }
    if (x+index<=Max_X) {
        GoTo(x+index-1,y);if (out()) cout<<' ';
    }
    if (x+(index-1)<=Max_X&&y+(index-1)<=Max_Y) {
        GoTo(x+(index-1)-1,y+(index-1)-1);if (out()) cout<<' ';
    }
    if (y+index<=Max_Y) {
        GoTo(x,y+index-1);if (out()) cout<<' ';
    }
    if (x-(index-1)>=0&&y+(index-1)<=Max_Y) {
        GoTo(x-(index-1)+1,y+(index-1)-1);if (out()) cout<<' ';
    }
    if (x-index>=0) {
        GoTo(x-index+1,y);if (out()) cout<<' ';
    }
    if (x-(index-1)>=0&&y-(index-1)>=0) {
        GoTo(x-(index-1)+1,y-(index-1)+1);if (out()) cout<<' ';
    }
}
void demo_firework() {
    long x=random(10,Max_X-10),y=Max_Y-3,high=random(5,Max_Y-5),color=random(1,9);
    Textcolor(color);
    for(;y>=high;y--) {
        GoTo(x,y);if (out()) cout<<"$";
        GoTo(x,y+1);if (out()) cout<<"*";
        GoTo(x,y+2);if (out()) cout<<".";
        GoTo(x,y+3);if (out()) cout<<" ";
        Sleep(20);
    }
    GoTo(x,y);if (out()) cout<<" ";GoTo(x,y+1);if (out()) cout<<" ";GoTo(x,y+2);if (out()) cout<<" ";
    Bum_chiu(x,y);
}*/
bool out(long x,long y) {
    if (meoltx<=x&&x<=meordx&&meolty<=y&&y<=meordy) return false;
    if (hpnyltx<=x&&x<=hpnyrdx&&hpnylty<=y&&y<=hpnyrdy) return false;
    if (bannerltx<=x&&x<=bannerrdx&&bannerlty<=y&&y<=bannerrdy) return false;
    return true;
}
void Bum_chiu(long x,long y,long step) {
    long len=7;
    if (step>len) return;
    //the firework is in 0ms
    if (step==1) {
        GoTo(x,y);if (out(x,y)) cout<<" ";GoTo(x,y+1);if (out(x,y+1)) cout<<" ";GoTo(x,y+2);if (out(x,y+2)) cout<<" ";
        GoTo(x,y);Textcolor(rd()%9+1);if (out(x,y)) cout<<'$';
    }
    //the firework is in delay ms
    if (step==2) {
        GoTo(x,y);if (out(x,y)) cout<<' ';
        GoTo(x-1,y);Textcolor(rd()%9+1);if (out(x-1,y)) cout<<'*';
        GoTo(x,y+1);Textcolor(rd()%9+1);if (out(x,y+1)) cout<<'*';
        GoTo(x+1,y);Textcolor(rd()%9+1);if (out(x+1,y)) cout<<'*';
        GoTo(x,y-1);Textcolor(rd()%9+1);if (out(x,y-1)) cout<<'*';
    }
    // the firework is in other ms
    if (step>=3&&step<=6) {
        long index=step-1;
        if (y-index>=0) {
            GoTo(x,y-index+1);if (out(x,y-index+1)) cout<<' ';
            GoTo(x,y-index);Textcolor(rd()%9+1);if (out(x,y-index)) cout<<'*';
        }
        if (x+(index-1)<=Max_X&&y-(index-1)>=0) {
            GoTo(x+(index-1)-1,y-(index-1)+1);if (out(x+(index-1)-1,y-(index-1)+1)) cout<<' ';
            GoTo(x+(index-1),y-(index-1));Textcolor(rd()%9+1);if (out(x+(index-1),y-(index-1))) cout<<'*';
        }
        if (x+index<=Max_X) {
            GoTo(x+index-1,y);if (out(x+index-1,y)) cout<<' ';
            GoTo(x+index,y);Textcolor(rd()%9+1);if (out(x+index,y)) cout<<'*';
        }
        if (x+(index-1)<=Max_X&&y+(index-1)<=Max_Y) {
            GoTo(x+(index-1)-1,y+(index-1)-1);if (out(x+(index-1)-1,y+(index-1)-1)) cout<<' ';
            GoTo(x+(index-1),y+(index-1));Textcolor(rd()%9+1);if (out(x+(index-1),y+(index-1))) cout<<'*';
        }
        if (y+index<=Max_Y) {
            GoTo(x,y+index-1);if (out(x,y+index-1)) cout<<' ';
            GoTo(x,y+index);Textcolor(rd()%9+1);if (out(x,y+index)) cout<<'*';
        }
        if (x-(index-1)>=0&&y+(index-1)<=Max_Y) {
            GoTo(x-(index-1)+1,y+(index-1)-1);if (out(x-(index-1)+1,y+(index-1)-1)) cout<<' ';
            GoTo(x-(index-1),y+(index-1));Textcolor(rd()%9+1);if (out(x-(index-1),y+(index-1))) cout<<'*';
        }
        if (x-index>=0) {
            GoTo(x-index+1,y);if (out(x-index+1,y)) cout<<' ';
            GoTo(x-index,y);Textcolor(rd()%9+1);if (out(x-index,y)) cout<<'*';
        }
        if (x-index>=0&&y-index>=0) {
            GoTo(x-(index-1)+1,y-(index-1)+1);if (out(x-(index-1)+1,y-(index-1)+1)) cout<<' ';
            GoTo(x-(index-1),y-(index-1));Textcolor(rd()%9+1);if (out(x-(index-1),y-(index-1))) cout<<'*';
        }
    }
    if (step==7) {
        long index=step-1;
        if (y-index>=0) {
            GoTo(x,y-index+1);if (out(x,y-index+1)) cout<<' ';
        }
        if (x+(index-1)<=Max_X&&y-(index-1)>=0) {
            GoTo(x+(index-1)-1,y-(index-1)+1);if (out(x+(index-1)-1,y-(index-1)+1)) cout<<' ';
        }
        if (x+index<=Max_X) {
            GoTo(x+index-1,y);if (out(x+index-1,y)) cout<<' ';
        }
        if (x+(index-1)<=Max_X&&y+(index-1)<=Max_Y) {
            GoTo(x+(index-1)-1,y+(index-1)-1);if (out(x+(index-1)-1,y+(index-1)-1)) cout<<' ';
        }
        if (y+index<=Max_Y) {
            GoTo(x,y+index-1);if (out(x,y+index-1)) cout<<' ';
        }
        if (x-(index-1)>=0&&y+(index-1)<=Max_Y) {
            GoTo(x-(index-1)+1,y+(index-1)-1);if (out(x-(index-1)+1,y+(index-1)-1)) cout<<' ';
        }
        if (x-index>=0) {
            GoTo(x-index+1,y);if (out(x-index+1,y)) cout<<' ';
        }
        if (x-(index-1)>=0&&y-(index-1)>=0) {
            GoTo(x-(index-1)+1,y-(index-1)+1);if (out(x-(index-1)+1,y-(index-1)+1)) cout<<' ';
        }
    }
}
void fireworks_display(void) {
    long Count=random(3,7);
    for(long index=1;index<=Count;index++) {
        long high,x=random(10,Max_X-10),y=random(Max_Y-3,Max_Y+5),color=random(1,9);
        if (x<=Max_X/5) high=random(10,Max_Y-5);else
            if (x<=Max_X/2) high=random(23,Max_Y-5);else
                if (x<=2*Max_X/3) high=random(5,15);else
                    high=random(10,Max_Y-5);
        firework.push_back(make_pair(make_pair(high,color),make_pair(x,y)));
    }
    sort(firework.begin(),firework.end());
    reverse(firework.begin(),firework.end());
    for(long up=firework.back().second.second-firework.back().first.first+10;up>0;up--){
        for(pair<ii,ii> &value:firework) {
                Textcolor(value.first.second);
                value.second.second--;
                long x=value.second.first,y=value.second.second;
                if (y>Max_Y-3) continue;
                if (y<value.first.first) Bum_chiu(x,value.first.first,value.first.first-y);else {
                    GoTo(x,y);if (out(x,y)) cout<<"$";
                    GoTo(x,y+1);if (out(x,y+1)) cout<<"*";
                    GoTo(x,y+2);if (out(x,y+2)) cout<<".";
                    GoTo(x,y+3);if (out(x,y+3)) cout<<" ";
                }
            }
        Sleep(20);
    }
    firework.clear();
}
int main()
{
    //SetWindowSize(Max_X,Max_Y);
    HideCursor();
    SetConsoleTitle("Happy New Year 2023");
    DisableResizeWindow();
    ShowScrollbar(0);
    PlaySound(TEXT("music/clock.wav"), NULL, SND_ASYNC | SND_FILENAME);
    sleep(1);
    make_countdown();
    system("cls");
    long tmp=0,cnt=10;
	PlaySound(TEXT("music/firework.wav"), NULL, SND_ASYNC | SND_LOOP);
    while (1) {
        if (tmp==0) {
            make_background();
        }
        //demo_firework();
        fireworks_display();
        tmp=(tmp+1)%5;
    }

    return 0;
}
