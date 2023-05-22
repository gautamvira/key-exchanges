prime = 3581
base = 13

#pivate key for A
akey = 43
#Public Key1 of A
apkey = (13**akey)%prime
#pivate key for B
bkey = 91
#Public Key1 of B
bpkey = (13**bkey)%prime
#pivate key for C
ckey = 113
#Public Key1 of C
cpkey = (13**ckey)%prime

#Then, B uses public key of A, C uses public key of B, A uses public key of C

sapkey = (cpkey**akey)%prime
sbpkey = (apkey**bkey)%prime
scpkey = (bpkey**ckey)%prime

#print first and second public keys
print("First Public Key For\nA: ", apkey, "\nB: ", bpkey, "\nC: ", cpkey)
print("Second Public Key For\nA: ", sapkey, "\nB: ", sbpkey, "\nC: ", scpkey)


#Now all public key exchanges are done
#Then, B uses second public key of A, C uses second public key of B, A uses second public key of C
ackey = (scpkey**akey) % prime
bckey = (sapkey**bkey) % prime
cckey = (sbpkey**ckey) % prime

#printing common keys
print("Common key for A: ", ackey, "\nCommon key for B: ", bckey, "\nCommon key for C: ", cckey)