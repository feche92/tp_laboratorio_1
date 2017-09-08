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
    public partial class FrmPaleta : Form
    {
        private Paleta paleta;
        public FrmPaleta()
        {
            InitializeComponent();
            paleta = 5;
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FrmTempera frm = new FrmTempera();
            frm.ShowDialog();
            

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Tempera tempera = new Tempera(ConsoleColor.Black, "marca1", 25);
            paleta -= tempera;
            listBox1.Items.Clear();
            listBox1.Items.Add((string)paleta);
        }
    }
}
