#!/usr/bin/env python
# coding: utf-8

# In[28]:


import regex 
import collections
import unicodedata
import re
import pandas as pd
import numpy as np
import math


Alphabet = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж','з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ','ы', 'ь', 'э', 'ю', 'я']
Alphabet_space = [' ', 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж','з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ','ы', 'ь', 'э', 'ю', 'я']


kniga = open("/Users/macbook/Downloads/avidreaders.ru__prestuplenie-i-nakazanie-dr-izd.txt").read()
kniga = kniga.replace("\n"," ")
kniga = ' '.join(kniga.split())
kniga = kniga.lower()



string  = ''.join(c for c in kniga if unicodedata.category(c).startswith('L'))


string_space = regex.sub(r'[^\w\s]+|[\d]+', r'',kniga).strip()
for i in string:
    if i not in Alphabet_space :
        string = re.sub(i, '', string)


print(string)


# In[29]:


list_of_latters1=[]
for i in string:
    list_of_latters1.append(i)
list_of_latters_with_space=[]
for j in string_space:
    list_of_latters_with_space.append(j)
    
def freq_count(text:list,Alphabet_space):
    freq_dict={}
    for i in Alphabet_space:
        k=0
        for j in text:
            if i==j:
                k+=1
        freq_dict.update({i:k})
    return freq_dict
     
amount_laters_with_space=freq_count(list_of_latters_with_space,Alphabet_space)
amount_laters=freq_count(list_of_latters1,Alphabet)


amount_laters
    


# In[30]:


def chastota(dictionary,text):
    chastota_dict={}
    for i in dictionary: 
        freq=dictionary[i]/len(text)
        chastota_dict.update({i:freq})
    return chastota_dict

chastota(amount_laters_with_space,list_of_latters_with_space)

        
    


# In[23]:


chastota(amount_laters,list_of_latters1)


# In[36]:


def create_bigram_list_step_one(string): 
    bigram=[]
    for i in range(0,len(string)):
        bigram.append(string[i:i+2])
    return bigram 
create_bigram_list_step_one(string)


# In[38]:


def create_bigram_list_step_two(string):
    bigram=[]
    for i in range(0,len(string),2):
        bigram.append(string[i:i+2])
    return bigram 
bigram1=create_bigram_list_step_one(string)
bigram2=create_bigram_list_step_two(string)
bigram1_space=create_bigram_list_step_one(string_space)
bigram2_space=create_bigram_list_step_two(string_space)


# In[ ]:


""""def bigram_freq(bigram_list,string):
    dict_bigram_freq={}
    for i in range(0,len(bigram_list)):
        k=0
        for j in range(0,len(string)-2):
            if string[j:j+2]==bigram_list[i]: 
                k+=1
        dict_bigram_freq.update({bigram_list[i]:k})
    return dict_bigram_freq

bigram_freq(bigram1,string)     


# In[58]:


def bigram_freq(bigram_list):
    dict1={}
    dict_bigram_freq= dict(collections.Counter(bigram_list))
    for i in  dict_bigram_freq:
        bg_freq=dict_bigram_freq[i]/len(bigram_list)
        dict1.update({i:bg_freq})
    return dict1

bg_freq_1=bigram_freq(bigram1)
bg_freq_2=bigram_freq(bigram2)
bg_freq_1_space=bigram_freq(bigram1_space)
bg_freq_2_space=bigram_freq(bigram2_space)

dict_bg_freq_1


# In[ ]:


def Entropia(chastota,n):
    t = []
    for f in chastota.values():
        t.append(f*math.log(f,2))
    t = sorted(t)
    H = -sum(t)/n
    return H

Entropia_latters_space=Entropia(chastota(amount_laters_with_space,list_of_latters_with_space),1)
Entropia_latters=Entropia(chastota(amount_laters,list_of_latters1),1)
Entropia_step_one=Entropia(bg_freq_1,2)
Entropia_step_one_space=Entropia(bg_freq_1_space,2)
Entropia_step_two=Entropia(bg_freq_2,2)
Entropia_step_two_space=Entropia(bg_freq_2_space,2) 



