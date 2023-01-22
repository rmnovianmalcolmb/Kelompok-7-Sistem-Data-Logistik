#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define s 1000

FILE *data;
time_t rawtime;
struct tm *info;
char a,menu;
char status[s][s],belum[]="Belum Kembali",sudah[]="Sudah Kembali";
char namaBarang[s][s],CjumlahBarang[s][s],CkodeBarang[s][s],CjumlahPinjam[s][s],CkodePinjam[s][s];
char namaPinjam[s][s],lamaPinjam[s][s],waktuPinjam[s][s],barangPinjam[s][s],waktuKembali[s][s];
int kodeBarang[s][s],jumlahBarang[s][s],jumlahPinjam[s][s],kodePinjam[s][s];
int i=0,j=0,flag;

void menuAwal(){
    system("cls");
    printf("---- Sistem Data Logistik ITTS ----\n");
    printf("-------------- Menu ---------------\n");
    printf(" 1. Daftar Barang\n");
    printf(" 2. Tambah Barang\n");
    printf(" 3. Perbarui Jumlah Barang\n");
    printf(" 4. Hapus Barang\n");
    printf(" 5. Peminjaman\n");
    printf(" 6. Pengembalian\n");
    printf(" 7. Laporan Peminjaman\n");
    printf(" 8. Hapus Laporan Peminjaman\n");
    printf(" 9. Keluar Sistem\n");
    printf("------------------------------------\n");
    printf(" Masukkan pilihan anda [1 s.d. 8] = ");
}

