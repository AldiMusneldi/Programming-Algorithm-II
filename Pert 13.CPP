#include<stdio.h>
#include<conio.h>
#include<string.h>
void entry()
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
  pjn=fopen("latihan13.dat","r");
  if (pjn==NULL)
  {  /*=====Buat File Baru=====*/
  pjn=fopen("latihan13.dat","w");
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
	         pjn=fopen("latihan13.dat","a");
	         lpt.no=vno;
            fwrite(&lpt,sizeof(lpt),1,pjn);
            fclose(pjn);
            gotoxy (25,13);printf("Data Berhasil Disimpan");
            }

     else
	  { gotoxy(25,14);printf("Data Tidak Disimpan");}

     }
     else
     { gotoxy(25,16);printf("Nomor Faktur Sudah Ada");}

     gotoxy(46,10);scanf("%c",&td);fflush(stdin);
  }
fclose(pjn);
getch();
}

void laporan()
{
FILE * pjn;
int br,x;
long int th,tth,bsd,tpsd;
int tjj;
float dsc;
struct
{int no;
 char tp[10];
 char lp[25];
 long int hj;
 int jj;
}lpt;

pjn=fopen("latihan13.dat","r");
if (pjn==NULL)
{ clrscr();
gotoxy(25,23);printf("Data Tidak Ada");
getch(); }
clrscr();
gotoxy(35,1);printf("Laporan Data Penjualan");
gotoxy(1,2);printf("-------------------------------------------------------------------------------------------");
gotoxy(1,3);printf("|  |  No. |  Tanggal  |      Nama Laptop       |  Harga  | Jumlah |  Total   |  Bayar     |");
gotoxy(1,4);printf("|No|      |           |                        |         |        |          |  Setelah   |");
gotoxy(1,5);printf("|  |Faktur| Penjualan |                        |  Jual   |  Jual  |  Harga   |  Diskon    |");
gotoxy(1,6);printf("-------------------------------------------------------------------------------------------");

br=7;x=0; tjj=0;tth=0;tpsd=0;
while (fread(&lpt,sizeof(lpt),1,pjn)==1)
{    th=lpt.hj*lpt.jj;
     if (th>30000000)
      { dsc=0.1*th;}
     else if (th>25000000)
      { dsc=0.075*th;}
     else if (th>20000000)
      { dsc=0.05*th;}
     else if (th>15000000)
		{ dsc=0.02*th;}

      bsd=th-dsc;
      tjj=lpt.jj+tjj;
      tth=th+tth;
      tpsd=bsd+tpsd;

      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(4,br); printf("| %i", lpt.no);
      gotoxy(10,br); printf(" | %s", lpt.tp);
      gotoxy(23,br);printf("| %s", lpt.lp);
      gotoxy(48,br);printf("| %li", lpt.hj);
      gotoxy(58,br);printf("| %i", lpt.jj);
      gotoxy(67,br);printf("| %li", th);
      gotoxy(78,br);printf("| %li", bsd);
      gotoxy(91,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("-------------------------------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total                                                  ");printf(" | %i     |", tjj);printf(" %li|", tth);printf(" %li   |", tpsd);
br=br+1;
gotoxy(1,br);printf("-------------------------------------------------------------------------------------------");
fclose(pjn);
getch();
}

main ()
{
  int pil=0;
  while(pil<3)
   {
       clrscr();
       gotoxy(25,5);printf("Menu Pilihan");
       gotoxy(25,6);printf("[1] Entry");
       gotoxy(25,7);printf("[2] Laporan");
       gotoxy(25,8);printf("[3] Exit");
       gotoxy(25,9);printf("Input Pilihan [1-3] : ");scanf("%i", &pil);
       if (pil==1)
       { entry(); continue; }
       else if (pil==2)
       {laporan(); continue;}
   }
}
