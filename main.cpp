#include <fstream>
#include <dos.h>
#include "ashid.h"
#include "resource.h"
#include "dlg1.cpp"


HWND hEdit[14][14];
HWND hinpt[30][20];
HWND HCOMB[2][2];
HWND HTEMP[20][20];
int inputdata[40];
int nop=0,multch=0;
char dir[6][100],tmpname[100],tmpname2[100];
int day=0,dte[5];
char tbox[20],cbox[20],abox[20];
char arr[10][5][20],dmy[4][5];
char A[40];
int xpos,ypos;
int indexc=1,indext=1,indexrec=1,indexarr=1;
char version[20];
char sh[40];
char Date[5];


LRESULT CALLBACK WinProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
void creat_tbl(HWND);
void mod_save();
void creat_tbl_p2(HWND);
void tbl_p2(HWND);
void menu(HWND);
void alldir();
void statictext();
LPSTR choice(WPARAM);
void creat_dir();
void input(HWND);
void load_data();
void getinput(HWND);
void input2(HWND);
void savetbl();
void destroy_window();
void get_tch(int ,int);
void get_data();
void teacher_table(int,int);
void c_dir();
void settings();



using namespace std;

class chck
{
    public:
        int a[10];
        char aa[10][10][10];
        char install_date[80];
        char uuid[80];
        char oa3x_original_product_key[80];
        char os_product_key[80];
        char name[80];
        char baseboard_serial_number[80];
        char bios_serial_number[80];
        char volume_serial_number[80];
        char ttm_product_key[40];
        char user_ttm_product_key[40];
        char universal_ttm_key[40];
        char z[20];
        char aab[10][10][10];
}chk,chk2;


class ARRANGEMENT
{
    public:
        int n;
        char ab_tch_name[20];
        char bs_period[9][20];
        char alt_tch_name[9][20];
        char bs_clss[9][20];
        ARRANGEMENT();
}Arr,blnkarr;

ARRANGEMENT::ARRANGEMENT()
{
    n=0;
    strcpy(ab_tch_name,"\0");
    for(int i=0;i<9;i++)
    {
        strcpy(bs_clss[i],"\0");
        strcpy(bs_period[i],"\0");
        strcpy(alt_tch_name[i],"\0");
    }

}
struct arryr
{
    char date[20];
    ARRANGEMENT tcharr[50];

}tarr[300],blankarr;



class TEACHERREC
{
    public:
        char tchname[20];
        char sbjname[12][20];
}blank2;

class TABLE
{
    public:
        char main[10][10][40];
        char info[10][10][40];
        char name[40];
        char sbj[30][40],sbjinfo[30][40],sbjexp[5][40],sbjexpinfo[5][40];
        char identifiers[5][20];
        char multi_sub[16][20];
        char multi_tch[16][20];

}clas,tchr,blank;



struct classfiles
{
TABLE clas;

}classfile[100];


struct record
{
TEACHERREC tchrec;

}rec[200];

struct teacherfiles
{
TABLE tch;

}teacherfile[200];


void dn()
{
ifstream fin;

fin.open("config.ttm",ios::in|ios::binary);
if(!fin.good())
{
fin.close();
MessageBox(NULL,"Configuration Setting File Missing!!!\nUnable To Proceed Further..Closing TTM..","Error!!!",MB_OK|MB_ICONERROR);
exit(0);
}
else
{
fin.read((char*)&chk,sizeof(chk));
fin.close();
}

for(int i=0;i<10;i++)
{
chk.a[i]=chk.a[i]-127;
chk.z[i+10]=chk.z[i+10]-127;
}
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
for(int k=0;k<10;k++)
{
chk.aa[i][j][k]=chk.aa[i][j][k]-127;
chk.aab[i][j][k]=chk.aab[i][j][k]-137;
}
}
}

for(int i=0;i<80;i++)
{
chk.install_date[i]=chk.install_date[i]-123;
chk.uuid[i]=chk.uuid[i]-147;
chk.oa3x_original_product_key[i]=chk.oa3x_original_product_key[i]-122;
chk.os_product_key[i]=chk.os_product_key[i]-127;
chk.name[i]=chk.name[i]-130;
chk.baseboard_serial_number[i]=chk.baseboard_serial_number[i]-127;
chk.bios_serial_number[i]=chk.bios_serial_number[i]-144;
chk.volume_serial_number[i]=chk.volume_serial_number[i]-128;
if(i<40)
{
chk.ttm_product_key[i]=chk.ttm_product_key[i]-121;
chk.user_ttm_product_key[i]=chk.user_ttm_product_key[i]-126;
chk.universal_ttm_key[i]=chk.universal_ttm_key[i]-130;
}
}




}


void en()
{

ofstream fout;

for(int i=0;i<10;i++)
{
chk.a[i]=chk.a[i]+127;
chk.z[i+10]=chk.z[i+10]+127;
}
for(int i=0;i<10;i++)
{
for(int j=0;j<10;j++)
{
for(int k=0;k<10;k++)
{
chk.aa[i][j][k]=chk.aa[i][j][k]+127;
chk.aab[i][j][k]=chk.aab[i][j][k]+137;
}
}
}

for(int i=0;i<80;i++)
{
chk.install_date[i]=chk.install_date[i]+123;
chk.uuid[i]=chk.uuid[i]+147;
chk.oa3x_original_product_key[i]=chk.oa3x_original_product_key[i]+122;
chk.os_product_key[i]=chk.os_product_key[i]+127;
chk.name[i]=chk.name[i]+130;
chk.baseboard_serial_number[i]=chk.baseboard_serial_number[i]+127;
chk.bios_serial_number[i]=chk.bios_serial_number[i]+144;
chk.volume_serial_number[i]=chk.volume_serial_number[i]+128;
if(i<40)
{
chk.ttm_product_key[i]=chk.ttm_product_key[i]+121;
chk.user_ttm_product_key[i]=chk.user_ttm_product_key[i]+126;
chk.universal_ttm_key[i]=chk.universal_ttm_key[i]+130;
}
}




fout.open("config.ttm",ios::out|ios::binary);
fout.write((char*)&chk,sizeof(chk));
fout.close();

}




void get_date()
{
    SYSTEMTIME stime={0};
    GetLocalTime(&stime);
    day=stime.wDayOfWeek;
    dte[0]=stime.wDay;
    dte[1]=stime.wMonth;
    dte[2]=stime.wYear;
    fstream fout,fin;
    strcpy(tmpname,dir[1]);
    strcat(tmpname,"date.ttm");

    fout.open(tmpname,ios::out|ios::binary);
    fout<<dte[2]<<endl<<dte[1]<<endl<<dte[0]<<endl;
    fout<<dte[0]<<"."<<dte[1]<<"."<<dte[2];
    fout.close();

    fin.open(tmpname,ios::in|ios::binary);
    fin>>dmy[2]>>dmy[1]>>dmy[0]>>Date;

    fin.close();

}





void del2()
{
int indt=0,indc=0,indrec=0;
GetWindowText(hinpt[0][1],abox,20);
GetWindowText(hinpt[0][3],tbox,20);
GetWindowText(hinpt[0][6],A,20);

while(indrec<=indexrec)
{
if(strcmp(rec[indrec].tchrec.tchname,A)==0)
{
for(int i=0;i<=10;i++)
{
if(i==0)
strcpy(rec[indrec].tchrec.tchname,"\0");
else
strcpy(rec[indrec].tchrec.sbjname[i],"\0");

} break;

}
indrec++;
}






while(indt<=indext)
{
if(strcmp(teacherfile[indt].tch.name,tbox)==0)
{
teacherfile[indt].tch=blank;
/*  for(int i=0;i<=6;i++)
{
for (int j=0;j<=8;j++)
{
strcpy(teacherfile[indt].tch.info[i][j],"\0");
strcpy(teacherfile[indt].tch.main[i][j],"\0");

strcpy(teacherfile[indt].tch.name,"\0");

if(i==0)
{
strcpy(teacherfile[indt].tch.sbj[j],"\0");
strcpy(teacherfile[indt].tch.sbj[j+10],"\0");
strcpy(teacherfile[indt].tch.sbjinfo[j],"\0");
strcpy(teacherfile[indt].tch.sbjinfo[j+10],"\0");
}

}
} break;
*/
}
indt++;
}




while(indc<=indexc)
{
if(strcmp(classfile[indc].clas.name,abox)==0)
{
classfile[indc].clas=blank;
}
indc++;
}
strcpy(tmpname2,dir[4]);
strcat(tmpname2,abox);
strcat(tmpname2,".xls");
remove(tmpname2);
strcpy(tmpname2,dir[2]);
strcat(tmpname2,tbox);
strcat(tmpname2,".xls");
remove(tmpname2);

savetbl();
mod_save();
load_data();
}






void del(HWND hWnd)
{
destroy_window();
load_data();
if(!hinpt[0][0])
{			hinpt[0][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"ENTER CLASS NAME TO BE DELETED",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
60,
500,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}



if(!hinpt[0][1])
{

hinpt[0][1]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"-",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
600,
60,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}


if(!hinpt[0][2])
{			hinpt[0][2]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"ENTER TEACHER NAME TO BE DELETED",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
100,
500,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[0][3])
{

hinpt[0][3]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"-",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
600,
100,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}


if(!hinpt[0][5])
{			hinpt[0][5]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"ENTER TEACHER RECORD TO BE DELETED",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
140,
500,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[0][6])
{

hinpt[0][6]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"-",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
600,
140,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}




if(!hinpt[0][4])
{
hinpt[0][4]=CreateWindowEx(WS_EX_CLIENTEDGE,
"BUTTON",
"SUBMIT",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
500,
180,
70,
30,
hWnd,
(HMENU)ID_DEL,
GetModuleHandle(NULL),
NULL);
}

}



void fillarr(int x,int y,int i)
{
int indt=0;


while(indt<=indext)
{
if((((teacherfile[indt].tch.name[0])>=65)&&((teacherfile[indt].tch.name[0])<=90))||(((teacherfile[indt].tch.name[0])>=97)&&((teacherfile[indt].tch.name[0])<=122)))
{
if(strcmp(teacherfile[indt].tch.name,abox)!=0)
{

if(!(((teacherfile[indt].tch.main[x][y][0])>=65)&&((teacherfile[indt].tch.main[x][y][0])<=90))||(((teacherfile[indt].tch.main[x][y][0])>=97)&&((teacherfile[indt].tch.main[x][y][0])<=122)))
{
SendMessage(HTEMP[i][2],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)teacherfile[indt].tch.name));
SendMessage(HCOMB[i][2], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
}
}
}
indt++;
}

}


void save_arr_tbl()
{
    int indr=0;
    char tmpname2[100],tem3[100];
    fstream fout,fout2;
    for (int i=1;i<9;i++)
        {
            for (int j=0;j<3;j++)
            {
                GetWindowText(HTEMP[i][j],arr[i][j],20);
            }
        }

    for(int i=1;i<9;i++)
        {
            if((((arr[i][2][1])>=65)&&((arr[i][2][1])<=90))||(((arr[i][2][1])>=97)&&((arr[i][2][1])<=122)))
                {
                    Arr.n=1;
                    strcpy(Arr.ab_tch_name,abox);
                    strcpy(Arr.alt_tch_name[i],arr[i][2]);
                    strcpy(Arr.bs_clss[i],arr[i][1]);
                    strcpy(Arr.bs_period[i],arr[i][0]);

                }
        }

    int flag=0,flag1=0;
    strcpy(tmpname,dir[1]);
    strcat(tmpname,"arr.ttm");
    fout.open(tmpname,ios::out|ios::binary);
    indr=0;

    while(indr<=indexarr)
    {
        if(strcmp(tarr[indr].date,Date)==0)     //current date found in the database
        {
            flag=1;
            for(int i=0;i<=50;i++)
            {
                if(strcmp(tarr[indr].tcharr[i].ab_tch_name,abox)==0)        //absent teacher name is present in the arr database
                {
                    flag1=1;
                    tarr[indr].tcharr[i]=Arr;
                }
            }
            if(flag1==0)                                                    ////absent teacher name is not present in the arr database
            {
                for(int i=0;i<=50;i++)
                {
                    if(tarr[indr].tcharr[i].n==0)        //checking blank class
                    {
                        flag=1;
                        tarr[indr].tcharr[i]=Arr;
                    }
                }
            }
        }
        fout.write((char*)&tarr[indr],sizeof(tarr[indr]));
        indr++;
    }

    if(flag==0)
    {
        indexarr++;
        strcpy(tarr[indexarr].date,Date);
        tarr[indexarr].tcharr[0]=Arr;
        fout.write((char*)&tarr[indexarr],sizeof(tarr[indexarr]));

    }

    fout.close();

load_data();

    strcpy(tmpname,"\0");
    strcpy(tmpname,dir[3]);

    strcat(tmpname,Date);
    strcat(tmpname,"\\");
    CreateDirectory(tmpname,NULL);
    strcpy(tem3,tmpname);
    strcat(tem3,"Absent Teachers\\");
    CreateDirectory(tem3,NULL);
    strcat(tmpname,"Alloted Arrangements\\");
    CreateDirectory(tmpname,NULL);


    indr=0;
    while(indr<=indexarr)
    {
        if(strcmp(tarr[indr].date,Date)==0)
        {
            for(int i=0;i<50;i++)
            {
                for(int j=1;j<9;j++)
                {
                    if(tarr[indr].tcharr[i].n==1)
                    {
                        strcpy(tmpname2,"\0");
                        strcpy(tmpname2,tem3);
                        strcat(tmpname2,tarr[indr].tcharr[i].ab_tch_name);
                        strcat(tmpname2,".txt");
                        fout2.open(tmpname2,ios::out|ios::app);
                        fout2<<"\tArrangement Created For The Teacher : "<<tarr[indr].tcharr[i].ab_tch_name<<"\n";
                        fout2<<"Teacher was busy in Period "<<tarr[indr].tcharr[i].bs_period[j]<<" in Class "<<tarr[indr].tcharr[i].bs_clss[j]<<" . \n";
                        fout2<<"Teacher Alloted : "<<tarr[indr].tcharr[i].alt_tch_name[j]<<"\n\n*************************************************************\n\n";


                        strcpy(tmpname2,"\0");
                        strcpy(tmpname2,tmpname);
                        strcat(tmpname2,tarr[indr].tcharr[i].alt_tch_name[j]);
                        strcat(tmpname2,".txt");
                        fout.open(tmpname2,ios::out|ios::app);
                        fout<<"\t\tTeacher name : "<<tarr[indr].tcharr[i].alt_tch_name[j]<<endl;
                        fout<<"Period : "<<tarr[indr].tcharr[i].bs_period[j]<<" . \n";
                        fout<<"Arrangement in "<<tarr[indr].tcharr[i].bs_clss[j]<<" in place of "<<tarr[indr].tcharr[i].ab_tch_name<<" .\n\n*************************************************************\n\n";

                        fout.close();
                        fout2.close();
                    }
                }
            }
        }
        indr++;
    }

  Arr=blnkarr;
    MessageBox(NULL,"Arrangement Files Created","INFO",MB_ICONINFORMATION|MB_OK);
}




