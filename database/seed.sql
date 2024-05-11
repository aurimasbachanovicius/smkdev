INSERT INTO User
VALUES (1, 'test1', 'TestFirstName1', 'TestLastName1', 'test1@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (2, 'test2', 'TestFirstName2', 'TestLastName2', 'test2@gmail.com', 'asdasd', '2024-03-20 14:00:00', 1),
       (3, 'test3', 'TestFirstName3', 'TestLastName3', 'test3@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (4, 'test4', 'TestFirstName4', 'TestLastName4', 'test4@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (5, 'test5', 'TestFirstName5', 'TestLastName5', 'test5@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (6, 'test6', 'TestFirstName6', 'TestLastName6', 'test6@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (7, 'test7', 'TestFirstName7', 'TestLastName7', 'test7@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1);

INSERT INTO UserAddress (user_id, street, city, postal_code, country)
VALUES (1, '123 Main St', 'New York', '10001', 'USA'),
       (2, '456 Oak St', 'Los Angeles', '90001', 'USA'),
       (3, '789 Pine St', 'Chicago', '60601', 'USA');

INSERT INTO ProductCategory (name, description, parent_category_id)
VALUES ('Electronics', 'Electronic devices and gadgets', NULL),
       ('Clothing', 'Apparel and accessories', NULL),
       ('Laptops', 'Portable computing devices', 1),
       ('Smartphones', 'Mobile communication devices', 1);

INSERT INTO Product (name, description, price, stock_quantity, category_id)
VALUES ('Laptop X', 'Powerful laptop with advanced features', 999.99, 50, 3),
       ('Smartphone Y', 'High-performance smartphone with AI capabilities', 699.99, 100, 4),
       ('T-shirt', 'Casual cotton t-shirt', 19.99, 200, 2);

INSERT INTO ProductImportation (product_id, country, firm, is_active)
VALUES (1, 'Lithuania', 'Pigu', 1),
       (2, 'Norway', 'Amazon', 1),
       (3, 'Lithuania', 'Varle', 0);

INSERT INTO UserOrder (user_id, order_date, total_amount, status, payment_method)
VALUES (1, NOW(), 1199.98, 'PROCESSED', 'Credit Card'),
       (2, NOW(), 699.99, 'UNPROCESSED', 'PayPal'),
       (3, NOW(), 19.99, 'PROCESSED', 'Credit Card');

INSERT INTO UserOrderItem (order_id, product_id, quantity, price)
VALUES (1, 1, 1, 999.99),
       (1, 2, 1, 699.99),
       (3, 3, 1, 19.99);

INSERT INTO UserProductReview (product_id, user_id, rating, comment)
VALUES (1, 1, 5, 'Great laptop! Amazing performance.'),
       (2, 2, 4, 'Good smartphone. Fast delivery.'),
       (3, 3, 5, 'Comfortable t-shirt. Fits perfectly.');

INSERT INTO UserCartItem (user_id, product_id, quantity, added_date)
VALUES (1, 1, 1, NOW()),
       (2, 2, 1, NOW()),
       (3, 3, 1, NOW());

INSERT INTO UserOrderPayment (order_id, payment_date, amount, payment_status)
VALUES (1, NOW(), 1199.98, 'PAID'),
       (2, NOW(), 699.99, 'UNPAID'),
       (3, NOW(), 19.99, 'PAID');
