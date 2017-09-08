using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Clase06.Entidades;

namespace Clase_6
{
    class Program
    {
        static void Main(string[] args)
        {
            Tempera tempera = new Tempera(ConsoleColor.Black, "marca", 10);
            Tempera temperaDos = new Tempera(ConsoleColor.Blue, "marca", 22);
            Tempera temperaTres = new Tempera(ConsoleColor.Black, "marca", 82);
            double num = 75.25;
            if (tempera == temperaDos)
                Console.WriteLine("son iguales");
            else
                Console.WriteLine("son distintos");
            if (tempera == temperaTres)
                Console.WriteLine("son iguales");
            else
                Console.WriteLine("son distintos");
            Console.WriteLine(temperaTres);
            tempera += num;
            Console.WriteLine(Tempera.Mostrar(tempera));
            Console.Read();
        }
    }
}
