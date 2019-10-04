# stage 1: argv
args = ["A"] * 99
args[ord('A') - 1] = ""
args[ord('B') - 1] = str("\x20\x0a\x0d")
args[ord('C') - 1] = "10000"

# stage 2: stdio
import os,subprocess
r0, w0 = os.pipe()
r2, w2 = os.pipe()
os.write(w0, b"\x00\x0a\x00\xff")
os.write(w2, b"\x00\x0a\x02\xff")

# stage 3: env
# os.environ["\xca\xfe\xba\xbe"] = "\xde\xad\xbe\xef"
environ = {"\xca\xfe\xba\xbe" : "\xde\xad\xbe\xef"}

# stage 4: file
with open("\x0a", "wb") as f:
    f.write(b"\x00\x00\x00\x00")
subprocess.Popen(["/Users/jiangyikun/vscode/CWorkSpace/ctf/pwnable/input2/input"]+args, stdin=r0, stderr=r2, env=environ)

# stage 5: network
import socket
addr = ("127.0.0.1", 10000)
sd = socket.socket()
sd.connect(addr)
sd.send("\xde\xad\xbe\xef")
