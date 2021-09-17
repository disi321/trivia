using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.Json;
using System.Text.Json.Serialization;
using Newtonsoft.Json.Linq;


namespace trivia_gui
{
    static class Program
    {
        public static byte[] Serialize(string json, char code)
        {
            int size = json.Length;
            byte[] sizeToMsg = BitConverter.GetBytes(size);
            int i = 5, j = 1;
            byte[] response = new byte[(size + 5)/8];

            response[0] <<= code;
            foreach(byte b in sizeToMsg)
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
        public static JObject Desrialize(string str)
        {
            return JObject.Parse(str);
        }
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());


        }
    }
}
