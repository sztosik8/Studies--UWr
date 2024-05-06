
// https://eduinf.waw.pl/inf/alg/001_search/0119.php
#include <iostream>
using namespace std;

struct node
{
    // private:
    node *up;
    node *left;
    node *right;

    int key;
    int bf;
};

void RR();
void RL();
void LR();
void LL();

void insert(int x);
void upper(int x);
void lower(int x);
void delate(int x);

void RR(node *v)
{
    node a = *v;
    node b = *a.right;
    b.up = a.up;
    a.right = b.left;
    a.up = &b;
    b.left = &a;

    if (b.bf == -1)
    {
        a.bf = 0;
        b.bf = 0;
    }
    else
    {
        a.bf = -1;
        b.bf = 1;
    }
}
void LL(node *v)
{
    node a = *v;
    node b = *a.left;
    b.up = a.up;
    a.up = &b;
    a.left = b.right;
    b.right = &a;

    if (b.bf == 1)
    {
        a.bf = 0;
        b.bf = 0;
    }
    else
    {
        a.bf = 1;
        b.bf = -1;
    }
}
void RL(node *A)
{
    node *B = A->right, *C = B->left, *p = A->up;

    B->left = C->right;
    if (B->left)
        B->left->up = B;

    A->right = C->left;
    if (A->right)
        A->right->up = A;

    C->left = A;
    C->right = B;
    A->up = B->up = C;
    C->up = p;

    if (p)
    {
        if (p->left == A)
            p->left = C;
        else
            p->right = C;
    }

    if (C->bf == -1)
        A->bf = 1;
    else
        A->bf = 0;
    if (C->bf == 1)
        B->bf = -1;
    else
        B->bf = 0;

    C->bf = 0;
}

/*void RL(node *v)
{

    node *a = v;
    node *b = a->right;
    LL(b);
    RR(a);
}*/

void LR(node *A)
{
    node *B = A->left, *C = B->right, *p = A->up;

    // RR(B);
    // LL(A);

    B->right = C->left;
    if (B->right)
        B->right->up = B;

    A->left = C->right;
    if (A->left)
        A->left->up = A;

    C->right = A;
    C->left = B;
    A->up = B->up = C;
    C->up = p;

    if (p)
    {
        if (p->left == A)
            p->left = C;
        else
            p->right = C;
    }

    if (C->bf == 1)
        A->bf = -1;
    else
        A->bf = 0;
    if (C->bf == -1)
        B->bf = 1;
    else
        B->bf = 0;

    C->bf = 0;
}

/*
void LR(node *v)
{
    node a = *v;
    node b = *a.right;
    RR(&b);
    LL(&a);
}*/

void insert(node *&root, int x)
{
    node *w, *p, *r;
    bool t;
    w = new node;
    w->key = x;
    w->left = NULL;
    w->right = NULL;
    w->up = NULL;
    w->bf = 0;

    p = root;

    if (!p)
        root = w; // jeśli drzewo jest puste, to węzeł w umieszczamy w korzeniu
    else
    { // inaczej szukamy miejsce dla w
        while (true)
        {
            if (x == p->key)
                return;

            else if (x < p->key) // porównujemy klucze
            {
                if (!p->left) // jeśli p nie posiada lewego syna, to
                {
                    p->left = w; // lewym synem p staje się węzeł w
                    break;       // wychodzimy z pętli
                }
                p = p->left; // inaczej przechodzimy do lewego syna
            }
            else
            {
                if (!p->right) // jeśli p nie posiada prawego syna, to
                {
                    p->right = w; // prawym synem staje się węzeł w
                    break;        // wychodzimy z pętli
                }
                p = p->right; // inaczej przechodzimy do prawego syna
            }
        }

        w->up = p;

        if (p->bf)
            p->bf = 0; // UWAGA NR 1
        else
        {
            if (p->left == w) // UWAGA NR 2
                p->bf = 1;
            else
                p->bf = -1;

            r = p->up; // będziemy szli w górę drzewa w kierunku korzenia
                       // r i p wskazują ojca i syna na tej ścieżce
            t = false;
            while (r)
            {
                if (r->bf)
                {
                    t = true; // ustalamy wynik pętli
                    break;    // przerywamy pętlę
                };
                // inaczej modyfikujemy r.bf
                if (r->left == p)
                    r->bf = 1;
                else
                    r->bf = -1;

                p = r; // przechodzimy w górę na wyższy poziom
                r = r->up;
            }

            if (t) // jeśli r.bf = +/- 1, to musimy
            {      // równoważyć drzewo
                if (r->bf == 1)
                {
                    if (r->right == p)
                        r->bf = 0; // gałęzie się równoważą
                    else if (p->bf == -1)
                        LR(r);
                    else
                        LL(r);
                }
                else
                { // r.bf = -1
                    if (r->left == p)
                        r->bf = 0; // gałęzie się równoważą
                    else if (p->bf == 1)
                        RL(r);
                    else
                        RR(r);
                }
            }
        }
    }
}

void upper(node *&root, int x)
{
    int ans = root->key;
    cout << "ans " << ans << '\n';

    while (true)
    {
        if (!root)
        {
            cout << ans << '\n';
            if (ans > x)
                cout << ans << '\n';
            else
                cout << "BRAK" << '\n';
            return;
        }
        if (x == root->key)
        {
            cout << x << '\n';
            return;
        }
        else if (x < root->key)
        {
            ans = root->key;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

int main()
{
    node *k = NULL;
    insert(k, 3);
    insert(k, 45);
    node *v = k->left;
    int e =v->key;
    cout << e << '\n';
    insert(k, 33);
    insert(k, 33);
    insert(k, 22);
   
    // upper(k, 44);
}