import math
import re

popular_bigrams = ['ст','но','то','на','ен']


file = open('02.txt', encoding='utf-8')
alphabet = ['а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ь','ы','э','ю','я']

text = file.read()
text = re.sub(r'\s+', ' ', text)
text = re.sub(r'[a-z]', ' ', text)
text = re.sub(" ", "", text)
file5 = open('text123.txt', 'w')
file5.write(text)

# file2 = open('text.txt', encoding='utf-8')

# rawtext = file2.read()
# rawtext = rawtext.lower()
# text2 = re.sub("[”|„|&|$|“|>|+|/|<| |,|.|!|?|-|-|‒|—|;|:|–|-|»|«|-|*|1|2|3|4|5|6|7|8|9|0|#|…|(|)|-|'|№|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z]", " ", rawtext)
# # text = re.sub("^\s+|\n|\r|\s+$", '', text)
# text2 = re.sub(r'\s+', ' ', text2)
# text2 = re.sub(r'[a-z]', ' ', text2)
# text2 = text2.lower()
# text2 = text2.replace("ё", "е")
# text2 = text2.replace("ъ", "ь")
# text2= text2.replace(" ", "")

# file3 = open('text2.txt', 'w')
# file3.write(text2)

# def gcd(num1, num2, q=None):
#     if q is None:
#         q=[]
#     if num2<num1:
#         tempnum=num2
#         num2=num1
#         num1=tempnum
#     if num1 == 0:
#         return (num2, q)
#     else:
#         div, q = gcd(num2 % num1, num1, q)
#     q.append(-(num2//num1))
#     return (div, q)

def gcd1(a, b, u=[1, 0], v=[0, 1]):
    r = a % b
    q = (a - r) / b
    u_next = u[0] - q * u[1]
    v_next = v[0] - q * v[1]
    if r == 0:
        return [b, u[1], v[1]]
    else:
        return gcd1(b, r, [u[1], u_next], [v[1], v_next])

# def root(a, n, b):
#     a = gcd(a,n)
#     print(a[0])
#     if a[0] >= 1:
#         u = a[1]
#         u.pop(0)
#         u1 = 0
#         u2 = 1
#         for i in u:
#             u2temp = u2
#             u2 = u1 + i*u2
#             u1 = u2temp
#         print(u2)
#         if a[0] == 1:
#             return((u2*b)%n)
#         else:
#             i = 0
#             x = []
#             while i < a[0]:
#                 x.append(((u2*b/a[0])+(n/a[0])*i)%n)
#                 i+=1
#             return(x)
#     else:
#         print("There are no solutions")
        





def bigramSTEP2_popular(text):
    res = 0
    d = {}
    ind =0 
    j=0
    while ind<len(alphabet):
        while j<len(alphabet):
            d[alphabet[ind]+alphabet[j]]=0
            j+=1
        ind+=1
        j=0
    bigram = ""
    i = 0
    count = 0
    length = len(text)
    while i<length-1:
        bigram = (text[i]+text[i+1])
        d[bigram] += 1
        i+=2
    res = sum(d.values())
    list1 = []
    most_frequent = []
    sorted_tuple = sorted(d.items(), key=lambda x: x[1])
    i = len(sorted_tuple)-5
    while i < len(sorted_tuple):
        #print(sorted_tuple[i])
        list1.append(sorted_tuple[i])
        i+=1

    for item, value in list1:
        most_frequent.append(item)
    return(most_frequent)

print(bigramSTEP2_popular(text))

#print(bigramSTEP2_popular(text2))

def EncodeNum(bigrams):
    i=0
    j=0
    list1=[]
    list_encodenum=[]
    for item in bigrams:
        while i<len(item):
            while j<len(alphabet):
                if item[i] == alphabet[j]:
                    list1.append(j)
                j+=1
            i+=1
            j=0
        i=0
    while i < len(list1):
        list_encodenum.append(list1[i]*len(alphabet)+list1[i+1])
        i+=2
    return list_encodenum


def FindKeys(bigrams_open, bigrams_cipher):
    length = len(alphabet)*len(alphabet)
    all_keys = []
    for i in range(5):
        for j in range(5):
            if i == j:
                pass
            else:
                for k in range(5):
                    for l in range(5):
                        if k == l:
                            pass
                        else:
                            keys = []
                            X1 = bigrams_open[i]
                            X2 = bigrams_open[j]
                            Y1 = bigrams_cipher[k]
                            Y2 = bigrams_cipher[l]
                            divX = X1-X2
                            divY = Y1-Y2
                            divider = gcd1(divX, length)[0]
                            if divider == 1:
                                u = gcd1(divX, length)[1]
                                a = (u * divY)%length
                                b = (Y1 - a*X1)%length
                                keys.append([a,b])
                            elif divider>1:
                                if divY % divider == 0:
                                        for y in range(int(divider)):
                                            a1 = divX / divider
                                            b1 = divY / divider
                                            n1 = length / divider
                                            x = ((b1 * gcd1(a1, n1)[1]) % n1) + y * n1
                                            a = (x * divY) % length
                                            b = (Y1 - a * X1) % length
                                            keys.append([a, b])
                                else:
                                    pass

                            all_keys.append(keys)

    return all_keys



# print(EncodeNum(bigramSTEP2_popular(text)))
# print(EncodeNum(popular_bigrams))

#print(FindKeys((EncodeNum(popular_bigrams)),EncodeNum(bigramSTEP2_popular(text))))


def Decrypter(text, a, b):
    alph = len(alphabet)*len(alphabet)
    newtext = ""
    i=0
    while i < len(text):
        a_reverse = gcd1(a, alph)[1]
        X = ((text[i]-b)*a_reverse)%alph
        x2 = int(X%len(alphabet))
        x1 = int((X - x2)/len(alphabet))
        newtext+=alphabet[x1]
        newtext+=alphabet[x2]
        i+=1
    return(newtext)
    
def check_text(text):
    banned_bigrams = ["оь", "уь", "аь", "эь", "юь", "яь", "иь"]
    # banned_bigrams = ["аь", "оь"]
    for bigram in banned_bigrams:
        if bigram in text:
            return False
    # if (text.count("ф")/len(text)) > 0.0019604907527753876 or text.count("щ")/len(text) > 0.00397133659595459 or text.count("ь")/len(text) > 0.01904738660086421:
    #     return False
    return True


all_keys = FindKeys((EncodeNum(popular_bigrams)),EncodeNum(bigramSTEP2_popular(text))) 
print(EncodeNum(popular_bigrams))
list1 = EncodeNum(text)
file4 = open('decrypted.txt', 'w')

for keys in all_keys:
    for key in keys:       
        text = Decrypter(list1, key[0], key[1])
        if check_text(text):
            file4.write(text+'\n'+'\n')
            print(key[0],key[1])


