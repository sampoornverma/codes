-- Write your PostgreSQL query statement below
select tweet_id 
from Tweets
where 15< (Length(content) );