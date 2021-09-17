using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;



namespace trivia_gui
{
    static class Program
    {
 
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        
        static void Main()
        {
            
            TcpClient client = new TcpClient();
            IPEndPoint server = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8826);
            
            try
            {
                client.Connect(server);
                NetworkStream clientStream = client.GetStream();
                Application.Run(new Form1(clientStream));

            }
            catch
            {
                MessageBox.Show("Cant connect to the server, please try again later");
                System.Environment.Exit(1);
            }




        }
    }
}
