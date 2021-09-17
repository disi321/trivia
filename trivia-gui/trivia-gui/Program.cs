using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
//using System.Windows;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;
using Newtonsoft.Json.Linq;
using Newtonsoft.Json;





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

            Application.Run(new Form1());

        }
    }
}
