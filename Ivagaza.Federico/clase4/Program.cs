using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clase4
{
    class Program
    {
        static void Main(string[] args)
        {
            Cosa dato = new Cosa();
            Console.WriteLine(dato.Mostrar());
            dato.EstablecerValor(7);
            dato.EstablecerValor("hola mundo");
            dato.EstablecerValor(new DateTime(1992,03,19));
            Console.WriteLine(dato.Mostrar());
            Cosa datoDos = new Cosa(45, "lalal");
            Console.WriteLine(datoDos.Mostrar());
            Cosa datoTres = new Cosa(15, "FEDERICO", new DateTime(1458, 11, 24));
            Console.WriteLine(datoTres.Mostrar());
            Console.Read();


        }
    }
}