void cedit()
{
int indt=0;

for(int i=1;i<9;i++)
for(int j=0;j<3;j++)
SetWindowText(HTEMP[i][j],"");

int i=1,x=day,y=1;
while(indt<=indext)
{
if(strcmp(teacherfile[indt].tch.name,abox)==0)
{
while(y<9)
{
if((((teacherfile[indt].tch.main[x][y][0])>=65)&&((teacherfile[indt].tch.main[x][y][0])<=90))||(((teacherfile[indt].tch.main[x][y][0])>=97)&&((teacherfile[indt].tch.main[x][y][0])<=122)))
{
SetWindowText(HTEMP[i][0],teacherfile[indt].tch.main[0][y]);
SetWindowText(HTEMP[i][1],teacherfile[indt].tch.main[x][y]);
fillarr(x,y,i);
i=i+1;
}
y=y+1;
}

}
indt++;
}

}

void creat_arrtbl(HWND hWnd)
{
    int indt=0;
    int m=0,k=0;
    destroy_window();
    HCOMB[1][0]=CreateWindowEx(WS_EX_TRANSPARENT,
                                "COMBOBOX",
                                "",
                                CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL|CBS_SORT|ES_CENTER,
                                100,
                                50,
                                150,
                                350,
                                hWnd,
                                (HMENU)IDC_ARRTT_ABOX,
                                GetModuleHandle(NULL),
                                NULL);

    for(int i=0;i<=8;i++)
        {
            for(int j=0;j<=2;j++)
                {
                    if (!HTEMP[i][j])
                        {
                            if(i==0)
                                {
                                    if(j==0)
                                        {
                                            HTEMP[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
                                            "STATIC",
                                            "Period",
                                            WS_CHILD|WS_VISIBLE|ES_CENTER,
                                            m+100,
                                            k+90,
                                            100,
                                            30,
                                            hWnd,
                                            NULL,
                                            GetModuleHandle(NULL),
                                            NULL);
                                        }
                                else if(j==1)
                                    {
                                        HTEMP[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
                                        "STATIC",
                                        "Class",
                                        WS_CHILD|WS_VISIBLE|ES_CENTER,
                                        m+100,
                                        k+90,
                                        100,
                                        30,
                                        hWnd,
                                        NULL,
                                        GetModuleHandle(NULL),
                                        NULL);
                                    }

                                else
                                    {
                                        HTEMP[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
                                        "STATIC",
                                        "Arrangement",
                                        WS_CHILD|WS_VISIBLE|ES_CENTER,
                                        m+100,
                                        k+90,
                                        100,
                                        30,
                                        hWnd,
                                        NULL,
                                        GetModuleHandle(NULL),
                                        NULL);
                                    }
                                }
                            else
                                {
                                    if(j!=2)
                                        {
                                            HTEMP[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
                                            "EDIT",
                                            "",
                                            WS_CHILD|WS_VISIBLE|ES_CENTER,
                                            m+100,
                                            k+90,
                                            70,
                                            30,
                                            hWnd,
                                            NULL,
                                            GetModuleHandle(NULL),
                                            NULL);
                                        }

                                    else
                                        {
                                            HTEMP[i][j]=CreateWindowEx(WS_EX_TRANSPARENT,
                                            "COMBOBOX",
                                            "",
                                            CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL|CBS_SORT,
                                            m+100,
                                            k+90,
                                            70,
                                            300,
                                            hWnd,
                                            NULL,
                                            GetModuleHandle(NULL),
                                            NULL);
                                        }
                                }
                            }m=m+100;
                        }    m=0;    k=k+40;
                    }


    if(!HTEMP[10][0])
        {
            HTEMP[10][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
            "BUTTON",
            "Create Arrangement Table",
            WS_TABSTOP|WS_VISIBLE|
            WS_CHILD|BS_DEFPUSHBUTTON,
            400,
            50,
            200,
            30,
            hWnd,
            (HMENU)ID_SAVE_ARR,
            GetModuleHandle(NULL),
            NULL);
        }

        k=0;

    while(indt<=indext)
        {
            if(k==0)
                {
                    strcpy(A,"Select Teacher ");
                    SendMessage(HCOMB[1][0],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)A));
                    SendMessage(HCOMB[1][0], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
                    k=1;
                }
            else
                {
                if((((teacherfile[indt].tch.name[0])>=65)&&((teacherfile[indt].tch.name[0])<=90))||(((teacherfile[indt].tch.name[0])>=97)&&((teacherfile[indt].tch.name[0])<=122)))
                    {
                        SendMessage(HCOMB[1][0],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)teacherfile[indt].tch.name));
                    }
                }

        indt++;
        }


}


void fill_ttt()
{
int indt=0;
while(indt<=indext)
{
if(strcmp(teacherfile[indt].tch.name,tbox)==0)
{
SetWindowText(hEdit[0][0],teacherfile[indt].tch.main[0][0]);

for(int i=1;i<=6;i++)
{

for(int j=1;j<=8;j++)
{
if(i==1)
{
SetWindowText(hEdit[0][j],teacherfile[indt].tch.main[0][j]);
}
SetWindowText(hEdit[i][j],teacherfile[indt].tch.main[i][j]);
SetWindowText(hEdit[i+6][j],teacherfile[indt].tch.info[i][j]);

}SetWindowText(hEdit[i][0],teacherfile[indt].tch.main[i][0]);

}
}
indt++;

}

}





void fill_cmtt()
{

int indrec=0;

while(indrec<=indexrec)
{
if(strcmp(rec[indrec].tchrec.tchname,cbox)==0)
{
for(int i=0;i<10;i++)
{
if(i==0)
SetWindowText(hinpt[1][i],rec[indrec].tchrec.tchname);
else
SetWindowText(hinpt[1][i],rec[indrec].tchrec.sbjname[i]);
}

}
indrec++;

}

}






void fill_ctt()
{

int indc=0;

while(indc<=indexc)
{
if(strcmp(classfile[indc].clas.name,cbox)==0)
{
SetWindowText(hEdit[0][0],classfile[indc].clas.main[0][0]);

for(int i=1;i<=6;i++)
{

for(int j=1;j<=8;j++)
{

if(i==1)
{
SetWindowText(hEdit[0][j],classfile[indc].clas.main[0][j]);
}

SetWindowText(hEdit[i][j],classfile[indc].clas.main[i][j]);
SetWindowText(hEdit[i+6][j],classfile[indc].clas.info[i][j]);

}
SetWindowText(hEdit[i][0],classfile[indc].clas.main[i][0]);
}
}
indc++;

}

}



void op_ttt(HWND hWnd)
{
int indt=0;
SendMessage(HCOMB[0][0],CB_RESETCONTENT,0,0);
destroy_window();

HCOMB[0][0]=CreateWindowEx(WS_EX_TRANSPARENT,
"COMBOBOX",
"",
CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL|CBS_SORT,
100,
50,
150,
350,
hWnd,
(HMENU)IDC_TECH_CBOX,
GetModuleHandle(NULL),
NULL);

int k=0;

SendMessage(HCOMB[0][0],CB_RESETCONTENT,0,0);
while(indt<=indext)
{
if(k==0)
{
strcpy(A,"Select Teacher");
SendMessage(HCOMB[0][0],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)A));
SendMessage(HCOMB[0][0], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
k=1;
}
else
{
if((((teacherfile[indt].tch.name[0])>=65)&&((teacherfile[indt].tch.name[0])<=90))||(((teacherfile[indt].tch.name[0])>=97)&&((teacherfile[indt].tch.name[0])<=122)))
{
SendMessage(HCOMB[0][0],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)teacherfile[indt].tch.name));
}
}

indt++;
}
tbl_p2(hWnd);
HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);
for(int i=7;i<=12;i++)
{
for(int j=0;j<=8;j++)
{
SendMessage(hEdit[i][j],
WM_SETFONT,
(WPARAM)hfDefault,
MAKELPARAM(FALSE,0));
}
}
}


void op_ctt(HWND hWnd)
{
int indc=0;
SendMessage(HCOMB[0][1],CB_RESETCONTENT,0,0);
destroy_window();
HCOMB[0][1]=CreateWindowEx(WS_EX_TRANSPARENT,
"COMBOBOX",
"",
CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL|CBS_SORT,
100,
50,
150,
350,
hWnd,
(HMENU)IDC_CLASS_CBOX,
GetModuleHandle(NULL),
NULL);

int k=0;

SendMessage(HCOMB[0][1],CB_RESETCONTENT,0,0);
while(indc<=indexc)
{
if(k==0)
{
strcpy(A,"Select class");
SendMessage(HCOMB[0][1],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)A));
SendMessage(HCOMB[0][1], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
k=1;
}
else
{
if((((classfile[indc].clas.name[0])>=65)&&((classfile[indc].clas.name[0])<=90))||(((classfile[indc].clas.name[0])>=97)&&((classfile[indc].clas.name[0])<=122)))
{
SendMessage(HCOMB[0][1],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)classfile[indc].clas.name));
}
}

indc++;
}
tbl_p2(hWnd);
HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);
for(int i=7;i<=12;i++)
{
for(int j=0;j<=8;j++)
{
SendMessage(hEdit[i][j],
WM_SETFONT,
(WPARAM)hfDefault,
MAKELPARAM(FALSE,0));
}
}

}


void settings(HWND hWnd)
{
destroy_window();
if(!hinpt[0][0])
{
hinpt[0][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"You May Change The Destination Of The Following Folders :",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
25,
25,
400,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[0][2])
{
hinpt[0][2]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"1.Teacher Time-Table :",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
25,
70,
150,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[0][3])
{
hinpt[0][3]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"2.Arrangement Table :",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
25,
115,
150,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[0][4])
{
hinpt[0][4]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"3.Class Time-Table :",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
25,
160,
150,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[0][5])
{
hinpt[0][5]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"4.Backup :",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
25,
205,
150,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[1][2])
{
hinpt[1][2]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
dir[2],
WS_VISIBLE|ES_CENTER|
WS_CHILD|ES_AUTOHSCROLL,
200,
70,
500,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[1][3])
{
hinpt[1][3]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
dir[3],
WS_VISIBLE|ES_CENTER|
WS_CHILD|ES_AUTOHSCROLL,
200,
115,
500,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[1][4])
{
hinpt[1][4]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
dir[4],
WS_VISIBLE|ES_CENTER|
WS_CHILD|ES_AUTOHSCROLL,
200,
160,
500,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[1][5])
{
hinpt[1][5]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
dir[5],
WS_VISIBLE|ES_CENTER|
WS_CHILD|ES_AUTOHSCROLL,
200,
205,
500,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[1][1])
{
hinpt[1][1]=CreateWindowEx(WS_EX_ACCEPTFILES,
"BUTTON",
"Reset To Default",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
430,
25,
120,
25,
hWnd,
(HMENU)ID_SETTING_RST,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[0][1])
{
hinpt[0][1]=CreateWindowEx(WS_EX_ACCEPTFILES,
"BUTTON",
"Save Changes",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
555,
25,
120,
25,
hWnd,
(HMENU)ID_SETTING_SAV,
GetModuleHandle(NULL),
NULL);
}
}

void creat_dir()
{
int a,b,c,d;
fstream fout;
strcpy(tmpname,dir[1]);
strcat(tmpname,"alldir.ttm");
fout.open(tmpname,ios::out|ios::binary);

a=CreateDirectory(dir[2],NULL);
if (a==0)
{
strcpy(tmpname,"Unable To Create ");
strcat(tmpname,dir[2]);
MessageBox(NULL,tmpname,"ERROR",MB_OK);
strcpy(dir[2],"C:\\Time-Table Manager\\Teacher Time-Table\\");
}
b=CreateDirectory(dir[3],NULL);
if (b==0)
{
strcpy(tmpname,"Unable To Create ");
strcat(tmpname,dir[3]);
MessageBox(NULL,tmpname,"ERROR",MB_OK);
strcpy(dir[3],"C:\\Time-Table Manager\\Arrangement Time-Table\\");
}
c=CreateDirectory(dir[4],NULL);
if (c==0)
{
strcpy(tmpname,"Unable To Create ");
strcat(tmpname,dir[4]);
MessageBox(NULL,tmpname,"ERROR",MB_OK);
strcpy(dir[4],"C:\\Time-Table Manager\\Class Time-Table\\");
}

d=CreateDirectory(dir[5],NULL);
if (d==0)
{
strcpy(tmpname,"Unable To Create ");
strcat(tmpname,dir[4]);
MessageBox(NULL,tmpname,"ERROR",MB_OK);
strcpy(dir[5],"C:\\Time-Table Manager\\TTM Database\\Backups\\");
}

for (int i=0;i<=5;i++)
{
fout<<dir[i]<<'\n';
}
fout.close();

MessageBox(NULL,"Error Causing Directory Resetted to Default","ERROR",MB_ICONERROR|MB_OK);


}



void alldir()
{
ofstream fout;

strcpy(dir[0],"C:\\Time-Table Manager\\");
CreateDirectory(dir[0],NULL);
strcpy(dir[1],"C:\\Time-Table Manager\\TTM Database\\");
CreateDirectory(dir[1],NULL);
strcpy(dir[2],"C:\\Time-Table Manager\\Teacher Time-Table\\");
CreateDirectory(dir[2],NULL);
strcpy(dir[3],"C:\\Time-Table Manager\\Arrangement Time-Table\\");
CreateDirectory(dir[3],NULL);
strcpy(dir[4],"C:\\Time-Table Manager\\Class Time-Table\\");
CreateDirectory(dir[4],NULL);
strcpy(dir[5],"C:\\Time-Table Manager\\TTM Database\\Backups\\");
CreateDirectory(dir[5],NULL);
fout.open("C:\\Time-Table Manager\\TTM Database\\alldir.ttm",ios::out|ios::binary);
for (int i=0;i<=5;i++)
{
fout<<dir[i]<<'\n';
}
fout.close();

}

void c_dir()
{

fstream fin,fout;

fin.open("C:\\Time-Table Manager\\TTM Database\\alldir.ttm",ios::in|ios::binary);
if(!fin)
{
fin.close();
alldir();
}
else
{
for(int i=0;i<=5;i++)
{
fin.getline(dir[i],100,'\n');
}
fin.close();
}
CreateDirectory(dir[2],NULL);
CreateDirectory(dir[3],NULL);
CreateDirectory(dir[4],NULL);
CreateDirectory(dir[5],NULL);

}


TABLE get_class()
{
int indc=0;
TABLE tbl;
while(indc<=indexc)
{
if(strcmp(classfile[indc].clas.name,clas.name)==0)
{
return classfile[indc].clas;
}
indc++;
}
return tbl;
}



void multisub(HWND hWnd)
{
int m=0,k=0;
int ms=233;
int mt=249;
int mi=265;

for(int i=0;i<=8;i++)
{
if(i==0)
{
hinpt[i][4]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"For Multiple Subjects In Single Period ( Optional )",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
800,
40,
390,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);

hinpt[i][5]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"Identifiers",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
1200,
40,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);


}
else
{
for(int j=5;j<=10;j++)
{
if(j==5)
{
if(i%2!=0)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"Static",
"Subjects:",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+800,
k+80,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(i%2==0)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"Static",
"Teachers:",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+800,
k+80,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
}

else
{
if(i%2==0)
{
if(j!=10)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"COMBOBOX",
"",
CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL,
m+800,
k+80,
70,
100,
hWnd,
(HMENU)mt,
GetModuleHandle(NULL),
NULL);
mt++;
}
}
else
{
if(j==10)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
clas.identifiers[mi-265],
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+800,
k+100,
70,
30,
hWnd,
(HMENU)mi,
GetModuleHandle(NULL),
NULL);
mi++;
}
else
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
clas.multi_sub[ms-233],
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+800,
k+80,
70,
30,
hWnd,
(HMENU)ms,
GetModuleHandle(NULL),
NULL);
ms++;

}
}
}




