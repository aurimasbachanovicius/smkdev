# Registered in 2023
SELECT *
FROM User
WHERE YEAR(registration_date) = 2023;

# Count of active users
SELECT COUNT(*) AS active_user_count
FROM User
WHERE is_active = 1;

# Count of total spent by user_id = 1
SELECT SUM(total_amount) AS total_spent
FROM UserOrder
WHERE user_id = 1;

# Get average rating for product
SELECT AVG(rating) AS average_rating
FROM UserProductReview
WHERE product_id = 1;

# List from where we import
SELECT DISTINCT country
FROM ProductImportation
ORDER BY country;

# List from where we import but in one row
SELECT GROUP_CONCAT(DISTINCT country) as 'import_countries'
FROM ProductImportation
ORDER BY country;

# All user order in 2023-05
SELECT *
FROM UserOrder
WHERE MONTH(order_date) = 4
  AND YEAR(order_date) = 2023;

# Get list from cheapest to most expensive product
SELECT description, CONCAT(price, '€')
FROM Product
ORDER BY price desc;

# Get unprocessed orders
SELECT *
FROM UserOrder
where status = 'UNPROCESSED';

# Get latest processed order
SELECT *
FROM UserOrder
where status = 'PROCESSED'
ORDER BY order_date desc
LIMIT 1