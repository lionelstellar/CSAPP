from pwn import *

#context.log_level = 'debug'

# run locally
# p = remote('pwnable.kr', 9007)

# run on remote server
p.recvuntil('- Ready? starting in 3 sec... -')



def senddata(num_start,num_end,C,count,coin = 0):

    #print 'num_start: %d , num_end: %d'%(num_start,num_end)
    #print 'C: %d,count: %d'%(C,count)


    if count == C:
        p.sendline(str(coin))
        return

    a = ''
    for i in range(num_start,(num_end+num_start)/2+1):
        a += str(i) + ' '

    p.sendline(a)

    data = p.recvuntil('\n',drop=True)

    if data[-1] != '9':
        senddata((num_end+num_start)/2+1,num_end,C,count+1,num_end)
    else:
        if num_end - num_start == 1:
            coin = num_start
        senddata(num_start,(num_end+num_start)/2,C,count+1,coin)

i = 0
while True:
    i += 1
    print i
    p.recvuntil('N=')
    N = int(p.recvuntil(' ',drop = True))
    p.recvuntil('C=')
    C = int(p.recvuntil('\n',drop = True))


    senddata(0,N,C,0)

p.interactive()