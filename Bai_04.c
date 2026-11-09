#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode
{
    Data infor;
    struct tagNode *link;
} Node;
typedef struct
{
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L)
{
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptyList(LList L)
{
    return L.spt == 0;
}

void nhap(Data *x)
{
    printf("Nhap ma SV: ");
    scanf("%d", &x->masv);

    if (x->masv > 0)
    {
        printf("Nhap ho ten: ");
        scanf("%s", x->hoten);

        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);

        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);

        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}

// in ttinsv
void in(Data x)
{
    printf("\nMa SV: %d", x.masv);
    printf("\nHo ten: %s", x.hoten);
    printf("\nDiem 1: %.2f", x.d1);
    printf("\nDiem 2: %.2f", x.d2);
    printf("\nDiem 3: %.2f\n", x.d3);
}

// Them node vao dau
void insert_Head(LList *L, Data x)
{
    Node *pp = (Node *)malloc(sizeof(Node));

    if (pp == NULL)
        return;

    pp->infor = x;
    pp->link = L->pHead;

    if (emptyList(*L))
    {
        L->pTail = pp;
    }

    L->pHead = pp;
    L->spt++;
}

// Them node vao cuoi
void insert_Tail(LList *L, Data x)
{
    Node *pp = (Node *)malloc(sizeof(Node));

    if (pp == NULL)
        return;

    pp->infor = x;
    pp->link = NULL;

    if (emptyList(*L))
    {
        L->pHead = pp;
        L->pTail = pp;
    }
    else
    {
        L->pTail->link = pp;
        L->pTail = pp;
    }

    L->spt++;
}

Node *timkiemnode(LList L, int masv)
{
    Node *pp = L.pHead;

    while (pp != NULL)
    {
        if (pp->infor.masv == masv)
            return pp;

        pp = pp->link;
    }

    return NULL;
}

void themnodedangsau(LList *L, Node *q, Data x)
{
    if (q == NULL)
        return;

    Node *pp = (Node *)malloc(sizeof(Node));

    if (pp == NULL)
        return;

    pp->infor = x;

    pp->link = q->link;
    q->link = pp;

    if (q == L->pTail)
    {
        L->pTail = pp;
    }

    L->spt++;
}

void xoanode(LList *L, int masv)
{
    if (emptyList(*L))
    {
        printf("Danh sach rong!\n");
        return;
    }

    Node *pp = L->pHead;
    Node *prev = NULL;

    while (pp != NULL && pp->infor.masv != masv)
    {
        prev = pp;
        pp = pp->link;
    }

    if (pp == NULL)
    {
        printf("Khong tim thay sinh vien!\n");
        return;
    }

    if (prev == NULL)
    {
        L->pHead = pp->link;
    }
    else
    {
        prev->link = pp->link;
    }

    if (pp == L->pTail)
    {
        L->pTail = prev;
    }

    free(pp);
    L->spt--;

    if (L->spt == 0)
    {
        L->pHead = NULL;
        L->pTail = NULL;
    }

    printf("Xoa sinh vien thanh cong!\n");
}

void processList(LList L)
{
    if (emptyList(L))
    {
        printf("Danh sach rong!\n");
        return;
    }

    Node *pp = L.pHead;

    printf("\n===== DANH SACH SINH VIEN =====\n");

    while (pp != NULL)
    {
        in(pp->infor);
        pp = pp->link;
    }

    printf("\nTong so sinh vien: %d\n", L.spt);
}

void clearList(LList *L)
{
    Node *pp = L->pHead;

    while (pp != NULL)
    {
        Node *temp = pp;
        pp = pp->link;
        free(temp);
    }

    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int main()
{
    LList L;
    Data x;
    int kt = 0;
    int chon;
    int masv;
    Node *q;

    initList(&L);

    do
    {
        printf("\nQUAN LY SINH VIEN\n");
        printf("1. Them node vao dau danh sach\n");
        printf("2. Them node vao cuoi danh sach\n");
        printf("3. Them node sau mot node khac\n");
        printf("4. Xoa sinh vien theo ma\n");
        printf("9. Duyet danh sach\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");

        scanf("%d", &chon);

        switch (chon)
        {
        case 1:
            nhap(&x);

            if (x.masv > 0)
                insert_Head(&L, x);
            break;

        case 2:
            nhap(&x);

            if (x.masv > 0)
                insert_Tail(&L, x);
            break;

        case 3:
            printf("Nhap ma SV muon them phia sau: ");
            scanf("%d", &masv);

            q = timkiemnode(L, masv);

            if (q == NULL)
            {
                printf("Khong tim thay sinh vien!\n");
            }
            else
            {
                printf("Nhap thong tin sinh vien moi:\n");
                nhap(&x);

                if (x.masv > 0)
                    themnodedangsau(&L, q, x);
            }
            break;

        case 4:
            printf("Nhap ma SV can xoa: ");
            scanf("%d", &masv);

            xoanode(&L, masv);
            break;

        case 9:
            processList(L);
            break;

        case 0:
            clearList(&L);
            printf("Da thoat chuong trinh!\n");
            kt = 1;
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (kt == 0);

    return 0;
}
