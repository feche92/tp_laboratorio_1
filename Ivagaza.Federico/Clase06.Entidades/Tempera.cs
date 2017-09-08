using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase06.Entidades
{
    public class Tempera
    {
        private ConsoleColor _color;
        private string _marca;
        private int _cantidad;

        public Tempera(ConsoleColor color, string marca, int cantidad)
        {
            this._color = color;
            this._marca = marca;
            this._cantidad = cantidad;
        }

        private string mostrar()
        {
            return "color:" + this._color + " marca:" + this._marca + " cantidad:" + this._cantidad;
        }

        public static string Mostrar(Tempera t1)
        {
            return t1.mostrar();
        }

        public static bool operator ==(Tempera t1, Tempera t2)
        {
            return t1._color == t2._color && t1._marca == t2._marca;
        }

        public static bool operator !=(Tempera t1, Tempera t2)
        {
            return !(t1 == t2);
        }

        public static Tempera operator +(Tempera t1, double temp)
        {
            if (temp > 0 && t1._cantidad+(int)temp<=100)
            {
                t1._cantidad = (int)temp + t1._cantidad;
            }            
            return t1;
        }

        public static implicit operator int(Tempera t1)
        {
            return t1._cantidad;
        }


    }
}
