
/*
 * Katarzyna Trzos
 * lista 3 zad 4 wektory
 * mcs -t:library  wektor.cs
 * mcs zad4.cs -r:wektor.dll
 * mono zad4.exe 
*/
using System;
public class Vector{
    private float[] vals;
    private int dim;
    
    //konstruktor klasy
    public Vector(int n)
    {
        dim = n;
        vals = new float[dim];
    }
    
    // dostep do poszczegolnych miejsc w wektorze
    public float this[int i]
    {
        get { return vals[i];}
        set { vals[i] = value;}
    }
    
    // dodawanie wketorow
    public static Vector operator +(Vector v1, Vector v2)
    {
        // ten sam wymiar
        if (v1.dim != v2.dim)
        {
            throw new Exception($"Podane wektory maja rozne wymiary!");
        }
        
        // rezult dodawania
        Vector res_V = new Vector(v1.dim);
        
        for (int i = 0; i < v1.dim; i++)
        {
            res_V[i] = v1[i] + v2[i];
        }
        
        return res_V;
    }
    
    // mnozenie wektorow
    public static float operator *(Vector v1, Vector v2)
    {
        // ten sam wymiar
        if (v1.dim != v2.dim)
        {
            throw new Exception($"Wektory v1 i v2 maja rozne wymiary!");
        }

        float res = 0.0f;
        for (int i = 0; i < v1.dim; i++)
        {
            res += (v1[i] * v2[i]);
        }
        return res;
    }

    public static Vector operator *(float a, Vector v)
    {
        Vector res_V = new Vector(v.dim);
        for (int i = 0; i < v.dim; i++)
        {
            res_V[i] = a * v[i];
        }
        return res_V;
    }

    public float norma()
    {
        return (float)Math.Sqrt(this * this);
    }
    public void print()
    {
        Console.Write($"( ");
        for (int i = 0; i < this.dim; i++)
        {
            Console.Write($"{vals[i]} ");
        }
        Console.Write($")");
        
        Console.WriteLine();
    }
}