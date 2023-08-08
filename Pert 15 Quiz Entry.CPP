#include<stdio.h>
#include<conio.h>

main()
{
FILE * vf;
int vkb;
char sd,td;
char ada;
struct
{int kb;
 char nb[10];
 int ps;
 long int hb;
 int lp;
}vr;

td='y';
while (td=='y' || td=='Y')
{ clrscr();
  gotoxy(25,1) ;printf("Entry Data Penjualan Barang");
  gotoxy(25,2) ;printf("---------------------------");
  gotoxy(25,4) ;printf("Kode Barang          :");
  gotoxy(25,5) ;printf("Nama Barang   :");
  gotoxy(25,6) ;printf("Penjualan Sebelumnya         :");
  gotoxy(25,7) ;printf("Harga Barang          :");
  gotoxy(25,8) ;printf("Lama Pesan        :");
  gotoxy(25,9) ;printf("Data Disimpan [Y/T] :");
  gotoxy(25,10);printf("Ada Data Lagi [Y/T] :");
   /*input variabel kunci*/
  gotoxy(46,4) ; scanf("%i",&vkb);fflush(stdin);
  /*Pencarian Kode Laptop*/
  /*Buka File Data Untuk Di Baca*/
  ada='t';
  vf=fopen("dpb.dat","r");
  if (vf==NULL)
  {  /*=====Buat File Baru=====*/
  vf=fopen("dpb.dat","w");
  }
  else
  { /*Cari Kode Ke File dengan cara membandingkan Kode */
	while (fread(&vr,sizeof(vr),1,vf)==1)
	{  if(vr.kb==vkb)
        { gotoxy(46,5) ;printf("%s",vr.nb);
 			 gotoxy(46,6) ;printf("%i",vr.ps);
 			 gotoxy(46,7) ;printf("%li",vr.hb);
 			 gotoxy(46,8) ;printf("%i",vr.lp);
          ada='y';
        }
   }
  }
/*Input Data Laptop Jika Kode Tidak Ada di File Data*/
     if (ada=='t')
     {  fflush(stdin);
 	     gotoxy(46,5); gets(vr.nb);fflush(stdin);
        gotoxy(46,6); scanf("%i", &vr.ps);fflush(stdin);
  	  	  gotoxy(46,7); scanf("%li",&vr.hb);fflush(stdin);
        gotoxy(46,8); scanf("%i",&vr.lp);fflush(stdin);
	     gotoxy(46,9); scanf("%c",&sd);fflush(stdin);
	     if (sd=='y'||sd=='Y')
           {
         /*Buka File Data Untuk Di Tulis*/
         	fclose(vf);
	         vf=fopen("dpb.dat","a");
	         vr.kb=vkb;
            fwrite(&vr,sizeof(vr),1,vf);
            fclose(vf);
            gotoxy (25,13);printf("Data Berhasil Disimpan");
            }

     else
	  { gotoxy(25,14);printf("Data Tidak Disimpan");}

     }
     else
     { gotoxy(25,16);printf("Kode Barang Sudah Ada");}

     gotoxy(46,10);scanf("%c",&td);fflush(stdin);
  }
fclose(vf);
getch();
}