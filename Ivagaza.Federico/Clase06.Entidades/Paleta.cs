using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Clase06.Entidades
{
    public class Paleta
    {
        private Tempera[] _colores;
        private int _cantMaximaColores;

        private Paleta():this(5)
        {

        }

        private Paleta(int cant)
        {
            this._cantMaximaColores = cant;
            this._colores = new Tempera[this._cantMaximaColores];
        }

        public static implicit operator Paleta(int cant)
        {
            Paleta paleta=new Paleta(cant);
            return paleta;
        }

        private string Mostrar()
        {
            string texto = "cantidad maxima:" + this._cantMaximaColores.ToString();
            for (int i = 0; i < this._cantMaximaColores;i++ )
            {
                if (this._colores.GetValue(i) != null)
                {
                    texto = texto + "\n" + Tempera.Mostrar(this._colores[i]);
                }
            }
            return texto;  
        }

        public static explicit operator string(Paleta paleta)
        {
            return paleta.Mostrar();
        }

        public static bool operator ==(Paleta paleta, Tempera tempera)
        {
            bool bandera = false;
            for(int i=0;i<paleta._cantMaximaColores;i++)
            {
                if (paleta._colores.GetValue(i) != null)
                {
                    if (paleta._colores[i] == tempera)
                    {
                        bandera = true;
                        break;
                    }
                }                                
            }
            return bandera;
        }

        public static bool operator !=(Paleta paleta, Tempera tempera)
        {
            return !(paleta == tempera);
        }

        private int ObtenerIndice()
        {
            int valor = -1;
            for (int i = 0; i < this._cantMaximaColores; i++)
            {
                if (this._colores.GetValue(i) == null)
                {
                    valor = i;
                    break;
                }
            }
            return valor;
        }

        private int ObtenerIndice(Tempera tempera)
        {
            int valor = -1;
            for (int i = 0; i < this._cantMaximaColores; i++)
            {
                if (this._colores.GetValue(i) != null)
                {
                    if (this._colores[i] == tempera)
                    {
                        valor = i;
                        break;
                    }
                }
            }
            return valor;
        }

        public static Paleta operator +(Paleta paleta, Tempera tempera)
        {
            int indice = paleta.ObtenerIndice();
            if (paleta != tempera && indice!=-1)
            {
                paleta._colores[indice] = tempera;
            }
            else if (paleta == tempera)
            {
                paleta._colores[paleta.ObtenerIndice(tempera)] += tempera;
            }
            return paleta;
        }

        public static Paleta operator -(Paleta paleta, Tempera tempera)
        {
            if (paleta == tempera)
            {
                paleta._colores[paleta.ObtenerIndice(tempera)] = null;
            }
            return paleta;
        }

     

    }
}
