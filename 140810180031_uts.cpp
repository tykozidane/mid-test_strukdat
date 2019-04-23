/*
Nama	: tyko zidane badhawi
NPM		: 140810180031
Kelas	: A
Program	: Turnamen Sepakbola Pelajar 2019
*/
#include<iostream>
using namespace std;
struct Data{
	int no;
	char tim[20];
	char asal[20];
	int gol;
	Data* next;
};
typedef Data* pointer;
typedef pointer List;
void createList(List& First){
	First=NULL;
}
void createElement(pointer& pBaru){
	pBaru=new Data;
	cout << "No Daftar	: "; cin >> pBaru->no;
	cout << "Nama Tim	: "; cin >> pBaru->tim;
	cout << "Daerah Asal	: "; cin >> pBaru->asal;
	pBaru->next=NULL;
}
void insertLast(List& First, pointer pBaru){
	pointer last;
	if (First==NULL){
		First=pBaru;
	}
	else {
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}
void update (List& First){
	pointer pBantu;
	pBantu=First;
	while(pBantu!=NULL){
		cout << "Tim	"<< pBantu->tim<<endl;
		cout << "Masukan Nilai gol	: "; cin >> pBantu->gol;
		pBantu=pBantu->next;
	}
}
void traversal(List First, int n){
	pointer pBantu, pTuker;
	pBantu=First;
	cout << "No. Daftar\tTim\t\tGol\n";
	for (int i=0; i<n;i++){
		if(pBantu->gol<pBantu->next->gol){
			First=pBantu->next;
			pBantu->next=First->next;
			First->next=pBantu;
		}
		while(pBantu->next->next!=NULL){
			if(pBantu->next->gol<pBantu->next->next->gol){
				pTuker=pBantu->next;
				pBantu->next=pTuker->next;
				pTuker->next=pTuker->next->next;
				pBantu->next->next=pTuker;
			}
			pBantu=pBantu->next;
		}
	}
	while(First!=NULL){
		cout <<First->no <<"\t\t"<<First->tim<<"\t"<<First->gol<< endl;
		First=First->next;
	}
	
}
int main(){
	pointer p;
	List First;
	int n;
	cout << "Jumlah Tim	: ";
	cin >> n;
	createList(First);
	for (int i=0; i<n; i++){
		createElement(p);
		insertLast(First, p);
	}
	update(First);
	traversal(First, n);
}
