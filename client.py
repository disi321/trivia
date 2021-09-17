import socket
import json
PORT = 8826
IP = "127.0.0.1"
login = "1{username: “user1”, password: “1234”}"
signup = "2{username: \"user1\", password: \"1234\", mail: \"user1@gmail.com\"}"
MENU = "1-login\n2-singup"
MSG = ""
USERNAME = "megidishh"
PASSWORD = "1234sS@ll"
EMAIL = "user1gmail.com"
PHONE = "0534379003"
ADDRESS = "zikim, 8, ashkelon"
BDAY = "25/8/1975"
BDAY = "1" ###################################
SERVER_LOGIN = '1'
SERVER_SIGNUP = '2'



def main():
    with socket.socket() as sock:
        sock.connect((IP, PORT))
        ans = sock.recv(1024).decode('utf-8')
        print(ans)

        json_login = '{\"username": \"' + USERNAME + '\", "password": \"' + PASSWORD + '\"}'
        json_sinup = '{\"username": \"' + USERNAME + '\", "password": \"' + PASSWORD + '\", "email\": \"' + EMAIL + '\", "address\": \"' + ADDRESS + '\", "phoneNumber\": \"' + PHONE + '\", "BdayDate\": \"' + BDAY + '\"}'

        full_msg = bytearray()

        option = int(input("1-login\n2-singup"))

        if option == 1:
            full_msg.extend(map(ord,SERVER_LOGIN))
            p = bytearray()
            length = len(json_login)
            p = length.to_bytes(4, byteorder = 'little')
            full_msg += p
            p = bytearray()
            p.extend(map(ord, json_login))
            full_msg += p


        elif option == 2:
            full_msg.extend(map(ord,SERVER_SIGNUP))
            p = bytearray()
            length = len(json_sinup)
            p = length.to_bytes(4, byteorder = 'little')
            full_msg += p
            p = bytearray()
            p.extend(map(ord, json_sinup))
            full_msg += p

        sock.send(full_msg)
        ans = sock.recv(1024).decode

        # deserailizing the data
        data = json.loads(str(ans)) 
  
        print("Datatype after deserailization : "
          + str(type(data)))

if __name__ == "__main__":
    main()
