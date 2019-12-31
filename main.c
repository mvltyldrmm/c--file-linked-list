#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct dugum { //bağlı listemiz için oluşturdğumuz düğüm
char kelime[100]; //Her bir düğümde tutulacak karakter sayısı 
struct dugum* next;
};
struct ogrenci{ //alacağımız kullanıcı bilgileri için struct yapısı
    char adi[20]; 
    char soyadi[20];
    float ortalama;
};

int main(){
    char dosya_ismi[50];
    printf("Yazilacak dosyanın ismi :");
    scanf("%s",&dosya_ismi);
    FILE *dosya = fopen(dosya_ismi,"w"); //dosyamızı oluşturup açıyorouz 'w' ile verileri yazıyoruz.
    int girdi;  
    while(true){ //Dosyaya birden fazla ogrenci bilgilerini eklemek için bir döngü oluşturduk.
        printf("Ogrenci kayit sistemine hosgeldiniz..\n");
        struct ogrenci ogrenci1;
        printf("Ogrenci adi: ");
        scanf("%s",&ogrenci1.adi);
        printf("Ogrenci Soyad: ");
        scanf("%s",&ogrenci1.soyadi);
        printf("Ogrenci Not Ortalamasi :");
        scanf("%f",&ogrenci1.ortalama);
        fprintf(dosya," %s  %s  %f\n",ogrenci1.adi,ogrenci1.soyadi,ogrenci1.ortalama); //dosyamıza bilgileri yazdırdık
        printf("Yeni kayit icin 1, cikis icin herhangi bir tus\n");
        scanf("%d",&girdi);
        if(girdi == 1){
            printf("Program devam ediyor.. \n");
            continue;
        }//end of if
        else {
            printf("Cikis yapiliyor..");
            break;
        }//end of else
    }//end of while
    fclose(dosya); // ALINAN BİLGİLER DOSYAYA KAYIT EDİLDİ. DOSYA KAPATILDI. ŞİMDİ OKUYUP BAĞLI LİSTEYE ATMAYA BAŞLIYORUZ.
    //close file
    dosya = fopen(dosya_ismi,"r"); //Oluşturduğumuz dosyayı tekrar açtık. 'r' sayesinde yalnızca okuyoruz.
    struct dugum* liste1 = (struct dugum*)malloc(sizeof(struct dugum)); //düğüm oluşturuldu
    struct dugum* iter1 = liste1; //taşıyıcı düğüm oluşturuldu
    while (!feof(dosya))  //dosyamız son satırına kadar okunuyor
    {
    char gecici[100];
    fscanf(dosya, "%s", gecici); // Dosyamızdan, verileri char türünden alıp geçici diziye atıyoruz.
    strcpy(iter1->kelime, gecici); // verileri düğüme kopyalıyoruz
    iter1->next = (struct dugum*)malloc(sizeof(struct dugum)); //bellekde yer ayırdık (malloc)
    iter1 = iter1->next; //bağlama işlemi
    }//end of while
    iter1 = liste1;
    printf("\n%s dosyanın icerigi :\n", dosya_ismi);
    while (iter1 != NULL) /*düğümün değeri boş olana kadar düğüme attığımız dosya 
    verilerini ekrana yazdırmak için while döngüsünü başlatıyoruz.*/
    {
    printf("%s\n", iter1->kelime);//düğümün verisini bastırıyoruz
    iter1 = iter1->next;//bir sonraki düğüme geçiyoruz
    }//end of while
    return 0;
}//end of main