m=m+80;
}
k=k+40;
m=0;
}
}




}

void check()
{
int year=2019,month=7;
if((year==dte[2])||(month==dte[1]))
{
MessageBox(NULL,"Time Limit For Using This Product Has Been Crossed!!!...\nPlease Buy A New One...","INFORMATION....",MB_OK|MB_ICONEXCLAMATION);
exit(0);
}

MessageBox(NULL,"Loading Essential Files For TTM...\nThis May Take Few Seconds...\n\nPlease Wait.....","INFORMATION....",MB_OK|MB_ICONINFORMATION);
strcpy(chk2.universal_ttm_key,"ttm-9119-PawanAshutosh-#240509");
strcpy(chk2.ttm_product_key,"ttm-APSKGT-PawanAshutosh-#240509");
strcpy(version,"AP.001");

FILE *f1=NULL,*f2=NULL,*f3=NULL,*f4=NULL,*f5=NULL,*f6=NULL,*f7=NULL,*f8=NULL;
char temp[256];

f1=popen("wmic os get InstallDate ", "r");
fgets(temp, 80, f1);
fgets(chk2.install_date, 80, f1);
fclose(f1);

f2=popen("wmic path win32_computersystemproduct get uuid ", "r");
fgets(temp, 80, f2);
fgets(chk2.uuid, 80, f2);
fclose(f2);

f3=popen("wmic path softwarelicensingservice get OA3xOriginalProductKey ", "r");
fgets(temp, 80, f3);
fgets(chk2.oa3x_original_product_key, 80, f3);
fclose(f3);

f4=popen("wmic os get serialnumber ", "r");
fgets(temp, 80, f4);
fgets(chk2.os_product_key, 80, f4);
fclose(f4);

f5=popen("wmic computersystem get Name ", "r");
fgets(temp, 80, f5);
fgets(chk2.name, 80, f5);
fclose(f5);

f6=popen("wmic bios get serialnumber ", "r");
fgets(temp, 80, f6);
fgets(chk2.bios_serial_number, 80, f6);
fclose(f6);

f7=popen("wmic baseboard get serialnumber ", "r");
fgets(temp, 80, f7);
fgets(chk2.baseboard_serial_number, 80, f7);
fclose(f7);

f8=popen("wmic diskdrive get serialnumber ", "r");
fgets(temp, 80, f8);
fgets(chk2.volume_serial_number, 80, f8);
fclose(f8);

ifstream fin;
ofstream fout;
//  DWORD serial;
//      MessageBox(NULL,"Some File Missing!!!\nUnable To Proceed Further..Closing TTM..","Error!!!",MB_OK|MB_ICONERROR);


//GetVolumeInformation("C:\\",NULL,0,&serial,NULL,NULL,NULL,0);


dn();

if(chk.a[0]!=9||chk.a[7]!=1||chk.a[3]!=1||chk.a[9]!=9)
{
MessageBox(NULL,"ORIGINALITY OF CONFIG FILE HAS BEEN CHANGED\nCLOSING!!!","ERROR!!!!!!!",MB_OK|MB_ICONERROR);
exit(0);
}
if(strcmp(chk.user_ttm_product_key,chk2.universal_ttm_key)==0)
{
return;
}

else if(strcmp(chk.user_ttm_product_key,chk2.ttm_product_key)!=0)
{
MessageBox(NULL,"You Can Use TTM Only 3 Times Without The Product Key\nGoto Options>Enter The Product Key .. and Save The Key Otherwise This Product Will Be Like A Garbage!!!","ALERT!!!",MB_OK|MB_ICONHAND);

if( (chk.aab[9][1][1]=='1')&&(chk.aab[1][0][7]=='1')&&(chk.aab[7][3][9]=='1'))
{
MessageBox(NULL,"You Have Used TTM 3 Times Without The Product Key..\nNow Buy A New One...","ALERT!!!",MB_OK|MB_ICONHAND);
exit(0);
}

if(chk.aab[9][1][1]!='1')
{
chk.aab[9][1][1]='1';
}
else if (chk.aab[1][0][7]!='1')
{
chk.aab[1][0][7]='1';
}
else if (chk.aab[7][3][9]!='1')
{
chk.aab[7][3][9]='1';
}


}



else
{

dn();

if(strcmp(chk.install_date,chk2.install_date)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"INSD","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.uuid,chk2.uuid)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"UD","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.oa3x_original_product_key,chk2.oa3x_original_product_key)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"OOPK","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.os_product_key,chk2.os_product_key)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"OSPK","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.name,chk2.name)!=0)
{
MessageBox(NULL,"Note : It Seems System Name To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"NAME","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.baseboard_serial_number,chk2.baseboard_serial_number)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"BSSN","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.bios_serial_number,chk2.bios_serial_number)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"BOSN","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}
if(strcmp(chk.volume_serial_number,chk2.volume_serial_number)!=0)
{
MessageBox(NULL,"Note : TTM Syncs Its Data With The System During The First Run..\nSystem Seems To Be Changed!!!\n Unable To Proceed Further ..\n Closing TTM","ERROR!!!",MB_OK|MB_ICONERROR);
MessageBox(NULL,"VOSN","ERROR CODE!!!",MB_OK|MB_ICONINFORMATION);
exit(0);
}

}

en();


}




void save_product_key2()
{


strcpy(chk.install_date,chk2.install_date);

strcpy(chk.uuid,chk2.uuid);

strcpy(chk.oa3x_original_product_key,chk2.oa3x_original_product_key);

strcpy(chk.os_product_key,chk2.os_product_key);

strcpy(chk.name,chk2.name);

strcpy(chk.baseboard_serial_number,chk2.baseboard_serial_number);

strcpy(chk.bios_serial_number,chk2.bios_serial_number);

strcpy(chk.volume_serial_number,chk2.volume_serial_number);
en();

destroy_window();
MessageBox(NULL,"DONE...\nHave a Great Experience...","Congratulations",MB_OK|MB_ICONINFORMATION);
}





