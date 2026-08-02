SELECT product_name, year, price
FROM Sales as s
INNER JOIN Product as p
    ON s.product_id = p.product_id;