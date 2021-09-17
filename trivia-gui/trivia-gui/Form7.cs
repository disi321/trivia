using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace trivia_gui
{
    public partial class Form7 : Form
    {
        string _name;
        int _players;
        int _numOfQ;
        int _time;
        public Form7(string name, int players, int numOfQ, int time)
        {
            this._name = name;
            this._players = players;
            this._numOfQ = numOfQ;
            this._time = time;
            InitializeComponent();
        }

        private void Form7_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox1.Text = "You are connectrd to room " + _name;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = "max_num_of_players: " + _players + "number_of_questions: " + _numOfQ + "time_per_question: " + _time;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
            Form4 form4 = new Form4();
            form4.Show();
        }
    }
}
