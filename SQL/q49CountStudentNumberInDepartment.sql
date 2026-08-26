-- Code360 Top 100 SQL Problem 49: countStudentNumberInDepartment
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT d.dept_name, COUNT(s.student_id) AS student_number FROM Department d LEFT JOIN Student s ON d.dept_id = s.dept_id GROUP BY d.dept_id ORDER BY student_number DESC, d.dept_name;