void save_product_key(HWND hWnd)
{
if(!hinpt[1][3])
{
hinpt[1][3]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_VISIBLE|ES_CENTER|
WS_CHILD|ES_AUTOHSCROLL,
200,
115,
500,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[0][3])
{
hinpt[0][3]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"ENTER THE PRODUCT KEY :",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
200,
80,
500,
25,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(!hinpt[0][1])
{
hinpt[0][1]=CreateWindowEx(WS_EX_ACCEPTFILES,
"BUTTON",
"Save ",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
555,
25,
120,
25,
hWnd,
(HMENU)ID_PRODUCT_KEY_SAV,
GetModuleHandle(NULL),
NULL);
}


}


void load_data()
{
    c_dir();
    indexc=1;
    indexrec=1;
    indext=1;
    indexarr=1;
    clas=blank;

    ifstream fin;
    strcpy(tmpname,dir[1]);

    strcat(tmpname,"Cls.ttm");
    fin.open(tmpname,ios::in|ios::binary);
    if(fin.good())
    {
        while(!fin.eof())
        {
            fin.read((char*)&classfile[indexc].clas,sizeof(classfile[indexc].clas));
            if((((classfile[indexc].clas.name[0])>=65)&&((classfile[indexc].clas.name[0])<=90))||(((classfile[indexc].clas.name[0])>=97)&&((classfile[indexc].clas.name[0])<=122)))
            {
                indexc++;
            }
        }
    }
    fin.close();



    strcpy(tmpname,dir[1]);
    strcat(tmpname,"Tch.ttm");
    fin.open(tmpname,ios::in|ios::binary);
    if(fin.good())
    {
        while(!fin.eof())
        {
            fin.read((char*)&teacherfile[indext].tch,sizeof(teacherfile[indext].tch));
            if((((teacherfile[indext].tch.name[0])>=65)&&((teacherfile[indext].tch.name[0])<=90))||(((teacherfile[indext].tch.name[0])>=97)&&((teacherfile[indext].tch.name[0])<=122)))
            {
                indext++;
            }
        }
    }
    fin.close();


    strcpy(tmpname,dir[1]);
    strcat(tmpname,"arr.ttm");
    fin.open(tmpname,ios::in|ios::binary);
    if(fin.good())
    {
        while(!fin.eof())
        {
            fin.read((char*)&tarr[indexarr],sizeof(tarr[indexarr]));
            if(((tarr[indexarr].date[0])>=48)&&((tarr[indexarr].date[0])>=57))
            {
                indexarr++;
            }
        }
    }
    fin.close();



    strcpy(tmpname,dir[1]);
    strcat(tmpname,"rec.ttm");
    fin.open(tmpname,ios::out|ios::binary);
    if(fin.good())
    {
        while(!fin.eof())
        {
            fin.read((char*)&rec[indexrec].tchrec,sizeof(rec[indexrec].tchrec));
            if((((rec[indexrec].tchrec.tchname[0])>=65)&&((rec[indexrec].tchrec.tchname[0])<=90))||(((rec[indexrec].tchrec.tchname[0])>=97)&&((rec[indexrec].tchrec.tchname[0])<=122)))
            {
                indexrec++;
            }
        }
    }
    fin.close();


}



void teacher_table(int x,int y)
{
char tmpname3[200];
int flag=0,indc=0,indt=0,i2=0;
char fname[10],n[15];
strcpy(fname,clas.info[x][y]);

while(indt<=indext)
{
if(strcmp(teacherfile[indt].tch.name,fname)==0)
{
if((((teacherfile[indt].tch.name[0])>=65)&&((teacherfile[indt].tch.name[0])<=90))||(((teacherfile[indt].tch.name[0])>=97)&&((teacherfile[indt].tch.name[0])<=122)))
{
if((((teacherfile[indt].tch.main[x][y][0])>=65)&&((teacherfile[indt].tch.main[x][y][0])<=90))||(((teacherfile[indt].tch.main[x][y][0])>=97)&&((teacherfile[indt].tch.main[x][y][0])<=122)))
{

if(strcmp(teacherfile[indt].tch.main[x][y],clas.name)==0)
{
return;
}

else
{

if((strcmp(A,clas.info[x][y])!=0)||(xpos!=x)||(ypos!=y))
{
xpos=x,ypos=y;
strcpy(A,clas.info[x][y]);

strcpy(tmpname3,"");
strcpy(tmpname3,"Teacher ");
strcat(tmpname3,fname);
strcat(tmpname3," is busy in class ");
strcat(tmpname3,teacherfile[indt].tch.main[x][y]);
strcat(tmpname3,".\nDo you want to Keep both...");
int rslt=MessageBox(NULL,tmpname3,"Alert!!!",MB_ICONERROR|MB_YESNO);

switch(rslt)
{
case IDYES:
{

strcat(teacherfile[indt].tch.main[x][y],"/");
strcat(teacherfile[indt].tch.main[x][y],clas.name);

}break;

case IDNO:
{
rslt=MessageBox(NULL,"Do you want to Replace it??","Alert!!!",MB_ICONERROR|MB_YESNO);
switch(rslt)
{
case IDYES:
{
while(indc<=indexc)
{
if(strcmp(teacherfile[indt].tch.main[x][y],classfile[indc].clas.name)==0)
{
while(i2!=indext)
{
for (int k=0;k<16;k++)
{
if(strcmp(classfile[indc].clas.multi_tch[k],teacherfile[i2].tch.name)==0);
{
strcpy(teacherfile[i2].tch.main[x][y],"\0");
strcpy(teacherfile[i2].tch.info[x][y],"\0");
}
}
i2++;
}
strcpy(classfile[indc].clas.main[x][y],"\0");
strcpy(classfile[indc].clas.info[x][y],"\0");
}

indc++;
}
strcpy(teacherfile[indt].tch.main[x][y],clas.name);
strcpy(teacherfile[indt].tch.info[x][y],clas.main[x][y]);
for(int i=0;i<5;i++)
{
if(strcmp(clas.main[x][y],clas.identifiers[i])==0)
{
strcpy(teacherfile[indt].tch.info[x][y],sh);
}
}

}break;

case IDNO:
{
SetWindowText(hEdit[x][y],'\0');
SendMessage(hEdit[x+6][y],CB_RESETCONTENT,0,0);
}break;

}
}break;

}

}
}
}
else
{
strcpy(teacherfile[indt].tch.main[x][y],clas.name);
strcpy(teacherfile[indt].tch.info[x][y],clas.main[x][y]);
for(int i=0;i<5;i++)
{
if(strcmp(clas.main[x][y],clas.identifiers[i])==0)
{
strcpy(teacherfile[indt].tch.info[x][y],sh);
}
}
}
}
flag=1;


}

indt++;
}
indt=0;
int f=0;



if(flag==0)
{
indext=indext+1;
teacherfile[indext].tch=tchr;
strcpy(teacherfile[indext].tch.name,clas.info[x][y]);
strcpy(teacherfile[indext].tch.main[x][y],clas.name);
strcpy(teacherfile[indext].tch.info[x][y],clas.main[x][y]);

}

}


void m_sub_fill(int x,int y,int i)
{
int m=0;

if (i==0)
m=0;

if (i==1)
m=4;

if (i==2)
m=8;

if (i==3)
m=12;
strcpy(tmpname,"");
strcpy(tmpname2,"");

if((((clas.multi_sub[m][0])>=65)&&((clas.multi_sub[m][0])<=90))||(((clas.multi_sub[m][0])>=97)&&((clas.multi_sub[m][0])<=122)))
{
strcpy(tmpname,clas.multi_sub[m]);
strcpy(sh,clas.multi_sub[m]);
strcpy(tmpname2,clas.multi_tch[m]);
strcpy(clas.info[x][y],clas.multi_tch[m]);
teacher_table(x,y);
}

if((((clas.multi_sub[m+1][0])>=65)&&((clas.multi_sub[m+1][0])<=90))||(((clas.multi_sub[m+1][0])>=97)&&((clas.multi_sub[m+1][0])<=122)))
{
if((((clas.multi_sub[m][0])>=65)&&((clas.multi_sub[m][0])<=90))||(((clas.multi_sub[m][0])>=97)&&((clas.multi_sub[m][0])<=122)))
{
strcat(tmpname,"/");
strcat(tmpname2,"/");
}
strcat(tmpname,clas.multi_sub[m+1]);
strcpy(sh,clas.multi_sub[m+1]);
strcat(tmpname2,clas.multi_tch[m+1]);
strcpy(clas.info[x][y],clas.multi_tch[m+1]);
teacher_table(x,y);
}

if((((clas.multi_sub[m+2][0])>=65)&&((clas.multi_sub[m+2][0])<=90))||(((clas.multi_sub[m+2][0])>=97)&&((clas.multi_sub[m+2][0])<=122)))
{
if((((clas.multi_sub[m+1][0])>=65)&&((clas.multi_sub[m+1][0])<=90))||(((clas.multi_sub[m+1][0])>=97)&&((clas.multi_sub[m+1][0])<=122)))
{
strcat(tmpname,"/");
strcat(tmpname2,"/");
}
strcat(tmpname,clas.multi_sub[m+2]);
strcpy(sh,clas.multi_sub[m+2]);
strcat(tmpname2,clas.multi_tch[m+2]);
strcpy(clas.info[x][y],clas.multi_tch[m+2]);
teacher_table(x,y);
}

if((((clas.multi_sub[m+3][0])>=65)&&((clas.multi_sub[m+3][0])<=90))||(((clas.multi_sub[m+3][0])>=97)&&((clas.multi_sub[m+3][0])<=122)))
{
if((((clas.multi_sub[m+2][0])>=65)&&((clas.multi_sub[m+2][0])<=90))||(((clas.multi_sub[m+2][0])>=97)&&((clas.multi_sub[m+2][0])<=122)))
{
strcat(tmpname,"/");
strcat(tmpname2,"/");
}
strcat(tmpname,clas.multi_sub[m+3]);
strcpy(sh,clas.multi_sub[m+3]);
strcat(tmpname2,clas.multi_tch[m+3]);
strcpy(clas.info[x][y],clas.multi_tch[m+3]);
teacher_table(x,y);
}

strcpy(sh,"");
strcpy(clas.sbjexp[i],tmpname);
strcpy(clas.info[x][y],tmpname2);
strcpy(clas.sbjexpinfo[i],tmpname2);
SendMessage(hEdit[x+6][y], CB_RESETCONTENT, 0,0);
SendMessage(hEdit[x+6][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)tmpname2));
SendMessage(hEdit[x+6][y], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
SetWindowText(hEdit[x][y],clas.sbjexp[i]);
strcpy(clas.main[x][y],clas.sbjexp[i]);



}


void get_tch(int x ,int y)
{
int flag=0,indrec=0,indc=0;


if((strcmp(A,clas.main[x][y])!=0)||(xpos!=x)||(ypos!=y))
{

xpos=x,ypos=y;
strcpy(A,clas.main[x][y]);
SendMessage(hEdit[x+6][y],CB_RESETCONTENT,0,0);

SendMessage(hEdit[x+6][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)" "));
SendMessage(hEdit[x+6][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)clas.info[x][y]));
SendMessage(hEdit[x+6][y], CB_SETCURSEL, (WPARAM)1, (LPARAM)0);


for(int i=0;i<4;i++)
{
if(strcmp(A,clas.identifiers[i])==0)
{
m_sub_fill(x,y,i);
return ;
}
}

while(indrec<=indexrec)
{
for(int i=0;i<10;i++)
{
if(strcmp(A,rec[indrec].tchrec.sbjname[i])==0)
{
if(strcmp(clas.info[x][y],rec[indrec].tchrec.tchname)!=0)
{
SendMessage(hEdit[x+6][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)rec[indrec].tchrec.tchname));
}
}
}
indrec++;
}


}
}




void get_tch2(int x ,int y,int z)
{
int flag=0,indrec=0,indc=0;

if((strcmp(A,clas.multi_sub[z])!=0)||(xpos!=x)||(ypos!=y))
{

xpos=x,ypos=y;
strcpy(A,clas.multi_sub[z]);
SendMessage(hinpt[x+1][y],CB_RESETCONTENT,0,0);


SendMessage(hinpt[x+1][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)" "));
SendMessage(hinpt[x+1][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)clas.multi_tch[z]));

while(indrec<=indexrec)
{
for(int i=0;i<10;i++)
{
if(strcmp(A,rec[indrec].tchrec.sbjname[i])==0)
{
if(strcmp(clas.multi_tch[z],rec[indrec].tchrec.tchname)!=0)
{
SendMessage(hinpt[x+1][y],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)rec[indrec].tchrec.tchname));
}
}
}
indrec++;
}

SendMessage(hinpt[x+1][y], CB_SETCURSEL, (WPARAM)1, (LPARAM)0);
}


}



void destroy_window()
{

for (int i=0;i<14;i++)
{
for (int j=0;j<14;j++)
{
if (hEdit[i][j])
{
DestroyWindow(hEdit[i][j]);
hEdit[i][j]=NULL;
}

}
}

for (int i=0;i<30;i++)
{
for (int j=0;j<20;j++)
{
if (hinpt[i][j])
{
DestroyWindow(hinpt[i][j]);
hinpt[i][j]=NULL;
}
}
}

for (int i=0;i<20;i++)
{
for (int j=0;j<20;j++)
{ if(HTEMP[i][j])
{
DestroyWindow(HTEMP[i][j]);
HTEMP[i][j]=NULL;
}
}
}
DestroyWindow(HCOMB[1][0]);
DestroyWindow(HCOMB[0][0]);
DestroyWindow(HCOMB[0][1]);
HCOMB[1][0]=NULL;
HCOMB[0][0]=NULL;
HCOMB[0][1]=NULL;

}


void savetbl()
{
    int indt=0,indc=0;
    ofstream fout;
    char fname[90],fname2[100],fn[90];

    strcpy(fname,dir[4]);
    strcat(fname,clas.name);
    strcat(fname,".xls");

    fout.open(fname,ios::out);

    for (int i=0;i<=6;i++)
    {
        for (int j=0;j<=8;j++)
        {
            fout<<clas.main[i][j]<<"\t";
        }
    fout<<endl;
        if (i!=0)
        {
            for (int j=1;j<=8;j++)
            {
                fout<<"\t"<<clas.info[i][j];
            }
            fout<<endl;
        }
    }

    fout.close();

    int ff=0;
    while(indt<=indext)
    {
        for(int i=1;i<7;i++)
        {
            for(int j=1;j<9;j++)
            {
                if(strcmp(teacherfile[indt].tch.main[i][j],clas.name)==0)
                {
                    if(((strcmp(teacherfile[indt].tch.name,clas.info[i][j])!=0)||(strcmp(teacherfile[indt].tch.info[i][j],clas.main[i][j])!=0))&&((strcmp(clas.main[i][j],clas.sbjexp[0])!=0)&&(strcmp(clas.main[i][j],clas.sbjexp[1])!=0)&&(strcmp(clas.main[i][j],clas.sbjexp[2])!=0)&&(strcmp(clas.main[i][j],clas.sbjexp[3])!=0)))
                    {
                        strcpy(teacherfile[indt].tch.main[i][j],"");
                        strcpy(teacherfile[indt].tch.info[i][j],"");
                    }
                }
            }
        }
            indt++;
    }

    indt=0;
    ofstream fout2;
    strcpy(tmpname,dir[1]);
    strcat(tmpname,"Tch.ttm");
    fout2.open(tmpname,ios::out|ios::binary);

    while(indt<=indext)
    {
        strcpy(fn,"\0");
        strcpy(fn,dir[2]);

        strcat(fn,teacherfile[indt].tch.name);
        strcat(fn,".xls");
        fout.open(fn,ios::out);
        for (int i=0;i<=6;i++)
        {
            for (int j=0;j<=8;j++)
            {
                fout<<teacherfile[indt].tch.main[i][j]<<"\t";
            } fout<<endl;

            if (i!=0)
            {
                for (int j=1;j<=8;j++)
                {
                    fout<<"\t"<<teacherfile[indt].tch.info[i][j];
                }
                 fout<<endl;
            }
        }

        fout2.write((char*)&teacherfile[indt].tch,sizeof(teacherfile[indt].tch));

        fout.close();
        indt++;
    }
        fout2.close();



    strcpy(tmpname,dir[1]);
    strcat(tmpname,"Cls.ttm");
    fout.open(tmpname,ios::out|ios::binary);
    indc=0;
    int flag=0;
    while(indc<=indexc)
    {
        if(strcmp(classfile[indc].clas.name,clas.name)==0)
        {
            classfile[indc].clas=clas;
            flag=1;
        }

        fout.write((char*)&classfile[indc].clas,sizeof(classfile[indc].clas));
        indc++;
    }
    if(flag==0)
    {
        fout.write((char*)&clas,sizeof(clas));
    }
    fout.close();

    MessageBox(NULL,"DONE","INFO!!!",MB_ICONINFORMATION|MB_OK);



}

void input2(HWND hWnd)
{
destroy_window();
creat_tbl(hWnd);

}




