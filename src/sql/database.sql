CREATE DATABASE IF NOT EXISTS warehouse;

USE warehouse;

CREATE TABLE IF NOT EXISTS Products (
	id int NOT NULL AUTO_INCREMENT,
	name text,
	description text,
	PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS Products_Instances (
	id int NOT NULL AUTO_INCREMENT,
	locationID int NOT NULL,
	productID int NOT NULL,
	quantity int DEFAULT 0,
	PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS Products_History (
	id int NOT NULL AUTO_INCREMENT,
	productID int NOT NULL,
	lastUpdate date NOT NULL,
	quantity int DEFAULT 0,
	PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS Locations(
	id int NOT NULL AUTO_INCREMENT,
	name text,
	PRIMARY KEY(id)
);