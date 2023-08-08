#include<stdio.h>
#include<conio.h>
main()
{
FILE*png;
char sd,td ='y';
struct
{ char nw[5];
  char na[8];
  char jb;
} jwb;

png=fopen("bantuan.dat","a");
if (png==NULL)
   { clrscr();
   printf("File tidak dapat dibuat");
   getch();}

while(td=='y'||td=='Y')
{clrscr();
gotoxy(10,1);printf("Entry Data Sembako");
gotoxy(10,2);printf("------------------");
gotoxy(10,3);printf("Nomor Warga      :");
gotoxy(10,4);printf("Nama Warga       :");
gotoxy(10,5);printf("Jenis Bantuan    :");
gotoxy(10,6);printf("Simpan Data[Y/T] :");
gotoxy(10,7);printf("Tambah Data[Y/T] :");

gotoxy(30,3);gets(jwb.nw);
gotoxy(30,4);gets(jwb.na);
gotoxy(30,5);scanf("%c",&jwb.jb);fflush(stdin);
gotoxy(30,6);scanf("%c",&sd);fflush(stdin);
if (sd=='y'||sd=='Y')
  { fwrite(&jwb,sizeof(jwb),1,png);
    gotoxy(30,8);printf("Data Berhasil Disimpan");}
else
  { gotoxy(30,8);printf("Data Tidak Disimpan");}
gotoxy(30,7);scanf("%c",&td);fflush(stdin);
}
fclose(png);
getch();
}