void input(HWND hWnd)
{

if(!hinpt[0][0])
{			hinpt[0][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"ENTER CLASS AND SECTION",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
60,
500,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}



if(!hinpt[0][1])
{

hinpt[0][1]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_CENTER,
600,
60,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}


if(!hinpt[0][8])
{
hinpt[0][8]=CreateWindowEx(WS_EX_CLIENTEDGE,
"BUTTON",
"SUBMIT",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
500,
220,
70,
30,
hWnd,
(HMENU)ID_N_SUB_Buttom,
GetModuleHandle(NULL),
NULL);
}
}












void cr_rec_save()
{

fstream fout;
strcpy(tmpname,dir[1]);
strcat(tmpname,"rec.ttm");
fout.open(tmpname,ios::out|ios::binary);
for(int i=1;i<15;i++)
{

if((((rec[indexrec].tchrec.tchname[0])>=65)&&((rec[indexrec].tchrec.tchname[0])<=90))||(((rec[indexrec].tchrec.tchname[0])>=97)&&((rec[indexrec].tchrec.tchname[0])<=122)))
{
indexrec=indexrec+1;
}

for(int j=0;j<10;j++)
{
if(j==0)
{
GetWindowText(hinpt[i][j],rec[indexrec].tchrec.tchname,20);
}
else
GetWindowText(hinpt[i][j],rec[indexrec].tchrec.sbjname[j],20);
}


}
int c=1;
for(int i=indexrec;i>=1;i--)
{

while(c<=indexrec)
{
if(i!=c)
{
if(strcmp(rec[c].tchrec.tchname,rec[i].tchrec.tchname)==0)
{
rec[c].tchrec=blank2;
}
}
c++;

}
c=1;
}

for(int i=1;i<=indexrec;i++)
{

fout.write((char*)&rec[i].tchrec,sizeof(rec[i].tchrec));
}
fout.close();
MessageBox(NULL,"DONE","INFO",MB_OK);
}





void mod_save()
{
int indrec=0;


fstream fout;
strcpy(tmpname,dir[1]);
strcat(tmpname,"rec.ttm");
fout.open(tmpname,ios::out|ios::binary);


while(indrec<=indexrec)
{
if(strcmp(rec[indrec].tchrec.tchname,cbox)==0)
{
for(int i=1;i<10;i++)
{
if(i==0)
{
GetWindowText(hinpt[1][i],rec[indrec].tchrec.tchname,20);
}
else
GetWindowText(hinpt[1][i],rec[indrec].tchrec.sbjname[i],20);

}
}
indrec++;
}



for(int i=1;i<=indexrec;i++)
{

fout.write((char*)&rec[i].tchrec,sizeof(rec[i].tchrec));
}
fout.close();
MessageBox(NULL,"DONE","INFO",MB_OK);
}













void cr_rec(HWND hWnd)
{
destroy_window();
char n;
int m=0,k=0;
for(int i=0;i<15;i++)
{
for(int j=0;j<10;j++)
{
if (!hinpt[i][j])
{
if(i==0)
{

if(j==0)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"Teacher Name",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+100,
k+50,
100,
40,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
else
{
strcpy(A,"Subject ");
n='0'+j;
A[8]=n;
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
A,
WS_CHILD|WS_VISIBLE|ES_CENTER,
m+100,
k+50,
100,
40,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

}
else
{

hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+100,
k+50,
100,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);


}
}
m=m+100;  }
m=0;
k=k+40;  }

hinpt[15][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"BUTTON",
"SAVE",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
10,
100,
30,
hWnd,
(HMENU)ID_CR_SAVE,
GetModuleHandle(NULL),
NULL);

}


void mod_rec(HWND hWnd)
{
destroy_window();
load_data();
char n;
int m=0,k=50;
int indrec=0;
SendMessage(HCOMB[0][0],CB_RESETCONTENT,0,0);
destroy_window();

HCOMB[0][0]=CreateWindowEx(WS_EX_TRANSPARENT,
"COMBOBOX",
"",
CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL|CBS_SORT,
100,
50,
150,
350,
hWnd,
(HMENU)ID_MODIFY,
GetModuleHandle(NULL),
NULL);

int kl=0;

SendMessage(HCOMB[0][0],CB_RESETCONTENT,0,0);
while(indrec<=indexrec)
{
if(kl==0)
{
strcpy(A,"Select Teacher");
SendMessage(HCOMB[0][0],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)A));
SendMessage(HCOMB[0][0], CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
kl=1;
}
else
{
if((((rec[indrec].tchrec.tchname[0])>=65)&&((rec[indrec].tchrec.tchname[0])<=90))||(((rec[indrec].tchrec.tchname[0])>=97)&&((rec[indrec].tchrec.tchname[0])<=122)))
{
SendMessage(HCOMB[0][0],CB_ADDSTRING,0,reinterpret_cast<LPARAM>((LPCTSTR)rec[indrec].tchrec.tchname));
}
}

indrec++;
}

for(int i=0;i<=1;i++)
{
for(int j=0;j<10;j++)
{
if (!hinpt[i][j])
{
if(i==0)
{

if(j==0)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"Teacher Name",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+100,
k+50,
100,
40,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
else
{
strcpy(A,"\0");
strcpy(A,"Subject  ");

n='0'+j;
A[8]=n;

hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
A,
WS_CHILD|WS_VISIBLE|ES_CENTER,
m+100,
k+50,
100,
40,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

}
else
{

hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+100,
k+50,
100,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);


}
}
m=m+100;  }
m=0;
k=k+40;  }

hinpt[15][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"BUTTON",
"UPDATE",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
10,
100,
30,
hWnd,
(HMENU)ID_UP_REC,
GetModuleHandle(NULL),
NULL);

}


void del_rec()
{/*
destroy_window();
char n;
int m=0,k=0;
for(int i=0;i<15;i++)
{
for(int j=0;j<10;j++)
{
if (!hinpt[i][j])
{
if(i==0)
{

if(j==0)
{
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"Teacher Name",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+100,
k+50,
100,
40,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
else
{
strcpy(A,"Subject ");
n='0'+j;
A[8]=n;
hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
A,
WS_CHILD|WS_VISIBLE|ES_CENTER,
m+100,
k+50,
100,
40,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

}
else
{

hinpt[i][j]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
m+100,
k+50,
100,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);


}
}
m=m+100;  }
m=0;
k=k+40;  }

hinpt[15][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"BUTTON",
"DELETE",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
10,
100,
30,
hWnd,
(HMENU)ID_DELE,
GetModuleHandle(NULL),
NULL);

*/
}


void menu(HWND hWnd)
{
dn();
HMENU hMenu, hSubMenu;

hMenu = CreateMenu();

hSubMenu = CreatePopupMenu();
AppendMenu(hSubMenu, MF_STRING,ID_CREAT_TT, "Class Time-Table");//IDM_APP_ABOUT
//AppendMenu(hSubMenu, MF_STRING,IDM_APP_ABOUT, "Class Time-Table");//IDM_APP_ABOUT
AppendMenu(hSubMenu, MF_STRING, ID_CREAT_AT, "Arrangement-Table");
AppendMenu(hSubMenu, MF_STRING, ID_CR_REC, "Teacher Record");
AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Create");


hSubMenu = CreatePopupMenu();
AppendMenu(hSubMenu, MF_STRING, ID_OPEN_TT, "Class Time-Table");
AppendMenu(hSubMenu, MF_STRING, ID_OPEN_TTT, "Teacher Time-Table");
AppendMenu(hSubMenu, MF_STRING, ID_OPEN_AT, "Arrangement-Table");
AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Open");


hSubMenu = CreatePopupMenu();
AppendMenu(hSubMenu, MF_STRING, ID_CLEAR_SRC, "Refresh");
AppendMenu(hSubMenu, MF_STRING, ID_CR_BACKUP, "Create Backup");
AppendMenu(hSubMenu, MF_STRING, ID_RS_BACKUP, "Restore Backup");
AppendMenu(hSubMenu, MF_STRING, ID_DELETE, "Delete ");
AppendMenu(hSubMenu, MF_STRING, ID_MOD_REC, "Modify Teacher Record");
AppendMenu(hSubMenu, MF_STRING, ID_SETTING, "Settings");
if(strcmp(chk.user_ttm_product_key,chk2.ttm_product_key)!=0)
{
AppendMenu(hSubMenu, MF_STRING, ID_PRODUCT_KEY, "Enter The Product Key");
}
if(strcmp(chk.user_ttm_product_key,chk2.universal_ttm_key)==0)
{
AppendMenu(hSubMenu, MF_STRING, ID_PRODUCT_KEY_UNI, "Remove Universal Product Key");
}
AppendMenu(hSubMenu, MF_STRING, ID_FILE_EXIT, "Exit");
AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Options");


hSubMenu = CreatePopupMenu();
AppendMenu(hSubMenu, MF_STRING, ID_TC_TTM, "T&&C");
AppendMenu(hSubMenu, MF_STRING, ID_INS_TTM, "Instruction");
AppendMenu(hSubMenu, MF_STRING, ID_CONTACT, "Contact");
AppendMenu(hSubMenu, MF_STRING, ID_ABOUT_TTM, "About TTM");
AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Help");


SetMenu(hWnd, hMenu);
en();

}


void statictext()
{   HGDIOBJ hfDefault=GetStockObject(DEFAULT_GUI_FONT);
for(int i=7;i<=12;i++)
{
for(int j=0;j<=8;j++)
{
SendMessage(hEdit[i][j],
WM_SETFONT,
(WPARAM)hfDefault,
MAKELPARAM(FALSE,0));
}
}


strcpy(clas.main[0][0],"P/DAY");
strcpy(clas.main[0][1],"I");
strcpy(clas.main[0][2],"II");
strcpy(clas.main[0][3],"III");
strcpy(clas.main[0][4],"IV");
strcpy(clas.main[0][5],"V");
strcpy(clas.main[0][6],"VI");
strcpy(clas.main[0][7],"VII");
strcpy(clas.main[0][8],"VIII");
strcpy(clas.main[1][0],"MON");
strcpy(clas.main[2][0],"TUE");
strcpy(clas.main[3][0],"WED");
strcpy(clas.main[4][0],"THU");
strcpy(clas.main[5][0],"FRI");
strcpy(clas.main[6][0],"SAT");
for (int i=0;i<2;i++)
{
if (i==0)
{
for (int j=0;j<=8;j++)
{
strcpy(tchr.main[0][j],clas.main[0][j]);
}
}
if ( i==1)
{
for ( int j=1;j<=6;j++)
{
strcpy(tchr.main[j][0],clas.main[j][0]);
}
}
}

int m=1;
for(int i=0;i<=1;i++)
{
for (int j=0;j<=8;j++)
{

if(i==0)
{
if(hEdit[i][j])
SetWindowText(hEdit[i][j],clas.main[i][j]);
}
else
if(hEdit[j+m][0])
SetWindowText(hEdit[j+m][0],clas.main[j+m][0]);

}
}

SetWindowText(hinpt[0][1],clas.name);

for(int i=1;i<=6;i++)
{

for(int j=1;j<=8;j++)
{
SetWindowText(hEdit[i][j],clas.main[i][j]);
}

}




}


void tbl_p2(HWND hWnd)
{

for (int i=0,l=0;i<=360,l<=6;i=i+60,l=l+1)
{
for (int j=0,k=0;j<=560,k<=8;j=j+70,k=k+1)
{   if (i==0)
{
i=30;
}
if(!hEdit[l][k])
{
hEdit[l][k]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_CENTER|ES_AUTOHSCROLL,
j+100,
i+50,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

if(i==30){i=0;}
}
}



for (int i=90,l=7;i<=390,l<=12;i=i+60,l=l+1)
{
for (int j=70 , k=1;j<=560,k<=8;j=j+70,k=k+1)
{  if(!hEdit[l][k])
{
hEdit[l][k]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_CENTER|ES_AUTOHSCROLL,
j+100,
i+50,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

}
}




}




void creat_tbl_p2(HWND hWnd)
{


int m=101;

for (int i=0,l=0;i<=360,l<=6;i=i+60,l=l+1)
{
for (int j=0,k=0;j<=560,k<=8;j=j+70,k=k+1)
{   if (i==0)
{
i=30;
}
if(!hEdit[l][k])
{
hEdit[l][k]=CreateWindowEx(WS_EX_CLIENTEDGE,
"EDIT",
"",
WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|ES_CENTER,
j+100,
i+50,
70,
30,
hWnd,
(HMENU)m,
GetModuleHandle(NULL),
NULL);
}

m=m+1;
if(i==30){i=0;}
}
}

m=164;
for (int i=90,l=7;i<=390,l<=12;i=i+60,l=l+1)
{
for (int j=70 , k=1;j<=560,k<=8;j=j+70,k=k+1)
{
if(!hEdit[l][k])
{
hEdit[l][k]=CreateWindowEx(WS_EX_CLIENTEDGE,
"COMBOBOX",
"",
CBS_DROPDOWNLIST|WS_VISIBLE|WS_CHILD|CBS_AUTOHSCROLL,
j+100,
i+50,
70,
100,
hWnd,
(HMENU)m,
GetModuleHandle(NULL),
NULL);



}

m=m+1;
}
}



}

void create_readme()
{
ofstream fout;
fout.open("ReadMe.txt",ios::out);
fout<<"********************Points To Remember********************\n";
fout<<"\n------ IMPORTANT NOTES ------\n";
fout<<"1.All Saved Files Are In \" C:\\Time-Table Manager \" Folder.\n";
fout<<"2.Do Not Try To Open Any .ttm File . This May Corrupt Your Product.\n";
fout<<"3.\"Config.ttm\" Is Necessary For TTM To Work . So Keep That File In The Folder Where You Have Saved This TTM Product.\n";
fout<<"4.Do Not Even Try To Pirate This Product.\n";
fout<<"5.You Can Use This Product Only 3 Times Without The PRODUCT KEY.\n";
fout<<"6.You Have Only Two Chances To Enter The Product Key(Goto OPTIONS->ENTER THE PRODUCT KEY).\n\n";
fout<<"\n------ HOW TO OPERATE ------\n";

fout<<"*CREATING CLASS TIME-TABLES : \n";
fout<<"1.Firstly Create Teacher's Record (Goto CREATE->TEACHER RECORD ).\n";
fout<<"2.In Teacher Record Type The Name Of The Teacher And Then Different Subject's Name He/She Can Teach In Cells Following It.Then Click SAVE.\n";
fout<<"3.Goto CREATE->CLASS TIME-TABLE And Then Enter Class Name With Section.\n";
fout<<"4.After Clicking On Submit You Will See A Blank Time-Table . You Have To Type Only The Subject Name .\n";
fout<<"5.Then Select The Respective Teacher's Name From Below List Box. After Doing Your Work Click SAVE .\n";
fout<<"6.Teacher's Time-Tables Will Be Created Automatically In Accordance To The Class Time-Tables.\n";
fout<<"7.If Multiple Subjects Are Needed In Single Period (eg-P.E/C.S) , Then \ni)Use The Right Hand Side Given Cells.\nii)Input Required Subjects And Select Respective Teachers From Below List Box.\niii)Use Minimum 3 Letters In Identifiers Cells For Identifying This Set Of Subjects And Teachers\niv)Use The Respective Identifiers In Place Of Subject In Time-Table To Add Multiple Subjects In Single Period.";


fout<<"\n\n*CREATING ARRANGEMENT TABLES : \n";
fout<<"1.Goto CREATE->ARRANGEMENT .\n";
fout<<"2.Select Absent Teacher's Name From The List Box.\n";
fout<<"3.The Class And Period In Which The Teacher Is Busy Will Be Shown Thereafter.\n";
fout<<"3.Select The Teacher From The List Box For Arrangement And Then Click CREATE ARRANGEMENT.\n";

fout<<"\n\n\t**** So Simple.Have A Nice Experience.... ****\n";

fout.close();
}

void creat_tbl(HWND hWnd)
{
multisub(hWnd);

if(!hinpt[0][0])
{
hinpt[0][0]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"CLASS AND SECTION",
WS_CHILD|WS_VISIBLE|ES_CENTER,
100,
40,
300,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}
if(!hinpt[0][1])
{
hinpt[0][1]=CreateWindowEx(WS_EX_CLIENTEDGE,
"STATIC",
"",
WS_CHILD|WS_VISIBLE|ES_CENTER,
420,
40,
70,
30,
hWnd,
NULL,
GetModuleHandle(NULL),
NULL);
}

creat_tbl_p2(hWnd);

hEdit[13][9]=CreateWindowEx(WS_EX_CLIENTEDGE,
"BUTTON",
"SAVE",
WS_TABSTOP|WS_VISIBLE|
WS_CHILD|BS_DEFPUSHBUTTON,
600,
40,
70,
30,
hWnd,
(HMENU)save,
GetModuleHandle(NULL),
NULL);

statictext();

}









LPSTR choice(WPARAM wParam)
{
switch(LOWORD(wParam))
{
case ID_P_D :
{
SendMessage(hEdit[0][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][0]),
reinterpret_cast<LPARAM>(clas.main[0][0]));


}break;

case ID_PERIOD_1 :
{
SendMessage(hEdit[0][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][1]),
reinterpret_cast<LPARAM>(clas.main[0][1]));


}break;

case ID_PERIOD_2 :
{
SendMessage(hEdit[0][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][2]),
reinterpret_cast<LPARAM>(clas.main[0][2]));


}break;

case ID_PERIOD_3 :
{
SendMessage(hEdit[0][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][3]),
reinterpret_cast<LPARAM>(clas.main[0][3]));


}break;

