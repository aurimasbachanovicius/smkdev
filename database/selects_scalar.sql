# get users whose email ends with @gmail.com
SELECT *
FROM User
WHERE email LIKE '%@gmail.com';

# get orders that total amount is between 10 and 1000
SELECT *
FROM UserOrder
WHERE total_amount BETWEEN 10 AND 1000;

# get users whose name or lastname is
SELECT *
FROM User
WHERE first_name = 'TestFirstName9'
   OR last_name = 'TestLastName10';

# get products when price > 50
SELECT *
FROM Product
WHERE price > 50;

# get order processed and unprocessed with total amount > 200
SELECT *
FROM UserOrder
WHERE status IN ('PROCESSED', 'UNPROCESSED')
  AND total_amount > 200;

# get inactive users
SELECT *
FROM User
WHERE is_active IS FALSE;

# get products in 1,2,3 categories
SELECT *
FROM Product
WHERE category_id IN (1, 2, 3);

# get user orders amount but only when there are more than two orders
SELECT user_id, COUNT(order_id) AS order_count
FROM UserOrder
GROUP BY user_id
HAVING order_count > 2;

# get product order quantity sum
SELECT product_id, SUM(quantity) AS total_quantity
FROM UserOrderItem
GROUP BY product_id;

# get users registered between 2023-12-31 and 2024-04-01
SELECT *
FROM User
WHERE registration_date BETWEEN '2023-12-31' and '2024-04-01'