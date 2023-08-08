#include<stdio.h>
#include<conio.h>
main()
{
FILE*rkg;
float bn;
float pk;
float tl,ttl;
long int x,br;
struct
{ int nbp;
  char nr[16];
  char nm[25];
  int dy;
  long int mbl;
  long int mbi;
}vr;
rkg=fopen("rekening.dat","r");
clrscr();
gotoxy(30,1);printf("Rekening Pembayaran PLN");
gotoxy(1,2);printf("---------------------------------------------------------------------------");
gotoxy(1,3);printf("|No|Bukti|  Norek  |Nama Pelanggan |Daya| Mbi | Mbl |Pakai|Beban|  Total  |");
gotoxy(1,4);printf("|  |Bayar|         |               |    |     |     |     |     |         |");
gotoxy(1,5);printf("---------------------------------------------------------------------------");
						/*12345678901234567890123456789012345678901234567890123456789012345678901234567890 */
						/*         1         2         3         4         5         6         7         8 */
br=6;x=0; ttl=0;
while (fread(&vr,sizeof(vr),1,rkg)==1)
{     pk=vr.mbi-vr.mbl;
		if (vr.dy==450)
		{ bn=35000;}
      else if (vr.dy==900)
      { bn=40000;}
      else if (vr.dy==1200)
      { bn=45000;}
      tl=(pk*500)+bn;
      ttl=ttl+tl;
      x=x+1;
      gotoxy(1,br);printf("| %li",x);
      gotoxy(4,br); printf("| %i", vr.nbp);
      gotoxy(10,br); printf("| %s", vr.nr);
      gotoxy(20,br);printf("| %s", vr.nm);
      gotoxy(36,br);printf("| %i", vr.dy);
      gotoxy(41,br);printf("| %li", vr.mbi);
      gotoxy(47,br);printf("| %li", vr.mbl);
      gotoxy(53,br);printf("| %5.1f", pk);
      gotoxy(59,br);printf("| %5.1f", bn);
      gotoxy(65,br);printf("| %8.1f", tl);
      gotoxy(75,br);printf("|");
      br=br+1;
}
gotoxy(1,br);printf("---------------------------------------------------------------------------");
br=br+1;
gotoxy(1,br);printf("|Total  ");printf("                                                        |%8.1f |", ttl);
br=br+1;
gotoxy(1,br);printf("---------------------------------------------------------------------------");
fclose(rkg);
getch();
}