void readPinjam()
{
    i = 0;
    data = fopen("kodePinjam.txt", "r");
    while(fgets(CkodePinjam[i], 100, data))
	{
        CkodePinjam[i][99] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("jumlahPinjam.txt", "r");
    while(fgets(CjumlahPinjam[i], 100, data))
	{
        CjumlahPinjam[i][99] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("namaPinjam.txt", "r");
    while(fgets(namaPinjam[i], 100, data))
	{
        namaPinjam[i][strlen(namaPinjam[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("lamaPinjam.txt", "r");
    while(fgets(lamaPinjam[i], 100, data))
	{
        lamaPinjam[i][strlen(lamaPinjam[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("waktuPinjam.txt", "r");
    while(fgets(waktuPinjam[i], 100, data))
	{
        waktuPinjam[i][strlen(waktuPinjam[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("barangPinjam.txt", "r");
    while(fgets(barangPinjam[i], 100, data))
	{
        barangPinjam[i][strlen(barangPinjam[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("status.txt", "r");
    while(fgets(status[i], 100, data))
	{
        status[i][strlen(status[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("waktuKembali.txt", "r");
    while(fgets(waktuKembali[i], 100, data))
	{
        waktuKembali[i][strlen(waktuKembali[i])-1] = '\0';
        i++;
    }
    fclose(data);
    for(int i=0;i<s;i++){
        sscanf(CkodePinjam[i],"%i",&kodePinjam[i]);
        sscanf(CjumlahPinjam[i],"%i",&jumlahPinjam[i]);
    }
}

void writePinjam()
{
    data = fopen("kodePinjam.txt","w");
    for(int i=0;i<s;i++){
        if (kodePinjam[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%i\n",kodePinjam[i][0]);
    }
    fclose(data);
    data = fopen("jumlahPinjam.txt","w");
    for(int i=0;i<s;i++){
        if (jumlahPinjam[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%i\n",jumlahPinjam[i][0]);
    }
    fclose(data);
    data = fopen("namaPinjam.txt","w");
    for(int i=0;i<s;i++){
        if (namaPinjam[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",namaPinjam[i]);
    }
    fclose(data);
    data = fopen("lamaPinjam.txt","w");
    for(int i=0;i<s;i++){
        if (lamaPinjam[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",lamaPinjam[i]);
    }
    fclose(data);
    data = fopen("waktuPinjam.txt","w");
    for(int i=0;i<s;i++){
        if (waktuPinjam[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",waktuPinjam[i]);
    }
    fclose(data);
    data = fopen("barangPinjam.txt","w");
    for(int i=0;i<s;i++){
        if (barangPinjam[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",barangPinjam[i]);
    }
    fclose(data);
    data = fopen("status.txt","w");
    for(int i=0;i<s;i++){
        if (status[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",status[i]);
    }
    fclose(data);
    data = fopen("waktuKembali.txt","w");
    for(int i=0;i<s;i++){
        if (waktuKembali[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",waktuKembali[i]);
    }
    fclose(data);
}

void writeBarang()
{
    data = fopen("kodeBarang.txt","w");
    for(int i=0;i<s;i++){
        if (kodeBarang[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%i\n",kodeBarang[i][0]);
    }
    fclose(data);
    data = fopen("namaBarang.txt","w");
    for(int i=0;i<s;i++){
        if (namaBarang[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%s\n",namaBarang[i]);
    }
    fclose(data);
    data = fopen("jumlahBarang.txt","w");
    for(int i=0;i<s;i++){
        if (kodeBarang[i][0] == '\0'){
        fprintf(data,"\n");
        continue;
        }
        fprintf(data,"%i\n",jumlahBarang[i][0]);
    }
    fclose(data);
}

void readBarang()
{
    i = 0;
    data = fopen("kodeBarang.txt", "r");
    while(fgets(CkodeBarang[i], 100, data))
	{
        CkodeBarang[i][99] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("namaBarang.txt", "r");
    while(fgets(namaBarang[i], 100, data))
	{
        namaBarang[i][strlen(namaBarang[i])-1] = '\0';
        i++;
    }
    fclose(data);
    i = 0;
    data = fopen("jumlahBarang.txt", "r");
    while(fgets(CjumlahBarang[i], 100, data))
	{
        CjumlahBarang[i][99] = '\0';
        i++;
    }
    fclose(data);
    for(int i=0;i<s;i++){
        sscanf(CkodeBarang[i],"%i",&kodeBarang[i]);
        sscanf(CjumlahBarang[i],"%i",&jumlahBarang[i]);
    }
}

void tambahBarang()
{
    menu2:
		printf("---------- Tambah Barang -----------\n");
        do{
            flag=1;
            printf(" Kode Barang\t: ");
            scanf(" %i",&i);
            if(kodeBarang[i][0] != '\0'){
                printf(" Kode ini sudah terpakai, masukkan kode lain\n\n");
                flag=0;
            }
        }while(flag==0);
        kodeBarang[i][0] = i;
        getchar();
        printf(" Nama Barang\t: ");
        scanf("%[^\n]s",&namaBarang[i]);
        printf(" Jumlah Barang\t: ");
        scanf("%i",&jumlahBarang[i][0]);
        printf(" Apakah Anda ingin menambahkan data lagi ? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu2;
        }
}

void updateBarang()
{
    printf(" Masukkan Kode Barang : ");
    scanf(" %i",&i);
    printf(" Kode Barang : %i\n",kodeBarang[i][0]);
    printf(" Nama Barang : %s\n",namaBarang[i]);
    printf(" Jumlah Barang Saat Ini : %i\n\n",jumlahBarang[i][0]);
    printf(" Jumlah Barang Baru : ");
    scanf(" %i",&jumlahBarang[i][0]);
}

void hapusBarang()
{
    menu4:
        printf(" Kode barang yang akan dihapus\t: ");
        scanf(" %i",&i);
        namaBarang[i][0] = '\0';
        kodeBarang[i][0] = '\0';
        jumlahBarang[i][0] = '\0';
        printf(" Barang berhasil dihapus dari daftar barang\n Apakah Anda ingin menghapus data lagi? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu4;
        }
}

void hapusPinjam()
{
    menu8:
        for(int i=1;i<s;i++){
        namaPinjam[i][0] = '\0';
        kodePinjam[i][0] = '\0';
        jumlahPinjam[i][0] = '\0';
        lamaPinjam[i][0] = '\0';
        waktuPinjam[i][0] = '\0';
        barangPinjam[i][0] = '\0';
        waktuKembali[i][0] = '\0';
        status[i][0] = '\0';
        }
        printf(" Data pinjam berhasil dihapus\n\n Ketik apa saja untuk kembali ke menu awal : ");
        getch();
        printf("\n");
}

void daftarBarang()
{
    printf("\n");
        printf("\t\t\tDaftar Barang\n");
        printf("------------------------------------------------------------------\n");
        printf(" Kode Barang\tNama Barang\tJumlah Barang\n");
        printf("------------------------------------------------------------------\n");
        for(i=0;i<s;i++){
            if(kodeBarang[i][0] == '\0' ){
                continue;
        }
        printf(" %i\t\t%s\t\t%i\n",kodeBarang[i][0],namaBarang[i],jumlahBarang[i][0]);
    }
        printf("\nKetik apa saja untuk kembali ke menu awal : ");
        getch();
        printf("\n");
}

void pinjamBarang()
{
    menu5:
    i = 1,j = 0;
    printf("\n---------- Peminjaman Barang -----------\n");
    for(i=1;i<s;i++){
        if (kodePinjam[i][0] == '\0')
            {break;}
        else continue;
    }
    kodePinjam[i][0] = i;
    printf(" Kode Pinjaman\t\t: %i\n",kodePinjam[i][0]);
    printf(" Nama Peminjam\t\t: ");
    scanf(" %[^\n]s",&namaPinjam[i]);
    do{
        flag=1;
        printf(" Kode barang\t\t: ");
        scanf(" %i",&j);
        if(kodeBarang[j][0] == '\0'){
            printf(" Kode salah, masukkan kode lain\n\n");
            flag=0;
        }
    }while(flag==0);
    getchar();
    printf(" Barang yang dipinjam\t: %s\n",namaBarang[j]);
    for(int z=0;z<s;z++){
        barangPinjam[i][z] = namaBarang[j][z];
    }
    menu52:
    printf(" Jumlah barang saat ini\t: %i\n",jumlahBarang[i][0]);
    printf(" Jumlah barang yang akan dipinjam : ");
    scanf(" %i",&jumlahPinjam[i][0]);
    if(jumlahPinjam[i][0] > jumlahBarang[j][0]){
        printf("\n Barang tidak mencukupi\n\n");
        goto menu52;
    }
    jumlahBarang[i][0] = jumlahBarang[i][0] - jumlahPinjam[j][0];
    printf(" Lama pinjam : ");
    scanf(" %[^\n]s",lamaPinjam[i]);
    time(&rawtime);
    info = localtime(&rawtime);
    strftime (waktuPinjam[i], s,"%d %B %Y (%X)",info);
    strcpy(status[i],belum);
    printf("\n--------------- Data Peminjaman Barang ---------------\n");
    printf(" Kode Pinjaman\t: %i\n",kodePinjam[i][0]);
    printf(" Nama Peminjam\t: %s\n",namaPinjam[i]);
    printf(" Kode Barang\t: %i\n",kodeBarang[i][0]);
    printf(" Nama Barang\t: %s\n",barangPinjam[i]);
    printf(" Jumlah barang\t: %i\n",jumlahPinjam[i][0]);
    printf(" Waktu Pinjam\t: %s\n",waktuPinjam[i]);
    printf(" Lama Pinjam\t: %s\n",lamaPinjam[i]);
    printf(" Ketik apa saja untuk kembali ke menu awal : ");
    getch();
    printf("\n");
}

void pengembalian()
{
    menu6:
    i=1;
    printf("\n---------- Pengembalian Barang -----------\n");
    printf(" Masukkan Kode Pinjam : ");
    scanf("%i",&i);
    if(kodePinjam[i][0] == '\0'){
        printf("Kode tidak valid\n");
        goto menu6;
    }
    printf("\n");
    printf(" Kode Pinjaman\t: %i\n",kodePinjam[i][0]);
    printf(" Nama Peminjam\t: %s\n",namaPinjam[i]);
    printf(" Kode Barang\t: %i\n",kodeBarang[i][0]);
    printf(" Nama Barang\t: %s\n",barangPinjam[i]);
    printf(" Jumlah barang\t: %i\n",jumlahPinjam[i][0]);
    printf(" Waktu Pinjam\t: %s\n",waktuPinjam[i]);
    printf(" Lama Pinjam\t: %s\n",lamaPinjam[i]);
    printf(" Apakah data sudah betul? (y/n) : ");
    scanf(" %c",&a);
    if(a == 'n'){
        goto menu6;
    }
    jumlahBarang[i][0] = jumlahBarang[i][0] + jumlahPinjam[j][0];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime (waktuKembali[i], s,"%d %B %Y",info);
    strcpy(status[i],sudah);
}
void daftarPinjam()
{
    printf("\n");
    printf("\t\t\tDaftar Barang\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf(" Kode Pinjam\tNama Peminjam\tBarang\tJumlah\tLama Pinjam\tWaktu Pinjam\t\t\tStatus\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    for(i=1;i<s;i++){
        if(kodePinjam[i][0] == '\0' ){
            continue;
    }
    printf(" %i\t\t%s\t\t%s\t%i\t%s\t\t%s\t%s %s",kodePinjam[i][0],namaPinjam[i],barangPinjam[i],jumlahPinjam[i][0],lamaPinjam[i],waktuPinjam[i],status[i],waktuKembali[i]);
    }
    printf("\n\n Ketik apa saja untuk kembali ke menu awal : ");
    getch();
    printf("\n");
}

int main(){
    start:
    readBarang();
    readPinjam();
    menuAwal();
    scanf(" %c",&menu);
    system("cls");
    switch(menu){
    case '1':
        daftarBarang();
        break;
    case '2':
        tambahBarang();
        writeBarang();
        break;
    case '3':
        updateBarang();
        writeBarang();
        break;
    case '4':
        hapusBarang();
        writeBarang();
        break;
    case '5':
        pinjamBarang();
        writePinjam();
        writeBarang();
        break;
    case '6':
        pengembalian();
        writePinjam();
        writeBarang();
        break;
    case '7':
        daftarPinjam();
        break;
    case '8':
        hapusPinjam();
        writePinjam();
        break;
    case '9':
        return 0;
    default :
        break;
    }
    printf("\n");
    goto start;
}
