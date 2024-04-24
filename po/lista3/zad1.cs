/*
 * Katarzyna Trzos
 * lista 3 zad 1 listy
 * mcs -t:library  lista.cs
 * mcs zad1.cs -r:lista.dll
 * mono zad1.exe
 */
using System;

class Program
{
    public static void Main()
    {
        List<int> L  = new List<int>();
        L.push_back(2);
        L.push_back(3);
        L.push_front(1);
        Console.WriteLine(L.pop_back());
        Console.WriteLine(L.pop_back());
        Console.WriteLine(L.pop_back());
        L.push_back(2);
        L.push_back(3);
        L.push_front(1);
        Console.WriteLine(L.pop_front());
        Console.WriteLine(L.pop_front());
        Console.WriteLine(L.pop_front());
        Console.WriteLine(L.pop_back());
    }
}