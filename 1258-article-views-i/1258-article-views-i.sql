# Write your MySQL query statement below
SELECT Distinct author_id as id
from Views
where author_id = viewer_id order by id;