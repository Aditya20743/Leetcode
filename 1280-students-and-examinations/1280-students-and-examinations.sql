# Write your MySQL query statement below
Select st.student_id, st.student_name, su.subject_name ,
COUNT(e.student_id) AS attended_exams
From Students st Join 
Subjects su Left Join Examinations e on su.subject_name = e.subject_name 
and st.student_id = e.student_id
group by st.student_id, su.subject_name order by st.student_id, su.subject_name