import socket
import ssl

def get_cmd(name,number):
    return f"raw.githubusercontent.com/coderuster/os/main/{number}/{name}"
def https_get(url):
    hostname, _, path = url.partition('/')
    if not path:
        path = '/'

    with socket.create_connection((hostname, 443)) as sock:
        context = ssl.create_default_context()
        with context.wrap_socket(sock, server_hostname=hostname) as ssock:
            request = f"GET {path} HTTP/1.1\r\nHost: {hostname}\r\nConnection: close\r\n\r\n"
            ssock.sendall(request.encode())

            response = b""
            while True:
                data = ssock.recv(4096)
                if not data:
                    break
                response += data
    body_start = response.find(b"\r\n\r\n") + len(b"\r\n\r\n")
    return response[body_start:].decode()

def run_command(cmd):
  try:
      data=https_get(cmd)
      return data
  except Exception as e:
    print(f"Error: {e}")
    return "ERROR"

def main():
    number=input("1[threading&sync|looping shell| CAT MKDIR]\n2[pipe conecpt|fork exec|PWD CD]\n3[priority|odd even|RMDIR CLEAR]\n4[round robin|opendir readdir|ls copy]\n5[semaphore|wait exit|move who]\n6[sequential alloc|cp ls grep|whoami man]\n7[indexed file alloc|getpid close|CAT MKDIR]\n8[linked list file alloc|arithemetic|pwd cd]\n9[fcfs|big among 3|rmdir clear]\n10[bankers|close stat|listing directory copy]\n11[FCFS page|factorial|who move]\n12[LRU page|opndir close|man whoami]\n13[LFU page| arithemetic|cat mkdir]\n14[paging concept|sum of n|pwd cd]\n15[SJFS scheu|fork exec|rmdir clear]\n16[first fit|arithrmetic|cat mkdir]\n17[worst fit|arithem|pwd cd]\n18[best fit|cp ls grep|whoami man]\n19[LRU page|close stat|listing dir|copy]\n20[indexed file alloc|arithem|cat mkdir]\nchoose: ").strip()
    files=['a.c','b.sh','c.txt']
    for f in files:
        cmd=get_cmd(f,number)
        content=run_command(cmd)
        with open(f,"w") as file:
            file.write(content)
if __name__=="__main__":
    main()