case ID_PERIOD_4 :
{
SendMessage(hEdit[0][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][4]),
reinterpret_cast<LPARAM>(clas.main[0][4]));


}break;

case ID_PERIOD_5 :
{
SendMessage(hEdit[0][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][5]),
reinterpret_cast<LPARAM>(clas.main[0][5]));


}break;

case ID_PERIOD_6 :
{
SendMessage(hEdit[0][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][6]),
reinterpret_cast<LPARAM>(clas.main[0][6]));


}break;

case ID_PERIOD_7 :
{
SendMessage(hEdit[0][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][7]),
reinterpret_cast<LPARAM>(clas.main[0][7]));


}break;

case ID_PERIOD_8 :
{
SendMessage(hEdit[0][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[0][8]),
reinterpret_cast<LPARAM>(clas.main[0][8]));


}break;

case ID_MONDAY :
{
SendMessage(hEdit[1][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][0]),
reinterpret_cast<LPARAM>(clas.main[1][0]));


}break;


case ID_TUESDAY :
{
SendMessage(hEdit[2][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][0]),
reinterpret_cast<LPARAM>(clas.main[2][0]));


}break;


case ID_WEDNESDAY :
{
SendMessage(hEdit[3][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][0]),
reinterpret_cast<LPARAM>(clas.main[3][0]));


}break;


case ID_THURSDAY :
{
SendMessage(hEdit[4][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][0]),
reinterpret_cast<LPARAM>(clas.main[4][0]));


}break;


case ID_FRIDAY :
{
SendMessage(hEdit[5][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][0]),
reinterpret_cast<LPARAM>(clas.main[5][0]));


}break;


case ID_SATURDAY :
{
SendMessage(hEdit[6][0],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][0]),
reinterpret_cast<LPARAM>(clas.main[6][0]));


}break;

case ID_PERIOD_M1:
{
SendMessage(hEdit[1][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][1]),
reinterpret_cast<LPARAM>(clas.main[1][1]));
if (clas.main[1][1][2])
{
get_tch(1,1);
}


}break;

case ID_PERIOD_M2:
{
SendMessage(hEdit[1][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][2]),
reinterpret_cast<LPARAM>(clas.main[1][2]));
if (clas.main[1][2][2])     get_tch(1,2);
}break;

case ID_PERIOD_M3:
{
SendMessage(hEdit[1][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][3]),
reinterpret_cast<LPARAM>(clas.main[1][3]));
if (clas.main[1][3][2])     get_tch(1,3);
}break;

case ID_PERIOD_M4:
{
SendMessage(hEdit[1][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][4]),
reinterpret_cast<LPARAM>(clas.main[1][4]));
if (clas.main[1][4][2])     get_tch(1,4);
}break;
case ID_PERIOD_M5:
{
SendMessage(hEdit[1][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][5]),
reinterpret_cast<LPARAM>(clas.main[1][5]));
if (clas.main[1][5][2])     get_tch(1,5);
}break;
case ID_PERIOD_M6:
{
SendMessage(hEdit[1][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][6]),
reinterpret_cast<LPARAM>(clas.main[1][6]));
if (clas.main[1][6][2])     get_tch(1,6);
}break;

case ID_PERIOD_M7:
{
SendMessage(hEdit[1][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][7]),
reinterpret_cast<LPARAM>(clas.main[1][7]));
if (clas.main[1][7][2])     get_tch(1,7);
}break;

case ID_PERIOD_M8:
{
SendMessage(hEdit[1][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[1][8]),
reinterpret_cast<LPARAM>(clas.main[1][8]));
if (clas.main[1][8][2])     get_tch(1,8);
}break;

case ID_PERIOD_T1:
{
SendMessage(hEdit[2][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][1]),
reinterpret_cast<LPARAM>(clas.main[2][1]));
if (clas.main[2][1][2])     get_tch(2,1);
}break;

case ID_PERIOD_T2:
{
SendMessage(hEdit[2][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][2]),
reinterpret_cast<LPARAM>(clas.main[2][2]));
if (clas.main[2][2][2])     get_tch(2,2);
}break;

case ID_PERIOD_T3:
{
SendMessage(hEdit[2][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][3]),
reinterpret_cast<LPARAM>(clas.main[2][3]));
if (clas.main[2][3][2])     get_tch(2,3);
}break;

case ID_PERIOD_T4:
{
SendMessage(hEdit[2][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][4]),
reinterpret_cast<LPARAM>(clas.main[2][4]));
if (clas.main[2][4][2])     get_tch(2,4);
}break;

case ID_PERIOD_T5:
{
SendMessage(hEdit[2][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][5]),
reinterpret_cast<LPARAM>(clas.main[2][5]));
if (clas.main[2][5][2])     get_tch(2,5);
}break;
case ID_PERIOD_T6:
{
SendMessage(hEdit[2][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][6]),
reinterpret_cast<LPARAM>(clas.main[2][6]));
if (clas.main[2][6][2])     get_tch(2,6);
}break;

case ID_PERIOD_T7:
{
SendMessage(hEdit[2][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][7]),
reinterpret_cast<LPARAM>(clas.main[2][7]));
if (clas.main[2][7][2])     get_tch(2,7);
}break;

case ID_PERIOD_T8:
{
SendMessage(hEdit[2][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[2][8]),
reinterpret_cast<LPARAM>(clas.main[2][8]));
if (clas.main[2][8][2])     get_tch(2,8);
}break;

case ID_PERIOD_W1:
{
SendMessage(hEdit[3][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][1]),
reinterpret_cast<LPARAM>(clas.main[3][1]));
if (clas.main[3][1][2])     get_tch(3,1);
}break;

case ID_PERIOD_W2:
{
SendMessage(hEdit[3][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][2]),
reinterpret_cast<LPARAM>(clas.main[3][2]));
if (clas.main[3][2][2])     get_tch(3,2);
}break;

case ID_PERIOD_W3:
{
SendMessage(hEdit[3][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][3]),
reinterpret_cast<LPARAM>(clas.main[3][3]));
if (clas.main[3][3][2])     get_tch(3,3);
}break;

case ID_PERIOD_W4:
{
SendMessage(hEdit[3][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][4]),
reinterpret_cast<LPARAM>(clas.main[3][4]));
if (clas.main[3][4][2])     get_tch(3,4);
}break;
case ID_PERIOD_W5:
{
SendMessage(hEdit[3][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][5]),
reinterpret_cast<LPARAM>(clas.main[3][5]));
if (clas.main[3][5][2])     get_tch(3,5);
}break;
case ID_PERIOD_W6:
{
SendMessage(hEdit[3][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][6]),
reinterpret_cast<LPARAM>(clas.main[3][6]));
if (clas.main[3][6][2])     get_tch(3,6);
}break;

case ID_PERIOD_W7:
{
SendMessage(hEdit[3][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][7]),
reinterpret_cast<LPARAM>(clas.main[3][7]));
if (clas.main[3][7][2])     get_tch(3,7);
}break;

case ID_PERIOD_W8:
{
SendMessage(hEdit[3][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[3][8]),
reinterpret_cast<LPARAM>(clas.main[3][8]));
if (clas.main[3][8][2])     get_tch(3,8);
}break;

case ID_PERIOD_TH1:
{
SendMessage(hEdit[4][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][1]),
reinterpret_cast<LPARAM>(clas.main[4][1]));
if (clas.main[4][1][2])     get_tch(4,1);
}break;

case ID_PERIOD_TH2:
{
SendMessage(hEdit[4][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][2]),
reinterpret_cast<LPARAM>(clas.main[4][2]));
if (clas.main[4][2][2])     get_tch(4,2);
}break;

case ID_PERIOD_TH3:
{
SendMessage(hEdit[4][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][3]),
reinterpret_cast<LPARAM>(clas.main[4][3]));
if (clas.main[4][3][2])     get_tch(4,3);
}break;

case ID_PERIOD_TH4:
{
SendMessage(hEdit[4][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][4]),
reinterpret_cast<LPARAM>(clas.main[4][4]));
if (clas.main[4][4][2])     get_tch(4,4);
}break;
case ID_PERIOD_TH5:
{
SendMessage(hEdit[4][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][5]),
reinterpret_cast<LPARAM>(clas.main[4][5]));
if (clas.main[4][5][2])     get_tch(4,5);
}break;
case ID_PERIOD_TH6:
{
SendMessage(hEdit[4][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][6]),
reinterpret_cast<LPARAM>(clas.main[4][6]));
if (clas.main[4][6][2])     get_tch(4,6);
}break;

case ID_PERIOD_TH7:
{
SendMessage(hEdit[4][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][7]),
reinterpret_cast<LPARAM>(clas.main[4][7]));
if (clas.main[4][7][2])     get_tch(4,7);
}break;

case ID_PERIOD_TH8:
{
SendMessage(hEdit[4][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[4][8]),
reinterpret_cast<LPARAM>(clas.main[4][8]));
if (clas.main[4][8][2])     get_tch(4,8);
}break;

case ID_PERIOD_F1:
{
SendMessage(hEdit[5][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][1]),
reinterpret_cast<LPARAM>(clas.main[5][1]));
if (clas.main[5][1][2])     get_tch(5,1);
}break;

case ID_PERIOD_F2:
{
SendMessage(hEdit[5][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][2]),
reinterpret_cast<LPARAM>(clas.main[5][2]));
if (clas.main[5][2][2])     get_tch(5,2);
}break;

case ID_PERIOD_F3:
{
SendMessage(hEdit[5][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][3]),
reinterpret_cast<LPARAM>(clas.main[5][3]));
if (clas.main[5][3][2])     get_tch(5,3);
}break;

case ID_PERIOD_F4:
{
SendMessage(hEdit[5][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][4]),
reinterpret_cast<LPARAM>(clas.main[5][4]));
if (clas.main[5][4][2])     get_tch(5,4);
}break;
case ID_PERIOD_F5:
{
SendMessage(hEdit[5][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][5]),
reinterpret_cast<LPARAM>(clas.main[5][5]));
if (clas.main[5][5][2])     get_tch(5,5);
}break;
case ID_PERIOD_F6:
{
SendMessage(hEdit[5][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][6]),
reinterpret_cast<LPARAM>(clas.main[5][6]));
if (clas.main[5][6][2])     get_tch(5,6);
}break;

case ID_PERIOD_F7:
{
SendMessage(hEdit[5][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][7]),
reinterpret_cast<LPARAM>(clas.main[5][7]));
if (clas.main[5][7][2])     get_tch(5,7);
}break;

case ID_PERIOD_F8:
{
SendMessage(hEdit[5][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[5][8]),
reinterpret_cast<LPARAM>(clas.main[5][8]));
if (clas.main[5][8][2])     get_tch(5,8);
}break;

case ID_PERIOD_S1:
{
SendMessage(hEdit[6][1],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][1]),
reinterpret_cast<LPARAM>(clas.main[6][1]));
if (clas.main[6][1][2])     get_tch(6,1);
}break;

case ID_PERIOD_S2:
{
SendMessage(hEdit[6][2],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][2]),
reinterpret_cast<LPARAM>(clas.main[6][2]));
if (clas.main[6][2][2])     get_tch(6,2);
}break;

case ID_PERIOD_S3:
{
SendMessage(hEdit[6][3],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][3]),
reinterpret_cast<LPARAM>(clas.main[6][3]));
if (clas.main[6][3][2])     get_tch(6,3);
}break;

case ID_PERIOD_S4:
{
SendMessage(hEdit[6][4],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][4]),
reinterpret_cast<LPARAM>(clas.main[6][4]));
if (clas.main[6][4][2])     get_tch(6,4);
}break;
case ID_PERIOD_S5:
{
SendMessage(hEdit[6][5],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][5]),
reinterpret_cast<LPARAM>(clas.main[6][5]));
if (clas.main[6][5][2])     get_tch(6,5);
}break;
case ID_PERIOD_S6:
{
SendMessage(hEdit[6][6],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][6]),
reinterpret_cast<LPARAM>(clas.main[6][6]));
if (clas.main[6][6][2])     get_tch(6,6);
}break;

case ID_PERIOD_S7:
{
SendMessage(hEdit[6][7],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][7]),
reinterpret_cast<LPARAM>(clas.main[6][7]));
if (clas.main[6][7][2])     get_tch(6,7);
}break;

