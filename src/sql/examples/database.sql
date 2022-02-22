CREATE DATABASE IF NOT EXISTS `bakcyl` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_bin;
USE `bakcyl`;

CREATE TABLE IF NOT EXISTS `locations` (
  `locationId` text COLLATE utf8mb4_bin NOT NULL,
  `categories` longtext COLLATE utf8mb4_bin DEFAULT NULL,
  PRIMARY KEY (`locationId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

CREATE TABLE IF NOT EXISTS `products` (
  `productId` bigint(20) unsigned NOT NULL COMMENT 'Barcode',
  `name` text COLLATE utf8mb4_bin NOT NULL,
  `description` longtext COLLATE utf8mb4_bin DEFAULT NULL,
  `categories` longtext COLLATE utf8mb4_bin NOT NULL,
  `minQuantity` int(11) unsigned NOT NULL DEFAULT '1',
  `maxQuantity` int(11) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`productId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

CREATE TABLE IF NOT EXISTS `productsInstances` (
  `instanceId` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `locationId` text COLLATE utf8mb4_bin NOT NULL,
  `productId` bigint(20) unsigned NOT NULL,
  `quantity` int(11) unsigned NOT NULL,
  PRIMARY KEY (`instanceId`),
  UNIQUE KEY `INSTANCE UNIQUE KEY` (`locationId`,`productId`),
  KEY `locationId` (`locationId`),
  KEY `productId` (`productId`),
  CONSTRAINT `locationId` FOREIGN KEY (`locationId`) REFERENCES `locations` (`locationId`),
  CONSTRAINT `productId` FOREIGN KEY (`productId`) REFERENCES `products` (`productId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;
