/*
 * Katrzyna Trzos
 * Lista 2 zadanie 4
*/

using System;
using System.Collections.Generic;

namespace LazyList
{
  class Program
  {
    static void Main(string[] args)
    {
    	LazyIntList A = new LazyPrimeList();

        Console.WriteLine("Trzecia liczba pierwsza: ");
        Console.WriteLine(A.element(3));
        Console.WriteLine("Rozmiar listy: ");
        Console.WriteLine(A.size() + "\n");

        LazyIntList B = new LazyIntList();

        Console.WriteLine("Dziesiata liczba w liscie: ");
        Console.WriteLine(B.element(10));
        Console.WriteLine("Dziesiata liczba w liscie: ");
        Console.WriteLine(B.size() + "\n");
        
        Console.WriteLine("Siodma liczba w liscie: ");
        Console.WriteLine(B.element(7));
        Console.WriteLine("Rozmiar listy: ");
        Console.WriteLine(B.size());
        
    }
  }
  
  class LazyIntList
  {
  	public int index = 0;
    public List<int> numbers = new List<int>();
    
    public virtual int element(int i)
    {
        i--;
    	while(index <= i)
        {
        	numbers.Add(index+1);
            index++;
        }
    	return numbers[i];
    }
    
    public int size()
    {
    	return index;
    }
  }
  

  class LazyPrimeList : LazyIntList
  {

    public int next_prime_number = 2;
  	public override int element(int i)
    {
        i--;
        while(index <= i)
        {
        	numbers.Add(next_prime_number);
            index++;
            while(true)
            {
                next_prime_number++;
                bool is_p_prime = true;
                for(int j=2; j<next_prime_number; j++)
                {
                    if(next_prime_number%j == 0)
                    {
                        is_p_prime = false;
                        break;
                    }
                }
                if(is_p_prime)
                    break;
            }
        }
    	return numbers[i];
    }
  }
}