case ID_PERIOD_S8:
{
SendMessage(hEdit[6][8],
WM_GETTEXT,
sizeof(clas.main)/sizeof(clas.main[6][8]),
reinterpret_cast<LPARAM>(clas.main[6][8]));
if (clas.main[6][8][2])     get_tch(6,8);
}break;

case ID_TEACHER_M1:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][1],clas.info[1][1],20);

teacher_table(1,1);
//break;
}

}break;

case ID_TEACHER_M2:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][2],clas.info[1][2],20);

teacher_table(1,2);
//break;
}

}break;

case ID_TEACHER_M3:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][3],clas.info[1][3],20);

teacher_table(1,3);
//break;
}

}break;

case ID_TEACHER_M4:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][4],clas.info[1][4],20);

teacher_table(1,4);
//break;
}

}break;
case ID_TEACHER_M5:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][5],clas.info[1][5],20);

teacher_table(1,5);
//break;
}

}break;
case ID_TEACHER_M6:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][6],clas.info[1][6],20);

teacher_table(1,6);
//break;
}

}break;
case ID_TEACHER_M7:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][7],clas.info[1][7],20);

teacher_table(1,7);
//break;
}

}break;
case ID_TEACHER_M8:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[7][8],clas.info[1][8],20);

teacher_table(1,8);
//break;
}

}break;
case ID_TEACHER_T1:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][1],clas.info[2][1],20);

teacher_table(2,1);
//break;
}

}break;
case ID_TEACHER_T2:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][2],clas.info[2][2],20);

teacher_table(2,2);
//break;
}

}break;
case ID_TEACHER_T3:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][3],clas.info[2][3],20);

teacher_table(2,3);
//break;
}

}break;
case ID_TEACHER_T4:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][4],clas.info[2][4],20);

teacher_table(2,4);
//break;
}

}break;
case ID_TEACHER_T5:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][5],clas.info[2][5],20);

teacher_table(2,5);
//break;
}

}break;
case ID_TEACHER_T6:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][6],clas.info[2][6],20);

teacher_table(2,6);
//break;
}

}break;
case ID_TEACHER_T7:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][7],clas.info[2][7],20);

teacher_table(2,7);
//break;
}

}break;
case ID_TEACHER_T8:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[8][8],clas.info[2][8],20);

teacher_table(2,8);
//break;
}

}break;
case ID_TEACHER_W1:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][1],clas.info[3][1],20);

teacher_table(3,1);
//break;
}

}break;
case ID_TEACHER_W2:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][2],clas.info[3][2],20);

teacher_table(3,2);
//break;
}

}break;
case ID_TEACHER_W3:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][3],clas.info[3][3],20);

teacher_table(3,3);
//break;
}

}break;
case ID_TEACHER_W4:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][4],clas.info[3][4],20);

teacher_table(3,4);
//break;
}

}break;
case ID_TEACHER_W5:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][5],clas.info[3][5],20);

teacher_table(3,5);
//break;
}

}break;
case ID_TEACHER_W6:
{

//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][6],clas.info[3][6],20);

teacher_table(3,6);
//break;
}

}break;
case ID_TEACHER_W7:
{


//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][7],clas.info[3][7],20);

teacher_table(3,7);
//break;
}

}break;
case ID_TEACHER_W8:
{

//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[9][8],clas.info[3][8],20);

teacher_table(3,8);
//break;
}

}break;
case ID_TEACHER_TH1:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][1],clas.info[4][1],20);

teacher_table(4,1);
//break;
}

}break;
case ID_TEACHER_TH2:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][2],clas.info[4][2],20);

teacher_table(4,2);
//break;
}

}break;
case ID_TEACHER_TH3:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][3],clas.info[4][3],20);

teacher_table(4,3);
//break;
}

}break;
case ID_TEACHER_TH4:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][4],clas.info[4][4],20);

teacher_table(4,4);
//break;
}

}break;
case ID_TEACHER_TH5:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][5],clas.info[4][5],20);

teacher_table(4,5);
//break;
}

}break;
case ID_TEACHER_TH6:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][6],clas.info[4][6],20);

teacher_table(4,6);
//break;
}

}break;
case ID_TEACHER_TH7:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][7],clas.info[4][7],20);

teacher_table(4,7);
//break;
}

}break;
case ID_TEACHER_TH8:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[10][8],clas.info[4][8],20);

teacher_table(4,8);
//break;
}

}break;
case ID_TEACHER_F1:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][1],clas.info[5][1],20);

teacher_table(5,1);
//break;
}

}break;
case ID_TEACHER_F2:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][2],clas.info[5][2],20);

teacher_table(5,2);
//break;
}

}break;
case ID_TEACHER_F3:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][3],clas.info[5][3],20);

teacher_table(5,3);
//break;
}

}break;
case ID_TEACHER_F4:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][4],clas.info[5][4],20);

teacher_table(5,4);
//break;
}

}break;
case ID_TEACHER_F5:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][5],clas.info[5][5],20);

teacher_table(5,5);
//break;
}

}break;
case ID_TEACHER_F6:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][6],clas.info[5][6],20);

teacher_table(5,6);
//break;
}

}break;
case ID_TEACHER_F7:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][7],clas.info[5][7],20);

teacher_table(5,7);
//break;
}

}break;
case ID_TEACHER_F8:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[11][8],clas.info[5][8],20);

teacher_table(5,8);
//break;
}

}break;
case ID_TEACHER_S1:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][1],clas.info[6][1],20);

teacher_table(6,1);
//break;
}

}break;
case ID_TEACHER_S2:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][2],clas.info[6][2],20);

teacher_table(6,2);
//break;
}

}break;
case ID_TEACHER_S3:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][3],clas.info[6][3],20);

teacher_table(6,3);
//break;
}

}break;
case ID_TEACHER_S4:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][4],clas.info[6][4],20);

teacher_table(6,4);
//break;
}

}break;
case ID_TEACHER_S5:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][5],clas.info[6][5],20);

teacher_table(6,5);
//break;
}

}break;
case ID_TEACHER_S6:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][6],clas.info[6][6],20);

teacher_table(6,6);
//break;
}

}break;
case ID_TEACHER_S7:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][7],clas.info[6][7],20);

teacher_table(6,7);
//break;
}

}break;
case ID_TEACHER_S8:
{
//switch(HIWORD(wParam))
{
//  case LBN_SELCHANGE:

GetWindowText(hEdit[12][8],clas.info[6][8],20);

teacher_table(6,8);
//break;
}

}break;


}

return 0;
}


void get_class_nos(HWND hWnd)
{
int indt=0,indc=0;

SendMessage(hinpt[0][1],
WM_GETTEXT,
sizeof(clas.name)/sizeof(clas.name[20]),
reinterpret_cast<LPARAM>(clas.name));

TABLE cls;
cls=get_class();
int Result;
if(strcmp(cls.name,clas.name)==0)
{

Result=MessageBox(NULL,
"Do you want to replace it?","Class Already Exist",
MB_ICONINFORMATION|MB_YESNOCANCEL);

switch(Result)
{
case IDYES:
{

while(indc<=indexc)
{
if(strcmp(classfile[indc].clas.name,cls.name)==0)
{

classfile[indc].clas=blank;

}
indc++;
}

while(indt<=indext)
{
for (int i=1;i<=6;i++)
{
for(int j=1;j<=8;j++)
{
if(strcmp(teacherfile[indt].tch.main[i][j],cls.name)==0)
{
strcpy(teacherfile[indt].tch.main[i][j],"\0");
strcpy(teacherfile[indt].tch.info[i][j],"\0");
}
}

}
indt++;
}
input2(hWnd);

}		break;


case IDNO:
{

clas=cls;
input2(hWnd);

}	break;
case IDCANCEL:
{

input(hWnd);

}	break;

}

}
else input2(hWnd);
}


BOOL CALLBACK AboutDlgProc (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
     switch (message)
     {
        case WM_INITDIALOG : return TRUE ;
        case WM_COMMAND :
                    switch (LOWORD (wParam))
                    {
                        case IDOK : case IDCANCEL : EndDialog (hDlg, 0) ;
                    return TRUE ;
                    } break ;
     } return FALSE ;
}

LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{

static HINSTANCE hInstance ;

switch(msg)
{  de:
case WM_CREATE:
{
     hInstance = ((LPCREATESTRUCT) lParam)->hInstance ;

c_dir();
get_date();
create_readme();
check();
load_data();
menu(hWnd);


}		break;


case WM_COMMAND:
{
if (((LOWORD(wParam))>100)&&((LOWORD(wParam))<212))
{
choice(wParam);

}
else
switch(LOWORD(wParam))
{

case IDM_APP_ABOUT : DialogBox(hInstance, TEXT ("AboutBox"), hWnd, AboutDlgProc) ;
break;
case save:
{
savetbl();
load_data();
destroy_window();

}break;


case ID_MULTI_SUB_1:
{

GetWindowText(hinpt[1][6],clas.multi_sub[0],20);
//  if(clas.multi_sub[0][2])
{
get_tch2(1,6,0);
}
}break;




case ID_MULTI_SUB_2:
{
GetWindowText(hinpt[1][7],clas.multi_sub[1],20);
if(clas.multi_sub[1][2])
{
get_tch2(1,7,1);
}
}break;




case ID_MULTI_SUB_3:
{
GetWindowText(hinpt[1][8],clas.multi_sub[2],20);
if(clas.multi_sub[2][2])
{
get_tch2(1,8,2);
}
}break;




case ID_MULTI_SUB_4:
{
GetWindowText(hinpt[1][9],clas.multi_sub[3],20);
if(clas.multi_sub[3][2])
{
get_tch2(1,9,3);
}
}break;




case ID_MULTI_SUB_5:
{
GetWindowText(hinpt[3][6],clas.multi_sub[4],20);
if(clas.multi_sub[4][2])
{
get_tch2(3,6,4);
}
}break;




case ID_MULTI_SUB_6:
{
GetWindowText(hinpt[3][7],clas.multi_sub[5],20);
if(clas.multi_sub[5][2])
{
get_tch2(3,7,5);
}
}break;




case ID_MULTI_SUB_7:
{
GetWindowText(hinpt[3][8],clas.multi_sub[6],20);
if(clas.multi_sub[6][2])
{
get_tch2(3,8,6);
}
}break;




case ID_MULTI_SUB_8:
{
GetWindowText(hinpt[3][9],clas.multi_sub[7],20);
if(clas.multi_sub[7][2])
{
get_tch2(3,9,7);
}
}break;




case ID_MULTI_SUB_9:
{
GetWindowText(hinpt[5][6],clas.multi_sub[8],20);
if(clas.multi_sub[8][2])
{
get_tch2(5,6,8);
}
}break;





case ID_MULTI_SUB_10:
{
GetWindowText(hinpt[5][7],clas.multi_sub[9],20);
if(clas.multi_sub[9][2])
{
get_tch2(5,7,9);
}
}break;




case ID_MULTI_SUB_11:
{
GetWindowText(hinpt[5][8],clas.multi_sub[10],20);
if(clas.multi_sub[10][2])
{
get_tch2(5,8,10);
}
}break;




case ID_MULTI_SUB_12:
{
GetWindowText(hinpt[5][9],clas.multi_sub[11],20);
if(clas.multi_sub[11][2])
{
get_tch2(5,9,11);
}
}break;




case ID_MULTI_SUB_13:
{
GetWindowText(hinpt[7][6],clas.multi_sub[12],20);
if(clas.multi_sub[12][2])
{
get_tch2(7,6,12);
}
}break;




case ID_MULTI_SUB_14:
{
GetWindowText(hinpt[7][7],clas.multi_sub[13],20);
if(clas.multi_sub[13][2])
{
get_tch2(7,7,13);
}
}break;




case ID_MULTI_SUB_15:
{
GetWindowText(hinpt[7][8],clas.multi_sub[14],20);
if(clas.multi_sub[14][2])
{
get_tch2(7,8,14);
}
}break;




case ID_MULTI_SUB_16:
{
GetWindowText(hinpt[7][9],clas.multi_sub[15],20);
if(clas.multi_sub[15][2])
{
get_tch2(7,9,15);
}
}break;





case ID_MULTI_TCH_1:
{
GetWindowText(hinpt[2][6],clas.multi_tch[0],20);
////if(clas.multi_tch[0][2])
{
//  //get_tch2(1,6,0));
}
}break;




case ID_MULTI_TCH_2:
{
GetWindowText(hinpt[2][7],clas.multi_tch[1],20);
//if(clas.multi_tch[1][2])
{
//get_tch2(1,7,1));
}
}break;




case ID_MULTI_TCH_3:
{
GetWindowText(hinpt[2][8],clas.multi_tch[2],20);
//if(clas.multi_tch[2][2])
{
//get_tch2(1,8,2));
}
}break;




case ID_MULTI_TCH_4:
{
GetWindowText(hinpt[2][9],clas.multi_tch[3],20);
//if(clas.multi_tch[3][2])
{
//get_tch2(1,9,3));
}
}break;




case ID_MULTI_TCH_5:
{
GetWindowText(hinpt[4][6],clas.multi_tch[4],20);
//if(clas.multi_tch[4][2])
{
//get_tch2(3,6,4));
}
}break;




case ID_MULTI_TCH_6:
{
GetWindowText(hinpt[4][7],clas.multi_tch[5],20);
//if(clas.multi_tch[5][2])
{
//get_tch2(3,7,5));
}
}break;




case ID_MULTI_TCH_7:
{
GetWindowText(hinpt[4][8],clas.multi_tch[6],20);
//if(clas.multi_tch[6][2])
{
//get_tch2(3,8,6));
}
}break;




case ID_MULTI_TCH_8:
{
GetWindowText(hinpt[4][9],clas.multi_tch[7],20);
//if(clas.multi_tch[7][2])
{
//get_tch2(3,9,7));
}
}break;




case ID_MULTI_TCH_9:
{
GetWindowText(hinpt[6][6],clas.multi_tch[8],20);
//if(clas.multi_tch[8][2])
{
//get_tch2(5,6,8));
}
}break;





case ID_MULTI_TCH_10:
{
GetWindowText(hinpt[6][7],clas.multi_tch[9],20);
//if(clas.multi_tch[9][2])
{
//get_tch2(5,7,9));
}
}break;




case ID_MULTI_TCH_11:
{
GetWindowText(hinpt[6][8],clas.multi_tch[10],20);
//if(clas.multi_tch[10][2])
{
//get_tch2(5,8,10));
}
}break;




case ID_MULTI_TCH_12:
{
GetWindowText(hinpt[6][9],clas.multi_tch[11],20);
//if(clas.multi_tch[11][2])
{
//get_tch2(5,9,11));
}
}break;




case ID_MULTI_TCH_13:
{
GetWindowText(hinpt[8][6],clas.multi_tch[12],20);
//if(clas.multi_tch[12][2])
{
//get_tch2(7,6,12));
}
}break;




case ID_MULTI_TCH_14:
{
GetWindowText(hinpt[8][7],clas.multi_tch[13],20);
//if(clas.multi_tch[13][2])
{
//get_tch2(7,7,13));
}
}break;




case ID_MULTI_TCH_15:
{
GetWindowText(hinpt[8][8],clas.multi_tch[14],20);
//if(clas.multi_tch[14][2])
{
//get_tch2(7,8,14));
}
}break;




case ID_MULTI_TCH_16:
{
GetWindowText(hinpt[8][9],clas.multi_tch[15],20);
//if(clas.multi_tch[15][2])
{
//get_tch2(7,9,15));
}
}break;




case ID_IDENTIFIER_1:
{
GetWindowText(hinpt[1][10],clas.identifiers[0],20);
}break;


case ID_IDENTIFIER_2:
{
GetWindowText(hinpt[3][10],clas.identifiers[1],20);
}break;


case ID_IDENTIFIER_3:
{
GetWindowText(hinpt[5][10],clas.identifiers[2],20);
}break;


case ID_IDENTIFIER_4:
{
GetWindowText(hinpt[7][10],clas.identifiers[3],20);
}break;

case ID_PRODUCT_KEY:
{
destroy_window();
save_product_key(hWnd);

}break;

case ID_PRODUCT_KEY_UNI:
{
dn();
strcpy(chk.user_ttm_product_key," ");
en();
MessageBox(NULL,"DONE...","Info..",MB_OK|MB_ICONINFORMATION);
destroy_window();
}break;

case ID_PRODUCT_KEY_SAV:
{dn();
GetWindowText(hinpt[1][3],chk.user_ttm_product_key,80);
if(strcmp(chk.user_ttm_product_key,chk2.ttm_product_key)==0)
{
save_product_key2();
destroy_window();
}
else if(strcmp(chk.user_ttm_product_key,chk2.universal_ttm_key)==0)
{
en();
MessageBox(NULL,"DONE...","Info..",MB_OK|MB_ICONINFORMATION);
destroy_window();

}
else
{
MessageBox(NULL,"OPPS !! YOUR GUESS WILL NOT WORK HERE...\nBUY THE ORIGINAL ONE...","INVALID PRODUCT KEY!!!!!!!!!!",MB_OK|MB_ICONERROR);
}


}break;




case ID_CR_BACKUP:
{
if((MessageBox(NULL,"Are you Sure to Create Backup now?","Alert!!",MB_ICONQUESTION|MB_YESNO)==IDYES))
{
destroy_window();


strcpy(tmpname2,"\0");
strcpy(tmpname2,dir[5]);
strcpy(tmpname2,"Cls.ttm");
remove(tmpname2);
strcpy(tmpname2,"\0");
strcpy(tmpname2,dir[5]);
strcpy(tmpname2,"Tch.ttm");
remove(tmpname2);
strcpy(tmpname2,"\0");
strcpy(tmpname2,dir[5]);
strcpy(tmpname2,"rec.ttm");
remove(tmpname2);
strcpy(tmpname,dir[5]);
strcat(tmpname,"Cls.ttm");
CopyFile("C:\\Time-Table Manager\\TTM Database\\Cls.ttm",tmpname,FALSE);

strcpy(tmpname,dir[5]);
strcat(tmpname,"Tch.ttm");
CopyFile("C:\\Time-Table Manager\\TTM Database\\Tch.ttm",tmpname,FALSE);

strcpy(tmpname,dir[5]);
strcat(tmpname,"rec.ttm");
CopyFile("C:\\Time-Table Manager\\TTM Database\\rec.ttm",tmpname,FALSE);

MessageBox(NULL,"DONE","INFO",MB_OK);

}

}break;

case ID_RS_BACKUP:
{
if((MessageBox(NULL,"Are you Sure to Restore Backup now?","Alert!!",MB_ICONQUESTION|MB_YESNO)==IDYES))
{

destroy_window();


strcpy(tmpname2,"\0");
strcpy(tmpname2,dir[1]);
strcpy(tmpname2,"Cls.ttm");
remove(tmpname2);
strcpy(tmpname2,"\0");
strcpy(tmpname2,dir[1]);
strcpy(tmpname2,"Tch.ttm");
remove(tmpname2);
strcpy(tmpname2,"\0");
strcpy(tmpname2,dir[1]);
strcpy(tmpname2,"rec.ttm");
remove(tmpname2);
strcpy(tmpname,dir[5]);
strcat(tmpname,"Cls.ttm");
CopyFile(tmpname,"C:\\Time-Table Manager\\TTM Database\\Cls.ttm",FALSE);

strcpy(tmpname,dir[5]);
strcat(tmpname,"Tch.ttm");
CopyFile(tmpname,"C:\\Time-Table Manager\\TTM Database\\Tch.ttm",false);
MessageBox(NULL,"DONE","INFO",MB_OK);

strcpy(tmpname,dir[5]);
strcat(tmpname,"rec.ttm");
CopyFile(tmpname,"C:\\Time-Table Manager\\TTM Database\\rec.ttm",false);
//  savetbl();
}

}break;

case ID_SAVE_ARR:
{
save_arr_tbl();
}break;


case IDC_CLASS_CBOX:
// It's our listbox, check the notification code
switch(HIWORD(wParam))
{
case LBN_SELCHANGE:
// Selection changed, do stuff here.
GetWindowText(HCOMB[0][1],cbox,20);
fill_ctt();
break;
}
break;


case ID_MODIFY:
// It's our listbox, check the notification code
switch(HIWORD(wParam))
{
case LBN_SELCHANGE:
// Selection changed, do stuff here.
GetWindowText(HCOMB[0][0],cbox,20);
fill_cmtt();
break;
}
break;

case IDC_TECH_CBOX:
// It's our listbox, check the notification code
switch(HIWORD(wParam))
{
case LBN_SELCHANGE:
// Selection changed, do stuff here.
GetWindowText(HCOMB[0][0],tbox,20);

fill_ttt();
break;
}
break;
case IDC_ARRTT_ABOX:

switch(HIWORD(wParam))
{
    case LBN_SELCHANGE:
    GetWindowText(HCOMB[1][0],abox,20);
    for(int i=1;i<9;i++)
        {
            SendMessage(HTEMP[i][2],CB_RESETCONTENT,0,0);
        }
    cedit();
    break;
}
break;


case ID_N_SUB_Buttom :
{
get_class_nos(hWnd);break;
}
case ID_CREAT_TT:
{
load_data();
destroy_window();
input(hWnd);
}		break;

case ID_CREAT_AT:
{
if(day==0)
{
MessageBox(NULL,"Can't create Arrangement ...Today is Sunday!!","Opps!!!",MB_ICONEXCLAMATION|MB_OK);
}
else
{
load_data();
creat_arrtbl(hWnd);
}
}		break;

case ID_FILE_EXIT:
{   PostMessage(hWnd, WM_CLOSE, 0, 0);
}		break;

case ID_OPEN_TT:
{
load_data();
destroy_window();
op_ctt(hWnd);
}		break;

case ID_OPEN_AT:
{
MessageBox(NULL,"SORRY... \nTHIS FEATURE IS NOT PROGRAMED YET!!","INFO",MB_ICONINFORMATION|MB_OK);

}		break;

case ID_OPEN_TTT:
{
load_data();
op_ttt(hWnd);
}		break;

case ID_INS_TTM:
{
MessageBox(NULL,"Following are few tips that will help you in using TTM smoothly..\n\n1.Create Teacher's record firstly.\n\n2.While creating Class Time-Table just enter the subject and teachers associated with it will appear in the list box automatically.\n\n3.Teacher's Time-Table will be created automatically in accordance to the Class Time-Table.\n\n4.By default all files are saved in C:\\Time-Table Manager\\.\nRead README.txt For More Details.\n\n\tHave a Great Experience... ","INSTRUCTIONS",MB_ICONINFORMATION|MB_OK);

}		break;

case ID_CONTACT:
{
MessageBox(NULL,"Want to report a bug or need a help ..We will hear your voice 24x7 .. E-mail at \n\niashutosh9119@gmail.com\nor at +91-9651891769","CONTACT",MB_ICONINFORMATION|MB_OK);

}		break;

case ID_DELETE:
{
del(hWnd);
//MessageBox(NULL,"SORRY... \nTHIS FEATURE IS NOT PROGRAMED YET!!","INFO",MB_ICONINFORMATION|MB_OK);

}		break;

case ID_DEL:
{
del2();
//MessageBox(NULL,"SORRY... \nTHIS FEATURE IS NOT PROGRAMED YET!!","INFO",MB_ICONINFORMATION|MB_OK);

}		break;

case ID_CLEAR_SRC:
{
destroy_window();
load_data();
menu(hWnd);
MessageBox(NULL,"DONE...","INFO",MB_ICONINFORMATION|MB_OK);
}		break;


case ID_TC_TTM:
{
MessageBox(NULL,"TTM is not a free-ware or share-ware..\nUsing it without the permission of its creators will lead you behind bars!!!!\nAll rights are reserved .. ","INFO",MB_ICONINFORMATION|MB_OK);

}		break;

case ID_DEL_REC:
{
del_rec();

}break;

case ID_MOD_REC:
{
mod_rec(hWnd);

}break;


case ID_UP_REC:
{
mod_save();
load_data();

}break;

case ID_CR_REC:
{
cr_rec(hWnd);

}break;

case ID_CR_SAVE:
{
cr_rec_save();
int yn=MessageBox(NULL,"Do You Want To Add More!!","INFO",MB_ICONINFORMATION|MB_YESNO);
switch(yn)
{
case IDYES :
{
cr_rec(hWnd);
}break;

case IDNO :
{
destroy_window();
}break;
}

}break;

case ID_SETTING:
{
settings(hWnd);
}		break;


case ID_SETTING_SAV:
{
for(int i=2;i<=5;i++)
{
GetWindowText(hinpt[1][i],dir[i],100);
}
creat_dir();

}	break;


case ID_SETTING_RST:
{
alldir();
MessageBox(NULL,"DONE...","INFO",MB_ICONINFORMATION|MB_OK);
}		break;


case ID_ABOUT_TTM:

{

MessageBox(NULL,
"Version  AP.001\r\nTTM is a school project created by Pawan Kumar Mishra(CLI version) and Ashutosh Mishra(GUI version) under the abled guidance of Mr. Anil Kumar Gupta, Department of Computer Science, Army Public School Kgt Gkp.\r\nIt is in development stage...  ",
"About Time-Table Manager",
MB_ICONINFORMATION|MB_OK);

}		break;






}
} break;



case WM_CLOSE :
{
int Result=MessageBox(NULL,
"Any Unsaved Data Will Be Lost!!\r\nAre You Sure You Want To EXIT??",
"Warning!!!!",
MB_ICONWARNING|MB_YESNO);

switch(Result)
{
case IDYES:
{
goto dis;

}		break;
case IDNO:
{
msg=!WM_CLOSE;

}	break;

}

}break;


dis:		case WM_DESTROY:
{
destroy_window();
MessageBox(NULL, "Thanks for using TTM", "Greetings From Team TTM", MB_OK);
PostQuitMessage(0);
return 0;
}		break;


}
return DefWindowProc(hWnd,msg,wParam,lParam);
}



int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
WNDCLASSEX wClass;
ZeroMemory(&wClass,sizeof(WNDCLASSEX));
wClass.cbClsExtra=0;
wClass.cbSize=sizeof(WNDCLASSEX);
wClass.cbWndExtra=0;
wClass.hbrBackground=(HBRUSH)COLOR_WINDOW+6;
//wClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
wClass.hIconSm=(HICON)LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDI_ICON),IMAGE_ICON,16,16,0);


wClass.hCursor=LoadCursor(NULL,IDC_HAND);
wClass.hInstance=hInst;
wClass.lpfnWndProc=(WNDPROC)WinProc;
wClass.lpszClassName="Window Class";
wClass.lpszMenuName=NULL;
wClass.style=CS_HREDRAW|CS_VREDRAW;

if(!RegisterClassEx(&wClass))
{
int nReslt=GetLastError();
cout<<nReslt;
MessageBox(NULL,
"Window class creation failed\r\n",
"Window Class Failed",
MB_ICONERROR);
}

HWND hWnd=CreateWindowEx(WS_EX_TRANSPARENT,
"Window Class",
"TIME-TABLE MANAGER",
WS_OVERLAPPEDWINDOW|WS_MAXIMIZE,
200,
100,
1000,
600,
NULL,
NULL,
hInst,
NULL);

if(!hWnd)
{
int nResult=GetLastError();
cout<<nResult;
MessageBox(NULL,
"windows creation failed",
"Window Creation Failed",
MB_ICONERROR);
}

ShowWindow(hWnd,SW_SHOWMAXIMIZED);
UpdateWindow(hWnd);
MSG msg;
ZeroMemory(&msg,sizeof(MSG));


while(GetMessage(&msg,NULL,0,0))
{
TranslateMessage(&msg);
DispatchMessage(&msg);
}

return 0;
}

