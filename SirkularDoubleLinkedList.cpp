#include <stdio.h>

typedef struct Tnode
{
  int value;
  Tnode *next;
  Tnode *back;
};

Tnode *baru, *bantu, *head, *tail;

void tambah(int value)
{
     baru = new Tnode;
     baru->next = baru;//menunjuk pointer ke selanjutnya
     baru->back = baru;//menunjuk pointer ke sebelumnya
     baru->value = value;//menunjuk pointer ke value
}
void tambahbelakang(int value)//fungsi menambah data di belakang
{
     tambah(value);
     if(head == NULL)
        head = tail = baru;
     else{
        tail->next = baru;
        baru->back = tail;
        tail = baru;
     }
     tail->next = head;
     head->back = tail;
}
void tambahdepan(int value)//fungsi penambahan nilai di depan
{
     tambah(value);
     if(head == NULL)
        head = tail = baru;
     else {
        baru->next = head;
        head->back = baru;
        head = baru;
     }
     tail->next = head;
     head->back = tail;
 }
 
 void cetak()//fungsi mencetak data
 {
     bantu = head;
     do
     {
      printf("%d",bantu->value);
      bantu = bantu->next;
     }while(bantu!=head);
  }
void menu(){
     int pil;
     int isi;
     do {
         printf("Menu :\n1.Masuk dari depan\n2.Masuk dari belakang\n3.Cetak\n4.Exit\nMasukkan pilihan anda");
         scanf("%d",&pil);
         switch(pil){
                   case 1 :
                        printf("Masukkan nilai : "); scanf("%d",&isi);
                        tambahdepan(isi);
                        break;
                   case 2 :
                        printf("Masukkan nilai : "); scanf("%d",&isi);
                        tambahbelakang(isi);
                        break;
                   case 3 : cetak();
                        break;
                   case 4 : printf("Terima kasih");
                        break;
                        
                   default :
                        printf("Tidak ada pilihan tersebut, masukkan angka dari 1 sampai 3");
            }
       }
       while(pil!=4);
    }
    
  int main()//fungsi utama program
  {
    menu();
          return 0;
  }
