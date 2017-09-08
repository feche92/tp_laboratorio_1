using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades.Clase05
{
    class Pluma
    {
        private string _marca;
        private Tinta _tinta;
        private int _cantidades;

        public Pluma()
        {
            this._marca = "sin marca";
            this._tinta = null;
            this._cantidades = 0;
        }

        public Pluma(string marca):this()
        {
            this._marca = marca;
        }

        public Pluma(string marca, Tinta tinta): this(marca)
        {
            this._tinta = tinta;
        }

        public Pluma(string marca, Tinta tinta, int cantidad): this(marca, tinta)
        {
            this._cantidades = cantidad;
        }

        private string Mostrar()
        {
            return "marca:" + this._marca + " tinta:" + this._tinta + " cantidad:" + this._cantidades;
        }

        public static bool operator ==(Tinta tinta, Pluma pluma)
        {
            return pluma._tinta == tinta;
        }

        public static bool operator !=(Tinta tinta, Pluma pluma)
        {
            return !(pluma._tinta == tinta);
        }

        public static Pluma operator +(Tinta tinta, Pluma pluma)
        {
            if (tinta == pluma)
                pluma._cantidades++;
            if (pluma._cantidades >= 100)
                pluma._cantidades = 100;
            return pluma;

        }

        public static Pluma operator -(Tinta tinta, Pluma pluma)
        {
            if (tinta == pluma)
                pluma._cantidades--;
            return pluma;
            
        }



    }
}
