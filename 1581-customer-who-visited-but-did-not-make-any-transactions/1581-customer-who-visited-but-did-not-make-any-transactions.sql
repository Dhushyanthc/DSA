SELECT v.customer_id, COUNT(v.customer_id) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions as t
    on v.visit_id = t.visit_id
WHERE t.amount IS NULL
GROUP BY v.customer_id;

