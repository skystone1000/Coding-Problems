/*
#0175. Combine Two Tables
https://leetcode.com/problems/combine-two-tables/
*/

# Write your MySQL query statement below

SELECT FirstName, LastName, City, State
FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;