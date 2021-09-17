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
    public partial class Form1 : Form
    {
        

        public Form1()
        {
            
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form2 form2 = new Form2();
            form2.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length != 0 && textBox2.Text.Length != 0)
            {
                bool isConnect = Communicator.Connect();
                if (isConnect == true)
                {
                    byte[] answer = Communicator.Send(Helper.LoginMsg(textBox1.Text, textBox2.Text));
                    byte[] newAns = new byte[1024];
                    for(int i = 5; i < answer.Length; i++)
                    {
                        newAns[i - 5] = answer[i]; 
                    }
                    string ans = System.Text.Encoding.ASCII.GetString(newAns);
                    MessageBox.Show(ans);
                    if (ans.Contains("Error") == false && ans.Contains("error") == false)
                    {
                        this.Hide();
                        Form4 form4 = new Form4();
                        form4.Show();
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
            else
            {
                MessageBox.Show("You must enter password and username");
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }
    }
}
