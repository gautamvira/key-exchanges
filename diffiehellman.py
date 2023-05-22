prime = 2399
base = 11
key = 2018

#public key
dh = (base**key) % prime
print("Your public key: ", dh)

secpubkey = int(input("Enter other public key: "))

#common key between two parties
ckey = (secpubkey**key) % prime
print("Common key: ", ckey)
