-- Code360 Top 100 SQL Problem 15: treeNode
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT id, CASE WHEN p_id IS NULL THEN 'Root' WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner' ELSE 'Leaf' END AS type FROM Tree;
