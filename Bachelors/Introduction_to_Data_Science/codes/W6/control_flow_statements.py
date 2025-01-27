#if -----------------------------------------------------------------------

Number = 1.0
if Number>1:
    print('Number is greater than unity.')
elif Number<1:
    print('Number is smaller than unity.')
else:
    print('Number is equal to unity.') 



#Python offers a conditional expression similar to the `if-else` construction that does not qualify as a control structure as it does not (re-)direct the flow of a piece of code.

   # <InstIf> if <CondIf> else <InstElse> 

Number = 0.9
print('Number is greater than unity.') if Number>1 else print('Number is smaller than or equal to unity.')


#for -----------------------------------------------------------------------

for i in range(5):
    print(i)

#example 2 
    
### for loop with a list as iterable
print('Individual elements of a list:')
ListOfFruits = ['Apples','Bananas','Oranges','Pears']
for Fruit in ListOfFruits:
    print(Fruit)
### for loop with a string as iterable
print('\nIndividual characters of a string:')
String = 'Python'
for char in String:
    print(char)


#If not only the elements of an iterable but also the indices are required for processing the block of instructions, it is convenient to apply the Python functiom `enumerate()`.
    
print('Indices and elements of a list:')
ListOfFruits = ['Apple','Banana','Cherry']
for Index,Fruit in enumerate(ListOfFruits): #useful for obtaining index and result
    print(Index,Fruit)


#while ----------------------------------------------------------------------------------
    
i = 0
while (i<5):
    print(i)
    i += 1


#example 2

### Parameter settings.
import numpy as np
Target = np.random.randint(1,4)   #.. set target number
Guess = 0               #.. initialize variable to store guess
print('The target number is either 1, 2, or 3.')
### Enter guesses as long as the target number is not found.
while (Guess!=Target):
    Guess = int(input('Enter your guess : '))
### Check that the while loop has correctly terminated with Guess equaling Target.
print('Target : {}'.format(Target))
print('Guess  : {}'.format(Guess))


newTarget = np.random.randint(1,10)
count = 1

while(count <= 3):
    guess = int(input("enter a number from 1 to 9: "))
    if guess > newTarget:
        print("too large")
        count = count + 1
    elif guess < newTarget:
        print("too small")
        count = count + 1
    else:
        print("congrats")
        break
if (count == 3):
    print("the number of tries has reached its maximum")
