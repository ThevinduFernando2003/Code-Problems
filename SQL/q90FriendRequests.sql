-- Code360 Top 100 SQL Problem 90: friendRequests
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT requester_id, accepter_id FROM RequestAccepted GROUP BY requester_id, accepter_id;
