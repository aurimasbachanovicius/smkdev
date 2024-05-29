# two tables:

SELECT o.order_id, u.username, o.order_date, o.total_amount
FROM UserOrder o
         INNER JOIN User u ON o.user_id = u.user_id;

SELECT p.product_id, p.name AS product_name, c.name AS category_name
FROM Product p
         INNER JOIN ProductCategory c ON p.category_id = c.category_id;

SELECT a.address_id, u.username, a.street, a.city, a.postal_code, a.country
FROM UserAddress a
         INNER JOIN User u ON a.user_id = u.user_id;

SELECT oi.order_item_id, oi.order_id, p.name AS product_name, oi.quantity, oi.price
FROM UserOrderItem oi
         INNER JOIN Product p ON oi.product_id = p.product_id;

SELECT u.username, r.product_id, r.rating, r.created_at
FROM UserProductReview r
         INNER JOIN User u ON r.user_id = u.user_id;

# three tables:

SELECT o.order_id, u.username, o.order_date, o.total_amount, p.payment_status
FROM UserOrder o
         INNER JOIN User u ON o.user_id = u.user_id
         INNER JOIN UserOrderPayment p ON o.order_id = p.order_id;

SELECT oi.order_item_id, oi.order_id, p.name AS product_name, c.name AS category_name, oi.quantity, oi.price
FROM UserOrderItem oi
         INNER JOIN Product p ON oi.product_id = p.product_id
         INNER JOIN ProductCategory c ON p.category_id = c.category_id;

# four tables

SELECT r.review_id, u.username, p.name AS product_name, c.name AS category_name, r.rating, r.comment, r.created_at
FROM UserProductReview r
         JOIN User u ON r.user_id = u.user_id
         JOIN Product p ON r.product_id = p.product_id
         JOIN ProductCategory c ON p.category_id = c.category_id;


# CASE usage
SELECT o.order_id,
       u.username,
       o.order_date,
       o.total_amount,
       CASE
           WHEN o.total_amount > 500 THEN 'High Value Order'
           WHEN o.status = 'UNPROCESSED' THEN 'Order Pending'
           ELSE 'Standard Order'
           END AS custom_status
FROM UserOrder o
         INNER JOIN User u ON o.user_id = u.user_id;

SELECT r.review_id,
       u.username,
       r.comment,
       r.created_at,
       CASE
           WHEN r.rating = 5 THEN 'Excellent'
           WHEN r.rating = 4 THEN 'Very Good'
           WHEN r.rating = 3 THEN 'Good'
           WHEN r.rating = 2 THEN 'Fair'
           WHEN r.rating = 1 THEN 'Bad'
           ELSE 'Unknown'
           END AS rating
FROM UserProductReview r
         JOIN User u ON r.user_id = u.user_id
WHERE YEAR(created_at) >= 2024;