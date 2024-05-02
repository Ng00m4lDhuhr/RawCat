import network

if __name__ == '__main__':
    blabla = b"I do not know what I am doing but I am not hacking"
    network.transmit("8.8.8.8", blabla)
    print("seems like no error is there.")
