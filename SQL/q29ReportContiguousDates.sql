-- Code360 Top 100 SQL Problem 29: reportContiguousDates
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT MIN(day) AS period_start, MAX(day) AS period_end, 'missing' AS period_state FROM (SELECT a.day, DATE_SUB(a.day, INTERVAL ROW_NUMBER() OVER (ORDER BY a.day) DAY) AS grp FROM (SELECT DISTINCT DATE_ADD('2019-01-01', INTERVAL seq DAY) AS day FROM seq_0_to_999 WHERE DATE_ADD('2019-01-01', INTERVAL seq DAY) <= '2019-01-07' AND DATE_ADD('2019-01-01', INTERVAL seq DAY) NOT IN (SELECT fail_date FROM Failed)) a) t GROUP BY grp UNION ALL SELECT fail_date, fail_date, 'failed' FROM Failed ORDER BY period_start;
