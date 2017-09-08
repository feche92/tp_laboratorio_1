using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades.Clase05;

namespace Clase5
{
    class Program
    {
        static void Main(string[] args)
        {
            Tinta tinta = new Tinta(ETipoTinta.China,ConsoleColor.DarkBlue);
            Tinta tintaDos = new Tinta();
            Tinta tintaTres = new Tinta();
            if (tintaTres == tintaDos)
                Console.WriteLine("son iguales");
            else
                Console.WriteLine("son distintas");
            if (tinta != tintaTres)
                Console.WriteLine("son distintas");
            else
                Console.WriteLine("son iguales");
            Console.WriteLine(Tinta.Mostrar(tinta));
            Console.WriteLine(Tinta.Mostrar(tintaDos));
            Console.WriteLine(tinta);
            Console.Read();
        }
    }
}
