using Newtonsoft.Json.Linq;
using System;
using System.Windows.Forms;

namespace trivia_gui
{
    class Helper
    {
        public static byte[] LoginMsg(string userName, string password)
        {
            JObject jsonLogin = new JObject
            {
                ["username"] = userName,
                ["password"] = password
            };
            return Serialize(Convert.ToString(jsonLogin), '1');
        }
        public static byte[] SignupMsg(string userName, string password, string email, string phone, string Bday)
        {
            JObject jsonLogin = new JObject
            {
                ["username"] = userName,
                ["password"] = password,
                ["email"] = email,
                ["phone"] = phone,
                ["Bday"] = Bday
            };
            return Serialize(Convert.ToString(jsonLogin), '2');
        }
        public static byte[] GetRooms()
        {
            JObject getRoomsJson = new JObject { };
            return Serialize(Convert.ToString(getRoomsJson), '9');//check if this is thr right code!!
        }

        public static byte[] Serialize(string json, char code)
        {
            int size = json.Length;
            byte[] sizeToMsg = BitConverter.GetBytes(size);
            byte[] response = new byte[(size + 5)];
            response[0] = (byte)(code);
            response[4] = 0;
            response[2] = 0;
            response[3] = 0;
            response[1] = (byte)(json.Length); ;
            int i = 1;
            string pp = "";
            pp += code;


            byte[] data = System.Text.Encoding.ASCII.GetBytes(json);
            for (int j = 5; j < data.Length + 5; j++)
            {
                response[j] = data[j - 5];
            }
            return response;

        }
        public static JObject Desrialize(string str)
        {
            return JObject.Parse(str);
        }
        public static byte[] createRoomMsg(string roomName, int numberOfPlayer, int numberOfQuestions, int TimeForQuestions)
        {
            JObject jsonCreateRoom = new JObject
            {
                ["roomName"] = roomName,
                ["NumberOfPlayers"] = numberOfPlayer,
                ["numberOfQuestions"] = numberOfQuestions,
                ["time"] = TimeForQuestions
            };

            return Serialize(Convert.ToString(jsonCreateRoom), '0');
        }
    }
}