# Dynamic-Programming-CoinChange
Solve coin change proglems with DP strategy
You have a pocket full of coins (pennies, nickels, dimes, and quarters with values of 1, 5, 10, and 25 cents respectively) that you wish to get rid of.  Each time you go to buy an item, you try to pay with the most number of coins possible.

Construct an algorithm that, given a cost and the number of coins you have available, pays the cost with as many coins as possible.

Your main will start with a pocket full of coins (loaded from stdin).  Everytime an item is bought, the value of the item will be entered via stdin and your algorithm should be used to determine how you will pay for the item, and determine your remaining coins.


Input:
starting number of each coin
value of items to be bought

Output:
for each item bought, the coins that were used, and the number of coins remaining in your pocket


Example:

	input:
	
7 10 1 3  ⇐ pennies nickels dimes quarters
		

36		

15

40


15
		

output:

7  10 1  3

- 6  6  0  0

------------

1  4  1  3

- 0  3  0  0

------------

1  1  1  3

- 0  1  1  1

------------

1  0  0  2

cannot pay 15 cents!

------------

1  0  0  2





2 Second Problem
You have a pocket full of coins again, but this time you know ahead of time what you will purchase as well as how much each item will cost.  Your goal is again to use as many coins as possible, but this time while trying to buy as many items as you can.

Construct an algorithm that, given the number of coins you have available and a list of item costs, uses as many coins as possible while trying to maximize the number of items that can be bought.


Input:
starting number of each coin
value of items to be bought

Output:

for each item bought, the coins that were used, and the number of coins remaining in your pocket



Example:


	input:
	

7 10 1 3  ⇐ pennies nickels dimes quarters

36

15

40

15



output:

7  10 1  3

- 6  1  0  1

------------

1  9  1  2

- 0  3  0  0

------------

1  6  1  2

- 0  3  0  1

------------

1  3  1  1

- 0  3  0  0

------------

1  0  1  1



(or solution that uses equivalent number of coins)

