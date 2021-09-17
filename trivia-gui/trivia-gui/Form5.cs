using System;
using System.Windows;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;
using System.Windows.Input;
using System.Media;
using System.Windows.Controls;
using System.Windows.Media;










namespace trivia_gui
{
   


    public partial class Form5 : Form
    {
        bool wantToGoBack;
        string[] rooms;

        public Form5()
        {
            InitializeComponent();
            wantToGoBack = false;
            Thread thread = new Thread(Refresh);
            thread.Start();

        }

        private void Form5_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            wantToGoBack = true;
            this.Hide();
            Form4 form4 = new Form4();
            form4.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            while(wantToGoBack == false)
            {


            }

        }
        private void Refresh()
        {
            byte[] buffer = Communicator.Send(Helper.GetRooms());
            string ans = System.Text.Encoding.ASCII.GetString(buffer);
            ans = ans.Substring(ans.IndexOf('{'), ans.IndexOf('}') - 4);
            GetRoomsResponse response = JsonConvert.DeserializeObject<GetRoomsResponse>(ans);
            string[] rooms = response.rooms.Split(',');
            int i = 80;
            if (rooms != null)
            {
                foreach (string roomName in rooms)
                {
                    TextBlock txt = new TextBlock();
                    txt.Text = roomName;
                    txt.FontSize = 25;
                    txt.Foreground = new SolidColorBrush(Colors.Red);
                    txt.Margin = new Thickness(70, i, 0, 0);
                    txt.Focus();
                    i = 20;


                }
            }

            Thread.Sleep(3000);
        }
    }

    class GetRoomsResponse
    {
        public string rooms;
    }
}
    

