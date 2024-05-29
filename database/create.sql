CREATE TABLE IF NOT EXISTS User
(
    user_id           INT AUTO_INCREMENT PRIMARY KEY,
    username          VARCHAR(50)  NOT NULL,
    first_name        VARCHAR(50)  NOT NULL,
    last_name         VARCHAR(50)  NOT NULL,
    email             VARCHAR(100) NOT NULL,
    password          VARCHAR(100) NOT NULL,
    registration_date DATE         NOT NULL,
    is_active         BOOLEAN      NOT NULL
);

CREATE TABLE IF NOT EXISTS UserAddress
(
    address_id  INT AUTO_INCREMENT PRIMARY KEY,
    user_id     INT,
    street      VARCHAR(100) NOT NULL,
    city        VARCHAR(50)  NOT NULL,
    postal_code VARCHAR(20)  NOT NULL,
    country     VARCHAR(50)  NOT NULL,
    FOREIGN KEY (user_id) REFERENCES User (user_id)
);

CREATE TABLE IF NOT EXISTS UserOrder
(
    order_id       INT AUTO_INCREMENT PRIMARY KEY,
    user_id        INT,
    order_date     DATETIME                          NOT NULL,
    total_amount   DECIMAL(10, 2)                    NOT NULL,
    status         ENUM ('UNPROCESSED', 'PROCESSED') NOT NULL,
    payment_method VARCHAR(50)                       NOT NULL,
    FOREIGN KEY (user_id) REFERENCES User (user_id)
);

CREATE TABLE IF NOT EXISTS ProductCategory
(
    category_id        INT AUTO_INCREMENT PRIMARY KEY,
    name               VARCHAR(100) NOT NULL,
    description        TEXT,
    parent_category_id INT,
    FOREIGN KEY (parent_category_id) REFERENCES ProductCategory (category_id)
);

CREATE TABLE IF NOT EXISTS Product
(
    product_id     INT AUTO_INCREMENT PRIMARY KEY,
    name           VARCHAR(100)   NOT NULL,
    description    TEXT,
    price          DECIMAL(10, 2) NOT NULL,
    stock_quantity INT            NOT NULL,
    category_id    INT,
    FOREIGN KEY (category_id) REFERENCES ProductCategory (category_id)
);

CREATE TABLE IF NOT EXISTS ProductImportation
(
    product_importation_id INT AUTO_INCREMENT PRIMARY KEY,
    product_id             INT,
    country                VARCHAR(50) NOT NULL,
    firm                   VARCHAR(50) NOT NULL,
    is_active              boolean,
    FOREIGN KEY (product_id) REFERENCES Product (product_id)
);

CREATE TABLE IF NOT EXISTS UserOrderItem
(
    order_item_id INT AUTO_INCREMENT PRIMARY KEY,
    order_id      INT,
    product_id    INT,
    quantity      INT            NOT NULL,
    price         DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (order_id) REFERENCES UserOrder (order_id),
    FOREIGN KEY (product_id) REFERENCES Product (product_id)
);

CREATE TABLE IF NOT EXISTS UserProductReview
(
    review_id  INT AUTO_INCREMENT PRIMARY KEY,
    product_id INT,
    user_id    INT,
    rating     INT NOT NULL,
    comment    TEXT,
    created_at DATE,
    FOREIGN KEY (product_id) REFERENCES Product (product_id),
    FOREIGN KEY (user_id) REFERENCES User (user_id)
);

CREATE TABLE IF NOT EXISTS UserCartItem
(
    cart_item_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id      INT,
    product_id   INT,
    quantity     INT      NOT NULL,
    added_date   DATETIME NOT NULL,
    FOREIGN KEY (user_id) REFERENCES User (user_id),
    FOREIGN KEY (product_id) REFERENCES Product (product_id)
);

CREATE TABLE IF NOT EXISTS UserOrderPayment
(
    payment_id     INT AUTO_INCREMENT PRIMARY KEY,
    order_id       INT,
    payment_date   DATETIME                              NOT NULL,
    amount         DECIMAL(10, 2)                        NOT NULL,
    payment_status ENUM ('UNPAID', 'PROCESSING', 'PAID') NOT NULL,
    FOREIGN KEY (order_id) REFERENCES UserOrder (order_id)
);
