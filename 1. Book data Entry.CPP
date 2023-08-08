#include<stdio.h>
#include<conio.h>
main()
{
/*Deklarasi Pointer File*/
FILE*vf;
char td ='Y',sd='y';
/*Deklarasi data buku bertipe struktur*/
struct
{char kb[5];
 char jb[25];
 char pg[20];
 char pn[20];
 int jml_b;
 }vr;
 /*Buka File*/
 vf=fopen("dbuku.dat","a");
 if (vf==NULL)
 {clrscr();
 printf("File data tidak dapat dibuat!");
 getch();}
 while(td=='y'||td=='Y')
 {clrscr();
 /*Cetak Disain Input data buku*/
 gotoxy(25,5);printf("Input Data Buku");
 gotoxy(25,6);printf("----------------------");
 gotoxy(25,7);printf("Kode buku     :");
 gotoxy(25,8);printf("Judul buku    :");
 gotoxy(25,9);printf("Pengarang buku:");
 gotoxy(25,10);printf("Penerbit      :");
 gotoxy(25,11);printf("Jumlah buku   :");
 gotoxy(25,12);printf("Simpan Data[Y/T?] :");
 gotoxy(25,13);printf("Tambah Data[T/T?] :");
 /*Input Data Buku*/
 gotoxy(40,7);gets(vr.kb);
 gotoxy(40,8);gets(vr.jb);
 gotoxy(40,9);gets(vr.pg);
 gotoxy(40,10);gets(vr.pn);
 gotoxy(40,11);scanf("%i",&vr.jml_b);fflush(stdin);
 gotoxy(40,12);sd=getche();fflush(stdin);
 /*Simpan data buku*/
 if(sd=='Y'||sd=='y')
  {fwrite(&vr,sizeof(vr),1,vf);
  gotoxy(40,14);printf("Data Berhasil Disimpan");}
 else
   {gotoxy(40,14);printf("Data Tidak Disimpan");}
 gotoxy(40,13);scanf("%c",&td);fflush(stdin);
 }
 /*tutup file data*/
 fclose(vf);
}
