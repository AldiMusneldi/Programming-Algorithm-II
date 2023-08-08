#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
FILE*mhs;
char ket[10];
float tn;
long int x,br;
struct
{char np[8] ;
 char ncm[15];
 char kpp[6];
 int nat;
 int nkd;
}vr;
mhs=fopen("mahasiswa.dat","r");
clrscr();
gotoxy(20,1);printf("Laporan Data Penyeleksian Mahasiswa Baru");
gotoxy(1,2);printf("-------------------------------------------------------------------------------");
gotoxy(1,3);printf("| No | No.       | Nama Calon Mahasiswa |Nilai   |Nilai  | Total | Keterangan |");
gotoxy(1,4);printf("|    | Daftar    |                      |Aptitude|K.Dasar| Nilai |            |");
gotoxy(1,5);printf("-------------------------------------------------------------------------------");
						/*12345678901234567890123456789012345678901234567890123456789012345678901234567890 */
						/*         1         2         3         4         5         6         7         8 */
br=6;x=0;
while (fread(&vr,sizeof(vr),1,mhs)==1)
{     tn=0.65*vr.nat+0.35*vr.nkd;
		if (tn>=65)
		{ strcpy(ket, "Lulus");}
      else
      { strcpy(ket, "Gagal");}
      x=x+1;
      gotoxy(1,br);printf("| %li",x);
      gotoxy(6,br); printf("| %s", vr.np);
      gotoxy(18,br); printf("| %s", vr.ncm);
      gotoxy(41,br);printf("| %i", vr.nat);
      gotoxy(50,br);printf("| %i", vr.nkd);
      gotoxy(58,br);printf("| %5.1f", tn);
      gotoxy(66,br);printf("| %s", ket);
      gotoxy(79,br);printf("|");
      br=br+1;
}
gotoxy(1,br);printf("-------------------------------------------------------------------------------");
fclose(mhs);
getch();
}
