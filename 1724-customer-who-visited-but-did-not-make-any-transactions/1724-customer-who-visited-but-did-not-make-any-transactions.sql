# Write your MySQL query statement below
select v.customer_id,COUNT(*) as count_no_trans
from Visits v
left join Transactions t
on t.visit_id = v.visit_id
where t.transaction_id IS null
group by v.customer_id;