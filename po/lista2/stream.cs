/*
Katarzyna Trzos
Lista 2 
Zad 1 streams
*/


using System;
using System.Collections;
using System.Collections.Generic;

class IntStream
{
    int cnt;
    bool eos;
    public IntStream()
    {
        cnt = 0;
        eos = false;
    }
    
    public int next()
    {
        cnt++;
        return cnt;
    }
    public bool eos()
    {
        return this.eos;
    }
    public void reset()
    {
        this.eos = false;
        cnt = 0;
    }
}

class PrimeStream : IntStream
{
    public PrimeStream()
    {
        
    }
}