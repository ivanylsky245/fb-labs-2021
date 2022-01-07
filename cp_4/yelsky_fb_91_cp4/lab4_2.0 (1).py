#!/usr/bin/env python
# coding: utf-8

# In[1]:


import random
import math

def fast_prime_check(num):
    list_of_checker=[]
    for i in range(2,15):
        list_of_checker.append(i)
    for j in  list_of_checker:
         if num %j==0 :
            return False 
         else:
            return True
        
        
        
        
        
def miller_rabin(num):
    if fast_prime_check(num)==False :
        return False
    y = num - 1
    x = 0
    while y % 2 == 0:
        x = x + 1
        y = y // 2
    z = y
    for i in range(0, 3):
        r = random.randint(2, num - 1)
        t = pow(r, z, num)
        if t == 1 or t == num - 1:
            continue
        for k in range(0, x - 1):
            t = pow(l, 2, num)
            if t == 1:
                return True
            if t == num - 1:
                break
        else:
            return False
    return True

def generate_prime_numbers():
    list1=[]
    while(len(list1)<4):
        number = random.getrandbits(256)
        if miller_rabin(number):
                list1.append(number)
    return list1


def p_q_p1_q1():
    list2=[]
    list2=list2.clear()
    list2=generate_prime_numbers()
    p=list2[0]
    q=list2[1]
    p1=list2[2]
    q1=list2[3]
    if p * q >= p1 * q1:
        p_q_p1_q1()
    else :
        return p,q,p1,q1

p,q,p1,q1=p_q_p1_q1()


def pary_kluchiv(p,q):
    n = p*q
    f = (p-1)*(q-1)
    e = 0
    conditional_bool=True 
    while conditional_bool:
        e = random.randrange(2, f - 1)
        if math.gcd(e, f) == 1:
            conditional_bool=False
    d = pow(e, -1, f)
    return n,f,e,d,


n,f,e,d=pary_kluchiv(p,q)
n1,f1,e1,d1=pary_kluchiv(p1,q1)

n,e,d,f
n1,e1,d1,f1


















# In[2]:


math.gcd(e1,f1)


# In[ ]:





# In[10]:


def encrypt_msg(n,Msg,e):
    C=pow(Msg,e,n)
    return C





def decrypt_msg(d,C,n,Msg):
    Msg1 = pow(C,d,n)
    if Msg==Msg1: 
        print("decryption sucssed")
    return Msg

Msg=random.randint(0,n)
print(Msg)






C=encrypt_msg(n,Msg,e)
print(C)


# In[11]:


D=decrypt_msg(d,C,n,Msg)
D


# In[25]:


def Cypher_Signature(Msg,d,n):
    Sign = pow(Msg,d,n)
    return Sign





def Verifycation(Msg,Sign,e,n):
    if Msg == pow(Sign,e,n):
        return True 





def Sendkey(key,e1,n1,d,n):
    return pow(Sign,e1,n1),pow(key,e1,n1),pow(key,d,n)



def Receivekey(key1,Sign1,d1,n1):
    return pow(S1,d1,n1),pow(k1,d1,n1)


secret_k=random.randint(0,n)


secret_k 












key1,Sign1,Sign=Sendkey(secret_k,e1,n1,d,n)
key1,Sign1,Sign
km,sm=Receivekey(key1,Sign1,d1,n1)


# In[27]:


Verifycation(km,sm,e,n)


# In[ ]:




