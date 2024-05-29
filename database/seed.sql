INSERT INTO User
VALUES (1, 'test1', 'TestFirstName1', 'TestLastName1', 'test1@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (2, 'test2', 'TestFirstName2', 'TestLastName2', 'test2@gmail.com', 'asdasd', '2024-03-20 14:00:00', 1),
       (3, 'test3', 'TestFirstName3', 'TestLastName3', 'test3@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (4, 'test4', 'TestFirstName4', 'TestLastName4', 'test4@microsoft.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (5, 'test5', 'TestFirstName5', 'TestLastName5', 'test5@microsoft.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (6, 'test6', 'TestFirstName6', 'TestLastName6', 'test6@microsoft.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (7, 'test7', 'TestFirstName7', 'TestLastName7', 'test7@microsoft.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (8, 'test8', 'TestFirstName8', 'TestLastName8', 'test8@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (9, 'test9', 'TestFirstName9', 'TestLastName9', 'test9@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1),
       (10, 'test10', 'TestFirstName10', 'TestLastName10', 'test10@gmail.com', 'asdasd', '2023-12-31 14:30:00', 1);

INSERT INTO UserAddress (user_id, street, city, postal_code, country)
VALUES (1, '123 Main St', 'New York', '10001', 'USA'),
       (2, '456 Oak St', 'Los Angeles', '90001', 'USA'),
       (3, '789 Pine St', 'Chicago', '60601', 'USA'),
       (4, '789 Test St', 'Chicago', '60601', 'USA'),
       (5, '789 Pine St', 'Chicago', '60601', 'USA'),
       (6, 'Snipiskes', 'Vilnius', '60601', 'LTU'),
       (7, 'Snipiskes', 'Vilnius', '60601', 'LTU'),
       (8, 'Seskine', 'Kaunas', '60601', 'LTU'),
       (9, 'Seskine', 'Kaunas', '60601', 'LTU'),
       (10, 'Seskine', 'Kaunas', '60601', 'LTU');

INSERT INTO ProductCategory (category_id, name, description, parent_category_id)
VALUES (1, 'Electronics', 'Electronic devices and gadgets', NULL),
       (2, 'Clothing', 'Apparel and accessories', NULL),
       (3, 'Cards', 'Cards', null),
       (4, 'Laptops', 'Portable computing devices', 1),
       (5, 'Smartphones', 'Mobile communication devices', 1),
       (6, 'Apparel', 'Apparel accessories', 2),
       (7, 'Jewelery', 'Jewelery accessories', 2),
       (8, 'Kitchen', 'Kitchen accessories', 2),
       (9, 'Beauty', 'Beauty accessories', 2),
       (10, 'Automotive', 'Automotive devices', 3);

INSERT INTO Product (name, description, price, stock_quantity, category_id)
VALUES ('Laptop X', 'Powerful laptop with advanced features', 999.99, 50, 4),
       ('Smartphone Y', 'High-performance smartphone with AI capabilities', 699.99, 100, 5),
       ('T-shirt', 'Casual cotton t-shirt size S', 19.99, 200, 2),
       ('T-shirt', 'Casual cotton t-shirt size M', 19.99, 200, 2),
       ('T-shirt', 'Casual cotton t-shirt size L', 19.99, 200, 2),
       ('T-shirt', 'Casual cotton t-shirt size XL', 19.99, 100, 2),
       ('T-shirt', 'Casual cotton t-shirt size XXL', 19.99, 50, 2),
       ('T-shirt', 'Casual cotton t-shirt size XXXL', 19.99, 10, 2),
       ('T-shirt', 'Casual cotton t-shirt size XS', 19.99, 200, 2),
       ('T-shirt', 'Casual cotton t-shirt size XXS', 19.99, 200, 2);

INSERT INTO ProductImportation (product_id, country, firm, is_active)
VALUES (1, 'Lithuania', 'Pigu', 1),
       (2, 'Norway', 'Amazon', 1),
       (3, 'Lithuania', 'Varle', 1),
       (4, 'Lithuania', 'Varle', 1),
       (5, 'Lithuania', 'Amazon', 1),
       (6, 'Lithuania', 'Pigu', 1),
       (7, 'Lithuania', 'Amazon', 1),
       (8, 'Lithuania', 'Varle', 0),
       (9, 'Lithuania', 'Amazon', 1),
       (10, 'Lithuania', 'Varle', 0);

INSERT INTO UserOrder (user_id, order_date, total_amount, status, payment_method)
VALUES (1, NOW(), 1199.98, 'PROCESSED', 'Credit Card'),
       (2, '2024-04-01', 699.99, 'UNPROCESSED', 'PayPal'),
       (4, '2023-04-01', 19.99, 'UNPROCESSED', 'Credit Card'),
       (4, '2023-04-01', 19.99, 'PROCESSED', 'Credit Card'),
       (4, '2023-03-01', 19.99, 'PROCESSED', 'PayPal'),
       (4, '2023-03-01', 19.99, 'PROCESSED', 'PayPal'),
       (3, '2023-03-01', 19.99, 'PROCESSED', 'PayPal'),
       (3, '2023-04-01', 19.99, 'PROCESSED', 'Credit Card'),
       (3, '2023-02-01', 19.99, 'PROCESSED', 'Credit Card'),
       (3, '2023-04-01', 19.99, 'PROCESSED', 'Credit Card');

INSERT INTO UserOrderItem (order_id, product_id, quantity, price)
VALUES (1, 1, 1, 999.99),
       (1, 2, 1, 699.99),
       (3, 3, 2, 19.99),
       (3, 3, 1, 19.99),
       (3, 3, 4, 19.99),
       (3, 3, 1, 12.99),
       (3, 3, 1, 19.99),
       (3, 3, 2, 13.99),
       (3, 3, 1, 19.99),
       (3, 3, 3, 15.99);

INSERT INTO UserProductReview (product_id, user_id, rating, comment, created_at)
VALUES (1, 1, 5, '115 great laptop! Amazing performance.', '2023-04-01'),
       (2, 2, 4, '224 Good smartphone. Fast delivery.', '2023-04-01'),
       (3, 3, 5, '335 Comfortable t-shirt. Fits perfectly.', '2023-04-01'),
       (4, 3, 5, '435 Comfortable t-shirt. Fits perfectly.', '2023-04-01'),
       (5, 3, 5, '535 Comfortable t-shirt. Fits perfectly.', '2024-04-01'),
       (5, 3, 5, '535 Comfortable t-shirt. Fits perfectly.', '2023-04-01'),
       (3, 3, 5, '335 Comfortable t-shirt. Fits perfectly.', '2024-04-01'),
       (3, 3, 5, '335 Comfortable t-shirt. Fits perfectly.', '2023-04-01'),
       (3, 3, 5, '335 Comfortable t-shirt. Fits perfectly.', '2024-04-01'),
       (3, 3, 5, '335 Comfortable t-shirt. Fits perfectly.', '2023-04-01');

INSERT INTO UserCartItem (user_id, product_id, quantity, added_date)
VALUES (1, 1, 1, NOW()),
       (2, 2, 1, '2023-04-01 14:00'),
       (3, 3, 1, '2023-04-01 14:00'),
       (3, 4, 1, '2023-04-01 14:00'),
       (3, 5, 1, '2024-02-22 13:00'),
       (6, 1, 2, '2023-04-01 12:00'),
       (3, 2, 5, '2024-04-01 15:00'),
       (3, 3, 3, '2024-03-01 14:00'),
       (3, 4, 1, '2024-02-01 16:00'),
       (3, 5, 1, '2023-04-22 22:00');

INSERT INTO UserOrderPayment (order_id, payment_date, amount, payment_status)
VALUES (1, NOW(), 1199.98, 'PAID'),
       (2, NOW(), 699.99, 'UNPAID'),
       (3, NOW(), 19.99, 'PAID'),
       (4, NOW(), 19.99, 'PAID'),
       (5, NOW(), 19.99, 'PAID'),
       (6, NOW(), 19.99, 'PAID'),
       (7, NOW(), 19.99, 'PAID'),
       (8, NOW(), 19.99, 'PAID'),
       (9, NOW(), 19.99, 'PAID'),
       (10, NOW(), 19.99, 'PAID');