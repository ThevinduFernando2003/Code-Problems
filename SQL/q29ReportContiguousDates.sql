-- Code360 Top 100 SQL Problem 29: Report Contiguous Dates
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    period_state,
    MIN(date_value) AS start_date,
    MAX(date_value) AS end_date
FROM (
    SELECT
        fail_date AS date_value,
        'failed' AS period_state,
        DATE_SUB(fail_date, INTERVAL ROW_NUMBER() OVER (ORDER BY fail_date) DAY) AS grp
    FROM Failed
    WHERE fail_date BETWEEN '2019-01-01' AND '2019-12-31'
    UNION ALL
    SELECT
        success_date,
        'succeeded',
        DATE_SUB(success_date, INTERVAL ROW_NUMBER() OVER (ORDER BY success_date) DAY)
    FROM Succeeded
    WHERE success_date BETWEEN '2019-01-01' AND '2019-12-31'
) t
GROUP BY period_state, grp
ORDER BY start_date;
