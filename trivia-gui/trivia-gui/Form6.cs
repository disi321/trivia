using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;

namespace trivia_gui
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form4 form4 = new Form4();
            form4.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length != 0 && textBox2.Text.Length != 0 && textBox3.Text.Length != 0 && textBox4.Text.Length != 0)
            {
                byte[] buffer = Communicator.Send(Helper.createRoomMsg(textBox1.Text, int.Parse(textBox2.Text), int.Parse(textBox3.Text), int.Parse(textBox4.Text)));
                byte[] newAns = new byte[1024];
                for (int i = 5; i < buffer.Length; i++)
                {
                    newAns[i - 5] = buffer[i];
                }
                string ans = System.Text.Encoding.ASCII.GetString(newAns);
                if (ans.Contains("Error") == false)
                {
                    this.Hide();
                    Form7 form7 = new Form7(textBox1.Text, int.Parse(textBox2.Text), int.Parse(textBox3.Text), int.Parse(textBox4.Text));
                    form7.Show();
                }
                else
                {
                    MessageBox.Show("The input is wrong, please try again!");
                }

        }   }
 
    }

}
    

