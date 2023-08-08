#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
FILE * pjn;
int vno;
char sd,td;
char ada;
struct
{int no;
 char tp[10];
 char lp[25];
 long int hj;
 int jj;
}lpt;

td='y';
while (td=='y' || td=='Y')
{ clrscr();
  gotoxy(25,1) ;printf("Entry Data Penjualan");
  gotoxy(25,2) ;printf("--------------------");
  gotoxy(25,4) ;printf("No. Faktur          :");
  gotoxy(25,5) ;printf("Tanggal Penjualan   :");
  gotoxy(25,6) ;printf("Nama Laptop         :");
  gotoxy(25,7) ;printf("Harga Jual          :");
  gotoxy(25,8) ;printf("Jumlah Jual         :");
  gotoxy(25,9) ;printf("Data Disimpan [Y/T] :");
  gotoxy(25,10);printf("Ada Data Lagi [Y/T] :");
   /*input variabel kunci*/
  gotoxy(46,4) ; scanf("%i",&vno);fflush(stdin);
  /*Pencarian Kode Laptop*/
  /*Buka File Data Untuk Di Baca*/
  ada='t';
  pjn=fopen("Laptop.dat","r");
  if (pjn==NULL)
  {  /*=====Buat File Baru=====*/
  pjn=fopen("Laptop.dat","w");
  }
  else
  { /*Cari Kode Ke File dengan cara membandingkan Kode */
	while (fread(&lpt,sizeof(lpt),1,pjn)==1)
	{  if(lpt.no==vno)
        { gotoxy(46,5) ;printf("%s",lpt.tp);
 			 gotoxy(46,6) ;printf("%s",lpt.lp);
 			 gotoxy(46,7) ;printf("%li",lpt.hj);
 			 gotoxy(46,8) ;printf("%i",lpt.jj);
          ada='y';
        }
   }
  }
/*Input Data Laptop Jika Kode Tidak Ada di File Data*/
     if (ada=='t')
     {  fflush(stdin);
 	     gotoxy(46,5); scanf("%s",&lpt.tp);fflush(stdin);
        gotoxy(46,6); gets(lpt.lp);fflush(stdin);
  	  	  gotoxy(46,7); scanf("%li",&lpt.hj);fflush(stdin);
        gotoxy(46,8); scanf("%i",&lpt.jj);fflush(stdin);
	     gotoxy(46,9); scanf("%c",&sd);fflush(stdin);
	     if (sd=='y'||sd=='Y')
           {
         /*Buka File Data Untuk Di Tulis*/
         	fclose(pjn);
	         pjn=fopen("Laptop.dat","a");
	         lpt.no=vno;
            fwrite(&lpt,sizeof(lpt),1,pjn);
            gotoxy (25,13);printf("Data Berhasil Disimpan");
            }

     else
	  { gotoxy(25,14);printf("Data Tidak Disimpan");}

     }
     else
     { gotoxy(25,16);printf("Nomor Faktur Sudah Ada");}

     gotoxy(46,10);scanf("%c",&td);fflush(stdin);
  }
}

