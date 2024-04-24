using System;
using System.Collections;              
using System.Collections.Generic;

class Program
{
    class Enumerator : IEnumerator<string>
    {
        private SlowaFibonacciego lista;
        private int count;
        private string element;

        public Enumerator(SlowaFibonacciego slowo)
        {
            this.lista = slowo;
            this.count = 1;
            this.element = "";
        }

        public bool MoveNext()
        {
            if (this.count > lista.Limit)
            {
                return false;
            }

            this.element = lista.Return(this.count);
            this.count++;
            return true;
        }

        public string Current
        {
            get
            {
                return this.element;
            }
        }
        object IEnumerator.Current => Current;

        public void Dispose()
        {
        }
 
        public void Reset()
        {
            this.count = 1;
        }
    }

    class SlowaFibonacciego : IEnumerable<string> {
        private int counter;
        private int limit;
        private List<string> slowa;

        public int Limit
        {
            get
            {
                return this.limit;
            }
        }

        public SlowaFibonacciego(int limit)
        {
            this.limit = limit;
            this.slowa = new List<string>();
            this.counter = 1;
            this.slowa.Add("b");
            this.slowa.Add("a");
        }

        private void Extension(int n)
        {
            if (n > this.limit)
            {
                return;
            }

            for (int i = this.counter + 1; i < n; i++)
            {
                this.slowa.Add(this.slowa[i - 1] + this.slowa[i - 2]);
                this.counter++;
            }
        }
        public string Return(int n)
        {
            if(n > limit){
                return "error";
            }
            if (n-1 > this.counter){
                Extension(n);
            }
            return this.slowa[n - 1];
        }
        public IEnumerator<string> GetEnumerator()
        {
            return new Enumerator(this);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return new Enumerator(this);
        }
    
    }

    public static void Main()
    {
        SlowaFibonacciego sf = new SlowaFibonacciego(6);
        
        foreach (string s1 in sf)
        {
            foreach (string s2 in sf)
            {
                Console.WriteLine(s1, s2);
            }
        }
    }
}