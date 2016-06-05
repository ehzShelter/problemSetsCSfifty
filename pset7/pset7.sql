-- MySQL dump 10.13  Distrib 5.5.44, for debian-linux-gnu (i686)
--
-- Host: localhost    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.44-0ubuntu0.14.04.1-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `transaction` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `timespan` datetime NOT NULL,
  `symbol` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(11) NOT NULL,
  `price` double NOT NULL,
  `id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES ('BUY','2015-09-23 12:45:04','asa',4,7.74,6),('BUY','2015-09-23 12:45:28','MSFT',2,43.9,6),('SELL','2015-09-23 12:46:05','ASA',8,7.74,6),('BUY','2015-09-23 13:35:19','FB',2,92.96,6),('BUY','2015-09-23 13:36:37','YHOO',15,30.4,6),('BUY','2015-09-23 17:25:39','FB',5,92.96,6),('SELL','2015-09-23 17:26:00','FB',257,92.96,6),('SELL','2015-09-23 19:13:14','MSFT',2,43.9,6),('BUY','2015-09-23 19:13:42','GOOG',15,622.69,6),('BUY','2015-09-23 19:19:41','FB',4,92.96,16),('BUY','2015-09-23 19:47:23','FB',54,93.58,6),('SELL','2015-09-24 16:26:28','FB',54,93.97,6),('BUY','2015-09-24 16:26:45','GOOG',15,622.36,6),('BUY','2015-09-24 17:23:17','ASA',1,7.62,6);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (6,'ASA',1),(6,'GOOG',30),(6,'YHOO',15),(16,'FB',4);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `hash` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '1000.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'belindazeng','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',1000.0000),(2,'caesar','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',1000.0000),(3,'jharvard','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',1000.0000),(4,'malan','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',1000.0000),(5,'rob','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',1000.0000),(6,'skroob','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',15765.1300),(7,'zamyla','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',1000.0000),(8,'asdf','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',10000.0000),(9,'ehzShelter','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',10000.0000),(11,'appliance','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',10000.0000),(15,'djm','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',10000.0000),(16,'Masud','$1$GwPURdiJ$/4pF73jdQXWddyKKs0per1',9628.1600);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-09-24 17:52:12
