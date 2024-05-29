# update user email
UPDATE User
SET email = 'newemail@example.com'
WHERE user_id = 1;

# make all users inactive without orders
UPDATE User
SET is_active = 0
WHERE user_id NOT IN (SELECT user_id FROM UserOrder);

# increase product prices by 10% for 1 category
UPDATE Product
SET price = price * 1.10
WHERE category_id = 1;

# update all user orders to processed
UPDATE UserOrder
SET status = 'PROCESSED'
WHERE status = 'UNPROCESSED';

# increase product stock by 10
UPDATE Product
SET stock_quantity = stock_quantity + 10
WHERE product_id = 1;

# remove parent category for 2nd category
UPDATE ProductCategory
SET parent_category_id = NULL
WHERE category_id = 2;

# set user address for 1st user
UPDATE UserAddress
SET street = '123 New Street'
WHERE user_id = 1
  AND address_id = 1;

# set the payment status of all unpaid payments to processing
UPDATE UserOrderPayment
SET payment_status = 'PROCESSING'
WHERE payment_status = 'UNPAID';

# update user product review
UPDATE UserProductReview
SET rating = 5
WHERE review_id = 1;

# deactivate product importation for specific firm
UPDATE ProductImportation
SET is_active = FALSE
WHERE firm = 'Pigu';

# delete specific user
DELETE
FROM User
WHERE username = 'test4';

# delete user cart for user by name
DELETE
FROM UserCartItem
where user_id = (select user_id from User where username = 'test8')

# remove all orders older than 1 year
DELETE
FROM UserOrder
WHERE order_date < DATE_SUB(NOW(), INTERVAL 1 YEAR);

# delete all reviews with rating of 1
DELETE
FROM UserProductReview
WHERE rating = 1;

# delete all payments for order
DELETE
FROM UserOrderPayment
WHERE order_id = 1;

# view users with order count
CREATE VIEW UsersWithOrderCount AS
SELECT u.user_id, u.username, COUNT(o.order_id) AS order_count
FROM User u
         LEFT JOIN UserOrder o ON u.user_id = o.user_id
GROUP BY u.user_id, u.username;

# view active users with orders that has at least one order
CREATE VIEW ActiveUsersWithOrders AS
SELECT u.user_id, u.username, COUNT(o.order_id) AS order_count
FROM User u
         INNER JOIN UserOrder o ON u.user_id = o.user_id
WHERE u.is_active = 1
GROUP BY u.user_id, u.username
