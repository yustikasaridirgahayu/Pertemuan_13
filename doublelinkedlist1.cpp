#include <iostream> 
#include <stdlib.h> 
using namespace std;
//Node Class
class Node
{
private:
  int data;
  Node *pNext;
  Node *pPrevious;
public:
  Node(int d):data(d),pNext(NULL),pPrevious(NULL){}
  int getData()const{return data;}
  void setData(int d){data=d;}
  Node *getNext()const{return pNext;}
  void setNext(Node *p){pNext=p;}
  Node *getPrevious()const{return pPrevious;}
  void setPrevious(Node *p){pPrevious=p;}
};

//LinkedList class
class LinkedList
{
protected:
  Node *pHead; //petunjuk (pointer) untuk node awal
  Node *pTail; //petunjuk (pointer) untuk node terakhir
  int nodeCounter; //menghitung jumlah angka pada node
  Node *makeNode(int data); //membuat dan menukar nodee baru
  void remove(Node *tmp); //menghilangkan node dari data yang dihubungkan (liked list)
public:
  LinkedList();
  ~LinkedList();

//pengoprasian
  void addFirst(int data); 
  void addLast(int data);
  void addBefore(int index, int data);
  void removeFirst();
  void removeLast();
  void displayInOrder()const;
  void displayInReverseOrder()const;
  void destroyList();
  int getSize()const{return nodeCounter;}
};
LinkedList::LinkedList():
pHead(NULL),pTail(NULL),nodeCounter(0)
{}
LinkedList::~LinkedList()
{
  destroyList();
}
void LinkedList::displayInOrder()const
{
  if( !pHead )
   {
    cout<<"\nNULL";
      return;
    }
    for(Node *cur=pHead;cur!=NULL;cur=cur->getNext())
      cout<<cur->getData()<<"->";
       cout<<"NULL"<<endl;
   }
void LinkedList::displayInReverseOrder()const  
{
  if (!pHead )
   {
    cout<<"\nNULL";
       return;
    }
    for(Node *cur=pTail;cur!=NULL;cur=cur->getPrevious())
      cout<<cur->getData()<<"-> ";
        cout<<"NULL"<<endl;
}
Node * LinkedList::makeNode(int data)
{
  nodeCounter++;
    return new Node(data);
}
void LinkedList::addFirst(int data) 
{
  //membuat node baru
   Node *pNew=makeNode(data); //membuat node baru sebagai node pertama atau awal pada data yang dibubungkan(linked list)
   if( !pHead ) //jika data yang dihubungkan atau yang dimasukkan tersebut kosong
      pHead=pTail=pNew;
   else //jika terdapat beberapa node
   {
      pNew->setNext(pHead);
      pHead->setPrevious(pNew);
        pHead=pNew;
    }
 }
void LinkedList::addLast(int data)
{
//membuat node baru
  Node *pNew=makeNode(data);
    //membuat node baru sebagai node terakhir pada data yang dihubungkan (linked list)
    //jika pada kondisi tidak terdapat node pada data yang dihubungkan (linked list),maka ditambah node lagi
    //cara lain untuk memindahkan sebuah node bau ke tempat node yang terakhir
   
   if(!pHead)
      pHead=pTail=pNew;
    else
   {
    pTail->setNext(pNew);
    pNew->setPrevious(pTail);
     pTail=pNew;
   }
}
void LinkedList::addBefore(int index,int data)
{
//mencetak atau memeriksa index untuk mengetahui apakah data yang dimasukan sesuai atau tidak
   if( index <1 ||index > getSize())
    {
      cerr<<"\nError: index is to hight/low";
        return;
    }
   if(index == 1)
    {
      addFirst(data);
         return;
    }
    //membuat node baru
      Node *pNew=makeNode(data);
      Node *pCur=pHead;
      for(int i=1;i<index -1;i++,pCur=pCur->getNext());
      pNew->setNext(pCur->getNext());
      pCur->setNext(pNew);
}
void LinkedList::removeFirst()
{
  if ( !pHead )
   {
    cerr<<"\nTidak ada node yang akan dihilangkan!!";
       return;
   }
   Node *pTmp=pHead;
   pHead=pHead->getNext();
    if(pHead)
      pHead->setPrevious(NULL);
    else
      pHead=pTail=NULL;
   remove(pTmp);
}
void LinkedList::remove(Node *tmp)
{
  delete tmp;
  nodeCounter--;
 };
void LinkedList::removeLast()
{
  if(!pHead)
   {
     cerr<<"\nTidak ada node yang akan dihilangkan!!";
       return;
    }
    Node *pTmp=pTail;
    pTail=pTail->getPrevious();
    if(pTail)
      pTail->setNext(NULL);
    else
      pTail=pHead=NULL;
     remove(pTmp);
}
void LinkedList::destroyList()
{
  Node *pTmp=pHead;
  Node *pCur;
  while(pTmp!=NULL)
   {
    pCur=pTmp;
    pTmp=pTmp->getNext();
    remove(pCur);
    }
}

//fungsi utama
int main()
{
LinkedList *p=new LinkedList;
   for(int i=0; i<5; i++)
      p->addLast(2*i+1);
  cout<<"\ndata yang telah dihubungkan atau dimasukkan pada fungsi perintah:\n";
    p->displayInOrder();
  cout<<"\ndata yang telah dibalikkan pada fungsi perintah:\n";
    p->displayInReverseOrder();
  cout<<"\nmenambahkan 2 sebelum node ke dua (3). \n";
    p->addBefore(2,2);
  cout<<"\nmenambahkan 4 sebelum node ke empat (5). \n";
    p->addBefore(4,4);
  cout<<"\nmenambahkan 6 sebelum node ke enam (7). \n";
    p->addBefore(6,6);
  cout<<"\nmenambahkan 8 sebelum node kedelapan (9). \n";
    p->addBefore(8,8);
   cout<<"\ndata yang telah dihubungkan atau dimasukan pada fungsi perintah : \n";
    p->displayInOrder();

  return 0;
}
