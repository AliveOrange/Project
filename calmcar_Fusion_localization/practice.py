a = {
   'x' : 1,
   'y' : 2,
   'z' : 3
}
 
b = {
   'w' : 10,
   'x' : 11,
   'y' : 2
}
 
print('Common keys:', a.keys() & b.keys())
print('Keys in a not in b:', a.keys() - b.keys())
print('Keys in a or in b',a.keys() | b.keys())
 
print('(key,value) pairs in common:', a.items() & b.items())
print('(key,value) pairs in a not in b:', a.items() - b.items())
print('(key,value) pairs in a or in b:', a.items() | b.items()) 