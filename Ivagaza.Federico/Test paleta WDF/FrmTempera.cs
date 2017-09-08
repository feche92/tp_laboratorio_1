using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Clase06.Entidades;

namespace Test_paleta_WDF
{
    public partial class FrmTempera : Form
    {
        private Tempera tempera;

        public Tempera GetTempera()
        {
            return this.tempera;
        }
        public FrmTempera()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int cantidad = int.Parse(textBox1.ToString());
            string marca = textBox3.ToString();
            ConsoleColor color = (ConsoleColor)Enum.Parse(typeof(ConsoleColor), textBox2.ToString());
            this.tempera = new Tempera(color, marca, cantidad);
            this.DialogResult = System.Windows.Forms.DialogResult.OK;

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            

        }
    }
}
