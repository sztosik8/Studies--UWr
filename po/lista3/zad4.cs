using System;
/*
 * Katarzyna Trzos
 * lista 3 zad 4 wektory
 * mcs -t:library  wektor.cs
 * mcs zad4.cs -r:wektor.dll
 * mono zad4.exe 
 */

class Program
{
    static void Main(string[] args)
    {

        Vector v = new Vector(4);
        Console.Write($"v = ");
        v.print();
        
        v[0] = 1;
        v[1] = 2;
        v[2] = 3;
        v[3] = 4;
        Console.Write($"v = ");
        v.print(); 
        Vector u = new Vector(4);
        u[0] = 5;
        u[1] = 6;
        u[2] = 7;
        u[3] = 8;
        Console.Write($"u = ");
        u.print();
        
        // mnozenie przez skalar
        Console.Write($"wektor v pomnozony przez skalar 3.56 : ");
        ((float)3.56 * v).print();
        
        
        
        
        // suma wektorow
        Console.Write($"suma dwoch wektorow v i u to: ");
        (v + u).print();
        
        // iloczyn skalarny
        Console.WriteLine($"iloczyn skalarny wektorow v i u to: {v*u} ");
    
        // norma
        Console.WriteLine($"Długość wektora u: {u.norma()}");
        
        // dodanie wektorow o innej dlugosci
        Vector w = new Vector(3);

        try
        {
            (v + w).print();
        }
        catch(Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
        
        











    }
}