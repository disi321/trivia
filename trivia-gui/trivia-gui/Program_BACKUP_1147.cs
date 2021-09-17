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


using System.Net;
using System.Text;
using System.Net.Sockets;


namespace trivia_gui
{
    static class Program
    {
<<<<<<< HEAD
 
=======
        public static byte[] Serialize(string json, char code)
        {
            int size = json.Length;
            byte[] sizeToMsg = BitConverter.GetBytes(size);
            int i = 5, j = 1;
            byte[] response = new byte[(size + 5) / 8];

            response[0] <<= code;
            foreach (byte b in sizeToMsg)
            {
                response[j] <<= b;
                j++;
            }
            foreach (char c in json)
            {
                response[i] <<= c;
                i++;
            }
            return response;
        }
        public static void Connect()
        {
            Socket socket;
            int PORT = 1111;
            IPHostEntry host = Dns.GetHostEntry(Dns.GetHostName());
            foreach (var address in host.AddressList)
            {
                if (address.AddressFamily == AddressFamily.InterNetwork)
                {
                    socket = new Socket(address.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
                    socket.Connect(new IPEndPoint(address, PORT));
                }
            }
        }
        public static JObject Desrialize(string str)
        {
            return JObject.Parse(str);
        }
>>>>>>> dddc4120213ab8d25b21f87d2ee7c3473d120ae4
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
