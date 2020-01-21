create table user (
    id bigint not null auto_increment,
    email varchar(255),
    password varchar(255),
    primary key (id)) engine=MyISAM;


INSERT INTO user (id, email, password) values (1, 'email@email.com','$2a$04$EZzbSqieYfe/nFWfBWt2KeCdyq0UuDEM1ycFF8HzmlVR6sbsOnw7u');