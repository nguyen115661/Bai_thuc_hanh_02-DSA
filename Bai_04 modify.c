#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;
/////////////////////////////////////
void initList(LList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L)
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
///////////////////////////////////////
void them_Cuoi(LList *L, Data x){
	Node *pp;
	pp = (Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else{
		L->pTail->link = pp;
		L->pTail = pp;
	}
	L->spt++;
}
///////////////////////////////////////
void them_Sau(LList *L, Node *q, Data x){
	Node *pp;
	if(NULL == q){
		return;
	}
	else{
		pp = (Node *) malloc(sizeof(Node));
		pp->infor = x;
		pp->link = q->link;
		q->link = pp;
		if(q == L->pTail) L->pTail = pp;
		L->spt++;
	}
}
///////////////////////////////////////
void xoa_dau_danh_sach(LList *L){
	Node *pp;
	if(emptyList(*L)) return;
	else{
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if(L->pHead == NULL) L->pTail = NULL;
	}
}
///////////////////////////////////////
void xoa_tuy_chon(LList *L, Node *q){
	Node *pp;
	if(NULL == q) return;
	else{
		pp = q->link;
		if(q->link == L->pTail){
			L->pTail = q;
		}
		q->link = pp->link;
		free(pp);
		L->spt--;
	}
}

void sap_xep(LList *L){
	Node *q, *p;
	Data t;
	for(q = L->pHead; q != NULL; q = q->link){
		for(p = q->link; p != NULL; p = p->link){
			if(strcmp(q->infor.hoten, p->infor.hoten) > 0){
				t = q->infor;
				q->infor = p->infor;
				p->infor = t;
			}
		}
	}
}

void tach_danh_sach(LList L, LList *L1, LList *L2){
	initList(L1);
	initList(L2);
	Node *pp = L.pHead;
	while(pp != NULL){
		if(pp->infor.masv < 50){
			them_Cuoi(L1, pp->infor);
		}
		else{
			them_Cuoi(L2, pp->infor);
		}
		pp = pp->link;
	}
}

void ghep(LList L1, LList L2, LList *L){
	initList(L);
	Node *p1 = L1.pHead;
	Node *p2 = L2.pHead;
	if(L1.spt < L2.spt){
		while(p1 != NULL){
			them_Cuoi(L, p1->infor);
			them_Cuoi(L, p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		}
		while(p2 != NULL){
			them_Cuoi(L, p2->infor);
			p2 = p2->link;
		}
	}
	else{
		while(p2 != NULL){
			them_Cuoi(L, p1->infor);
			them_Cuoi(L, p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		}
		while(p1 != NULL){
			them_Cuoi(L, p1->infor);
			p1 = p1->link;
		}
	}
}
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ho ten: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in d? li?u trong node 
        	pp = pp->link;
    	}
}
/////////////////////////////////////////

int main(){
    LList L, L1, L2;
	int kt = 0;
	Data x;
	initList(&L); //tao ra 1 ds rong
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n4: Xoa phan tu o dau danh sach");
	    printf("\n5: Xoa phan tu o sau phan tu khac trong danh sach");
	    printf("\n6: Sap xep danh sach");
	    printf("\n7: Tach danh sach");
	    printf("\n8: Ghep danh sach");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap thong tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sinh vien can them\n");
	            nhap(&x);
	            if(x.masv > 0)
	            	them_Cuoi(&L, x);
            	break;
            case 3:{
            	printf("Nhap thong tin sinh vien can them\n");
	            nhap(&x);
	            printf("Nhap ma sinh vien muon dien vao sau\n");
	            int ma;
	            scanf("%d", &ma);
	            Node *q = L.pHead;
	            while(q != NULL && q->infor.masv != ma){
	            	q = q->link;
				}
	            
	            if(x.masv > 0){
	            	them_Sau(&L, q, x);
				}
            	break;
			}
			case 4:{
				xoa_dau_danh_sach(&L);
				break;
			}
			case 5:{
				int ma;
				printf("Nhap ma sinh vien can xoa");
				scanf("%d", &ma);
				Node *q = L.pHead;
				while(q!= NULL && q->infor.masv != ma){
					q = q->link;
				}
				xoa_tuy_chon(&L, q);
				break;
			}
			case 6:{
				printf("Dang sap xep danh sach\n");
				sap_xep(&L);
				break;
			}
			case 7:{
				printf("Tach danh sach\n");
				tach_danh_sach(L, &L1, &L2);
				break;
			}
			case 8:{
				printf("Ghep danh sach\n");
				ghep(L1, L2, &L);
				break;
			}
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}