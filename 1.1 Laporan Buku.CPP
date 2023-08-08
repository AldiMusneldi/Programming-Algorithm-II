#include<stdio.h>
#include<conio.h>
main()
{
FILE*vf;
long int br;
struct
{ char kb[5];
  char jb[25];
  char pg[20];
  char pn[20];
  int jml;
}vr;
vf=fopen("dbuku.dat","r");
clrscr();
gotoxy(35,1);printf("LAPORAN DATA BUKU");
gotoxy(1,2);printf("----------------------------------------------------------------------------------");
gotoxy(1,3);printf("| KODE |       JUDUL BUKU      |     PENGARANG     |       PENERBIT      | JML |");
gotoxy(1,4);printf("----------------------------------------------------------------------------------");
                  /*12345678901234567890123456789012345678901234567890123456789012345678901234567890 */
                  /*         1         2         3         4         5         6         7         8 */
br=5;
while(fread(&vr,sizeof(vr),1,vf)==1)
{
      gotoxy(1,br); printf("| %s", vr.kb);
      gotoxy(8,br); printf("| %s", vr.jb);
      gotoxy(32,br);printf("| %s", vr.pg);
      gotoxy(52,br);printf("| %s", vr.pn);
      gotoxy(74,br);printf("| %li", vr.jml);
      gotoxy(80,br);printf("|");
      br=br+1;
}
gotoxy(1,br);printf("----------------------------------------------------------------------------------");
fclose(vf);
getch();
}