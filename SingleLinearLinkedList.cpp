#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    int no_peserta;
    int NIM;
    char kelas;
    Mahasiswa*next;
};
void printList(Mahasiswa*n)
{
      while (n!=NULL)
      {
          cout<<"No peserta : "<<n->no_peserta<<" "<<endl;
          cout<<"NIM        : "<<n->NIM<<" "<<endl;
          cout<<"Kelas      : "<<n->kelas<<" "<<endl;
          cout<<endl;
          n = n->next;
      }
}
int main ()
{
    Mahasiswa*head = NULL;
    Mahasiswa*second= NULL;
    Mahasiswa*third= NULL;
    
    head=new Mahasiswa();
    second= new Mahasiswa();
    third= new Mahasiswa();
    
    head->no_peserta=01;
    head->NIM=123;
    head->kelas='B';
    head->next=second;
    
    second->no_peserta=02;
    second->NIM=456;
    second->kelas='B';
    second->next=third;
    
    third->no_peserta=03;
    third->NIM=789;
    third->kelas='B';
    third->next=NULL;
    
    printList(head);
    
    cin.get();
    return 0;
    
 }
