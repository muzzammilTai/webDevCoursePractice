-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 08, 2022 at 08:17 AM
-- Server version: 10.4.22-MariaDB
-- PHP Version: 8.0.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sql_sample_database`
--

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

CREATE TABLE `customer` (
  `Cust_Id` int(11) NOT NULL,
  `Cust_Name` varchar(50) DEFAULT NULL,
  `City` varchar(50) DEFAULT NULL,
  `Grade` int(11) DEFAULT NULL,
  `SalesmanId` int(11) DEFAULT NULL,
  `credit` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`Cust_Id`, `Cust_Name`, `City`, `Grade`, `SalesmanId`, `credit`) VALUES
(3003, 'Jozy Altidor', 'Moscow', 200, 5007, 15000),
(3007, 'Brad Davis', 'New York', 200, 5001, 6000),
(3005, 'Graham Zusi', 'California', 200, 5002, 10000),
(3008, 'Julian Green', 'London', 300, 5002, 2000),
(3004, 'Fabian Johnson', 'Paris', 300, 5006, 20000),
(3009, 'Geoff Cameron', 'Berlin', 100, 5003, 56000),
(3002, 'Nick Rimando', 'New York', 100, 5001, 3000),
(3001, 'Brad Guzan', 'London', 100, 5005, 25000);

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `Order_no` int(11) NOT NULL,
  `Purchase_amt` decimal(10,2) DEFAULT NULL,
  `Order_date` date DEFAULT NULL,
  `Customer_Id` int(11) DEFAULT NULL,
  `SalesmanId` int(11) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`Order_no`, `Purchase_amt`, `Order_date`, `Customer_Id`, `SalesmanId`) VALUES
(7001, '16000.00', '2012-10-05', 3005, 5002),
(7009, '1280.65', '2012-09-10', 3001, 5005),
(7002, '1075.26', '2012-10-05', 3002, 5001),
(7004, '1120.50', '2012-08-17', 3009, 5003),
(7007, '1958.50', '2012-09-10', 3005, 5002),
(7005, '3410.60', '2012-07-27', 3007, 5001),
(7008, '6770.00', '2012-09-10', 3002, 5001),
(7010, '2993.43', '2012-10-10', 3004, 5006),
(7003, '3490.40', '2012-10-10', 3009, 5003),
(7012, '1260.45', '2012-06-27', 3008, 5002),
(7011, '1085.29', '2012-08-17', 3003, 5007),
(7013, '4055.60', '2012-04-25', 3002, 5001);

-- --------------------------------------------------------

--
-- Table structure for table `salesman`
--

CREATE TABLE `salesman` (
  `SalesmanId` int(11) NOT NULL,
  `Name` varchar(30) DEFAULT NULL,
  `City` varchar(30) DEFAULT NULL,
  `Comission` float DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `salesman`
--

INSERT INTO `salesman` (`SalesmanId`, `Name`, `City`, `Comission`) VALUES
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'MC Lyon', 'Paris', 0.14),
(5007, 'Paul Adam', 'Rome', 0.13),
(5003, 'Lauson Hen', 'San Jose', 0.12);

-- --------------------------------------------------------

--
-- Table structure for table `supplierproducts`
--

CREATE TABLE `supplierproducts` (
  `SupplierId` int(11) NOT NULL,
  `ProductId` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `supplierproducts`
--

INSERT INTO `supplierproducts` (`SupplierId`, `ProductId`) VALUES
(1, 1),
(1, 2);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `customer`
--
ALTER TABLE `customer`
  ADD PRIMARY KEY (`Cust_Id`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`Order_no`);

--
-- Indexes for table `salesman`
--
ALTER TABLE `salesman`
  ADD PRIMARY KEY (`SalesmanId`);

--
-- Indexes for table `supplierproducts`
--
ALTER TABLE `supplierproducts`
  ADD PRIMARY KEY (`SupplierId`,`ProductId`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
