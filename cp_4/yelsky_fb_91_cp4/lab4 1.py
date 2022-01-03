#!/usr/bin/env python
# coding: utf-8

# In[58]:


import random
import math
def miller_rabin(num):
    if num % 2 == 0 or num % 3 == 0 or num % 5 == 0 or num % 7 == 0 :
        return False
    y = num - 1
    x = 0
    while y % 2 == 0:
        x = x + 1
        y = y // 2
    z = y
    for i in range(0, 3):
        m = random.randint(2, num - 1)
        l = pow(m, z, num)
        if l == 1 or l == num - 1:
            continue
        for k in range(0, x - 1):
            l = pow(l, 2, num)
            if l == 1:
                return True
            if l == num - 1:
                break
        else:
            return False
    return True



def proste_chyslo(size):
    i=0
    while(i<1):
        number = random.getrandbits(size)
        if miller_rabin(number):
                 i+=1
                 return number

def p_p1_q_q1():
    p=proste_chyslo(256)
    p1=proste_chyslo(256)
    q=proste_chyslo(256)
    q1=proste_chyslo(256)
    while not p * q <= p1 * q1:
        p_p1_q_q1()
    return p, p1, q, q1




p=4429540880077795634198658644001995631132676320702670240224036104419289056559
p1=69092879725250473477623603915575304837558176810318876972115760746934658775773
q=66995302051973629214396153293087487168194982240797623777449789950098155081747
q1=5932159964588744632859589796823845338722068068318309026694491367015374223127

def GenerateKeyPair(p,q):
    n = p*q
    fi_n = (p-1)*(q-1)
    e = random.randint(2,fi_n-1)
    while math.gcd(e,fi_n)!=1:
         e = random.randint(2,fi_n-1)
    d = pow(e, -1, fi_n)
    return n,e,d,fi_n



n,e,d,fn = GenerateKeyPair(p,q)
n1,e1,d1,fn1 = GenerateKeyPair(p1,q1)

n1,e1,d1


# In[24]:



def Encrypt(n,e,M):
    C = pow(M,e,n)
    return C


# In[25]:


def Decrypt(C,d,n):
    M = pow(C,d,n)
    return M


# In[26]:


def Sign(M,d,n):
    S = pow(M,d,n)
    return S


# In[27]:


def Verify(M,S,e,n):
    return M == pow(S,e,n)


# In[28]:


M=random.randint(0,n)
M


# In[29]:


C=Encrypt(n,e,M)
print (C)


# In[30]:


decrypt_msg=Decrypt(C,d,n)
print(decrypt_msg)


# In[59]:


def SendKey(k,e1,n1,d,n):
    k1 = pow(k,e1,n1)
    S = pow(k,d,n)
    S1 = pow(S,e1,n1)
    return k1,S1,S

def ReceiveKey(k1,S1,d1,n1):
    k = pow(k1,d1,n1)
    S = pow(S1,d1,n1)
    return k,S

k=random.randint(0,n)

k


# In[34]:


n1>n


# In[35]:


k1,S1,S=SendKey(k,e1,n1,d,n)
k1,S1,S


# In[36]:


km,sm=ReceiveKey(k1,S1,d1,n1)
km,sm 


# In[37]:


Verify(km,sm,e,n)


# In[40]:


hex_ = "E939D4CD7C15D54DD63D7E00DDADDD165BBA359FAD67B34695CFA565207E2DCE267F6625BB9E6D34F7F13D2058AEC1ED3AF15084FBB24C0B9E1CD5E0CE001287"
n2 = (int(float.fromhex(hex_)))
e2 = int(float.fromhex("10001"))


# In[41]:


n2


# In[42]:


SendKey(k,e2,n2,d,n)


# In[46]:


hex2=hex(9406351785313746231599576772404170530758296312506555109829843647396408060347069310006956011417281297479435217133657759292575449144930737286128579580372633)
hex1=hex(9546628585006922681540377533631496977546636223540773760204124129876718480423313135651365445730711601378027821415763869345369604554658007881356006012223488)


# In[47]:


hex1


# In[48]:


hex2


# In[51]:


e_a=hex(282531633390409782071380671872806735085075328849297598800718484533179703074902983575132552425915603436421530996721411087688641556144385761982976946807167)
n_A=hex(296758429212377017298594030822641713114600735986487235840061652754450268914412371815751178086730803753452281332836959215222677398551774527360171151528573)


# In[55]:


e_a


# In[56]:


n_A


# In[ ]:




