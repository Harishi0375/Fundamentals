Written by Nik Tsonev

DB normalisation is the process of making your db more readable by applying specific rules of how tables need to be modelled. There are 4 levels of normalisation from 1NF being to loosest one to BCNF being the strictest one

## 1NF

the rules are simple:
1. Can't user row order to convey information - you cant order rows in a specific way as the DB will always return them in arbitrary ways
2. Same columns can't have multiple data types
3. Cant have a table without a primary key (this is to prevent duplicates)
4. Repeating groups aren't permitted - so you cant have a low of columns per row as it is awkward to Query
### 1 

for example if you have you order in height as follows

| name |
| ---- |
| Tim  |
| Nik  |
| Pico |

instead it should be as follows

| name | heigh (cm) |
| ---- | ---------- |
| Tim  | 190        |
| Nik  | 170        |
| Pico | 169        |

so that no matter in what order the query gives you the names you will know who is tallest

### 2

| name | heigh (cm)                       |
| ---- | -------------------------------- |
| Tim  | 190                              |
| Nik  | 170                              |
| Pico | "one-hundred and sixty nine cm " |

this is not allowed as query this would be very hard and is not efficient memory wise

### 3

the reason we want a primary key is to prevent duplicates because

| name | heigh (cm) |
| ---- | ---------- |
| Tim  | 190        |
| Nik  | 170        |
| Pico | 169        |
| Pico | 180        |

having 2 picos we dont know which one it is, but by creating a primary key as the name field, the DB will now allow for you to insert more than one Pico. 

Note that the primary key should always be the independant column(s)

```SQL
ALTER TABLE people
ADD PRIMARY KEY (name);
```

### 4

for example if you have a game where there is a player and inventory you cant do the following 

| player_id | arrows | shield | food | ... |
| --------- | ------ | ------ | ---- | --- |
| 123       | 2      | 24     | 23   | ..  |
this makes it awkward to query as if you had n amount of elements you'd need to include all of them to your query which is tiresome and prone to error. Instead do this

| player_id | item_type | amount |
| --------- | --------- | ------ |
| 123       | "arrows"  | 2      |
| 123       | "shield"  | 24     |
| 123       | "food"    | 23     |

this allows for specific queries such as 

```SQL
SELECT player_id FROM players
WHERE item_type = "food";
```

which would give the food

or if you want all the inventory of a specific player 

```SQL
SELECT * FROM players
WHERE player_id = 123;
```

and because of the primary key, we ensure no duplicates 
## 2NF

this builds on top of 1NF but adds one more rule. 

All components must be dependent on the primary key 

given the video game example, we add skill as a new column 

| player_id | item_type | amount | Skill |
| --------- | --------- | ------ | ----- |
| 123       | "arrows"  | 2      | "new" |
| 123       | "shield"  | 24     | "new" |
| 123       | "food"    | 23     | "new" |
| Sniks12   | "food"    | 23     | "mid" |
| Sniks12   | "shield"  | 1      | "mid" |

now if we add a new item type for Sniks12 we could accidentally do this 

"player_inv" table

| player_id | item_type | amount | Skill |
| --------- | --------- | ------ | ----- |
| 123       | "arrows"  | 2      | "new" |
| 123       | "shield"  | 24     | "new" |
| 123       | "food"    | 23     | "new" |
| Sniks12   | "food"    | 23     | "mid" |
| Sniks12   | "shield"  | 1      | "mid" |
| Sniks12   | "arrows"  | 1      | "new" |
and now the DB does not know what to do, or what if we delete the columns for items but still want to know the skill level. The problem is that Skill is only dependant on player_id and not on `item_type` which violates 2NF because both `player_id` and `item_type` are `primary keys `

instead, we should leave the "player_inv" and make a new one called "player_rating"

| player_id | Skill |
| --------- | ----- |
| 123       | "new" |
| Sniks12   | "mid" |

now every column is `fully` dependant on the primary key, achieving 2NF 
## 3NF

the rule is that every non-key element in a table should be dependent on the key, the whole key, and nothing but the key. 

for example, now we have skill as string but we want more precession as there can be better newbies, thats why we add to "player_rating" a new column called skill 

where - new  -> 1,2,3,4
	  -  mid  -> 5, 6, 7
	  - good -> 8, 9, 10

| player_id | Skill  | skill_level |
| --------- | ------ | ----------- |
| 123       | "new"  | 2           |
| Sniks12   | "mid"  | 6           |
| Kitty     | "new"  | 4           |
| loser     | "good" | 9           |

now if 123 goes to 5 we can update it 

| player_id | Skill  | skill_level |
| --------- | ------ | ----------- |
| 123       | "new"  | 5           |
| Sniks12   | "mid"  | 6           |
| Kitty     | "new"  | 4           |
| loser     | "good" | 9           |

problem is that now skill should be updated, this leads to inconsistencies. That is because skill is `dependant` on `skill_level` which is not a primary key  

{ player_id } -> { skill_level }
{ player_id } -> { skill_level } -> { Skill }

instead we should remove skill and make a new table that shows the conversion

| player_id | skill_level |
| --------- | ----------- |
| 123       | 5           |
| Sniks12   | 6           |
| Kitty     | 4           |
| loser     | 9           |

skill_level_t

| skill_level | Skill  |
| ----------- | ------ |
| 1           | "new"  |
| 2           | "new"  |
| 3           | "new"  |
| 4           | "new"  |
| 5           | "mid"  |
| 6           | "mid"  |
| 7           | "mid"  |
| 8           | "good" |
| 9           | "good" |
| 10          | "good" |

so now every time we update skill_level we know there wont be any inconsistencies as we dont need to update the skill coll

```SQL
SELECT Skill FROM skill_level_t,
JOIN player_rating 
On player_rating.skill_level = skill_level_t.skill_level
WHERE  player_rating.player_id = Sniks12;
```

this will return the skill of the player Sniks12

## BCNF

BCNF is quite simple, the standard is that there can only be 2 things per table. The `superkey` X and the column Y. 

A superkey is the combination of one or more primary keys 

so if you have more than one column depending on the superkey, you should split the table into two or more until ever table has the superkey X and the column y
$$X \rightarrow Y$$

Note that in practice, BCNF cannot always be achieved and 3NF should be satisfactory in most cases 

