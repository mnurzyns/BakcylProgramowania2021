CREATE DATABASE IF NOT EXISTS `bakcyl` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_bin;
USE `bakcyl`;

CREATE TABLE IF NOT EXISTS `locations` (
  `id` text COLLATE utf8mb4_bin NOT NULL,
  `categories` longtext COLLATE utf8mb4_bin DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

CREATE TABLE IF NOT EXISTS `products` (
  `id` bigint(20) unsigned NOT NULL COMMENT 'Barcode',
  `name` text COLLATE utf8mb4_bin NOT NULL,
  `description` longtext COLLATE utf8mb4_bin DEFAULT NULL,
  `categories` longtext COLLATE utf8mb4_bin NOT NULL,
  `minQuantity` int(10) unsigned NOT NULL DEFAULT '1',
  `maxQuantity` int(10) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

CREATE TABLE IF NOT EXISTS `productsInstances` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `locationId` text COLLATE utf8mb4_bin NOT NULL,
  `productId` bigint(20) unsigned NOT NULL,
  `quantity` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `INSTANCE UNIQUE KEY` (`locationId`,`productId`),
  KEY `locationId` (`locationId`),
  KEY `productId` (`productId`),
  CONSTRAINT `locationId` FOREIGN KEY (`locationId`) REFERENCES `locations` (`id`),
  CONSTRAINT `productId` FOREIGN KEY (`productId`) REFERENCES `products` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;