-- Code360 Top 100 SQL Problem 39: winningCandidate
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT c.name FROM Candidate c JOIN Vote v ON c.id = v.candidateId GROUP BY v.candidateId ORDER BY COUNT(*) DESC LIMIT 1;
