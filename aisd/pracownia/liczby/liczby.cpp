#include <iostream>

using namespace std;
int bst_tab[50003];
class bst
{
private:
    int n;

public:
    bst() : n(0) {}

    /*
        int syn_l();
        int syn_p();
        int ojciec();
        */

    void clear_up(int i);
    void set_down(int i);

    void insert(int x);
    void wypisz();
    // int upper(int x);
    // int lower(int x);
    //  string delate(int x);
};

int syn_l(int n)
{
    return (n * 2) + 1;
}

int syn_p(int n)
{
    return (n + 1) * 2;
}

int ojciec(int n)
{
    return (n - 1) / 2;
}

void bst::clear_up(int i)
{
    if (i != 0) // sprawdz porzadek z ojcem
    {
        cout << "porownuje " << i << ' ' << ojciec(i) << '\n';
        if (i % 2 == 1)
        {
            if (bst_tab[i] > bst_tab[ojciec(i)])
            {
                swap(bst_tab[i], bst_tab[ojciec(i)]);
                clear_up(ojciec(i));
            }
        }
        else
        {
            if (bst_tab[i] < bst_tab[ojciec(i)])
            {
                swap(bst_tab[i], bst_tab[ojciec(i)]);
                clear_up(ojciec(i));
            }
        }
    }}

    // sprawdz porzadek z synami
  void bst::set_down(int i)
  {
        if (syn_l(i) <= n)
        {
            cout << "porownuje syna lewego " << i << ' ' << syn_l(i) << '\n';
            if (bst_tab[syn_l(i)] > bst_tab[i])
            {
                swap(bst_tab[i], bst_tab[syn_l(i)]);
                clear_down (syn_l(i));
            }
        }
        if (syn_p(i) <= n)
        {
            cout << "porownuje syna  pra3ego " << i << ' ' << syn_p(i) << '\n';
            if (bst_tab[syn_p(i)] < bst_tab[i])
            {
                swap(bst_tab[i], bst_tab[syn_p(i)]);
                clear(syn_p(i));
            }
        }
    
    return;
}

void bst::insert(int x)
{
    bst_tab[n] = x;
    clear(n);
    n += 1;
}

void bst::wypisz()
{
    for (int i = 0; i < n; i++)
    {
        cout << bst_tab[i] << ' ';
    }
    cout << '\n';
    cout << '\n';
}

/*

int bst::upper(int x)
{
    return 0;
}
int bst::lower(int x)
{
    return 0;
}
*/
int main()
{
    bst k;

    k.insert(3);
    k.wypisz();

    k.insert(1);
    k.wypisz();

    k.insert(4);
    k.wypisz();

    k.insert(8);
    k.wypisz();

    k.insert(2);
    k.wypisz();

    k.insert(-4);
    k.wypisz();

    k.insert(7);
    k.wypisz();
}