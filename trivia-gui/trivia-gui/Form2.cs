using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;

namespace trivia_gui
{
    public partial class Form2 : Form
    {
        NetworkStream _client;
        public Form2 ()
        {
            
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Length != 0 || textBox2.Text.Length != 0 || textBox3.Text.Length != 0 || textBox4.Text.Length != 0 || textBox5.Text.Length != 0)
            {
                if(Communicator.Connect() == true)
                {
                    byte[] answer = Communicator.Send(Helper.SignupMsg(textBox1.Text, textBox2.Text, textBox3.Text, textBox4.Text, textBox5.Text));
                    byte[] newAns = new byte[1024];
                    for (int i = 5; i < answer.Length; i++)
                    {
                        newAns[i - 5] = answer[i];
                    }
                    string ans = System.Text.Encoding.ASCII.GetString(newAns);
                    MessageBox.Show(ans);
                    if (ans.Contains("Error") == false && ans.Contains("error") == false)
                    {
                        this.Hide();
                        Form3 form3 = new Form3();
                        form3.Show();
                    }
                    else
                    {
                        MessageBox.Show("The input is wrong, please try again!");
                    }
                }
                else
                {
                    MessageBox.Show("Cant connect to the server, please try again later");
                }
                
            }
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form1 form1 = new Form1();
            form1.Show();
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            string bDay = textBox5.Text;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            string phoneNumber = textBox1.Text;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            string username = textBox2.Text;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            string email = textBox3.Text;
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            string password = textBox4.Text;
        }
    }
}
