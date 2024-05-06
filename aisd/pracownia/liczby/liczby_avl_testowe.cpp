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
// Rotacja RR
//-----------
void RR(node *&root, node *A)
{
    node *B = A->right, *p = A->up;

    A->right = B->left;
    if (A->right)
        A->right->up = A;

    B->left = A;
    B->up = p;
    A->up = B;

    if (p)
    {
        if (p->left == A)
            p->left = B;
        else
            p->right = B;
    }
    else
        root = B;

    if (B->bf == -1)
        A->bf = B->bf = 0;
    else
    {
        A->bf = -1;
        B->bf = 1;
    }
}

// Rotacja LL
//-----------
void LL(node *&root, node *A)
{
    node *B = A->left, *p = A->up;

    A->left = B->right;
    if (A->left)
        A->left->up = A;

    B->right = A;
    B->up = p;
    A->up = B;

    if (p)
    {
        if (p->left == A)
            p->left = B;
        else
            p->right = B;
    }
    else
        root = B;

    if (B->bf == 1)
        A->bf = B->bf = 0;
    else
    {
        A->bf = 1;
        B->bf = -1;
    }
}

// Rotacja RL
//-----------
void RL(node *&root, node *A)
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
    else
        root = C;

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

// Rotacja LR
//-----------
void LR(node *&root, node *A)
{
    node *B = A->left, *C = B->right, *p = A->up;

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
    else
        root = C;

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

// Wstawia nowy węzeł do drzewa AVL
// root - referencja korzenia
// k    - klucz nowego węzła
//---------------------------------
void insert(node *&root, int k)
{
    node *w, *p, *r;
    bool t;

    w = new node; // tworzymy dynamicznie nowy węzeł
    w->left = w->right = w->up = NULL;
    w->key = k;
    w->bf = 0;

    //----------------------------------------
    // FAZA 1 - wstawienie węzła do drzewa AVL
    //----------------------------------------

    p = root; // rozpoczynamy od korzenia

    if (!p)
        root = w; // jeśli drzewo jest puste, to węzeł w umieszczamy w korzeniu
    else
    { // inaczej szukamy miejsce dla w
        while (true)
            if (k < p->key) // porównujemy klucze
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

        w->up = p; // ojcem w jest p

        //---------------------------------
        // FAZA 2 - równoważenie drzewa AVL
        //---------------------------------

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
                        LR(root, r);
                    else
                        LL(root, r);
                }
                else
                { // r.bf = -1
                    if (r->left == p)
                        r->bf = 0; // gałęzie się równoważą
                    else if (p->bf == 1)
                        RL(root, r);
                    else
                        RR(root, r);
                }
            }
        }
    }
}

void upper(node *&root, int x)
{
    int ans = root->key;
    node *help;
    help = root;

    while (true)
    {
        if (!help)
        {
            if (ans >= x)
                cout << ans << '\n';
            else
                cout << "BRAK" << '\n';
            return;
        }
        if (x == help->key)
        {
            cout << x << '\n';
            return;
        }
        else if (x < help->key)
        {
            ans = help->key;
            help = help->left;
        }
        else if (x > help->key)
        {
            help = help->right;
        }
    }
}

void lower(node *&root, int x)
{
    int ans = root->key;
    node *help;
    help = root;

    while (true)
    {
        if (!help)
        {
            if (ans <= x)
                cout << ans << '\n';
            else
                cout << "BRAK" << '\n';
            return;
        }
        if (x == help->key)
        {
            cout << x << '\n';
            return;
        }
        else if (x < help->key)
        {
            help = help->left;
        }
        else if (x > help->key)
        {
            ans = help->key;
            help = help->right;
        }
    }
}

// Funkcja usuwa rekurencyjnie węzeł x
// root - referencja do zmiennej z adresem korzenia
// x - wskazanie usuwanego węzła
//-------------------------------------------------
void delate(node *&root, int x)
{
    node *help, *prev;
    help = root;
    prev = NULL;

    while (true)
    {
        if (!help)
        {
            cout << "BRAK" << '\n';
            return;
        }
        if (x == help->key)
        {
            cout << x << '\n';
            break;
        }
        else if (x < help->key)
        {
            prev = help;
            help = help->left;
        }
        else if (x > help->key)
        {
            prev = help;
            help = help->right;
        }
    }

    node
        *t,
        *y, *z;
    bool nest;

    if (help->left && help->right)
    {
        //y = 
        delate(root, prev->key);    //////// tu cos dziwnego
        nest = false;
    }
    else
    {
        if (help->left)
        {
            y = help->left;
            help->left = NULL;
        }
        else
        {
            y = help->right;
            help->right = NULL;
        }
        help->bf = 0;
        nest = true;
    }

    if (y)
    {
        y->up = help->up;
        y->left = help->left;
        if (y->left)
            y->left->up = y;
        y->right = help->right;
        if (y->right)
            y->right->up = y;
        y->bf = help->bf;
    }

    if (help->up)
    {
        if (help->up->left == help)
            help->up->left = y;
        else
            help->up->right = y;
    }
    else
        root = y;

    if (nest)
    {
        z = y;
        y = help->up;
        while (y)
        {
            if (!y->bf)
            { // Przypadek nr 1
                if (y->left == z)
                    y->bf = -1;
                else
                    y->bf = 1;
                break;
            }
            else
            {
                if (((y->bf == 1) && (y->left == z)) || ((y->bf == -1) && (y->right == z)))
                { // Przypadek nr 2
                    y->bf = 0;
                    z = y;
                    y = y->up;
                }
                else
                {
                    if (y->left == z)
                        t = y->right;
                    else
                        t = y->left;
                    if (!t->bf)
                    { // Przypadek 3A
                        if (y->bf == 1)
                            LL(root, y);
                        else
                            RR(root, y);
                        break;
                    }
                    else if (y->bf == t->bf)
                    { // Przypadek 3B
                        if (y->bf == 1)
                            LL(root, y);
                        else
                            RR(root, y);
                        z = t;
                        y = t->up;
                    }
                    else
                    { // Przypadek 3C
                        if (y->bf == 1)
                            LR(root, y);
                        else
                            RL(root, y);
                        z = y->up;
                        y = z->up;
                    }
                }
            }
        }
    }
    cout << "OK" << '\n';
    return;
}

int main()
{
    node *k = NULL;

    insert(k, 3);
    insert(k, 45);

    insert(k, 33);
    insert(k, 33);
    insert(k, 22);

    cout << k->key << '\n'
         << '\n';
    upper(k, 32);
    lower(k, 32);
    cout << '\n';
    delate(k, 22);
    cout << '\n';
    upper(k, 32);
    lower(k, 32);
    // cout << k->key << '\n';
    cout << '\n';
     delate(k, 33);



    /*
        upper(k, 1);
        lower(k, 1);
        cout << '\n';

        upper(k, 3);
        lower(k, 3);
        cout << '\n';

        upper(k, 4);
        lower(k, 4);
        cout << '\n';


        cout << '\n';

        upper(k, 45);
        lower(k, 45);
        cout << '\n';

        upper(k, 120);
        lower(k, 120);
        cout << '\n';*/
}
