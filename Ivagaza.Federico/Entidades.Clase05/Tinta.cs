using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.Clase05
{
    public class Tinta
    {
        private ConsoleColor _color;
        private ETipoTinta _tipo;

        public Tinta()
        {
            this._tipo = ETipoTinta.Comun;
            this._color = ConsoleColor.Black;
        }
        public Tinta(ETipoTinta x):this()
        {
            this._tipo = x;
        }
        public Tinta(ETipoTinta x, ConsoleColor color): this(x)
        {
            this._color = color; 
        }

        private string Mostrar()
        {
            string texto;
            texto="color:" + this._color + " tipo:" + this._tipo;
            return texto;
        }

        public static string Mostrar(Tinta x)
        {
            return x.Mostrar();
        }

        public static bool operator ==(Tinta a, Tinta b)
        {

            return a._color == b._color && b._tipo == a._tipo;
           
        }

        public static bool operator !=(Tinta a, Tinta b)
        {
            return !(a == b);
        }
        /// <summary>
        /// castea explicitamente un objeto de tipo Tinta a string
        /// </summary>
        /// <param name="a">objeto Tinta</param>
        /// <returns>string</returns>
        /*public static explicit operator string(Tinta a)
        {
            return a.Mostrar();
        }*/

        //convierte implicitamente
        public static implicit operator string(Tinta a)
        {
            //corvierte implicitamente
            return a._tipo.ToString();
        }
    }
}
