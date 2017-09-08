using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace clase4
{
    class Cosa
    {
        public int entero;
        public string cadena;
        public DateTime fecha;
        public ConsoleColor color;

        public void EstablecerValor(ConsoleColor x)
        {
            this.color = x;
        }

        /// <summary>
        /// Establece un valor al entero de la clase cosa
        /// </summary>
        /// <param name="x">entero a pasar</param>
        public void EstablecerValor(int x)
        {
            this.entero = x;
        }
        /// <summary>
        /// Establece una cadena al dato tipo string de la clase cosa
        /// </summary>
        /// <param name="x">cadena a pasar</param>
        public void EstablecerValor(string x)
        {
            this.cadena = x;
        }
        /// <summary>
        /// establece una fecha al atributo DateTime de la clase cosa
        /// </summary>
        /// <param name="x"></param>
        public void EstablecerValor(DateTime x)
        {
            this.fecha = x;
        }
        /// <summary>
        /// muestra todos los atributos de la clase
        /// </summary>
        /// <returns>retorna un string con los valores de todos los atributos</returns>
        public string Mostrar()
        {
            string texto;
            Console.BackgroundColor = color;
            texto = "entero:" + this.entero + " cadena:" + this.cadena + " fecha:" + this.fecha;
            return texto;
        }
        /// <summary>
        /// inicializa un objeto con los valores por defecto
        /// </summary>
        public Cosa()
        {
            this.entero = 0;
            this.cadena = "sin valor";
            this.fecha = DateTime.Now;
            this.color = ConsoleColor.Red;
        }
        /// <summary>
        /// inicializa un objeto con un entero y un string que se le pase por parametros
        /// </summary>
        /// <param name="a">entero</param>
        /// <param name="b">string</param>
        public Cosa(int a,string b):this(a)//unicamente solo puede usarse en sobrecargas de contructores
        {
            this.cadena = b;
        }
        /// <summary>
        /// inicializa un objeto con un entero que se le pase por parametro y los demas datos quedan por defecto
        /// </summary>
        /// <param name="x">entero</param>
        public Cosa(int a):this()
        {
            this.entero = a;            
        }
        /// <summary>
        /// inicializa un objeto con todos los atributos que se le pasen por parametros
        /// </summary>
        /// <param name="a">entero</param>
        /// <param name="b">cadena</param>
        /// <param name="c">fecha</param>      
        public Cosa(int a, string b, DateTime c): this(a, b)
        {
            this.fecha = c;
        }
        


    }
}
