# Write your MySQL query statement below
-- 
select start.machine_id,Round(avg(end.timestamp-start.timestamp),3) as processing_time 
from Activity start
join Activity end
on start.machine_id=end.machine_id
  and start.process_id=end.process_id
where start.activity_type="start"
and end.activity_type="end"
group by start.machine_id;