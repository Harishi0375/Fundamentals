lst4 = ['two',3,4.2,5]
print('lst4 :',lst4)
lst4[3] = 'five'
print('lst4 :',lst4)


lst5 = ['cat','dog']
print('lst5 :',lst5)
lst6 = lst5.copy()
lst6[0] = 'mouse'
print('lst6 :',lst6)
print('lst5 :',lst5)

tpl = (1,2)
print(tpl,type(tpl))
print('tpl[1] = {}'.format(tpl[1]))  