#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
FILE*kjw;
int br,x;
char ket[15],hr[6];
int bm,tbm;
struct
 { char no[5];
   char np[15];
   int kh;
   char ku;
 }wst;

kjw=fopen("wisata.dat","r");
clrscr();
gotoxy(23,1);printf("Laporan Data Pengunjung Wisata");
gotoxy(1,2);printf("----------------------------------------------------------------------");
gotoxy(1,3);printf("|No|No   | Nama          |Kode| Hari |Kel | Keterangan    | Biaya    |");
gotoxy(1,4);printf("|  |     |               |    |      |    |               |          |");
gotoxy(1,5);printf("|  |Peng.| Pengunjung    |Hari|      |Umur|               | Masuk    |");
gotoxy(1,6);printf("----------------------------------------------------------------------");
						/*12345678901234567890123456789012345678901234567890123456789012345678901234567890 */
						/*         1         2         3         4         5         6         7         8 */
br=7;x=0; tbm=0;
while (fread(&wst,sizeof(wst),1,kjw)==1)
{    if (wst.ku=='A')
		{ strcpy(ket, "Anak-Anak");}
     else
      { strcpy(ket, "Dewasa");}


		if (wst.kh==1)
		{ strcpy(hr, "Senin");}
      else if(wst.kh==2)
      { strcpy(hr, "Selasa");}
      else if(wst.kh==3)
      { strcpy(hr, "Rabu");}
      else if(wst.kh==4)
      { strcpy(hr, "Kamis");}
      else if(wst.kh==5)
      { strcpy(hr, "Jum'at");}
      else if(wst.kh==6)
      { strcpy(hr, "Sabtu");}
      else if(wst.kh==7)
      { strcpy(hr, "Minggu");}


      if (wst.kh==7)
		{
          if (wst.ku=='A')
          { bm=10000;}
          else
          { bm=25000;}
      }
      else
      {
          if (wst.ku=='A')
          { bm=5000;}
          else
          { bm=15000;}
      }
      tbm=tbm+bm;

      x=x+1;
      gotoxy(1,br);printf("|%i",x);
      gotoxy(4,br); printf("|%s", wst.no);
      gotoxy(10,br); printf("| %s", wst.np);
      gotoxy(26,br);printf("|%i", wst.kh);
      gotoxy(31,br);printf("|%s", hr);
      gotoxy(38,br);printf("| %c", wst.ku);
      gotoxy(43,br);printf("| %s", ket);
      gotoxy(59,br);printf("| %i", bm);
      gotoxy(70,br);printf("|");
      br=br+1;
 }

gotoxy(1,br);printf("----------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total Biaya Masuk  ");printf("                                      | %i    |", tbm);
br=br+1;
gotoxy(1,br);printf("----------------------------------------------------------------------");
fclose(kjw);
getch();
}
