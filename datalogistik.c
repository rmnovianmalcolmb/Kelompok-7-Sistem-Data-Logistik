#include<stdio.h>
#include<time.h>

char a,namaBarang[1000][1000],kodeBarang[1000][1000];
int i,flag,jumlahBarang[1000][1000];

void waktu(){
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime (buffer, 80,"%A, %d %B %Y (%X)",info);
    printf("%s",buffer);
}

int main(){
    char menu;

    start:
        printf("---- Aplikasi Peminjaman Barang ----\n");
        printf("--------------- Menu ---------------\n");
        printf(" 1. Tambah Barang\n");
        printf(" 2. Hapus Barang\n");
        printf(" 3. Daftar Barang\n");
        printf(" 4. Peminjaman\n");
        printf(" 5. Pengembalian\n");
        printf(" 6. Laporan\n");
        printf(" 7. Exit\n");
        printf("------------------------------------\n");
        printf(" Masukkan pilihan anda [1 s.d. 6] = ");
        scanf(" %c",&menu);

    switch(menu){
    case '1':
        menu1:
		printf("\n---------- Tambah Barang -----------\n");
        do{
            flag=1;
            printf(" Kode Barang\t: ");
            scanf(" %i",&i);
            if(namaBarang[i][0] != '\0'){
                printf(" Kode ini sudah terpakai, masukkan kode lain\n\n");
                flag=0;
            }
            kodeBarang[i][0] = i;
        }while(flag==0);
        getchar();
        printf(" Nama Barang\t: ");
        scanf("%[^\n]s",&namaBarang[i]);
        printf(" Jumlah Barang\t: ");
        scanf("%i",&jumlahBarang[i][0]);
        printf(" Apakah Anda ingin menambahkan data lagi ? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu1;
        }
        else break;
    case '2':
        menu2:
        printf(" Kode barang yang akan dihapus\t: ");
        scanf(" %i",&i);
        namaBarang[i][0] = '\0';
        kodeBarang[i][0] = '\0';
        jumlahBarang[i][0] = '\0';
        printf(" Barang berhasil dihapus dari daftar barang\n Apakah Anda ingin menghapus data lagi? (y/n) : ");
        scanf(" %c",&a);
        if(a=='y'){
            goto menu2;
        }
        else break;
    case '3':
        printf("\n");
        printf("\t\t\tDaftar Buku");
        printf("\t\t\t___________\n");
        printf("------------------------------------------------------------------\n");
        printf(" Kode Barang\tNama Barang\tJumlah Barang\n");
        printf("------------------------------------------------------------------\n");
        for(i=0;i<1000;i++){
            if(kodeBarang[i][0] == '\0' || namaBarang[i][0] == '\0' || jumlahBarang[i][0] == '\0'){
                continue;
        }
        printf(" %i\t\t%s\t\t%i\n\n",kodeBarang[i][0],namaBarang[i],jumlahBarang[i][0]);
    }
        printf("\nKetik apa saja untuk kembali ke menu awal : ");
        scanf(" %s",&a);
        if(a==20){
            goto menu2;
        }
        else break;
    default :
        break;
    }
    printf("\n");
    goto start;
}

