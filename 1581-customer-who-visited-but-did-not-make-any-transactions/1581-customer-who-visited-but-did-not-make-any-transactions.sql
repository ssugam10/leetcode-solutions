# Write your MySQL query statement below
select customer_id, count(*) as count_no_trans from Visits where visit_id not in (select b.visit_id from Transactions b) group by customer_id;