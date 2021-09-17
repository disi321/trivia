using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net; 
using System.Net.Sockets;

namespace trivia_gui
{
 
        static class Communicator
        {
            public static Socket serverSocket;
            public static int roomId;
            public static bool Connect()
            {
                Socket sock = new Socket(SocketType.Stream, ProtocolType.Tcp);
                IPAddress iP = IPAddress.Parse("127.0.0.1");
                IPEndPoint iPEndPoint = new IPEndPoint(iP, 8826);
                try
                {
                    sock.Connect(iPEndPoint);
                }
                catch
                {
                    serverSocket = null;
                    return false;
                }
                serverSocket = sock;
                return true;
            }
            public static byte[] Send(byte[] data)
            {
                serverSocket.Send(data);
                byte[] input = new byte[1024];
                serverSocket.Receive(input, 1024, SocketFlags.None);
                return input;
            }

        }
}

